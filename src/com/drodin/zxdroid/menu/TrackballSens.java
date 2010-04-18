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

package com.drodin.zxdroid.menu;

import android.content.Context;
import android.content.res.TypedArray;
import android.preference.DialogPreference;
import android.util.AttributeSet;
import android.view.View;
import android.widget.SeekBar;
import android.widget.TextView;

import com.drodin.zxdroid.NativeLib;
import com.drodin.zxdroid.R;

public class TrackballSens extends DialogPreference
		implements SeekBar.OnSeekBarChangeListener {

	private SeekBar seekBar;
	private TextView valueView;
	private int minValue, maxValue;
	private int oldValue, newValue;

	public TrackballSens(Context context, AttributeSet attrs) {
		super(context, attrs);

		minValue = attrs.getAttributeIntValue("", "minValue", 1);
		maxValue = attrs.getAttributeIntValue("", "maxValue", 10);

		setDialogLayoutResource(R.layout.bar);
		setPositiveButtonText(R.string.save_btn);
		setNegativeButtonText(R.string.df_btn_cancel);
	}

	@Override
	protected void onBindDialogView(View view) {
		super.onBindDialogView(view);

		if (newValue < minValue)
			newValue = minValue;
		if (newValue > maxValue)
			newValue = maxValue;

		seekBar = (SeekBar) view.findViewById(R.id.seekbar);
		seekBar.setMax(maxValue - minValue);
		seekBar.setProgress(newValue - minValue);
		seekBar.setSecondaryProgress(newValue - minValue);
		seekBar.setOnSeekBarChangeListener(this);

		valueView = (TextView) view.findViewById(R.id.value);
		valueView.setText(Integer.toString(newValue));
	}

	public void onProgressChanged(SeekBar seekBar,
			int progress, boolean fromUser) {
		newValue = progress + minValue;
		valueView.setText(Integer.toString(newValue));
	}

	public void onStartTrackingTouch(SeekBar seekBar) {
	}

	public void onStopTrackingTouch(SeekBar seekBar) {
	}

	@Override
	protected void onDialogClosed(boolean positiveResult) {
		super.onDialogClosed(positiveResult);

		if (!positiveResult)
			newValue = oldValue;
		else {
			NativeLib.trackballSensitivity = newValue;
			oldValue = newValue;
			persistInt(newValue);
		}
	}

	@Override
	protected Object onGetDefaultValue(TypedArray a, int index) {
		return a.getInteger(index, 0);
	}

	@Override
	protected void onSetInitialValue(
			boolean restoreValue, Object defaultValue) {
		oldValue = (restoreValue ?
				getPersistedInt(0) : ((Integer) defaultValue).intValue());
		newValue = oldValue;
	}
}
