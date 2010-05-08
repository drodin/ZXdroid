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

#include <math.h>

#include <stdio.h>
#include <assert.h>
#include <dlfcn.h>

#include "android.h"
#include "ui/android/androidui.h"
#include "ui/android/androiddisplay.h"

#include "config.h"

#include "machine.h"
#include "settings.h"

static const char *classPathName = LIB_CLASS;

int fuse_init_done = 0;

int needRedraw = 0;

int global_event_type = 0;
int global_event_value = 0;

JNIEnv* cenv = NULL;
jclass nclass;

int mWidth = 0;
int mHeight = 0;
int mScaling = 0;

extern int  fuse_init(int argc, char **argv);
extern void z80_do_opcodes();
extern void event_do_events();
extern int  fuse_end();

void
resize(JNIEnv *env, jobject thiz, jint width, jint height, jboolean scaling) {
    cenv = env;

    mWidth = width;
    mHeight = height;
    mScaling = scaling;

    nclass = (*cenv)->FindClass(cenv, classPathName);

    jfieldID sfid = (*cenv)->GetStaticFieldID(cenv, nclass, "soundEnabled", "Z");
    settings_current.sound = (*cenv)->GetStaticBooleanField(cenv, nclass, sfid);

    jfieldID rfid = (*cenv)->GetStaticFieldID(cenv, nclass, "skipFrames", "Z");
    settings_current.frame_rate = (*cenv)->GetStaticBooleanField(cenv, nclass, rfid) + 1;

    jboolean isCopy;
    jfieldID mfid = (*cenv)->GetStaticFieldID(cenv, nclass, "currentMachine", "Ljava/lang/String;");
    jstring machineId = (*cenv)->GetStaticObjectField(cenv, nclass, mfid);
    char *current_machine = (char*) (*cenv)->GetStringUTFChars(cenv, machineId, &isCopy);

    if (!fuse_init_done) {
    
        char * argv[16] = { "fuse", "--kempston", "--sound-freq", "11025", "--machine", current_machine };
        int argc = 6;

        if (!settings_current.sound) {
	        argv[argc] = "--no-sound";
            argc++;
        }

        fuse_init_done = !fuse_init(argc,argv);

    } else {

        fuse_emulation_pause();

        if( strcmp (machine_current->id, current_machine) ) machine_select_id( current_machine );
        
        uidisplay_init( width, height );
        
        fuse_emulation_unpause();

    }


}

void
render(JNIEnv *env, jobject thiz, jint event) {

    if (event) {
        global_event_type = ((int)event/1000)*1000;
        global_event_value = event%1000;
    }

    needRedraw = 0;
    while (!needRedraw) {
        z80_do_opcodes();
        event_do_events();
    }

}

void
quit(JNIEnv *env, jobject thiz) {
    cenv = env;
    fuse_emulation_pause();    
    snapshot_write(LAST_SNAPSHOT);
    fuse_end();
    fuse_init_done = 0;
    exit(0);
}

static JNINativeMethod methods[] = {
    {"resize", "(IIZ)V", (void*)resize },
    {"render", "(I)V", (void*)render },
    {"quit", "()V", (void*)quit },
};

static int registerNativeMethods(JNIEnv* env, const char* className, JNINativeMethod* gMethods, int numMethods)
{
    jclass clazz;

    clazz = (*env)->FindClass(env, className);
    if (clazz == NULL) {
        return JNI_FALSE;
    }
    if ((*env)->RegisterNatives(env, clazz, gMethods, numMethods) < 0) {
        return JNI_FALSE;
    }

    return JNI_TRUE;
}

static int registerNatives(JNIEnv* env)
{
  if (!registerNativeMethods(env, classPathName, methods, sizeof(methods) / sizeof(methods[0]))) {
    return JNI_FALSE;
  }

  return JNI_TRUE;
}

typedef union {
    JNIEnv* env;
    void* venv;
} UnionJNIEnvToVoid;

jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
    JNIEnv* env = NULL;
    UnionJNIEnvToVoid uenv;
    uenv.venv = NULL;
    jint result = -1;

    if ((*vm)->GetEnv(vm, &uenv.venv, JNI_VERSION_1_4) != JNI_OK) {
        goto fail;
    }
    env = uenv.env;

    assert(env != NULL);

    if (!registerNatives(env)) {
        goto fail;
    }

    result = JNI_VERSION_1_4;

fail:
    return result;

}

