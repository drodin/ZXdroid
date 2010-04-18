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

import android.content.Context;
import android.content.res.Configuration;
import android.inputmethodservice.Keyboard;
import android.inputmethodservice.KeyboardView;
import android.util.AttributeSet;
import android.view.Gravity;
import android.view.View;
import android.widget.TextView;


public class SoftControls extends KeyboardView implements KeyboardView.OnKeyboardActionListener {

	private ArrayList<Keyboard> control = new ArrayList<Keyboard>(5);
	private String[] controlType = getResources().getStringArray(R.array.control_entries);

	public int mControlId = 0;
	public Keyboard mControl;

	private int lastKeyCode1 = 0;
	private int lastKeyCode2 = 0;

	private boolean capPressed = false;
	private boolean symPressed = false;

	public SoftControls(Context context, AttributeSet attr) {
		super(context, attr);

		setPreviewEnabled(false);

		setOnKeyboardActionListener(this);

		if (NativeLib.displayOrientation==Configuration.ORIENTATION_PORTRAIT) {
			control.add(new Keyboard(getContext(), R.xml.keyboard));
			control.add(new Keyboard(getContext(), R.xml.kempston));
			control.add(new Keyboard(getContext(), R.xml.cursor));		
			control.add(new Keyboard(getContext(), R.xml.sinclair1));	
			control.add(new Keyboard(getContext(), R.xml.sinclair2));	
		} else {
			control.add(new Keyboard(getContext(), R.xml.keyboard_ccw));
			control.add(new Keyboard(getContext(), R.xml.kempston_ccw));
			control.add(new Keyboard(getContext(), R.xml.cursor_ccw));
			control.add(new Keyboard(getContext(), R.xml.sinclair1_ccw));
			control.add(new Keyboard(getContext(), R.xml.sinclair2_ccw));
		}

		switchControl(NativeLib.onScreenControls);

	}

	public void switchControl(String index) {
		int i;
		for (i=0; i<controlType.length; i++)
			if (controlType[i].equals(index)) break;
		if (i >= controlType.length || i < 0) i = 0;
		mControlId = i;
		mControl = control.get(mControlId);

		if (mControlId==0) {
			if (NativeLib.displayOrientation==Configuration.ORIENTATION_LANDSCAPE)
				setPadding(
						(NativeLib.displayHeight-NativeLib.mWidth-control.get(mControlId).getMinWidth())/2, 0,
						(NativeLib.displayHeight-NativeLib.mWidth-control.get(mControlId).getMinWidth())/2, 0
				);
			else
				setPadding(0, 0, 0, 0);
		}
		else {
			if (NativeLib.displayOrientation==Configuration.ORIENTATION_LANDSCAPE)
				setPadding(
						(NativeLib.displayHeight-NativeLib.mWidth-control.get(mControlId).getMinWidth())/2-1,
						(NativeLib.displayWidth-control.get(mControlId).getHeight())/2,
						(NativeLib.displayHeight-NativeLib.mWidth-control.get(mControlId).getMinWidth())/2+1,
						(NativeLib.displayWidth-control.get(mControlId).getHeight())/2
				);
			else
				setPadding(
						(NativeLib.mWidth-control.get(mControlId).getMinWidth())/2, 0,
						(NativeLib.mWidth-control.get(mControlId).getMinWidth())/2, 0
				);
		}

		setKeyboard(mControl);
	}

	public void setControlName() {
		final TextView controlName = (TextView)((View)getParent()).findViewById(R.id.controlName);
		if (mControlId==0)
			controlName.setText("");
		else {
			controlName.setText(controlType[mControlId]);
			if (NativeLib.displayOrientation == Configuration.ORIENTATION_PORTRAIT) {
				controlName.setGravity(Gravity.RIGHT|Gravity.TOP);
				controlName.setPadding(
						0, (NativeLib.mWidth-mControl.getHeight())/5*2,
						(NativeLib.mWidth-mControl.getMinWidth())/2, 0
				);
			} else {
				controlName.setGravity(Gravity.CENTER_HORIZONTAL|Gravity.BOTTOM);
				controlName.setPadding(0, 0, 0, mControl.getHeight()/3);
			}
		}
	}

	@Override
	public void onKey(int primaryCode, int[] keyCodes) {

		if (primaryCode == Keyboard.KEYCODE_SHIFT) {
			if (capPressed == false && symPressed == false) {
				NativeLib.eventQueue.add(NativeLib.KEY_PRESS + NativeLib.spectrumKeyCap);
				capPressed = true;
			} else if (capPressed == false && symPressed == true) {
				NativeLib.eventQueue.add(NativeLib.KEY_PRESS + NativeLib.spectrumKeyCap);
				NativeLib.eventQueue.add(NativeLib.KEY_RELEASE + NativeLib.spectrumKeyCap);
				capPressed = false;
				//NativeLib.eventQueue.add(NativeLib.KEY_RELEASE + NativeLib.spectrumKeySym);
				//symPressed = false;
				mControl.getModifierKeys().get(0).on=false;
				//mControl.getModifierKeys().get(1).on=false;
				//invalidateAllKeys();
			} else if (capPressed == true) {
				NativeLib.eventQueue.add(NativeLib.KEY_RELEASE + NativeLib.spectrumKeyCap);
				capPressed = false;
			}
		}

		if (primaryCode == Keyboard.KEYCODE_ALT) {
			if (symPressed == false && capPressed == false) {
				NativeLib.eventQueue.add(NativeLib.KEY_PRESS + NativeLib.spectrumKeySym);
				symPressed = true;
			} else if (symPressed == false && capPressed == true) {
				NativeLib.eventQueue.add(NativeLib.KEY_PRESS + NativeLib.spectrumKeySym);
				NativeLib.eventQueue.add(NativeLib.KEY_RELEASE + NativeLib.spectrumKeySym);
				symPressed = false;
				//NativeLib.eventQueue.add(NativeLib.KEY_RELEASE + NativeLib.spectrumKeyCap);
				//capPressed = false;
				//mControl.getModifierKeys().get(0).on=false;
				mControl.getModifierKeys().get(1).on=false;
				//invalidateAllKeys();
			} else if (symPressed == true && capPressed == false) {
				NativeLib.eventQueue.add(NativeLib.KEY_RELEASE + NativeLib.spectrumKeySym);
				symPressed = false;
			}
		}

	}

	@Override
	public void onPress(final int primaryCode) {
		if (primaryCode!=Keyboard.KEYCODE_SHIFT && primaryCode!=Keyboard.KEYCODE_ALT) {
			if (primaryCode > 200) {
				lastKeyCode1 = (int)(primaryCode/1000);
				lastKeyCode2 = primaryCode - lastKeyCode1*1000;
				NativeLib.eventQueue.add(NativeLib.KEY_PRESS + lastKeyCode1);
				NativeLib.eventQueue.add(NativeLib.KEY_PRESS + lastKeyCode2);
			} else {
				lastKeyCode1 = primaryCode;
				lastKeyCode2 = 0;
				NativeLib.eventQueue.add(NativeLib.KEY_PRESS + lastKeyCode1);
			}
		}
	}


	@Override
	public void onRelease(final int primaryCode) {
		if (primaryCode!=Keyboard.KEYCODE_SHIFT && primaryCode!=Keyboard.KEYCODE_ALT) {
			if (lastKeyCode1!=0)
				NativeLib.eventQueue.add(NativeLib.KEY_RELEASE + lastKeyCode1);
			if (lastKeyCode2!=0)
				NativeLib.eventQueue.add(NativeLib.KEY_RELEASE + lastKeyCode2);
			lastKeyCode1 = 0;
			lastKeyCode2 = 0;
		}
	}

	@Override
	public void onText(CharSequence text) {
	}

	@Override
	public void swipeDown() {
	}

	@Override
	public void swipeLeft() {
	}

	@Override
	public void swipeRight() {
	}

	@Override
	public void swipeUp() {
	}

}
