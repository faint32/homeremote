package com.sommer.remote;



import com.sommer.allremote.R;
import com.sommer.data.AirData;
import com.sommer.data.Value;
import com.sommer.ircomm.RemoteCore;

import com.sommer.utils.MyRemoteDatabase;


import android.graphics.Typeface;
import android.os.Bundle;
import android.util.DisplayMetrics;
import android.view.Display;
import android.view.KeyEvent;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

import android.widget.TextView;


public class AirActivity extends BaseActivity implements OnClickListener {
	TextView airShow;
	TextView airMode;
	TextView airWindDir;	
	TextView airWind;
	AirData airData;

	// private boolean mIsOpen = false;
	// private boolean mIsOther = false;
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_air);
		airData =MyRemoteDatabase.getAirData(getApplicationContext());
		
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
		

		Button air_mode = (Button) findViewById(R.id.air_mode);
		air_mode.setOnClickListener(this);
		air_mode.setWidth((screenWidth) / 4);
		air_mode.setHeight((screenHeight) / 10);


		Button air_tempadd = (Button) findViewById(R.id.air_tempadd);
		air_tempadd.setOnClickListener(this);
		air_tempadd.setWidth((screenWidth) / 4);
		air_tempadd.setHeight((screenHeight) / 10);
	
		
		Button air_tempsub = (Button) findViewById(R.id.air_tempsub);
		air_tempsub.setOnClickListener(this);
		air_tempsub.setWidth((screenWidth) / 4);
		air_tempsub.setHeight((screenHeight) / 10);
		

		Button air_wind_auto_dir = (Button) findViewById(R.id.air_wind_auto_dir);
		air_wind_auto_dir.setOnClickListener(this);
		air_wind_auto_dir.setWidth((screenWidth) / 4);
		air_wind_auto_dir.setHeight((screenHeight) / 10);
	

		Button air_wind_count = (Button) findViewById(R.id.air_wind_count);
		air_wind_count.setOnClickListener(this);
		air_wind_count.setWidth((screenWidth) / 4);
		air_wind_count.setHeight((screenHeight) / 10);
		

		Button air_wind_dir = (Button) findViewById(R.id.air_wind_dir);
		air_wind_dir.setOnClickListener(this);
		air_wind_dir.setWidth((screenWidth) / 4);
		air_wind_dir.setHeight((screenHeight) / 10);
		
		
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
		airShow.setText(getTempStr(airData));
		airMode.setText(getModeStr(airData));
		airWindDir.setText(getWindDirStr(airData));
		airWind.setText(getWindStr(airData));
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
		if(airData.getmPower() == 0x00 && v.getId() != R.id.air_power)
		{
			return;
		}
		int data;
		switch (v.getId()) {
		
		case R.id.air_mode:
			Value.currentKey = "air_mode";
			data= airData.getmMode();
			data++;
			
			if(data>5){
				data = 1;
			}
			airData.setmMode(data);
			// mIsOther = true;
			break;
		case R.id.air_power:
			Value.currentKey ="air_power";
			if(airData.getmPower()==0){
				airData.setmPower(1);
			}else{
				airData.setmPower(0);
			}
			break;
		case R.id.air_tempadd:
			Value.currentKey = "air_tempadd";
			data= airData.getmTmp();
			data++;
			
			if(data>30){
				data = 16;
			}
			airData.setmTmp(data);
			
			break;
		case R.id.air_tempsub:
			Value.currentKey = "air_tempsub";
			data= airData.getmTmp();
			data--;
			
			if(data<16){
				data = 30;
			}
			airData.setmTmp(data);
		
			
			break;
		case R.id.air_wind_auto_dir:
			Value.currentKey = "air_wind_auto_dir";
			if(airData.getmWindAuto()==0){
				airData.setmWindAuto(1);
			}else{
				airData.setmWindAuto(0);
			}
			break;
		case R.id.air_wind_count:
			Value.currentKey ="air_wind_count";
			data= airData.getmWindCount();
			data++;
			
			if(data>4){
				data = 1;
			}
			airData.setmWindCount(data);
			break;
		case R.id.air_wind_dir:
			if(airData.getmWindDir()==0){
				airData.setmWindDir(1);
			}else{
				airData.setmWindDir(0);
			}
			
			break;
		default:
			break;
		}
		if (Value.currentKey != null) {
			RemoteCore.sendAirRemote(airData);	
			
			
		}
		MyRemoteDatabase.saveAirData(getApplicationContext(), airData);
		airShow.setText(getTempStr(airData));
		airMode.setText(getModeStr(airData));
		airWindDir.setText(getWindDirStr(airData));
		airWind.setText(getWindStr(airData));
	}
	
	
	
	
	public  String getModeStr(AirData airdata) {
		String mModeStr = null;
		if (airdata.getmPower() == 0x01) {
			 mModeStr = getString(R.string.air_mode_val);
			if (airdata.getmMode() == 0x01) {
				mModeStr += getString(R.string.air_mode_value_1);
			}
			if (airdata.getmMode()  == 0x02) {
				mModeStr += getString(R.string.air_mode_value_2);
			}
			if (airdata.getmMode()  == 0x03) {
				mModeStr += getString(R.string.air_mode_value_3);
			}
			if (airdata.getmMode()  == 0x04) {
				mModeStr += getString(R.string.air_mode_value_4);
			}
			if (airdata.getmMode()  == 0x05) {
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
		if (airdata.getmPower() == 0x01) {
			mWindStr = getString(R.string.air_wind_count);
			if (airdata.getmWindCount() == 0x01) {
				mWindStr += getString(R.string.air_wind_count_value_1);
			}
			if (airdata.getmWindCount()  == 0x02) {
				mWindStr += getString(R.string.air_wind_count_value_2);
			}
			if (airdata.getmWindCount()  == 0x03) {
				mWindStr += getString(R.string.air_wind_count_value_3);
			}
			if (airdata.getmWindCount()  == 0x04) {
				mWindStr += getString(R.string.air_wind_count_value_4);
			}
			
		}
		else{
			mWindStr = "";	
		}
		
		return mWindStr;
	}
	
	public  String getWindAuto(AirData airdata) {
		String mWindStr = null;
		if (airdata.getmPower() == 0x01) {
			mWindStr = getString(R.string.air_wind_auto_dir);
			if (airdata.getmWindAuto() == 0x00) {
				mWindStr += getString(R.string.air_wind_auto_dir_value_0);
			}
			if (airdata.getmWindAuto()  == 0x01) {
				mWindStr += getString(R.string.air_wind_auto_dir_value_1);
			}
					
		}
		else{
			mWindStr = "";	
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
			mWindStr=String.valueOf(airData.getmTmp())+" ℃";
					
		}
		else{
			mWindStr = "";	
		}
		
		return mWindStr;
	}
	
	
	
}