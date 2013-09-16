package com.sommer.remote;

import com.sommer.allremote.R;
import com.sommer.service.RemoteUpdateService;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.view.KeyEvent;

public class Start extends Activity {
	private final int SPLASH_DISPLAY_LENGHT = 2000;//Integer.valueOf(this.getString(R.string.splash_delay_value));
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_start);
        startService(new Intent(this, RemoteUpdateService.class));
        new Handler().postDelayed(new Runnable() {
			public void run() {
				Intent mainIntent = new Intent(Start.this,
						MainActivity.class);
				startActivity(mainIntent);
				finish();
			}

		}, SPLASH_DISPLAY_LENGHT);
    }
	@Override
	public boolean onKeyDown(int keyCode, KeyEvent event) {
		// TODO Auto-generated method stub
		if (keyCode == KeyEvent.KEYCODE_BACK) {
			return true;
		} else {
			return super.onKeyDown(keyCode, event);
		}
	}
}