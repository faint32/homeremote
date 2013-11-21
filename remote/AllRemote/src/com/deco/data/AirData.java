package com.deco.data;


public class AirData {
	
	private  int code = 0;
	private  int mPower=1;
	private  int mTmp=25;
	private  int mMode=1;
	private  int mWindAuto=0;
	private  int mWindDir=1;
	private  int mWindCount=2;
	private  int mkey =0;
	
	
	
	
	
	public AirData(int code, int mPower, int mTmp, int mMode,
			int mWindAuto, int mWindDir, int mWindCount, int mkey) {
		super();
	
		this.code = code;
		this.mPower = mPower;
		this.mTmp = mTmp;
		this.mMode = mMode;
		this.mWindAuto = mWindAuto;
		this.mWindDir = mWindDir;
		this.mWindCount = mWindCount;
		this.mkey = mkey;
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
		if (mTmp>30){
			mTmp= 30;
		}
		return mTmp;
	}
	public  int subTmp(int mTmp) {
		mTmp--;
		if (mTmp<16){
			mTmp= 16;
		}
		return mTmp;
	}
	
	
	
	public int getMkey() {
		return mkey;
	}

	public void setMkey(int mkey) {
		this.mkey = mkey;
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
	public int getCode() {
		return code;
	}
	public void setCode(int code) {
		this.code = code;
	}
	public String getInfo() {
		return   "code==>" + this.code+"   "
				 +"power==>" + this.mPower+"   " 
				 +"mMode==>"+ this.mMode +"   " 
				 +"mWindAuto==>"+ this.mWindAuto +"   " 
				 +"mWindDir==>"+ this.mWindDir +"   " 
				 +"mWindCount==>"+ this.mWindCount +"   " 
				 +"mkey==>"+ this.mkey +"   " ;
		
	}
	
	
}
