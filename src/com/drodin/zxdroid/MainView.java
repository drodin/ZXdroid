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

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.view.KeyEvent;
import android.view.MotionEvent;

public class MainView extends GLSurfaceView {

	MainActivity mMainActivity = null;

	private static boolean trackballUsed = false;
	private static long trackUp = 0;
	private static long trackDown = 0;
	private static long trackLeft = 0;
	private static long trackRight = 0;


	public MainView(Context context) {
		super(context);

		setId((int)Math.random()*100);

		setFocusable(true);
		setFocusableInTouchMode(true);
		requestFocus();

		setRenderer(new MainRenderer());
		setRenderMode(GLSurfaceView.RENDERMODE_WHEN_DIRTY);
	}

	@Override
	public boolean onTouchEvent (MotionEvent event) {
		if (
				event.getX()>NativeLib.menuTouchDelta && 
				event.getX()<(float)NativeLib.mWidth-NativeLib.menuTouchDelta &&
				event.getY()>NativeLib.menuTouchDelta &&
				event.getY()<(float)NativeLib.mHeight-NativeLib.menuTouchDelta
		)
			MainActivity.currentInstance.showMenu();
		return true;
	}

	@Override
	public boolean onKeyPreIme (int keyCode, KeyEvent event) {
		if (event.getRepeatCount() == 0 && keyCode > 0 && keyCode < NativeLib.androidKeys.length) {
			NativeLib.eventQueue.add(
					((event.getAction() == KeyEvent.ACTION_DOWN)?NativeLib.KEY_PRESS:NativeLib.KEY_RELEASE)
					+ ((NativeLib.definiedKeys[keyCode]==0)?keyCode:NativeLib.definiedKeys[keyCode])
			);
		}
		return true;
	}

	@Override
	public boolean onTrackballEvent(MotionEvent event) {
		trackballUsed = true;

		final int action = event.getAction();

		if (action == MotionEvent.ACTION_MOVE) {

			final float x = event.getX();
			final float y = event.getY();

			if (y<0 && trackUp==0) {
				trackDown = 0;
				NativeLib.eventQueue.add(
						NativeLib.KEY_RELEASE +
						((NativeLib.definiedKeys[KeyEvent.KEYCODE_DPAD_DOWN]==0)?
								KeyEvent.KEYCODE_DPAD_DOWN:NativeLib.definiedKeys[KeyEvent.KEYCODE_DPAD_DOWN])
				);
				trackUp = System.currentTimeMillis();
				NativeLib.eventQueue.add(
						NativeLib.KEY_PRESS +
						((NativeLib.definiedKeys[KeyEvent.KEYCODE_DPAD_UP]==0)?
								KeyEvent.KEYCODE_DPAD_UP:NativeLib.definiedKeys[KeyEvent.KEYCODE_DPAD_UP])
				);
			}
			else if	(y>0 && trackDown==0) {
				trackUp = 0;
				NativeLib.eventQueue.add(
						NativeLib.KEY_RELEASE +
						((NativeLib.definiedKeys[KeyEvent.KEYCODE_DPAD_UP]==0)?
								KeyEvent.KEYCODE_DPAD_UP:NativeLib.definiedKeys[KeyEvent.KEYCODE_DPAD_UP])
				);
				trackDown = System.currentTimeMillis();
				NativeLib.eventQueue.add(
						NativeLib.KEY_PRESS +
						((NativeLib.definiedKeys[KeyEvent.KEYCODE_DPAD_DOWN]==0)?
								KeyEvent.KEYCODE_DPAD_DOWN:NativeLib.definiedKeys[KeyEvent.KEYCODE_DPAD_DOWN])
				);
			}

			if (x<0 && trackLeft==0) {
				trackRight = 0;
				NativeLib.eventQueue.add(
						NativeLib.KEY_RELEASE +
						((NativeLib.definiedKeys[KeyEvent.KEYCODE_DPAD_RIGHT]==0)?
								KeyEvent.KEYCODE_DPAD_RIGHT:NativeLib.definiedKeys[KeyEvent.KEYCODE_DPAD_RIGHT])
				);
				trackLeft = System.currentTimeMillis();
				NativeLib.eventQueue.add(
						NativeLib.KEY_PRESS +
						((NativeLib.definiedKeys[KeyEvent.KEYCODE_DPAD_LEFT]==0)?
								KeyEvent.KEYCODE_DPAD_LEFT:NativeLib.definiedKeys[KeyEvent.KEYCODE_DPAD_LEFT])
				);
			}
			else if	(x>0 && trackRight==0) {
				trackLeft = 0;
				NativeLib.eventQueue.add(
						NativeLib.KEY_RELEASE +
						((NativeLib.definiedKeys[KeyEvent.KEYCODE_DPAD_LEFT]==0)?
								KeyEvent.KEYCODE_DPAD_LEFT:NativeLib.definiedKeys[KeyEvent.KEYCODE_DPAD_LEFT])
				);
				trackRight = System.currentTimeMillis();
				NativeLib.eventQueue.add(
						NativeLib.KEY_PRESS +
						((NativeLib.definiedKeys[KeyEvent.KEYCODE_DPAD_RIGHT]==0)?
								KeyEvent.KEYCODE_DPAD_RIGHT:NativeLib.definiedKeys[KeyEvent.KEYCODE_DPAD_RIGHT])
				);
			}

		} else if (action == MotionEvent.ACTION_DOWN) {
			NativeLib.eventQueue.add(
					NativeLib.KEY_PRESS +
					((NativeLib.definiedKeys[KeyEvent.KEYCODE_DPAD_CENTER]==0)?
							KeyEvent.KEYCODE_DPAD_CENTER:NativeLib.definiedKeys[KeyEvent.KEYCODE_DPAD_CENTER])
			);
		} else {
			NativeLib.eventQueue.add(
					NativeLib.KEY_RELEASE +
					((NativeLib.definiedKeys[KeyEvent.KEYCODE_DPAD_CENTER]==0)?
							KeyEvent.KEYCODE_DPAD_CENTER:NativeLib.definiedKeys[KeyEvent.KEYCODE_DPAD_CENTER])
			);
		}
		return true;
	}

	private void finishTrackballEvents() {
		if ( trackUp!=0 && (System.currentTimeMillis()-trackUp) > NativeLib.trackballSensitivity*100 ) {
			trackUp = 0;
			NativeLib.eventQueue.add(
					NativeLib.KEY_RELEASE +
					((NativeLib.definiedKeys[KeyEvent.KEYCODE_DPAD_UP]==0)?
							KeyEvent.KEYCODE_DPAD_UP:NativeLib.definiedKeys[KeyEvent.KEYCODE_DPAD_UP])
			);
		}
		if ( trackDown!=0 && (System.currentTimeMillis()-trackDown) > NativeLib.trackballSensitivity*100 ) {
			trackDown = 0;
			NativeLib.eventQueue.add(
					NativeLib.KEY_RELEASE +
					((NativeLib.definiedKeys[KeyEvent.KEYCODE_DPAD_DOWN]==0)?
							KeyEvent.KEYCODE_DPAD_DOWN:NativeLib.definiedKeys[KeyEvent.KEYCODE_DPAD_DOWN])
			);
		}
		if ( trackLeft!=0 && (System.currentTimeMillis()-trackLeft) > NativeLib.trackballSensitivity*100 ) {
			trackLeft = 0;
			NativeLib.eventQueue.add(
					NativeLib.KEY_RELEASE +
					((NativeLib.definiedKeys[KeyEvent.KEYCODE_DPAD_LEFT]==0)?
							KeyEvent.KEYCODE_DPAD_LEFT:NativeLib.definiedKeys[KeyEvent.KEYCODE_DPAD_LEFT])
			);
		}
		if ( trackRight!=0 && (System.currentTimeMillis()-trackRight) > NativeLib.trackballSensitivity*100 ) {
			trackRight = 0;
			NativeLib.eventQueue.add(
					NativeLib.KEY_RELEASE +
					((NativeLib.definiedKeys[KeyEvent.KEYCODE_DPAD_RIGHT]==0)?
							KeyEvent.KEYCODE_DPAD_RIGHT:NativeLib.definiedKeys[KeyEvent.KEYCODE_DPAD_RIGHT])
			);
		}
	}

	public class MainRenderer implements GLSurfaceView.Renderer {

		@Override
		public void onDrawFrame(GL10 gl) {

			if (trackballUsed)
				finishTrackballEvents();

			if (NativeLib.eventQueue.size()<=0) {
				NativeLib.render(0);
			} else {
				NativeLib.render(NativeLib.eventQueue.remove(0));
			}

			requestRender();
		}

		@Override
		public void onSurfaceChanged(GL10 gl, int width, int height) {
			NativeLib.resize(NativeLib.mWidth, NativeLib.mHeight, NativeLib.smoothScaling);
		}

		@Override
		public void onSurfaceCreated(GL10 gl, EGLConfig config) {
			Thread.currentThread().setPriority(Thread.MAX_PRIORITY);
			//Process.setThreadPriority(Process.THREAD_PRIORITY_DISPLAY);
		}

	}

}
