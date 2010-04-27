
package com.drodin.zxdroid.menu;

import java.io.IOException;
import java.io.InputStream;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;

import com.drodin.zxdroid.R;


public class HelpView extends Activity
{
    @Override
	protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

        try {
        	
            InputStream is = getAssets().open("help.txt");
            
            int size = is.available();
            
            byte[] buffer = new byte[size];
            is.read(buffer);
            is.close();
            
            String text = new String(buffer);
            
            setContentView(R.layout.help);
            
            TextView tv = (TextView)findViewById(R.id.help_tv);
            tv.setText(text);
            
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}

