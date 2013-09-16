package com.sommer.ircore;

import android.util.Log;


import com.sommer.data.AirData;


import com.sommer.data.RemoteData;
import com.sommer.utils.Tools;



public class RemoteCore {
	final static byte	_REMOTE_HEAD__=				0x5A;
	final static byte	_REMOTE_SEND_NORMAL_=		0x51;
	final static byte	_REMOTE_SEND_LEARN__=		0x53;
	final static byte	_REMOTE_LEARN_START_=		0x55;
	final static byte	_REMOTE_LEARN_STOP_=		0x57;
	final static byte	_REMOTE_LEARN_READ_=		0x59;
	
	final static String TAG = "RemoteCore";
	private static final String libSoName = "RemoteCore";
	static {  
        System.loadLibrary(libSoName);  
    }  
	
	

	public static void sendRemote(String  rmtData){
		
		if (rmtData== null){
		//	Log.v(TAG, "send learn data null");
			return ;
		}
		
		
		
	
	}
public static void sendTestRemote(String testCode){
		
		if (testCode== null){
		//	Log.v(TAG, "send learn data null");
			return ;
		}
		byte[] sendData = new byte[129];
		byte[] tempData = Tools.hexStringToBytes(testCode);
			sendData[0] = _REMOTE_SEND_NORMAL_;
			System.arraycopy(tempData, 0, sendData, 1, tempData.length);	
			Log.v(TAG, "send normal data =====>"+ sendData);
		

	}

public static void sendAirRemote(AirData airdata){
	int i =0;
	if (airdata== null){
	//	Log.v(TAG, "send learn data null");
		return ;
	}
	byte[] sendData = new byte[129];
	int[] tempData = Tools.airDataToByte(airdata);
//	for (byte t: tempData){
//		Log.v(TAG, "get byte i("+ i + ")data =========>"+ t);
//		i++;
//	}

	byte[] temp1Data = getAirData(tempData);
//	i=0;
//	for (byte t: temp1Data){
//		Log.v(TAG, "get byte i("+ i + ")data =========>"+ t);
//		i++;
//	}

	
	sendData[0] = _REMOTE_SEND_NORMAL_;
	System.arraycopy(temp1Data, 0, sendData, 1, temp1Data.length);	
	Log.v(TAG, "send normal data =====>"+ sendData);
	
}


	public static void initRemote(){
		
	}
	
	public static void finishRemote(){
		
	}
	
	public static void remoteLearnStart(){
		
	}
	
	public static void remoteLearnStop(){
		
	}
	public static String readLearnData(){
		
	
		return null;
		
		}
	
	public static int learnRemoteLoop(int timeout){
		
		return 0;
	}
	
	public static String encodeRemoteData(RemoteData rmtDt){
		String temp = rmtDt.getCustom()+rmtDt.getData();
		byte[] data1=Tools.hexStringToBytes(temp);
		if (rmtDt.getData()==null){
			return null;
		}
		int length;
		String data2=rmtDt.getCodetype();
		byte[] encodeData=Encode ( data1,data2);
		length = encodeData.length;
		byte[] toData = new byte[encodeData.length+3];
		
		toData[0] = _REMOTE_SEND_NORMAL_;
		toData[1] = (byte) (length);
		System.arraycopy(encodeData, 0, toData, 2, length);
		String toDataStr = Tools.bytesToHexString(toData);
		Log.v(TAG, "encode data ->" + toDataStr);
		return toDataStr;
	}
	
	
//	public static String updateRemoteData(String rmtDt){
//		
//		
//		byte[] encodeData=Tools.hexStringToBytes(rmtDt) ;
//		int length = encodeData.length;
//		byte[] toData = new byte[encodeData.length+4];
//		
//		toData[0] = _REMOTE_HEAD__;
//		toData[1] = _REMOTE_SEND_NORMAL_;
//		toData[2] = (byte) (length);
//		System.arraycopy(encodeData, 0, toData, 3, length);
//		String toDataStr = Tools.bytesToHexString(toData);
//	//	Log.v(TAG, "encode data ->" + toDataStr);
//		return toDataStr;
//	}
	 
	
	
	 public native static byte[]  Encode (byte[] data1,String data2);
	 public native static byte[]  getAirData (int[] data1);
	
}