package com.database;



import com.deco.data.RemoteData;
import com.deco.data.Value;
import com.deco.ircore.RemoteCommunicate;

import android.util.Log;





public class IRDataBase  {
	final static String TAG = "IRDataBase";
	private static final String libSoName = "IRDataBase";

	static {  
        System.loadLibrary(libSoName);  
    }  
	
		
	public static String[] getETEKIRDataBase (int type,int index){
		return getDataBase(type,index);
	}
	 
	

	public static RemoteData getSampleKeyData(int _type,String _index,int keyColumn){
		RemoteData rmtData = new RemoteData();
		

		Log.v(TAG, "type ---->" + _type);
		Log.v(TAG, "index ---->"+ _index);
		String[] rmtdatas = getDataBase(_type, Integer.valueOf(_index));
		rmtData.setIndex(rmtdatas[1]);
		rmtData.setCodetype(rmtdatas[2]) ; 
		rmtData.setMode(Value.RemoteType[_type]);
		rmtData.setCustom(rmtdatas[3]) ;
		rmtData.setData(rmtdatas[keyColumn]) ;
		return rmtData;
		
	}
	

	
	public static String[] getRemoteData(int _type,String _index){
		
		
//				Cursor c = myDataBase.query(Value.CodeProTab[_type], null,  " code_index =?" ,new String[]{_index}, null, null, null);
//				//	Cursor c = myDataBase.rawQuery("SELECT * FROM " + TV_CODE_TAB + " WHERE custom=20020080"   ,null);
//				   if (c==null){
//					   return null;
//				   }
//					c.moveToFirst();
//			//		Log.v(TAG, "columnCoutn data " + c.getColumnCount());
//					for (int i=4;i<c.getColumnCount();i++){
//					RemoteData rmtData = new RemoteData();
//					rmtData.setIndex(c.getString(1));
//					rmtData.setCodetype(c.getString(2)) ; 
//					rmtData.setMode(Value.RemoteType[_type]);
//					rmtData.setCustom(c.getString(3)) ;
//					rmtData.setData(c.getString(i)) ;
//				//	Log.v(TAG, "remote data " + rmtData.getRemoteData());
//				
//					rmtDts[i-4] = RemoteComm.encodeRemoteData(rmtData);
//					}
//		c.close();	
		String[] rmtDts = new String[100];
		String[] rmtdatas = IRDataBase.getDataBase(_type, Integer.valueOf(_index));
		for (int i=4;i<rmtdatas.length;i++){
			RemoteData rmtData = new RemoteData();
			rmtData.setIndex(rmtdatas[1]);
			rmtData.setCodetype(rmtdatas[2]) ; 
			rmtData.setMode(Value.RemoteType[_type]);
			rmtData.setCustom(rmtdatas[3]) ;
			rmtData.setData(rmtdatas[i]) ;
		//	Log.v(TAG, "remote data " + rmtData.getRemoteData());
		
			rmtDts[i-4] = RemoteCommunicate.encodeDECORemoteData(rmtData);
			}
		return rmtDts;
		
	}
	
	 public native static String[]  getDataBase(int type,int index);
	

}
