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

package com.drodin.zxdroid;

import java.util.ArrayList;

public class NativeLib {

	static {
		System.loadLibrary("fuse");
	}

	public static volatile ArrayList<Integer> eventQueue = new ArrayList<Integer>(256);
	public static volatile String openFileName = "";
	public static volatile String saveFileName = "";

	public static boolean skipFrames;

	public static boolean smoothScaling;
	
	public static boolean soundEnabled;

	public static String onScreenControls;
	public static long trackballSensitivity;

	public static String currentMachine;
	
	public static void setCurrentMachine(String machine) {
		currentMachine = machine;
	}

	public static native void resize(int width, int height, boolean scaling);

	public static native void render(int event);
	
	public static native void quit();

	public static final int spectrumScreenWidth = 320;
	public static final int spectrumScreenHeight = 240;
	public static int mWidth, mHeight;
	public static int displayWidth, displayHeight, displayOrientation;

	public static final String sdcardDir = "/sdcard";
	public static String startDir;

	public static final String supportExt = "" + " dck rom"
	+ " dsk fdi sad scl trd td0 udi" + " hdf" + " mdf mdr" + " rzx"
	+ " sna snp sp szx z80 zxs" + " csw tap tzx spc sta ltp"
	+ " gz zip";

	public static final float menuTouchDelta = 20.0f;

	public static final int KEY_PRESS = 1000;
	public static final int KEY_RELEASE = 2000;

	public static final int MENU_EVENT = 3000;
	public static final int MENU_FILE_OPEN = 101;
	public static final int MENU_FILE_SAVESNAPSHOT = 102;
	public static final int MENU_FILE_EXIT = 123;

	public static final String[] androidKeys = {
		"UNKNOWN", "SOFT_LEFT", "SOFT_RIGHT", "HOME", "BACK", "CALL", "ENDCALL",
		"0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
		"STAR", "POUND", "DPAD_UP", "DPAD_DOWN", "DPAD_LEFT", "DPAD_RIGHT",
		"DPAD_CENTER", "VOLUME_UP", "VOLUME_DOWN", "POWER", "CAMERA", "CLEAR",
		"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
		"N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
		"COMMA", "PERIOD", "ALT_LEFT", "ALT_RIGHT", "SHIFT_LEFT", "SHIFT_RIGHT",
		"TAB", "SPACE", "SYM", "EXPLORER", "ENVELOPE", "ENTER", "DEL", "GRAVE",
		"MINUS", "EQUALS", "LEFT_BRACKET", "RIGHT_BRACKET", "BACKSLASH", "SEMICOLON",
		"APOSTROPHE", "SLASH", "AT", "NUM", "HEADSETHOOK", "FOCUS", "PLUS", "MENU",
		"NOTIFICATION", "SEARCH", "MEDIA_PLAY_PAUSE", "MEDIA_STOP", "MEDIA_NEXT",
		"MEDIA_PREVIOUS", "MEDIA_REWIND", "MEDIA_FAST_FORWARD", "MUTE"
	};

	public static final String[] spectrumKeys = {
		null, null, null, null, null, null, null,
		"0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
		null, null, null, null, null, null,
		null, null, null, null, null, null,
		"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
		"N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
		null, null, null, null, null, null,
		null, "SPACE", null, null, null, "RETURN", null, null,
		null, null, null, null, null, null,
		null, null, null, null, null, null, null, null,
		null, null, null, null, null,
		null, null, null, null, //ADDED		
		null, null, null, null, null, null, null, null, null,
		"KEMPSTON UP", "KEMPSTON DOWN", "KEMPSTON LEFT", "KEMPSTON RIGHT", "KEMPSTON FIRE" 
	};

	public static final int spectrumKeyCap = 59;
	public static final int spectrumKeySym = 58;
	public static final int spectrumModFireLock = 1000;

	public static boolean interceptMenuBack;
	public static int[] definiedKeys = new int[androidKeys.length];
	// DPAD as Kempston
	public static String defaultDefinedKeys = "19:101;20:102;21:103;22:104;23:105;";

	public static final String tmpFilePrefix = "zxdroid_tmp_";
	public static String tmpUncompressedFN = null;

	public static boolean hideControls;
	public static boolean controlsHidden;
}
