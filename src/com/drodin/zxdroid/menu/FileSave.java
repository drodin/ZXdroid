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

import java.io.File;
import java.util.ArrayList;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;

import android.app.ListActivity;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;
import android.view.WindowManager;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.TextView;

import com.drodin.zxdroid.NativeLib;
import com.drodin.zxdroid.R;

public class FileSave extends ListActivity {

	private final static String PARENT_DIR = "..";

	private TextView pathView;
	private EditText fileSave;
	private Button saveButton;

	protected final List<String> currentFiles = new ArrayList<String>();

	private File currentDir = null;

	private final String validChars = "qwertyuiopasdfghjklzxcvbnm1234567890_-";
	private String validString(String in) {
		in = in.toLowerCase();
		String out = "";
		for (int i=0; i<in.length(); i++) {
			char c = in.charAt(i);
			if (validChars.indexOf(c) != -1)
				out += c;
		}
		if (!out.equals(""))
			return out;
		else
			return getString(R.string.default_save_fn);
	}

	@Override
	public void onCreate(final Bundle icicle) {
		super.onCreate(icicle);

		setContentView(R.layout.file_save);

		getWindow().setFlags(WindowManager.LayoutParams.FLAG_BLUR_BEHIND,
				WindowManager.LayoutParams.FLAG_BLUR_BEHIND);

		pathView = (TextView) findViewById(R.id.savepath_tv);
		fileSave = (EditText) findViewById(R.id.savefn_et);
		//fileSave.requestFocus();

		saveButton = (Button) findViewById(R.id.save_btn);
		saveButton.setOnClickListener(new View.OnClickListener() {

			@Override
			public void onClick(View v) {
				final Intent extras = new Intent();
				extras.putExtra("menuEventValue", NativeLib.MENU_FILE_SAVESNAPSHOT);
				extras.putExtra("saveFileName",
						(String)(pathView.getText() + 
								validString(fileSave.getText().toString()) + 
								getString(R.string.save_ext)));
				setResult(RESULT_OK, extras);
				finish();
			}
		});

		try {
			showDirectory(NativeLib.startDir);
		} catch (NullPointerException e) {
			try {
				showDirectory(NativeLib.sdcardDir);
			} catch (NullPointerException e2) {
				showDirectory("/");
			}
		}
	}

	@Override
	protected void onListItemClick(final ListView l, final View v, final int position, final long id) {
		if (position == 0 && PARENT_DIR.equals(this.currentFiles.get(0))) {
			showDirectory(this.currentDir.getParent());
		} else {
			final File file = new File(this.currentFiles.get(position));

			if (file.isDirectory()) {
				showDirectory(file.getAbsolutePath());
			} else {
				final String fname = this.currentFiles.get(position);
				fileSave.setText(fname.subSequence(fname.lastIndexOf("/")+1, fname.lastIndexOf(".")));
				fileSave.requestFocus();
			}
		}
	}

	private void showDirectory(final String path) {
		NativeLib.startDir = path;

		this.currentFiles.clear();
		this.currentDir = new File(path);

		pathView.setText(currentDir.getAbsolutePath()+"/");

		if (this.currentDir.getParentFile() != null ) {
			this.currentFiles.add(PARENT_DIR);
		}

		final File[] files = this.currentDir.listFiles();
		final Set<String> sortedFiles = new TreeSet<String>();
		final Set<String> sortedDirs = new TreeSet<String>();

		for (final File file : files) {
			final String name = file.getAbsolutePath();

			if (file.isDirectory()) {
				sortedDirs.add(name);
			} else {
				final String extension = name.indexOf('.') > 0 ? name.substring(name.lastIndexOf('.') + 1) : "";


				if (extension.toLowerCase().equals("sna")) {
					sortedFiles.add(name);
				}
			}
		}
		this.currentFiles.addAll(sortedDirs);
		this.currentFiles.addAll(sortedFiles);

		final Context context = this;

		ArrayAdapter<String> filenamesAdapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, this.currentFiles) {
			@Override
			public View getView(final int position, final View convertView, final ViewGroup parent) {
				return new ModifiedTextLayout(context, getItem(position), position);
			}
		};

		setListAdapter(filenamesAdapter);
	}

	class ModifiedTextLayout extends LinearLayout {

		public ModifiedTextLayout(final Context context, final String path, final int position) {
			super(context);

			setOrientation(HORIZONTAL);

			final File file = new File(path);

			final TextView textView = new TextView(context);
			textView.setTextAppearance(context, R.style.ListText);

			if (file.isDirectory()) {
				textView.setText("/" + file.getName());
			} else {
				textView.setText(file.getName());
			}

			addView(textView, new LinearLayout.LayoutParams(
					LayoutParams.FILL_PARENT, LayoutParams.WRAP_CONTENT));
		}
	}

}
