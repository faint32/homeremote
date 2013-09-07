package com.sommer.data;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;


import android.content.Context;
import android.util.Log;


import com.sommer.ircomm.RemoteCore;
import com.sommer.utils.RemoteDB;


public class KeyToRemote {
	private static RemoteDB mRmtDB = null;
	final static String  TAG = "KeyToRemote";	
/*
	public static void keyTabSetValue(Context mContext,int deviceType){
		ArrayList<RemoteData> tempRemotes = new ArrayList<RemoteData>();
		String[] tempCodeDatas = new String[30];
	
		
		if (mRmtDB==null){
			mRmtDB = new RemoteDB(mContext);	
			}
		mRmtDB.open();
		 tempRemotes=mRmtDB.getRemoteKeyData(Value.DeviceType.TYPE_TV, Value.tv_index);
		 for (int i=0;i<tempRemotes.size();i++){
				
				try {
				//	tempCodeDatas[i]=keyToRemoteData(tempRemotes.get(i));
					tempCodeDatas[i] =	RemoteCore.encodeRemoteData(tempRemotes.get(i));
				} catch (Exception e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				Log.v(TAG, "datavalue byte count " + i +"--->" + tempCodeDatas[i]);
			}
		 Set<?> set=Value.keyValueTab.entrySet();
	        Iterator<?> it=set.iterator();
		Log.v(TAG, "keyTabSetValue start");
			switch (deviceType){
			case Value.DeviceType.TYPE_TV:
				       while(it.hasNext()){
			            @SuppressWarnings("unchecked")
						Map.Entry<String, KeyValue> me=(Map.Entry<String, KeyValue>)it.next();
			            Log.v(TAG, "keyvaluetab index ----->   "  +me.getKey() );	
			            Log.v(TAG, "keyvaluetab hashcode ----->   "  +me.hashCode() );	
			            KeyValue kv = me.getValue();
			            if(kv.getDeviceType()==Value.DeviceType.TYPE_TV){
			            	String temp = tempCodeDatas[kv.getKeyColumn()];
			            	  kv.setData(temp);
			            	  kv.setIsLearned(0);
			            	  me.setValue(kv);
			            	  Log.v(TAG, "keyvaluetab kv ----->   "  +kv.getKeyValue() );	
			            }
			        }

				break;
			case Value.DeviceType.TYPE_DVD:
				mRmtDB.open();
				 try {
					tempRemotes=mRmtDB.getRemoteKeyData(Value.DeviceType.TYPE_DVD, Value.dvd_index);
				} catch (Exception e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
				 for (int i=0;i<tempRemotes.size();i++){
						
						try {
							tempCodeDatas[i] =	RemoteCore.encodeRemoteData(tempRemotes.get(i));
						} catch (Exception e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
						Log.v(TAG, "datavalue byte count " + i +"--->" + tempCodeDatas[i]);
					}
		 
				
			        while(it.hasNext()){
			            @SuppressWarnings("unchecked")
						Map.Entry<String, KeyValue> me=(Map.Entry<String, KeyValue>)it.next();
			            Log.v(TAG, "keyvaluetab index ----->   "  +me.getKey() );	
			            Log.v(TAG, "keyvaluetab hashcode ----->   "  +me.hashCode() );	
			            KeyValue kv = me.getValue();
			            if(kv.getDeviceType()==Value.DeviceType.TYPE_DVD){
			            	String temp = tempCodeDatas[kv.getKeyColumn()];
			            	
			            	  kv.setData(temp);
			            	  kv.setIsLearned(0);
			            	  me.setValue(kv);
			            	  Log.v(TAG, "keyvaluetab kv ----->   "  +kv.getKeyValue() );	
			            }
			        }

				break;
			case Value.DeviceType.TYPE_STB:
				mRmtDB.open();
				 try {
					tempRemotes=mRmtDB.getRemoteKeyData(Value.DeviceType.TYPE_STB, Value.stb_index);
				} catch (Exception e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
				 for (int i=0;i<tempRemotes.size();i++){
						
						try {
							tempCodeDatas[i] =	RemoteCore.encodeRemoteData(tempRemotes.get(i));
						} catch (Exception e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
						Log.v(TAG, "datavalue byte count " + i +"--->" + tempCodeDatas[i]);
					}
		 
				
			        while(it.hasNext()){
			            @SuppressWarnings("unchecked")
						Map.Entry<String, KeyValue> me=(Map.Entry<String, KeyValue>)it.next();
			            Log.v(TAG, "keyvaluetab index ----->   "  +me.getKey() );	
			            Log.v(TAG, "keyvaluetab hashcode ----->   "  +me.hashCode() );	
			            KeyValue kv = me.getValue();
			            if(kv.getDeviceType()==Value.DeviceType.TYPE_STB){
			            	String temp = tempCodeDatas[kv.getKeyColumn()];
			            	
			            	  kv.setData(temp);
			            	  kv.setIsLearned(0);
			            	  me.setValue(kv);
			            	  Log.v(TAG, "keyvaluetab kv ----->   "  +kv.getKeyValue() );	
			            }
			        }

				break;
				
				
				
				default:
					Log.v(TAG, "error device type");
				break;
			}
		mRmtDB.close();
	}
	*/
	public static void allKeyTabSetValue(Context mContext){
		ArrayList<RemoteData> tempRemotes = new ArrayList<RemoteData>();
	
		String[] tvCodeDatas = new String[30];
		String[] dvdCodeDatas = new String[30];
		String[] stbCodeDatas = new String[30];
		
		String[] fanCodeDatas = new String[30];
		String[] pjtCodeDatas = new String[30];
		if (mRmtDB==null){
			mRmtDB = new RemoteDB(mContext);	
			}
		mRmtDB.open();
		tempRemotes=mRmtDB.getRemoteKeyData(Value.DeviceType.TYPE_TV, Value.tv_index);
		 for (int i=0;i<tempRemotes.size();i++){
			 tvCodeDatas[i] =	RemoteCore.encodeRemoteData(tempRemotes.get(i));
			//	Log.v(TAG, "datavalue byte count " + i +"--->" + tempCodeDatas[i]);
			}
	   tempRemotes.clear();
	   tempRemotes=mRmtDB.getRemoteKeyData(Value.DeviceType.TYPE_DVD, Value.dvd_index);
		 for (int i=0;i<tempRemotes.size();i++){
			 dvdCodeDatas[i] =	RemoteCore.encodeRemoteData(tempRemotes.get(i));
			//	Log.v(TAG, "datavalue byte count " + i +"--->" + tempCodeDatas[i]);
			}
		 tempRemotes.clear();
		 tempRemotes=mRmtDB.getRemoteKeyData(Value.DeviceType.TYPE_STB, Value.stb_index);
		 for (int i=0;i<tempRemotes.size();i++){
			stbCodeDatas[i] =	RemoteCore.encodeRemoteData(tempRemotes.get(i));
			//	Log.v(TAG, "datavalue byte count " + i +"--->" + tempCodeDatas[i]);
			}
		 tempRemotes.clear();
		 tempRemotes=mRmtDB.getRemoteKeyData(Value.DeviceType.TYPE_FAN, Value.fan_index);
		 for (int i=0;i<tempRemotes.size();i++){
			fanCodeDatas[i] =	RemoteCore.encodeRemoteData(tempRemotes.get(i));
			//	Log.v(TAG, "datavalue byte count " + i +"--->" + tempCodeDatas[i]);
			}
		 tempRemotes.clear();
		 tempRemotes=mRmtDB.getRemoteKeyData(Value.DeviceType.TYPE_PJT, Value.pjt_index);
		 for (int i=0;i<tempRemotes.size();i++){
			pjtCodeDatas[i] =	RemoteCore.encodeRemoteData(tempRemotes.get(i));
			//	Log.v(TAG, "datavalue byte count " + i +"--->" + tempCodeDatas[i]);
			}
		
		 
		 
		 Set<?> set=Value.keyValueTab.entrySet();
	        Iterator<?> it=set.iterator();
		Log.v(TAG, "keyTabSetValue start");
			
				       while(it.hasNext()){
			            @SuppressWarnings("unchecked")
						Map.Entry<String, KeyValue> me=(Map.Entry<String, KeyValue>)it.next();
//			            Log.v(TAG, "keyvaluetab index ----->   "  +me.getKey() );	
//			            Log.v(TAG, "keyvaluetab hashcode ----->   "  +me.hashCode() );	
			            KeyValue kv = me.getValue();
			            if(kv.getDeviceType()==Value.DeviceType.TYPE_TV){
			            	String temp = tvCodeDatas[kv.getKeyColumn()];
			            	  kv.setData(temp);
			            	  kv.setIsLearned(0);
			            	  me.setValue(kv);
			            	  Log.v(TAG, "keyvaluetab kv ----->   "  +kv.getKeyValue() );	
			            }
			            if(kv.getDeviceType()==Value.DeviceType.TYPE_DVD){
			            	String temp = dvdCodeDatas[kv.getKeyColumn()];
			            	  kv.setData(temp);
			            	  kv.setIsLearned(0);
			            	  me.setValue(kv);
			            	  Log.v(TAG, "keyvaluetab kv ----->   "  +kv.getKeyValue() );	
			            }
			            if(kv.getDeviceType()==Value.DeviceType.TYPE_STB){
			            	String temp = stbCodeDatas[kv.getKeyColumn()];
			            	  kv.setData(temp);
			            	  kv.setIsLearned(0);
			            	  me.setValue(kv);
			            	  Log.v(TAG, "keyvaluetab kv ----->   "  +kv.getKeyValue() );	
			            }
			            if(kv.getDeviceType()==Value.DeviceType.TYPE_FAN){
			            	String temp = fanCodeDatas[kv.getKeyColumn()];
			            	  kv.setData(temp);
			            	  kv.setIsLearned(0);
			            	  me.setValue(kv);
			            	  Log.v(TAG, "keyvaluetab kv ----->   "  +kv.getKeyValue() );	
			            }
			            if(kv.getDeviceType()==Value.DeviceType.TYPE_PJT){
			            	String temp = pjtCodeDatas[kv.getKeyColumn()];
			            	  kv.setData(temp);
			            	  kv.setIsLearned(0);
			            	  me.setValue(kv);
			            	  Log.v(TAG, "keyvaluetab kv ----->   "  +kv.getKeyValue() );	
			            }
			            
			        }
				       mRmtDB.close();
		
	}
	
	
	
	
}
