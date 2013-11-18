package com.deco.remote;





import com.deco.allremote.R;
import com.deco.data.AirData;
import com.deco.data.Value;

import com.deco.ircore.RemoteCommunicate;
import com.deco.ircore.RemoteOut;
import com.deco.utils.MyAppInfo;
import com.deco.utils.UserDB;

import android.app.Activity;
import android.content.Intent;

import android.graphics.Typeface;
import android.os.Bundle;
import android.util.DisplayMetrics;
import android.view.Display;
import android.view.KeyEvent;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TextView;


public class AirRemote extends Activity implements OnClickListener {
	TextView airShow;
	TextView airMode;
	TextView airWindDir;	
	TextView airWind;
	
	byte    airKey;
	// private boolean mIsOpen = false;
	// private boolean mIsOther = false;
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_air);
		
		Intent intent = getIntent();   
		Value.currentDevice = intent.getIntExtra("current", 0);
		
		Typeface type= Typeface.createFromAsset(getAssets(),"fonts/lcd.TTF");
		DisplayMetrics dm = new DisplayMetrics();
		Display display = getWindowManager().getDefaultDisplay();
		display.getMetrics(dm);
		int screenWidth = dm.widthPixels;
		int screenHeight = dm.heightPixels;

		Button air_power = (Button) findViewById(R.id.air_power);
		air_power.setOnClickListener(this);
		air_power.setWidth((screenWidth) / 4);
		air_power.setHeight((screenHeight) / 10);
		air_power.setBackgroundResource(R.drawable.button_power);

		Button air_mode = (Button) findViewById(R.id.air_mode);
		air_mode.setOnClickListener(this);
		air_mode.setWidth((screenWidth) / 4);
		air_mode.setHeight((screenHeight) / 10);
		air_mode.setBackgroundResource(R.drawable.button);

		Button air_tempadd = (Button) findViewById(R.id.air_tempadd);
		air_tempadd.setOnClickListener(this);
		air_tempadd.setWidth((screenWidth) / 4);
		air_tempadd.setHeight((screenHeight) / 10);
		air_tempadd.setBackgroundResource(R.drawable.button);
		
		Button air_tempsub = (Button) findViewById(R.id.air_tempsub);
		air_tempsub.setOnClickListener(this);
		air_tempsub.setWidth((screenWidth) / 4);
		air_tempsub.setHeight((screenHeight) / 10);
		air_tempsub.setBackgroundResource(R.drawable.button);

		Button air_wind_auto_dir = (Button) findViewById(R.id.air_wind_auto_dir);
		air_wind_auto_dir.setOnClickListener(this);
		air_wind_auto_dir.setWidth((screenWidth) / 4);
		air_wind_auto_dir.setHeight((screenHeight) / 10);
		air_wind_auto_dir.setBackgroundResource(R.drawable.button);

		Button air_wind_count = (Button) findViewById(R.id.air_wind_count);
		air_wind_count.setOnClickListener(this);
		air_wind_count.setWidth((screenWidth) / 4);
		air_wind_count.setHeight((screenHeight) / 10);
		air_wind_count.setBackgroundResource(R.drawable.button);

		Button air_wind_dir = (Button) findViewById(R.id.air_wind_dir);
		air_wind_dir.setOnClickListener(this);
		air_wind_dir.setWidth((screenWidth) / 4);
		air_wind_dir.setHeight((screenHeight) / 10);
		air_wind_dir.setBackgroundResource(R.drawable.button);
		
		 airShow=((TextView) findViewById(R.id.text_show));
		 airShow.setTypeface(type);
		// airShow.setText("25");
		 airMode=((TextView) findViewById(R.id.text_mode));
		 airMode.setTypeface(type);
		// airMode.setText("cold");
		 airWindDir=((TextView) findViewById(R.id.text_wind_dir));
		 airWindDir.setTypeface(type);
		// airWindDir.setText("vertical");
		 airWind=((TextView) findViewById(R.id.text_wind_count));
		 airWind.setTypeface(type);
		// airWind.setText("low");
		
	}
	@Override
	public void onStart()
	{
		super.onStart();
		UserDB mUserDB = new UserDB(this);
		mUserDB.open();
		mUserDB.getAirData(Value.currentDevice);
		airShow.setText(getTempStr(Value.airData));
		airMode.setText(getModeStr(Value.airData));
		airWindDir.setText(getWindDirStr(Value.airData));
		airWind.setText(getWindStr(Value.airData));
		mUserDB.close();
	}
	
	
	
	
	@Override
	protected void onDestroy() {
		// TODO Auto-generated method stub
		super.onDestroy();
		UserDB mUserDB = new UserDB(this);
		mUserDB.open();
		mUserDB.updateAirData(Value.currentDevice);
		mUserDB.close();
	}
	
	@Override
	protected void onStop() {
		// TODO Auto-generated method stub
		super.onDestroy();
		UserDB mUserDB = new UserDB(this);
		mUserDB.open();
		mUserDB.updateAirData(Value.currentDevice);
		mUserDB.close();
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
		if(Value.airData.getmPower() == 0x00 && v.getId() != R.id.air_power)
		{
			return;
		}
		int data;
		switch (v.getId()) {
		
		case R.id.air_mode:
			Value.currentKey = "air_mode";
			data= Value.airData.getmMode();
			data++;
			
			if(data>4){
				data = 0;
			}
			Value.airData.setmMode(data);
			
			airKey = 1;
			Value.airData.setMkey(airKey);
			// mIsOther = true;
			break;
		case R.id.air_power:
			Value.currentKey ="air_power";
			if(Value.airData.getmPower()==0){
				Value.airData.setmPower(1);
			}else{
				Value.airData.setmPower(0);
			}
			airKey = 0;
			Value.airData.setMkey(airKey);
			break;
		case R.id.air_tempadd:
			Value.currentKey = "air_tempadd";
			data= Value.airData.getmTmp();
			data++;
			
			if(data>30){
				data = 16;
			}
			Value.airData.setmTmp(data);
			airKey = 3;
			Value.airData.setMkey(airKey);
			break;
		case R.id.air_tempsub:
			Value.currentKey = "air_tempsub";
			data= Value.airData.getmTmp();
			data--;
			
			if(data<16){
				data = 30;
			}
			Value.airData.setmTmp(data);
			airKey =4 ;
			Value.airData.setMkey(airKey);
			break;
		case R.id.air_wind_auto_dir:
			Value.currentKey = "air_wind_auto_dir";
			if(Value.airData.getmWindAuto()==0){
				Value.airData.setmWindAuto(1);
			}else{
				Value.airData.setmWindAuto(0);
			}
			airKey = 6;
			Value.airData.setMkey(airKey);
			break;
		case R.id.air_wind_count:
			Value.currentKey ="air_wind_count";
			data= Value.airData.getmWindCount();
			data++;
			
			if(data>3){
				data = 0;
			}
			Value.airData.setmWindCount(data);
			airKey = 2;
			Value.airData.setMkey(airKey);
			break;
		case R.id.air_wind_dir:
			if(Value.airData.getmWindDir()==0){
				Value.airData.setmWindDir(1);
			}else{
				Value.airData.setmWindDir(0);
			}
			airKey = 5;
			Value.airData.setMkey(airKey);
			break;
		default:
			break;
		}
		if (Value.currentKey != null) {
		RemoteCommunicate.sendDECOAirRemote(Value.airData);	

			
		}
	
		airShow.setText(getTempStr(Value.airData));
		airMode.setText(getModeStr(Value.airData));
		airWindDir.setText(getWindDirStr(Value.airData));
		airWind.setText(getWindStr(Value.airData));
	
	}
	
	
	
	
	public  String getModeStr(AirData airdata) {
		String mModeStr = null;
		if (airdata.getmPower() == 0x01) {
			 mModeStr = getString(R.string.air_mode_val);
			if (airdata.getmMode() == 0x00) {
				mModeStr += getString(R.string.air_mode_value_1);
			}
			if (airdata.getmMode()  == 0x01) {
				mModeStr += getString(R.string.air_mode_value_2);
			}
			if (airdata.getmMode()  == 0x02) {
				mModeStr += getString(R.string.air_mode_value_3);
			}
			if (airdata.getmMode()  == 0x03) {
				mModeStr += getString(R.string.air_mode_value_4);
			}
			if (airdata.getmMode()  == 0x04) {
				mModeStr += getString(R.string.air_mode_value_5);
			}
		}
		else{
			mModeStr = getString(R.string.air_power_off);	
		}
		
		return mModeStr;
	}
	public  String getWindStr(AirData airdata) {
		String mWindStr = null;
		mWindStr = getString(R.string.air_wind_val);
		if (airdata.getmPower() == 0x01) {
		//	mWindStr = getString(R.string.air_wind_count);
			if (airdata.getmWindCount() == 0x00) {
				mWindStr += getString(R.string.air_wind_count_value_1);
			}
			if (airdata.getmWindCount()  == 0x01) {
				mWindStr += getString(R.string.air_wind_count_value_2);
			}
			if (airdata.getmWindCount()  == 0x02) {
				mWindStr += getString(R.string.air_wind_count_value_3);
			}
			if (airdata.getmWindCount()  == 0x03) {
				mWindStr += getString(R.string.air_wind_count_value_4);
			}
			
		}
		else{
		//	mWindStr = "";	
		}
		
		return mWindStr;
	}
	
	public  String getWindAuto(AirData airdata) {
		String mWindStr = null;
		mWindStr = getString(R.string.air_wind_auto_dir);
		if (airdata.getmPower() == 0x01) {
		//	mWindStr = getString(R.string.air_wind_auto_dir);
			if (airdata.getmWindAuto() == 0x00) {
				mWindStr += getString(R.string.air_wind_auto_dir_value_0);
			}
			if (airdata.getmWindAuto()  == 0x01) {
				mWindStr += getString(R.string.air_wind_auto_dir_value_1);
			}
					
		}
		else{
		//	mWindStr = "";	
		}
		
		return mWindStr;
	}
	public  String getWindDirStr(AirData airdata) {
		String mWindStr = null;
		mWindStr = getString(R.string.air_wind_dir_val);
		if (airdata.getmPower() == 0x01) {
		
			if (airdata.getmWindDir() == 0x00) {
				mWindStr += getString(R.string.air_wind_auto_dir_value_0);
			}
			if (airdata.getmWindDir()  == 0x01) {
				mWindStr += getString(R.string.air_wind_auto_dir_value_1);
			}
					
		}
		else{
		
		}
		
		return mWindStr;
	}
	
	
	public  String getTempStr(AirData airdata) {
		String mWindStr = null;
		if (airdata.getmPower() == 0x01) {
			mWindStr=String.valueOf(Value.airData.getmTmp())+"℃";
					
		}
		else{
			mWindStr = "";	
		}
		
		return mWindStr;
	}
	
	
	
}