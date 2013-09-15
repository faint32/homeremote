package com.sommer.remote;



import com.sommer.allremote.R;

import com.sommer.data.Value;
import com.sommer.ircore.KeyTreate;


import android.content.Intent;
import android.os.Bundle;
import android.util.DisplayMetrics;
import android.view.KeyEvent;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;


public class DVDRemote extends BaseActivity implements OnClickListener {
//	TextView keyValueIndex;
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		
		setContentView(R.layout.activity_dvd);
		
		Intent intent = getIntent();   
		Value.currentDevice = intent.getIntExtra("current", 0);
		
		DisplayMetrics dm = new DisplayMetrics();
		getWindowManager().getDefaultDisplay().getMetrics(dm);
		int screenWidth = dm.widthPixels;
		int screenHeight = dm.heightPixels;
		
		Button dvd_av = (Button)findViewById(R.id.dvd_av);
		dvd_av.setOnClickListener(this);
		dvd_av.setWidth((screenWidth) / 4);
		dvd_av.setHeight((screenHeight) / 10);
		
		
		Button dvd_back = (Button)findViewById(R.id.dvd_back);
		dvd_back.setOnClickListener(this);
		dvd_back.setWidth((screenWidth) / 4);
		dvd_back.setHeight((screenHeight) / 10);
		
		
		Button dvd_down = (Button)findViewById(R.id.dvd_down);
		dvd_down.setOnClickListener(this);
		dvd_down.setWidth((screenWidth) / 4);
		dvd_down.setHeight((screenHeight) / 10);
		
		
		Button dvd_downsong = (Button)findViewById(R.id.dvd_downsong);
		dvd_downsong.setOnClickListener(this);
		dvd_downsong.setWidth((screenWidth) / 4);
		dvd_downsong.setHeight((screenHeight) / 10);
		
		
		Button dvd_left = (Button)findViewById(R.id.dvd_left);
		dvd_left.setOnClickListener(this);
		dvd_left.setWidth((screenWidth) / 4);
		dvd_left.setHeight((screenHeight) / 10);
	
		
		Button dvd_menu = (Button)findViewById(R.id.dvd_menu);
		dvd_menu.setOnClickListener(this);
		dvd_menu.setWidth((screenWidth) / 4);
		dvd_menu.setHeight((screenHeight) / 10);
		
		
		Button dvd_mute = (Button)findViewById(R.id.dvd_mute);
		dvd_mute.setOnClickListener(this);
		dvd_mute.setWidth((screenWidth) / 4);
		dvd_mute.setHeight((screenHeight) / 10);
		
		
		Button dvd_ok = (Button)findViewById(R.id.dvd_ok);
		dvd_ok.setOnClickListener(this);
		dvd_ok.setWidth((screenWidth) / 4);
		dvd_ok.setHeight((screenHeight) / 10);
		
		
		Button dvd_open = (Button)findViewById(R.id.dvd_open);
		dvd_open.setOnClickListener(this);
		dvd_open.setWidth((screenWidth) / 4);
		dvd_open.setHeight((screenHeight) / 10);
		
		
		Button dvd_pause = (Button)findViewById(R.id.dvd_pause);
		dvd_pause.setOnClickListener(this);
		dvd_pause.setWidth((screenWidth) / 4);
		dvd_pause.setHeight((screenHeight) / 10);
		
		
		Button dvd_play = (Button)findViewById(R.id.dvd_play);
		dvd_play.setOnClickListener(this);	
		dvd_play.setWidth((screenWidth) / 4);
		dvd_play.setHeight((screenHeight) / 10);
	
		
		Button dvd_power = (Button)findViewById(R.id.dvd_power);
		dvd_power.setOnClickListener(this);
		dvd_power.setWidth((screenWidth) / 4);
		dvd_power.setHeight((screenHeight) / 10);
	
		
		Button dvd_quickback = (Button)findViewById(R.id.dvd_quickback);
		dvd_quickback.setOnClickListener(this);
		dvd_quickback.setWidth((screenWidth) / 4);
		dvd_quickback.setHeight((screenHeight) / 10);

		
		Button dvd_quickforward = (Button)findViewById(R.id.dvd_quickforward);
		dvd_quickforward.setOnClickListener(this);
		dvd_quickforward.setWidth((screenWidth) / 4);
		dvd_quickforward.setHeight((screenHeight) / 10);

		
		Button dvd_right = (Button)findViewById(R.id.dvd_right);
		dvd_right.setOnClickListener(this);
		dvd_right.setWidth((screenWidth) / 4);
		dvd_right.setHeight((screenHeight) / 10);

		
		Button dvd_stop = (Button)findViewById(R.id.dvd_stop);
		dvd_stop.setOnClickListener(this);
		dvd_stop.setWidth((screenWidth) / 4);
		dvd_stop.setHeight((screenHeight) / 10);

		
		Button dvd_title = (Button)findViewById(R.id.dvd_title);
		dvd_title.setOnClickListener(this);
		dvd_title.setWidth((screenWidth) / 4);
		dvd_title.setHeight((screenHeight) / 10);

		
		Button dvd_up = (Button)findViewById(R.id.dvd_up);
		dvd_up.setOnClickListener(this);
		dvd_up.setWidth((screenWidth) / 4);
		dvd_up.setHeight((screenHeight) / 10);
	
		
		Button dvd_upsong = (Button)findViewById(R.id.dvd_upsong);
		dvd_upsong.setOnClickListener(this);
		dvd_upsong.setWidth((screenWidth) / 4);
		dvd_upsong.setHeight((screenHeight) / 10);
	
		
//		 keyValueIndex = (TextView) findViewById(R.id.dvd_showkey);
//		 keyValueIndex.setTextSize(24);
//		 keyValueIndex.setWidth((screenWidth) / 4);
//		 keyValueIndex.setHeight((screenHeight) / 10);

	}
	@Override
	public void onStart()
	{
		super.onStart();
	
		
	}
	@Override
	public boolean onKeyDown(int keyCode, KeyEvent event) {
		// TODO Auto-generated method stub
		if (keyCode == KeyEvent.KEYCODE_BACK) {
			
			if (event.isLongPress()) {
				openOptionsMenu();
				return true;
			}
			return true;
		} else {
			return super.onKeyDown(keyCode, event);
		}
	}
	public void onClick(View v) {
		// TODO Auto-generated method stub
		switch(v.getId())
		{
	
		

		case R.id.dvd_av:
			Value.currentKey =  "dvd_av";
			break;
		case R.id.dvd_back:
			Value.currentKey = "dvd_back";
			break;
		case R.id.dvd_down:
			Value.currentKey ="dvd_down";
			break;
		case R.id.dvd_downsong:
			Value.currentKey = "dvd_downsong";
			break;
		case R.id.dvd_left:
			Value.currentKey ="dvd_left";
			break;
		case R.id.dvd_menu:
			Value.currentKey = "dvd_menu";
			break;
		case R.id.dvd_mute:
			Value.currentKey ="dvd_mute";
			break;
		case R.id.dvd_open:
			Value.currentKey ="dvd_open";
			break;
		case R.id.dvd_pause:
			Value.currentKey ="dvd_pause";
			break;
		case R.id.dvd_play:
			Value.currentKey ="dvd_play";
			break;
		case R.id.dvd_ok:
			Value.currentKey = "dvd_ok";
			break;
		case R.id.dvd_power:
			Value.currentKey ="dvd_power";
			break;
		case R.id.dvd_quickback:
			Value.currentKey = "dvd_quickback";
			break;
		case R.id.dvd_quickforward:
			Value.currentKey = "dvd_quickforward";
			break;
		case R.id.dvd_right:
			Value.currentKey = "dvd_right";
			break;
		case R.id.dvd_title:
			Value.currentKey = "dvd_title";
			break;
		case R.id.dvd_up:
			Value.currentKey = "dvd_up";
			break;
		case R.id.dvd_upsong:
			Value.currentKey = "dvd_upsong";
			break;
		case R.id.dvd_stop:
			Value.currentKey = "dvd_stop";
			break;
		default:
			Value.currentKey = null;
		}
		if (Value.currentKey != null) {
			KeyTreate.getInstance().keyTreate(Value.currentDevice ,Value.currentKey);	

			
		}
	}
}