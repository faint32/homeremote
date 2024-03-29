package com.deco.data;

public class RemoteDevice {
	private int id;
	private int type;
	private String code;
	private String name ;
	private String brand ;
	private AirData airData;
	
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public int getType() {
		return type;
	}
	public void setType(int type) {
		this.type = type;
	}
	public String getCode() {
		return code;
	}
	public void setCode(String code) {
		this.code = code;
	}
	public String getBrand() {
		return brand;
	}
	public void setBrand(String brand) {
		this.brand = brand;
	}
	public String getInfo() {
		return   this.name+"   "
				 +Value.REMOTE_TYPE[this.type] +"   " + this.brand
				 +"   " +this.code ;
		
	}
	
	public String getFullInfo() {
		return   this.name+"   "
				 +Value.REMOTE_TYPE[this.type] +"   " + this.brand
				 +"   " +this.code ;
		
	}

	public String getShortInfo() {
		return   this.name+" \n  "
				 +Value.REMOTE_TYPE[this.type] ;
		
	}
	public AirData getAirData() {
		return airData;
	}
	public void setAirData(AirData airData) {
		this.airData = airData;
	}
	
}
