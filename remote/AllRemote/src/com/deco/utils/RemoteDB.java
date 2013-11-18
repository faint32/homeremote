package com.deco.utils;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;

import java.util.Locale;

import com.deco.data.RemoteData;
import com.deco.data.Value;
import com.deco.ircore.RemoteCommunicate;

import android.annotation.SuppressLint;
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
public class RemoteDB extends SQLiteOpenHelper {

	final static String TAG = "RemoteDB";

	final static String LIST_TAB = "remote";
	final static String BRAND_TAB = "brand";

	final static String KEY_TAB = "key_tab";

	private static final int DB_VERSION = 1;

	@SuppressLint("SdCardPath")
	private static String DB_PATH = "/data/data/com.deco.allremote/databases/";

	// private static String DB_PATH =
	// android.os.Environment.getExternalStorageDirectory().getAbsolutePath()
	// + "/arthurcn/drivertest/packfiles/";

	private static String DB_NAME = "Remote.db";
	private static String ASSETS_NAME = "Remote.db";

	private SQLiteDatabase myDataBase;
	private final Context myContext;

	// private static final int ASSETS_SUFFIX_BEGIN = 100;

	// private static final int ASSETS_SUFFIX_END = 110;

	public RemoteDB(Context context, String name, CursorFactory factory,
			int version) {

		super(context, name, null, version);
		this.myContext = context;
	}

	public RemoteDB(Context context, String name, int version) {
		this(context, name, null, version);
	}

	public RemoteDB(Context context, String name) {
		this(context, name, DB_VERSION);
	}

	public RemoteDB(Context context) {
		this(context, DB_PATH + DB_NAME);
	}

	public void createDataBase() throws IOException {
		// boolean dbExist = checkDataBase();

		try {
			File dir = new File(DB_PATH);
			if (!dir.exists()) {
				dir.mkdirs();
			}
			File dbf = new File(DB_PATH + DB_NAME);
			if (dbf.exists()) {
				dbf.delete();
			}
			// SQLiteDatabase.openOrCreateDatabase(dbf, null);
			// 澶嶅埗asseets涓殑db鏂囦欢鍒癉B_PATH涓�
			copyDataBase();
			// copyBigDataBase();
		} catch (IOException e) {
			throw new Error("create database failed");
		}

	}

	private boolean checkDataBase() {
		SQLiteDatabase checkDB = null;
		String myPath = DB_PATH + DB_NAME;
		try {
			checkDB = SQLiteDatabase.openDatabase(myPath, null,
					SQLiteDatabase.OPEN_READONLY);
		} catch (SQLiteException e) {
			// database does't exist yet.
		}
		if (checkDB != null) {
			checkDB.close();
			Log.v(TAG, "db  close");

		}

		return checkDB != null ? true : false;
	}

	// private boolean checkDataBaseTime() throws IOException{
	// String myPath = DB_PATH + DB_NAME;
	//
	// File f = new File(myPath.toString());
	// long time1 = f.lastModified();
	// Log.v(TAG, "database modify time ====> "+ time1);
	// String[] path= myContext.getAssets().list("");
	// for (String p:path){
	// Log.v(TAG, "assets databse modify path ====> "+p );
	// }
	// f = new File(path[0].toString());
	//
	// long time2 = f.lastModified();
	// Log.v(TAG, "assets databse modify time ====> "+ time2);
	// if (time1==time2){
	// return true;
	// }
	// else{
	// return false;
	// }

	// }
//	private byte[] InputStreamToByte(InputStream is) throws IOException {
//		ByteArrayOutputStream bytestream = new ByteArrayOutputStream();
//		int ch;
//		while ((ch = is.read()) != -1) {
//			bytestream.write(ch);
//		}
//		byte imgdata[] = bytestream.toByteArray();
//		bytestream.close();
//		return imgdata;
//	}

	public RemoteDB open() {
		String myPath = DB_PATH + DB_NAME;

		myDataBase = SQLiteDatabase.openDatabase(myPath, null,
				SQLiteDatabase.OPEN_READONLY);

		Log.v(TAG, "database opened");
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

	// private void copyBigDataBase() throws IOException{
	// InputStream myInput;
	// String outFileName = DB_PATH + DB_NAME;
	// OutputStream myOutput = new FileOutputStream(outFileName);
	// for (int i = ASSETS_SUFFIX_BEGIN; i < ASSETS_SUFFIX_END+1; i++) {
	// myInput = myContext.getAssets().open(ASSETS_NAME + "." + i);
	// byte[] buffer = new byte[1024];
	// int length;
	// while ((length = myInput.read(buffer))>0){
	// myOutput.write(buffer, 0, length);
	// }
	// myOutput.flush();
	// myInput.close();
	// }
	// myOutput.close();
	// Log.v(TAG, "database copy finished");
	//
	// }

	@Override
	public synchronized void close() {
		if (myDataBase != null) {
			myDataBase.close();

		}
		super.close();
		Log.v(TAG, "database closed");
	}

	@Override
	public void onCreate(SQLiteDatabase db) {
	}

	@Override
	public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
	}

	@SuppressWarnings("unused")
	private SQLiteDatabase openOrCreateDatabase(String string, Object object) {
		// TODO Auto-generated method stub
		return null;
	}

	public RemoteData getKeyData(int _type, String _index) {
		RemoteData rmtData = new RemoteData();
		int keyColumn = 4;
		switch (_type) {
		case Value.DeviceType.TYPE_TV:
			keyColumn = 10;
			break;
		case Value.DeviceType.TYPE_DVD:
			keyColumn = 4;
			break;
		case Value.DeviceType.TYPE_STB:
			keyColumn = 10;
			break;
		case Value.DeviceType.TYPE_FAN:
			keyColumn = 4;
			break;

		case Value.DeviceType.TYPE_PJT:
			keyColumn = 4;
			break;

		default:
			break;
		}
		Cursor c = myDataBase.query(Value.CodeProTab[_type], null,
				" code_index =?", new String[] { _index }, null, null, null);
		c.moveToFirst();
		rmtData.setIndex(c.getString(1));
		rmtData.setCodetype(c.getString(2));
		rmtData.setMode(Value.RemoteType[_type]);
		rmtData.setCustom(c.getString(3));
		rmtData.setData(c.getString(keyColumn));
		return rmtData;

	}

	public ArrayList<RemoteData> getRemoteKeyData(int _type, String _index) {
		ArrayList<RemoteData> rmtDts = new ArrayList<RemoteData>();

		rmtDts.clear();
		Cursor c = myDataBase.query(Value.CodeProTab[_type], null,
				" code_index =?", new String[] { _index }, null, null, null);
		// Cursor c = myDataBase.rawQuery("SELECT * FROM " + TV_CODE_TAB +
		// " WHERE custom=20020080" ,null);
		if (c == null) {
			return null;
		}
		c.moveToFirst();
		// Log.v(TAG, "columnCoutn data " + c.getColumnCount());
		for (int i = 4; i < c.getColumnCount(); i++) {
			RemoteData rmtData = new RemoteData();
			rmtData.setIndex(c.getString(1));
			rmtData.setCodetype(c.getString(2)); // 鑾峰彇绗竴鍒楃殑鍊�绗竴鍒楃殑绱㈠紩浠�寮�
			rmtData.setMode(Value.RemoteType[_type]);
			rmtData.setCustom(c.getString(3));
			rmtData.setData(c.getString(i));
			// Log.v(TAG, "remote data " + rmtData.getRemoteData());
			rmtDts.add(rmtData);
		}

		return rmtDts;

	}

	// public void setKeyRemoteData(int _type,String _index){
	// // ArrayList<RemoteData> rmtDts = new ArrayList<RemoteData>();
	// String[] rmtData = new String[35];
	//
	// Cursor c = myDataBase.query(Value.CodeProTab[_type], null,
	// " code_index =?" ,new String[]{_index}, null, null, null);
	// if(c.moveToFirst()){
	//
	// // Log.v(TAG, "columnCoutn data " + c.getColumnCount());
	// for (int i=4;i<c.getColumnCount();i++){
	// RemoteData rmtData1 = new RemoteData();
	// rmtData1.setCodetype(c.getString(2)) ; //鑾峰彇绗竴鍒楃殑鍊�绗竴鍒楃殑绱㈠紩浠�寮�
	// rmtData1.setCustom(c.getString(3)) ;
	// rmtData1.setData(c.getString(i)) ;
	// // Log.v(TAG, "remote data " + rmtData.getRemoteData());
	// rmtData[i-4]=RemoteCore.encodeRemoteData(rmtData1);
	// }
	//
	// }
	//
	// }

	public ArrayList<String> getBrand(String _type) {
		ArrayList<String> brands = new ArrayList<String>();
		// get all remote data
		Cursor c = myDataBase.query(LIST_TAB, null, " type =?",
				new String[] { _type }, null, null, null);
		c.moveToFirst();

		do {
			String menufactory = c.getString(1);

			if (compareListValue(brands, menufactory) == -1) {
				// Log.v(TAG, "menufactory = " + menufactory);
				brands.add(menufactory);

			}
		} while (c.moveToNext());

		c.close();

		return brands;

	}

	public ArrayList<String> getAllBrand() {
		ArrayList<String> brands = new ArrayList<String>();
		// get all remote data
		Cursor c = myDataBase.query(LIST_TAB, null, null, null, null, null,
				null);
		c.moveToFirst();

		do {
			String menufactory = c.getString(1);

			if (compareListValue(brands, menufactory) == -1) {
				// Log.v(TAG, "menufactory = " + menufactory);
				brands.add(menufactory);

			}
		} while (c.moveToNext());

		c.close();

		return brands;

	}

	public ArrayList<String> getProducts(String deviceType, String _brandName) {
		ArrayList<String> products = new ArrayList<String>();
		String brandNameLow = _brandName.toLowerCase();
		Cursor c = myDataBase.query(LIST_TAB, null, "brand =? and type = ? ",
				new String[] { brandNameLow, deviceType }, null, null, null);
		c.moveToFirst();
		do {

			products.add(c.getString(3));
		} while (c.moveToNext());

		c.close();

		return products;

	}

	// public void getKeyInitialTable(){
	// String keyName;
	// Cursor c = myDataBase.query(KEY_TAB, null, null ,null, null, null, null);
	// c.moveToFirst();
	//
	// do {
	// KeyValue kv = new KeyValue();
	// keyName = c.getString(1);
	// kv.setKeyName(keyName);
	// kv.setDeviceType(c.getInt(2));
	// kv.setKeyColumn(c.getInt(3));
	// Value.keyValueTab.add(kv);
	// // Value.keyRemoteTab.put(keyName, kv.getData());
	// }while (c.moveToNext());
	//
	// c.close();
	//
	// }
	//

	public ArrayList<String> translateBrands(ArrayList<String> brands) {
		ArrayList<String> newBrands = new ArrayList<String>();
		String localeLanguage = Locale.getDefault().getLanguage();
		int column = 0;

		if (localeLanguage.equals("zh")) {
			column = 4; // get brand chinese name
		} else if (localeLanguage.equals("tw")) {
			column = 3; // get brand taiwan name
		} else {
			column = 2; // get brand english default name
		}
		// Log.v(TAG, "get language  " + localeLanguage + "    column  " +
		// column);
		for (String brand : brands) {

			Cursor c = myDataBase.query(BRAND_TAB, null, "brand =?  ",
					new String[] { brand }, null, null, null);
			if (c.moveToFirst()) {
				// Log.v(TAG, "cursor successed");
				byte[] val = c.getBlob(column);
				if (val != null && localeLanguage.equals("zh")) {
					try {
						newBrands.add(new String(val, "GBK"));
					} catch (UnsupportedEncodingException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				} else {
					newBrands.add(c.getString(column));
				}

			} else {
				newBrands.add(brand);
			}
			c.close();
		}

		return newBrands;

	}

	public int getKeyColumn(String keyName) {
		int keyColumn = 0;

		Cursor c = myDataBase.query(KEY_TAB, null, "name =?  ",
				new String[] { keyName }, null, null, null);

		if (c.moveToFirst()) {
			int index = c.getColumnIndex("key_column");
			keyColumn = c.getInt(index);
		}
		c.close();

		return keyColumn;
	}

	public String[] getRemoteData(int _type, String _index) {
		String[] rmtDts = new String[100];

		Cursor c = myDataBase.query(Value.CodeProTab[_type], null,
				" code_index =?", new String[] { _index }, null, null, null);
		// Cursor c = myDataBase.rawQuery("SELECT * FROM " + TV_CODE_TAB +
		// " WHERE custom=20020080" ,null);
		if (c == null) {
			return null;
		}
		c.moveToFirst();
		// Log.v(TAG, "columnCoutn data " + c.getColumnCount());
		for (int i = 4; i < c.getColumnCount(); i++) {
			RemoteData rmtData = new RemoteData();
			rmtData.setIndex(c.getString(1));
			rmtData.setCodetype(c.getString(2));
			rmtData.setMode(Value.RemoteType[_type]);
			rmtData.setCustom(c.getString(3));
			rmtData.setData(c.getString(i));
			// Log.v(TAG, "remote data " + rmtData.getRemoteData());

			rmtDts[i - 4] = RemoteCommunicate.encodeDECORemoteData(rmtData);
		}

		return rmtDts;

	}

	/**
	 * compareListValue compare arraylist all members
	 * 
	 * @param datas
	 * @param data
	 * @return if get same members return >0 or no same member return -1
	 */
	public int compareListValue(ArrayList<String> datas, String data) {
		int i;
		for (i = 0; i < datas.size(); i++) {
			if (datas.get(i).equals(data)) {
				return i;
			}
		}
		return -1;

	}

}