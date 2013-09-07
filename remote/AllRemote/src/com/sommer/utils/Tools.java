package com.sommer.utils;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

import com.sommer.data.AirData;

import android.app.Activity;
import android.content.Context;
import android.widget.Toast;



public final class Tools {

	public static String bytesToHexString(byte[] src) {
		StringBuilder stringBuilder = new StringBuilder("");
		if (src == null || src.length <= 0) {
			return null;
		}
		for (int i = 0; i < src.length; i++) {
			int v = src[i] & 0xFF;
			String hv = Integer.toHexString(v);
			if (hv.length() < 2) {
				stringBuilder.append(0);
			}
			stringBuilder.append(hv);
		}
		return stringBuilder.toString();
	}
	
	
	public static String bytesToHexString(byte[] src,int length) {
		StringBuilder stringBuilder = new StringBuilder("");
		if (src == null || length<= 0) {
			return null;
		}
		for (int i = 0; i < length; i++) {
			int v = src[i] & 0xFF;
			String hv = Integer.toHexString(v);
			if (hv.length() < 2) {
				stringBuilder.append(0);
			}
			stringBuilder.append(hv);
		}
		return stringBuilder.toString();
	}
	public static byte[] hexStringToBytes(String hexString) {
		if (hexString == null || hexString.equals("")) {
			return null;
		}
		hexString = hexString.toUpperCase();
		
		int length = hexString.length() / 2;
		char[] hexChars = hexString.toCharArray();
		byte[] d = new byte[length];
		for (int i = 0; i < length; i++) {
			int pos = i * 2;
			d[i] = (byte) (charToByte(hexChars[pos]) << 4 | charToByte(hexChars[pos + 1]));
		//	Log.v("remoteSend", "data ----> " + d[i]);
		}
		return d;
	}

	private static byte charToByte(char c) {
		return (byte) "0123456789ABCDEF".indexOf(c);
	}
	public static int[] airDataToByte(AirData data) {
		int[] temp = new int[10];
		temp[0] = (int) data.getCodeType();
		temp[1] = (int) data.getmPower();
		temp[2] = (int) data.getmMode();
		temp[3] = (int) data.getmWindCount();
		temp[4] = (int) data.getmTmp();
		temp[5] = (int) data.getmWindDir();
		temp[6] = (int) data.getmWindAuto();
		
		return temp;  
    }
	
	public static void saveDocumnet(Context mContext, String datas,String fileName) {  
		
	      
        try {  
           
            FileOutputStream outputStream =mContext.openFileOutput(fileName,  
                    Activity.MODE_PRIVATE);  
            outputStream.write(datas.getBytes());  
            outputStream.flush();  
            outputStream.close();  
            Toast.makeText(mContext, fileName+"save successed", Toast.LENGTH_LONG).show();  
        } catch (FileNotFoundException e) {  
            e.printStackTrace();  
        } catch (IOException e) {  
            e.printStackTrace();  
        }  
  
    }
}
