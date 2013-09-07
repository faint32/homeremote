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

public class LightActivity extends Activity implements OnClickListener {


	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_light);
		DisplayMetrics dm = new DisplayMetrics();
		getWindowManager().getDefaultDisplay().getMetrics(dm);
		int screenWidth = dm.widthPixels;
		int screenHeight = dm.heightPixels;
		
		Button light_power_all_on = (Button) findViewById(R.id.light_power_all_on);
		light_power_all_on.setOnClickListener(this);
		light_power_all_on.setWidth((screenWidth) / 4);
		light_power_all_on.setHeight((screenHeight) / 10);
		light_power_all_on.setBackgroundResource(R.drawable.button);
		
		Button light_power_all_off = (Button) findViewById(R.id.light_power_all_off);
		light_power_all_off.setOnClickListener(this);
		light_power_all_off.setWidth((screenWidth) / 4);
		light_power_all_off.setHeight((screenHeight) / 10);
		light_power_all_off.setBackgroundResource(R.drawable.button);
		
		Button light_power_on = (Button) findViewById(R.id.light_power_on);
		light_power_on.setOnClickListener(this);
		light_power_on.setWidth((screenWidth) / 4);
		light_power_on.setHeight((screenHeight) / 10);
		light_power_on.setBackgroundResource(R.drawable.button);
		
		Button light_power_off = (Button) findViewById(R.id.light_power_off);
		light_power_off.setOnClickListener(this);
		light_power_off.setWidth((screenWidth) / 4);
		light_power_off.setHeight((screenHeight) / 10);
		light_power_off.setBackgroundResource(R.drawable.button);
		
		Button light_light = (Button) findViewById(R.id.light_light);
		light_light.setOnClickListener(this);
		light_light.setWidth((screenWidth) / 4);
		light_light.setHeight((screenHeight) / 10);
		light_light.setBackgroundResource(R.drawable.button);
		
		Button light_dark = (Button) findViewById(R.id.light_dark);
		light_dark.setOnClickListener(this);
		light_dark.setWidth((screenWidth) / 4);
		light_dark.setHeight((screenHeight) / 10);
		light_dark.setBackgroundResource(R.drawable.button);
		
		Button light_lost = (Button) findViewById(R.id.light_lost);
		light_lost.setOnClickListener(this);
		light_lost.setWidth((screenWidth) / 4);
		light_lost.setHeight((screenHeight) / 10);
		light_lost.setBackgroundResource(R.drawable.button);
		
		Button light_study = (Button) findViewById(R.id.light_study);
		light_study.setOnClickListener(this);
		light_study.setWidth((screenWidth) / 4);
		light_study.setHeight((screenHeight) / 10);
		light_study.setBackgroundResource(R.drawable.button);
		
		Button light_keyA = (Button) findViewById(R.id.light_keyA);
		light_keyA.setOnClickListener(this);
		light_keyA.setWidth((screenWidth) / 4);
		light_keyA.setHeight((screenHeight) / 10);
		light_keyA.setBackgroundResource(R.drawable.button);
		
		Button light_keyB = (Button) findViewById(R.id.light_keyB);
		light_keyB.setOnClickListener(this);
		light_keyB.setWidth((screenWidth) / 4);
		light_keyB.setHeight((screenHeight) / 10);
		light_keyB.setBackgroundResource(R.drawable.button);
		
		Button light_keyC = (Button) findViewById(R.id.light_keyC);
		light_keyC.setOnClickListener(this);
		light_keyC.setWidth((screenWidth) / 4);
		light_keyC.setHeight((screenHeight) / 10);
		light_keyC.setBackgroundResource(R.drawable.button);
		
		Button light_keyD = (Button) findViewById(R.id.light_keyD);
		light_keyD.setOnClickListener(this);
		light_keyD.setWidth((screenWidth) / 4);
		light_keyD.setHeight((screenHeight) / 10);
		light_keyD.setBackgroundResource(R.drawable.button);
		
		Button light_key1 = (Button) findViewById(R.id.light_key1);
		light_key1.setOnClickListener(this);
		light_key1.setWidth((screenWidth) / 4);
		light_key1.setHeight((screenHeight) / 10);
		light_key1.setBackgroundResource(R.drawable.button);
		
		Button light_key2 = (Button) findViewById(R.id.light_key2);
		light_key2.setOnClickListener(this);
		light_key2.setWidth((screenWidth) / 4);
		light_key2.setHeight((screenHeight) / 10);
		light_key2.setBackgroundResource(R.drawable.button);
		
		Button light_key3 = (Button) findViewById(R.id.light_key3);
		light_key3.setOnClickListener(this);
		light_key3.setWidth((screenWidth) / 4);
		light_key3.setHeight((screenHeight) / 10);
		light_key3.setBackgroundResource(R.drawable.button);
		
		Button light_key4 = (Button) findViewById(R.id.light_key4);
		light_key4.setOnClickListener(this);
		light_key4.setWidth((screenWidth) / 4);
		light_key4.setHeight((screenHeight) / 10);
		light_key4.setBackgroundResource(R.drawable.button);
		
		Button light_key5 = (Button) findViewById(R.id.light_key5);
		light_key5.setOnClickListener(this);
		light_key5.setWidth((screenWidth) / 4);
		light_key5.setHeight((screenHeight) / 10);
		light_key5.setBackgroundResource(R.drawable.button);
		
		Button light_key6 = (Button) findViewById(R.id.light_key6);
		light_key6.setOnClickListener(this);
		light_key6.setWidth((screenWidth) / 4);
		light_key6.setHeight((screenHeight) / 10);
		light_key6.setBackgroundResource(R.drawable.button);
		
		Button light_setting = (Button) findViewById(R.id.light_setting);
		light_setting.setOnClickListener(this);
		light_setting.setWidth((screenWidth) / 4);
		light_setting.setHeight((screenHeight) / 10);
		light_setting.setBackgroundResource(R.drawable.button);
		
		Button light_timer1 = (Button) findViewById(R.id.light_timer1);
		light_timer1.setOnClickListener(this);
		light_timer1.setWidth((screenWidth) / 4);
		light_timer1.setHeight((screenHeight) / 10);
		light_timer1.setBackgroundResource(R.drawable.button);
		
		Button light_timer2 = (Button) findViewById(R.id.light_timer2);
		light_timer2.setOnClickListener(this);
		light_timer2.setWidth((screenWidth) / 4);
		light_timer2.setHeight((screenHeight) / 10);
		light_timer2.setBackgroundResource(R.drawable.button);
		
		Button light_timer3 = (Button) findViewById(R.id.light_timer3);
		light_timer3.setOnClickListener(this);
		light_timer3.setWidth((screenWidth) / 4);
		light_timer3.setHeight((screenHeight) / 10);
		light_timer3.setBackgroundResource(R.drawable.button);
		
		Button light_timer4 = (Button) findViewById(R.id.light_timer4);
		light_timer4.setOnClickListener(this);
		light_timer4.setWidth((screenWidth) / 4);
		light_timer4.setHeight((screenHeight) / 10);
		light_timer4.setBackgroundResource(R.drawable.button);
		

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
		
		case R.id.light_power_all_on:
			Value.currentKey ="light_power_all_on";
			break;
		case R.id.light_power_all_off:
			Value.currentKey ="light_power_all_off";
			break;
		case R.id.light_power_on:
			Value.currentKey ="light_power_on";
			break;
		case R.id.light_power_off:
			Value.currentKey ="light_power_off";
			break;
		case R.id.light_light:
			Value.currentKey ="light_light";
			break;
		case R.id.light_dark:
			Value.currentKey ="light_dark";
			break;
		case R.id.light_lost:
			Value.currentKey ="light_lost";
			break;
		case R.id.light_study:
			Value.currentKey ="light_study";
			break;
		case R.id.light_keyA:
			Value.currentKey ="light_keyA";
			break;
		case R.id.light_keyB:
			Value.currentKey ="light_keyB";
			break;
		case R.id.light_keyC:
			Value.currentKey ="light_keyC";
			break;
		case R.id.light_keyD:
			Value.currentKey ="light_keyD";
			break;
		case R.id.light_key1:
			Value.currentKey ="light_key1";
			break;
		case R.id.light_key2:
			Value.currentKey ="light_key2";
			break;
		case R.id.light_key3:
			Value.currentKey ="light_key3";
			break;
		case R.id.light_key4:
			Value.currentKey ="light_key4";
			break;
		case R.id.light_key5:
			Value.currentKey ="light_key5";
			break;
		case R.id.light_key6:
			Value.currentKey ="light_key6";
			break;
		case R.id.light_setting:
			Value.currentKey ="light_setting";
			break;
		case R.id.light_timer1:
			Value.currentKey ="light_timer1";
			break;
		case R.id.light_timer2:
			Value.currentKey ="light_timer2";
			break;
		case R.id.light_timer3:
			Value.currentKey ="light_timer3";
			break;
		case R.id.light_timer4:
			Value.currentKey ="light_timer4";
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