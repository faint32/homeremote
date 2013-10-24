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


public class FanRemote extends BaseActivity implements OnClickListener {
	

	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_fan);
		
		Intent intent = getIntent();   
		Value.currentDevice = intent.getIntExtra("current", 0);
		
		DisplayMetrics dm = new DisplayMetrics();
		getWindowManager().getDefaultDisplay().getMetrics(dm);
		int screenWidth = dm.widthPixels;
		int screenHeight = dm.heightPixels;
		
		Button fan_key0 = (Button) findViewById(R.id.fan_key0);
		fan_key0.setOnClickListener(this);
		fan_key0.setWidth((screenWidth) / 4);
		fan_key0.setHeight((screenHeight) / 11);
		
		
		Button fan_key1 = (Button) findViewById(R.id.fan_key1);
		fan_key1.setOnClickListener(this);
		fan_key1.setWidth((screenWidth) / 4);
		fan_key1.setHeight((screenHeight) / 11);
		
		
		Button fan_key2 = (Button) findViewById(R.id.fan_key2);
		fan_key2.setOnClickListener(this);
		fan_key2.setWidth((screenWidth) / 4);
		fan_key2.setHeight((screenHeight) / 11);
		
		
		Button fan_key3 = (Button) findViewById(R.id.fan_key3);
		fan_key3.setOnClickListener(this);
		fan_key3.setWidth((screenWidth) / 4);
		fan_key3.setHeight((screenHeight) / 11);
		
		
		Button fan_key4 = (Button) findViewById(R.id.fan_key4);
		fan_key4.setOnClickListener(this);
		fan_key4.setWidth((screenWidth) / 4);
		fan_key4.setHeight((screenHeight) / 11);
	
		
		Button fan_key5 = (Button) findViewById(R.id.fan_key5);
		fan_key5.setOnClickListener(this);
		fan_key5.setWidth((screenWidth) / 4);
		fan_key5.setHeight((screenHeight) / 11);
	
		
		Button fan_key6 = (Button) findViewById(R.id.fan_key6);
		fan_key6.setOnClickListener(this);
		fan_key6.setWidth((screenWidth) / 4);
		fan_key6.setHeight((screenHeight) / 11);
		
		
		Button fan_key7 = (Button) findViewById(R.id.fan_key7);
		fan_key7.setOnClickListener(this);
		fan_key7.setWidth((screenWidth) / 4);
		fan_key7.setHeight((screenHeight) / 11);
	
		Button fan_key8 = (Button) findViewById(R.id.fan_key8);
		fan_key8.setOnClickListener(this);
		fan_key8.setWidth((screenWidth) / 4);
		fan_key8.setHeight((screenHeight) / 11);
		
		
		Button fan_key9 = (Button) findViewById(R.id.fan_key9);
		fan_key9.setOnClickListener(this);
		fan_key9.setWidth((screenWidth) / 4);
		fan_key9.setHeight((screenHeight) / 11);
	
		
		Button fan_power = (Button) findViewById(R.id.fan_power);
		fan_power.setOnClickListener(this);
		fan_power.setWidth((screenWidth) / 4);
		fan_power.setHeight((screenHeight) / 11);
	
		
		Button fan_timer = (Button) findViewById(R.id.fan_timer);
		fan_timer.setOnClickListener(this);
		fan_timer.setWidth((screenWidth) / 4);
		fan_timer.setHeight((screenHeight) / 11);
	
		
		Button fan_li = (Button) findViewById(R.id.fan_li);
		fan_li.setOnClickListener(this);
		fan_li.setWidth((screenWidth) / 4);
		fan_li.setHeight((screenHeight) / 11);
	
		Button fan_cool = (Button) findViewById(R.id.fan_cool);
		fan_cool.setOnClickListener(this);
		fan_cool.setWidth((screenWidth) / 4);
		fan_cool.setHeight((screenHeight) / 11);
		
		
		Button fan_mode = (Button) findViewById(R.id.fan_mode);
		fan_mode.setOnClickListener(this);
		fan_mode.setWidth((screenWidth) / 4);
		fan_mode.setHeight((screenHeight) / 11);
		
		
		Button fan_sleep = (Button) findViewById(R.id.fan_sleep);
		fan_sleep.setOnClickListener(this);
		fan_sleep.setWidth((screenWidth) / 4);
		fan_sleep.setHeight((screenHeight) / 11);
	
		
		Button fan_light = (Button) findViewById(R.id.fan_light);
		fan_light.setOnClickListener(this);
		fan_light.setWidth((screenWidth) / 4);
		fan_light.setHeight((screenHeight) / 11);
	
		
		Button fan_speed = (Button) findViewById(R.id.fan_speed);
		fan_speed.setOnClickListener(this);
		fan_speed.setWidth((screenWidth) / 4);
		fan_speed.setHeight((screenHeight) / 11);
		
		
		Button fan_speedlow = (Button) findViewById(R.id.fan_speedlow);
		fan_speedlow.setOnClickListener(this);
		fan_speedlow.setWidth((screenWidth) / 4);
		fan_speedlow.setHeight((screenHeight) / 11);
		
		
		Button fan_speedmiddle = (Button) findViewById(R.id.fan_speedmiddle);
		fan_speedmiddle.setOnClickListener(this);
		fan_speedmiddle.setWidth((screenWidth) / 4);
		fan_speedmiddle.setHeight((screenHeight) / 11);
		
		
		Button fan_speedhight = (Button) findViewById(R.id.fan_speedhight);
		fan_speedhight.setOnClickListener(this);
		fan_speedhight.setWidth((screenWidth) / 4);
		fan_speedhight.setHeight((screenHeight) / 11);
	
		
		Button fan_freq = (Button) findViewById(R.id.fan_freq);
		fan_freq.setOnClickListener(this);
		fan_freq.setWidth((screenWidth) / 4);
		fan_freq.setHeight((screenHeight) / 11);
	

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
		switch (v.getId()) {
		
		case R.id.fan_key0:
			Value.currentKey = "fans_key0";
			break;
		case R.id.fan_key1:
			Value.currentKey = "fans_key1";
			break;
		case R.id.fan_key2:
			Value.currentKey = "fans_key2";
			break;
		case R.id.fan_key3:
			Value.currentKey = "fans_key3";
			break;
		case R.id.fan_key4:
			Value.currentKey = "fans_key4";
			break;
		case R.id.fan_key5:
			Value.currentKey = "fans_key5";
			break;
		case R.id.fan_key6:
			Value.currentKey = "fans_key6";
			break;
		case R.id.fan_key7:
			Value.currentKey = "fans_key7";
			break;
		case R.id.fan_key8:
			Value.currentKey = "fans_key8";
			break;
		case R.id.fan_key9:
			Value.currentKey = "fans_key9";
			break;
		case R.id.fan_sleep:
			Value.currentKey = "fans_sleep";
			break;
		case R.id.fan_power:
			Value.currentKey = "fans_power";
			break;
		case R.id.fan_mode:
			Value.currentKey = "fans_mode";
			break;
		case R.id.fan_cool:
			Value.currentKey = "fans_cool";
			break;
		case R.id.fan_li:
			Value.currentKey = "fans_li";
			break;
		case R.id.fan_timer:
			Value.currentKey = "fans_timer";
			break;
		case R.id.fan_speed:
			Value.currentKey = "fans_speed";
			break;
		case R.id.fan_light:
			Value.currentKey = "fans_light";
			break;
		case R.id.fan_speedlow:
			Value.currentKey = "fans_speedlow";
			break;
		case R.id.fan_speedmiddle:
			Value.currentKey = "fans_speedmiddle";
			break;
		case R.id.fan_speedhight:
			Value.currentKey = "fans_speedhight";
			break;
		case R.id.fan_freq:
			Value.currentKey = "fans_freq";
			break;
		default:
			Value.currentKey = null;
		}
		if (Value.currentKey != null) {
			try {
				KeyTreate.getInstance().keyTreate(Value.currentDevice ,Value.currentKey);	

			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}