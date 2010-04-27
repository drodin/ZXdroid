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

import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.preference.ListPreference;
import android.preference.Preference;
import android.preference.PreferenceActivity;
import android.preference.PreferenceManager;
import android.preference.PreferenceScreen;
import android.view.WindowManager;

import com.drodin.zxdroid.MainActivity;
import com.drodin.zxdroid.NativeLib;
import com.drodin.zxdroid.R;

public class MenuTop extends PreferenceActivity
implements Preference.OnPreferenceChangeListener {

	private SharedPreferences settings;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		getWindow().setFlags(WindowManager.LayoutParams.FLAG_BLUR_BEHIND,
				WindowManager.LayoutParams.FLAG_BLUR_BEHIND);

		addPreferencesFromResource(R.xml.preferences);

		settings = PreferenceManager.getDefaultSharedPreferences(this);

		findPreference("frameSkip").setOnPreferenceChangeListener(this);
		findPreference("smoothScaling").setOnPreferenceChangeListener(this);

		findPreference("soundEnabled").setOnPreferenceChangeListener(this);

		findPreference("onScreenControls").setSummary(NativeLib.onScreenControls);
		findPreference("onScreenControls").setOnPreferenceChangeListener(this);
		
		findPreference("interceptMenuBack").setOnPreferenceChangeListener(this);

		SharedPreferences.Editor editor = settings.edit();
		editor.putString("currentMachine", NativeLib.currentMachine);
		editor.commit();
		((ListPreference)findPreference("currentMachine")).setValue(NativeLib.currentMachine);

		findPreference("currentMachine")
		.setSummary(((ListPreference)findPreference("currentMachine")).getEntry());
		findPreference("currentMachine").setOnPreferenceChangeListener(this);

	}

	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
		super.onActivityResult(requestCode, resultCode, data);
		if (resultCode == RESULT_OK && requestCode == 0) {
			setResult(RESULT_OK, data);
			finish();
		} 
		else if (requestCode == 1) {
			SharedPreferences.Editor editor = settings.edit();
			String definedKeysStr = "";
			for (int i=0; i<NativeLib.definiedKeys.length; i++)
				if (NativeLib.definiedKeys[i]!=0)
					definedKeysStr += i+":"+NativeLib.definiedKeys[i]+";";
			editor.putString("definedKeys", definedKeysStr);
			editor.commit();
		}
	}

	@Override
	public boolean onPreferenceTreeClick(PreferenceScreen screen, Preference pref) {
		if (pref.getKey().equals("loadFile")) {
			startActivityForResult(new Intent(this, FileOpen.class), 0);
		}
		if (pref.getKey().equals("saveSnapshot")) {
			startActivityForResult(new Intent(this, FileSave.class), 0);
		}
		if (pref.getKey().equals("exit")) {
			setResult(RESULT_OK, new Intent().putExtra("menuEventValue", NativeLib.MENU_FILE_EXIT));
			finish();
		}
		if (pref.getKey().equals("defineKeys")) {
			startActivityForResult(new Intent(this, DefineKeys.class), 1);
		}
		if (pref.getKey().equals("help")) {
			startActivityForResult(new Intent(this, HelpView.class), 0);
		}
		return super.onPreferenceTreeClick(screen, pref);
	}

	@Override
	public boolean onPreferenceChange(Preference preference, Object newValue) {
		if (preference.getKey().equals("frameSkip")) {
			NativeLib.frameSkip = (newValue.equals(false))?false:true;
			finish();
		}
		if (preference.getKey().equals("smoothScaling")) {
			NativeLib.smoothScaling = (newValue.equals(false))?false:true;
			finish();
		}
		if (preference.getKey().equals("soundEnabled")) {
			NativeLib.soundEnabled = (newValue.equals(false))?false:true;
			finish();
		}
		if (preference.getKey().equals("interceptMenuBack")) {
			NativeLib.interceptMenuBack = (newValue.equals(false))?false:true;
			if (newValue.equals(true)) {
				preference.setSummary(getString(R.string.intercept_warning));
			} else {
				preference.setSummary(null);
			}
		}
		if (preference.getKey().equals("onScreenControls")) {
			if (!NativeLib.onScreenControls.equals(newValue.toString())) {
				NativeLib.onScreenControls = newValue.toString();
				MainActivity.mSoftControls.switchControl(NativeLib.onScreenControls);
				MainActivity.mSoftControls.setControlName();
				finish();
			}
		}
		if (preference.getKey().equals("currentMachine")) {		
			NativeLib.currentMachine = newValue.toString();
			finish();
		}
		return true;
	}
}
