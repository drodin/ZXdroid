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

import android.app.ListActivity;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.view.WindowManager;
import android.widget.ArrayAdapter;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.TextView;

import com.drodin.zxdroid.NativeLib;
import com.drodin.zxdroid.R;

public class DefineKeys extends ListActivity {

	private int spectrumKeyCode = 0;

	@Override
	public void onCreate(Bundle icicle) {
		super.onCreate(icicle);

		getWindow().setFlags(WindowManager.LayoutParams.FLAG_BLUR_BEHIND,
				WindowManager.LayoutParams.FLAG_BLUR_BEHIND);

		drawListAdapter();

	}

	private void drawListAdapter() {
		final Context context = this;

		ArrayAdapter<String> keyLabelsAdapter = new ArrayAdapter<String>(
				this, android.R.layout.simple_list_item_1, NativeLib.spectrumKeys) {
			@Override
			public View getView(final int position, final View convertView, final ViewGroup parent) {
				return new Modified(context, getItem(position), position);
			}
		};

		setListAdapter(keyLabelsAdapter);		
	}

	@Override
	public void onListItemClick(ListView parent, View v, int position, long id) {
		spectrumKeyCode = position;
		startActivityForResult(new Intent(this, KeySelect.class).putExtra("spectrumKeyCode", spectrumKeyCode), 0);
	}

	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
		super.onActivityResult(requestCode, resultCode, data);
		if (resultCode == RESULT_OK && requestCode == 0) {
			int androidKeyCode = data.getIntExtra("androidKeyCode", 0);
			for (int i=0; i<NativeLib.definiedKeys.length; i++)
				if (NativeLib.definiedKeys[i] == spectrumKeyCode)
					NativeLib.definiedKeys[i] = 0;
			if (androidKeyCode!=0)
				NativeLib.definiedKeys[androidKeyCode] = spectrumKeyCode;
			drawListAdapter();
		}
	}

	class Modified extends LinearLayout {

		public Modified(final Context context, final String keyLabel, final int position) {
			super(context);

			if (keyLabel!=null) { 

				setOrientation(HORIZONTAL);

				final TextView textView = new TextView(context);
				textView.setTextAppearance(context, R.style.ListText);

				final TextView textView2 = new TextView(context);
				textView2.setTextAppearance(context, R.style.ListTextSmall);

				textView.setText(keyLabel);
				textView.setPadding(10, 0, 0, 0);

				textView2.setText("?");
				for (int i=0; i<NativeLib.definiedKeys.length; i++)
					if (NativeLib.definiedKeys[i]!=0 && NativeLib.definiedKeys[i]==position) {
						textView2.setText(NativeLib.androidKeys[i]);
						continue;
					}
				textView2.setGravity(Gravity.RIGHT);
				textView2.setPadding(0, 0, 10, 0);
				
				addView(textView, new LinearLayout.LayoutParams(
						LayoutParams.WRAP_CONTENT, LayoutParams.WRAP_CONTENT));
				addView(textView2, new LinearLayout.LayoutParams(
						LayoutParams.FILL_PARENT, LayoutParams.WRAP_CONTENT));

			} else {

				final View hiddenView = new View(context);
				hiddenView.setVisibility(INVISIBLE);
				addView(hiddenView, new LinearLayout.LayoutParams(0,0));

			}

		}

	}

}

