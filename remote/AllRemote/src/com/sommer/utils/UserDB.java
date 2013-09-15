package com.sommer.utils;


import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;





import com.sommer.data.RemoteDevice;
import com.sommer.data.Value;



import android.content.ContentValues;
import android.content.Context;

import android.database.Cursor;

import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteDatabase.CursorFactory;
import android.database.sqlite.SQLiteException;
import android.database.sqlite.SQLiteOpenHelper;
import android.util.Log;




public class UserDB extends SQLiteOpenHelper {
	
	final static String TAG = "UserDB";

	
	final static String REMOTEDEVICES	="remote_devices";
	
	final static String AIR	="air_data";
	
	
	
	final static String USERTAB	="user_tab";
	public static final String USER_ID = "_id";
	public static final String USER_DEVICE= "device";
	public static final String USER_NAME = "key_name";
	public static final String USER_DATA = "remote_data";

	//用户数据库文件的版本
	private static final int DB_VERSION = 1;
	//数据库文件目标存放路径为系统默认位置，
	private static String DB_PATH = "/data/data/com.sommer.allremote/files/databases/";
	
	//如果你想把数据库文件存放在SD卡的话
	// private static String DB_PATH = android.os.Environment.getExternalStorageDirectory().getAbsolutePath()
	// + "/arthurcn/drivertest/packfiles/";
	
	private static String DB_NAME = "User.db";
	private static String ASSETS_NAME = "User.db";
	
	private SQLiteDatabase myUserDB;
	private final Context myContext;
	


	public UserDB(Context context, String name, CursorFactory factory, int version) {
	//必须通过super调用父类当中的构造函数
		super(context, name, null, version);
		this.myContext = context;
	}
	
	public UserDB(Context context, String name, int version){
		this(context,name,null,version);
	}
	
	public UserDB(Context context, String name){
		this(context,name,DB_VERSION);
	}
	
	public UserDB (Context context) {
		this(context, DB_PATH + DB_NAME);
	}
	
	public void createDataBase() throws IOException{
		boolean dbExist = checkDataBase();
		
		if (dbExist==false){
		
		//创建数据库
		try {
			File dir = new File(DB_PATH);
			if(!dir.exists()){
			dir.mkdirs();
			}
			File dbf = new File(DB_PATH + DB_NAME);
			if(dbf.exists()){
			dbf.delete();
		}
			SQLiteDatabase.openOrCreateDatabase(dbf, null);
			// 复制asseets中的db文件到DB_PATH下
			copyDataBase();
			//copyBigDataBase();
			} catch (IOException e) {
			throw new Error("数据库创建失败");
			}
		}
		
	}

	//检查数据库是否有效
	private boolean checkDataBase(){
		SQLiteDatabase checkDB = null;
		String myPath = DB_PATH + DB_NAME;
		try{ 
		checkDB = SQLiteDatabase.openDatabase(myPath, null, SQLiteDatabase.OPEN_READWRITE);
		}catch(SQLiteException e){
		//database does't exist yet.
		}
		if(checkDB != null){
		checkDB.close();
		Log.v(TAG, "db  close");
	
		}
		return checkDB != null ? true : false;
	}
	
	
	public UserDB open(){
		String myPath = DB_PATH + DB_NAME;
	//	Log.v(TAG, "数据库已经...");
		
		myUserDB = SQLiteDatabase.openDatabase(myPath, null, SQLiteDatabase.OPEN_READWRITE);
	//	Log.v(TAG, "数据库打开");
		return this;
	
	}
	
	/**
	* Copies your database from your local assets-folder to the just created empty database in the
	* system folder, from where it can be accessed and handled.
	* This is done by transfering bytestream.
	* */
	private void copyDataBase() throws IOException{
		//Open your local db as the input stream
		InputStream myInput = myContext.getAssets().open(ASSETS_NAME);
		// Path to the just created empty db
		String outFileName = DB_PATH + DB_NAME;
		//Open the empty db as the output stream
		OutputStream myOutput = new FileOutputStream(outFileName);
		//transfer bytes from the inputfile to the outputfile
		byte[] buffer = new byte[1024];
		int length;
		while ((length = myInput.read(buffer))>0){
		myOutput.write(buffer, 0, length);
		}
		//Close the streams
		myOutput.flush();
		myOutput.close();
		myInput.close();
	}

	

	@Override
	public synchronized void close() {
		if(myUserDB != null){
			myUserDB.close();
	//	System.out.println("关闭成功1");
		}
		super.close();
	//	System.out.println("关闭成功2");
	}

	/**
	* 该函数是在第一次创建的时候执行，
	* 实际上是第一次得到SQLiteDatabase对象的时候才会调用这个方法
	*/
	@Override
	public void onCreate(SQLiteDatabase db) {
	}

	/**
	* 数据库表结构有变化时采用
	*/
	@Override
	public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
	}

	@SuppressWarnings("unused")
	private SQLiteDatabase openOrCreateDatabase(String string, Object object) {
	// TODO Auto-generated method stub
		return null;
	}
	
	



public  void updateKeyValue(String keyName,String data){
	  ContentValues values = new ContentValues();
	      values.put(USER_NAME, keyName);

	      values.put(USER_DATA,data );

	  	myUserDB.update(USERTAB, values, "name=?", new String[] {keyName});

	  
}


public  void addKeyValue(String keyName,String data,int device){
	  ContentValues values = new ContentValues();
	      values.put(USER_NAME, keyName);
	      values.put(USER_DEVICE, String.valueOf(device));
	      values.put(USER_DATA,data );

	  	myUserDB.insert(USERTAB,null, values);
	  
}

	
	public  void getRemoteDevices(){
		
	//	Log.v(TAG, "saveAllKeyTabValue start");
		Cursor c = myUserDB.query(REMOTEDEVICES, null, null ,null, null, null, null);
		
		
		c.moveToFirst();
	
		do{
			RemoteDevice rmtDev = new RemoteDevice();
			rmtDev.setId(c.getInt(0));
			rmtDev.setType(c.getInt(1));
			rmtDev.setCode(c.getString(2));
			rmtDev.setName(c.getString(3));
			
			Value.rmtDevs.add(rmtDev);
			
		}while(c.moveToNext());
	
		c.close(); 

	//	Log.v(TAG, "devicetype--->"+ Value.rmtDevs.toString());
	}
	
	public  String getRemoteData(int device,String keyName){
		String rmtData = null;	
		//	Log.v(TAG, "saveAllKeyTabValue start");
			Cursor c = myUserDB.query(USERTAB, null, "device =? and key_name = ? " ,new String[]{String.valueOf(device),keyName}, null, null, null);
			
			if (c.moveToFirst()){
				rmtData =	c.getString(3);
			}		
			c.close(); 
			return rmtData;
		//	Log.v(TAG, "devicetype--->"+ Value.rmtDevs.toString());
		}
	
	
	
	
	public void deleteRemoteDevice(int device){
		
	     
	        myUserDB.delete(USERTAB, "device =? ",new String[]{String.valueOf(device)});  
	        myUserDB.delete(REMOTEDEVICES, "_id =? ",new String[]{String.valueOf(device)}); 
	}
	
}