package com.deco.utils;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

import com.deco.data.AirData;
import com.deco.data.RemoteDevice;
import com.deco.data.Value;

import android.content.ContentValues;
import android.content.Context;

import android.database.Cursor;

import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteDatabase.CursorFactory;
import android.database.sqlite.SQLiteException;
import android.database.sqlite.SQLiteOpenHelper;
import android.util.Log;

/**
 * @author work
 * 
 */
public class UserDB extends SQLiteOpenHelper {

	final static String TAG = "UserDB";

	final static String REMOTEDEVICES = "remote_devices";
	public static final String REMOTE_ID = "_id";
	public static final String REMOTE_TYPE = "type";
	public static final String REMOTE_CODE = "code";
	public static final String REMOTE_NAME = "name";
	public static final String REMOTE_BRAND = "brand";

	public static final String AIR_POWER = "power";
	public static final String AIR_TEMP = "temp";
	public static final String AIR_MODE = "mode";
	public static final String AIR_AUTO = "auto";
	public static final String AIR_WDIR = "wind_direct";
	public static final String AIR_WCOUNT = "wind_count";

	final static String USERTAB = "user_tab";
	public static final String USER_ID = "_id";
	public static final String USER_DEVICE = "device";
	public static final String USER_NAME = "key_name";
	public static final String USER_DATA = "data";
	public static final String USER_LEARN = "is_learn";
	// 用户数据库文件的版本
	private static final int DB_VERSION = 1;
	// 数据库文件目标存放路径为系统默认位置，
	private static String DB_PATH = "/data/data/com.deco.allremote/databases/";

	// 如果你想把数据库文件存放在SD卡的话
	// private static String DB_PATH =
	// android.os.Environment.getExternalStorageDirectory().getAbsolutePath()
	// + "/arthurcn/drivertest/packfiles/";

	private static String DB_NAME = "User.db";
	private static String ASSETS_NAME = "User.db";

	private SQLiteDatabase myUserDB;
	private final Context myContext;

	public UserDB(Context context, String name, CursorFactory factory,
			int version) {
		// 必须通过super调用父类当中的构造函数
		super(context, name, null, version);
		this.myContext = context;
	}

	public UserDB(Context context, String name, int version) {
		this(context, name, null, version);
	}

	public UserDB(Context context, String name) {
		this(context, name, DB_VERSION);
	}

	public UserDB(Context context) {
		this(context, DB_PATH + DB_NAME);
	}

	public void createDataBase() throws IOException {
		// boolean dbExist = checkDataBase();
		File dbf = new File(DB_PATH + DB_NAME);
		if (dbf.exists() == false) {

			// if (Value.initial==true){

			// 创建数据库
			try {
				File dir = new File(DB_PATH);
				if (!dir.exists()) {
					dir.mkdirs();
				}
				// dbf = new File(DB_PATH + DB_NAME);
				if (dbf.exists()) {
					dbf.delete();
				}
				// SQLiteDatabase.openOrCreateDatabase(dbf, null);
				// 复制asseets中的db文件到DB_PATH下
				copyDataBase();
				// copyBigDataBase();
			} catch (IOException e) {
				throw new Error("user database create failed");
			}
		}

	}

	// 检查数据库是否有效
	// private boolean checkDataBase(){
	// SQLiteDatabase checkDB = null;
	// String myPath = DB_PATH + DB_NAME;
	// try{
	// checkDB = SQLiteDatabase.openDatabase(myPath, null,
	// SQLiteDatabase.OPEN_READONLY);
	// }catch(SQLiteException e){
	// //database does't exist yet.
	// }
	// if(checkDB != null){
	// checkDB.close();
	// Log.v(TAG, "db  close");
	//
	// }
	// return checkDB != null ? true : false;
	// }

	public UserDB open() {
		String myPath = DB_PATH + DB_NAME;

		myUserDB = SQLiteDatabase.openDatabase(myPath, null,
				SQLiteDatabase.OPEN_READWRITE);

		return this;

	}

	/**
	 * Copies your database from your local assets-folder to the just created
	 * empty database in the system folder, from where it can be accessed and
	 * handled. This is done by transfering bytestream.
	 * */
	private void copyDataBase() throws IOException {
		// Open your local db as the input stream
		InputStream myInput = myContext.getAssets().open(ASSETS_NAME);
		// Path to the just created empty db
		String outFileName = DB_PATH + DB_NAME;
		// Open the empty db as the output stream
		OutputStream myOutput = new FileOutputStream(outFileName);
		// transfer bytes from the inputfile to the outputfile
		byte[] buffer = new byte[1024];
		int length;
		while ((length = myInput.read(buffer)) > 0) {
			myOutput.write(buffer, 0, length);
		}
		// Close the streams
		myOutput.flush();
		myOutput.close();
		myInput.close();
	}

	@Override
	public synchronized void close() {
		if (myUserDB != null) {
			myUserDB.close();
			// System.out.println("关闭成功1");
		}
		super.close();
		// System.out.println("关闭成功2");
	}

	/**
	 * 该函数是在第一次创建的时候执行， 实际上是第一次得到SQLiteDatabase对象的时候才会调用这个方法
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

	public void updateKeyValue(String keyName, String data) {
		ContentValues values = new ContentValues();
		values.put(USER_NAME, keyName);

		values.put(USER_DATA, data);

		myUserDB.update(USERTAB, values, "name=?", new String[] { keyName });

	}

	public void addKeyValue(String keyName, String data, int device, int column) {
		try {
			ContentValues value = new ContentValues();

			value.put(USER_NAME, keyName);
			value.put(USER_DEVICE, String.valueOf(device));
			value.put(USER_DATA, data);
			value.put(USER_LEARN, 0);

			long newData = myUserDB.insert(USERTAB, null, value);
			// Log.v(TAG, "new id --->"+ newData);
		} catch (Exception e) {
			Log.v(TAG, e.toString());
			e.printStackTrace();
		}

	}

	public void getRemoteDevices() {

		// Log.v(TAG, "saveAllKeyTabValue start");
		Cursor c = myUserDB.query(REMOTEDEVICES, null, null, null, null, null,
				null);
		Value.rmtDevs.clear();
		c.moveToFirst();
		AirData ad = new AirData();

		do {
			RemoteDevice rmtDev = new RemoteDevice();
			rmtDev.setId(c.getInt(0));
			rmtDev.setType(c.getInt(1));
			rmtDev.setCode(c.getString(2));
			rmtDev.setName(c.getString(3));
			rmtDev.setBrand(c.getString(4));
			if (rmtDev.getType() == Value.DeviceType.TYPE_AIR) {
				ad.setCode(Integer.valueOf(c.getString(2)));
				ad.setmPower(c.getInt(5));
				ad.setmTmp(c.getInt(6));
				ad.setmMode(c.getInt(7));
				ad.setmWindAuto(c.getInt(8));
				ad.setmWindDir(c.getInt(9));
				ad.setmWindCount(c.getInt(10));
				rmtDev.setAirData(ad);
			}
			Value.rmtDevs.add(rmtDev);

		} while (c.moveToNext());

		c.close();

		// Log.v(TAG, "devicetype--->"+ Value.rmtDevs.toString());
	}

	public String getRemoteData(int device, String keyName) {
		String rmtData = null;
		// Log.v(TAG, "saveAllKeyTabValue start");
		Cursor c = myUserDB.query(USERTAB, null, "device =? and key_name = ? ",
				new String[] { String.valueOf(device), keyName }, null, null,
				null);

		if (c.moveToFirst()) {
			rmtData = c.getString(3);
		}
		c.close();
		return rmtData;
		// Log.v(TAG, "devicetype--->"+ Value.rmtDevs.toString());
	}

	public void updateRemoteDevice(int device) {
		RemoteDevice rmtDev = Value.rmtDevs.get(device);

		ContentValues values = new ContentValues();
		values.put(REMOTE_ID, rmtDev.getId());
		values.put(REMOTE_TYPE, rmtDev.getType());
		values.put(REMOTE_CODE, rmtDev.getCode());
		values.put(REMOTE_NAME, rmtDev.getName());
		values.put(REMOTE_BRAND, rmtDev.getBrand());

		myUserDB.update(REMOTEDEVICES, values, "_id =? ",
				new String[] { String.valueOf(device) });

		// myUserDB.delete(USERTAB, "device =? ",new
		// String[]{String.valueOf(device)});

	}

	public void saveRemoteDevice(RemoteDevice rmtDev) {

		ContentValues values = new ContentValues();
		values.put(REMOTE_ID, rmtDev.getId());
		values.put(REMOTE_TYPE, rmtDev.getType());
		values.put(REMOTE_CODE, rmtDev.getCode());
		values.put(REMOTE_NAME, rmtDev.getName());
		values.put(REMOTE_BRAND, rmtDev.getBrand());
		if (rmtDev.getType() == Value.DeviceType.TYPE_AIR) {
			AirData ad = rmtDev.getAirData();
			values.put(AIR_POWER, ad.getmPower());
			values.put(AIR_TEMP, ad.getmTmp());
			values.put(AIR_MODE, ad.getmMode());
			values.put(AIR_AUTO, ad.getmWindAuto());
			values.put(AIR_WDIR, ad.getmWindDir());
			values.put(AIR_WCOUNT, ad.getmWindCount());
		}
		if (isDeviceExist(rmtDev.getId())) {
			Log.v(TAG, "updata" + rmtDev.getFullInfo());
			myUserDB.update(REMOTEDEVICES, values, "_id = ? ",
					new String[] { String.valueOf(rmtDev.getId()) });
		} else {
			Log.v(TAG, "insert database");
			myUserDB.insert(REMOTEDEVICES, null, values);

		}

		// myUserDB.delete(USERTAB, "device =? ",new
		// String[]{String.valueOf(device)});

	}

	public void saveRmtDevKeyTab(RemoteDevice rmtDev) {

		if (rmtDev.getType() == Value.DeviceType.TYPE_AIR)
			return;

		ContentValues values = new ContentValues();
		values.put(REMOTE_ID, rmtDev.getId());
		values.put(REMOTE_TYPE, rmtDev.getType());
		values.put(REMOTE_CODE, rmtDev.getCode());
		values.put(REMOTE_NAME, rmtDev.getName());
		values.put(REMOTE_BRAND, rmtDev.getBrand());

		if (isDeviceExist(rmtDev.getId())) {
			Log.v(TAG, "updata" + rmtDev.getFullInfo());
			myUserDB.update(REMOTEDEVICES, values, "_id = ? ",
					new String[] { String.valueOf(rmtDev.getId()) });
		} else {
			Log.v(TAG, "insert database");
			myUserDB.insert(REMOTEDEVICES, null, values);

		}

		// myUserDB.delete(USERTAB, "device =? ",new
		// String[]{String.valueOf(device)});

	}

	public boolean isDeviceExist(int device) {
		Cursor c = myUserDB.query(REMOTEDEVICES, null, "_id = ? ",
				new String[] { String.valueOf(device) }, null, null, null);

		if (c.moveToFirst()) {
			c.close();
			return true;
		}
		c.close();
		return false;
	}

	public void delDevKeyTab(int device) {
		if (isDeviceExist(device)) {
			myUserDB.delete(USERTAB, "device =? ",
					new String[] { String.valueOf(device) });
		}
	}

	public void addRemoteDevice(int device) {

		ContentValues values = new ContentValues();
		values.put(REMOTE_ID, Value.rmtDev.getId());
		values.put(REMOTE_TYPE, Value.rmtDev.getType());
		values.put(REMOTE_CODE, Value.rmtDev.getCode());
		values.put(REMOTE_NAME, Value.rmtDev.getName());
		values.put(REMOTE_BRAND, Value.rmtDev.getBrand());

		myUserDB.insert(REMOTEDEVICES, null, values);

	}

	public void deleteRemoteDevice(int type, int device) {
		ContentValues cv = new ContentValues();
		//

		myUserDB.delete(REMOTEDEVICES, "_id =? ",
				new String[] { String.valueOf(device) });
		Cursor c = myUserDB.query(REMOTEDEVICES, null, "_id > ?",
				new String[] { String.valueOf(device) }, null, null, null);
		
		if (c.moveToFirst()) {
			do {
				int oldID = c.getInt(0);
				int newID = oldID;
				newID -= 1;
				cv.put(REMOTE_ID, newID);
				myUserDB.update(REMOTEDEVICES, cv, "_id=?",
						new String[] { String.valueOf(oldID) });
			} while (c.moveToNext());
		}
		c.close();
    
	    if (type != Value.DeviceType.TYPE_AIR){
			myUserDB.delete(USERTAB, "device =? ",
					new String[] { String.valueOf(device) });
			 c = myUserDB.query(USERTAB, null, "device > ?",
					new String[] { String.valueOf(device) }, null, null, null);

			if (c.moveToFirst()) {
				do {
					int newDevice = c.getInt(1);
					newDevice -= 1;
					cv.put(USER_DEVICE, newDevice);
					myUserDB.update(USERTAB, cv, "_id=?",
							new String[] { String.valueOf(c.getInt(0)) });
				} while (c.moveToNext());
			}
			c.close();
	    }
		
	}
	
	public void saveLearnData(int device, String keyName, String learnData) {
		// TODO Auto-generated method stub
	
		 ContentValues cvs = new ContentValues();
		 cvs.put(USER_DATA,learnData);
	      cvs.put(USER_LEARN,1);
	  
		//	Log.v(TAG, "saveAllKeyTabValue start");
		 myUserDB.update(USERTAB, cvs,"device =? and key_name = ? " ,new String[]{String.valueOf(device),keyName});
	}  
	public void deviceKeyTabInitial(int device, String keyName, String data) {

		ContentValues cvs = new ContentValues();

		cvs.put(USER_DEVICE, device);
		cvs.put(USER_NAME, keyName);
		cvs.put(USER_DATA, data);
		cvs.put(USER_LEARN, 0);
		myUserDB.insert(USERTAB, null, cvs);
		Log.v(TAG, cvs.toString());
	}

	public void cleanKeyTab() {

		// myUserDB.delete(USERTAB, "_id =? ",new
		// String[]{String.valueOf(device)});
		myUserDB.execSQL("DELETE FROM " + USERTAB);
	}

}