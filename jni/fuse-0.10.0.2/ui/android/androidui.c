/*

   Copyright (c) 2010 Dmitry Rodin

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

   E-mail: rodin.dmitry@gmail.com

*/

#include <config.h>

#include <stdio.h>

#include "android.h"

#include "display.h"
#include "sound.h"
#include "fuse.h"
#include "ui/ui.h"
#include "ui/uidisplay.h"
#include "ui/scaler/scaler.h"
#include "settings.h"
#include "androiddisplay.h"
#include "androidjoystick.h"
#include "androidkeyboard.h"
#include "androidui.h"
#include "menu.h"

void ui_set_current_machine() {
    jmethodID mid = (*cenv)->GetStaticMethodID(cenv, nclass, "setCurrentMachine", "(Ljava/lang/String;)V");
    (*cenv)->CallStaticVoidMethod(cenv, nclass, mid, (*cenv)->NewStringUTF(cenv, machine_current->id));
}

int 
ui_init( int *argc, char ***argv )
{
  androidkeyboard_init();

  ui_mouse_present = 1;

  return 0;
}

int 
ui_event( void ) {
  if ( global_event_type ) {
    switch ( global_event_type ) {
    case KEY_PRESS:
      androidkeyboard_keypress( global_event_value );
      break;
    case KEY_RELEASE:
      androidkeyboard_keyrelease( global_event_value );
      break;
    case MENU_EVENT:
      switch (global_event_value) {
        case 0:
          needRedraw = 1;
          break;
        case MENU_FILE_OPEN:
          menu_file_open(0);
          ui_set_current_machine();
          break;
        case MENU_FILE_SAVESNAPSHOT:
          menu_file_savesnapshot(0);
          break;
        case MENU_FILE_EXIT:
          fuse_exiting = 1;
          break;
        case MENU_MACHINE_RESET:
            machine_reset(0);
            break;
        default:
          break;
      }
      break;
    default:
      break;
    }
    global_event_type = 0;
    global_event_value = 0;
  }
    return 0;
}

char * ui_get_open_filename( const char *title ) {
    jboolean isCopy;
    jstring openFileName;

    jfieldID fid = (*cenv)->GetStaticFieldID(cenv, nclass, "openFileName", "Ljava/lang/String;");
    openFileName = (*cenv)->GetStaticObjectField(cenv, nclass, fid);
    
    return (char*) (*cenv)->GetStringUTFChars(cenv, openFileName, &isCopy);
}

char * ui_get_save_filename( const char *title ) {
    jboolean isCopy;
    jstring saveFileName;

    jfieldID fid = (*cenv)->GetStaticFieldID(cenv, nclass, "saveFileName", "Ljava/lang/String;");
    saveFileName = (*cenv)->GetStaticObjectField(cenv, nclass, fid);
    
    return (char*) (*cenv)->GetStringUTFChars(cenv, saveFileName, &isCopy);
}


int 
ui_end( void )
{
  int error;

  error = uidisplay_end();
  if ( error )
    return error;

  androidkeyboard_end();

  return 0;
}

int ui_statusbar_update_speed( float speed ) { 
    //LOGI("%f", speed);
    return 0;
}

/* UNDEFINED FUNCTIONS */

int ui_mouse_grab( int startup ) { return 1; }
int ui_mouse_release( int suspend ) { return 0; }
int ui_statusbar_update( ui_statusbar_item item, ui_statusbar_state state ) { return 0; }
int ui_widgets_reset( void ) { return 0; }
int menu_select_roms_with_title( const char *title, size_t start, size_t count ) { return 0; }
scaler_type menu_get_scaler( scaler_available_fn selector ) { return 0; }
int ui_get_rollback_point( GSList *points ) { return -1; }
int ui_tape_browser_update( ui_tape_browser_update_type change, libspectrum_tape_block *block ) { return 0; }
int ui_error_specific( ui_error_level severity, const char *message ) { return 0; }
int ui_menu_item_set_active( const char *path, int active ) { return 0; }
ui_confirm_joystick_t ui_confirm_joystick( libspectrum_joystick libspectrum_type, int inputs ) { return UI_CONFIRM_JOYSTICK_NONE; }
ui_confirm_save_t ui_confirm_save_specific( const char *message ) { return UI_CONFIRM_SAVE_CANCEL; }

scaler_type current_scaler = SCALER_NUM;
int scaler_select_id( const char *scaler_mode ) { return 0; }
const char *scaler_name( scaler_type scaler ) { return "normal"; }
int scaler_select_scaler( scaler_type scaler ) { return 0; }
int scaler_is_supported( scaler_type scaler ) { return 1; }

int unittests_run( void ) { return 0; }

int pokefinder_clear( void ) { return 0; }

int debugger_mode = 0;
void debugger_event( int event_code ) {}
int debugger_end( void ) { return 0; }
int debugger_init( void ) { return 0; }
int debugger_command_evaluate( const char *command ) { return 0; }
int debugger_check( int type, libspectrum_dword value ) { return 0; }
int debugger_event_register( const char *type, const char *detail ) { return 0; }
int debugger_trap( void ) { return 0; }
int debugger_add_time_events( void ) { return 0; }

