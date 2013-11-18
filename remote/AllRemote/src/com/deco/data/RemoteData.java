package com.deco.data;



public class RemoteData {
	String index;
	String codetype;
	String mode;
	String custom;
	String data;
	
	
	public String getCodetype() {
		return codetype;
	}
	public void setCodetype(String codetype) {
		this.codetype = codetype;
	}
	public RemoteData() {
		super();
		// TODO Auto-generated constructor stub
	}
	public String getIndex() {
		return index;
	}
	public void setIndex(String index) {
		this.index = index;
	}
	
	public String getMode() {
		return mode;
	}
	public void setMode(String mode) {
		this.mode = mode;
	}
	
	public String getCustom() {
		return custom;
	}
	public void setCustom(String custom) {
		this.custom = custom;
	}
	public String getData() {
		return data;
	}
	public void setData(String data) {
		this.data = data;
	}
	
	
	public String getRemoteDataInfo(){
		return 	"index --->" +this.index
				+"  codetype --->" +this.codetype
				+"  mode --->" +this.mode
				+"  custom --->" +this.custom
				+"  data --->" +this.data	;
		}
	
}
