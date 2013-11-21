package com.deco.remote;

import java.util.ArrayList;

import com.database.IRDataBase;
import com.deco.allremote.R;
import com.deco.data.AirData;
import com.deco.data.RemoteData;
import com.deco.data.RemoteGetKeyValue;
import com.deco.data.Value;
import com.deco.ircore.RemoteCommunicate;
import com.deco.utils.RemoteDB;
import com.deco.utils.UserDB;

import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.annotation.SuppressLint;
import android.app.Activity;

import android.content.Context;
import android.graphics.Typeface;

import android.util.Log;
import android.view.KeyEvent;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.animation.AccelerateInterpolator;
import android.view.animation.AlphaAnimation;
import android.view.animation.Animation;
import android.view.Window;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ImageButton;

import android.widget.Toast;
//import android.widget.RadioButton;
import android.widget.Spinner;
import android.widget.AdapterView.OnItemSelectedListener;
import android.widget.TextView;

public class SelectRemote extends Activity implements OnItemSelectedListener,
		OnClickListener {
	final static String TAG = "SelectRemote";
	// private EffectThread mThread = null;
	private Spinner deviceSp = null;

	private int mCount = 0;
	private int mCutCount = 0;
	// private AirData ad = new AirData(5003, 1, 20, 1, 1, 1, 1);
	private AirData ad = new AirData(5000, 1, 24, 1, 0, 0, 0, 0);
	private TextView mDeviceCount = null;
	private TextView mRemainCount = null;
	private TextView mCurrentCount = null;

	private int mType = Value.DeviceType.TYPE_TV;
	private String mTypeName = null;

	private ArrayList<String> list = new ArrayList<String>();
	private ArrayList<String> nameList = new ArrayList<String>();

	private ArrayList<String> productList = new ArrayList<String>();

	private RemoteDB mRmtDB;

	private Bundle bundle = new Bundle();
	RemoteData rmtData = new RemoteData();
	// Button autoButton;
	// Button stopButton;
	ImageButton saveButton;
	ImageButton cancelButton;
	Button upButton;
	Button downButton;
	
	Context mContext;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		requestWindowFeature(Window.FEATURE_INDETERMINATE_PROGRESS);
		setContentView(R.layout.activity_select);

		// database instruction

		Typeface type = Typeface.createFromAsset(getAssets(),
				"fonts/font_bold.ttf");
		mRmtDB = new RemoteDB(getApplicationContext());
		mType = Value.rmtDev.getType();
		mTypeName = Value.RemoteType[mType];
		// String[] typeDevices =
		// getResources().getStringArray(R.array.type_array);
		// int[] typeChecks =
		// {R.drawable.check_off,R.drawable.check_off,R.drawable.check_off,
		// R.drawable.check_off,R.drawable.check_off,R.drawable.check_off
		// };

		// typeSp = (Spinner) findViewById(R.id.typeSp);
		// mContext = this;
		// DeviceAdapter typeAdapter = new
		// DeviceAdapter(mContext,typeDevices,typeChecks);
		// // type_adapter.setDropDownViewResource(R.layout.myspinner_dropdown);
		// Log.v(TAG, "start --->"+ Value.rmtDev.getFullInfo());
		// //
		// type_adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
		// typeSp.setAdapter(typeAdapter);
		// typeSp.setSelection(mType);
		// typeAdapter.changeSelected(mType);
		// typeSp.setOnItemSelectedListener(this);

		deviceSp = (Spinner) findViewById(R.id.nameSp);
		deviceSp.setOnItemSelectedListener(this);

		mDeviceCount = (TextView) findViewById(R.id.count_text);
		mDeviceCount.setTypeface(type);
		mRemainCount = (TextView) findViewById(R.id.remain_count);
		mRemainCount.setTypeface(type);
		mCurrentCount = (TextView) findViewById(R.id.cur_count);
		// mDeviceName = (TextView) findViewById(R.id.remote_name);
		// mDeviceName.setText(Value.rmtDev.getName());
		// mChangeName = (Button) findViewById(R.id.name_change);
		// mChangeName.setOnClickListener(this);
		// autoButton = (Button) findViewById(R.id.str_auto);
		// autoButton.setOnClickListener(this);
		// autoButton.setEnabled(false);
		// stopButton = (Button) findViewById(R.id.str_stop);
		// stopButton.setOnClickListener(this);
		// stopButton.setEnabled(false);
		saveButton = (ImageButton) findViewById(R.id.asl_right);
		saveButton.setOnClickListener(this);
		upButton = (Button) findViewById(R.id.str_up);
		upButton.setOnClickListener(this);
		
		cancelButton = (ImageButton) findViewById(R.id.asl_left);
		cancelButton.setOnClickListener(this);
		downButton = (Button) findViewById(R.id.str_down);
		downButton.setOnClickListener(this);
		

		initialRemoteList(mType);
		// Locale.getDefault().getLanguage();
	}

	private ArrayList<String> getBrand(String _type) {
		mRmtDB.open();
		list = mRmtDB.getBrand(_type);
		nameList = mRmtDB.translateBrands(list);
		mRmtDB.close();
		return nameList;
	}

	private void getProducts(String _type, String _brand) {
		mRmtDB.open();
		try {
			productList = mRmtDB.getProducts(_type, _brand);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		mRmtDB.close();
		mCount = productList.size();
	}

	private final Handler mHandler = new Handler() {

		@Override
		public void handleMessage(Message msg) {
			super.handleMessage(msg);
			switch (msg.what) {
			case R.id.MESSAGE_WRITE:
				mRemainCount.setTextSize(60);
				mRemainCount.setText(String.valueOf(msg.arg1));
				// spark();
				break;
			}
		}
	};

	@SuppressLint("HandlerLeak")
	private void showCodeSending() {
		mHandler.post(new Runnable() {
			public void run() {
				final View localView = findViewById(R.id.testcode_sending);
				if (localView.getVisibility() == 0)
					return;
				AlphaAnimation localAlphaAnimation = new AlphaAnimation(0.0F,
						1.0F);
				localAlphaAnimation
						.setInterpolator(new AccelerateInterpolator());
				localAlphaAnimation.setDuration(100);
				localAlphaAnimation
						.setAnimationListener(new Animation.AnimationListener() {
							public void onAnimationEnd(Animation paramAnimation) {
								localView.setVisibility(8);
							}

							public void onAnimationRepeat(
									Animation paramAnimation) {
							}

							public void onAnimationStart(
									Animation paramAnimation) {
								localView.setVisibility(0);
							}
						});
				localView.startAnimation(localAlphaAnimation);
			}
		});
	}

	@SuppressWarnings("unused")
	void sendTestCode(int count) {
		String index = productList.get(count);
		Value.rmtDev.setCode(index);
		Log.v(TAG, "current index ====>   " + index);
		if (mType != Value.DeviceType.TYPE_AIR) {
			RemoteData rmtData = null;
			try {
				// rmtData = IRDataBase.getSampleKeyData(mType,
				// index,keyColumn);
				rmtData = IRDataBase.getSampleKeyData(mType, index, 4);
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}

			Log.v(TAG, "rmtData ====>   " + rmtData.getRemoteDataInfo());
			if (rmtData != null) {
				String testCode = RemoteCommunicate
						.encodeDECORemoteData(rmtData);
				showCodeSending();
				RemoteCommunicate.sendDECORemote(testCode);
			} else {
				Toast.makeText(this, "this device is not valid",
						Toast.LENGTH_SHORT).show();
			}

			// hideCodeSending();
		} else {
			// Log.v(TAG, "air index data ->"+ index);
			int code = Integer.parseInt(index);
			Log.v(TAG, "air code data ->" + code);
			ad.setCode(code);

			RemoteCommunicate.sendDECOAirRemote(ad);
		}

	}

	void save(int count) {
		String index = productList.get(count);
		Value.rmtDev.setCode(index);
		if (Value.rmtDev.getType()==Value.DeviceType.TYPE_AIR){
			Value.rmtDev.setAirData(ad);
		}
		UserDB mUserDB = new UserDB(this);
		mUserDB.open();
		mUserDB.saveRemoteDevice(Value.rmtDev);
		mUserDB.getRemoteDevices();
		if(Value.rmtDev.getType()!=Value.DeviceType.TYPE_AIR){
		mUserDB.delDevKeyTab(Value.rmtDev.getId());
		mUserDB.close();	
		RemoteGetKeyValue.keyTabSetValue(Value.rmtDev,mContext);	
		}else {
		mUserDB.close();		
		}
	}

	@Override
	public void onStart() {
		super.onStart();
//		UserDB mUserDB = new UserDB(this);
//		mUserDB.open();
//		mUserDB.getAirData(Value.rmtDev.getId());
//		mUserDB.close();
//		ad = Value.airData;

	}

	@Override
	protected void onDestroy() {
		super.onDestroy();
		// if (mThread != null) {
		// mThread.cancel();
		// }
		mRmtDB.close();

	}

	public void onItemSelected(AdapterView<?> arg0, View arg1, int arg2,
			long arg3) {

		// TODO Auto-generated method stub
		if (arg0 == deviceSp) {

			mCutCount = 0;

			Value.rmtDev.setBrand(nameList.get(arg2));
			getProducts(Value.RemoteType[mType], list.get(arg2));
			// sendTestCode(mCutCount);
			mCount = productList.size();
			mDeviceCount.setText("(" + String.valueOf(mCount) + ")          ");
			mCurrentCount.setText("    (" + String.valueOf(mCutCount + 1)
					+ ")     ");
		}
	}

	public void initialRemoteList(int mType) {
		mCutCount = 0;

		mTypeName = Value.RemoteType[mType];
		ArrayAdapter<String> remote_adapter = new ArrayAdapter<String>(this,
				R.layout.option_item, getBrand(mTypeName));
		deviceSp.setAdapter(remote_adapter);

		mCutCount = 0;
		mCount = remote_adapter.getCount();

		mDeviceCount.setText("(" + String.valueOf(mCount) + ")");
		mCurrentCount.setText("    (" + String.valueOf(mCutCount + 1)
				+ ")     ");
	}

	@Override
	public boolean onKeyDown(int keyCode, KeyEvent event) {
		// TODO Auto-generated method stub

		return super.onKeyDown(keyCode, event);
	}

	public void onNothingSelected(AdapterView<?> arg0) {
		// TODO Auto-generated method stub
	}

	public void onClick(View arg0) {
		// TODO Auto-generated method stub
		switch (arg0.getId()) {
		// case R.id.str_auto:
		// if (mThread != null) {
		// mThread.cancel();
		// mThread = null;
		// }
		// autoButton.setEnabled(false);
		// stopButton.setEnabled(true);
		// saveButton.setEnabled(false);
		// upButton.setEnabled(false);
		// downButton.setEnabled(false);
		// deviceSp.setEnabled(false);
		// typeSp.setEnabled(false);
		// // mThread = new EffectThread();
		// // mThread.start();
		// break;
		// case R.id.str_stop:
		// if (mThread != null) {
		// mThread.cancel();
		// mThread = null;
		// }
		// autoButton.setEnabled(false);
		// stopButton.setEnabled(false);
		// saveButton.setEnabled(true);
		// upButton.setEnabled(true);
		// downButton.setEnabled(true);
		//
		// deviceSp.setEnabled(true);
		// typeSp.setEnabled(true);
		// break;
		case R.id.asl_right:


			save(mCutCount);
			Log.v(TAG, "end --->" + Value.rmtDev.getFullInfo());
		
			
			finish();
			RemoteDevicesList.instance.finish();
			break;
		case R.id.asl_left:
			Log.v(TAG, "back --->" + Value.rmtDev.getFullInfo());
	
			finish();
			break;
		case R.id.str_up:
			mCutCount++;
			if (mCutCount > mCount - 1) {
				mCutCount = 0;
			}
			try {
				sendTestCode(mCutCount);
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			mDeviceCount.setText("(" + String.valueOf(mCount) + ")          ");
			mCurrentCount.setText("    (" + String.valueOf(mCutCount + 1)
					+ ")     ");

			break;
		case R.id.str_down:
			mCutCount--;
			if (mCutCount < 0) {
				mCutCount = mCount - 1;
			}
			try {
				sendTestCode(mCutCount);
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			mDeviceCount.setText("(" + String.valueOf(mCount) + ")          ");
			mCurrentCount.setText("    (" + String.valueOf(mCutCount + 1)
					+ ")     ");
			break;
		default:
			break;
		}

	}

}
