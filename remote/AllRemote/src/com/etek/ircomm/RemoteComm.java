package com.etek.ircomm;

import com.sommer.data.AirData;
import com.sommer.data.RemoteData;
import com.sommer.utils.Tools;

import android.util.Log;



public class RemoteComm {
	final static String	_ET4003_CONTROL_SEND_CODE_1_=	"53";
	final static int	_ET4003_CONTROL_SEND_CODE   =	0x53;
	final static String	_ET4003_CONTROL_SEND_CODE_2_=		"55";
	final static String TAG = "RemoteComm";
	private static final String libSoName = "ETEKIRCore";
	static {  
        System.loadLibrary(libSoName);  
    }  
	
	//static final byte[] demoData = {0x00,0x02,0x20,(byte) 0x80,0x00,0x3d,(byte) 0xbd,0x00,0x00,0x00,0x00,0x20,0x04,0x04,0x02,0x1a,0x00,0x71,0x00,(byte) 0x94,0x01,(byte) 0x93,0x00,0x00,0x00,0x00,0x58,(byte) 0xbf};

	public static void sendRemote(String remoteData){
		
		if (remoteData== null){
	
			return ;
		}
		
		byte[] sendData = Tools.hexStringToBytes(remoteData);
		int length = sendData.length;
		sendIRCode(sendData,length);
	}
public static void sendTestRemote(String testCode){
		
		if (testCode== null){
		//	Log.v(TAG, "send learn data null");
			return ;
		}
		
		byte[] sendData = Tools.hexStringToBytes(testCode);
		int length = sendData.length;
		
		Log.v(TAG, "send normal data =====>"+ sendData);
		sendIRCode(sendData,length);

	}

public static void sendAirRemote(AirData airdata){
	int i =0;
	if (airdata== null){
	//	Log.v(TAG, "send learn data null");
		return ;
	}
	byte[] sendData = new byte[129];
	int[] tempData = Tools.airDataToByte(airdata);

	byte[] toData = getAirData(tempData);


	int length = toData.length+1;
	Log.v(TAG, "air data  -->"+Tools.bytesToHexString(toData));
	sendData[0] = 	_ET4003_CONTROL_SEND_CODE;
	System.arraycopy(toData, 0, sendData, 1, toData.length);	

	sendIRCode(sendData,length);

}

public static String getLearnData (String data){
		String keyDataStr;
		keyDataStr = _ET4003_CONTROL_SEND_CODE_2_ +data;
		return keyDataStr;		
}



	public static boolean initRemote(){
	int ret=	IRinit ();
	if (ret == 1){
		return true;
	}else {
		return false;
	}
	}
	
	public static void finishRemote(){
		Finish ();
	}
	
	public static void remoteLearnStart(){
		learnIRCodeStart ();
	}
	
	public static void remoteLearnStop(){
		learnIRCodeStop ();
	}
	public static String readLearnData(){
		
		 byte[] learnData= readLearnIRCode();
		String lrnDtStr = Tools.bytesToHexString(learnData);
		Log.v(TAG, "learn data --->" + lrnDtStr);
		return lrnDtStr;
		
		}
	
	public static int learnRemoteLoop(int timeout){
		
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
	
	public static String encodeRemoteData(RemoteData rmtDt){
		if (rmtDt.getData()==""){
			return null;
		}
		String temp = rmtDt.getCustom()+rmtDt.getData();
		byte[] data1=Tools.hexStringToBytes(temp);
		String data2=rmtDt.getCodetype();
		byte[] encodeData=Encode ( data1,data2);
		temp = Tools.bytesToHexString(encodeData);
		temp = _ET4003_CONTROL_SEND_CODE_1_ + temp;
	//	Log.v(TAG, "encode data ->" + temp);
		return temp;
	}
	 
	 public native static void  sendIRCode (byte[] data, int length);  
	 public native static void  learnIRCodeStart();  
	 public native static void  learnIRCodeStop();  
	 public native static byte[]  readLearnIRCode();
	 public native static void  sendLearnCode (byte[] data);
	 public native static int  IRinit ();
	 public native static void  Finish ();
	 public native static void  setLearnTimeout (int time);
	 public native static int  learnIRCodeMain ();
	 public native static byte[]  Encode (byte[] data1,String data2);
	 public native static byte[]  getAirData (int[] data1);
	
}