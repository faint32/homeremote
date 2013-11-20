#include <jni.h>
#include <string.h>
#include <fcntl.h>
#include "logo.h"
#include "AirEncode.h"

//#define DEBUG
//#define EETEST

int dataLen;
//int bitLen[64];
unsigned char bits[240];
unsigned char form[64];
unsigned char data[64];
unsigned char tempData[124];
unsigned char airSendData[128];

unsigned char airData[120];
#define		REMOTE_SEND_1		0x51
#define SPECIAL_Airet	0x00
#define LOGIC_Airet	0x01
#define END_Airet	0x02

char airRemoteEncode_all(char* airData) {
	char i, length;
	char formLength;
	LOGD("type  all encode ");
	memcpy(tempData,airData,120);
	timeShiftF(airData, tempData);
	length =  117;

	
#ifdef EETEST
	for (i = 0; i < length; i++) {
		LOGD("second tempData[%d] ============> 0x%x ", i, tempData[i]);
	}
#endif
	return length = WrapUpSendData(airSendData, tempData, REMOTE_SEND_1, length);

}




char airRemoteEncode_00(char* airData) {
	char i, length;

	char formLength;
	char dataLenFul;
	char dataLenOdd;
	char dataLen = 0;
	char len;
	timeShift(airData, tempData);

	formLength = 19;
	dataLenFul = airData[25] / 8;
	dataLenOdd = airData[25] % 8;
	dataLen = 0;
	if (dataLenOdd > 0) {
		dataLen = dataLenFul + 1;
	} else {
		dataLen = dataLenFul;
	}

	for (i = 0; i < dataLen; i++) {
		data[i] = airData[i + 29];
	}

	dataLen = airDataToBitsTypeR(bits, data, 1, dataLenFul, dataLenOdd);

	LOGD("type  0x00 encode ");
	bits[0] = 3;
	dataLen++;
	bits[dataLen] = 1;
	dataLen++;
	bits[dataLen] = 0;
	dataLen++;
	dataLen = compressData(tempData, bits, dataLen, formLength);
	length = dataLen + formLength;
	//repeat times
	tempData[length] = 1;
	length++;
#ifdef EETEST
	for (i = 0; i < length; i++) {

		LOGD("second tempData[%d] ============> 0x%x ", i, tempData[i]);
	}
#endif
	return length = WrapUpSendData(airSendData, tempData, REMOTE_SEND_1, length);

}
char airRemoteEncode_01(char* airData) {
	char i, length;
	char formLength;
	char dataLenFul;
	char dataLenOdd;
	char dataLen = 0;
	char len;
	char dataIndex = 0;
	timeShift(airData, tempData);

	formLength = 19;
	dataLenFul = airData[25] / 8;
	dataLenOdd = airData[25] % 8;
	dataLen = 0;
	if (dataLenOdd > 0) {
		dataLen = dataLenFul + 1;
	} else {
		dataLen = dataLenFul;
	}

	for (i = 0; i < dataLen; i++) {
		data[i] = airData[i + 29];
	}

	dataLen = airDataToBitsTypeR(bits, data, 1, dataLenFul, dataLenOdd);

	LOGD("type  0x01 encode ");
	bits[0] = 3;
	dataLen++;
	bits[dataLen] = 4;
	dataLen++;
	bits[dataLen] = 1;
	dataLen++;
	bits[dataLen] = 0;
	dataLen++;
	dataLen = compressData(tempData, bits, dataLen, formLength);
	length = dataLen + formLength;
	//repeat times
	tempData[length] = 1;
	length++;
#ifdef EETEST
	for (i = 0; i < length; i++) {

		LOGD("second tempData[%d] ============> 0x%x ", i, tempData[i]);
	}
#endif
	return length = WrapUpSendData(airSendData, tempData, REMOTE_SEND_1, length);
}
char airRemoteEncode_02(char* airData) {
	char i, length;
	char formLength;
	char dataLenFul;
	char dataLenOdd;
	char dataLen = 0;
	char len;
	char dataIndex = 0;
	LOGD("type  0x02 encode ");
	
	timeShiftE(airData, tempData);
	formLength = 20;
	length = 20;
	dataIndex = 29;


	tempData[length]=SPECIAL_Airet;
	length++;
	tempData[length]=1;
	length++;
	tempData[length]=0<<2;
	length++;
	dataLenFul = airData[25] / 8;
	dataLenOdd = airData[25] % 8;
	tempData[length]=LOGIC_Airet;
	length++;
	tempData[length]=dataLenFul;
	length++;
	tempData[length]=dataLenOdd;
	length++;
	
	if (dataLenOdd > 0) {
		dataLen = dataLenFul + 1;
	} else {
		dataLen = dataLenFul;
	}
	for (i = 0; i < dataLen; i++) {
		tempData[length+i] = airData[i + dataIndex];
	}
	dataIndex += dataLen;
	length +=dataLen;
	
	tempData[length]=SPECIAL_Airet;
	length++;
	tempData[length]=2;
	length++;
	tempData[length]=1<<2;
	length++;
	tempData[length]=0<<2;
	length++;
	dataLenFul = airData[26] / 8;
	dataLenOdd = airData[26] % 8;
	tempData[length]=LOGIC_Airet;
	length++;
	tempData[length]=dataLenFul;
	length++;
	tempData[length]=dataLenOdd;
	length++;
	
	if (dataLenOdd > 0) {
		dataLen = dataLenFul + 1;
	} else {
		dataLen = dataLenFul;
	}
	for (i = 0; i < dataLen; i++) {
		tempData[length+i] = airData[i + dataIndex];
	}
	length +=dataLen;
	tempData[length]=SPECIAL_Airet;
	length++;
	tempData[length]=1;
	length++;
	tempData[length]=1<<2;
	length++;
	tempData[length]=END_Airet;
	length++;
#ifdef EETEST
	for (i = 0; i < length; i++) {
		LOGD("second tempData[%d] ============> 0x%x ", i, tempData[i]);
	}
#endif
	return length = WrapUpSendData(airSendData, tempData, REMOTE_SEND_1, length);

}

char airRemoteEncode_06(char* airData) {
	char i, length;
	char formLength;
	char dataLenFul;
	char dataLenOdd;
	char dataLen = 0;
	char len;
	char dataIndex = 0;
	LOGD("type  0x06 encode ");
	timeShift(airData, tempData);
	formLength = 19;
	length = 0;
	dataIndex = 29;
	dataLenFul = airData[25] / 8;
	dataLenOdd = airData[25] % 8;
	if (dataLenOdd > 0) {
		dataLen = dataLenFul + 1;
	} else {
		dataLen = dataLenFul;
	}
	for (i = 0; i < dataLen; i++) {
		data[i] = airData[i + dataIndex];
	}
	dataIndex += dataLen;
	bits[length] = 3;
	length++;
	len = airDataToBitsTypeR(bits, data, length, dataLenFul, dataLenOdd);
	length += len;
	dataLenFul = airData[26] / 8;
	dataLenOdd = airData[26] % 8;
	if (dataLenOdd > 0) {
		dataLen = dataLenFul + 1;
	} else {
		dataLen = dataLenFul;
	}
	for (i = 0; i < dataLen; i++) {
		data[i] = airData[i + dataIndex];
	}
	dataIndex += dataLen;
	bits[length] = 3;
	length++;
	len = airDataToBitsTypeR(bits, data, length, dataLenFul, dataLenOdd);
	length += len;
	bits[length] = 3;
	length++;
	bits[length] = 4;
	length++;
	dataLenFul = airData[27] / 8;
	dataLenOdd = airData[27] % 8;
	if (dataLenOdd > 0) {
		dataLen = dataLenFul + 1;
	} else {
		dataLen = dataLenFul;
	}
	for (i = 0; i < dataLen; i++) {
		data[i] = airData[i + dataIndex];
	}
	dataIndex += dataLen;
	bits[length] = 3;
	length++;
	len = airDataToBitsTypeR(bits, data, length, dataLenFul, dataLenOdd);
	length += len;

	dataLenFul = airData[28] / 8;
	dataLenOdd = airData[28] % 8;
	if (dataLenOdd > 0) {
		dataLen = dataLenFul + 1;
	} else {
		dataLen = dataLenFul;
	}
	for (i = 0; i < dataLen; i++) {
		data[i] = airData[i + dataIndex];
	}
	dataIndex += dataLen;
	bits[length] = 3;
	length++;
	len = airDataToBitsTypeR(bits, data, length, dataLenFul, dataLenOdd);
	length += len;
	bits[length] = 3;
	length++;
	bits[length] = 1;
	length++;
	bits[length] = 0;
	length++;
	len = compressData(tempData, bits, length, formLength);
	length = len + formLength;
	//repeat times
	tempData[length] = 1;
	length++;
	return length = WrapUpSendData(airSendData, tempData, REMOTE_SEND_1, length);

}

char airRemoteEncode_07(char* airData) {
		char i, length;
	char formLength,dataLenFul,dataLenOdd,dataIndex;
	char dataLen = 0;
	char len;
	
	dataLen=timeShiftAIR(airData, tempData);
	dataIndex = 33;

	formLength = tempData[3]+3;
	length = formLength;
	tempData[length]=SPECIAL_Airet;
	length++;
	tempData[length]=1;
	length++;
	tempData[length]=0<<2;
	length++;
	dataLenFul = airData[25] / 8;
	dataLenOdd = airData[25] % 8;
	tempData[length]=LOGIC_Airet;
	length++;
	tempData[length]=dataLenFul;
	length++;
	tempData[length]=dataLenOdd;
	length++;
	
	if (dataLenOdd > 0) {
		dataLen = dataLenFul + 1;
	} else {
		dataLen = dataLenFul;
	}
	for (i = 0; i < dataLen; i++) {
		tempData[length+i] = airData[i + dataIndex];
	}
	dataIndex += dataLen;
	length +=dataLen;
	
	tempData[length]=SPECIAL_Airet;
	length++;
	tempData[length]=2;
	length++;
	tempData[length]=1<<2;
	length++;
	tempData[length]=0<<2;
	length++;
	dataLenFul = airData[26] / 8;
	dataLenOdd = airData[26] % 8;
	tempData[length]=LOGIC_Airet;
	length++;
	tempData[length]=dataLenFul;
	length++;
	tempData[length]=dataLenOdd;
	length++;
	
	if (dataLenOdd > 0) {
		dataLen = dataLenFul + 1;
	} else {
		dataLen = dataLenFul;
	}
	for (i = 0; i < dataLen; i++) {
		tempData[length+i] = airData[i + dataIndex];
	}
	dataIndex += dataLen;
	length +=dataLen;
	tempData[length]=SPECIAL_Airet;
	length++;
	tempData[length]=2;
	length++;
	tempData[length]=1<<2;
	length++;
	tempData[length]=0<<2;
	length++;
	dataLenFul = airData[27] / 8;
	dataLenOdd = airData[27] % 8;
	tempData[length]=LOGIC_Airet;
	length++;
	tempData[length]=dataLenFul;
	length++;
	tempData[length]=dataLenOdd;
	length++;
	
	if (dataLenOdd > 0) {
		dataLen = dataLenFul + 1;
	} else {
		dataLen = dataLenFul;
	}
	for (i = 0; i < dataLen; i++) {
		tempData[length+i] = airData[i + dataIndex];
	}
	length +=dataLen;
	tempData[length]=SPECIAL_Airet;
	length++;
	tempData[length]=1;
	length++;
	tempData[length]=1<<2;
	length++;
	tempData[length]=END_Airet;
	length++;
#ifdef EETEST
	for (i = 0; i < length; i++) {
		LOGD("second tempData[%d] ============> 0x%x ", i, tempData[i]);
	}
#endif
	return length = WrapUpSendData(airSendData, tempData, REMOTE_SEND_1, length);
}

char airRemoteEncode_09(char* airData) {
			char i, length;
	char formLength,dataLenFul,dataLenOdd,dataIndex;
	char dataLen = 0;
	char len;
	
	dataLen=timeShiftAIR(airData, tempData);
	dataIndex = 33;

	formLength = tempData[3]+3;
	length = formLength;
	tempData[length]=SPECIAL_Airet;
	length++;
	tempData[length]=1;
	length++;
	tempData[length]=0<<2;
	length++;
	dataLenFul = airData[25] / 8;
	dataLenOdd = airData[25] % 8;
	tempData[length]=LOGIC_Airet;
	length++;
	tempData[length]=dataLenFul;
	length++;
	tempData[length]=dataLenOdd;
	length++;
	
	if (dataLenOdd > 0) {
		dataLen = dataLenFul + 1;
	} else {
		dataLen = dataLenFul;
	}
	for (i = 0; i < dataLen; i++) {
		tempData[length+i] = airData[i + dataIndex];
	}
	dataIndex += dataLen;
	length +=dataLen;
	
	tempData[length]=SPECIAL_Airet;
	length++;
	tempData[length]=2;
	length++;
	tempData[length]=1<<2;
	length++;
	tempData[length]=0<<2;
	length++;
	dataLenFul = airData[26] / 8;
	dataLenOdd = airData[26] % 8;
	tempData[length]=LOGIC_Airet;
	length++;
	tempData[length]=dataLenFul;
	length++;
	tempData[length]=dataLenOdd;
	length++;
	
	if (dataLenOdd > 0) {
		dataLen = dataLenFul + 1;
	} else {
		dataLen = dataLenFul;
	}
	for (i = 0; i < dataLen; i++) {
		tempData[length+i] = airData[i + dataIndex];
	}
	dataIndex += dataLen;
	length +=dataLen;
	tempData[length]=SPECIAL_Airet;
	length++;
	tempData[length]=2;
	length++;
	tempData[length]=1<<2;
	length++;
	tempData[length]=0<<2;
	length++;
	dataLenFul = airData[27] / 8;
	dataLenOdd = airData[27] % 8;
	tempData[length]=LOGIC_Airet;
	length++;
	tempData[length]=dataLenFul;
	length++;
	tempData[length]=dataLenOdd;
	length++;
	
	if (dataLenOdd > 0) {
		dataLen = dataLenFul + 1;
	} else {
		dataLen = dataLenFul;
	}
	for (i = 0; i < dataLen; i++) {
		tempData[length+i] = airData[i + dataIndex];
	}
	dataIndex += dataLen;
	length +=dataLen;

	tempData[length]=SPECIAL_Airet;
	length++;
	tempData[length]=2;
	length++;
	tempData[length]=1<<2;
	length++;
	tempData[length]=0<<2;
	length++;
	dataLenFul = airData[28] / 8;
	dataLenOdd = airData[28] % 8;
	tempData[length]=LOGIC_Airet;
	length++;
	tempData[length]=dataLenFul;
	length++;
	tempData[length]=dataLenOdd;
	length++;
	
	if (dataLenOdd > 0) {
		dataLen = dataLenFul + 1;
	} else {
		dataLen = dataLenFul;
	}
	for (i = 0; i < dataLen; i++) {
		tempData[length+i] = airData[i + dataIndex];
	}
	dataIndex += dataLen;
	length +=dataLen;

	tempData[length]=SPECIAL_Airet;
	length++;
	tempData[length]=2;
	length++;
	tempData[length]=1<<2;
	length++;
	tempData[length]=0<<2;
	length++;
	dataLenFul = airData[29] / 8;
	dataLenOdd = airData[29] % 8;
	tempData[length]=LOGIC_Airet;
	length++;
	tempData[length]=dataLenFul;
	length++;
	tempData[length]=dataLenOdd;
	length++;
	
	if (dataLenOdd > 0) {
		dataLen = dataLenFul + 1;
	} else {
		dataLen = dataLenFul;
	}
	for (i = 0; i < dataLen; i++) {
		tempData[length+i] = airData[i + dataIndex];
	}
	
	length +=dataLen;
	tempData[length]=SPECIAL_Airet;
	length++;
	tempData[length]=1;
	length++;
	tempData[length]=1<<2;
	length++;
	tempData[length]=END_Airet;
	length++;
#ifdef EETEST
	for (i = 0; i < length; i++) {
		LOGD("second tempData[%d] ============> 0x%x ", i, tempData[i]);
	}
#endif
	return length = WrapUpSendData(airSendData, tempData, REMOTE_SEND_1, length);

}


char airRemoteEncode_0a(char* airData) {
			char i, length;
	char formLength,dataLenFul,dataLenOdd,dataIndex;
	char dataLen = 0;
	char len;
	
	dataLen=timeShiftAIR(airData, tempData);
	dataIndex = 33;

	formLength = tempData[3]+3;
	length = formLength;
	tempData[length]=SPECIAL_Airet;
	length++;
	tempData[length]=1;
	length++;
	tempData[length]=0<<2;
	length++;
	dataLenFul = airData[25] / 8;
	dataLenOdd = airData[25] % 8;
	tempData[length]=LOGIC_Airet;
	length++;
	tempData[length]=dataLenFul;
	length++;
	tempData[length]=dataLenOdd;
	length++;
	
	if (dataLenOdd > 0) {
		dataLen = dataLenFul + 1;
	} else {
		dataLen = dataLenFul;
	}
	for (i = 0; i < dataLen; i++) {
		tempData[length+i] = airData[i + dataIndex];
	}
	dataIndex += dataLen;
	length +=dataLen;
	
	tempData[length]=SPECIAL_Airet;
	length++;
	tempData[length]=2;
	length++;
	tempData[length]=1<<2;
	length++;
	tempData[length]=0<<2;
	length++;
	dataLenFul = airData[26] / 8;
	dataLenOdd = airData[26] % 8;
	tempData[length]=LOGIC_Airet;
	length++;
	tempData[length]=dataLenFul;
	length++;
	tempData[length]=dataLenOdd;
	length++;
	
	if (dataLenOdd > 0) {
		dataLen = dataLenFul + 1;
	} else {
		dataLen = dataLenFul;
	}
	for (i = 0; i < dataLen; i++) {
		tempData[length+i] = airData[i + dataIndex];
	}
	dataIndex += dataLen;
	length +=dataLen;
	tempData[length]=SPECIAL_Airet;
	length++;
	tempData[length]=2;
	length++;
	tempData[length]=1<<2;
	length++;
	tempData[length]=0<<2;
	length++;
	dataLenFul = airData[27] / 8;
	dataLenOdd = airData[27] % 8;
	tempData[length]=LOGIC_Airet;
	length++;
	tempData[length]=dataLenFul;
	length++;
	tempData[length]=dataLenOdd;
	length++;
	
	if (dataLenOdd > 0) {
		dataLen = dataLenFul + 1;
	} else {
		dataLen = dataLenFul;
	}
	for (i = 0; i < dataLen; i++) {
		tempData[length+i] = airData[i + dataIndex];
	}
	dataIndex += dataLen;
	length +=dataLen;

	tempData[length]=SPECIAL_Airet;
	length++;
	tempData[length]=2;
	length++;
	tempData[length]=1<<2;
	length++;
	tempData[length]=0<<2;
	length++;
	dataLenFul = airData[28] / 8;
	dataLenOdd = airData[28] % 8;
	tempData[length]=LOGIC_Airet;
	length++;
	tempData[length]=dataLenFul;
	length++;
	tempData[length]=dataLenOdd;
	length++;
	
	if (dataLenOdd > 0) {
		dataLen = dataLenFul + 1;
	} else {
		dataLen = dataLenFul;
	}
	for (i = 0; i < dataLen; i++) {
		tempData[length+i] = airData[i + dataIndex];
	}
	dataIndex += dataLen;
	length +=dataLen;

	tempData[length]=SPECIAL_Airet;
	length++;
	tempData[length]=2;
	length++;
	tempData[length]=1<<2;
	length++;
	tempData[length]=0<<2;
	length++;
	dataLenFul = airData[29] / 8;
	dataLenOdd = airData[29] % 8;
	tempData[length]=LOGIC_Airet;
	length++;
	tempData[length]=dataLenFul;
	length++;
	tempData[length]=dataLenOdd;
	length++;
	
	if (dataLenOdd > 0) {
		dataLen = dataLenFul + 1;
	} else {
		dataLen = dataLenFul;
	}
	for (i = 0; i < dataLen; i++) {
		tempData[length+i] = airData[i + dataIndex];
	}
	dataIndex += dataLen;
	length +=dataLen;

	tempData[length]=SPECIAL_Airet;
	length++;
	tempData[length]=2;
	length++;
	tempData[length]=1<<2;
	length++;
	tempData[length]=0<<2;
	length++;
	dataLenFul = airData[30] / 8;
	dataLenOdd = airData[30] % 8;
	tempData[length]=LOGIC_Airet;
	length++;
	tempData[length]=dataLenFul;
	length++;
	tempData[length]=dataLenOdd;
	length++;
	
	if (dataLenOdd > 0) {
		dataLen = dataLenFul + 1;
	} else {
		dataLen = dataLenFul;
	}
	for (i = 0; i < dataLen; i++) {
		tempData[length+i] = airData[i + dataIndex];
	}
	length +=dataLen;
	tempData[length]=SPECIAL_Airet;
	length++;
	tempData[length]=1;
	length++;
	tempData[length]=1<<2;
	length++;
	tempData[length]=END_Airet;
	length++;
#ifdef EETEST
	for (i = 0; i < length; i++) {
		LOGD("second tempData[%d] ============> 0x%x ", i, tempData[i]);
	}
#endif
	return length = WrapUpSendData(airSendData, tempData, REMOTE_SEND_1, length);
}


char airRemoteEncode_10(char* airData) {
	char i, length;
	char formLength;
	char dataLenFul;
	char dataLenOdd;
	char dataLen = 0;
	char len;
	char dataIndex = 0;
	timeShiftB(airData, tempData);

	formLength = 19;
	dataLenFul = airData[25] / 8;
	dataLenOdd = airData[25] % 8;
	dataLen = 0;
	if (dataLenOdd > 0) {
		dataLen = dataLenFul + 1;
	} else {
		dataLen = dataLenFul;
	}

	for (i = 0; i < dataLen; i++) {
		data[i] = airData[i + 33];
	}

	dataLen = airDataToBitsTypeR(bits, data, 1, dataLenFul, dataLenOdd);

	LOGD("type  0x00 encode ");
	bits[0] = 3;
	dataLen++;
	bits[dataLen] = 2;
	dataLen++;
	bits[dataLen] = 0;
	dataLen++;
	dataLen = compressData(tempData, bits, dataLen, formLength);
	length = dataLen + formLength;
	//repeat times
	tempData[length] = 1;
	length++;
#ifdef EETEST
	for (i = 0; i < length; i++) {

		LOGD("second tempData[%d] ============> 0x%x ", i, tempData[i]);
	}
#endif
	return length = WrapUpSendData(airSendData, tempData, REMOTE_SEND_1, length);

}


char airRemoteEncode_85(char* airData) {
	char i, length;
	char formLength;
	char dataLenFul;
	char dataLenOdd;
	char dataLen = 0;
	char len;
	char tData[100];
	char dataIndex = 0;
	LOGD("type  0x06 encode ");
	timeShiftD(airData, tempData);
	length = 0;
	formLength = 27;
	dataIndex = 29;
	dataLenFul = airData[25] / 8;
	dataLenOdd = airData[25] % 8;
	if (dataLenOdd > 0) {
		dataLen = dataLenFul + 1;
	} else {
		dataLen = dataLenFul;
	}
	for (i = 0; i < dataLen; i++) {
		data[i] = airData[i + dataIndex];
	//	LOGD(" data[%d] ============> 0x%x ", i, data[i]);
	}
	dataIndex += dataLen;
	bits[length] = 5;
	length++;
	memset(tData,0x00,100);
	len = TCL2data2bits(tData,data,dataLen);
	if (tData[0]==0x00){
		LOGD(" fix head data");
		fixHeadTime(tempData);
		}
	len = TCLEdgeShiftLevel(bits, tData,length, len);

	length += len;
	

	dataLenFul = airData[26] / 8;
	dataLenOdd = airData[26] % 8;
	if (dataLenOdd > 0) {
		dataLen = dataLenFul + 1;
	} else {
		dataLen = dataLenFul;
	}
	for (i = 0; i < dataLen; i++) {
		data[i] = airData[i + dataIndex];
	}
	dataIndex += dataLen;
	bits[length] = 5;
	length++;
	memset(tData,0x00,100);
	len = TCL2data2bits(tData,data,dataLen);
	len = TCLEdgeShiftLevel(bits, tData,length, len);
	length += len;
	dataLenFul = airData[27] / 8;
	dataLenOdd = airData[27] % 8;
	if (dataLenOdd > 0) {
		dataLen = dataLenFul + 1;
	} else {
		dataLen = dataLenFul;
	}
	for (i = 0; i < dataLen; i++) {
		data[i] = airData[i + dataIndex];
	}
	dataIndex += dataLen;
	bits[length] = 5;
	length++;
	memset(tData,0x00,100);
	len = TCL2data2bits(tData,data,dataLen);
	if (bits[0]==0x01){
		fixHeadTime(tempData);
		}
	len = TCLEdgeShiftLevel(bits, tData,length, len);
	length += len;

	bits[length] = 6;
	length++;
	bits[length] = 0;
	length++;
	len = compressData(tempData, bits, length, formLength);
	length = len + formLength;
	//repeat times
	tempData[length] = 1;
	length++;
	#ifdef EETEST
	for (i = 0; i < length; i++) {

		LOGD("second tempData[%d] ============> 0x%x ", i, tempData[i]);
	}
#endif
	return length = WrapUpSendData(airSendData, tempData, REMOTE_SEND_1, length);

}

char airRemoteEncode_11(char* airData) {
	char i, length;
	char formLength;
	char dataLenFul;
	char dataLenOdd;
	char dataLen = 0;
	char len;
	char dataIndex = 0;
	timeShift(airData, tempData);

	formLength = 19;
	dataLenFul = airData[25] / 8;
	dataLenOdd = airData[25] % 8;
	dataLen = 0;
	if (dataLenOdd > 0) {
		dataLen = dataLenFul + 1;
	} else {
		dataLen = dataLenFul;
	}

	for (i = 0; i < dataLen; i++) {
		data[i] = airData[i + 33];
	}

	dataLen = airDataToBitsTypeR(bits, data, 1, dataLenFul, dataLenOdd);

	LOGD("type  0x01 encode ");
	bits[0] = 3;
	dataLen++;
	bits[dataLen] = 4;
	dataLen++;
	bits[dataLen] = 3;
	dataLen++;
	bits[dataLen] = 0;
	dataLen++;
	dataLen = compressData(tempData, bits, dataLen, formLength);
	length = dataLen + formLength;
	//repeat times
	tempData[length] = 1;
	length++;
#ifdef EETEST
	for (i = 0; i < length; i++) {

		LOGD("second tempData[%d] ============> 0x%x ", i, tempData[i]);
	}
#endif
	return length = WrapUpSendData(airSendData, tempData, REMOTE_SEND_1, length);
}

char airRemoteEncode_12(char* airData) {
	char i, length;
	char formLength;
	char dataLenFul;
	char dataLenOdd;
	char dataLen = 0;
	char len;
	char dataIndex = 0;
	LOGD("type  0x02 encode ");
	timeShiftB(airData, tempData);
	formLength = 19;
	length = 0;
	dataIndex = 33;
	dataLenFul = airData[25] / 8;
	dataLenOdd = airData[25] % 8;
	dataLen = 0;
	if (dataLenOdd > 0) {
		dataLen = dataLenFul + 1;
	} else {
		dataLen = dataLenFul;
	}
	for (i = 0; i < dataLen; i++) {
		data[i] = airData[i + dataIndex];
	}
	dataIndex += dataLen;
	bits[length] = 3;
	length++;
	len = airDataToBitsTypeR(bits, data, length, dataLenFul, dataLenOdd);
	length += len;
	bits[length] = 4;
	length++;
	dataLenFul = airData[26] / 8;
	dataLenOdd = airData[26] % 8;
	if (dataLenOdd > 0) {
		dataLen = dataLenFul + 1;
	} else {
		dataLen = dataLenFul;
	}
	for (i = 0; i < dataLen; i++) {
		data[i] = airData[i + dataIndex];
	}
	bits[length] = 3;
	length++;
	len = airDataToBitsTypeR(bits, data, length, dataLenFul, dataLenOdd);
	length += len;
	bits[length] = 2;
	length++;
	bits[length] = 0;
	length++;
	len = compressData(tempData, bits, length, formLength);
	length = len + formLength;
	//repeat times
	tempData[length] = 1;
	length++;
#ifdef EETEST
	for (i = 0; i < length; i++) {
		LOGD("second tempData[%d] ============> 0x%x ", i, tempData[i]);
	}
#endif
	return length = WrapUpSendData(airSendData, tempData, REMOTE_SEND_1, length);
}
char airRemoteEncode_20(char* airData) {
	char i, length;
	char formLength;
	char dataLenFul;
	char dataLenOdd;
	char dataLen = 0;
	char len;
	char dataIndex = 0;
	LOGD("type  0x20 encode ");
	timeShiftC(airData, tempData);
	formLength = 23;
	length = 0;
	dataIndex = 29;
	dataLenFul = airData[25] / 8;
	dataLenOdd = airData[25] % 8;
	dataLen = 0;
	if (dataLenOdd > 0) {
		dataLen = dataLenFul + 1;
	} else {
		dataLen = dataLenFul;
	}
	for (i = 0; i < dataLen; i++) {
		data[i] = airData[i + dataIndex];
	}
	dataIndex += dataLen;
	bits[length] = 5;
	length++;
	bits[length] = 3;
	length++;
	len = airDataToBitsTypeR(bits, data, length, dataLenFul, dataLenOdd);
	length += len;
	bits[length] = 1;
	length++;
	bits[length] = 0;
	length++;
	len = compressData(tempData, bits, length, formLength);
	length = len + formLength;
	//repeat times
	tempData[length] = 1;
	length++;
#ifdef EETEST
	for (i = 0; i < length; i++) {
		LOGD("second tempData[%d] ============> 0x%x ", i, tempData[i]);
	}
#endif
	return length = WrapUpSendData(airSendData, tempData, REMOTE_SEND_1, length);
}

char airRemoteEncode_21(char* airData) {
		char i, length;
	char formLength;
	char dataLen = 0;
	char len;
	dataLen=timeShiftAIR(airData, tempData,3);

	formLength = tempData[2];
	
	for (i = 0; i < dataLen; i++) {
		tempData[formLength+i] = airData[i + 29];
	}

	length = formLength + dataLen;
	//repeat times
	tempData[length] = 1;
	length++;
#ifdef EETEST
	for (i = 0; i < length; i++) {

		LOGD("second tempData[%d] ============> 0x%x ", i, tempData[i]);
	}
#endif
	return length = WrapUpSendData(airSendData, tempData, REMOTE_SEND_1, length);
}

char airRemoteEncode_22(char* airData) {
	char i, length;
	char formLength;
	char dataLenFul;
	char dataLenOdd;
	char dataLen = 0;
	char len;
	char dataIndex = 0;
	LOGD("type  0x22 encode ");
	timeShift(airData, tempData);
	formLength = 19;
	length = 0;
	dataIndex = 29;
	dataLenFul = airData[25] / 8;
	dataLenOdd = airData[25] % 8;
	dataLen = 0;
	if (dataLenOdd > 0) {
		dataLen = dataLenFul + 1;
	} else {
		dataLen = dataLenFul;
	}
	for (i = 0; i < dataLen; i++) {
		data[i] = airData[i + dataIndex];
	}
	dataIndex += dataLen;
	bits[length] = 3;
	length++;
	len = airDataToBitsTypeR(bits, data, length, dataLenFul, dataLenOdd);
	length += len;
	bits[length] = 4;
	length++;
	dataLenFul = airData[26] / 8;
	dataLenOdd = airData[26] % 8;
	if (dataLenOdd > 0) {
		dataLen = dataLenFul + 1;
	} else {
		dataLen = dataLenFul;
	}
	for (i = 0; i < dataLen; i++) {
		data[i] = airData[i + dataIndex];
	}
	len = airDataToBitsTypeR(bits, data, length, dataLenFul, dataLenOdd);
	length += len;
	bits[length] = 1;
	length++;
	bits[length] = 0;
	length++;
	len = compressData(tempData, bits, length, formLength);
	length = len + formLength;
	//repeat times
	tempData[length] = 1;
	length++;
#ifdef EETEST
	for (i = 0; i < length; i++) {
		LOGD("second tempData[%d] ============> 0x%x ", i, tempData[i]);
	}
#endif
	return length = WrapUpSendData(airSendData, tempData, REMOTE_SEND_1, length);

}

char airRemoteEncode_32(char* airData) {
	char i, length;
	char formLength;
	char dataLenFul;
	char dataLenOdd;
	char dataLen = 0;
	char len;
	char dataIndex = 0;
	LOGD("type  0x32 encode ");
	timeShiftC(airData, tempData);
	formLength = 23;
	length = 0;
	dataIndex = 29;
	dataLenFul = airData[25] / 8;
	dataLenOdd = airData[25] % 8;
	dataLen = 0;
	if (dataLenOdd > 0) {
		dataLen = dataLenFul + 1;
	} else {
		dataLen = dataLenFul;
	}
	for (i = 0; i < dataLen; i++) {
		data[i] = airData[i + dataIndex];
	}
	dataIndex += dataLen;
	bits[length] = 5;
	length++;
	bits[length] = 3;
	length++;
	len = airDataToBitsTypeR(bits, data, length, dataLenFul, dataLenOdd);
	length += len;
	bits[length] = 4;
	length++;
	dataLenFul = airData[26] / 8;
	dataLenOdd = airData[26] % 8;
	if (dataLenOdd > 0) {
		dataLen = dataLenFul + 1;
	} else {
		dataLen = dataLenFul;
	}
	for (i = 0; i < dataLen; i++) {
		data[i] = airData[i + dataIndex];
	}
	bits[length] = 5;
	length++;
	bits[length] = 3;
	length++;
	len = airDataToBitsTypeR(bits, data, length, dataLenFul, dataLenOdd);
	length += len;
	bits[length] = 1;
	length++;
	bits[length] = 0;
	length++;
	len = compressData(tempData, bits, length, formLength);
	length = len + formLength;
	//repeat times
	tempData[length] = 1;
	length++;
#ifdef EETEST
	for (i = 0; i < length; i++) {
		LOGD("second tempData[%d] ============> 0x%x ", i, tempData[i]);
	}
#endif
	return length = WrapUpSendData(airSendData, tempData, REMOTE_SEND_1, length);

}

int airRemoteEncode(char* airData) {
	char i, length;
	char airType = airData[12];
	if (airData[0] == 0x7f) {
		switch (airType) {
		case 0x00:
			length = airRemoteEncode_00(airData);
			break;
		case 0x01:
			length = airRemoteEncode_01(airData);
			break;
		case 0x02:
			length = airRemoteEncode_02(airData);
			break;
		case 0x06:
			length = airRemoteEncode_06(airData);
			break;
		case 0x07:
			length = airRemoteEncode_07(airData);
			break;
		case 0x09:
			length = airRemoteEncode_09(airData);
			break;
		case 0x0a:
			length = airRemoteEncode_0a(airData);
			break;
		case 0x10:
			length = airRemoteEncode_10(airData);
			break;
		case 0x11:
			length = airRemoteEncode_11(airData);
			break;
		case 0x12:
			length = airRemoteEncode_12(airData);
			break;
		case 0x20:
			length = airRemoteEncode_20(airData);
			break;
		case 0x22:
			length = airRemoteEncode_22(airData);
			break;
		case 0x32:
			length = airRemoteEncode_32(airData);
			break;
		case 0x85:
			length = airRemoteEncode_85(airData);
			break;
		default:
			length = airRemoteEncode_00(airData);
			break;
		}
	} 
	else if (airData[0] == 0x7e) {
		length = airRemoteEncode_all(airData);
	}else if (airData[0] == 0x03) {
		data[0] = airData[1];
		data[1] = airData[2];
		data[2] = airData[3];
		length = remoteEncode_NEC6122_C1(airSendData,data);
	}else {
		length = airRemoteEncode_00(airData);
		}

	return length;
}

jbyteArray Java_com_deco_ircore_RemoteCommunicate_getAirData(JNIEnv* env, jobject jobj,
		jintArray data) {
	AIR_status airStatus;
//	unsigned char airDatas[20];
	int i, length = 128;
	unsigned char err;
	int* airDatas = (int*) (*env)->GetIntArrayElements(env, data, NULL);

	airStatus.nAirCode = airDatas[0];
	if (airDatas[1] > 2) {
		airStatus.vPower = 0;
	} else {
		airStatus.vPower = airDatas[1];
	}
	if (airDatas[2] > 5) {
		airStatus.vMode = 0;
	} else {
		airStatus.vMode = airDatas[2];
	}
	if (airDatas[3] > 4) {
		airStatus.vSpeed = 0;
	} else {
		airStatus.vSpeed = airDatas[3];
	}
	airDatas[4] = airDatas[4] - 16;
	if (airDatas[4] > 15) {
		airStatus.vTemper = 0;
	} else {
		airStatus.vTemper = airDatas[4];
	}
	if (airDatas[5] > 2) {
		airStatus.vWind = 0;
	} else {
		airStatus.vWind = airDatas[5];
	}
	if (airDatas[6] > 4) {
		airStatus.vManualWind = 0;
	} else {
		airStatus.vManualWind = airDatas[6];
	}
	if (airDatas[7] > 7) {
		airStatus.vKey = 0;
	} else {
		airStatus.vKey = airDatas[7];
	}

#ifdef DEBUG
	LOGD("aircode ----> %d ", airStatus.nAirCode);
	LOGD("vPower ----> %d ", airStatus.vPower);
	LOGD("vMode ----> %d ", airStatus.vMode);
	LOGD("vSpeed ----> %d ", airStatus.vSpeed);
	LOGD("vTemper ----> %d  ", airStatus.vTemper);
	LOGD("vWind ----> %d  ", airStatus.vWind);
	LOGD("vManualWind ----> %d ", airStatus.vManualWind);
	LOGD("vKey ----> %d ", airStatus.vKey);
#endif
	err = HandleAirRemote(airStatus, airData);
//	if (err == 0xff) {
//		LOGD("encode error ----> %d ", airStatus.nAirCode);
//	}
//	for (i = 0; i < 80; i++) {
//		LOGD("airData[%d ] ----> 0x%x ", i, airData[i]);
//	}

	length = airRemoteEncode(airData);

	jbyteArray byteArray = (*env)->NewByteArray(env, length);

	(*env)->SetByteArrayRegion(env, byteArray, 0, length, (jbyte*) airSendData);

	return byteArray;

}

