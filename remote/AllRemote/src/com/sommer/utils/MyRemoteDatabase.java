package com.sommer.utils;


import com.sommer.data.AirData;
import com.sommer.data.Value;

import android.content.Context;
import android.content.SharedPreferences;

public class MyRemoteDatabase {
	final static String TVINDEX ="tvindex";
	final static String STBINDEX ="stbindex";
	final static String DVDINDEX ="dvdindex";
	final static String FANINDEX ="fanindex";
	final static String PJTINDEX ="pjtindex";
	final static String LIGHTINDEX ="lightindex";
	final static String AIRINDEX ="airindex";
	final static String INITIAL ="initial";
	
	final static String DB = "REMOTEINDEX";
	
	final static String AIRDATA = "AIRDATA";
	final static String TEMP = "airtemp";
	final static String POWER = "airpower";
	final static String MODE = "airmode";
	final static String WINDC = "airwindcount";
	final static String WINDD = "airwinddirect";
	final static String WINDA = "airauto";
	final static String CODETYPE = "airtype";
	
	public static  void saveRemoteIndex(Context _mContext){
		SharedPreferences  sharedPreferences = _mContext.getSharedPreferences(DB,0);  
		SharedPreferences.Editor mEditor = sharedPreferences.edit();  
        mEditor.putString(TVINDEX,Value.tv_index); 
        mEditor.putString(STBINDEX,Value.stb_index); 
        mEditor.putString(DVDINDEX,Value.dvd_index); 
        mEditor.putString(FANINDEX,Value.fan_index); 
        mEditor.putString(PJTINDEX,Value.pjt_index); 
        mEditor.putString(LIGHTINDEX,Value.light_index); 
        mEditor.putString(AIRINDEX,Value.air_index); 
        mEditor.putBoolean(INITIAL,Value.initial); 
        
        mEditor.commit();  
	}
	public static  void saveAirData(Context _mContext,AirData ad){
		SharedPreferences  sharedPreferences = _mContext.getSharedPreferences(AIRDATA,0);  
		SharedPreferences.Editor mEditor = sharedPreferences.edit();  
        mEditor.putInt(TEMP,ad.getmTmp()); 
        mEditor.putInt(POWER,ad.getmPower()); 
        mEditor.putInt(MODE,ad.getmMode()); 
        mEditor.putInt(WINDC,ad.getmWindCount()); 
        mEditor.putInt(WINDD,ad.getmWindDir()); 
        mEditor.putInt(WINDA,ad.getmWindAuto()); 
        mEditor.putInt(CODETYPE,ad.getCodeType()); 
        mEditor.commit();  
	}
	
	public static void getRemoteIndex(Context _mContext){
		SharedPreferences  sharedPreferences = _mContext.getSharedPreferences(DB,0);  
		Value.tv_index  = sharedPreferences.getString(TVINDEX, "0000");
		Value.stb_index  = sharedPreferences.getString(STBINDEX, "2173");
		Value.dvd_index  = sharedPreferences.getString(DVDINDEX, "1001");
		Value.fan_index  = sharedPreferences.getString(FANINDEX, "3001");
		Value.pjt_index  = sharedPreferences.getString(PJTINDEX, "4000");
		Value.light_index  = sharedPreferences.getString(LIGHTINDEX, "6000");
		Value.air_index  = sharedPreferences.getString(AIRINDEX, "5000");
		Value.initial =sharedPreferences.getBoolean(INITIAL, false);

	}
	public static AirData getAirData(Context _mContext){
		AirData ad = new AirData();
		SharedPreferences  sharedPreferences = _mContext.getSharedPreferences(AIRDATA,0);  
		ad.setmTmp(sharedPreferences.getInt(TEMP, 25));
		ad.setmPower(sharedPreferences.getInt(POWER, 1));
		ad.setmMode(sharedPreferences.getInt(MODE, 1));
		ad.setmWindCount(sharedPreferences.getInt(WINDC, 1));
		ad.setmWindDir(sharedPreferences.getInt(WINDD, 1));
		ad.setmWindAuto(sharedPreferences.getInt(WINDA, 1));
		ad.setCodeType(sharedPreferences.getInt(CODETYPE, 5000));
		
		
		return ad;
	}
	  
}
