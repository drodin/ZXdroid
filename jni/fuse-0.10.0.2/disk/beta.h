/* beta.h: Routines for handling the Beta disk interface
   Copyright (c) 2003-2004 Fredrick Meunier, Philip Kendall

   $Id: beta.h 3681 2008-06-16 09:40:29Z pak21 $

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

     Fred: fredm@spamcop.net

*/

#ifndef FUSE_BETA_H
#define FUSE_BETA_H

#include <libspectrum.h>

#include "periph.h"

extern int beta_available;  /* Is the Beta disk interface available for use? */
extern int beta_active;     /* Is the Beta disk interface enabled? */
extern int beta_builtin;    /* Is the Beta disk interface built-in? */

extern const periph_t beta_peripherals[];
extern const size_t beta_peripherals_count;

int beta_init( void );

void beta_end( void );

void beta_page( void );
void beta_unpage( void );

void beta_cr_write( libspectrum_word port, libspectrum_byte b );

libspectrum_byte beta_sr_read( libspectrum_word port, int *attached );

libspectrum_byte beta_tr_read( libspectrum_word port, int *attached );
void beta_tr_write( libspectrum_word port, libspectrum_byte b );

libspectrum_byte beta_sec_read( libspectrum_word port, int *attached );
void beta_sec_write( libspectrum_word port, libspectrum_byte b );

libspectrum_byte beta_dr_read( libspectrum_word port, int *attached );
void beta_dr_write( libspectrum_word port, libspectrum_byte b );

libspectrum_byte beta_sp_read( libspectrum_word port, int *attached );
void beta_sp_write( libspectrum_word port, libspectrum_byte b );

typedef enum beta_drive_number {
  BETA_DRIVE_A = 0,
  BETA_DRIVE_B,
  BETA_DRIVE_C,
  BETA_DRIVE_D,
} beta_drive_number;

int beta_disk_insert( beta_drive_number which, const char *filename,
                       int autoload );
int beta_disk_eject( beta_drive_number which, int write );
int beta_disk_writeprotect( beta_drive_number which, int wrprot );
int beta_disk_write( beta_drive_number which, const char *filename );

#endif                  /* #ifndef FUSE_BETA_H */
