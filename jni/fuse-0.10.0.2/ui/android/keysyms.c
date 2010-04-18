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


#include "input.h"
#include "keyboard.h"

keysyms_map_t keysyms_map[] = {

  //{ 4,  INPUT_KEY_           }, //back
  //{ 5,  INPUT_KEY_           }, //call
  //{ 6,  INPUT_KEY_           }, //endcall

  { 7,  INPUT_KEY_0           },
  { 8,  INPUT_KEY_1           },
  { 9,  INPUT_KEY_2           },
  { 10, INPUT_KEY_3           },
  { 11, INPUT_KEY_4           },
  { 12, INPUT_KEY_5           },
  { 13, INPUT_KEY_6           },
  { 14, INPUT_KEY_7           },
  { 15, INPUT_KEY_8           },
  { 16, INPUT_KEY_9           },

  { 19, INPUT_KEY_Up          }, //dpad_up
  { 20, INPUT_KEY_Down        }, //dpad_down
  { 21, INPUT_KEY_Left        }, //dpad_left
  { 22, INPUT_KEY_Right       }, //dpad_right
  { 23, INPUT_KEY_Escape      }, //dpad_center
  
  //{ 24, INPUT_KEY_           }, //volume_up
  //{ 25, INPUT_KEY_           }, //volumr_down
  //{ 26, INPUT_KEY_           }, //power
  //{ 27, INPUT_KEY_           }, //camera  

  { 29, INPUT_KEY_a           },
  { 30, INPUT_KEY_b           },
  { 31, INPUT_KEY_c           },
  { 32, INPUT_KEY_d           },
  { 33, INPUT_KEY_e           },
  { 34, INPUT_KEY_f           },
  { 35, INPUT_KEY_g           },
  { 36, INPUT_KEY_h           },
  { 37, INPUT_KEY_i           },
  { 38, INPUT_KEY_j           },
  { 39, INPUT_KEY_k           },
  { 40, INPUT_KEY_l           },
  { 41, INPUT_KEY_m           },
  { 42, INPUT_KEY_n           },
  { 43, INPUT_KEY_o           },
  { 44, INPUT_KEY_p           },
  { 45, INPUT_KEY_q           },
  { 46, INPUT_KEY_r           },
  { 47, INPUT_KEY_s           },
  { 48, INPUT_KEY_t           },
  { 49, INPUT_KEY_u           },
  { 50, INPUT_KEY_v           },
  { 51, INPUT_KEY_w           },
  { 52, INPUT_KEY_x           },
  { 53, INPUT_KEY_y           },
  { 54, INPUT_KEY_z           },
  { 55, INPUT_KEY_comma       },
  { 56, INPUT_KEY_period      },
  { 57, INPUT_KEY_Alt_L       },
  { 58, INPUT_KEY_Alt_R       },
  { 59, INPUT_KEY_Shift_L     },

  { 62, INPUT_KEY_space       },

  { 66, INPUT_KEY_Return      },
  { 67, INPUT_KEY_BackSpace   },

  { 76, INPUT_KEY_slash       },
  { 77, INPUT_KEY_Tab         }, //@

  //{ 80, INPUT_KEY_           }, //focus

  //{ 82, INPUT_KEY_           }, //menu

  //{ 84, INPUT_KEY_           }, //search (SYM)

  /* Nonandroid codes for Kempston Joystick */
  { 101, INPUT_JOYSTICK_UP     },
  { 102, INPUT_JOYSTICK_DOWN   },
  { 103, INPUT_JOYSTICK_LEFT   },
  { 104, INPUT_JOYSTICK_RIGHT  },
  { 105, INPUT_JOYSTICK_FIRE_1 },

  { 0, 0 }			/* End marker: DO NOT MOVE! */

};

