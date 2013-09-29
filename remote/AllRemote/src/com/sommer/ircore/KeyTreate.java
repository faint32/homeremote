package com.sommer.ircore;

import android.content.Context;
import android.os.Handler;
import android.util.Log;

import com.sommer.allremote.R;
import com.sommer.data.AirData;

import com.sommer.data.RemoteData;
import com.sommer.data.RemoteDevice;
import com.sommer.data.Value;
import com.sommer.utils.RemoteDB;
import com.sommer.utils.Tools;
import com.sommer.utils.UserDB;

public class KeyTreate {
	private final static String TAG ="KeyTreate";
	private Handler mHandler;
	private static Context mContext;
	private static UserDB userDB;

	private static KeyTreate mKeyTreate = null;
	
	
	public void setHandler(Handler _handler) {
		mHandler = _handler;
	}
	
	
	
	public static KeyTreate getInstance() {
		if (mKeyTreate == null) {
			mKeyTreate = new KeyTreate();
		}
		return mKeyTreate;
	}
	public void setContext(Context _context) {
		mContext = _context;
	}
	public  void keyTreate(int device, String keyName){
		
		try {
		
			
			if (Value.isStudying){
			
			mHandler.obtainMessage(R.id.MSG_LEARN_END, 1, -1)
			.sendToTarget();

			}
			else{
			//	Log.v(TAG, "keytable----->"+ Value.keyRemoteTab.toString() );
//			String rmtData = Value.keyRemoteTab.get(Value.currentKey);
//			Log.v(TAG, "rmtdata--->"+ rmtData);
//			byte[] rmtDataByte = Tools.hexStringToBytes(rmtData);
//			RemoteOut.sendRemote(rmtDataByte);
			if (userDB==null){
				userDB = new UserDB(mContext);	
				}
			remoteSendUI();
			userDB.open();
			String	rmtData = userDB.getRemoteData(device,keyName);
			userDB.close();
			byte[] rmtDataByte = Tools.hexStringToBytes(rmtData);
		
			RemoteOut.sendRemote(rmtDataByte);	
			
			}
		
			
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	public  void airKeyTreate(AirData airData){
		try {
			
			RemoteCore.sendAirRemote(airData);	
			remoteSendUI();
		
			
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	

	
	private synchronized void remoteSendUI() {
		
		if (mHandler == null)
			return;
		mHandler.obtainMessage(R.id.MESSAGE_SEND, 1, -1)
				.sendToTarget();
	}

}
