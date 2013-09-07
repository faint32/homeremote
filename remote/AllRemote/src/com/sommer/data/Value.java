package com.sommer.data;

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
	public static final String USERTAB = "user_tab";
	public static final String USER_ID = "_id";
	public static final String USER_NAME = "name";
	public static final String USER_CODE = "code_type";
	public static final String USER_FORM = "form";
	public static final String USER_LEARN = "is_learned";
	public static final String USER_DATA = "data";
	public static final String USER_DEVICE = "device_type";
	public static final String USER_COLUMN = "key_column";
	
	
	
	public static String tv_index;
	public static String dvd_index ;
	public static String stb_index;
	public static String fan_index ;
	public static String pjt_index ;
	public static String air_index ;
	public static String light_index ;
	public static Boolean initial;
	public static Boolean isStudying = false;
	public static String currentKey = null;
	
	public static final String[] tv_keys = {
		"tv_power",
		"tv_menu", //Menu
		"tv_ok", //OK
		"tv_av", //AV/TV
		"tv_voladd", //Vol+
		"tv_volsub", //Vol-
		"tv_mute", //Mute
		"tv_back", //Return
		"tv_chadd", //CH+
		"tv_chsub", //CH-
		"tv_key1", //1
		"tv_key2", //2
		"tv_key3", //3
		"tv_key4", //4
		"tv_key5", //5
		"tv_key6", //6
		"tv_key7", //7
		"tv_key8", //8
		"tv_key9", //9
		"tv_key0", //0
		"tv_key10", //<![CDATA[-/]], //
	};
	public static final String[] stb_key = {
		"stb_wait", //Standby
		"stb_watch", //Guides
		"stb_back", //Return
		"stb_key0", //0
		"stb_key1", //1
		"stb_key2", //2
		"stb_key3", //3
		"stb_key4", //4
		"stb_key5", //5
		"stb_key6", //6
		"stb_key7", //7
		"stb_key8", //8
		"stb_key9", //9
		"stb_chadd", //CH+
		"stb_chsub", //CH-
		"stb_voladd", //Vol+
		"stb_volsub", //Vol-
		"stb_up", //Up
		"stb_down", //Down
		"stb_left", //Left
		"stb_right", //Right
		"stb_ok", //OK
		"stb_menu" //Menu
	};
	
	public static final String[] dvd_key = {
		"dvd_power", //ON/OF
		"dvd_mute", //Mute
		"dvd_quickforward", //, //, //
		"dvd_quickback", //<![CDATA[<<]], //
		"dvd_play", //Play
		"dvd_stop", //Stop
		"dvd_upsong", //<![CDATA[|<<]], //
		"dvd_downsong", //, //, //|
		"dvd_pause", //Pause
		"dvd_av", //Format
		"dvd_title", //Title
		"dvd_open", //Pass in and out
		"dvd_menu", //Menu
		"dvd_back", //Return
		"dvd_up", //Up
		"dvd_down", //Down
		"dvd_left", //Left
		"dvd_right", //Right
		"dvd_ok" //OK

	};
	public static final String[] fan_key = {
		"fan_power", //ON/OFF
		"fan_mode", // Mode
		"fan_li", //Anion
		"fan_speed", //Air Volume
		"fan_key0", //ON/Wind
		"fan_speedlow", //Low Speed
		"fan_speedmiddle", //Medium Speed
		"fan_speedhight", //High Speed
		"fan_sleep", //Sleep
		"fan_freq", //Shake
		"fan_cool", //Cold
		"fan_timer", //Timing
		"fan_light", //Light
		"fan_key1", //1
		"fan_key2", //2
		"fan_key3", //3
		"fan_key4", //4
		"fan_key5", //5
		"fan_key6", //6
		"fan_key7", //7
		"fan_key8", //8
		"fan_key9" //9

	};
	public static final String[] light_key = {
		"light_power_all_on", //All On
		"light_power_all_off", //All Off
		"light_power_on", //On
		"light_power_off", //OFF
		"light_light", //Brightness+
		"light_dark", //Brightness-
		"light_lost", //Burglar
		"light_keyA", //A
		"light_keyB", //B
		"light_keyC", //C
		"light_keyD", //D
		"light_setting", //SET
		"light_study", //Learn
		"light_key1", //1
		"light_key2", //2
		"light_key3", //3
		"light_key4", //4
		"light_key5", //5
		"light_key6", //6
		"light_timer1", //Timing1
		"light_timer2", //Timing2
		"light_timer3", //Timing3
		"light_timer4" //Timing4

	};
	public static final String[] pjt_key = {
		"pjt_power_on", //ON
		"pjt_power_off", //OFF
		"pjt_computer", //PC
		"pjt_video", //VIDEO
		"pjt_sign", //Source
		"pjt_zoomadd", //Zoom +
		"pjt_zoomsub", //Zoom -
		"pjt_pictureadd", //Screens+
		"pjt_picturesub", //Screens-
		"pjt_brightness", //Brightness
		"pjt_auto", //Auto
		"pjt_exit", //Quit
		"pjt_menu", //Menu
		"pjt_pause", //Pause
		"pjt_mute", //Mute
		"pjt_voladd", //VOL+
		"pjt_volsub", //VOL-
		"pjt_up", //UP
		"pjt_down", //DOWN
		"pjt_left", //LEFT
		"pjt_right", //RIGHT
		"pjt_ok", //OK

	};
	
		
	
	public static final String[] air_key = {
		"air_power", //ON/OF
		"air_tempadd", //Up
		"air_tempsub", //Down
		"air_mode", //Mode
		"air_wind_count", //Air volume
		"air_wind_dir", //Manually Wind
		"air_wind_auto_dir", //Auto Wind

	};
	public static HashMap<String, KeyValue> keyValueTab ;

	
	public static class DeviceType {
		public final static int TYPE_TV = 0x00;
		public final static int TYPE_STB = 0x02;
		public final static int TYPE_DVD = 0x01;
		public final static int TYPE_FAN = 0x03;
		public final static int TYPE_AIR = 0x05;
		public final static int TYPE_LIGHT = 0x06;
		public final static int TYPE_PJT = 0x04;
	}


	
	
}
