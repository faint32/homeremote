package com.deco.data;

import java.util.ArrayList;
import java.util.HashMap;

import android.content.Context;
import android.os.Handler;

public final class Value {
	public static int HEADER = 0x99;
	public final static String[] RemoteType ={ 
		"TV","DVD","STB","FAN","PJT","AIR"
	};
	

	
	
	public  static String[] REMOTE_TYPE;
	public  static int selectStatus = 0;

	public static Boolean initial=true;
	public static Boolean audio= true;
	public static Boolean isStudying = false;
	public static String currentKey = null;
	public static int currentDevice = 0;
	public static Handler mHandler;
	public static Handler listHandler;
//	public static int cKey = 0;
	
	public static int screenWidth ;
	public static int screenHeight;
	public static Context mAppContext;
//	public static HashMap<String, String> keyRemoteTab ;
//	public static ArrayList<KeyValue> keyValueTab  ;
	
	
	
	public static AirData airData = new AirData();
	public static ArrayList<RemoteDevice> rmtDevs = new ArrayList<RemoteDevice>();
	public static RemoteDevice rmtDev = new RemoteDevice();

	
	public static class DeviceType {
		public final static int TYPE_TV = 0x00;
		public final static int TYPE_STB = 0x02;
		public final static int TYPE_DVD = 0x01;
		public final static int TYPE_FAN = 0x03;
		public final static int TYPE_AIR = 0x05;
		public final static int TYPE_PJT = 0x04;
	}


	
	
}
