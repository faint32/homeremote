package com.sommer.data;

import java.util.ArrayList;
import java.util.HashMap;

public final class Value {
	public static int HEADER = 0x99;
	public final static String[] RemoteType ={ 
		"TV","DVD","STB","FAN","PJT","AIR","LIGHT"
	};
	
	public static int screenWidth;
	public static int  screenHeight ;
	public final static String[] CodeProTab ={ 
		"code_tv","code_dvd","code_stb","code_fan","code_pjt","code_air","code_light"
	};

	
	
	
	public static String tv_index;
	public static String dvd_index ;
	public static String stb_index;
	public static String fan_index ;
	public static String pjt_index ;
	public static String air_index ;
	public static Boolean initial;
	public static Boolean isStudying = false;
	public static String currentKey = null;
	public static int cKey = 0;
	

	public static int[] deviceType;
	public static String[] deviceIndex;
	public static HashMap<String, String> keyRemoteTab ;
	public static ArrayList<KeyValue> keyValueTab  ;
	
	public static class DeviceType {
		public final static int TYPE_TV = 0x00;
		public final static int TYPE_STB = 0x02;
		public final static int TYPE_DVD = 0x01;
		public final static int TYPE_FAN = 0x03;
		public final static int TYPE_AIR = 0x05;
		public final static int TYPE_PJT = 0x04;
	}


	
	
}
