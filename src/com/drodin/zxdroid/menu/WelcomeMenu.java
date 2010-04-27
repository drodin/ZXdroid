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

import java.io.File;
import java.util.ArrayList;
import java.util.Arrays;

import android.app.ListActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.WindowManager;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import com.drodin.zxdroid.NativeLib;
import com.drodin.zxdroid.R;


public class WelcomeMenu extends ListActivity {

	private int positionDelta = 0;

	@Override
	public void onCreate(Bundle icicle) {
		super.onCreate(icicle);

		getWindow().setFlags(WindowManager.LayoutParams.FLAG_BLUR_BEHIND,
				WindowManager.LayoutParams.FLAG_BLUR_BEHIND);

		ArrayList<String> menuItems =
			new ArrayList<String>(Arrays.asList(getResources().getStringArray(R.array.welcome_menu)));

		File lastSnapshot = new File("/data/data/" + getPackageName() + "/files/last.snapshot");
		if (!lastSnapshot.exists()) {
			menuItems.remove(0);
			positionDelta++;
		}

		ArrayAdapter<String> menuItemsAdapter = 
			new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, menuItems);

		setListAdapter(menuItemsAdapter);
		

	}

	@Override
	public void onListItemClick(ListView parent, View v, int position, long id) {
		position += positionDelta;
		switch (position) {
		case 0:
			final Intent extras = new Intent();
			extras.putExtra("menuEventValue", NativeLib.MENU_FILE_OPEN);
			extras.putExtra("openFileName", "/data/data/" + getPackageName() + "/files/last.snapshot");
			setResult(RESULT_OK, extras);
			finish();
			break;
		case 1:
			startActivityForResult(new Intent(this, FileOpen.class), 0);
			break;
		case 2:
			startActivityForResult(new Intent(this, FileOpen.class).
					putExtra("startDir", "/data/data/" + getPackageName() + "/files"), 0);
			break;
		case 3:
			finish();
			break;
		case 4:
			startActivityForResult(new Intent(this, HelpView.class), 0);
			break;
		default:
			finish();
			break;
		}
	}
	
	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
		super.onActivityResult(requestCode, resultCode, data);
		if (resultCode == RESULT_OK && requestCode == 0) {
			setResult(RESULT_OK, data);
		}
		finish();
	}

}