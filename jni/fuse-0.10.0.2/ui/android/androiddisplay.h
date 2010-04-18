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

#ifndef FUSE_ANDROIDDISPLAY_H
#define FUSE_ANDROIDDISPLAY_H

typedef struct ANDROID_Color {
	int8_t r;
	int8_t g;
	int8_t b;
	int8_t unused;
} ANDROID_Color;

extern int needRedraw;
extern int uidisplay_init( int width, int height );

#endif			/* #ifndef FUSE_ANDROIDDISPLAY_H */
