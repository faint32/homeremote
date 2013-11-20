package com.deco.data;






import android.content.Context;





import com.database.IRDataBase;


import com.deco.utils.RemoteDB;
import com.deco.utils.UserDB;



public class RemoteGetKeyValue {
	private static RemoteDB mRmtDB = null;
	private static UserDB mUsrDB = null;
	final static String  TAG = "RemoteGetKeyValue";	

	

		
		public static void keyTabSetValue(RemoteDevice rmtDev,Context mContext){
		
		  
			String[] codeDatas = new String[100];
			int keyColumn;
			if (mRmtDB==null){
				mRmtDB = new RemoteDB(mContext);	
				}
			if (mUsrDB==null){
				mUsrDB = new UserDB(mContext);	
				}
			mRmtDB.open();
			mUsrDB.open();
			int type = rmtDev.getType();
			int id	=	rmtDev.getId();
			String index = rmtDev.getCode();
			switch (type){
			case Value.DeviceType.TYPE_TV:
				codeDatas=IRDataBase.getRemoteData(type,index);

				String[] tv_keys = mRmtDB.getKeyValueTAB(type);
				for (String key:tv_keys){
					keyColumn= mRmtDB.getKeyColumn(key);
					mUsrDB.deviceKeyTabInitial(id, key, codeDatas[keyColumn]);
				}
				break;
			case Value.DeviceType.TYPE_STB:
				codeDatas=IRDataBase.getRemoteData(type,index);
				String[] stb_key = mRmtDB.getKeyValueTAB(type);
				for (String key:stb_key){
					keyColumn= mRmtDB.getKeyColumn(key);
					mUsrDB.deviceKeyTabInitial(id, key, codeDatas[keyColumn]);
				}
				break;	
			case Value.DeviceType.TYPE_DVD:
				codeDatas=IRDataBase.getRemoteData(type,index);
				String[] dvd_key = mRmtDB.getKeyValueTAB(type);
				for (String key:dvd_key){
					keyColumn= mRmtDB.getKeyColumn(key);
					mUsrDB.deviceKeyTabInitial(id, key, codeDatas[keyColumn]);
				}
				break;	
			case Value.DeviceType.TYPE_FAN:
				codeDatas=IRDataBase.getRemoteData(type, index);
				String[] fan_key = mRmtDB.getKeyValueTAB(type);
				for (String key:fan_key){
					keyColumn= mRmtDB.getKeyColumn(key);
					
					mUsrDB.deviceKeyTabInitial(id,  key, codeDatas[keyColumn]);
				//	Log.v(TAG, "column data  ------>"+codeDatas[keyColumn]+ "column   ------>"+ +keyColumn);
				}
				break;	
			case Value.DeviceType.TYPE_PJT:
				codeDatas=IRDataBase.getRemoteData(type, index);
				String[] pjt_key = mRmtDB.getKeyValueTAB(type);
				for (String key:pjt_key){
					keyColumn= mRmtDB.getKeyColumn(key);
					mUsrDB.deviceKeyTabInitial(id, key, codeDatas[keyColumn]);
				}
				break;	
			
			default:
				break;
			}
			
			mRmtDB.close();
			mUsrDB.close();
		
		}


		public static void cleanTab(Context mContext) {
			// TODO Auto-generated method stub
			
			if (mUsrDB==null){
				mUsrDB = new UserDB(mContext);	
				}
			
			mUsrDB.open();	
			mUsrDB.cleanKeyTab();
			mUsrDB.close();
		}
	
	
	
	
}
