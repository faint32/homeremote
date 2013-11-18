package com.deco.ircore;

import android.util.Log;


import com.deco.data.AirData;
import com.deco.data.RemoteData;
import com.deco.data.Value;
import com.deco.utils.Tools;


public class RemoteCommunicate {
	final static String TAG = "RemoteComm";
	Boolean trig=false;
	private static final String libSoName = "IRCore";
	static {  
        System.loadLibrary(libSoName);  
    }  
	
	public static void sendDECORemote(String remoteData){
	
		if (remoteData== null){
			return ;
		}
		
		byte[] sendData = Tools.hexStringToBytes(remoteData);
		
		if (sendData[0]==0x51&&sendData[1]<128){
		sendIRCode(sendData);
		} 
	}

public static void sendDECOAirRemote(AirData airdata){
	
	if (airdata== null){
	//	Log.v(TAG, "send learn data null");
		return ;
	}

	int[] tempData = Tools.airDataToArray(airdata);
	byte[] sendData = getAirData(tempData);
	//saveSendData(sendData);
    Log.v(TAG, "airdata ----> " + Tools.bytesToHexString(sendData));

	sendIRCode(sendData);

}

//public static String getLearnData (String data){
//		String keyDataStr="51"+data;
//		
//		return keyDataStr;		
//}
//


public static boolean initDECORemote(){
	int ret=	IRinit ();
	if (ret == 1){
		return true;
	}else {
		return false;
	}
	}
	
	public static void finishDECORemote(){
		Finish ();
	}
	
	public static void remoteDECOLearnStart(){
		learnIRCodeStart ();
	}
	
	
	public static void remoteDECOLearnStop(){
		learnIRCodeStop ();
	}
	public static String readDECOLearnData(){
		 
		 byte[] learnData= readLearnIRCode(64);
		int length = Tools.getValidLearnData(learnData);
		//Log.v(TAG, "learn length --->" + length);
		String lenStr = Integer.toHexString(length); 
		String lrnDtStr = Tools.bytesToHexString(learnData,length);
		lrnDtStr ="51" +lenStr +lrnDtStr +"00";
	//	Log.v(TAG, "learn data --->" + lrnDtStr);
		return lrnDtStr;
		
		}
	
	public static int learnDECORemoteLoop(int timeout){
		
		learnIRCodeStart();  
//		String lrnDtStr;
		setLearnTimeout(timeout);
		
		while(true){
		int status= learnIRCodeMain();
		if (status==-1){
			Log.v(TAG, "learn remote  device error " );	
//			lrnDtStr="device error";
//			remoteLearnStop();
			return status;
			}
		else if (status==0){
			Log.v(TAG, "learn remote  device timeout " );
//			lrnDtStr="time out";
//			remoteLearnStop();
			return status;
			}
		else {
//			byte[] learnData= readLearnIRCode();
//			 lrnDtStr = Tools.bytesToHexString(learnData);
//			 Log.v(TAG, "learn remote data  --->" + lrnDtStr);
			 return status;
			}
		}
	}
	
	public static String encodeDECORemoteData(RemoteData rmtDt){
		if (rmtDt.getData()==null){
			return null;
		}
	
		String temp = rmtDt.getCustom()+rmtDt.getData();
		 Log.v(TAG, "getData ---->"+ temp);
		byte[] data=Tools.hexStringToBytes(temp);
		byte[] encodeData=remoteEncode (data,rmtDt.getCodetype());
//		for(byte t:encodeData){
//			saveStr = "0x" +Tools.bytesToHex(t) + "   \n";
//		}
	//	Tools.saveDocumnet(saveStr, "remoteValue");
		String toDataStr = Tools.bytesToHexString(encodeData);
		return toDataStr;
	}
	
	static void saveSendData(byte sendData[]){
		String texts = "";
		int i =0;
		for (byte data:sendData){
			texts += "data["+i+"]  ====> 0x"+ Tools.bytesToHex(data)+"    \n";
			i++;
		//	Log.v(TAG, texts);
		}
		
		
		Tools.saveDocumnet(Value.mAppContext, texts, "text.txt");
	}
	 
	 public native static void  sendIRCode (byte[] data);  
	 public native static void  learnIRCodeStart();  
	 public native static void  learnIRCodeStop();  
	 public native static byte[]  readLearnIRCode(int length);
	 public native static void  sendLearnCode (byte[] data);
	 public native static int  IRinit ();
	 public native static void  Finish ();
	 public native static void  setLearnTimeout (int time);
	 public native static int  learnIRCodeMain ();
	 public native static byte[]  getAirData (int[] data1);
	 public native static byte[]  remoteEncode (byte[] data,String type);
	 
	
}