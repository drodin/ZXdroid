########## PATHS ##########

ROOT_PATH := $(call my-dir)
FUSE_PATH := $(ROOT_PATH)/fuse-0.10.0.2
LIBSPECTRUM_PATH := $(ROOT_PATH)/libspectrum-0.5.0.1

FUSEDATADIR := /data/data/com.drodin.zxdroid/files
CURRENT_SNAPSHOT := current.sna

PACKAGE_PATH := com/drodin/zxdroid
LIB_CLASS    := NativeLib
AUDIO_CLASS  := MainAudio




########## FUSE ##########

include $(CLEAR_VARS)

LOCAL_MODULE := fuse

LOCAL_PATH := $(FUSE_PATH)

LOCAL_CFLAGS := \
    -DHAVE_CONFIG_H \
    -DFUSEDATADIR=\"$(FUSEDATADIR)\" \
    -DCURRENT_SNAPSHOT=\"$(FUSEDATADIR)/$(CURRENT_SNAPSHOT)\" \
    -DLIB_CLASS=\"$(PACKAGE_PATH)/$(LIB_CLASS)\" \
    -DAUDIO_CLASS=\"$(PACKAGE_PATH)/$(AUDIO_CLASS)\" \
    -I$(FUSE_PATH)/ui/android \
    -I$(LIBSPECTRUM_PATH) \
    --include $(FUSE_PATH)/memory.h

LOCAL_SRC_FILES := \
    ay.c \
	dck.c \
	display.c \
	divide.c \
	event.c \
	fuse.c \
	ide.c \
	if1.c \
	if2.c \
	input.c \
	joystick.c \
	kempmouse.c \
	keyboard.c \
	loader.c \
	machine.c \
	memory.c \
	mempool.c \
	menu.c \
	module.c \
	periph.c \
	printer.c \
	profile.c \
	psg.c \
	rzx.c \
	scld.c \
	screenshot.c \
	settings.c \
	simpleide.c \
	slt.c \
	snapshot.c \
	sound.c \
	spectrum.c \
	tape.c \
	ui.c \
	uidisplay.c \
	ula.c \
	utils.c \
	windres.rc \
	zxatasp.c \
	zxcf.c \
    compat/unix/file.c \
    compat/unix/osname.c \
    compat/unix/paths.c \
    disk/beta.c \
    disk/crc.c \
    disk/disk.c \
    disk/fdd.c \
    disk/plusd.c \
    disk/upd_fdc.c \
    disk/wd_fdc.c \
    machines/pentagon.c \
    machines/pentagon512.c \
    machines/pentagon1024.c \
    machines/scorpion.c \
    machines/spec128.c \
    machines/spec16.c \
    machines/spec48.c \
    machines/specplus2.c \
    machines/spec_se.c \
    machines/specplus2a.c \
    machines/specplus3.c \
    machines/specplus3e.c \
    machines/tc2048.c \
    machines/tc2068.c \
    machines/ts2068.c \
    timer/timer.c \
    ui/android/android.c \
    ui/android/androiddisplay.c \
    ui/android/androidsound.c \
    ui/android/androidjoystick.c \
    ui/android/androidkeyboard.c \
    ui/android/androidtimer.c \
    ui/android/androidui.c \
    ui/android/keysyms.c \
    z80/z80.c \
    z80/z80_ops.c

LOCAL_STATIC_LIBRARIES := spectrum

LOCAL_LDLIBS := -llog -lz -lGLESv1_CM

include $(BUILD_SHARED_LIBRARY)




########## LIBSPECTRUM ##########

include $(CLEAR_VARS)

LOCAL_MODULE := spectrum

LOCAL_PATH := $(LIBSPECTRUM_PATH)

LOCAL_SRC_FILES := \
	bzip2.c \
	creator.c \
	crypto.c \
	csw.c \
	dck.c \
	ide.c \
	libspectrum.c \
	memory.c \
	microdrive.c \
	plusd.c \
	rzx.c \
	sna.c \
	snp.c \
	snapshot.c \
	snap_accessors.c \
	sp.c \
	symbol_table.c \
	szx.c \
	tap.c \
	tape.c \
	tape_accessors.c \
	tape_block.c \
	tape_set.c \
	timings.c \
	tzx_read.c \
	tzx_write.c \
	warajevo_read.c \
	wav.c \
	z80.c \
	z80em.c \
	zlib.c \
	zxs.c \
	myglib/garray.c \
	myglib/ghash.c \
	myglib/gslist.c
	
include $(BUILD_STATIC_LIBRARY)

