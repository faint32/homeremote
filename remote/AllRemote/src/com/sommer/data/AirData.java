package com.sommer.data;


public class AirData {
	private  int codeType = 0;
	private  int mPower=1;
	private  int mTmp=25;
	private  int mMode=1;
	private  int mWindAuto=0;
	private  int mWindDir=1;
	private  int mWindCount=2;
	
	
	
	public AirData(int codeType, int mPower, int mTmp, int mMode,
			int mWindAutoDir, int mWindDir, int mWindCount) {
		super();
		this.setCodeType(codeType);
		this.mPower = mPower;
		this.mTmp = mTmp;
		this.mMode = mMode;
		this.mWindAuto = mWindAutoDir;
		this.mWindDir = mWindDir;
		this.mWindCount = mWindCount;
	}
	
	public AirData() {
		super();
		
	}
	public  int getmTmp() {
		return mTmp;
	}
	public  void setmTmp(int mTmp) {
		this.mTmp = mTmp;
	}
	public  int addTmp(int mTmp) {
		mTmp++;
		if (mTmp>35){
			mTmp= 35;
		}
		return mTmp;
	}
	public  int subTmp(int mTmp) {
		mTmp--;
		if (mTmp<18){
			mTmp= 18;
		}
		return mTmp;
	}
	public  int getmPower() {
		return mPower;
	}
	public  void setmPower(int mPower) {
		this.mPower = mPower;
	}
	public  int getmMode() {
		return mMode;
	}
	public  void setmMode(int mMode) {
		this.mMode = mMode;
	}
	public  int getmWindAuto() {
		return mWindAuto;
	}
	public  void setmWindAuto(int mWindAutoDir) {
		this.mWindAuto = mWindAutoDir;
	}
	public  int getmWindDir() {
		return mWindDir;
	}
	public  void setmWindDir(int mWindDir) {
		this.mWindDir = mWindDir;
	}
	public  int getmWindCount() {
		return mWindCount;
	}
	public  void setmWindCount(int mWindCount) {
		this.mWindCount = mWindCount;
	}
	public int getCodeType() {
		return codeType;
	}
	public void setCodeType(int codeType) {
		this.codeType = codeType;
	}
	
	
}
