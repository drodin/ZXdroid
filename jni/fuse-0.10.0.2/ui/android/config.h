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

#define ANDROID 1

/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.in by autoheader.  */

/* DirectX 7 or higher is required */
/* #undef DIRECTSOUND_VERSION */

/* Define to 1 if you have the `dirname' function. */
#define HAVE_DIRNAME 1

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Defined if we've got enough memory to compile z80_ops.c */
#define HAVE_ENOUGH_MEMORY 1

/* Define to 1 if you have the `fsync' function. */
#define HAVE_FSYNC 1

/* Define to 1 if you have the `geteuid' function. */
#define HAVE_GETEUID 1

/* Define to 1 if you have the `getopt_long' function. */
#define HAVE_GETOPT_LONG 1

/* Defined if gpm in use */
/* #undef HAVE_GPM_H */

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the <jsw.h> header file. */
/* #undef HAVE_JSW_H */

/* Define to 1 if you have the <libgen.h> header file. */
#define HAVE_LIBGEN_H 1

/* Define to 1 if you have the <libspectrum.h> header file. */
#define HAVE_LIBSPECTRUM_H 1

/* Defined if we've got glib */
/* #undef HAVE_LIB_GLIB */

/* Defined if we've got libxml2 */
/* #undef HAVE_LIB_XML2 */

/* Define to 1 if you have the <memory.h> header file. */
/*#define HAVE_MEMORY_H 1*/

/* Define to 1 if you have the `mkstemp' function. */
#define HAVE_MKSTEMP 1

/* Define to 1 if you have libsamplerate. */
/* #undef HAVE_SAMPLERATE */

/* Define to 1 if you have the <siginfo.h> header file. */
/* #undef HAVE_SIGINFO_H */

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/audioio.h> header file. */
/* #undef HAVE_SYS_AUDIOIO_H */

/* Define to 1 if you have the <sys/audio.h> header file. */
/* #undef HAVE_SYS_AUDIO_H */

/* Define to 1 if you have the <sys/soundcard.h> header file. */
/* #undef HAVE_SYS_SOUNDCARD_H 0 */

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if you have the <X11/extensions/XShm.h> header file. */
/* #undef HAVE_X11_EXTENSIONS_XSHM_H */

/* Defined if no sound code is present */
/* #undef NO_SOUND */

/* Name of package */
#define PACKAGE "fuse"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME ""

/* Define to the full name and version of this package. */
#define PACKAGE_STRING ""

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME ""

/* Define to the version of this package. */
#define PACKAGE_VERSION ""

/* Location of the ROM images */
/* #undef ROMSDIR */

/* Defined if the sound code uses a fifo */
/* #undef SOUND_FIFO */

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* The header needed to define the timer type */
#define TIMER_HEADER <time.h>

/* The type needed for the timer routines */
//#define TIMER_TYPE struct timeval
#define TIMER_TYPE struct timespec

/* Defined if framebuffer UI in use */
/* #undef UI_FB */

/* Defined if GTK+ UI (either 1.2 or 2.x) is in use */
/* #undef UI_GTK */

/* Defined if the SDL UI in use */
/* #undef UI_SDL */

/* Defined if svgalib UI in use */
/* #undef UI_SVGA */

/* Defined if Win32 UI in use */
/* #undef UI_WIN32 */

/* Defined if Xlib UI in use */
/* #undef UI_X */

/* Defined if we're using hardware joysticks */
#define USE_JOYSTICK 1

/* Defined if we're going to be using the installed libpng */
/* #undef USE_LIBPNG */

/* Defined if we're using a widget-based UI */
//#define USE_WIDGET 1

/* Version number of package */
#define VERSION "0.10.0.2"

/* Minimal supported version of Windows is 95 or NT4 */
/* #undef WINVER */

/* Define to 1 if your processor stores words with the most significant byte
   first (like Motorola and SPARC, unlike Intel and VAX). */
/*#define WORDS_BIGENDIAN 1*/

/* Define to 1 if the X Window System is missing or not being used. */
/* #undef X_DISPLAY_MISSING */

/* Define to 1 if `lex' declares `yytext' as a `char *' by default, not a
   `char[]'. */
#define YYTEXT_POINTER 1

/* Internet Explorer is 4.0 or higher is required */
/* #undef _WIN32_IE */

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */

/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */
#ifndef __cplusplus
/* #undef inline */
#endif
