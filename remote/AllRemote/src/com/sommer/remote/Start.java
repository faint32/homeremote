package com.sommer.remote;

import java.io.IOException;

import com.sommer.allremote.R;
import com.sommer.service.RemoteUpdateService;
import com.sommer.utils.RemoteDB;
import com.sommer.utils.UserDB;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.view.KeyEvent;

public class Start extends Activity {
	private final int SPLASH_DISPLAY_LENGHT = 2000;//Integer.valueOf(this.getString(R.string.splash_delay_value));
	 
	  private RemoteDB mRmtDB = null;
	  private UserDB mUserDB = null;
	  Context mContext;
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_start);
        mContext = getApplicationContext();
        mRmtDB = new RemoteDB(mContext);
    	try {
    		mRmtDB.createDataBase();
    	} catch (IOException e) {
    		// TODO Auto-generated catch block
    		e.printStackTrace();
    	}

    	
    	mUserDB = new UserDB(mContext);
    	try {
    		mUserDB.createDataBase();
    	} catch (IOException e) {
    		// TODO Auto-generated catch block
    		e.printStackTrace();
    	}
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
