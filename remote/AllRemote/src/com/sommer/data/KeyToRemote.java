package com.sommer.data;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;


import android.content.Context;
import android.util.Log;



import com.sommer.allremote.R;
import com.sommer.ircomm.RemoteCore;
import com.sommer.utils.RemoteDB;


public class KeyToRemote {
	private static RemoteDB mRmtDB = null;
	final static String  TAG = "KeyToRemote";	

	public static void keyTabSetValue(RemoteDevice rmtDev,Context mContext){
		
		  
		String[] codeDatas = new String[100];
		int keyColumn;
		if (mRmtDB==null){
			mRmtDB = new RemoteDB(mContext);	
			}
		mRmtDB.open();
		int dType=rmtDev.getType();
		String index = rmtDev.getCode();
		switch (dType){
		case Value.DeviceType.TYPE_TV:
			codeDatas=mRmtDB.getRemoteData(dType, index);
//			for (String code:codeDatas){
//				Log.v(TAG, "rmt code --->"+ code);	
//			}
			
			String[] tv_key = mContext.getResources().getStringArray(R.array.tv_key);
			for (String key:tv_key){
				keyColumn= mRmtDB.getKeyColumn(key);
//				Log.v(TAG, "tv_key--->" + key);
//				Log.v(TAG, "key column--->" + keyColumn);
//				Value.keyRemoteTab.put(key, codeDatas[keyColumn]);
			}
			break;
		case Value.DeviceType.TYPE_STB:
			codeDatas=mRmtDB.getRemoteData(dType,index);
			String[] stb_key = mContext.getResources().getStringArray(R.array.stb_key);
			for (String key:stb_key){
				keyColumn= mRmtDB.getKeyColumn(key);
//				Value.keyRemoteTab.put(key, codeDatas[keyColumn]);
			}
			break;	
		case Value.DeviceType.TYPE_DVD:
			codeDatas=mRmtDB.getRemoteData(dType,index);
			String[] dvd_key = mContext.getResources().getStringArray(R.array.dvd_key);
			for (String key:dvd_key){
				keyColumn= mRmtDB.getKeyColumn(key);
//				Value.keyRemoteTab.put(key, codeDatas[keyColumn]);
			}
			break;	
		case Value.DeviceType.TYPE_FAN:
			codeDatas=mRmtDB.getRemoteData(dType, index);
			String[] fan_key = mContext.getResources().getStringArray(R.array.fan_key);
			for (String key:fan_key){
				keyColumn= mRmtDB.getKeyColumn(key);
//				Value.keyRemoteTab.put(key, codeDatas[keyColumn]);
			}
			break;	
		case Value.DeviceType.TYPE_PJT:
			codeDatas=mRmtDB.getRemoteData(dType, index);
			String[] pjt_key = mContext.getResources().getStringArray(R.array.pjt_key);
			for (String key:pjt_key){
				keyColumn= mRmtDB.getKeyColumn(key);
//				Value.keyRemoteTab.put(key, codeDatas[keyColumn]);
			}
			break;	
		
		default:
			break;
		}
		
		mRmtDB.close();

	}
	
	
	
	
}
