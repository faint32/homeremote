package com.sommer.service;








import com.sommer.utils.MyRemoteDatabase;

import android.app.IntentService;





import android.content.Context;
import android.content.Intent;



import android.os.IBinder;




public class RemoteUpdateService extends IntentService {

  public static String TAG = "RemoteUpdateService";
 
  
 
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
    refreshremoterlists();
    sendBroadcast(new Intent(remoterListS_REFRESHED));
    
    
  }

  @Override
  public IBinder onBind(Intent intent) {
    return null;
  }
 
 

  public void refreshremoterlists() {
	  
   

  }
  
  @Override
  public int onStartCommand(Intent intent, int flags, int startId) {
    // Retrieve the shared preferences
    Context context = getApplicationContext();
    
    MyRemoteDatabase.getRemoteIndex(context);


    return super.onStartCommand(intent, flags, startId);
  };





  @Override
  public void onCreate() {
    super.onCreate();

  }

}