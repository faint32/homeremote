package com.sommer.data;

public class KeyValue {
	String  keyName;
	int isLearned;
	String data;
	int deviceType;
	int keyColumn;
	
	
	public int getDeviceType() {
		return deviceType;
	}
	public void setDeviceType(int deviceType) {
		this.deviceType = deviceType;
	}
	public int getKeyColumn() {
		return keyColumn;
	}
	public void setKeyColumn(int keyColumn) {
		this.keyColumn = keyColumn;
	}
	public String getKeyName() {
		return keyName;
	}
	public void setKeyName(String keyName) {
		this.keyName = keyName;
	}
	
	
	public int getIsLearned() {
		return isLearned;
	}
	public void setIsLearned(int isLearned) {
		this.isLearned = isLearned;
	}
	public String getData() {
		return data;
	}
	public void setData(String data) {
		this.data = data;
	}
	
	
	public String getKeyValue(){
		String keyString = this.keyName
		 + this.isLearned
		+ this.data
		+ this.deviceType
		+ this.keyColumn;
	return keyString;	
	}
	
	
	
}
