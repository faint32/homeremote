 package com.sommer.remote;



import com.sommer.allremote.R;
import com.sommer.data.Value;
import com.sommer.ircomm.KeyTreate;

import android.app.Activity;
import android.os.Bundle;
import android.util.DisplayMetrics;
import android.view.KeyEvent;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.RadioButton;
import android.widget.Toast;

public class PJTRemote extends BaseActivity implements OnClickListener {


	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_pjt);
		DisplayMetrics dm = new DisplayMetrics();
		getWindowManager().getDefaultDisplay().getMetrics(dm);
		int screenWidth = dm.widthPixels;
		int screenHeight = dm.heightPixels;

		Button pjt_power_on = (Button) findViewById(R.id.pjt_power_on);
		pjt_power_on.setOnClickListener(this);
		pjt_power_on.setWidth((screenWidth) / 4);
		pjt_power_on.setHeight((screenHeight) / 11);
		pjt_power_on.setBackgroundResource(R.drawable.button_power);
		
		Button pjt_power_off = (Button) findViewById(R.id.pjt_power_off);
		pjt_power_off.setOnClickListener(this);
		pjt_power_off.setWidth((screenWidth) / 4);
		pjt_power_off.setHeight((screenHeight) / 11);
		pjt_power_off.setBackgroundResource(R.drawable.button);
		
		Button pjt_computer = (Button) findViewById(R.id.pjt_computer);
		pjt_computer.setOnClickListener(this);
		pjt_computer.setWidth((screenWidth) / 4);
		pjt_computer.setHeight((screenHeight) / 11);
		pjt_computer.setBackgroundResource(R.drawable.button);
		
		Button pjt_video = (Button) findViewById(R.id.pjt_video);
		pjt_video.setOnClickListener(this);
		pjt_video.setWidth((screenWidth) / 4);
		pjt_video.setHeight((screenHeight) / 11);
		pjt_video.setBackgroundResource(R.drawable.button);
		
		Button pjt_sign = (Button) findViewById(R.id.pjt_sign);
		pjt_sign.setOnClickListener(this);
		pjt_sign.setWidth((screenWidth) / 4);
		pjt_sign.setHeight((screenHeight) / 11);
		pjt_sign.setBackgroundResource(R.drawable.button);
		
		Button pjt_zoomadd = (Button) findViewById(R.id.pjt_zoomadd);
		pjt_zoomadd.setOnClickListener(this);
		pjt_zoomadd.setWidth((screenWidth) / 4);
		pjt_zoomadd.setHeight((screenHeight) / 11);
		pjt_zoomadd.setBackgroundResource(R.drawable.button);
		
		Button pjt_zoomsub = (Button) findViewById(R.id.pjt_zoomsub);
		pjt_zoomsub.setOnClickListener(this);
		pjt_zoomsub.setWidth((screenWidth) / 4);
		pjt_zoomsub.setHeight((screenHeight) / 11);
		pjt_zoomsub.setBackgroundResource(R.drawable.button);
		
		Button pjt_pictureadd = (Button) findViewById(R.id.pjt_pictureadd);
		pjt_pictureadd.setOnClickListener(this);
		pjt_pictureadd.setWidth((screenWidth) / 4);
		pjt_pictureadd.setHeight((screenHeight) / 11);
		pjt_pictureadd.setBackgroundResource(R.drawable.button);
		
		Button pjt_picturesub = (Button) findViewById(R.id.pjt_picturesub);
		pjt_picturesub.setOnClickListener(this);
		pjt_picturesub.setWidth((screenWidth) / 4);
		pjt_picturesub.setHeight((screenHeight) / 11);
		pjt_picturesub.setBackgroundResource(R.drawable.button);
		
		Button pjt_brightness = (Button) findViewById(R.id.pjt_brightness);
		pjt_brightness.setOnClickListener(this);
		pjt_brightness.setWidth((screenWidth) / 4);
		pjt_brightness.setHeight((screenHeight) / 11);
		pjt_brightness.setBackgroundResource(R.drawable.button);
		
		Button pjt_exit = (Button) findViewById(R.id.pjt_exit);
		pjt_exit.setOnClickListener(this);
		pjt_exit.setWidth((screenWidth) / 4);
		pjt_exit.setHeight((screenHeight) / 11);
		pjt_exit.setBackgroundResource(R.drawable.button);
		
		Button pjt_menu = (Button) findViewById(R.id.pjt_menu);
		pjt_menu.setOnClickListener(this);
		pjt_menu.setWidth((screenWidth) / 4);
		pjt_menu.setHeight((screenHeight) / 11);
		pjt_menu.setBackgroundResource(R.drawable.button);
		
		Button pjt_pause = (Button) findViewById(R.id.pjt_pause);
		pjt_pause.setOnClickListener(this);
		pjt_pause.setWidth((screenWidth) / 4);
		pjt_pause.setHeight((screenHeight) / 11);
		pjt_pause.setBackgroundResource(R.drawable.button);
		
		Button pjt_mute = (Button) findViewById(R.id.pjt_mute);
		pjt_mute.setOnClickListener(this);
		pjt_mute.setWidth((screenWidth) / 4);
		pjt_mute.setHeight((screenHeight) / 11);
		pjt_mute.setBackgroundResource(R.drawable.button);
		
		Button  pjt_voladd = (Button) findViewById(R.id.pjt_voladd);
		pjt_voladd.setOnClickListener(this);
		pjt_voladd.setWidth((screenWidth) / 4);
		pjt_voladd.setHeight((screenHeight) / 11);
		pjt_voladd.setBackgroundResource(R.drawable.button);
		
		Button pjt_volsub = (Button) findViewById(R.id.pjt_volsub);
		pjt_volsub.setOnClickListener(this);
		pjt_volsub.setWidth((screenWidth) / 4);
		pjt_volsub.setHeight((screenHeight) / 11);
		pjt_volsub.setBackgroundResource(R.drawable.button);
		
		Button pjt_auto = (Button) findViewById(R.id.pjt_auto);
		pjt_auto.setOnClickListener(this);
		pjt_auto.setWidth((screenWidth) / 4);
		pjt_auto.setHeight((screenHeight) / 11);
		pjt_auto.setBackgroundResource(R.drawable.button);
		
		Button pjt_up = (Button) findViewById(R.id.pjt_up);
		pjt_up.setOnClickListener(this);
		pjt_up.setWidth((screenWidth) / 4);
		pjt_up.setHeight((screenHeight) / 11);
		pjt_up.setBackgroundResource(R.drawable.button);
		
		Button pjt_down = (Button) findViewById(R.id.pjt_down);
		pjt_down.setOnClickListener(this);
		pjt_down.setWidth((screenWidth) / 4);
		pjt_down.setHeight((screenHeight) / 11);
		pjt_down.setBackgroundResource(R.drawable.button);
		
		Button pjt_left = (Button) findViewById(R.id.pjt_left);
		pjt_left.setOnClickListener(this);
		pjt_left.setWidth((screenWidth) / 4);
		pjt_left.setHeight((screenHeight) / 11);
		pjt_left.setBackgroundResource(R.drawable.button);
		
		Button pjt_right = (Button) findViewById(R.id.pjt_right);
		pjt_right.setOnClickListener(this);
		pjt_right.setWidth((screenWidth) / 4);
		pjt_right.setHeight((screenHeight) / 11);
		pjt_right.setBackgroundResource(R.drawable.button);
		
		Button pjt_ok = (Button) findViewById(R.id.pjt_ok);
		pjt_ok.setOnClickListener(this);
		pjt_ok.setWidth((screenWidth) / 4);
		pjt_ok.setHeight((screenHeight) / 11);
		pjt_ok.setBackgroundResource(R.drawable.button);
		

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
		
		case R.id.pjt_power_on:
			Value.currentKey = "pjt_power_on";
			break;
		case R.id.pjt_power_off:
			Value.currentKey = "pjt_power_off";
			break;
		case R.id.pjt_computer:
			Value.currentKey = "pjt_computer";
			break;
		case R.id.pjt_video:
			Value.currentKey = "pjt_video";
			break;
		case R.id.pjt_sign:
			Value.currentKey = "pjt_sign";
			break;
		case R.id.pjt_zoomadd:
			Value.currentKey = "pjt_zoomadd";
			break;
		case R.id.pjt_zoomsub:
			Value.currentKey = "pjt_zoomsub";
			break;
		case R.id.pjt_mute:
			Value.currentKey = "pjt_mute";
			break;
		case R.id.pjt_voladd:
			Value.currentKey = "pjt_voladd";
			break;
		case R.id.pjt_volsub:
			Value.currentKey = "pjt_volsub";
			break;
		case R.id.pjt_auto:
			Value.currentKey = "pjt_auto";
			break;
		case R.id.pjt_pause:
			Value.currentKey = "pjt_pause";
			break;
		case R.id.pjt_brightness:
			Value.currentKey = "pjt_brightness";
			break;
		case R.id.pjt_exit:
			Value.currentKey = "pjt_exit";
			break;
		case R.id.pjt_menu:
			Value.currentKey = "pjt_menu";
			break;
		case R.id.pjt_pictureadd:
			Value.currentKey = "pjt_pictureadd";
			break;
		case R.id.pjt_picturesub:
			Value.currentKey = "pjt_picturesub";
			break;
		case R.id.pjt_up:
			Value.currentKey = "pjt_up";
			break;
		case R.id.pjt_down:
			Value.currentKey = "pjt_down";
			break;
		case R.id.pjt_left:
			Value.currentKey = "pjt_left";
			break;
		case R.id.pjt_right:
			Value.currentKey = "pjt_right";
			break;
		case R.id.pjt_ok:
			Value.currentKey = "pjt_ok";
			break;
		default:
			Value.currentKey = null;
		}
		if (Value.currentKey != null) {
			try {
				KeyTreate.getInstance().keyTreate();
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}