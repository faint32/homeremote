package com.sommer.ircomm;

import android.util.Log;


import com.sommer.data.AirData;
import com.sommer.data.CodeType;
import com.sommer.data.KeyValue;
import com.sommer.data.RemoteData;
import com.sommer.utils.Tools;



public class RemoteCore {
	final static byte	ET4003_CONTROL_SEND_CODE_1_=		0x53;
	final static byte	_ET4003_CONTROL_SEND_CODE_2_=		0x55;
	final static String TAG = "RemoteComm";
	private static final String libSoName = "RemoteCore";
	static {  
        System.loadLibrary(libSoName);  
    }  
	
	//static final byte[] demoData = {0x00,0x02,0x20,(byte) 0x80,0x00,0x3d,(byte) 0xbd,0x00,0x00,0x00,0x00,0x20,0x04,0x04,0x02,0x1a,0x00,0x71,0x00,(byte) 0x94,0x01,(byte) 0x93,0x00,0x00,0x00,0x00,0x58,(byte) 0xbf};

	public static void sendRemote(KeyValue kv){
		
		if (kv.getData()== null){
		//	Log.v(TAG, "send learn data null");
			return ;
		}
		byte[] sendData = new byte[129];
		byte[] tempData = Tools.hexStringToBytes(kv.getData());
		int length = tempData.length+1;
		if (kv.getIsLearned()==1){
			sendData[0] = _ET4003_CONTROL_SEND_CODE_2_;
		//	Log.v(TAG, "send learn data =====>"+ sendData);
			System.arraycopy(tempData, 0, sendData, 1, tempData.length);	
		}
		else{
			sendData[0] = ET4003_CONTROL_SEND_CODE_1_;
		//	Log.v(TAG, "send normal data =====>"+ sendData);
			System.arraycopy(tempData, 0, sendData, 1, tempData.length);	
		}
	
	}
public static void sendTestRemote(String testCode){
		
		if (testCode== null){
		//	Log.v(TAG, "send learn data null");
			return ;
		}
		byte[] sendData = new byte[129];
		byte[] tempData = Tools.hexStringToBytes(testCode);
		int length = tempData.length+1;
		
			sendData[0] = ET4003_CONTROL_SEND_CODE_1_;
			System.arraycopy(tempData, 0, sendData, 1, tempData.length);	
			Log.v(TAG, "send normal data =====>"+ sendData);
		

	}

public static void sendAirRemote(AirData airdata){
	int i =0;
	if (airdata== null){
	//	Log.v(TAG, "send learn data null");
		return ;
	}
	byte[] sendData = new byte[128];
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

	int length = temp1Data.length+1;
	sendData[0] = ET4003_CONTROL_SEND_CODE_1_;
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
		if (data1==null){
			return null;
		}
		String data2=rmtDt.getCodetype();
		byte[] encodeData=Encode ( data1,data2);
		temp = Tools.bytesToHexString(encodeData);
	//	Log.v(TAG, "encode data ->" + temp);
		return temp;
	}
	 
	
	
	 public native static byte[]  Encode (byte[] data1,String data2);
	 public native static byte[]  getAirData (int[] data1);
	
}