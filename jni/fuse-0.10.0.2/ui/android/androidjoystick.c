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
#include "ui/android/android.h"

#if !defined USE_JOYSTICK || defined HAVE_JSW_H
/* Fake joystick, or override UI-specific handling */
#include "../uijoystick.c"

#else			/* #if !defined USE_JOYSTICK || defined HAVE_JSW_H */

#include "settings.h"
#include "input.h"

int
ui_joystick_init( void )
{
    
  settings_current.joystick_keyboard_output = 2;

  settings_current.joystick_keyboard_up     = INPUT_JOYSTICK_UP;
  settings_current.joystick_keyboard_down   = INPUT_JOYSTICK_DOWN;
  settings_current.joystick_keyboard_left   = INPUT_JOYSTICK_LEFT;
  settings_current.joystick_keyboard_right  = INPUT_JOYSTICK_RIGHT;
  settings_current.joystick_keyboard_fire   = INPUT_JOYSTICK_FIRE_1;

  return 0;
}

void ui_joystick_poll( void ) { }

void ui_joystick_end( void ) { }

#endif			/* #if !defined USE_JOYSTICK || defined HAVE_JSW_H */
