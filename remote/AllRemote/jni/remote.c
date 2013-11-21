/*
 * remote.c
 *
 *  Created on: 2013-10-17
 *      Author: work
 */
#include "remote.h"
#include <string.h>
#include "logo.h"

#define		REMOTE_SEND_1		0x51
#define		REMOTE_SEND_2		0x52
#define		REMOTE_SEND_3		0x53

unsigned char bits[240];

char tempData[128];

char codeData[4];
char bitLen[32];
char dataLen;




int remoteEncode_LC7461M_PANASONIC(char* sendData,char* code){
	char codeData[6];
	int i,length;
	#ifdef DEBUG
	LOGD("code type ======= LC7461M_PANASONIC ");
	#endif
	
	codeData[1] = *code++;
	
	codeData[0] = *code++;
	codeData[3] = *code++;
	codeData[2] = *code++;
	codeData[5] = *code++;
	codeData[4] = *code++;
	
	length =  sizeof(LC7461M_PANASONIC);
			//get fix form frame data
	
	memcpy(tempData,LC7461M_PANASONIC,length);

	//get remote custom&data get code length

	bitLen[0] = 8;
	bitLen[1] = 8;
	bitLen[2] = 8;
	bitLen[3] = 8;
	bitLen[4] = 8;
	bitLen[5] = 8;

			//decode all bits data
	bits[0]=3;		//head frame
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,1,6); //data frame
	dataLen++;
	bits[dataLen]=4;		//finish frame
	dataLen++;
	bits[dataLen]=0;		//end frame
	dataLen++;

	dataLen=compressData(tempData,bits,dataLen,length);

	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);

	return length;
}

int remoteEncode_LC7461F_C1(char* sendData,char* code){
	int i,length;
	#ifdef DEBUG
	LOGD("code type =======> LC7461F_C1 ");
	#endif

	codeData[1] = *code++;
	codeData[0] = *code++;
	codeData[3] = *code++;
	codeData[2] = *code++;
	codeData[4] = *code++;
	codeData[5] = ~codeData[4];
	/*
  	for (i=0;i<6;i++){
	LOGD("code[%d] =======>0x%x ", i,codeData[i]);	
  		}
	*/
	length =  sizeof(LC7461F_C1);
	//get fix form frame data

	memcpy(tempData,LC7461F_C1,length);

	//	LOGD("sendData %d ----> 0x%x /n ",i,sendData[i]);

	//get remote custom&data get code length

		bitLen[0] = 8;
		bitLen[1] = 5;
		bitLen[2] = 8;
		bitLen[3] = 5;
		bitLen[4] = 8;
		bitLen[5] = 8;

	//decode all bits data
	bits[0]=3;		//head frame
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,1,6); //data frame
	dataLen++;
	bits[dataLen]=4;		//finish frame
	dataLen++;
	bits[dataLen]=0;		//end frame
	dataLen++;

	dataLen=compressData(tempData,bits,dataLen,length);

	length += dataLen;
	//repeat times
	tempData[length]=2;
	length ++;
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}


int remoteEncode_LC7461M_C13(char* sendData,char* code){

	int i,length;
	#ifdef DEBUG
	LOGD("code type ======= LC7461M_C13 ");
	#endif

	codeData[1] = *code++;
	codeData[0] = *code++;
	codeData[3] = *code++;
	codeData[2] = *code++;
	codeData[4] = *code++;
	codeData[5] = ~codeData[4];

	//get fix form frame data
	length =  sizeof(LC7461M_C13) / sizeof(char);

	memcpy(tempData,LC7461M_C13,length);

	//get remote custom&data get code length
	bitLen[0] = 8;
	bitLen[1] = 5;
	bitLen[2] = 8;
	bitLen[3] = 5;
	bitLen[4] = 8;
	bitLen[5] = 8;

			//decode all bits data
	bits[0]=3;		//head frame
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,1,6); //data frame
	dataLen++;
	bits[dataLen]=4;		//finish frame
	dataLen++;
	bits[dataLen]=3;		//repeat frame
	dataLen++;
	bits[dataLen]=4;		//repeat frame
	dataLen++;
	bits[dataLen]=0;		//end frame
	dataLen++;

	dataLen=compressData(tempData,bits,dataLen,length);



	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

	for (i=0;i<length;i++){

	   }
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}


int remoteEncode_NEC6122_C1(char* sendData,char* code){

	int i,length;
	#ifdef DEBUG
	LOGD("code type ======= NEC6122_C1 ");
	#endif
	codeData[0] = *code++;
	codeData[1] = *code++;
	codeData[2] = *code++;
	codeData[3] = ~codeData[2];
	//get fix form frame data
	length =  sizeof(NEC6122_C1) ;
	memcpy(tempData,NEC6122_C1,length);

	//get remote custom&data get code length
//	for (i=0;i<4;i++){
//
//		   LOGD("codeData [%d] ======= 0x%x ",i,codeData[i]);
//	   }

	bitLen[0] = 8;
	bitLen[1] = 8;
	bitLen[2] = 8;
	bitLen[3] = 8;
			//decode all bits data
	bits[0]=3;		//head frame
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,1,4); //data frame
	dataLen++;
	bits[dataLen]=4;		//finish frame
	dataLen++;
	bits[dataLen]=5;		//repeat frame
	dataLen++;
	bits[dataLen]=4;		//repeat frame
	dataLen++;
	bits[dataLen]=0;		//end frame
	dataLen++;
//	for (i=0;i<dataLen;i++){
//
//		   LOGD("bits [%d] ======= 0x%x ",i,bits[i]);
//	   }

	dataLen=compressData(tempData,bits,dataLen,length);

//	for (i=0;i<dataLen;i++){
//
//		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
//	   }


	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

//	for (i=0;i<length;i++){
//		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
//	   }
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}

int remoteEncode_TC9028_C1(char* sendData,char* code){

	int i,length;
	#ifdef DEBUG
	LOGD("code type ======= TC9028_C1 ");
	#endif
	codeData[0] = *code++;
	
	codeData[1] = *code++;
	codeData[2] = *code++;
	codeData[3] = ~codeData[2];
	//get fix form frame data
	length =  sizeof(TC9028_C1) ;
	memcpy(tempData,TC9028_C1,length);

	//get remote custom&data get code length
//	for (i=0;i<4;i++){
//
//		   LOGD("codeData [%d] ======= 0x%x ",i,codeData[i]);
//	   }

	bitLen[0] = 8;
	bitLen[1] = 8;
	bitLen[2] = 8;
	bitLen[3] = 8;
			//decode all bits data
	bits[0]=3;		//head frame
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,1,4); //data frame
	dataLen++;
	bits[dataLen]=4;		//finish frame
	dataLen++;
	bits[dataLen]=5;		//repeat frame
	dataLen++;
	bits[dataLen]=4;		//repeat frame
	dataLen++;
	bits[dataLen]=0;		//end frame
	dataLen++;
//	for (i=0;i<dataLen;i++){
//
//		   LOGD("bits [%d] ======= 0x%x ",i,bits[i]);
//	   }

	dataLen=compressData(tempData,bits,dataLen,length);

//	for (i=0;i<dataLen;i++){
//
//		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
//	   }


	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

//	for (i=0;i<length;i++){
//		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
//
//	   }
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}

int remoteEncode_TC9012_C1(char* sendData,char* code){

	int i,length;
	#ifdef DEBUG
	LOGD("code type ======= TC9012_C1 ");
	#endif
	codeData[0] = *code++;
	codeData[1] = *code++;
	codeData[2] = *code++;
	codeData[3] = ~codeData[2];
	//get fix form frame data
	length =  sizeof(TC9012_C1) ;
	memcpy(tempData,TC9012_C1,length);

	//get remote custom&data get code length
//	for (i=0;i<4;i++){
//
//		   LOGD("codeData [%d] ======= 0x%x ",i,codeData[i]);
//	   }

	bitLen[0] = 8;
	bitLen[1] = 8;
	bitLen[2] = 8;
	bitLen[3] = 8;
			//decode all bits data
	bits[0]=3;		//head frame
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,1,4); //data frame
	dataLen++;
	bits[dataLen]=4;		//finish frame
	dataLen++;
	bits[dataLen]=3;		//repeat frame
	dataLen++;
	bits[dataLen]=2;		//repeat frame
	dataLen++;
	bits[dataLen]=4;		//repeat frame
	dataLen++;
	bits[dataLen]=0;		//end frame
	dataLen++;
//	for (i=0;i<dataLen;i++){
//
//		   LOGD("bits [%d] ======= 0x%x ",i,bits[i]);
//	   }

	dataLen=compressData(tempData,bits,dataLen,length);

//	for (i=0;i<dataLen;i++){
//
//		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
//	   }


	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

//	for (i=0;i<length;i++){
//		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
//
//	   }
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}

int remoteEncode_MN6014W_C5D6_1(char* sendData,char* code){

	int i,length;
	#ifdef DEBUG
	LOGD("code type ======= MN6014W_C5D6_1 ");
	#endif
	codeData[0] = *code++;
	codeData[2] = *code++;
	codeData[1] = *code++;
	codeData[3] = ~codeData[1];
	//get fix form frame data
	length =  sizeof(MN6014W_C5D6_1) ;
	memcpy(tempData,MN6014W_C5D6_1,length);

	//get remote custom&data get code length
	for (i=0;i<4;i++){
		  
		   LOGD("codeData [%d] ======= 0x%x ",i,codeData[i]);
	   }

	bitLen[0] = 5;
	bitLen[1] = 6;
	bitLen[2] = 5;
	bitLen[3] = 6;
			//decode all bits data
	bits[0]=3;		//head frame
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,1,4); //data frame
	dataLen++;
	bits[dataLen]=4;		//finish frame
	dataLen++;
	bits[dataLen]=0;		//end frame
	dataLen++;
	for (i=0;i<dataLen;i++){
		  
		   LOGD("bits [%d] ======= 0x%x ",i,bits[i]);
	   }

	dataLen=compressData(tempData,bits,dataLen,length);

	for (i=0;i<dataLen;i++){
		  
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
	   }


	length += dataLen;
	//repeat times
	tempData[length]=2;
	length ++;

	for (i=0;i<length;i++){
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
		  
	   }
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}

int remoteEncode_KONKA_KK_Y261(char* sendData,char* code){

	int i,length;
	#ifdef DEBUG
	LOGD("code type ======= KONKA_KK_Y261 ");
	#endif
	codeData[0] = *code++;
	codeData[1] = *code++;

	//get fix form frame data
	length =  sizeof(KONKA_KK_Y261) ;
	memcpy(tempData,KONKA_KK_Y261,length);

	//get remote custom&data get code length
	for (i=0;i<2;i++){
		  
		   LOGD("codeData [%d] ======= 0x%x ",i,codeData[i]);
	   }

	bitLen[0] =8;
	bitLen[1] = 8;
			//decode all bits data
	bits[0]=3;		//head frame
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,1,2); //data frame
	dataLen++;
	bits[dataLen]=4;		//finish frame
	dataLen++;
	bits[dataLen]=5;		//finish frame
	dataLen++;
	bits[dataLen]=0;		//end frame
	dataLen++;
	for (i=0;i<dataLen;i++){
		  
		   LOGD("bits [%d] ======= 0x%x ",i,bits[i]);
	   }

	dataLen=compressData(tempData,bits,dataLen,length);

	for (i=0;i<dataLen;i++){
		  
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
	   }


	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

	for (i=0;i<length;i++){
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
		  
	   }
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}
int remoteEncode_VICTOR_C8D8(char* sendData,char* code){

	int i,length;
	#ifdef DEBUG
	LOGD("code type ======= VICTOR_C8D8 ");
	#endif
	codeData[0] = *code++;
	codeData[1] = *code++;

	//get fix form frame data
	length =  sizeof(VICTOR_C8D8) ;
	memcpy(tempData,VICTOR_C8D8,length);

	//get remote custom&data get code length
	for (i=0;i<2;i++){
		  
		   LOGD("codeData [%d] ======= 0x%x ",i,codeData[i]);
	   }

	bitLen[0] =8;
	bitLen[1] = 8;
			//decode all bits data
	bits[0]=3;		//head frame
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,1,2); //data frame
	dataLen++;
	bits[dataLen]=4;		//finish frame
	dataLen++;
	bits[dataLen]=0;		//end frame
	dataLen++;
	for (i=0;i<dataLen;i++){
		  
		   LOGD("bits [%d] ======= 0x%x ",i,bits[i]);
	   }

	dataLen=compressData(tempData,bits,dataLen,length);

	for (i=0;i<dataLen;i++){
		  
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
	   }


	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

	for (i=0;i<length;i++){
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
		  
	   }
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}

int remoteEncode_M50560(char* sendData,char* code){

	int i,length;
	int tempLength;
	#ifdef DEBUG
	LOGD("code type ======= M50560 ");
	#endif
	codeData[0] = *code++;
	codeData[1] = *code++;

	//get fix form frame data
	length =  sizeof(M50560) ;
	memcpy(tempData,M50560,length);

	//get remote custom&data get code length
	for (i=0;i<2;i++){
		  
		   LOGD("codeData [%d] ======= 0x%x ",i,codeData[i]);
	   }

	bitLen[0] =8;
	bitLen[1] = 8;
			//decode all bits data
	bits[0]=3;		//head frame
	dataLen = dataCodeToBitsTypeR(bits,&codeData[0],bitLen,1,1); //data frame
	dataLen++;
	bits[dataLen]=4;		//finish frame
	dataLen++;
	tempLength = dataLen;
	dataLen = dataCodeToBitsTypeR(bits,&codeData[1],bitLen,tempLength,1); //data frame
	dataLen += tempLength;
	bits[dataLen]=5;		//finish frame
	dataLen++;
	bits[dataLen]=0;		//end frame
	dataLen++;
	for (i=0;i<dataLen;i++){
		  
		   LOGD("bits [%d] ======= 0x%x ",i,bits[i]);
	   }

	dataLen=compressData(tempData,bits,dataLen,length);

	for (i=0;i<dataLen;i++){
		  
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
	   }


	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

	for (i=0;i<length;i++){
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
		  
	   }
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}
int remoteEncode_UPD1986(char* sendData,char* code){

	int i,length;
	int tempLength;
	#ifdef DEBUG
	LOGD("code type ======= UPD1986 ");
	#endif

	

	switch (*code&0x1f){
		case 0:
			length =  sizeof(UPD1986C_00) ;
			memcpy(tempData,UPD1986C_00,length);
			break;
		case 1:
			length =  sizeof(UPD1986C_01) ;
			memcpy(tempData,UPD1986C_01,length);
			break;
		case 2:
			length =  sizeof(UPD1986C_02) ;
			memcpy(tempData,UPD1986C_02,length);
			break;
		case 3:
			length =  sizeof(UPD1986C_03) ;
			memcpy(tempData,UPD1986C_03,length);
			break;
		case 4:
			length =  sizeof(UPD1986C_04) ;
			memcpy(tempData,UPD1986C_04,length);
			break;
		case 5:
			length =  sizeof(UPD1986C_05) ;
			memcpy(tempData,UPD1986C_05,length);
			break;
		case 6:
			length =  sizeof(UPD1986C_06) ;
			memcpy(tempData,UPD1986C_06,length);
			break;
		case 7:
			length =  sizeof(UPD1986C_07) ;
			memcpy(tempData,UPD1986C_07,length);
			break;
		case 8:
			length =  sizeof(UPD1986C_08) ;
			memcpy(tempData,UPD1986C_08,length);
			break;
		case 9:
			length =  sizeof(UPD1986C_09) ;
			memcpy(tempData,UPD1986C_09,length);
			break;
		case 0x0a:
			length =  sizeof(UPD1986C_0a) ;
			memcpy(tempData,UPD1986C_0a,length);
			break;
		case 0x0b:
			length =  sizeof(UPD1986C_0b) ;
			memcpy(tempData,UPD1986C_0b,length);
			break;
		case 0x0c:
			length =  sizeof(UPD1986C_0c) ;
			memcpy(tempData,UPD1986C_0c,length);
			break;
		case 0x0d:
			length =  sizeof(UPD1986C_0d) ;
			memcpy(tempData,UPD1986C_0d,length);
			break;
		case 0x0e:
			length =  sizeof(UPD1986C_0e) ;
			memcpy(tempData,UPD1986C_0e,length);
			break;
		case 0x0f:
			length =  sizeof(UPD1986C_0f) ;
			memcpy(tempData,UPD1986C_0f,length);
			break;
		case 0x10:
			length =  sizeof(UPD1986C_10) ;
			memcpy(tempData,UPD1986C_10,length);
			break;
		case 0x11:
			length =  sizeof(UPD1986C_11) ;
			memcpy(tempData,UPD1986C_11,length);
			break;
		case 0x13:
			length =  sizeof(UPD1986C_12) ;
			memcpy(tempData,UPD1986C_12,length);
			break;
		case 0x14:
			length =  sizeof(UPD1986C_14) ;
			memcpy(tempData,UPD1986C_14,length);
			break;
		case 0x15:
			length =  sizeof(UPD1986C_15) ;
			memcpy(tempData,UPD1986C_15,length);
			break;
		case 0x16:
			length =  sizeof(UPD1986C_16) ;
			memcpy(tempData,UPD1986C_16,length);
			break;
		case 0x17:
			length =  sizeof(UPD1986C_17) ;
			memcpy(tempData,UPD1986C_17,length);
			break;
		case 0x18:
			length =  sizeof(UPD1986C_18) ;
			memcpy(tempData,UPD1986C_18,length);
			break;
		case 0x19:
			length =  sizeof(UPD1986C_19) ;
			memcpy(tempData,UPD1986C_19,length);
			break;
		case 0x1a:
			length =  sizeof(UPD1986C_1a) ;
			memcpy(tempData,UPD1986C_1a,length);
			break;
		case 0x1b:
			length =  sizeof(UPD1986C_1b) ;
			memcpy(tempData,UPD1986C_1b,length);
			break;
		case 0x1c:
			length =  sizeof(UPD1986C_1c) ;
			memcpy(tempData,UPD1986C_1c,length);
			break;
		case 0x1d:
			length =  sizeof(UPD1986C_1d) ;
			memcpy(tempData,UPD1986C_1d,length);
			break;
		case 0x1e:
			length =  sizeof(UPD1986C_1e) ;
			memcpy(tempData,UPD1986C_1e,length);
			break;
		case 0x1f:
			length =  sizeof(UPD1986C_1f) ;
			memcpy(tempData,UPD1986C_1f,length);	
			break;
			
		}

	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}

int remoteEncode_MIT_C8D8(char* sendData,char* code){

	int i,length;
	int tempLength;
	#ifdef DEBUG
	LOGD("code type ======= MIT_C8D8 ");
	#endif
	codeData[0] = *code++;
	codeData[1] = *code++;

	//get fix form frame data
	length =  sizeof(MIT_C8D8) ;
	memcpy(tempData,MIT_C8D8,length);

	//get remote custom&data get code length
	for (i=0;i<2;i++){
		  
		   LOGD("codeData [%d] ======= 0x%x ",i,codeData[i]);
	   }

	bitLen[0] =8;
	bitLen[1] = 8;
			//decode all bits data
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,0,2); //data frame
	bits[dataLen]=3;		//finish frame
	dataLen++;
	bits[dataLen]=0;		//end frame
	dataLen++;
	for (i=0;i<dataLen;i++){
		  
		   LOGD("bits [%d] ======= 0x%x ",i,bits[i]);
	   }

	dataLen=compressData(tempData,bits,dataLen,length);

	for (i=0;i<dataLen;i++){
		  
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
	   }


	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

	for (i=0;i<length;i++){
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
		  
	   }
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}
int remoteEncode_SHARP_IX0773CE(char* sendData,char* code){

	int i,length;
	int tempLength;
	#ifdef DEBUG
	LOGD("code type ======= SHARP_IX0773CE ");
	#endif
	codeData[0] = *code++;
	codeData[2] = *code++;
	codeData[1] = *code;

	//get fix form frame data
	length =  sizeof(SHARP_IX0773CE) ;
	memcpy(tempData,SHARP_IX0773CE,length);

	//get remote custom&data get code length
	for (i=0;i<3;i++){
		  
		   LOGD("codeData [%d] ======= 0x%x ",i,codeData[i]);
	   }

	bitLen[0] = 5;
	bitLen[1] = 8;
	bitLen[2] = 2;
			//decode all bits data
	tempLength = dataCodeToBitsTypeR(bits,codeData,bitLen,0,3); //data frame
	bits[tempLength]=3;		//end frame
	tempLength++;
	codeData[2] = ~codeData[2];
	codeData[1] = ~codeData[1];
	bitLen[0] = 5;
	bitLen[1] = 8;
	bitLen[2] = 2;

	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,tempLength,3); //data frame
	
	dataLen += tempLength;
	bits[dataLen]=3; 	//end frame
	dataLen++;

	
	bits[dataLen]=0;		//FINISH frame
	dataLen++;
	for (i=0;i<dataLen;i++){
		  
		   LOGD("bits [%d] ======= 0x%x ",i,bits[i]);
	   }

	dataLen=compressData(tempData,bits,dataLen,length);

	for (i=0;i<dataLen;i++){
		  
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
	   }


	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

	for (i=0;i<length;i++){
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
		  
	   }
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}

int remoteEncode_UPD6124(char* sendData,char* code){

	int i,length;
	int tempLength;
	#ifdef DEBUG
	LOGD("code type ======= UPD6124 ");
	#endif
	codeData[1] = *code++;
	codeData[0] = *code++;
	

	//get fix form frame data
	length =  sizeof(UPD6124) ;
	memcpy(tempData,UPD6124,length);

	//get remote custom&data get code length
	for (i=0;i<2;i++){
		  
		   LOGD("codeData [%d] ======= 0x%x ",i,codeData[i]);
	   }

	bitLen[0] = 7;
	bitLen[1] = 5;
			//decode all bits data
	bits[0]=3;		//finish frame
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,1,2); //data frame
	bits[dataLen]=1;		//finish frame
	dataLen++;
	bits[dataLen]=0;		//end frame
	dataLen++;
	for (i=0;i<dataLen;i++){
		  
		   LOGD("bits [%d] ======= 0x%x ",i,bits[i]);
	   }

	dataLen=compressData(tempData,bits,dataLen,length);

	for (i=0;i<dataLen;i++){
		  
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
	   }


	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

	for (i=0;i<length;i++){
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
		  
	   }
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}

int remoteEncode_M3004_6C(char* sendData,char* code){

	int i,length;
	int tempLength;
	#ifdef DEBUG
	LOGD("code type ======= M3004_6C ");
	#endif
	codeData[0] = 0X03;
	codeData[1] = *code++;
	codeData[2] = *code++;
	

	//get fix form frame data
	length =  sizeof(M3004_6C) ;
	memcpy(tempData,M3004_6C,length);

	//get remote custom&data get code length
	for (i=0;i<2;i++){
		  
		   LOGD("codeData [%d] ======= 0x%x ",i,codeData[i]);
	   }

	bitLen[0] = 2;
	bitLen[1] = 3;
	bitLen[2] = 6;
			//decode all bits data
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,0,3); //data frame
	bits[dataLen]=3;		//finish frame
	dataLen++;
	bits[dataLen]=0;		//end frame
	dataLen++;
	for (i=0;i<dataLen;i++){
		  
		   LOGD("bits [%d] ======= 0x%x ",i,bits[i]);
	   }

	dataLen=compressData(tempData,bits,dataLen,length);

	for (i=0;i<dataLen;i++){
		  
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
	   }


	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

	for (i=0;i<length;i++){
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
		  
	   }
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}

int remoteEncode_M50119P(char* sendData,char* code){

	int i,length;
	int tempLength;
	#ifdef DEBUG
	LOGD("code type ======= M50119P ");
	#endif
	codeData[0] = *code++;
	codeData[1] = *code++;
	

	//get fix form frame data
	length =  sizeof(M50119P) ;
	memcpy(tempData,M50119P,length);

	//get remote custom&data get code length
	for (i=0;i<2;i++){
	LOGD("codeData [%d] ======= 0x%x ",i,codeData[i]);
	   }

	bitLen[0] =3;
	bitLen[1] = 7;
			//decode all bits data
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,0,2); //data frame
	bits[dataLen]=3;		//finish frame
	dataLen++;
	bits[dataLen]=0;		//end frame
	dataLen++;
	for (i=0;i<dataLen;i++){
		  
		   LOGD("bits [%d] ======= 0x%x ",i,bits[i]);
	   }

	dataLen=compressData(tempData,bits,dataLen,length);

	for (i=0;i<dataLen;i++){
		  
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
	   }


	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

	for (i=0;i<length;i++){
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
		  
	   }
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}



int remoteEncode_SAA3010_RC_5(char* sendData,char* code){
	int i,length;
	char temp[64];
	char rationalCount;
	char oddCount ;
	if (oddCount!=0)
		rationalCount++;
	#ifdef DEBUG
	LOGD("code type ======= RC5_D1 ");
	#endif
	code++;
	codeData[0] = 0x03;
	codeData[1] = *code++;
	codeData[2] = *code++;
		
	length =  sizeof(SAA3010_RC_5) ;
	memcpy(tempData,SAA3010_RC_5,length);
	bitLen[0] = 3;
	bitLen[1] = 5;
	bitLen[2] = 6;
					//decode all bits data
	memset(bits,0x00,64);
	dataLen = RC5data2bits(bits,codeData,bitLen,3); //data frame
	
	 rationalCount = dataLen/8;
	 oddCount = dataLen%8;
	 tempData[length-1] = oddCount;
	 tempData[length-2] = rationalCount;
	if (oddCount!=0)
		rationalCount++;
	dataLen = rationalCount;
	 bitsToByte(bits,temp,rationalCount);
	
	for (i=0;i<dataLen;i++){
	 LOGD("tempData [%d] ======= 0x%x ",i,temp[i]);
		}
	
	for (i=0;i<dataLen;i++){
		tempData[length+i]=temp[i];
		}
	length += dataLen;
	//repeat times
	tempData[length]= 1;
	length ++;
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}


int remoteEncode_CUSTOM_6BIT(char* sendData,char* code){

	int i,length;
	int tempLength;
	#ifdef DEBUG
	LOGD("code type ======= T06AAB ");
	#endif
	codeData[0] = *code++;
	

	//get fix form frame data
	length =  sizeof(CUSTOM_6BIT) ;
	memcpy(tempData,CUSTOM_6BIT,length);

	//get remote custom&data get code length
	for (i=0;i<2;i++){
	LOGD("codeData [%d] ======= 0x%x ",i,codeData[i]);
	   }

	bitLen[0] = 6;
			//decode all bits data
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,0,1); //data frame
	bits[dataLen]=1;		//finish frame
	dataLen++;
	bits[dataLen]=0;		//end frame
	dataLen++;
	for (i=0;i<dataLen;i++){
		  
		   LOGD("bits [%d] ======= 0x%x ",i,bits[i]);
	   }

	dataLen=compressData(tempData,bits,dataLen,length);

	for (i=0;i<dataLen;i++){
		LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
	   }


	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

	for (i=0;i<length;i++){
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
		  
	   }
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}
int remoteEncode_CUSTOM_48BITA(char* sendData,char* code){
	char codeData[6];
	int i,length;
	#ifdef DEBUG
	LOGD("code type ======= CUSTOM_48P ");
	#endif
	
	codeData[1] = *code++;
	
	codeData[0] = *code++;
	codeData[3] = *code++;
	codeData[2] = *code++;
	codeData[4] = *code++;
	codeData[5] = ~codeData[4];
	length =  sizeof(CUSTOM_48P);
			//get fix form frame data
	
	memcpy(tempData,CUSTOM_48P,length);

	//get remote custom&data get code length

	bitLen[0] = 8;
	bitLen[1] = 8;
	bitLen[2] = 8;
	bitLen[3] = 8;
	bitLen[4] = 8;
	bitLen[5] = 8;

			//decode all bits data
	bits[0]=3;		//head frame
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,1,6); //data frame
	dataLen++;
	bits[dataLen]=4;		//finish frame
	dataLen++;
	bits[dataLen]=5;		//repeat frame
	dataLen++;
	bits[dataLen]=4;		//repeat frame
	dataLen++;
	bits[dataLen]=0;		//end frame
	dataLen++;
	dataLen=compressData(tempData,bits,dataLen,length);

	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);

	return length;
}

int remoteEncode_CUSTOM_32BITA(char* sendData,char* code){

	int i,length;
	#ifdef DEBUG
	LOGD("code type ======= CUSTOM_32P ");
	#endif
	codeData[0] = *code++;
	codeData[1] = *code++;
	codeData[2] = *code++;
	codeData[3] = ~codeData[2];
	//get fix form frame data
	length =  sizeof(CUSTOM_32P) ;
	memcpy(tempData,CUSTOM_32P,length);

	//get remote custom&data get code length
	for (i=0;i<4;i++){
		  
		   LOGD("codeData [%d] ======= 0x%x ",i,codeData[i]);
	   }

	bitLen[0] = 8;
	bitLen[1] = 8;
	bitLen[2] = 8;
	bitLen[3] = 8;
			//decode all bits data
	bits[0]=3;		//head frame
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,1,4); //data frame
	dataLen++;
	bits[dataLen]=4;		//finish frame
	dataLen++;
	bits[dataLen]=5;		//repeat frame
	dataLen++;
	bits[dataLen]=4;		//repeat frame
	dataLen++;
	bits[dataLen]=0;		//end frame
	dataLen++;
	#ifdef DEBUG
	LOGD("code type ======= CUSTOM_32P ");
	
	for (i=0;i<dataLen;i++){
		  
		   LOGD("bits [%d] ======= 0x%x ",i,bits[i]);
	   }
	
#endif
	dataLen=compressData(tempData,bits,dataLen,length);
#ifdef DEBUG

	for (i=0;i<dataLen;i++){
		  
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
	   }
#endif


	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

//	for (i=0;i<length;i++){
//		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
//	   }
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}
int remoteEncode_NEC6121_50K(char* sendData,char* code){

	int i,length;
	#ifdef DEBUG
	LOGD("code type ======= PD6121G_50K ");
	#endif
	codeData[0] = *code++;
	codeData[1] = *code++;
	codeData[2] = *code++;
	codeData[3] = ~codeData[2];
	//get fix form frame data
	length =  sizeof(PD6121G_50K) ;
	memcpy(tempData,PD6121G_50K,length);

	//get remote custom&data get code length
	for (i=0;i<4;i++){
		  
		   LOGD("codeData [%d] ======= 0x%x ",i,codeData[i]);
	   }

	bitLen[0] = 8;
	bitLen[1] = 8;
	bitLen[2] = 8;
	bitLen[3] = 8;
			//decode all bits data
	bits[0]=3;		//head frame
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,1,4); //data frame
	dataLen++;
	bits[dataLen]=4;		//finish frame
	dataLen++;
	bits[dataLen]=5;		//repeat frame
	dataLen++;
	bits[dataLen]=4;		//repeat frame
	dataLen++;
	bits[dataLen]=0;		//end frame
	dataLen++;
	#ifdef DEBUG
	LOGD("code type ======= CUSTOM_32P ");
	
	for (i=0;i<dataLen;i++){
		  
		   LOGD("bits [%d] ======= 0x%x ",i,bits[i]);
	   }
	
#endif
	dataLen=compressData(tempData,bits,dataLen,length);
#ifdef DEBUG

	for (i=0;i<dataLen;i++){
		  
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
	   }
#endif


	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

//	for (i=0;i<length;i++){
//		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
//	   }
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}

int remoteEncode_PD6121F(char* sendData,char* code){

	int i,length;
	#ifdef DEBUG
	LOGD("code type ======= PD6121F ");
	#endif
	codeData[0] = *code++;
	codeData[1] = *code++;
	codeData[2] = *code++;
	codeData[3] = ~codeData[2];
	//get fix form frame data
	length =  sizeof(PD6121F) ;
	memcpy(tempData,PD6121F,length);

	//get remote custom&data get code length
	for (i=0;i<4;i++){
		  
		   LOGD("codeData [%d] ======= 0x%x ",i,codeData[i]);
	   }

	bitLen[0] = 8;
	bitLen[1] = 8;
	bitLen[2] = 8;
	bitLen[3] = 8;
			//decode all bits data
	bits[0]=3;		//head frame
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,1,4); //data frame
	dataLen++;
	bits[dataLen]=4;		//finish frame
	dataLen++;
	bits[dataLen]=0;		//end frame
	dataLen++;
	#ifdef DEBUG
	LOGD("code type ======= remoteEncode_PD6121F ");
	
	for (i=0;i<dataLen;i++){
		  
		   LOGD("bits [%d] ======= 0x%x ",i,bits[i]);
	   }
	
#endif
	dataLen=compressData(tempData,bits,dataLen,length);
#ifdef DEBUG

	for (i=0;i<dataLen;i++){
		  
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
	   }
#endif


	length += dataLen;
	//repeat times
	tempData[length]= 2;
	length ++;

//	for (i=0;i<length;i++){
//		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
//	   }
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}


int remoteEncode_TC9012F(char* sendData,char* code){

	int i,length;
	#ifdef DEBUG
	LOGD("code type ======= TC9012F ");
	#endif
	codeData[0] = *code++;
	codeData[1] = *code++;
	codeData[2] = *code++;
	codeData[3] = ~codeData[2];
	//get fix form frame data
	length =  sizeof(TC9012F) ;
	memcpy(tempData,TC9012F,length);

	//get remote custom&data get code length
	for (i=0;i<4;i++){
		  
		   LOGD("codeData [%d] ======= 0x%x ",i,codeData[i]);
	   }

	bitLen[0] = 8;
	bitLen[1] = 8;
	bitLen[2] = 8;
	bitLen[3] = 8;
			//decode all bits data
	bits[0]=3;		//head frame
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,1,4); //data frame
	dataLen++;
	bits[dataLen]=4;		//finish frame
	dataLen++;
	bits[dataLen]=0;		//end frame
	dataLen++;
	for (i=0;i<dataLen;i++){
		  
		   LOGD("bits [%d] ======= 0x%x ",i,bits[i]);
	   }

	dataLen=compressData(tempData,bits,dataLen,length);

	for (i=0;i<dataLen;i++){
		  
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
	   }


	length += dataLen;
	//repeat times
	tempData[length]=2;
	length ++;

	for (i=0;i<length;i++){
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
		  
	   }
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}

int remoteEncode_CUSTOM_32BITB(char* sendData,char* code){

	int i,length;
	#ifdef DEBUG
	LOGD("code type ======= CUSTOM_32B ");
	#endif
	codeData[0] = *code++;
	codeData[1] = *code++;
	codeData[2] = *code++;
	codeData[3] = ~codeData[2];
	//get fix form frame data
	length =  sizeof(CUSTOM_32P) ;
	memcpy(tempData,CUSTOM_32P,length);

	//get remote custom&data get code length
	for (i=0;i<4;i++){
		  
		   LOGD("codeData [%d] ======= 0x%x ",i,codeData[i]);
	   }

	bitLen[0] = 8;
	bitLen[1] = 8;
	bitLen[2] = 8;
	bitLen[3] = 8;
			//decode all bits data
	bits[0]=3;		//head frame
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,1,4); //data frame
	dataLen++;
	bits[dataLen]=4;		//finish frame
	dataLen++;
	
	bits[dataLen]=0;		//end frame
	dataLen++;
	#ifdef DEBUG
	LOGD("code type ======= CUSTOM_32P ");
	
	for (i=0;i<dataLen;i++){
		  
		   LOGD("bits [%d] ======= 0x%x ",i,bits[i]);
	   }
	
#endif
	dataLen=compressData(tempData,bits,dataLen,length);
#ifdef DEBUG

	for (i=0;i<dataLen;i++){
		  
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
	   }
#endif


	length += dataLen;
	//repeat times
	tempData[length]=2;
	length ++;

//	for (i=0;i<length;i++){
//		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
//	   }
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}



int remoteEncode_RCA_01_56K(char* sendData,char* code){

	int i,length;
	#ifdef DEBUG
	LOGD("code type ======= RCA_01_56K ");
	#endif
	codeData[0] = *code++;
	codeData[1] = *code++;
	codeData[2] = ~codeData[0];
	codeData[3] = ~codeData[1];
	//get fix form frame data
	length =  sizeof(RCA_01_56K) ;
	memcpy(tempData,RCA_01_56K,length);

	//get remote custom&data get code length
	for (i=0;i<4;i++){
		  
		   LOGD("codeData [%d] ======= 0x%x ",i,codeData[i]);
	   }

	bitLen[0] = 4;
	bitLen[1] = 8;
	bitLen[2] = 4;
	bitLen[3] = 8;
			//decode all bits data
	bits[0]=3;		//head frame
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,1,4); //data frame
	dataLen++;
	bits[dataLen]=4;		//finish frame
	dataLen++;
	
	bits[dataLen]=0;		//end frame
	dataLen++;
	#ifdef DEBUG
	LOGD("code type ======= RCA_01_56K ");
	
	for (i=0;i<dataLen;i++){
		  
		   LOGD("bits [%d] ======= 0x%x ",i,bits[i]);
	   }
	
#endif
	dataLen=compressData(tempData,bits,dataLen,length);
#ifdef DEBUG

	for (i=0;i<dataLen;i++){
		  
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
	   }
#endif


	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

//	for (i=0;i<length;i++){
//		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
//	   }
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}

int remoteEncode_RCA_56K(char* sendData,char* code){

	int i,length;
	#ifdef DEBUG
	LOGD("code type ======= RCA_56K ");
	#endif
	codeData[0] = *code++;
	codeData[1] = *code++;
	codeData[2] = ~codeData[0];
	codeData[3] = ~codeData[1];
	//get fix form frame data
	length =  sizeof(RCA_56K) ;
	memcpy(tempData,RCA_56K,length);

	//get remote custom&data get code length
	for (i=0;i<4;i++){
		  
		   LOGD("codeData [%d] ======= 0x%x ",i,codeData[i]);
	   }

	bitLen[0] = 4;
	bitLen[1] = 8;
	bitLen[2] = 4;
	bitLen[3] = 8;
			//decode all bits data
	bits[0]=3;		//head frame
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,1,4); //data frame
	dataLen++;
	bits[dataLen]=4;		//finish frame
	dataLen++;
	
	bits[dataLen]=0;		//end frame
	dataLen++;
	#ifdef DEBUG
	LOGD("code type ======= RCA_56K ");
	
	for (i=0;i<dataLen;i++){
		  
		   LOGD("bits [%d] ======= 0x%x ",i,bits[i]);
	   }
	
#endif
	dataLen=compressData(tempData,bits,dataLen,length);
#ifdef DEBUG

	for (i=0;i<dataLen;i++){
		  
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
	   }
#endif


	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

//	for (i=0;i<length;i++){
//		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
//	   }
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}

int remoteEncode_MN6014A_C6D6(char* sendData,char* code){

	int i,length;
	#ifdef DEBUG
	LOGD("code type ======= MN6014W_C6D6 ");
	#endif
	codeData[0] = *code++;
	codeData[1] = *code++;
	codeData[2] = ~codeData[0];
	codeData[3] = ~codeData[1];
	//get fix form frame data
	length =  sizeof(MN6014W_C6D6) ;
	memcpy(tempData,MN6014W_C6D6,length);

	
	bitLen[0] = 6;
	bitLen[1] = 6;
	bitLen[2] = 6;
	bitLen[3] = 6;
			//decode all bits data
	bits[0]=3;		//head frame
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,1,4); //data frame
	dataLen++;
	bits[dataLen]=4;		//finish frame
	dataLen++;
	
	bits[dataLen]=0;		//end frame
	dataLen++;
	#ifdef DEBUG
	for (i=0;i<dataLen;i++){
		  
		   LOGD("bits [%d] ======= 0x%x ",i,bits[i]);
	   }
	
#endif
	dataLen=compressData(tempData,bits,dataLen,length);
#ifdef DEBUG

	for (i=0;i<dataLen;i++){
		  
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
	   }
#endif


	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

//	for (i=0;i<length;i++){
//		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
//	   }
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}
int remoteEncode_MN6014A_C6D6_38K(char* sendData,char* code){

	int i,length;
	#ifdef DEBUG
	LOGD("code type ======= MN6014W_C6D6 ");
	#endif
	codeData[0] = *code++;
	codeData[1] = *code++;
	codeData[2] = ~codeData[0];
	codeData[3] = ~codeData[1];
	//get fix form frame data
	length =  sizeof(MN6014W_C6D6_38K) ;
	memcpy(tempData,MN6014W_C6D6_38K,length);

	
	bitLen[0] = 6;
	bitLen[1] = 6;
	bitLen[2] = 6;
	bitLen[3] = 6;
			//decode all bits data
	bits[0]=3;		//head frame
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,1,4); //data frame
	dataLen++;
	bits[dataLen]=4;		//finish frame
	dataLen++;
	
	bits[dataLen]=0;		//end frame
	dataLen++;
	#ifdef DEBUG
	for (i=0;i<dataLen;i++){
		  
		   LOGD("bits [%d] ======= 0x%x ",i,bits[i]);
	   }
	
#endif
	dataLen=compressData(tempData,bits,dataLen,length);
#ifdef DEBUG

	for (i=0;i<dataLen;i++){
		  
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
	   }
#endif


	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

//	for (i=0;i<length;i++){
//		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
//	   }
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}

int remoteEncode_MN6014A_C5D6(char* sendData,char* code){

	int i,length;
	#ifdef DEBUG
	LOGD("code type ======= MN6014W_C5D6 ");
	#endif
	codeData[0] = *code++;
	codeData[1] = *code++;
	codeData[2] = ~codeData[0];
	codeData[3] = ~codeData[1];
	//get fix form frame data
	length =  sizeof(MN6014W_C5D6) ;
	memcpy(tempData,MN6014W_C5D6,length);

	
	bitLen[0] = 5;
	bitLen[1] = 6;
	bitLen[2] = 5;
	bitLen[3] = 6;
			//decode all bits data
	bits[0]=3;		//head frame
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,1,4); //data frame
	dataLen++;
	bits[dataLen]=4;		//finish frame
	dataLen++;
	
	bits[dataLen]=0;		//end frame
	dataLen++;
	#ifdef DEBUG
	for (i=0;i<dataLen;i++){
		  
		   LOGD("bits [%d] ======= 0x%x ",i,bits[i]);
	   }
	
#endif
	dataLen=compressData(tempData,bits,dataLen,length);
#ifdef DEBUG

	for (i=0;i<dataLen;i++){
		  
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
	   }
#endif


	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

//	for (i=0;i<length;i++){
//		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
//	   }
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}
int remoteEncode_M50462(char* sendData,char* code){

	int i,length;
	#ifdef DEBUG
	LOGD("code type ======= M50462 ");
	#endif
	codeData[0] = *code++;
	codeData[1] = *code++;
	//get fix form frame data
	length =  sizeof(M50462) ;
	memcpy(tempData,M50462,length);

	
	bitLen[0] = 8;
	bitLen[1] = 8;
			//decode all bits data
	
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,0,2); //data frame
	bits[dataLen]=1;		//finish frame
	dataLen++;
	
	bits[dataLen]=0;		//end frame
	dataLen++;
	#ifdef DEBUG
	for (i=0;i<dataLen;i++){
		  
		   LOGD("bits [%d] ======= 0x%x ",i,bits[i]);
	   }
	
#endif
	dataLen=compressData(tempData,bits,dataLen,length);
#ifdef DEBUG

	for (i=0;i<dataLen;i++){
		  
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
	   }
#endif


	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

//	for (i=0;i<length;i++){
//		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
//	   }
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}
int remoteEncode_MIT_C8D8_33K(char* sendData,char* code){

	int i,length;
	#ifdef DEBUG
	LOGD("code type ======= MIT_C8D8_33K ");
	#endif
	codeData[0] = *code++;
	codeData[1] = *code++;
	//get fix form frame data
	length =  sizeof(MIT_C8D8_33K) ;
	memcpy(tempData,MIT_C8D8_33K,length);

	
	bitLen[0] = 8;
	bitLen[1] = 8;
			//decode all bits data
	
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,0,2); //data frame
	bits[dataLen]=1;		//finish frame
	dataLen++;
	
	bits[dataLen]=0;		//end frame
	dataLen++;
	#ifdef DEBUG
	for (i=0;i<dataLen;i++){
		  
		   LOGD("bits [%d] ======= 0x%x ",i,bits[i]);
	   }
	
#endif
	dataLen=compressData(tempData,bits,dataLen,length);
#ifdef DEBUG

	for (i=0;i<dataLen;i++){
		  
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
	   }
#endif


	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

//	for (i=0;i<length;i++){
//		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
//	   }
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}


int remoteEncode_MIT_C8D8_40K(char* sendData,char* code){

	int i,length;
	#ifdef DEBUG
	LOGD("code type ======= MIT_C8D8_40K ");
	#endif
	codeData[0] = *code++;
	codeData[1] = *code++;
	//get fix form frame data
	length =  sizeof(MIT_C8D8_40K) ;
	memcpy(tempData,MIT_C8D8_40K,length);

	
	bitLen[0] = 8;
	bitLen[1] = 8;
			//decode all bits data
	
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,0,2); //data frame
	bits[dataLen]=1;		//finish frame
	dataLen++;
	
	bits[dataLen]=0;		//end frame
	dataLen++;
	#ifdef DEBUG
	for (i=0;i<dataLen;i++){
		  
		   LOGD("bits [%d] ======= 0x%x ",i,bits[i]);
	   }
	
#endif
	dataLen=compressData(tempData,bits,dataLen,length);
#ifdef DEBUG

	for (i=0;i<dataLen;i++){
		  
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
	   }
#endif


	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

//	for (i=0;i<length;i++){
//		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
//	   }
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}
int remoteEncode_SHARP_10P(char* sendData,char* code){

	int i,length;
	int tempLength;
	#ifdef DEBUG
	LOGD("code type ======= SHARP_10P ");
	#endif
	codeData[0] = *code++;
	codeData[2] = *code++;
	codeData[1] = *code;

	//get fix form frame data
	length =  sizeof(SHARP_10P) ;
	memcpy(tempData,SHARP_10P,length);

	//get remote custom&data get code length
	for (i=0;i<3;i++){
		  
		   LOGD("codeData [%d] ======= 0x%x ",i,codeData[i]);
	   }

	bitLen[0] = 5;
	bitLen[1] = 8;
	bitLen[2] = 2;
			//decode all bits data
	tempLength = dataCodeToBitsTypeR(bits,codeData,bitLen,0,3); //data frame
	bits[tempLength]=3;		//end frame
	tempLength++;
	codeData[2] = ~codeData[2];
	codeData[1] = ~codeData[1];
	bitLen[0] = 5;
	bitLen[1] = 8;
	bitLen[2] = 2;

	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,tempLength,3); //data frame
	
	dataLen += tempLength;
	bits[dataLen]=3; 	//end frame
	dataLen++;

	
	bits[dataLen]=0;		//FINISH frame
	dataLen++;
	
	dataLen=compressData(tempData,bits,dataLen,length);

	


	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}

int remoteEncode_SHARP_C3D9(char* sendData,char* code){

	int i,length;
	int tempLength;
	#ifdef DEBUG
	LOGD("code type ======= SHARP_C3D9 ");
	#endif
	codeData[0] = *code++;
	codeData[2] = *code++;
	codeData[1] = *code;

	//get fix form frame data
	length =  sizeof(SHARP_C3D9) ;
	memcpy(tempData,SHARP_C3D9,length);

	//get remote custom&data get code length
	for (i=0;i<3;i++){
		  
		   LOGD("codeData [%d] ======= 0x%x ",i,codeData[i]);
	   }

	bitLen[0] = 3;
	bitLen[1] = 8;
	bitLen[2] = 1;
			//decode all bits data
	tempLength = dataCodeToBitsTypeR(bits,codeData,bitLen,0,3); //data frame
	bits[tempLength]=3;		//end frame
	tempLength++;
	codeData[2] = ~codeData[2];
	codeData[1] = ~codeData[1];
	bitLen[0] = 3;
	bitLen[1] = 8;
	bitLen[2] = 1;

	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,tempLength,3); //data frame
	
	dataLen += tempLength;
	bits[dataLen]=3; 	//end frame
	dataLen++;

	
	bits[dataLen]=0;		//FINISH frame
	dataLen++;
	
	dataLen=compressData(tempData,bits,dataLen,length);

	


	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}
int remoteEncode_M9148(char* sendData,char* code){

	int i,length;
	int tempLength;
	#ifdef DEBUG
	LOGD("code type ======= M9148 ");
	#endif
	codeData[0] = *code++;
	codeData[1] = *code++;
	codeData[2] = *code;

	//get fix form frame data
	length =  sizeof(M9148) ;
	memcpy(tempData,M9148,length);

	//get remote custom&data get code length
	for (i=0;i<3;i++){
		  
		   LOGD("codeData [%d] ======= 0x%x ",i,codeData[i]);
	   }

	bitLen[0] = 3;
	bitLen[1] = 3;
	bitLen[2] = 5;
			//decode all bits data
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,0,3); //data frame
	if (codeData[2]&0x20){
	bits[dataLen]=4;
	}else {
	bits[dataLen]=3;
	}//end frame
	dataLen++;


	
	bits[dataLen]=0;		//FINISH frame
	dataLen++;
	
	dataLen=compressData(tempData,bits,dataLen,length);

	


	length += dataLen;
	//repeat times
	tempData[length]=2;
	length ++;

	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}

int remoteEncode_CUSTOM_1OBITA(char* sendData,char* code){

	int i,length;
	int tempLength;
	#ifdef DEBUG
	LOGD("code type ======= CUSTOM_10BITA ");
	#endif
	codeData[0] = *code++;
	codeData[1] = *code++;


	//get fix form frame data
	length =  sizeof(CUSTOM_10BITA) ;
	memcpy(tempData,CUSTOM_10BITA,length);

	

	bitLen[0] = 4;
	bitLen[1] = 6;
			//decode all bits data
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,1,2); //data frame
	bits[0] = 3;
	dataLen++;

	
	bits[dataLen]=0;		//FINISH frame
	dataLen++;
	
	dataLen=compressData(tempData,bits,dataLen,length);

	


	length += dataLen;
	//repeat times
	tempData[length]=2;
	length ++;

	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}

int remoteEncode_XY04_A(char* sendData,char* code){

	int i,length;
	int tempLength;
	#ifdef DEBUG
	LOGD("code type ======= XY04_A ");
	#endif
	codeData[0] = *code++;
	codeData[1] = *code++;


	//get fix form frame data
	length =  sizeof(XY04_A) ;
	memcpy(tempData,XY04_A,length);

	

	bitLen[0] = 2;
	bitLen[1] = 8;
			//decode all bits data
	dataLen= dataCodeToBitsTypeR(bits,codeData,bitLen,0,2); //data frame
	bits[dataLen]=1;		//END frame	
	dataLen ++;
	bits[dataLen]=0;		//FINISH frame
	dataLen++;
	
	dataLen=compressData(tempData,bits,dataLen,length);

	


	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}

int remoteEncode_CUSTOM_10PB(char* sendData,char* code){

	int i,length;
	int tempLength;
	#ifdef DEBUG
	LOGD("code type ======= CUSTOM_10PB ");
	#endif
	codeData[0] = *code++;
	codeData[1] = *code++;


	//get fix form frame data
	length =  sizeof(CUSTOM_10PB) ;
	memcpy(tempData,CUSTOM_10PB,length);

	

	bitLen[0] = 2;
	bitLen[1] = 8;
			//decode all bits data
	dataLen= dataCodeToBitsTypeR(bits,codeData,bitLen,0,2); //data frame
	bits[dataLen]=1;		//END frame	
	dataLen ++;
	bits[dataLen]=0;		//FINISH frame
	dataLen++;
	
	dataLen=compressData(tempData,bits,dataLen,length);

	


	length += dataLen;
	//repeat times
	tempData[length]=2;
	length ++;

	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}


int remoteEncode_MN6027B_D5(char* sendData,char* code){

	int i,length;
	int tempLength;
	#ifdef DEBUG
	LOGD("code type ======= MN6027B_D5 ");
	#endif
	codeData[0] = *code;
	codeData[1] = ~codeData[0];


	//get fix form frame data
	length =  sizeof(MN6027B_D5) ;
	memcpy(tempData,MN6027B_D5,length);

	

	bitLen[0] = 5;
	bitLen[1] = 5;
			//decode all bits data
	dataLen= dataCodeToBitsTypeR(bits,codeData,bitLen,0,2); //data frame
	bits[dataLen]=1;		//END frame	
	dataLen ++;
	bits[dataLen]=0;		//FINISH frame
	dataLen++;
	
	dataLen=compressData(tempData,bits,dataLen,length);

	


	length += dataLen;
	//repeat times
	tempData[length]=2;
	length ++;

	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}
int remoteEncode_M50119P_01(char* sendData,char* code){

	int i,length;
	int tempLength;
	#ifdef DEBUG
	LOGD("code type ======= M50119P_01 ");
	#endif
	codeData[0] = *code++;
	codeData[1] = *code++;
	

	//get fix form frame data
	length =  sizeof(M50119P_01) ;
	memcpy(tempData,M50119P_01,length);

	
	bitLen[0] =3;
	bitLen[1] = 7;
			//decode all bits data
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,0,2); //data frame

	bits[dataLen]=0;		//end frame
	dataLen++;
	

	dataLen=compressData(tempData,bits,dataLen,length);

	

	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}
int remoteEncode_CUSTOM_6PB(char* sendData,char* code){

	int i,length;
	int tempLength;
	#ifdef DEBUG
	LOGD("code type ======= CUSTOM_6BITB ");
	#endif
	codeData[0] = *code;
	

	//get fix form frame data
	length =  sizeof(CUSTOM_6BITB) ;
	memcpy(tempData,CUSTOM_6BITB,length);

	
	bitLen[0] =6;

			//decode all bits data
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,0,1); //data frame
	bits[dataLen]=1;		//end frame
	dataLen++;
	bits[dataLen]=0;		//finish frame
	dataLen++;
	

	dataLen=compressData(tempData,bits,dataLen,length);

	

	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}

int remoteEncode_CUSTOM_6PC(char* sendData,char* code){

	int i,length;
	int tempLength;
	#ifdef DEBUG
	LOGD("code type ======= CUSTOM_6BITC ");
	#endif
	codeData[0] = *code;
	

	//get fix form frame data
	length =  sizeof(CUSTOM_6BITC) ;
	memcpy(tempData,CUSTOM_6BITC,length);

	

	bitLen[0] = 6;

			//decode all bits data
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,0,1); //data frame
	bits[dataLen]=1;		//end frame
	dataLen++;
	bits[dataLen]=0;		//end frame
	dataLen++;
	

	dataLen=compressData(tempData,bits,dataLen,length);

	

	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}


int remoteEncode_IRT1250C5D6(char* sendData,char* code){

	int i,length;
	int tempLength;
	#ifdef DEBUG
	LOGD("code type ======= IRT1250C5D6 ");
	#endif
	codeData[0] = *code++;
	codeData[1] = *code;

	//get fix form frame data
	length =  sizeof(IRT1250C5D6) ;
	memcpy(tempData,IRT1250C5D6,length);

	

	bitLen[0] = 5;
	bitLen[1] = 6;

			//decode all bits data
	bits[0]=3;		//end frame		
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,1,2); //data frame
	dataLen++;
	bits[dataLen]=3;		//end frame
	dataLen++;
	bits[dataLen]=1;		//end frame
	dataLen++;
	bits[dataLen]=0;		//end frame
	dataLen++;
	

	dataLen=compressData(tempData,bits,dataLen,length);

	

	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}

int remoteEncode_LG3004_6C_33K(char* sendData,char* code){

	int i,length;
	int tempLength;
	#ifdef DEBUG
	LOGD("code type ======= LG3004_6C_33K ");
	#endif
	codeData[0] = 0X00;
	codeData[1] = code[4];
	codeData[2] = code[5];

	//get fix form frame data
	length =  sizeof(LG3004_6C_33K) ;
	memcpy(tempData,LG3004_6C_33K,length);

	

	bitLen[0] = 2;
	bitLen[1] = 3;
	bitLen[2] = 6;

			//decode all bits data
	
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,0,3); //data frame
	bits[dataLen]=1;		//end frame
	dataLen++;
	bits[dataLen]=0;		//end frame
	dataLen++;
	

	dataLen=compressData(tempData,bits,dataLen,length);

	

	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}
int remoteEncode_SL490_01_0HZ(char* sendData,char* code){

	int i,length;
	int tempLength;
	#ifdef DEBUG
	LOGD("code type ======= SL490_01_0HZ ");
	#endif
	codeData[0] = *code;


	//get fix form frame data
	length =  sizeof(SL490_01_0HZ) ;
	memcpy(tempData,SL490_01_0HZ,length);

	

	bitLen[0] = 5;

			//decode all bits data
	
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,0,1); //data frame
	bits[dataLen]=3;		//end frame
	dataLen++;
	bits[dataLen]=0;		//end frame
	dataLen++;
	

	dataLen=compressData(tempData,bits,dataLen,length);

	

	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}

int remoteEncode_PAN_7051(char* sendData,char* code){
	int i,length;
	#ifdef DEBUG
	LOGD("code type =======> PAN_7051 ");
	#endif

	codeData[1] = *code++;
	codeData[0] = *code++;
	codeData[3] = *code++;
	codeData[2] = *code++;
	codeData[4] = *code++;
	codeData[5] = *code++;;
	/*
  	for (i=0;i<6;i++){
	LOGD("code[%d] =======>0x%x ", i,codeData[i]);	
  		}
	*/
	length =  sizeof(PAN_7051);
	//get fix form frame data

	memcpy(tempData,PAN_7051,length);

	//	LOGD("sendData %d ----> 0x%x /n ",i,sendData[i]);

	//get remote custom&data get code length

		bitLen[0] = 8;
		bitLen[1] = 8;
		bitLen[2] = 8;
		bitLen[3] = 8;
		bitLen[4] = 8;
		bitLen[5] = 8;

	//decode all bits data
	bits[0]=3;		//head frame
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,1,6); //data frame
	dataLen++;
	bits[dataLen]=4;		//finish frame
	dataLen++;
	bits[dataLen]=0;		//end frame
	dataLen++;

	dataLen=compressData(tempData,bits,dataLen,length);

	length += dataLen;
	//repeat times
	tempData[length]= 1;
	length ++;
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}

int remoteEncode_DVB_40BIT(char* sendData,char* code){
	int i,length;
	int tempLength;
	#ifdef DEBUG
	LOGD("code type ======= DVB_40BIT ");
	#endif
	codeData[0] = *code++;
	codeData[1] = *code++;
	codeData[2] = *code++;
	codeData[3] = *code++;
	codeData[4] = *code++;

	//get fix form frame data
	length =  sizeof(DVB_40BIT) ;
	memcpy(tempData,DVB_40BIT,length);

	//get remote custom&data get code length
	

	bitLen[0] = 8;
	bitLen[1] = 8;
	bitLen[2] = 8;
			//decode all bits data
	tempLength = dataCodeToBitsTypeR(bits,codeData,bitLen,1,3); //data frame
	bits[0]=3;		//end frame
	tempLength++;
	bits[tempLength]=3;		//end frame
	tempLength++;
	codeData[0] = codeData[3];
	codeData[1] = codeData[4];
	bitLen[0] = 8;
	bitLen[1] = 8;

	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,tempLength,2); //data frame
	
	dataLen += tempLength;
	bits[dataLen]=4; 	//end frame
	dataLen++;
	bits[dataLen]=5;	//end frame
	dataLen++;
	bits[dataLen]=4;	//end frame
	dataLen++;

	
	bits[dataLen]=0;		//FINISH frame
	dataLen++;
	
	dataLen=compressData(tempData,bits,dataLen,length);

	


	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}
int remoteEncode_THOMSON_RCT311(char* sendData,char* code){

	int i,length;
	int tempLength;
	#ifdef DEBUG
	LOGD("code type ======= THOMSON_RCT311 ");
	#endif
	codeData[0] = *code++;
	codeData[1] =  0X01;
	codeData[2] =  *code;


	//get fix form frame data
	length =  sizeof(THOMSON_RCT311) ;
	memcpy(tempData,THOMSON_RCT311,length);

	bitLen[0] = 4;
	bitLen[1] = 1;
	bitLen[2] = 7;

			//decode all bits data
	
	dataLen = dataCodeToBitsTypeL(bits,codeData,bitLen,0,3); //data frame
	bits[dataLen]=3;		//end frame
	dataLen++;
	bits[dataLen]=0;		//end frame
	dataLen++;
	

	dataLen=compressData(tempData,bits,dataLen,length);

	

	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}

int remoteEncode_SL490_0HZ(char* sendData,char* code){

	int i,length;
	int tempLength;
	#ifdef DEBUG
	LOGD("code type ======= SL490_0HZ ");
	#endif
	codeData[0] = *code;


	//get fix form frame data
	length =  sizeof(SL490_0HZ) ;
	memcpy(tempData,SL490_0HZ,length);

	

	bitLen[0] = 5;

			//decode all bits data
	
	dataLen = dataCodeToBitsTypeL(bits,codeData,bitLen,0,1); //data frame
	bits[dataLen]=3;		//end frame
	dataLen++;
	bits[dataLen]=0;		//end frame
	dataLen++;
	

	dataLen=compressData(tempData,bits,dataLen,length);

	

	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}
int remoteEncode_ZENITH_S7(char* sendData,char* code){

	int i,length;
	int tempLength;
	#ifdef DEBUG
	LOGD("code type ======= ZENITH_S7 ");
	#endif
	codeData[0] = *code++;
	codeData[1] = *code;
	codeData[2] = 0x02;


	//get fix form frame data
	length =  sizeof(ZENITH_S7) ;
	memcpy(tempData,ZENITH_S7,length);

	

	bitLen[0] = 3;
	bitLen[1] = 8;
	bitLen[2] = 2;

			//decode all bits data
	
	dataLen = dataCodeToBitsZenithR(bits,codeData,bitLen,3); //data frame
	bits[dataLen]=1;		//end frame
	dataLen++;
	bits[dataLen]=0;		//end frame
	dataLen++;
	

	dataLen=compressData(tempData,bits,dataLen,length);

	

	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}

int remoteEncode_ZENITH_D5(char* sendData,char* code){

	int i,length;
	int tempLength;
	#ifdef DEBUG
	LOGD("code type ======= ZENITH_S7 ");
	#endif
	codeData[0] = *code++;
	codeData[1] = *code;
	codeData[2] = 0x02;


	//get fix form frame data
	length =  sizeof(ZENITH_S7) ;
	memcpy(tempData,ZENITH_S7,length);

	

	bitLen[0] = 3;
	bitLen[1] = 8;
	bitLen[2] = 2;

			//decode all bits data
	
	dataLen = dataCodeToBitsZenithR(bits,codeData,bitLen,3); //data frame
	bits[dataLen]=1;		//end frame
	dataLen++;
	bits[dataLen]=0;		//end frame
	dataLen++;
	

	dataLen=compressData(tempData,bits,dataLen,length);

	

	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}

int remoteEncode_RC6(char* sendData,char* code){
	int i,length;
	char temp[64];
	char rationalCount;
	char oddCount ;
	if (oddCount!=0)
		rationalCount++;
	#ifdef DEBUG
	LOGD("code type ======= RC6 ");
	#endif
	codeData[0] = *code++;
	code++;
	codeData[1] = *code++;
	codeData[2] = *code++;
		
	length =  sizeof(RC6) ;
	memcpy(tempData,RC6,length);
					//decode all bits data
	memset(bits,0x00,100);
	dataLen = RC6data2bits(bits,codeData,2); //data frame
	
	 rationalCount = dataLen/8;
	 oddCount = dataLen%8;
	 tempData[length-1] = oddCount;
	 tempData[length-2] = rationalCount;
	if (oddCount!=0)
		rationalCount++;
	dataLen = rationalCount;
	bitsToByte(bits,temp,rationalCount);
	
	for (i=0;i<dataLen;i++){
	 LOGD("tempData [%d] ======= 0x%x ",i,temp[i]);
		}
	for (i=0;i<dataLen;i++){
		tempData[length+i]=temp[i];
		}
	length += dataLen;
	//repeat times
	tempData[length]= 1;
	length ++;
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}

int remoteEncode_PHILIPS_RC_6(char* sendData,char* code){
	int i,length;
	char temp[64];
	char rationalCount;
	char oddCount ;
	if (oddCount!=0)
		rationalCount++;
	#ifdef DEBUG
	LOGD("code type ======= PHILIPS_RC_6 ");
	#endif
	codeData[0] = *code++;
	codeData[1] = *code++;
	codeData[2] = *code++;
	codeData[3] = *code++;
	codeData[4] = *code++;
	length =  sizeof(PHILIPS_RC_6) ;
	memcpy(tempData,PHILIPS_RC_6,length);
					//decode all bits data
	memset(bits,0x00,100);
	dataLen = RC6data2bits(bits,codeData,4); //data frame
	
	 rationalCount = dataLen/8;
	 oddCount = dataLen%8;
	 tempData[length-1] = oddCount;
	 tempData[length-2] = rationalCount;
	if (oddCount!=0)
		rationalCount++;
	dataLen = rationalCount;
	bitsToByte(bits,temp,rationalCount);
	
	for (i=0;i<dataLen;i++){
	 LOGD("tempData [%d] ======= 0x%x ",i,temp[i]);
		}
	for (i=0;i<dataLen;i++){
		tempData[length+i]=temp[i];
		}
	length += dataLen;
	//repeat times
	tempData[length]= 1;
	length ++;
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}



int remoteEncode_SPEC_C7D8(char* sendData,char* code){
	int i,length;
	int tempLength;
	#ifdef DEBUG
	LOGD("code type ======= SPEC_C7D8 ");
	#endif
	codeData[0] = *code++;
	codeData[1] = *code++;
	codeData[2] = *code;

	//get fix form frame data
	length =  sizeof(SPEC_C7D8) ;
	memcpy(tempData,SPEC_C7D8,length);

	//get remote custom&data get code length
	for (i=0;i<3;i++){
		  
		   LOGD("codeData [%d] ======= 0x%x ",i,codeData[i]);
	   }

	bitLen[0] = 7;
			//decode all bits data
	tempLength = dataCodeToBitsTypeRB(bits,codeData,bitLen,0,1); //data frame

	bitLen[0] = codeData[2] ;
	codeData[0] = codeData[1];


	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,tempLength,1); //data frame
	
	dataLen += tempLength;
	bits[dataLen]=1; 	//end frame
	dataLen++;

	
	bits[dataLen]=0;		//FINISH frame
	dataLen++;
	
	dataLen=compressData(tempData,bits,dataLen,length);

	


	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}

int remoteEncode_SPEC_C6D7(char* sendData,char* code){
	int i,length;
	int tempLength;
	#ifdef DEBUG
	LOGD("code type ======= SPEC_C6D7 ");
	#endif
	codeData[0] = *code++;
	codeData[1] = *code++;
	codeData[2] = *code++;

	//get fix form frame data
	length =  sizeof(SPEC_C6D7) ;
	memcpy(tempData,SPEC_C6D7,length);


	bitLen[0] = 6;
			//decode all bits data
	tempLength = dataCodeToBitsTypeRB(bits,codeData,bitLen,0,1); //data frame
	
	codeData[0] = codeData[1];
	bitLen[0] = codeData[2];


	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,tempLength,1); //data frame
	
	dataLen += tempLength;
	bits[dataLen]=1; 	//end frame
	dataLen++;

	
	bits[dataLen]=0;		//FINISH frame
	dataLen++;
	
	dataLen=compressData(tempData,bits,dataLen,length);

	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}


int remoteEncode_SPEC_C7D7(char* sendData,char* code){
	int i,length;
	int tempLength;
	#ifdef DEBUG
	LOGD("code type ======= SPEC_C7D8 ");
	#endif
	codeData[0] = *code++;
	codeData[1] = *code++;
	codeData[2] = *code;

	//get fix form frame data
	length =  sizeof(SPEC_C7D8) ;
	memcpy(tempData,SPEC_C7D8,length);

	//get remote custom&data get code length
	for (i=0;i<3;i++){
		  
		   LOGD("codeData [%d] ======= 0x%x ",i,codeData[i]);
	   }

	bitLen[0] = 7;
			//decode all bits data
	tempLength = dataCodeToBitsTypeRB(bits,codeData,bitLen,0,1); //data frame

	bitLen[0] = codeData[2] ;
	codeData[0] = codeData[1];


	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,tempLength,1); //data frame
	
	dataLen += tempLength;
	bits[dataLen]=1; 	//end frame
	dataLen++;

	
	bits[dataLen]=0;		//FINISH frame
	dataLen++;
	
	dataLen=compressData(tempData,bits,dataLen,length);

	


	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}

int remoteEncode_SAF1039(char* sendData,char* code){
	int i,length;
	int tempLength;
	#ifdef DEBUG
	LOGD("code type ======= SAF1039 ");
	#endif
	codeData[0] = *code++;
	codeData[1] = *code++;
	codeData[2] = *code++;

	//get fix form frame data
	length =  sizeof(SAF1039) ;
	memcpy(tempData,SAF1039,length);


	bitLen[0] = 7;
			//decode all bits data
	tempLength = dataCodeToBitsTypeRB(bits,codeData,bitLen,0,1); //data frame
	
	codeData[0] = codeData[1];

	dataLen = dataCodeToBitsSAF(bits,codeData,tempLength); //data frame
	
	dataLen += tempLength;
	bits[dataLen]=1; 	//end frame
	dataLen++;

	
	bits[dataLen]=0;		//FINISH frame
	dataLen++;
	
	dataLen=compressData(tempData,bits,dataLen,length);

	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}

int remoteEncode_UPD6124_D7C8(char* sendData,char* code){

	int i,length;
	int tempLength;
	#ifdef DEBUG
	LOGD("code type ======= UPD6124_D7C8 ");
	#endif
	codeData[1] = *code++;
	codeData[0] = *code++;
	

	//get fix form frame data
	length =  sizeof(UPD6124_D7C8) ;
	memcpy(tempData,UPD6124_D7C8,length);

	//get remote custom&data get code length
	for (i=0;i<2;i++){
		  
		   LOGD("codeData [%d] ======= 0x%x ",i,codeData[i]);
	   }

	bitLen[0] = 7;
	bitLen[1] = 8;
			//decode all bits data
	bits[0]=3;		//finish frame
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,1,2); //data frame
	bits[dataLen]=1;		//finish frame
	dataLen++;
	bits[dataLen]=0;		//end frame
	dataLen++;
	for (i=0;i<dataLen;i++){
		  
		   LOGD("bits [%d] ======= 0x%x ",i,bits[i]);
	   }

	dataLen=compressData(tempData,bits,dataLen,length);

	for (i=0;i<dataLen;i++){
		  
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
	   }


	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

	for (i=0;i<length;i++){
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
		  
	   }
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}

int remoteEncode_UPD6124_D7C13(char* sendData,char* code){

	int i,length;
	int tempLength;
	#ifdef DEBUG
	LOGD("code type ======= UPD6124_D7C13 ");
	#endif
	
	codeData[1] = *code++;
	codeData[2] = *code++;
	codeData[0] = *code++;
	

	//get fix form frame data
	length =  sizeof(UPD6124_D7C13) ;
	memcpy(tempData,UPD6124_D7C13,length);

	//get remote custom&data get code length
	
	bitLen[0] = 7;
	bitLen[1] = 8;
	bitLen[2] = 5;
			//decode all bits data
	bits[0]=3;		//finish frame
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,1,3); //data frame
	bits[dataLen]=1;		//finish frame
	dataLen++;
	bits[dataLen]=0;		//end frame
	dataLen++;
	for (i=0;i<dataLen;i++){
		  
		   LOGD("bits [%d] ======= 0x%x ",i,bits[i]);
	   }

	dataLen=compressData(tempData,bits,dataLen,length);

	for (i=0;i<dataLen;i++){
		  
		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
	   }


	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

//	for (i=0;i<length;i++){
//		   LOGD("tempData [%d] ======= 0x%x ",i,tempData[i]);
//
//	   }
	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}

int remoteEncode_PIONEER(char* sendData,char* code){

	int i,length;
	int tempLength;
	#ifdef DEBUG
	LOGD("code type ======= PIONEER ");
	#endif
	codeData[0] = *code++;
	codeData[1] = *code++;
	codeData[2] = *code++;
	codeData[3] = *code++;
	codeData[4] = *code++;
	codeData[5] = *code++;
	codeData[6] = *code++;
	codeData[7] = *code++;

	//get fix form frame data
	length =  sizeof(PIONEER) ;
	memcpy(tempData,PIONEER,length);

	//get remote custom&data get code length
//	for (i=0;i<3;i++){
//
//		   LOGD("codeData [%d] ======= 0x%x ",i,codeData[i]);
//	   }

	bitLen[0] = 8;
	bitLen[1] = 8;
	bitLen[2] = 8;
	bitLen[3] = 8;
			//decode all bits data
	tempLength = dataCodeToBitsTypeR(bits,codeData,bitLen,1,4); //data frame
	bits[0]=3;		//end frame
	tempLength++;
	bits[tempLength]=4;		//end frame
	tempLength++;
	codeData[0] = codeData[4];
	codeData[1] = codeData[5];
	codeData[2] = codeData[6];
	codeData[3] = codeData[7];
	bitLen[0] = 8;
	bitLen[1] = 8;
	bitLen[2] = 8;
	bitLen[3] = 8;

    bits[tempLength]=3;		//end frame
	tempLength++;
	dataLen = dataCodeToBitsTypeR(bits,codeData,bitLen,tempLength,4); //data frame
	
	dataLen += tempLength;
	bits[dataLen]=4; 	//end frame
	dataLen++;
	bits[dataLen]=0;		//FINISH frame
	dataLen++;
	
	dataLen=compressData(tempData,bits,dataLen,length);
	length += dataLen;
	//repeat times
	tempData[length]=1;
	length ++;

	length =WrapUpSendData(sendData,tempData,REMOTE_SEND_1,length);
	return length;
}

