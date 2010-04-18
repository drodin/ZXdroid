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

#include "android.h"
#include "settings.h"
#include "machine.h"

#define HIFI_FREQ 88200

jshortArray sndBuff;
jint sndBuffSize;

static const char *aclassPathName = AUDIO_CLASS;

int
sound_lowlevel_init( const char *device, int *freqptr, int *stereoptr )
{
    jclass aclass = (*cenv)->FindClass(cenv, aclassPathName);
    jmethodID ainit = (*cenv)->GetStaticMethodID(cenv, aclass, "init", "(II)I");
    
    (*cenv)->CallStaticIntMethod(cenv, aclass, ainit, *freqptr, *stereoptr);
   
    sndBuffSize = (settings_current.sound_hifi ? HIFI_FREQ : settings_current.sound_freq) / 
        (( float ) machine_current->timings.processor_speed / machine_current->timings.tstates_per_frame) *
        ( *stereoptr ? 2 : 1 );

    sndBuff = (*cenv)->NewGlobalRef(cenv, (*cenv)->NewShortArray(cenv, sndBuffSize));
    
    return 0;
}

void
sound_lowlevel_end( void )
{
    jclass aclass = (*cenv)->FindClass(cenv, aclassPathName);
    jmethodID adestroy = (*cenv)->GetStaticMethodID(cenv, aclass, "destroy", "()V");
    
    (*cenv)->CallStaticVoidMethod(cenv, aclass, adestroy);

    (*cenv)->DeleteGlobalRef(cenv, sndBuff);
    sndBuffSize = 0;
}

void
sound_lowlevel_frame( libspectrum_signed_word *data, int len )
{
    jclass aclass = (*cenv)->FindClass(cenv, aclassPathName);    
    jmethodID awrite = (*cenv)->GetStaticMethodID(cenv, aclass, "write", "([SI)V");

    (*cenv)->SetShortArrayRegion(cenv, sndBuff, 0, len, (jshort*) data);
    (*cenv)->CallStaticVoidMethod(cenv, aclass, awrite, sndBuff, len);
}

