package com.deco.remote;

import com.deco.allremote.R;

import com.deco.data.RemoteDevice;
import com.deco.data.Value;
import com.deco.ircore.KeyTreate;
import com.deco.ircore.RemoteCommunicate;


import com.deco.ui.QuitDialog;
import com.deco.ui.SelectPicPopupWindow;

//import com.deco.utils.RemoteDB;
//import com.deco.utils.UserDB;

import android.os.Bundle;
import android.os.Message;
import android.os.Vibrator;

//import android.os.Environment;
import android.os.Handler;


import android.annotation.SuppressLint;


import android.app.AlertDialog;
import android.app.Dialog;

import android.app.TabActivity;

import android.content.Context;


import android.content.DialogInterface;
import android.content.Intent;




import android.util.DisplayMetrics;
import android.util.Log;

import android.view.GestureDetector;
import android.view.Gravity;
import android.view.KeyEvent;

import android.view.LayoutInflater;


import android.view.GestureDetector.OnGestureListener;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnClickListener;

import android.view.View.OnTouchListener;
import android.view.animation.AccelerateInterpolator;
import android.view.animation.AlphaAnimation;
import android.view.animation.Animation;


//import android.widget.HorizontalScrollView;
import android.widget.ImageButton;

import android.widget.TabHost.OnTabChangeListener;
import android.widget.TextView;


import android.widget.RelativeLayout;

import android.widget.TabHost;


import android.widget.Toast;



@SuppressLint("HandlerLeak")

public class MainActivity extends TabActivity implements OnTouchListener,
		OnGestureListener {
	private static final String TAG = "MainActivity";
	private static final int FLING_MIN_DISTANCE = 20;
	private static final int FLING_MIN_VELOCITY = 0;

	
	private static Context mContext;
	private TabHost tabHost;
//	private HorizontalScrollView mHs;
	private GestureDetector mGestureDetector;
//	private Button mBt_menu;
	private static KeyTreate mKeyTreate = null;
	SelectPicPopupWindow menuWindow;
	private Vibrator vibrator;  
//	private SlidingDrawer sd;
//	private MenuAdapter myListAdapter;
//	private ListView listView;
//	private ArrayList<MenuList> menulists;

	TextView devicesTV;
	private ImageButton mBt_menu;
	private ImageButton mBT_next;
	private ImageButton mBT_previous;

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		
		mGestureDetector = new GestureDetector(this);
		RelativeLayout line = (RelativeLayout) findViewById(R.id.parent);
		line.setOnTouchListener(this);
		line.setLongClickable(true);
		mContext = this;
		if (RemoteCommunicate.initDECORemote()){
			Toast.makeText(mContext, "device de6008 ready", Toast.LENGTH_SHORT).show();
			}else {
				Toast.makeText(mContext, " de6008 is not ready", Toast.LENGTH_SHORT).show();	
			}
		DisplayMetrics dm = new DisplayMetrics();
		getWindowManager().getDefaultDisplay().getMetrics(dm);
		int screenWidth = dm.widthPixels;
		int screenHeight = dm.heightPixels;
		Value.screenHeight = screenHeight;
		Value.screenWidth  = screenWidth;
		devicesTV = (TextView) findViewById(R.id.selectRemote);
	//	mHs = (HorizontalScrollView) findViewById(R.id.hs);
		mBt_menu = (ImageButton) findViewById(R.id.settings);
		mBt_menu.setOnClickListener(new OnClickListener() {			
				public void onClick(View v) {
					menuWindow = new SelectPicPopupWindow(MainActivity.this, itemsOnClick);
					menuWindow.showAtLocation(MainActivity.this.findViewById(R.id.parent), Gravity.BOTTOM|Gravity.CENTER_HORIZONTAL, 0, 0); 
				}
			});
		mBT_next = (ImageButton) findViewById(R.id.selectRight);
		mBT_next.setOnClickListener(new OnClickListener() {			
			private RemoteDevice mDev;

			public void onClick(View v) {
				int total = tabHost.getTabWidget().getChildCount();
				int current = tabHost.getCurrentTab();
				if (current + 1 >= total) {
					current = total - 1;
				} 
				else {
					current = current + 1;
				}
//				Log.v(TAG, "total ====>" + total);
//				Log.v(TAG, "current ====>" + current);
				mDev =Value.rmtDevs.get(current);
				tabHost.setCurrentTab(current);
				devicesTV.setText(mDev.getName());
			}
		});
		mBT_previous = (ImageButton) findViewById(R.id.selectLeft);
		mBT_previous.setOnClickListener(new OnClickListener() {			
			private RemoteDevice mDev;

			public void onClick(View v) {
				
				int current = tabHost.getCurrentTab();
				if (current - 1 < 0) {
					current = 0;
				} else {
					current = current - 1;
				}
				tabHost.setCurrentTab(current);
				mDev =Value.rmtDevs.get(current);
				devicesTV.setText(mDev.getName());

		
			}
		});
		
	//	menuLoading();
		
		initHostTab();

	
		
		 
		
	}

	@Override
	public void onStart() {
		super.onStart();
		if (mKeyTreate == null) {
			mKeyTreate = KeyTreate.getInstance();
			mKeyTreate.setContext(this);
			mKeyTreate.setHandler(mHandler);
		}
		
		
		
		tabHost = getTabHost();
		tabHost.setCurrentTab(0);
		tabHost.clearAllTabs();
		initHostTab();
		tabHost.setOnTabChangedListener(new OnTabChangeListener()  
        {  
            public void onTabChanged(String tabId)  
            {  
            	Value.currentDevice = tabHost.getCurrentTab();
           //    Toast.makeText(getApplicationContext(), "鐜板湪鏄�+tabHost.getCurrentTab()	, Toast.LENGTH_SHORT).show();  
            }  
        });  
	//	RemoteComm.initRemote();
	

	}

	@Override
	public void onDestroy() {
		super.onDestroy();
		
	}
	
	@Override
	public void onPause() {
		super.onPause();
		
	
	}
	
	@Override
	protected void onRestart() {
		// TODO Auto-generated method stub
		super.onRestart();
	}

	void initHostTab(){
		tabHost = getTabHost();
		TabHost.TabSpec spec;
		tabHost.setup();
		Intent intent;
		RemoteDevice mDev;
		for (int i=0;i<Value.rmtDevs.size();i++){
			mDev =Value.rmtDevs.get(i);
		switch (mDev.getType()){
		
		case Value.DeviceType.TYPE_TV:
			intent = new Intent().setClass(this, TVRemote.class);
			intent.putExtra("current",mDev.getId());  
			spec = tabHost
					.newTabSpec(this.getString(R.string.tv))
					.setIndicator(mDev.getName())
					.setContent(intent);
			tabHost.addTab(spec);
			break;
		case Value.DeviceType.TYPE_DVD:
			intent = new Intent().setClass(this, DVDRemote.class);
			intent.putExtra("current",mDev.getId());  
			spec = tabHost
					.newTabSpec(this.getString(R.string.dvd))
					.setIndicator(mDev.getName())
					.setContent(intent);
			tabHost.addTab(spec);
			break;
		case Value.DeviceType.TYPE_STB:
			intent = new Intent().setClass(this,STBRemote.class);
			intent.putExtra("current",mDev.getId());  
			spec = tabHost
					.newTabSpec(this.getString(R.string.stb))
					.setIndicator(mDev.getName())
					.setContent(intent);
			tabHost.addTab(spec);
			break;
		case Value.DeviceType.TYPE_PJT:
			intent = new Intent().setClass(this, PJTRemote.class);
			intent.putExtra("current",mDev.getId());  
			spec = tabHost
					.newTabSpec(this.getString(R.string.pjt))
					.setIndicator(mDev.getName())
					.setContent(intent);
			tabHost.addTab(spec);
			break;
		case Value.DeviceType.TYPE_FAN:
			intent = new Intent().setClass(this, FanRemote.class);
			intent.putExtra("current",mDev.getId());  
			spec = tabHost
					.newTabSpec(this.getString(R.string.fan))
					.setIndicator(mDev.getName())
					.setContent(intent);
			tabHost.addTab(spec);
			break;
		case Value.DeviceType.TYPE_AIR:
			intent = new Intent().setClass(this, AirRemote.class);
			intent.putExtra("current",mDev.getId());  
			spec = tabHost
					.newTabSpec(this.getString(R.string.air))
					.setIndicator(mDev.getName())
					.setContent(intent);
			tabHost.addTab(spec);		
			break;
		
		default:
			break;
		}
	}
//		TabWidget tabWidget = tabHost.getTabWidget();
//		int count = tabWidget.getChildCount();
	
		
	
//		if (count > 4) {
//			for (int i = 0; i < count; i++) {
//				tabWidget.getChildTabViewAt(i).setMinimumWidth(Value.screenWidth / 4);
//			}
//		}
//		for (int i = 0; i < tabWidget.getChildCount(); i++) {
//			tabWidget.getChildAt(i).getLayoutParams().height = (Value.screenHeight) / 18;
//			tabWidget.getChildAt(i).getLayoutParams().width = Value.screenWidth / 4;
//		}
		
		tabHost.setCurrentTab(0);	
		mDev =Value.rmtDevs.get(0);
	
		devicesTV.setText(mDev.getName());
}
	

	

	public boolean onDown(MotionEvent arg0) {
		// TODO Auto-generated method stub
		return false;
	}

	public void onActivityResult(int requestCode, int resultCode, Intent data) {
		switch (requestCode) {
		case R.id.REQUEST_STUDY:
			 if (resultCode == RESULT_OK) { 
					Toast t = Toast.makeText(mContext, R.string.study_alert,  Toast.LENGTH_SHORT);
	            	t.setGravity( Gravity.CENTER_HORIZONTAL, 0, 0);
	            	t.show();
		        }else if (resultCode == RESULT_CANCELED) { 
		            Bundle bundle = data.getExtras(); 
		            int status = bundle.getInt("status");  
		            if (status == -1){
		            	Toast t = Toast.makeText(mContext, R.string.study_exit,  Toast.LENGTH_SHORT);
		            	t.setGravity( Gravity.CENTER_HORIZONTAL, 0, 0);
		            	t.show();
		     
		            }
		            else if (status == 0){
		            	Toast t = Toast.makeText(mContext, R.string.study_timeout,  Toast.LENGTH_SHORT);
		            	t.setGravity( Gravity.CENTER_HORIZONTAL, 0, 0);
		            	t.show();
		            }
		            
		        } 
			break;
		default:
			break;
		}

	}

	


	
	public boolean onFling(MotionEvent e1, MotionEvent e2, float velocityX,
			float velocityY) {
		RemoteDevice mDev; 
		// TODO Auto-generated method stub
		int total = tabHost.getTabWidget().getChildCount();
		int current = tabHost.getCurrentTab();
		// TODO Auto-generated method stub
		if (e1.getX() - e2.getX() > FLING_MIN_DISTANCE
				&& Math.abs(velocityX) > FLING_MIN_VELOCITY) {
			if (current + 1 >= total) {
				current = total - 1;
			} 
			else {
				current = current + 1;
			}
//			Log.v(TAG, "total ====>" + total);
//			Log.v(TAG, "current ====>" + current);
			mDev =Value.rmtDevs.get(current);
			tabHost.setCurrentTab(current);
			devicesTV.setText(mDev.getName());
//			if (current % 4 != 0 || current == 0) {
//				mHs.scrollTo(tabHost.getTabWidget().getChildTabViewAt(current - (current % 4))
//						.getLeft(), mHs.getHeight());
//			} else {
//				mHs.scrollTo(tabHost.getTabWidget().getChildTabViewAt(current)
//						.getLeft(), mHs.getHeight());
//			}

		} else if (e2.getX() - e1.getX() > FLING_MIN_DISTANCE
				&& Math.abs(velocityX) > FLING_MIN_VELOCITY) {
			if (current - 1 < 0) {
				current = 0;
			} else {
				current = current - 1;
			}
			tabHost.setCurrentTab(current);
			mDev =Value.rmtDevs.get(current);
			devicesTV.setText(mDev.getName());
//			mHs.scrollTo(tabHost.getTabWidget().getChildTabViewAt(current)
//					.getLeft(), mHs.getHeight());
		}
		return false;
	}

	public void onLongPress(MotionEvent e) {
		// TODO Auto-generated method stub

	}

	public boolean onScroll(MotionEvent e1, MotionEvent e2, float distanceX,
			float distanceY) {
		// TODO Auto-generated method stub
		return false;
	}

	public void onShowPress(MotionEvent e) {
		// TODO Auto-generated method stub

	}

	public boolean onSingleTapUp(MotionEvent e) {
		// TODO Auto-generated method stub
		return false;
	}

	public boolean onTouch(View arg0, MotionEvent arg1) {
		// TODO Auto-generated method stub
		return mGestureDetector.onTouchEvent(arg1);
	}
	
	
	private OnClickListener  itemsOnClick = new OnClickListener(){

			public void onClick(View v) {
				menuWindow.dismiss();
				switch (v.getId()) {
				case R.id.btn_study:
//				
//					Log.v(TAG, "btn_study btn_study");
//					Value.isStudying = true;
//					
//					RemoteComm.learnRemoteMain();
//					Toast toast = Toast.makeText(getApplicationContext(), R.string.study_alert,
//							Toast.LENGTH_SHORT);
//					toast.setGravity( Gravity.CENTER_HORIZONTAL, 0, 0);
//					toast.show();
					mHandler.obtainMessage(R.id.MSG_OPTION_STUDY, 1, -1)
					.sendToTarget();
					break;
				case R.id.btn_options:		
					mHandler.obtainMessage(R.id.MSG_OPTION_LIST, 1, -1)
					.sendToTarget();
					break;
				case R.id.btn_about:	
					mHandler.obtainMessage(R.id.MSG_OPTION_ABOUT, 1, -1)
					.sendToTarget();
					break;
				case R.id.btn_quit:	
					mHandler.obtainMessage(R.id.MSG_OPTION_QUIT, 1, -1)
					.sendToTarget();
					break;	
				default:
					break;
				}
				
					
			}
	    	
	    };
	
	void popMenuLoad(){
		
	}
//    void menuLoading(){
 //   	listView = (ListView) findViewById(R.id.menu_list);
//		menulists = new ArrayList<MenuList>();
//		Resources res = getResources();
//		Bitmap bmp=BitmapFactory.decodeResource(res, R.drawable.menu_list);  
//		String str = res.getString(R.string.options);
//		MenuList ml = new MenuList(bmp,str);
//		menulists.add(ml);
//		bmp=BitmapFactory.decodeResource(res, R.drawable.menu_learn);
//		str = res.getString(R.string.study);
//		ml = new MenuList(bmp,str);
//		menulists.add(ml);
//		bmp=BitmapFactory.decodeResource(res, R.drawable.menu_about);
//		str = res.getString(R.string.about);
//		ml = new MenuList(bmp,str);
//		menulists.add(ml);
//		bmp=BitmapFactory.decodeResource(res, R.drawable.menu_quit);
//		str = res.getString(R.string.quit);
//		ml = new MenuList(bmp,str);
//		menulists.add(ml);
////		sd = (SlidingDrawer) findViewById(R.id.sliding);  
//	
//
//		myListAdapter = new MenuAdapter(this, menulists);
//
//		listView.setAdapter(myListAdapter);
//
//		
//		listView.setOnItemClickListener(new OnItemClickListener()
//		{
//		    @Override
//		    public void onItemClick(AdapterView<?> arg0, View arg1, int arg2,
//		            long arg3)
//		    {
//		    	
//		    	
//		    	sd.close();
//		    	switch (arg2) {
//		    	
//				case 1:
//					
//					mHandler.obtainMessage(R.id.MSG_OPTION_STUDY, 1, -1)
//					.sendToTarget();
//					
//					break;
//				case 0:		
//					mHandler.obtainMessage(R.id.MSG_OPTION_LIST, 1, -1)
//					.sendToTarget();
//					break;
//				case 2:	
//					mHandler.obtainMessage(R.id.MSG_OPTION_ABOUT, 1, -1)
//					.sendToTarget();
//					
//					break;
//				case 3:	
//					mHandler.obtainMessage(R.id.MSG_OPTION_QUIT, 1, -1)
//					.sendToTarget();
//					break;	
//				default:
//					break;
//				}
//		    }
//		});
//    }
	
	
	public static Context getContext() {
		return mContext;
	}
	
	public void showCodeSending()
	  {
	    mHandler.post(new Runnable()
	    {
	      public void run()
	      {
	        final View localView = findViewById(R.id.code_sending);
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
	        final View localView = findViewById(R.id.code_sending);
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

	private final Handler mHandler = new Handler() {

		@Override
		public void handleMessage(Message msg) {
			super.handleMessage(msg);
			switch (msg.what) {
			case R.id.MESSAGE_WRITE:
				break;
			case R.id.MESSAGE_SEND:
				vibrator = (Vibrator)getSystemService(Context.VIBRATOR_SERVICE);  
				 long [] pattern = {100,100};   
				vibrator.vibrate(pattern,1);          
				showCodeSending();
				
		//		hideCodeSending();
				
				break;
			case R.id.MESSAGE_READ:
				
				break;
			case R.id.MESSAGE_TOAST:
			
				break;
			case R.id.MSG_LEARN_END:
				RemoteCommunicate.remoteDECOLearnStop();
				Value.isStudying=false;
				Toast toast = Toast.makeText(getApplicationContext(), R.string.study_save,
						Toast.LENGTH_SHORT);
					toast.setGravity( Gravity.CENTER_HORIZONTAL, 0, 0);
					toast.show();
				break;
			case R.id.MSG_OPTION_STUDY:	

				Log.v(TAG, "msg study");
				Value.isStudying = true;
				Intent studyIntent = new Intent(mContext, Studying.class);
			
				startActivityForResult(studyIntent, R.id.REQUEST_STUDY);  
				
				break;
			case R.id.MSG_OPTION_LIST:
				Log.v("test", "btn_options btn_options");
//				Intent optionsIntent = new Intent(mContext, ListActivity.class);
//				startActivityForResult(optionsIntent, R.id.REQUEST_OPTIONS);
				
				Intent optionsIntent = new Intent(mContext, RemoteDevicesList.class);
				startActivity(optionsIntent);
				break;
			case R.id.MSG_OPTION_QUIT:
			
				 Dialog dialog = new QuitDialog(mContext, R.style.QuitDialog  ,new QuitDialog.PriorityListener() {  
						
						
						@Override
						public void quitApplication() {
							// TODO Auto-generated method stub
							finish();
						}  
		            });  
		              dialog.show();
			
				break;
			case R.id.MSG_OPTION_ABOUT:
//				Dialog dialog = new Dialog(mContext);
//				dialog.setContentView(R.layout.dialog_about);
//				dialog.setTitle(R.string.title_about);
//				dialog.show();
				LayoutInflater mInflater = LayoutInflater.from(mContext);
				View settingView = mInflater.inflate(R.layout.dialog_about, null);
				AlertDialog aboutDialog = new AlertDialog.Builder(mContext)
						.setIcon(R.drawable.ic_launcher)
						.setTitle(R.string.title_about)
						.setView(settingView)
						.setPositiveButton(R.string.dialog_ok,
								new DialogInterface.OnClickListener() {
									public void onClick(DialogInterface dialog,
											int whichButton) {
									}
								}).create();
				aboutDialog.show();
				break;
			
				
			default:
				break;
			}
		}
	};
	public boolean dispatchKeyEvent(KeyEvent event) { 
	    if (event.getKeyCode() == KeyEvent.KEYCODE_BACK) { 
	        if (event.getAction() == KeyEvent.ACTION_DOWN 
	                && event.getRepeatCount() == 0) { 
	        	 Dialog dialog = new QuitDialog(mContext, R.style.QuitDialog  ,new QuitDialog.PriorityListener() {  
						
						
						@Override
						public void quitApplication() {
							// TODO Auto-generated method stub
							finish();
						}  
		            });  
		              dialog.show();
	            return true; 
	        } 
	    } 
	    if (event.getKeyCode() == KeyEvent.KEYCODE_MENU) { 
	        if (event.getAction() == KeyEvent.ACTION_DOWN 
	                && event.getRepeatCount() == 0) { 
	        	menuWindow = new SelectPicPopupWindow(MainActivity.this, itemsOnClick);
				menuWindow.showAtLocation(MainActivity.this.findViewById(R.id.parent), Gravity.BOTTOM|Gravity.CENTER_HORIZONTAL, 0, 0); 
	            return true; 
	        } 
	    } 
	    return super.dispatchKeyEvent(event); 
	} 

}
