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

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.zip.ZipEntry;
import java.util.zip.ZipInputStream;

import android.app.Activity;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.res.AssetManager;
import android.content.res.Configuration;
import android.os.Bundle;
import android.preference.PreferenceManager;
import android.util.Log;
import android.view.Display;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup.LayoutParams;
import android.widget.LinearLayout;

import com.admob.android.ads.AdListener;
import com.admob.android.ads.AdManager;
import com.admob.android.ads.AdView;
import com.drodin.zxdroid.menu.MenuTop;
import com.drodin.zxdroid.menu.SelectControl;
import com.drodin.zxdroid.menu.WelcomeMenu;

public class MainActivity extends Activity implements AdListener {

	private static Display mDispaly;

	public static MainActivity currentInstance = null;
	public static boolean firstRun = true;

	private static SharedPreferences settings = null;

	private static LinearLayout mMainLayout = null;
	private static LinearLayout mInnerLayout = null;
	private static MainView mMainView = null;
	private static View mControlsView = null;
	public static SoftControls mSoftControls = null;

	public static AdView adView = null;

	private static boolean menuOnTop = false;

	@Override
	protected void onCreate(Bundle icicle) {
		super.onCreate(icicle);

		currentInstance = this;
		settings = PreferenceManager.getDefaultSharedPreferences(this);

		InstallFiles();

		LoadSettings();

		NativeLib.displayOrientation = getResources().getConfiguration().orientation;

		mDispaly = getWindowManager().getDefaultDisplay();
		if (NativeLib.displayOrientation == Configuration.ORIENTATION_PORTRAIT) {
			NativeLib.displayWidth = mDispaly.getWidth();
			NativeLib.displayHeight = mDispaly.getHeight();
		} else {
			NativeLib.displayWidth = mDispaly.getHeight();
			NativeLib.displayHeight = mDispaly.getWidth();
		}

		NativeLib.mWidth = NativeLib.displayWidth;
		NativeLib.mHeight = (int)NativeLib.mWidth*NativeLib.spectrumScreenHeight/NativeLib.spectrumScreenWidth;

		//Process.setThreadPriority(Process.THREAD_PRIORITY_BACKGROUND);

		AdManager.setTestDevices(new String[] {AdManager.TEST_EMULATOR});

		createScreen();

	}

	private void createScreen() {
		if (mMainView != null)
			mMainView.onPause();

		if (mMainLayout != null)
			mMainLayout.setVisibility(View.INVISIBLE);

		NativeLib.displayOrientation = getResources().getConfiguration().orientation;

		mMainLayout = new LinearLayout(getApplicationContext());

		mInnerLayout = new LinearLayout(getApplicationContext());
		mInnerLayout.setOrientation(LinearLayout.VERTICAL);

		mMainView =	new MainView(getApplicationContext());
		mMainView.onPause();

		mControlsView = getLayoutInflater().inflate(R.layout.controls, null);
		mSoftControls = (SoftControls) mControlsView.findViewById(R.id.keyboardView);

		adView = new AdView(this);
		adView.setAdListener(this);
		adView.setGravity(Gravity.BOTTOM);

		if (NativeLib.displayOrientation==Configuration.ORIENTATION_PORTRAIT) {
			mMainLayout.setOrientation(LinearLayout.VERTICAL);
			mInnerLayout.addView(mMainView,
					new LayoutParams(NativeLib.mWidth, NativeLib.mHeight));	
			mMainLayout.addView(mInnerLayout);
			mMainLayout.addView(mControlsView,
					new LayoutParams(NativeLib.mWidth, mSoftControls.mControl.getHeight()));
			mMainLayout.addView(adView,
					new LayoutParams(LayoutParams.WRAP_CONTENT, LayoutParams.FILL_PARENT));
		} else {
			mMainLayout.setOrientation(LinearLayout.HORIZONTAL);
			/*if (NativeLib.hideControls) {
				mInnerLayout.setLayoutParams(
						new LayoutParams(
								NativeLib.mWidth*NativeLib.spectrumScreenWidth/NativeLib.spectrumScreenHeight,
								NativeLib.mWidth));
				mInnerLayout.addView(mMainView,
						new LayoutParams(
								NativeLib.mWidth*NativeLib.spectrumScreenWidth/NativeLib.spectrumScreenHeight,
								NativeLib.mWidth));
			} else {*/
				mMainLayout.addView(mControlsView,
						new LayoutParams(NativeLib.displayHeight-NativeLib.mWidth, NativeLib.mWidth));
				mInnerLayout.setLayoutParams(
						new LayoutParams(NativeLib.mWidth, LayoutParams.FILL_PARENT));
				mInnerLayout.addView(mMainView,
						new LayoutParams(NativeLib.mWidth, NativeLib.mHeight));
				mInnerLayout.addView(adView,
						new LayoutParams(LayoutParams.WRAP_CONTENT, LayoutParams.FILL_PARENT));
			//}
			mMainLayout.addView(mInnerLayout);
		}

		System.gc();

		setContentView(mMainLayout);

		mSoftControls.setControlName();

		if (mMainView != null && menuOnTop == false)
			mMainView.onResume();
	}

	@Override
	public void onConfigurationChanged (Configuration newConfig) {
		Log.i("zxdroid","congig changed");
		if (mSoftControls.capPressed)
			NativeLib.eventQueue.add(NativeLib.KEY_RELEASE + NativeLib.spectrumKeyCap);
		if(mSoftControls.symPressed)
			NativeLib.eventQueue.add(NativeLib.KEY_RELEASE + NativeLib.spectrumKeySym);
		if (mSoftControls.fireLock != 0 )
			NativeLib.eventQueue.add(NativeLib.KEY_RELEASE + mSoftControls.fireLock);
		super.onConfigurationChanged(newConfig);
		createScreen();
	}

	@Override
	protected void onResume() {
		super.onResume();
		if (mMainView != null)
			mMainView.onResume();
	}

	@Override
	protected void onPause() {
		super.onPause();
		if (mMainView != null)
			mMainView.onPause();
	}

	@Override
	protected void onDestroy() {
		super.onDestroy();

		if (NativeLib.tmpUncompressedFN != null) {
			File tmpFile = new File(NativeLib.tmpUncompressedFN);
			tmpFile.delete();
		}

		SharedPreferences.Editor editor = settings.edit();
		editor.putString("startDir", NativeLib.startDir);
		editor.commit();

		NativeLib.quit();

		if (mMainView != null)
			mMainView = null;
		if (mSoftControls != null)
			mSoftControls = null;
		System.gc();
		System.exit(0);
	}

	public void showMenu () {
		if (!menuOnTop) {
			menuOnTop = true;
			startActivityForResult(new Intent(this, MenuTop.class), 0);
		}
	}
	
	public void showSelectControl () {
		if (!menuOnTop) {
			menuOnTop = true;
			startActivityForResult(new Intent(this, SelectControl.class), 0);
		}
	}
	
	public void showWelcomeMenu () {
		if (!menuOnTop) {
			menuOnTop = true;
			startActivityForResult(new Intent(this, WelcomeMenu.class), 0);
		}
	}

	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
		super.onActivityResult(requestCode, resultCode, data);

		if (resultCode == RESULT_OK && requestCode == 0) {

			final String openFileName = data.getStringExtra("openFileName");
			if (openFileName != null) NativeLib.openFileName = openFileName;

			final String saveFileName = data.getStringExtra("saveFileName");
			if (saveFileName != null) NativeLib.saveFileName = saveFileName;

			final int menuEventValue = data.getIntExtra("menuEventValue", 0);
			switch (menuEventValue) {
			case 0:
				break;
			case NativeLib.MENU_FILE_EXIT:
				finish();
				break;
			default:
				NativeLib.eventQueue.add(NativeLib.MENU_EVENT + menuEventValue);
				break;
			}
		}
		menuOnTop = false;
	}

	private void LoadSettings() {
		final String definedKeys = settings.getString("definedKeys", NativeLib.defaultDefinedKeys);
		if (definedKeys.contains(";")) {
			final String[] keyPairs = definedKeys.split(";");
			for (int i=0; i<keyPairs.length; i++)
				NativeLib.definiedKeys[Integer.parseInt(keyPairs[i].split(":")[0])]
				                       = Integer.parseInt(keyPairs[i].split(":")[1]);
		}

		NativeLib.frameSkip = settings.getBoolean("frameSkip", false);
		NativeLib.smoothScaling = settings.getBoolean("smoothScaling", true);
		NativeLib.soundEnabled = settings.getBoolean("soundEnabled", false);
		NativeLib.trackballSensitivity = settings.getInt("trackballSensitivity", 3);
		NativeLib.interceptMenuBack = settings.getBoolean("interceptMenuBack", false);
		NativeLib.onScreenControls = settings.getString("onScreenControls", "Kempston");
		//NativeLib.currentMachine = settings.getString("currentMachine", "128");
		NativeLib.currentMachine = "128";
		NativeLib.startDir = settings.getString("startDir", NativeLib.sdcardDir);

	}

	private void InstallFiles() {

		final String outdir = "/data/data/" + getPackageName() + "/files/";
		final AssetManager mAssetManager = getApplication().getResources().getAssets();

		try {
			File dir = new File(outdir);
			if (!dir.exists()) {
				dir.mkdir();
			}
			ZipInputStream zs = new ZipInputStream(mAssetManager.open("files.zip", AssetManager.ACCESS_BUFFER));
			ZipEntry ze;
			while((ze = zs.getNextEntry())!=null) {
				long filesize = ze.getSize();
				File outfile = new File(outdir, ze.getName());
				if (outfile.exists())
					continue;
				byte[] tempdata = new byte[(int)filesize];
				int offset = 0;
				while (offset<filesize)
					offset += zs.read(tempdata, offset, (int)filesize-offset);
				zs.closeEntry();
				outfile.createNewFile();
				FileOutputStream fo = new FileOutputStream(outfile);
				fo.write(tempdata);
				fo.close();
			}
			zs.close();
		} catch(IOException e) { }
	}

	@Override
	public void onFailedToReceiveAd(AdView arg0) {
		// TODO Auto-generated method stub

	}

	@Override
	public void onFailedToReceiveRefreshedAd(AdView arg0) {
		// TODO Auto-generated method stub

	}

	@Override
	public void onReceiveAd(AdView arg0) {
		// TODO Auto-generated method stub

	}

	@Override
	public void onReceiveRefreshedAd(AdView arg0) {
		// TODO Auto-generated method stub

	}

}
