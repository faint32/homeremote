package com.deco.utils;


import com.deco.data.AirData;
import com.deco.data.Value;

import android.content.Context;
import android.content.SharedPreferences;

public class MyAppInfo {
//	final static String TVINDEX ="tvindex";
//	final static String STBINDEX ="stbindex";
//	final static String DVDINDEX ="dvdindex";
//	final static String FANINDEX ="fanindex";
//	final static String PJTINDEX ="pjtindex";
//	final static String LIGHTINDEX ="lightindex";
//	final static String AIRINDEX ="airindex";
	final static String INITIAL ="initial";
	final static String AUDIO ="audio";
	final static String DB = "REMOTEINDEX";
	
//	final static String AIRDATA = "AIRDATA";
//	final static String TEMP = "airtemp";
//	final static String POWER = "airpower";
//	final static String MODE = "airmode";
//	final static String WINDC = "airwindcount";
//	final static String WINDD = "airwinddirect";
//	final static String WINDA = "airauto";
//	final static String CODETYPE = "airtype";
	
	public static  void saveInfo(Context _mContext){
		SharedPreferences  sharedPreferences = _mContext.getSharedPreferences(DB,0);  
		SharedPreferences.Editor mEditor = sharedPreferences.edit();  
    
        mEditor.putBoolean(INITIAL,Value.initial); 
        mEditor.putBoolean(AUDIO,Value.audio); 
        mEditor.commit();  
	}

	
	public static void getInfo(Context mContext){
		SharedPreferences  sharedPreferences = mContext.getSharedPreferences(DB,0);  
		
		Value.initial =sharedPreferences.getBoolean(INITIAL, true);
		Value.audio =sharedPreferences.getBoolean(AUDIO, false);

	}

	  
}
