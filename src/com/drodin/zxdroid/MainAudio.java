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

import android.media.AudioFormat;
import android.media.AudioManager;
import android.media.AudioTrack;

public class MainAudio {

	private static AudioTrack mAudio = null;

	public static int init(int rate, int stereo) {
		int channels = (stereo==1)?AudioFormat.CHANNEL_CONFIGURATION_STEREO:AudioFormat.CHANNEL_CONFIGURATION_MONO;
		int encoding = AudioFormat.ENCODING_PCM_16BIT;
		int bufSize = 4*AudioTrack.getMinBufferSize( rate, channels, encoding );
		mAudio = new AudioTrack(AudioManager.STREAM_MUSIC, 
				rate,
				channels,
				encoding,
				bufSize,
				AudioTrack.MODE_STREAM
		);
		mAudio.play();
		return bufSize;
	}

	public static void destroy() {
		if( mAudio != null )
		{
			mAudio.stop();
			mAudio.release();
			mAudio = null;
		}		
	}

	public static void write(short[] buffer, int len) {
		mAudio.write( buffer, 0, len );
	}

}
