package com.sommer.data;


public class CodeType {
	String codeTypeIndex;
	int type;
	String form;
	public int getType() {
		return type;
	}
	public void setType(int type) {
		this.type = type;
	}
	public String getForm() {
		return form;
	}
	public void setForm(String form) {
		this.form = form;
	}
	public String getCodeTypeIndex() {
		return codeTypeIndex;
	}
	public void setCodeTypeIndex(String codeTypeIndex) {
		this.codeTypeIndex = codeTypeIndex;
	}
	public String getCodeType(){
		
		String codeType = codeTypeIndex +String.valueOf(type) +form;
		return codeType;
	}
	
}
