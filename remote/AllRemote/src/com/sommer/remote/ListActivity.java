package com.sommer.remote;

import java.sql.Array;
import java.util.ArrayList;
import java.util.Locale;
import java.util.Timer;
import java.util.TimerTask;



import com.sommer.allremote.R;
import com.sommer.data.AirData;
import com.sommer.data.RemoteData;
import com.sommer.data.Value;
import com.sommer.ircomm.RemoteCore;

import com.sommer.utils.MyRemoteDatabase;
import com.sommer.utils.RemoteDB;
import com.sommer.utils.UserDB;


import android.R.integer;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.app.Activity;
import android.content.res.Resources;
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
//import android.widget.RadioButton;
import android.widget.Spinner;
import android.widget.AdapterView.OnItemSelectedListener;
import android.widget.TextView;

public class ListActivity extends Activity implements OnItemSelectedListener,
		OnClickListener {
	final static String TAG = "ListActivity";
//	private EffectThread mThread = null;
	private Spinner deviceSp = null;
	private Spinner typeSp = null;
	private int mCount = 0;
	private int mCutCount = 0;
	private AirData ad;
	
	private TextView mDeviceCount = null;
	private TextView mRemainCount = null;
	private TextView mCurrentDevice= null;
	private TextView mCurrentCount = null;
	private int mType = Value.DeviceType.TYPE_TV;
	private String mTypeName =null;

	private int mI = 0;

	private ArrayList<String> list = new ArrayList<String>();
	private ArrayList<String> productList = new ArrayList<String>();

	private RemoteDB mRmtDB;
	private UserDB mUsertDB;
	RemoteData rmtData = new RemoteData();
//	Button autoButton;
//	Button stopButton;
	Button saveButton;
	Button upButton;
	Button downButton;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		requestWindowFeature(Window.FEATURE_INDETERMINATE_PROGRESS);
		setContentView(R.layout.activity_list);
		ad = new AirData(5000, 1, 20, 1, 1, 1, 1);
		// database instruction
		mRmtDB = new RemoteDB(getApplicationContext());
		mUsertDB = new UserDB(getApplicationContext());
		mTypeName = Value.RemoteType[mType];

		typeSp = (Spinner) findViewById(R.id.typeSp);
		ArrayAdapter<CharSequence> type_adapter = ArrayAdapter
				.createFromResource(this, R.array.type_array,
						R.layout.option_item);
		 
	//	type_adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item); 
		typeSp.setAdapter(type_adapter);
		typeSp.setOnItemSelectedListener(this);
		
		
		deviceSp = (Spinner) findViewById(R.id.nameSp);
		deviceSp.setOnItemSelectedListener(this);

//
		mDeviceCount = (TextView) findViewById(R.id.count_text);
		mRemainCount = (TextView) findViewById(R.id.remain_count);
		mCurrentDevice= (TextView) findViewById(R.id.cur_name);;
		mCurrentCount = (TextView) findViewById(R.id.cur_count);

//		autoButton = (Button) findViewById(R.id.str_auto);
//		autoButton.setOnClickListener(this);
//		autoButton.setEnabled(false);
//		stopButton = (Button) findViewById(R.id.str_stop);
//		stopButton.setOnClickListener(this);
//		stopButton.setEnabled(false);
		 saveButton = (Button) findViewById(R.id.str_save);
		saveButton.setOnClickListener(this);
		 upButton = (Button) findViewById(R.id.str_up);
		upButton.setOnClickListener(this);
		upButton.setEnabled(false);
		 downButton = (Button) findViewById(R.id.str_down);
		downButton.setOnClickListener(this);
		downButton.setEnabled(false);
	//	Locale.getDefault().getLanguage();
	}
	
	
	
	 private ArrayList<String> getBrand(String _type)
	    {
			
			mRmtDB.open();
			list=mRmtDB.getBrand(_type);
		//	list=mRmtDB.translateBrands(list);
			mRmtDB.close();
	        return list;
	    }

	 
	 private void getProducts(String _type,String _brand)
	    {
			
			mRmtDB.open();
			try {
				productList=mRmtDB.getProducts(_type,_brand);
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		
			mRmtDB.close();
			Log.v(TAG, "CODE DATA ->"+ _type +"BRAND DATA ->" + _brand);
			 for(int i=0;i<productList.size();i++)
			  {
				 Log.v(TAG, "productlist ( "+ i +") data->" + productList.get(i));
			  
			  }
			 mCount =productList.size();
	    }
	 private final Handler mHandler = new Handler() {

			@Override
			public void handleMessage(Message msg) {
				super.handleMessage(msg);
				switch (msg.what) {
				case R.id.MESSAGE_WRITE:
					mRemainCount.setTextSize(60);
					mRemainCount.setText(String.valueOf(msg.arg1));
				//	spark();
					break;
				}
			}
		};
		private void showCodeSending()
		  {
		    mHandler.post(new Runnable()
		    {
		      public void run()
		      {
		        final View localView = findViewById(R.id.testcode_sending);
		        if (localView.getVisibility() == 0)
		          return;
		        AlphaAnimation localAlphaAnimation = new AlphaAnimation(0.0F, 1.0F);
		        localAlphaAnimation.setInterpolator(new AccelerateInterpolator());
		        localAlphaAnimation.setDuration(100);
		        localAlphaAnimation.setAnimationListener(new Animation.AnimationListener()
		        {
		          public void onAnimationEnd(Animation paramAnimation)
		          {
		        	  localView.setVisibility(8);
		          }

		          public void onAnimationRepeat(Animation paramAnimation)
		          {
		          }

		          public void onAnimationStart(Animation paramAnimation)
		          {
		        	  localView.setVisibility(0);
		          }
		        });
		        localView.startAnimation(localAlphaAnimation);
		      }
		    });
		  }

		public void hideCodeSending()
		  {
		    mHandler.post(new Runnable()
		    {
		      public void run()
		      {
		        final View localView = findViewById(R.id.testcode_sending);
		        if (localView.getVisibility() != 0)
		          return;
		        AlphaAnimation localAlphaAnimation = new AlphaAnimation(1.0F, 0.0F);
		        localAlphaAnimation.setInterpolator(new AccelerateInterpolator());
		        localAlphaAnimation.setDuration(100);
		        localAlphaAnimation.setAnimationListener(new Animation.AnimationListener()
		        {
		          public void onAnimationEnd(Animation paramAnimation)
		          {
		        	  localView.setVisibility(0);
		          }

		          public void onAnimationRepeat(Animation paramAnimation)
		          {
		          }

		          public void onAnimationStart(Animation paramAnimation)
		          {
		        	  localView.setVisibility(8); 
		          }
		        });
		        localView.startAnimation(localAlphaAnimation);
		      }
		    });
		  }	 
	
void sendTestCode(int count){
		 String index = productList.get(count);
		 if (mType!= Value.DeviceType.TYPE_AIR){
		 mRmtDB.open();
		 RemoteData rmtData = null;
		try {
			rmtData = mRmtDB.getKeyData(mType, index);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		 mRmtDB.close();
		 Log.v(TAG, "current index ====>   "+ index);
		 String testCode = RemoteCore.encodeRemoteData(rmtData);
		 showCodeSending();
		 RemoteCore.sendTestRemote(testCode);
	//	 hideCodeSending();
		 }else{
		Log.v(TAG, "air index data ->"+ index);	 
		int id=	 Integer.parseInt(index);
		Log.v(TAG, "air index data ->"+ id);
			 ad.setCodeType(id);
			 
		 RemoteCore.sendAirRemote(ad);
		 }
		 
	 }

	void save(int count){
		 String index = productList.get(count);
		 switch(mType){
		 case Value.DeviceType.TYPE_TV:
			 Value.tv_index=index;
			 break;
		 case Value.DeviceType.TYPE_DVD:
			 Value.dvd_index=index;
			 break;
		 case Value.DeviceType.TYPE_STB:
			 Value.stb_index=index;
			 break;
		 case Value.DeviceType.TYPE_PJT:
			 Value.pjt_index=index;
			 break;
		 case Value.DeviceType.TYPE_FAN:
			 Value.fan_index=index;
			 break;
		 case Value.DeviceType.TYPE_AIR:
			 Value.air_index=index;
			 int id=Integer.parseInt(index);
			 ad.setCodeType(id);
			 MyRemoteDatabase.saveAirData(getApplicationContext(), ad);
			 break;
		 default:
			 break;
		 }
		 MyRemoteDatabase.saveRemoteIndex(getApplicationContext());
		 if(mType!= Value.DeviceType.TYPE_AIR){
		 mRmtDB.open();
		 mRmtDB.setKeyRemoteData(mType, index);
		 mRmtDB.close();
		 
		 mUsertDB.open();
		 mUsertDB.saveAllKeyTabValue();
		 mUsertDB.close();
		 }
	 }
	 
	@Override
	public void onStart() {
		super.onStart();
	//	mRmtDB.open();
	}

	@Override
	protected void onDestroy() {
		super.onDestroy();
//		if (mThread != null) {
//			mThread.cancel();
//		}
		mRmtDB.close();
	//	mRmtDB.close();
	}

	
	public void onItemSelected(AdapterView<?> arg0, View arg1, int arg2,
			long arg3) {
		String brandName = null;
		// TODO Auto-generated method stub
		if (arg0 == typeSp) {
//			autoButton.setEnabled(false);
//			stopButton.setEnabled(false);
			saveButton.setEnabled(true);
			upButton.setEnabled(true);
			downButton.setEnabled(true);
			switch (arg2) {
			case 0:				// tv
				mType = Value.DeviceType.TYPE_TV;
				mTypeName = Value.RemoteType[mType];
				ArrayAdapter<String> tv_adapter =new  
				ArrayAdapter<String>(this, R.layout.option_item, getBrand(mTypeName));
				deviceSp.setAdapter(tv_adapter);

				mCount = tv_adapter.getCount();
		
				
				mDeviceCount.setText("(" + String.valueOf(mCount) + ")");
				mCurrentCount.setText("    (" + String.valueOf(mCutCount+1) + ")     ");

				return;
			case 1:
				mType = Value.DeviceType.TYPE_DVD;
				mTypeName = Value.RemoteType[mType];
				ArrayAdapter<String> dvd_adapter =new  
				ArrayAdapter<String>(this, R.layout.option_item, getBrand(mTypeName));

				deviceSp.setAdapter(dvd_adapter);
			
				mCount = dvd_adapter.getCount();

				
				
				mDeviceCount.setText("(" + String.valueOf(mCount) + ")");
				mCurrentCount.setText("    (" + String.valueOf(mCutCount+1) + ")     ");
				
				return;
			case 2:
				mType = Value.DeviceType.TYPE_STB;
				mTypeName = Value.RemoteType[mType];
				ArrayAdapter<String> stb_adapter =new  
				ArrayAdapter<String>(this, R.layout.option_item, getBrand(mTypeName));

				deviceSp.setAdapter(stb_adapter);
				
				mDeviceCount.setText("(" + String.valueOf(mCount) + ")");
				mCurrentCount.setText("    (" + String.valueOf(mCutCount+1) + ")     ");
				
				return;
			case 3:
				mType = Value.DeviceType.TYPE_AIR;
				mTypeName = Value.RemoteType[mType];
				ArrayAdapter<String> air_adapter =new  
				ArrayAdapter<String>(this, R.layout.option_item, getBrand(mTypeName));

				deviceSp.setAdapter(air_adapter);
				
				mCount = air_adapter.getCount();
				
				mDeviceCount.setText("(" + String.valueOf(mCount) + ")");
				mCurrentCount.setText("    (" + String.valueOf(mCutCount+1) + ")     ");
				
				return;
			case 4:
				mType = Value.DeviceType.TYPE_FAN;
				mTypeName = Value.RemoteType[mType];
				ArrayAdapter<String> fans_adapter =new  
				ArrayAdapter<String>(this, R.layout.option_item, getBrand(mTypeName));

				deviceSp.setAdapter(fans_adapter);
				mCount = fans_adapter.getCount();
				
			
				
				mDeviceCount.setText("(" + String.valueOf(mCount) + ")");
				mCurrentCount.setText("    (" + String.valueOf(mCutCount+1) + ")     ");
				
				return;
			case 5:
				mType = Value.DeviceType.TYPE_PJT;
				mTypeName = Value.RemoteType[mType];
				ArrayAdapter<String> pjt_adapter =new  
				ArrayAdapter<String>(this, R.layout.option_item, getBrand(mTypeName));
				deviceSp.setAdapter(pjt_adapter);
				mCount = pjt_adapter.getCount();
				mDeviceCount.setText("(" + String.valueOf(mCount) + ")");
				mCurrentCount.setText("    (" + String.valueOf(mCutCount+1) + ")     ");
			
				return;
			default:
				return;
			}
		}
		if (arg0 == deviceSp) {
		
//			autoButton.setEnabled(false);
//			stopButton.setEnabled(false);
			saveButton.setEnabled(true);
			upButton.setEnabled(true);
			downButton.setEnabled(true);
			Log.v(TAG, "arg2 --->" + arg2);
//			if (mType == Value.DeviceType.TYPE_TV) {
				mTypeName = Value.RemoteType[mType];
				brandName = list.get(arg2);
			//	Log.v(TAG, "get brandName of list"+ brandName);
			
				getProducts(Value.RemoteType[mType],brandName);
				mCount =productList.size();	
				

			mDeviceCount.setText("(" + String.valueOf(mCount) + ")          ");
			mCurrentCount.setText("    (" + String.valueOf(mCutCount+1) + ")     ");
		}
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
//		case R.id.str_auto:
//			if (mThread != null) {
//				mThread.cancel();
//				mThread = null;
//			}
//			autoButton.setEnabled(false);
//			stopButton.setEnabled(true);
//			saveButton.setEnabled(false);
//			upButton.setEnabled(false);
//			downButton.setEnabled(false);
//			deviceSp.setEnabled(false);
//			typeSp.setEnabled(false);
////			mThread = new EffectThread();
////			mThread.start();
//			break;
//		case R.id.str_stop:
//			if (mThread != null) {
//				mThread.cancel();
//				mThread = null;
//			}
//			autoButton.setEnabled(false);
//			stopButton.setEnabled(false);
//			saveButton.setEnabled(true);
//			upButton.setEnabled(true);
//			downButton.setEnabled(true);
//			
//			deviceSp.setEnabled(true);
//			typeSp.setEnabled(true);
//			break;
		case R.id.str_save:
			
//			if (mThread != null) {
//				mThread.cancel();
//				mThread = null;
//			}
			save(mCutCount);
			finish();
			break;
			
		case R.id.str_up:
			mCutCount++;
			if (mCutCount >mCount-1){
				mCutCount=0;
			}
			sendTestCode(mCutCount);	
			mDeviceCount.setText("(" + String.valueOf(mCount) + ")");
			mCurrentCount.setText("    (" + String.valueOf(mCutCount+1) + ")     ");
			
			break;
		case R.id.str_down:
			mCutCount--;
			if (mCutCount < 0){
				mCutCount=mCount-1;
			}
			sendTestCode(mCutCount);	
			mDeviceCount.setText("(" + String.valueOf(mCount) + ")");
			mCurrentCount.setText("    (" + String.valueOf(mCutCount+1) + ")     ");
			break;
		}

	}

	
}

