/***
	Copyright (c) 2008-2009 CommonsWare, LLC

	Licensed under the Apache License, Version 2.0 (the "License"); you may
	not use this file except in compliance with the License. You may obtain
	a copy of the License at
		http://www.apache.org/licenses/LICENSE-2.0
	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.
 */

package com.drodin.zxdroid.menu;

import android.app.ListActivity;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.preference.PreferenceManager;
import android.view.View;
import android.view.WindowManager;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import com.drodin.zxdroid.MainActivity;
import com.drodin.zxdroid.NativeLib;
import com.drodin.zxdroid.R;


public class SelectControl extends ListActivity {

	@Override
	public void onCreate(Bundle icicle) {
		super.onCreate(icicle);
				
		setTitle(R.string.onscreen_controls);
		
		getWindow().setFlags(WindowManager.LayoutParams.FLAG_BLUR_BEHIND,
				WindowManager.LayoutParams.FLAG_BLUR_BEHIND);

		setListAdapter(ArrayAdapter.createFromResource(
				this, R.array.control_entries, android.R.layout.simple_list_item_1));

	}

	@Override
	public void onListItemClick(ListView parent, View v, int position, long id) {
		NativeLib.onScreenControls = getResources().getStringArray(R.array.control_entries)[position];
		SharedPreferences settings = PreferenceManager.getDefaultSharedPreferences(this);
		SharedPreferences.Editor editor = settings.edit();
		editor.putString("onScreenControls", NativeLib.onScreenControls);
		editor.commit();
		MainActivity.mSoftControls.switchControl(NativeLib.onScreenControls);
		MainActivity.mSoftControls.setControlName();
		finish();
	}

}