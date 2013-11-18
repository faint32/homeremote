package com.deco.ircore;

import android.content.Context;
import android.os.Handler;
import android.util.Log;


import com.deco.allremote.R;
import com.deco.data.AirData;

import com.deco.data.RemoteData;
import com.deco.data.RemoteDevice;
import com.deco.data.Value;
import com.deco.utils.RemoteDB;
import com.deco.utils.Tools;
import com.deco.utils.UserDB;

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
		//	Log.v(TAG,"device=====>" + device +"      keyName=====>" + keyName);
			String rmtData = null;
			try {
				userDB.open();
				rmtData = userDB.getRemoteData(device,keyName);
				userDB.close();
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		//	Log.v(TAG, rmtData);
		//	byte[] rmtDataByte = Tools.hexStringToBytes(rmtData);
		
			RemoteCommunicate.sendDECORemote(rmtData);	
			
			}
		
			
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	public  void airKeyTreate(AirData airData){
		try {
			
			RemoteCommunicate.sendDECOAirRemote(airData);	
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
