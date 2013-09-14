package com.sommer.remote;






import com.sommer.allremote.R;

import com.sommer.data.Value;
import com.sommer.ircomm.KeyTreate;
import com.sommer.ui.FuncationButton;




import android.content.Intent;

import android.os.Bundle;
import android.util.DisplayMetrics;

import android.view.KeyEvent;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.View.OnLongClickListener;
import android.widget.Button;




public class TVRemote extends BaseActivity implements OnClickListener,
		OnLongClickListener {
    final static String TAG = "TVActivity";
	//NumButton numberButtonWindows;
	FuncationButton funButtonWindows;
	
//	TextView keyValueIndex;
//	String TVCodeIndex;
//	HashMap<String , KeyValue> keyTab = new HashMap<String , KeyValue>();   
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_tv);
		
		Intent intent = getIntent();   
		Value.currentDevice = intent.getIntExtra("current", 0);
		
		
		
		DisplayMetrics dm = new DisplayMetrics();
		getWindowManager().getDefaultDisplay().getMetrics(dm);
		int screenWidth = dm.widthPixels;
		int screenHeight = dm.heightPixels;
//		Log.v(TAG, "dm widthpixels--->"+screenWidth+"       dm heightPixels ------>"+ screenHeight);
		Button tv_key0 = (Button) findViewById(R.id.tv_key0);
		tv_key0.setOnClickListener(this);
		
		tv_key0.setWidth((screenWidth) / 4);
		tv_key0.setHeight((screenHeight) / 10);
	
		

		Button tv_key1 = (Button) findViewById(R.id.tv_key1);
		tv_key1.setOnClickListener(this);
		tv_key1.setWidth((screenWidth) / 4);
		tv_key1.setHeight((screenHeight) / 10);
	//	tv_key1.getBackground().setAlpha(50);
		
		
		Button tv_key2 = (Button) findViewById(R.id.tv_key2);
		tv_key2.setOnClickListener(this);
		tv_key2.setWidth((screenWidth) / 4);
		tv_key2.setHeight((screenHeight) / 10);
	//	tv_key2.getBackground().setAlpha(50);
		
		
		Button tv_key3 = (Button) findViewById(R.id.tv_key3);
		tv_key3.setOnClickListener(this);
		tv_key3.setWidth((screenWidth) / 4);
		tv_key3.setHeight((screenHeight) / 10);
	//	tv_key3.getBackground().setAlpha(50);
		
		Button tv_key4 = (Button) findViewById(R.id.tv_key4);
		tv_key4.setOnClickListener(this);
		tv_key4.setWidth((screenWidth) / 4);
		tv_key4.setHeight((screenHeight) / 10);
		

		Button tv_key5 = (Button) findViewById(R.id.tv_key5);
		tv_key5.setOnClickListener(this);
		tv_key5.setWidth((screenWidth) / 4);
		tv_key5.setHeight((screenHeight) / 10);
	

		Button tv_key6 = (Button) findViewById(R.id.tv_key6);
		tv_key6.setOnClickListener(this);
		tv_key6.setWidth((screenWidth) / 4);
		tv_key6.setHeight((screenHeight) / 10);
		

		Button tv_key7 = (Button) findViewById(R.id.tv_key7);
		tv_key7.setOnClickListener(this);
		tv_key7.setWidth((screenWidth) / 4);
		tv_key7.setHeight((screenHeight) / 10);
	

		Button tv_key8 = (Button) findViewById(R.id.tv_key8);
		tv_key8.setOnClickListener(this);
		tv_key8.setWidth((screenWidth) / 4);
		tv_key8.setHeight((screenHeight) / 10);
		

		Button tv_key9 = (Button) findViewById(R.id.tv_key9);
		tv_key9.setOnClickListener(this);
		tv_key9.setWidth((screenWidth) / 4);
		tv_key9.setHeight((screenHeight) / 10);
		
		
		Button tv_10 = (Button) findViewById(R.id.tv_key10);
		tv_10.setOnClickListener(this);
		tv_10.setWidth((screenWidth) / 4);
		tv_10.setHeight((screenHeight) / 10);
	

		Button tv_power = (Button) findViewById(R.id.tv_power);
		tv_power.setOnClickListener(this);
		tv_power.setWidth((screenWidth) / 4);
		tv_power.setHeight((screenHeight) / 10);
		

		Button tv_av = (Button) findViewById(R.id.tv_av);
		tv_av.setOnClickListener(this);
		tv_av.setWidth((screenWidth) / 4);
		tv_av.setHeight((screenHeight) / 10);
	

		Button tv_mute = (Button) findViewById(R.id.tv_mute);
		tv_mute.setOnClickListener(this);
		tv_mute.setWidth((screenWidth) / 4);
		tv_mute.setHeight((screenHeight) / 10);
		

		Button tv_back = (Button) findViewById(R.id.tv_back);
		tv_back.setOnClickListener(this);
		tv_back.setWidth((screenWidth) / 4);
		tv_back.setHeight((screenHeight) / 10);
		
		Button tv_chadd = (Button) findViewById(R.id.tv_chadd);
		tv_chadd.setOnClickListener(this);
		tv_chadd.setWidth((screenWidth) / 4);
		tv_chadd.setHeight((screenHeight) / 10);
	

		Button tv_chsub = (Button) findViewById(R.id.tv_chsub);
		tv_chsub.setOnClickListener(this);
		tv_chsub.setWidth((screenWidth) / 4);
		tv_chsub.setHeight((screenHeight) / 10);
		

		Button tv_voladd = (Button) findViewById(R.id.tv_voladd);
		tv_voladd.setOnClickListener(this);
		tv_voladd.setOnLongClickListener(this);
		tv_voladd.setWidth((screenWidth) / 4);
		tv_voladd.setHeight((screenHeight) / 10);
		

		Button tv_volsub = (Button) findViewById(R.id.tv_volsub);
		tv_volsub.setOnClickListener(this);
		tv_volsub.setWidth((screenWidth) / 4);
		tv_volsub.setHeight((screenHeight) / 10);
		

		Button tv_ok = (Button) findViewById(R.id.tv_ok);
		tv_ok.setOnClickListener(this);
		tv_ok.setWidth((screenWidth) / 4);
		tv_ok.setHeight((screenHeight) / 10);
		

		Button tv_menu = (Button) findViewById(R.id.tv_menu);
		tv_menu.setOnClickListener(this);
		tv_menu.setWidth((screenWidth) / 4);
		tv_menu.setHeight((screenHeight) / 10);
	
		
//		 keyValueIndex = (TextView) findViewById(R.id.tv_showkey);
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

			return true;
		} else {
			return super.onKeyDown(keyCode, event);
		}
	}

	public void onClick(View _view) {
		switch (_view.getId()) {
		case R.id.tv_key0:
			Value.currentKey = "tv_key0";
		
			break;
		case R.id.tv_key1:
		
			Value.currentKey = "tv_key1";
		
			break;
		case R.id.tv_key2:
			
			Value.currentKey = "tv_key2";
			
			break;
		case R.id.tv_key3:
			
			Value.currentKey = "tv_key3";
		
			break;
		case R.id.tv_key4:
			
			Value.currentKey = "tv_key4";
			
			break;
		case R.id.tv_key5:
			
			Value.currentKey = "tv_key5";
			
			break;
		case R.id.tv_key6:
			
			Value.currentKey = "tv_key6";
		
			break;
		case R.id.tv_key7:
			
			Value.currentKey = "tv_key7";
		
			break;
		case R.id.tv_key8:
			
			Value.currentKey = "tv_key8";
			
			break;
		case R.id.tv_key9:
		
			Value.currentKey = "tv_key9";
			
			break;
		case R.id.tv_key10:
			
			Value.currentKey = "tv_key10";
			
			break;
		case R.id.tv_power:
		
			Value.currentKey = "tv_power";
		
			break;
		case R.id.tv_av:
		
			Value.currentKey = "tv_av";
		
			break;
		case R.id.tv_mute:
		
			Value.currentKey = "tv_mute";
		
			break;
		case R.id.tv_back:
			
			Value.currentKey = "tv_back";
		
			break;
		case R.id.tv_chadd:
		
			Value.currentKey = "tv_chadd";
		
			break;
		case R.id.tv_chsub:
			
			Value.currentKey = "tv_chsub";
			
			break;
		case R.id.tv_voladd:
			
			Value.currentKey = "tv_voladd";
		
			break;
		case R.id.tv_volsub:
			
			Value.currentKey = "tv_volsub";
		
			break;
		case R.id.tv_ok:
		
			Value.currentKey = "tv_ok";
		
			break;
		case R.id.tv_menu:
		
			Value.currentKey = "tv_menu";
			
			break;
		default:
			
			Value.currentKey = null;
			
			break;
		}
		if (Value.currentKey != null) {
			KeyTreate.getInstance().keyTreate(Value.currentDevice ,Value.currentKey);	
//			numberButtonWindows = new NumButton(this, itemsOnClick);
//			numberButtonWindows.showAtLocation(this.findViewById(R.id.tv_main_view), Gravity.BOTTOM|Gravity.CENTER_HORIZONTAL, 0, 0);
//			funButtonWindows = new FuncationButton(this, itemsOnClick);
//			funButtonWindows.showAtLocation(this.findViewById(R.id.tv_main_view), Gravity.BOTTOM|Gravity.CENTER_HORIZONTAL, 0, 0);

			
		}
	}

	public boolean onLongClick(View v) {
		// TODO Auto-generated method stub
		switch (v.getId()) {
		case R.id.tv_voladd:
			
			break;
		case R.id.tv_volsub:
			
			break;
		default:
		
		}
		return false;
	}
	

	
	
//	public boolean dispatchKeyEvent(KeyEvent event) { 
//		if (event.getKeyCode() == KeyEvent.KEYCODE_MENU) { 
//		Log.v(TAG, "key menu ");
//		return true; 
//		} 
//		return super.dispatchKeyEvent(event); 
//		} 
}
