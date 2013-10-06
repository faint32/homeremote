package com.sommer.data;




import android.content.Context;
import android.util.Log;




import com.sommer.allremote.R;

import com.sommer.utils.RemoteDB;
import com.sommer.utils.UserDB;


public class RemoteGetKeyValue {
	private static RemoteDB mRmtDB = null;
	private static UserDB mUsrDB = null;
	final static String  TAG = "RemoteGetKeyValue";	

	public static void remoteUpdateOrAddKeyValue(RemoteDevice rmtDev,Context mContext,boolean isUpdate){
		
		  
		String[] codeDatas = new String[100];
		int keyColumn;
		int id = rmtDev.getId();
		if (mRmtDB==null){
			mRmtDB = new RemoteDB(mContext);	
			}
		mRmtDB.open();
		if (mUsrDB==null){
			mUsrDB = new UserDB(mContext);	
			}
		mUsrDB.open();
		int dType=rmtDev.getType();
		if (dType!=Value.DeviceType.TYPE_AIR){
		String index = rmtDev.getCode();
		codeDatas=mRmtDB.getRemoteData(dType,index);
		}
		if(isUpdate){
		mUsrDB.updateRemoteDevice(id);
		} else {
		mUsrDB.addRemoteDevice(id);	
		}
		switch (dType){
		case Value.DeviceType.TYPE_TV:
				
			String[] tv_key = mContext.getResources().getStringArray(R.array.tv_key);
			for (String key:tv_key){
				keyColumn= mRmtDB.getKeyColumn(key);
				Log.v(TAG, "add key ---->"+ key + "key value --->" +codeDatas[keyColumn]);
				mUsrDB.addKeyValue(key, codeDatas[keyColumn],id,keyColumn);

			}
			break;
		case Value.DeviceType.TYPE_STB:
			
			String[] stb_key = mContext.getResources().getStringArray(R.array.stb_key);
			for (String key:stb_key){
				keyColumn= mRmtDB.getKeyColumn(key);
				mUsrDB.addKeyValue(key, codeDatas[keyColumn],id,keyColumn);
//				Value.keyRemoteTab.put(key, codeDatas[keyColumn]);
			}
			break;	
		case Value.DeviceType.TYPE_DVD:
			
			String[] dvd_key = mContext.getResources().getStringArray(R.array.dvd_key);
			for (String key:dvd_key){
				keyColumn= mRmtDB.getKeyColumn(key);
				mUsrDB.addKeyValue(key, codeDatas[keyColumn],id,keyColumn);
//				Value.keyRemoteTab.put(key, codeDatas[keyColumn]);
			}
			break;	
		case Value.DeviceType.TYPE_FAN:
		
			String[] fan_key = mContext.getResources().getStringArray(R.array.fan_key);
			for (String key:fan_key){
				keyColumn= mRmtDB.getKeyColumn(key);
				mUsrDB.addKeyValue(key, codeDatas[keyColumn],id,keyColumn);
//				Value.keyRemoteTab.put(key, codeDatas[keyColumn]);
			}
			break;	
		case Value.DeviceType.TYPE_PJT:
		
			String[] pjt_key = mContext.getResources().getStringArray(R.array.pjt_key);
			for (String key:pjt_key){
				keyColumn= mRmtDB.getKeyColumn(key);
				mUsrDB.addKeyValue(key, codeDatas[keyColumn],id,keyColumn);
//				Value.keyRemoteTab.put(key, codeDatas[keyColumn]);
			}
			break;	
		case Value.DeviceType.TYPE_AIR:
			
			
			break;	
		
		default:
			break;
		}
		
		mRmtDB.close();
		mUsrDB.close();
	}
	
	
	
	
}
