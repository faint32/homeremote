package com.sommer.utils;


import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Locale;
import java.util.Map;
import java.util.Set;


import com.sommer.data.CodeType;
import com.sommer.data.KeyValue;
import com.sommer.data.RemoteData;
import com.sommer.data.Value;
import com.sommer.ircomm.RemoteCore;


import android.content.ContentValues;
import android.content.Context;
import android.content.res.Resources;
import android.database.Cursor;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteDatabase.CursorFactory;
import android.database.sqlite.SQLiteException;
import android.database.sqlite.SQLiteOpenHelper;
import android.util.Log;




public class UserDB extends SQLiteOpenHelper {
	
	final static String TAG = "UserDB";

	
	final static String REMOTE	="remote_index";
	
	final static String AIR	="air_data";
	
	
	
	final static String USERTAB	="user_tab";
	public static final String USER_ID = "_id";
	public static final String USER_NAME = "key_name";
	public static final String USER_LEARN = "is_learned";
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
		checkDB = SQLiteDatabase.openDatabase(myPath, null, SQLiteDatabase.OPEN_READONLY);
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
	
	public void getUserKeyValue(){
		
			Cursor c = myUserDB.query(USERTAB, null, null ,null, null, null, null);
			c.moveToFirst();
			do{


				Value.keyRemoteTab.put(c.getString(1), c.getString(2));
				
			//	Value.keyRemoteTab.put(kv.getKeyName(), kv.getData());
			}while(c.moveToNext());
	//		 String name = cursor.getString(cursor.getColumnIndex("name"));

		
		c.close(); 
		
		
		
		
	}
	
	
	@SuppressWarnings("unchecked")
	public  void saveAllKeyTabValue(){
		
		Log.v(TAG, "saveAllKeyTabValue start");
		Cursor c = myUserDB.query(USERTAB, null, null ,null, null, null, null);
		c.moveToFirst();
		do{
			 ContentValues cvs = new ContentValues();

		//	Value.keyRemoteTab.put(c.getString(1), c.getString(2));
			 
			cvs.put(USER_NAME, c.getString(1));
			
			String data = RemoteCore.updateRemoteData(c.getString(2));
		     
			cvs.put(USER_DATA,data );
		      
		  	myUserDB.update(USERTAB, cvs, "key_name=?", new String[] {c.getString(1)});
			
		//	Value.keyRemoteTab.put(kv.getKeyName(), kv.getData());
		}while(c.moveToNext());
	
		c.close(); 

		
	}
	
	public  void getRemoteIndex(){
		
		Log.v(TAG, "saveAllKeyTabValue start");
		Cursor c = myUserDB.query(REMOTE, null, null ,null, null, null, null);
		int size = c.getCount();
		Value.deviceType = new int[size];
		Value.deviceIndex = new String[size];
		c.moveToFirst();
		int i = 0;
		do{
			Value.deviceType[i]=c.getInt(1);
			Value.deviceIndex[i] = c.getString(2); 
			i++;
		}while(c.moveToNext());
	
		c.close(); 

		Log.v(TAG, "devicetype--->"+ Value.deviceType.toString());
	}
	
	
	
	
}