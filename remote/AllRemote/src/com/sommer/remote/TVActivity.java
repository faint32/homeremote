package com.sommer.remote;






import com.sommer.allremote.R;
import com.sommer.data.KeyValue;
import com.sommer.data.Value;
import com.sommer.ircomm.KeyTreate;
import com.sommer.ui.FuncationButton;
import com.sommer.ui.NumButton;
import com.sommer.ui.SelectPicPopupWindow;



import android.app.Activity;
import android.content.Intent;
import android.graphics.Color;
import android.os.Bundle;
import android.util.DisplayMetrics;
import android.util.Log;

import android.view.Gravity;
import android.view.KeyEvent;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.View.OnLongClickListener;
import android.widget.Button;

import android.widget.TextView;


public class TVActivity extends BaseActivity implements OnClickListener,
		OnLongClickListener {
    final static String TAG = "TVActivity";
	//NumButton numberButtonWindows;
	FuncationButton funButtonWindows;
	int current;
//	TextView keyValueIndex;
//	String TVCodeIndex;
//	HashMap<String , KeyValue> keyTab = new HashMap<String , KeyValue>();   
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_tv);
		Intent intent = getIntent();   
		
		current = intent.getIntExtra("current", 0);   
		
		
		
		DisplayMetrics dm = new DisplayMetrics();
		getWindowManager().getDefaultDisplay().getMetrics(dm);
		int screenWidth = dm.widthPixels;
		int screenHeight = dm.heightPixels;
		Log.v(TAG, "dm widthpixels--->"+screenWidth+"       dm heightPixels ------>"+ screenHeight);
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
			Value.cKey = current + 21;
			break;
		case R.id.tv_key1:
		
			Value.currentKey = "tv_key1";
			Value.cKey = current + 12;
			break;
		case R.id.tv_key2:
			
			Value.currentKey = "tv_key2";
			Value.cKey = current + 13;
			break;
		case R.id.tv_key3:
			
			Value.currentKey = "tv_key3";
			Value.cKey = current + 14;
			break;
		case R.id.tv_key4:
			
			Value.currentKey = "tv_key4";
			Value.cKey = current + 15;
			break;
		case R.id.tv_key5:
			
			Value.currentKey = "tv_key5";
			Value.cKey = current + 16;
			break;
		case R.id.tv_key6:
			
			Value.currentKey = "tv_key6";
			Value.cKey = current + 17;
			break;
		case R.id.tv_key7:
			
			Value.currentKey = "tv_key7";
			Value.cKey = current + 18;
			break;
		case R.id.tv_key8:
			
			Value.currentKey = "tv_key8";
			Value.cKey = current + 19;
			break;
		case R.id.tv_key9:
		
			Value.currentKey = "tv_key9";
			Value.cKey = current + 20;
			break;
		case R.id.tv_key10:
			
			Value.currentKey = "tv_key10";
			Value.cKey = current + 22;
			break;
		case R.id.tv_power:
		
			Value.currentKey = "tv_power";
			Value.cKey = current + 0;
			break;
		case R.id.tv_av:
		
			Value.currentKey = "tv_av";
			Value.cKey = current + 5;
			break;
		case R.id.tv_mute:
		
			Value.currentKey = "tv_mute";
			Value.cKey = current + 8;
			break;
		case R.id.tv_back:
			
			Value.currentKey = "tv_back";
			Value.cKey = current + 9;
			break;
		case R.id.tv_chadd:
		
			Value.currentKey = "tv_chadd";
			Value.cKey = current + 10;
			break;
		case R.id.tv_chsub:
			
			Value.currentKey = "tv_chsub";
			Value.cKey = current + 11;
			break;
		case R.id.tv_voladd:
			
			Value.currentKey = "tv_voladd";
			Value.cKey = current + 6;
			break;
		case R.id.tv_volsub:
			
			Value.currentKey = "tv_volsub";
			Value.cKey = current + 7;
			break;
		case R.id.tv_ok:
		
			Value.currentKey = "tv_ok";
			Value.cKey = current + 3;
			break;
		case R.id.tv_menu:
		
			Value.currentKey = "tv_menu";
			Value.cKey = current + 1;
			break;
		default:
			
			Value.currentKey = null;
			break;
		}
		if (Value.currentKey != null) {
			KeyTreate.getInstance().keyTreate();	
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
	
	 private OnClickListener  itemsOnClick = new OnClickListener(){

			public void onClick(View v) {
			//	numberButtonWindows.dismiss();
				switch (v.getId()) {
				case R.id.btn_study:

				
					break;
				case R.id.btn_options:		
					
					break;
				case R.id.btn_about:	
					
					break;
				case R.id.btn_quit:	
				
					break;	
				default:
					break;
				}
				
					
			}
	    	
	    };
}
