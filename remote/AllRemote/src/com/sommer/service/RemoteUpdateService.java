package com.sommer.service;








import java.io.IOException;
import java.util.HashMap;

import com.sommer.allremote.R;
import com.sommer.data.KeyToRemote;
import com.sommer.data.Value;
import com.sommer.ircomm.RemoteCore;
import com.sommer.utils.MyRemoteDatabase;
import com.sommer.utils.RemoteDB;
import com.sommer.utils.UserDB;

import android.app.IntentService;





import android.content.Context;
import android.content.Intent;



import android.os.IBinder;
import android.util.Log;
import android.view.Gravity;
import android.widget.Toast;




public class RemoteUpdateService extends IntentService {

  public static String TAG = "RemoteUpdateService";
 
  private RemoteDB mRmtDB = null;
  private UserDB mUserDB = null;
  Context mContext;
 
  public static final int NOTIFICATION_ID = 1;
  
  public RemoteUpdateService() {
    super("remoterlistUpdateService");
  }

  public RemoteUpdateService(String name) {
    super(name);
  }
  
  public static String remoterListS_REFRESHED = 
      "com.sommer.remotelist.remoteLists_REFRESHED";

  @Override
  protected void onHandleIntent(Intent intent) {
	  Value.REMOTE_TYPE= getResources().getStringArray(R.array.type_array);
	  Load();
    sendBroadcast(new Intent(remoterListS_REFRESHED));
    stopSelf();
    
  }

  @Override
  public IBinder onBind(Intent intent) {
    return null;
  }
 
 

 
  @Override
  public int onStartCommand(Intent intent, int flags, int startId) {
    // Retrieve the shared preferences
	 
    
  //  MyRemoteDatabase.getRemoteIndex(mContext);


    return super.onStartCommand(intent, flags, startId);
  };





  @Override
  public void onCreate() {
    super.onCreate();
    mContext = getApplicationContext();
    mRmtDB = new RemoteDB(mContext);
	try {
		mRmtDB.createDataBase();
	} catch (IOException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}

	
	mUserDB = new UserDB(mContext);
	try {
		mUserDB.createDataBase();
	} catch (IOException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}
  }

  @Override
	public void onDestroy() {
		super.onDestroy();
		mRmtDB.close();
		mUserDB.close();
		
	}
	
	
  
  
  public void Load() {
		
		MyRemoteDatabase.getRemoteIndex(mContext);
//		Value.keyRemoteTab = new HashMap<String, String>();
		if (Value.initial){
		mUserDB.open();
//		mUserDB.getUserKeyValue();
		mUserDB.getRemoteDevices();
		mUserDB.close();
		Log.v(TAG, "updata finished");
//		Toast toast = Toast.makeText(mContext, R.string.updata_end,
//				Toast.LENGTH_SHORT);
//		toast.setGravity(Gravity.BOTTOM | Gravity.CENTER_HORIZONTAL, 0, 0);
//		toast.show();
		}
		else{
//		mRmtDB.open();
//		mRmtDB.getKeyInitialTable();
//		
//		mRmtDB.close();
//		KeyToRemote.allKeyTabSetValue(this);
//		mUserDB.open();
//		mUserDB.saveAllKeyTabValue();
//		mUserDB.close();
		Value.initial=true;
		Save();
		Toast toast = Toast.makeText(mContext, R.string.first_updata_end,
				Toast.LENGTH_SHORT);
		toast.setGravity(Gravity.BOTTOM | Gravity.CENTER_HORIZONTAL, 0, 0);
		toast.show();
	
		}
  }
  public void Save() {
		MyRemoteDatabase.saveRemoteIndex(mContext);
	}
}