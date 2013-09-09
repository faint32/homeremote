package com.sommer.ircomm;

import android.content.Context;
import android.os.Handler;
import android.util.Log;

import com.sommer.allremote.R;
import com.sommer.data.AirData;
import com.sommer.data.KeyValue;
import com.sommer.data.RemoteData;
import com.sommer.data.Value;
import com.sommer.utils.Tools;

public class KeyTreate {
	private final static String TAG ="KeyTreate";
	private Handler mHandler;
	private Context mContext;
	private static int index=0;
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
	public  void keyTreate(){
		
		try {
		
			
			if (Value.isStudying){
			
			mHandler.obtainMessage(R.id.MSG_LEARN_END, 1, -1)
			.sendToTarget();

			}
			else{
			//	Log.v(TAG, "keytable----->"+ Value.keyRemoteTab.toString() );
			String rmtData = Value.keyRemoteTab.get(Value.currentKey);
			Log.v(TAG, "rmtdata--->"+ rmtData);
			byte[] rmtDataByte = Tools.hexStringToBytes(rmtData);
			RemoteOut.sendRemote(rmtDataByte);
			remoteSendUI();
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
