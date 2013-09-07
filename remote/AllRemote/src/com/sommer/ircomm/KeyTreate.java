package com.sommer.ircomm;

import android.content.Context;
import android.os.Handler;
import android.util.Log;

import com.sommer.allremote.R;
import com.sommer.data.AirData;
import com.sommer.data.KeyValue;
import com.sommer.data.RemoteData;
import com.sommer.data.Value;

public class KeyTreate {
	private final static String TAG ="KeyTreate";
	private Handler mHandler;
	private Context mContext;
	private static int index=0;
	private static KeyTreate mKeyTreate = null;
	private static String[] testcode  ={      
		"T48BAU",
	      "T42BBB",
	      "T42AAF",
	      "T32DCA",
	      "T32DBZ",
	      "T32DBU",
	      "T32CAM",
	      "T22ABN",
	      "T16GAA",
	      "T16DAI",
	      "T16BAT",
	      "T16AAR",
	      "T15AAE",
	      "T11CAE",
	      "T11AAQ",
	      "T10ACQ",
	      "T06AAB",
	      "P14ABG",
	      "P14ABD",
	      "VADE08",
	      "T48AAA",
	      "T32DCP",
	      "T32DCO",
	      "T32BAR",
	      "T32ABO",
	      "T32ABD",
	      "T32AAI",
	      "T24CAG",
	      "T24ACL",
	      "T24ACK",
	      "T24ACC",
	      "T24ABE",
	      "T24AAG",
	      "T22ABH",
	      "T16AAU",
	      "T16AAT",
	      "T16AAS",
	      "T16AAP",
	      "T15AIB",
	      "T14BAF",
	      "T12BAE",
	      "T12ACF",
	      "T11BBH",
	      "T10ECC",
	      "T10BBE",
	      "T10AGN",
	      "T10AGM",
	      "T10AEE",
	      "T10AED",
	      "T10ACT",
	      "T10ACS",
	      "T10ACR",
	      "T10ACH",
	      "T06AAP",
	      "T06AAO",
	      "P21BAC",
	      "N11BFO",
	      "N11BAC",
	      "N11AAD",
	      "N05AAI",
	      "T48BAV",
	      "T40DAA",
	      "T12AAB",
	      "P36AAE",
	      "E00ABG",
	      "N05AAA",
	      "E13AAA",
	      "E12CGD",
	      "E12CGC",
	      "E00ACI",
	      "E00ACH",
	      "E00ACG"
	};
	
	
	public void setHandler(Handler _handler) {
		mHandler = _handler;
	}
	
	
	
	public static KeyTreate getInstance() {
		if (mKeyTreate == null) {
			mKeyTreate = new KeyTreate();
		}
		return mKeyTreate;
	}
	public void setContext(Context _context) {
		mContext = _context;
	}
	public  void keyTreate(){
		KeyValue kv;
		try {
			kv = new KeyValue();
			
			if (Value.isStudying){
			kv.setKeyName(Value.currentKey);
			kv.setIsLearned(1);
			kv.setData(RemoteCore.readLearnData());	
			
			mHandler.obtainMessage(R.id.MSG_LEARN_END, 1, -1)
			.sendToTarget();
		//	RemoteComm.sendRemote(kv);	
			Value.keyValueTab.put(Value.currentKey, kv);
			
			}
			else{
			kv= Value.keyValueTab.get(Value.currentKey);
//			RemoteData rd = new RemoteData();
//			if (Value.currentKey=="tv_chadd"){
//				index++;
//				if (index>70){
//					index=0;
//				}
//			}
//			if (Value.currentKey=="tv_chsub"){
//				index--;
//				if (index<0){
//					index=70;
//				}
//			}
//			String test = testcode[index];
//			Log.v(TAG, "key name "+ Value.currentKey);
//			Log.v(TAG, "test code "+ test+ "   index ==>"+ index);
//			rd.setCodetype(test);
//			rd.setCustom("12345678");
//			rd.setData("90abcdef");
//			kv.setData(RemoteComm.encodeRemoteData(rd));
//			kv.setIsLearned(0);
			RemoteCore.sendRemote(kv);	
			remoteSendUI();
			}
			//		RemoteComm.sendRemote(rmtData,codeType);
		//	RemoteComm.sendRemote();
			
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	public  void airKeyTreate(AirData airData){
		try {
			
			RemoteCore.sendAirRemote(airData);	
			remoteSendUI();
		
			
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	

	
	private synchronized void remoteSendUI() {
		
		if (mHandler == null)
			return;
		mHandler.obtainMessage(R.id.MESSAGE_SEND, 1, -1)
				.sendToTarget();
	}

}
