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
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Enumeration;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

import android.app.ListActivity;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;
import android.view.WindowManager;
import android.widget.ArrayAdapter;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.TextView;

import com.drodin.zxdroid.NativeLib;
import com.drodin.zxdroid.R;

public class FileOpen extends ListActivity {

	private String startDir;

	private final static String PARENT_DIR = "..";

	private TextView pathView;

	protected final List<String> currentFiles = new ArrayList<String>();

	private File currentDir = null;

	@Override
	public void onCreate(final Bundle icicle) {
		super.onCreate(icicle);

		setContentView(R.layout.file_open);

		getWindow().setFlags(WindowManager.LayoutParams.FLAG_BLUR_BEHIND,
				WindowManager.LayoutParams.FLAG_BLUR_BEHIND);

		pathView = (TextView) findViewById(R.id.file_tv);

		startDir = getIntent().getStringExtra("startDir");

		try {
			if(startDir != null)
				showDirectory(startDir);
			else
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
				String name = this.currentFiles.get(position);
				String extension = name.indexOf('.') > 0 ? name.substring(name.lastIndexOf('.') + 1) : "";

				if (extension.toLowerCase().equals("zip"))
					name = handleZip(name);

				final Intent extras = new Intent();
				extras.putExtra("menuEventValue", NativeLib.MENU_FILE_OPEN);
				extras.putExtra("openFileName", name);
				setResult(RESULT_OK, extras);
				finish();
			}
		}
	}

	private void showDirectory(final String path) {
		if (startDir == null)
			NativeLib.startDir = path;

		this.currentFiles.clear();
		this.currentDir = new File(path);

		pathView.setText(currentDir.getAbsolutePath()+"/");

		if (this.currentDir.getParentFile() != null && !path.equals(startDir)) {
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

				if (
						startDir == null && 
						NativeLib.supportExt.contains(extension.toLowerCase()) && 
						!(name.contains(NativeLib.tmpFilePrefix))
				) {
					sortedFiles.add(name);
				} else if (startDir != null && extension.toLowerCase().equals("sna")) {
					sortedFiles.add(name);
				}
				
			}
		}
		this.currentFiles.addAll(sortedDirs);
		this.currentFiles.addAll(sortedFiles);

		final Context context = this;

		ArrayAdapter<String> filenamesAdapter = new ArrayAdapter<String>(this, android.R.layout.simple_expandable_list_item_1, this.currentFiles) {
			@Override
			public View getView(final int position, final View convertView, final ViewGroup parent) {
				return new ModifiedTextLayout(context, getItem(position), position);
			}
		};

		setListAdapter(filenamesAdapter);
	}

	private String handleZip(String name) {
		if (NativeLib.tmpUncompressedFN!=null) {
			File oldFile = new File(NativeLib.tmpUncompressedFN);
			oldFile.delete();
		}
		try {
			boolean handled = false;
			ZipFile zf = new ZipFile(name);
			Enumeration<? extends ZipEntry> zes = zf.entries();
			while(zes.hasMoreElements() && !handled) {
				ZipEntry ze = zes.nextElement();
				String zename = ze.getName();
				String zeext = zename.indexOf('.') > 0 ? zename.substring(zename.lastIndexOf('.') + 1) : "";
				if (NativeLib.supportExt.contains(zeext.toLowerCase())) {
					InputStream is = zf.getInputStream(ze);
					int offset = 0;
					long filesize = ze.getSize();
					byte[] tempdata = new byte[(int)filesize];
					while (offset<filesize)
						offset += is.read(tempdata, offset, (int)filesize-offset);
					is.close();
					name = NativeLib.tmpUncompressedFN =
						NativeLib.sdcardDir + "/" + NativeLib.tmpFilePrefix + zename;
					File outfile = new File(NativeLib.tmpUncompressedFN);
					outfile.delete();
					outfile.createNewFile();
					FileOutputStream fo = new FileOutputStream(outfile);
					fo.write(tempdata);
					fo.close();
					handled = true;
				}
			}
			zf.close();
		} catch (IOException e) { }
		System.gc();
		return name;
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
