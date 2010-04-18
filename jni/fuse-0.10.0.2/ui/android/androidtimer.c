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

#include <errno.h>
#include <string.h>
#include <unistd.h>

#include "timer/timer.h"
#include "ui/ui.h"
#include "android.h"

int
timer_get_real_time( timer_type *real_time )
{
  int error;

  error = clock_gettime(CLOCK_MONOTONIC, real_time);
  if( error ) {
    return 1;
  }

  return 0;
}

float
timer_get_time_difference( timer_type *a, timer_type *b )
{
  return ( a->tv_sec - b->tv_sec ) + ( a->tv_nsec - b->tv_nsec ) / 1000000000.0;
}

void
timer_add_time_difference( timer_type *a, long msec )
{
  a->tv_nsec += msec * 1000000;
  if( a->tv_nsec >= 1000000000 ) {
    a->tv_nsec -= 1000000000;
    a->tv_sec += 1;
  } else if( a->tv_nsec < 0 ) {
    a->tv_nsec += 1000000000;
    a->tv_sec -= 1;
  }
}

void
timer_sleep_ms( int ms )
{
  usleep( ms * 1000 );
}
