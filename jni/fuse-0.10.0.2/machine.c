/* machine.c: Routines for handling the various machine types
   Copyright (c) 1999-2008 Philip Kendall

   $Id: machine.c 3681 2008-06-16 09:40:29Z pak21 $

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License along
   with this program; if not, write to the Free Software Foundation, Inc.,
   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

   Author contact information:

   E-mail: philip-fuse@shadowmagic.org.uk

*/

#include <config.h>

#include <stdlib.h>
#include <string.h>

#include "event.h"
#include "fuse.h"
#include "machine.h"
#include "machines/machines.h"
#include "machines/scorpion.h"
#include "machines/spec128.h"
#include "machines/spec48.h"
#include "machines/specplus3.h"
#include "machines/tc2068.h"
#include "memory.h"
#include "module.h"
#include "settings.h"
#include "snapshot.h"
#include "sound.h"
#include "tape.h"
#include "timer/timer.h"
#include "ui/ui.h"
#include "ui/uidisplay.h"
#include "ula.h"
#include "utils.h"

fuse_machine_info **machine_types = NULL; /* Array of available machines */
int machine_count = 0;

fuse_machine_info *machine_current = NULL; /* The currently selected machine */
static int machine_location;	/* Where is the current machine in
				   machine_types[...]? */

static int machine_add_machine( int (*init_function)(fuse_machine_info *machine) );
static int machine_select_machine( fuse_machine_info *machine );
static void machine_set_const_timings( fuse_machine_info *machine );
static void machine_set_variable_timings( fuse_machine_info *machine );

int machine_init_machines( void )
{
  int error;

  error = machine_add_machine( spec16_init    );
  if (error ) return error;
  error = machine_add_machine( spec48_init    );
  if (error ) return error;
  error = machine_add_machine( spec128_init   );
  if (error ) return error;
  error = machine_add_machine( specplus2_init );
  if (error ) return error;
  error = machine_add_machine( specplus2a_init );
  if( error ) return error;

  error = machine_add_machine( specplus3_init );
  if (error ) return error;

  error = machine_add_machine( specplus3e_init );
  if( error ) return error;

  error = machine_add_machine( tc2048_init );
  if (error ) return error;
  error = machine_add_machine( tc2068_init );
  if( error ) return error;
  error = machine_add_machine( ts2068_init );
  if( error ) return error;
  error = machine_add_machine( pentagon_init );
  if (error ) return error;
  error = machine_add_machine( pentagon512_init );
  if (error ) return error;
  error = machine_add_machine( pentagon1024_init );
  if (error ) return error;
  error = machine_add_machine( scorpion_init );
  if ( error ) return error;
  error = machine_add_machine( spec_se_init );
  if ( error ) return error;

  return 0;
}

static int machine_add_machine( int (*init_function)( fuse_machine_info *machine ) )
{
  fuse_machine_info *machine;
  int error;

  machine_count++;

  machine_types = realloc( machine_types,
			   machine_count * sizeof( fuse_machine_info* ) );
  if( machine_types == NULL ) {
    ui_error( UI_ERROR_ERROR, "out of memory at %s:%d", __FILE__, __LINE__ );
    return 1;
  }

  machine_types[ machine_count - 1 ] = malloc( sizeof( fuse_machine_info ) );
  if( !machine_types[ machine_count - 1 ] ) {
    ui_error( UI_ERROR_ERROR, "out of memory at %s:%d", __FILE__, __LINE__ );
    return 1;
  }

  machine = machine_types[ machine_count - 1 ];

  error = init_function( machine ); if( error ) return error;

  machine_set_const_timings( machine );

  machine->capabilities = libspectrum_machine_capabilities( machine->machine );

  return 0;
}

int
machine_select( libspectrum_machine type )
{
  int i;
  int error;

  for( i=0; i < machine_count; i++ ) {
    if( machine_types[i]->machine == type ) {
      machine_location = i;
      error = machine_select_machine( machine_types[i] );

      if( !error ) return 0;

      /* If we couldn't select the new machine type, try falling back
	 to plain old 48K */
      if( type != LIBSPECTRUM_MACHINE_48 ) 
	error = machine_select( LIBSPECTRUM_MACHINE_48 );
	
      /* If that still didn't work, give up */
      if( error ) {
	ui_error( UI_ERROR_ERROR, "can't select 48K machine. Giving up." );
	fuse_abort();
      } else {
	ui_error( UI_ERROR_INFO, "selecting 48K machine" );
	return 0;
      }
      
      return 0;
    }
  }

  ui_error( UI_ERROR_ERROR, "machine type %d unknown", type );
  return 1;
}

int machine_select_id( const char *id )
{
  int i, error;

  for( i=0; i < machine_count; i++ ) {
    if( ! strcmp( machine_types[i]->id, id ) ) {
      error = machine_select_machine( machine_types[i] );
      if( error ) return error;
      return 0;
    }
  }

  ui_error( UI_ERROR_ERROR, "Machine id '%s' unknown", id );
  return 1;
}

const char*
machine_get_id( libspectrum_machine type )
{
  int i;

  for( i=0; i<machine_count; i++ )
    if( machine_types[i]->machine == type ) return machine_types[i]->id;

  return NULL;
}

static int
machine_select_machine( fuse_machine_info *machine )
{
  int width, height, i;
  int capabilities;

  machine_current = machine;

  settings_set_string( &settings_current.start_machine, machine->id );
  
  tstates = 0;

  /* Reset the event stack */
  event_reset();
  if( event_add( 0, timer_event ) ) return 1;
  if( event_add( machine->timings.tstates_per_frame, spectrum_frame_event ) )
    return 1;

  sound_end();

  if( uidisplay_end() ) return 1;

  capabilities = libspectrum_machine_capabilities( machine->machine );

  /* Set screen sizes here */
  if( capabilities & LIBSPECTRUM_MACHINE_CAPABILITY_TIMEX_VIDEO ) {
    width = DISPLAY_SCREEN_WIDTH;
    height = 2*DISPLAY_SCREEN_HEIGHT;
  } else {
    width = DISPLAY_ASPECT_WIDTH;
    height = DISPLAY_SCREEN_HEIGHT;
  }

  if( uidisplay_init( width, height ) ) return 1;

  sound_init( settings_current.sound_device );

  /* Mark RAM as not-present/read-only. The machine's reset function will
   * mark available pages as present/writeable.
   */
  for( i = 0; i < 2 * SPECTRUM_RAM_PAGES; i++ )
    memory_map_ram[i].writable = 0;

  /* Do a hard reset */
  if( machine_reset( 1 ) ) return 1;

  /* And the dock menu item */
  if( capabilities & LIBSPECTRUM_MACHINE_CAPABILITY_TIMEX_DOCK ) {
    ui_menu_activate( UI_MENU_ITEM_MEDIA_CARTRIDGE_DOCK_EJECT, 0 );
  }

  /* Reset any dialogue boxes etc. which contain machine-dependent state */
  ui_widgets_reset();

  return 0;
}

int
machine_load_rom_bank_from_buffer( memory_page* bank_map, size_t which,
                                   int page_num, unsigned char *buffer,
                                   size_t length, int custom )
{
  size_t i, offset;
  
  bank_map[ which ].offset = 0;
  bank_map[ which ].page_num = page_num;
  bank_map[ which ].page = memory_pool_allocate( length );
  if( !bank_map[ which ].page ) {
    ui_error( UI_ERROR_ERROR, "Out of memory at %s:%d", __FILE__,
              __LINE__ );
    return 1;
  }

  memcpy( bank_map[ which ].page, buffer, length );
  bank_map[ which ].source = custom ? MEMORY_SOURCE_CUSTOMROM :
                                      MEMORY_SOURCE_SYSTEM;

  for( i = 1, offset = MEMORY_PAGE_SIZE;
       offset < length;
       i++, offset += MEMORY_PAGE_SIZE   ) {
    bank_map[ which + i ].offset = offset;
    bank_map[ which + i ].page_num = page_num;
    bank_map[ which + i ].page = bank_map[ which ].page + offset;
    bank_map[ which + i ].source = custom ? MEMORY_SOURCE_CUSTOMROM :
                                            MEMORY_SOURCE_SYSTEM;
  }

  return 0;
}

static int
machine_load_rom_bank_from_file( memory_page* bank_map, size_t which,
                                 int page_num, const char *filename,
                                 size_t expected_length, int custom )
{
  int fd, error;
  utils_file rom;

  fd = utils_find_auxiliary_file( filename, UTILS_AUXILIARY_ROM );
  if( fd == -1 ) {
    ui_error( UI_ERROR_ERROR, "couldn't find ROM '%s'", filename );
    return 1;
  }
  
  error = utils_read_fd( fd, filename, &rom );
  if( error ) return error;
  
  if( rom.length != expected_length ) {
    ui_error( UI_ERROR_ERROR,
	      "ROM '%s' is %ld bytes long; expected %ld bytes",
	      filename, (unsigned long)rom.length,
	      (unsigned long)expected_length );
    utils_close_file( &rom );
    return 1;
  }

  error = machine_load_rom_bank_from_buffer( bank_map, which, page_num,
                                             rom.buffer, rom.length, custom );

  error |= utils_close_file( &rom );

  return error;
}

int
machine_load_rom_bank( memory_page* bank_map, size_t which, int page_num,
                       const char *filename, const char *fallback,
                       size_t expected_length )
{
  int custom = 0;
  int retval;

  if( fallback ) custom = strcmp( filename, fallback );

  retval = machine_load_rom_bank_from_file( bank_map, which, page_num,
                                            filename, expected_length, custom );
  if( retval && fallback )
    retval = machine_load_rom_bank_from_file( bank_map, which, page_num,
                                              fallback, expected_length, 0 );
  return retval;
}

int
machine_load_rom( size_t which, int page_num, const char *filename,
                  const char *fallback, size_t expected_length )
{
  return machine_load_rom_bank( memory_map_rom, which, page_num, filename,
                                fallback, expected_length );
}

int
machine_reset( int hard_reset )
{
  size_t i;
  int error;

  sound_ay_reset();

  tape_stop();

  memory_pool_free();

  machine_current->ram.romcs = 0;

  machine_set_variable_timings( machine_current );

  /* Do the machine-specific bits, including loading the ROMs */
  error = machine_current->reset(); if( error ) return error;

  module_reset( hard_reset );

  error = machine_current->memory_map(); if( error ) return error;

  /* Set up the contention array */
  for( i = 0; i < machine_current->timings.tstates_per_frame; i++ ) {
    ula_contention[ i ] = machine_current->ram.contend_delay( i );
    ula_contention_no_mreq[ i ] = machine_current->ram.contend_delay_no_mreq( i );
  }

  /* Check for an Interface I ROM */
  ui_statusbar_update( UI_STATUSBAR_ITEM_MICRODRIVE,
		       UI_STATUSBAR_STATE_NOT_AVAILABLE );
  
  /* Update the disk menu items */
  ui_menu_disk_update();

  /* clear out old display image ready for new one */
  display_refresh_all();

  return 0;
}

static void
machine_set_const_timings( fuse_machine_info *machine )
{
  /* Pull timings we use repeatedly out of libspectrum and store them
     for ourself */
  machine->timings.processor_speed =
    libspectrum_timings_processor_speed( machine->machine );
  machine->timings.left_border =
    libspectrum_timings_left_border( machine->machine );
  machine->timings.horizontal_screen =
    libspectrum_timings_horizontal_screen( machine->machine );
  machine->timings.right_border =
    libspectrum_timings_right_border( machine->machine );
  machine->timings.tstates_per_line =
    libspectrum_timings_tstates_per_line( machine->machine );
  machine->timings.interrupt_length =
    libspectrum_timings_interrupt_length( machine->machine );
  machine->timings.tstates_per_frame =
    libspectrum_timings_tstates_per_frame( machine->machine );
}

static void
machine_set_variable_timings( fuse_machine_info *machine )
{
  size_t y;

  /* Magic number alert

     libspectrum_timings_top_left_pixel gives us the number of tstates
     after the interrupt at which the top-left pixel of the screen is
     displayed. However, what's more useful for Fuse is when the first
     pixel of the top line of the border is displayed.

     Fuse shows DISPLAY_BORDER_HEIGHT lines of top border and
     DISPLAY_BORDER_WIDTH_COLS columns of left border, so we subtract
     the appropriate offset to get when the top-left pixel of the
     border is displayed.
  */

  machine->line_times[0]=
    libspectrum_timings_top_left_pixel( machine->machine ) -
    /* DISPLAY_BORDER_HEIGHT lines of top border */
    DISPLAY_BORDER_HEIGHT * machine->timings.tstates_per_line -
    4 * DISPLAY_BORDER_WIDTH_COLS; /* Left border at 4 tstates per column */

  if( settings_current.late_timings ) machine->line_times[0]++;

  for( y=1; y<DISPLAY_SCREEN_HEIGHT+1; y++ ) {
    machine->line_times[y] = machine->line_times[y-1] + 
                             machine->timings.tstates_per_line;
  }
}

int machine_end( void )
{
  int i;

  for( i=0; i<machine_count; i++ ) {
    if( machine_types[i]->shutdown ) machine_types[i]->shutdown();
    free( machine_types[i] );
  }

  free( machine_types );

  return 0;
}
