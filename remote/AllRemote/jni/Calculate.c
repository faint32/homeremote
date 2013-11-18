#include <string.h>
#include "logo.h"
#include "Calculate.h"



unsigned char HiBitFst(unsigned char low_first)
{
	unsigned char i,j,temp=0;
	j = low_first;
	for(i=0;i!=8;i++)
	{
		temp<<=1;
		if(j&0x01)temp++;
		j>>= 1;
	}
	return temp;
}
unsigned char CountBit(unsigned char air_byte){
	unsigned char i,temp=0;

	for(i=0;i<8;i++){
		if((air_byte>>i)&0x01){
			temp++;
		}
	}

	return temp;
}


void timeShift(unsigned char* datain,unsigned char* dataout){
	int temp1,temp2,temp3,temp4,temp5,temp6;
	int freq;
	dataout[0] = 0x00;
	dataout[1] = datain[11]*33/10;
	freq =datain[11];
	dataout[2] = 0x11;
	temp1 = (datain[13]*256+datain[14])*4/freq;
	temp2 = (datain[15]*256+datain[16])*4/freq;
	temp3 = (datain[17]*256+datain[18])*4/freq;
	temp4 = (datain[19]*256+datain[20])*4/freq;
	temp5 = (datain[21]*256+datain[22])*4/freq;
	temp6 = (datain[23]*256+datain[24])*4/freq;
	dataout[3] = temp3%256;
	dataout[4] = temp3/256;
	dataout[5] = temp4%256;
	dataout[6] = temp4/256;
	dataout[7] = temp3%256;
	dataout[8] = temp3/256;
	dataout[9] = temp5%256;
	dataout[10] = temp5/256;
	dataout[11] = temp1%256;
	dataout[12] = temp1/256;
	dataout[13] = temp2%256;
	dataout[14] = temp2/256;
	dataout[15] = temp3%256;
	dataout[16] = temp3/256;
	dataout[17] = temp6%256;
	dataout[18] = temp6/256;
		
}


void timeShiftB(unsigned char* datain,unsigned char* dataout){
	int temp1,temp2,temp3,temp4,temp5,temp6;
	int freq;
	dataout[0] = 0x00;
	dataout[1] = datain[11]*33/10;
	freq =datain[11];
	dataout[2] = 0x11;
	temp1 = (datain[13]*256+datain[14])*4/freq;
	temp2 = (datain[15]*256+datain[16])*4/freq;
	temp3 = (datain[17]*256+datain[18])*4/freq;
	temp4 = (datain[19]*256+datain[20])*4/freq;
	temp5 = (datain[21]*256+datain[22])*4/freq;
	temp6 = (datain[23]*256+datain[24])*4/freq;
	dataout[3] = temp5%256;
	dataout[4] = temp5/256;
	dataout[5] = temp3%256;
	dataout[6] = temp3/256;
	dataout[7] = temp3%256;
	dataout[8] = temp3/256;
	dataout[9] = temp5%256;
	dataout[10] = temp5/256;
	dataout[11] = temp1%256;
	dataout[12] = temp1/256;
	dataout[13] = temp2%256;
	dataout[14] = temp2/256;
	dataout[15] = temp3%256;
	dataout[16] = temp3/256;
	dataout[17] = temp6%256;
	dataout[18] = temp6/256;
		
}
void timeShiftC(unsigned char* datain,unsigned char* dataout){
	int temp1,temp2,temp3,temp4,temp5,temp6;
	int freq;
	dataout[0] = 0x00;
	dataout[1] = datain[11]*33/10;
	freq =datain[11];
	dataout[2] = 0x15;
	temp1 = (datain[13]*256+datain[14])*4/freq;
	temp2 = (datain[15]*256+datain[16])*4/freq;
	temp3 = (datain[17]*256+datain[18])*4/freq;
	temp4 = (datain[19]*256+datain[20])*4/freq;
	temp5 = (datain[21]*256+datain[22])*4/freq;
	temp6 = (datain[23]*256+datain[24])*4/freq;
	dataout[3] = temp3%256;
	dataout[4] = temp3/256;
	dataout[5] = temp4%256;
	dataout[6] = temp4/256;
	dataout[7] = temp3%256;
	dataout[8] = temp3/256;
	dataout[9] = temp5%256;
	dataout[10] = temp5/256;
	dataout[11] = temp1%256;
	dataout[12] = temp1/256;
	dataout[13] = temp2%256;
	dataout[14] = temp2/256;
	dataout[15] = temp3%256;
	dataout[16] = temp3/256;
	dataout[17] = temp6%256;
	dataout[18] = temp6/256;
	dataout[19] = temp1%256;
	dataout[20] = temp1/256;
	dataout[21] = temp1%256;
	dataout[22] = temp1/256;	
}

void timeShiftD(unsigned char* datain,unsigned char* dataout){
	int temp1,temp2,temp3,temp4,temp5,temp6;
	int freq;
	dataout[0] = 0x00;
	dataout[1] = datain[11]*33/10;
	freq =datain[11];
	dataout[2] = 25;
	temp1 = (datain[13]*256+datain[14])*4/freq;
	temp2 = (datain[15]*256+datain[16])*4/freq;
	temp3 = (datain[17]*256+datain[18])*4/freq;
	temp4 = temp3*2;
	temp5 = (datain[21]*256+datain[22])*4/freq;
	temp6 = (datain[23]*256+datain[24])*4/freq;
	dataout[3] = temp3%256;
	dataout[4] = temp3/256;
	dataout[5] = temp3%256;
	dataout[6] = temp3/256;
	dataout[7] = temp3%256;
	dataout[8] = temp3/256;
	dataout[9] = temp4%256;
	dataout[10] = temp4/256;
	dataout[11] = temp4%256;
	dataout[12] = temp4/256;
	dataout[13] = temp3%256;
	dataout[14] = temp3/256;
	dataout[15] = temp4%256;
	dataout[16] = temp4/256;
	dataout[17] = temp4%256;
	dataout[18] = temp4/256;
	dataout[19] = temp1%256;
	dataout[20] = temp1/256;
	dataout[21] = temp2%256;
	dataout[22] = temp2/256;
	dataout[23] = temp6%256;
	dataout[24] = temp6/256;
	dataout[25] = temp6%256;
	dataout[26] = temp6/256;
		
}
void fixHeadTime(unsigned char* datain){
	int temp1;
	temp1 = datain[21]+datain[22]*256+datain[4]*256+datain[3];
	datain[21] = temp1%256;
	datain[22] = temp1/256;
		
}

char timeShiftAIR(unsigned char* datain,unsigned char* dataout){
	int temp1,temp2,temp3,temp4,temp5,temp6;
	int freq;
	char dataLenFul;
	char dataLenOdd;
	char index,count;
	char len=0;
	dataout[0] = 0x80;
	dataout[1] = datain[11]*33/10;
	freq =datain[11];
	dataout[3] = 0x11;
	temp1 = (datain[13]*256+datain[14])*4/freq;
	temp2 = (datain[15]*256+datain[16])*4/freq;
	temp3 = (datain[17]*256+datain[18])*4/freq;
	temp4 = (datain[19]*256+datain[20])*4/freq;
	temp5 = (datain[21]*256+datain[22])*4/freq;
	temp6 = (datain[23]*256+datain[24])*4/freq;
	dataout[4] = temp3%256;
	dataout[5] = temp3/256;
	dataout[6] = temp4%256;
	dataout[7] = temp4/256;
	dataout[8] = temp3%256;
	dataout[9] = temp3/256;
	dataout[10] = temp5%256;
	dataout[11] = temp5/256;
	dataout[12] = temp1%256;
	dataout[13] = temp1/256;
	dataout[14] = temp2%256;
	dataout[15] = temp2/256;
	dataout[16] = temp3%256;
	dataout[17] = temp3/256;
	dataout[18] = temp6%256;
	dataout[19] = temp6/256;
	index = 0x11;
	return index;
}

void timeShiftE(unsigned char* datain,unsigned char* dataout){
	int temp1,temp2,temp3,temp4,temp5,temp6;
	int freq;
	dataout[0] = 0x80;
	dataout[1] = datain[11]*33/10;
	freq = datain[11];
	dataout[3] = 0x11;
	temp1 = (datain[13]*256+datain[14])*4/freq;
	temp2 = (datain[15]*256+datain[16])*4/freq;
	temp3 = (datain[17]*256+datain[18])*4/freq;
	temp4 = (datain[19]*256+datain[20])*4/freq;
	temp5 = (datain[21]*256+datain[22])*4/freq;
	temp6 = (datain[23]*256+datain[24])*4/freq;
	dataout[4] = temp3%256;
	dataout[5] = temp3/256;
	dataout[6] = temp4%256;
	dataout[7] = temp4/256;
	dataout[8] = temp3%256;
	dataout[9] = temp3/256;
	dataout[10] = temp5%256;
	dataout[11] = temp5/256;
	dataout[12] = temp1%256;
	dataout[13] = temp1/256;
	dataout[14] = temp2%256;
	dataout[15] = temp2/256;
	dataout[16] = temp3%256;
	dataout[17] = temp3/256;
	dataout[18] = temp6%256;
	dataout[19] = temp6/256;
		
}

void timeShiftF(unsigned char* datain,unsigned char* dataout){
	int i,j,k;
	int freq;
	int count,temp,temp1,temp2;
	
	dataout[0] = 0x80;
	dataout[1] = datain[1]*33/10;
	freq = datain[1];
	dataout[3] = datain[3]-0X83;
	count = dataout[3]/2;
	j = 4;
	k = 4;
	for (i=0;i<count;i++){
		temp1 = (datain[j++]&0x7f)*256;
		temp2 = datain[j++];
		temp = (temp1+temp2)*4/freq;
		dataout[k++] = temp%256;
		dataout[k++] = temp/256;
		}
		
}

int getDataEnd(unsigned char* datain,int start){
	int i;
	int freq;
	int count,temp,temp1,temp2;
	
	for (i=start;i<120;i++){
		if (datain[i]==0x02){
			if (datain[i+1]==0x00){
			return i;
			}
		}
		
	}
	return 120;	
}

/*****************************************************/
//   low bit add
//
/*****************************************************/
unsigned char lowBitAdd(Air_para *Ch_para){
	unsigned char i,temp1=0,temp2=0,temp3=0,count=0,temp;
   
	for(i=0;i<4;i++){

		temp1= (Ch_para->COD[4]>>i)&0x01;
		temp2= (Ch_para->COD[5]>>i)&0x01;
		temp3= (Ch_para->COD[6]>>i)&0x01;
		temp = (temp1+temp2+temp3)&0x01;
		count |= (temp<<i);
		
	}
	count |= 0xf0;
	return count;
}




void HBarray(unsigned char length, Air_para *Ch_para)
{
	unsigned char i;
	for(i=0;i<length;i++)Ch_para->COD[i]=HiBitFst(Ch_para->COD[i]);
}


unsigned char GetZeron(unsigned char air_code)
{
	unsigned char i,j,temp;
	j = air_code;
	for(i=0,temp=8;i!=8;i++)
	{
		if(j&0x01)
			temp--;
		j >>= 1;
	}
	return temp;
}
void AdjustZero(Air_para *rmt_array)
{
	unsigned char i,j,temp;
	temp = GetZeron(rmt_array->COD[0]);
	temp += GetZeron(rmt_array->COD[1]);
	temp += GetZeron(rmt_array->COD[2]);
	temp += GetZeron(rmt_array->COD[4]);
	temp += GetZeron(rmt_array->COD[5]);
	temp += GetZeron(rmt_array->COD[6]);
	i = rmt_array->COD[1];
	i >>= 4;
	j = temp;
	j <<= 4;
	rmt_array->COD[1] += j;
	temp += i;
	temp >>= 4;
	rmt_array->COD[2] += temp;
}

unsigned char Sumarray(unsigned char codnum, Air_para *air_para){
	unsigned char i,sum;
	for(i=0,sum=0;i<codnum;i++)
		sum+=air_para->COD[i];
	return sum;
}

void ShBitLft(unsigned char length,Air_para *Ch_para)
{
	unsigned char i;
	for(i=0;i<length;i++)
	{
		Ch_para->COD[i]<<=1;
		if(Ch_para->COD[i+1]&0x80)
			Ch_para->COD[i]++;
	}
}

unsigned char NSarray(unsigned char length,Air_para *Ch_para)
{
	unsigned char i,temp;
	for(i=0,temp=0;i<length;i++)
	{
		temp+=Ch_para->COD[i]&0x0f;
		temp+=Ch_para->COD[i]>>4;
	}
	return temp;
}

unsigned char SBarray(unsigned char length,Air_para *Ch_para)
{
	unsigned char i,sum;
	for(i=0,sum=0;i<length;i++)
		sum+=CountBit(Ch_para->COD[i]);
	return sum;
}



/*
 *   data to bitsdata left shift
 */
int airDataToBitsTypeR(char* bits,char* codeData,char bitStart,char dataLen,char dataLenOdd){
	int i,j, dataLength=0;
	char temp;
	char mask;
	int m = bitStart;
	for ( i=0;i<dataLen;++i)
		{
		temp = codeData[i];
		mask = 0x01;
	//	LOGD("codeData %d =======> 0x%x \n ",i,codeData[i]);
		for (j=0;j<8;j++){

			if (temp&mask){
				bits[m] = 2;
			}
			else {
				bits[m] = 1;
			}
			temp >>= 1;
			dataLength++;
		//	LOGD("bits %d =======> %d \n ",m,bits[m]);
			m++;
			}
		
		}
		if (dataLenOdd>0){
			temp = codeData[dataLen];
			mask = 0x01;
			for (j=0;j<dataLenOdd;j++){

				if (temp&mask){
					bits[m] = 2;
				}
				else {
					bits[m] = 1;
				}
				temp >>= 1;
				dataLength++;
			//	LOGD("bits %d =======> %d \n ",m,bits[m]);
				m++;
				}
		}

  return dataLength;

}

/*
 *   data to bitsdata left shift
 */
int airDataToBitsTypeL(char* bits,char* codeData,char bitStart,char dataLen,char dataLenOdd){
	int i,j, dataLength=0;
	char temp;
	char mask;
	int m = bitStart;
	for ( i=0;i<dataLen;++i)
		{
		temp = codeData[i];
		mask = 0x80;
	//	LOGD("codeData %d =======> 0x%x \n ",i,codeData[i]);
		for (j=0;j<8;j++){

			if (temp&mask){
				bits[m] = 2;
			}
			else {
				bits[m] = 1;
			}
			temp <<= 1;
			dataLength++;
		//	LOGD("bits %d =======> %d \n ",m,bits[m]);
			m++;
			}
		if (dataLenOdd>0){
			temp = codeData[i];
			mask = 0x01<<(dataLenOdd-1);
			for (j=0;j<dataLenOdd;j++){

				if (temp&mask){
					bits[m] = 2;
				}
				else {
					bits[m] = 1;
				}
				temp <<= 1;
				dataLength++;
			//	LOGD("bits %d =======> %d \n ",m,bits[m]);
				m++;
				}
			}
		}

  return dataLength;

}






void shiftAirData(char* data,char shiftIndex,char length){
	int i;
	for (i=0;i<length;i++){
	data[shiftIndex+i] = data[i];
	}
}


/*
 *   data to bits data left shift
 */
char dataCodeToBitsTypeL(char*bits,char* codeData,char* bitLen,char bitStart,char length){
	int i,j;
	char dataLength=0;
	char temp,lenTemp,mask;

	int m = bitStart;
	for ( i=0;i<length;++i)
		{
		temp = codeData[i];
		lenTemp =bitLen[i];
		mask = 0x01<<(lenTemp-1);
	//	LOGD("codeData %d =======> 0x%x \n ",i,codeData[i]);
		for (j=0;j<lenTemp;j++){

			if (temp&mask){
				bits[m] = 2;
			}
			else {
				bits[m] = 1;
			}
			temp <<= 1;
			dataLength++;
		//	LOGD("bits %d =======> %d \n ",m,bits[m]);
			m++;
			}
		}

  return dataLength;

}

/*
 *   data to bits data right shift
 */
int dataCodeToBitsTypeR(char*bits,char* codeData,char* bitLen,char bitStart,char length){
	int i,j, dataLength=0;
	char temp;
	char mask;
	int m = bitStart;
	for ( i=0;i<length;++i)
		{
		temp = codeData[i];
		mask = 0x01;
	//	LOGD("codeData %d =======> 0x%x \n ",i,codeData[i]);
		for (j=0;j<bitLen[i];j++){

			if (temp&mask){
				bits[m] = 2;
			}
			else {
				bits[m] = 1;
			}
			temp >>= 1;
			dataLength++;
		//	LOGD("bits %d =======> %d \n ",m,bits[m]);
			m++;
			}
		}

  return dataLength;

}
/*
 *   data to bits data right shift SPIECIAL
 */
int dataCodeToBitsTypeRB(char*bits,char* codeData,char* bitLen,char bitStart,char length){
	int i,j, dataLength=0;
	char temp;
	char mask;
	int m = bitStart;
	for ( i=0;i<length;++i)
		{
		temp = codeData[i];
		mask = 0x01;
	//	LOGD("codeData %d =======> 0x%x \n ",i,codeData[i]);
		for (j=0;j<bitLen[i];j++){

			if (temp&mask){
				bits[m] = 3;
			}
			else {
				bits[m] = 1;
			}
			temp >>= 1;
			dataLength++;
		//	LOGD("bits %d =======> %d \n ",m,bits[m]);
			m++;
			}
		}

  return dataLength;

}

/*
 *   data to bits data right shift
 */
int dataCodeTo2BitsTypeR(char*bits,char* codeData,char* bitLen,char bitStart,char length){
	int i,j, dataLength=0;
	char temp;
	char mask;
	int m = bitStart;
	for ( i=0;i<length;++i)
		{
		temp = codeData[i];
		mask = 0x03;
	//	LOGD("codeData %d =======> 0x%x \n ",i,codeData[i]);
		for (j=0;j<bitLen[i];j+=2){
			switch (temp&mask){
				case 0:
					bits[m++]=1;
					break;
				case 1:
					bits[m++]=2;
					break;	
				case 2:
					bits[m++]=3;
					break;
				case 3:
					bits[m++]=4;
					break;
				default:
					break;
				}
			temp >>= 2;
			dataLength++;
		//	LOGD("bits %d =======> %d \n ",m,bits[m]);
			}
		}

  return dataLength;

}




int dataCodeToBitsZenithR(char*bits,char* codeData,char* bitLen,char length){
	int i,j, dataLength=0;
	char temp;
	char mask;
	int m = 0;
	for ( i=0;i<length;++i)
		{
		temp = codeData[i];
		mask = 0x01;
	//	LOGD("codeData %d =======> 0x%x \n ",i,codeData[i]);
		for (j=0;j<bitLen[i];j++){

			if (temp&mask){
				bits[m] = 3;
				m++;
				dataLength++;
			}
			else {
				bits[m] = 1;
				m++;
				bits[m] = 2;
				m++;
				dataLength += 2;
			}
			temp >>= 1;
			
		//	LOGD("bits %d =======> %d \n ",m,bits[m]);
			
			}
		}

    return dataLength;

}

int dataCodeToBitsSAF(char*bits,char* codeData,char bitStart){
	int i,j, dataLength=0;
	char temp;
	char mask;
	int m = bitStart;
	
		temp = codeData[i];
		mask = 0x01;
	//	LOGD("codeData %d =======> 0x%x \n ",i,codeData[i]);
		for (j=0;j<5;j++){

			if (temp&mask){
				bits[m++] = 1;
				bits[m++] = 1;
				dataLength+=2;
			}
			else {
				bits[m++] = 2;
				dataLength++;
			}
			temp >>= 1;
			
		//	LOGD("bits %d =======> %d \n ",m,bits[m]);
	
			}
		

  return dataLength;

}


/*
 * push bits to sendData
 */
char compressData (char* data,char* bits,int length,int start){
	int j=start;
	int i=0;
	char len=0;

	unsigned char t;
	while (length--){
		if (i%2==1){
			t = (bits[i]<<4);
			t &=0xf0;
			data[j]&=0x0f;
			data[j] |=t;
			j++;
	//	LOGD("data %d ed=======> 0x%x \n ",len,data[len]);

		}else {
			t &=0x0f;
			data[j]&=0xf0;
			data[j] |=bits[i];
			len++;
	//	LOGD("data %d st=======> 0x%x \n ",len,data[len]);

		}
		i++;
	}

	return len;
}



/*
 * get data xor value
 */
char getDataCRC(char* data,char length){
	char temp=0;
	int i;
	for (i=0;i<length;i++){
		temp ^=	data[i];
	//	LOGD("sendData %d =======> 0x%x  xor =========> 0x%x ",i,sendData[i],temp);
	}
	return temp;
}


int WrapUpSendData(char* sendData,char* data,char cmd,char length){
	int i;
	char xorData=0;
	xorData=getDataCRC(data,length);

	for (i=0;i!=length;i++){
		sendData[i+2]=data[i];
	}
	sendData[0] = cmd;
	sendData[1] = length;
	sendData[length+2] = xorData;
	return length+3;
}

int RC5data2bits(char*bits,char* codeData,char* bitLen,char length){
	int i,j, dataLength=0;
	char temp;
	char mask;
	int m = 0;
	for ( i=0;i<length;++i)
		{
		temp = codeData[i];
		mask = 0x01;
	//	LOGD("codeData %d =======> 0x%x \n ",i,codeData[i]);
		for (j=0;j<bitLen[i];j++){

			if (temp&mask){
				bits[m++] = 0;
				bits[m++] = 1;
			}
			else {
				bits[m++] = 1;
				bits[m++] = 0;
			}
			temp >>= 1;
			dataLength += 2;
		//	LOGD("bits %d =======> %d \n ",m,bits[m]);
			
			}
		}

  return dataLength;

}


int RC6data2bits(char*bits,char* codeData,char length){
	int i,j, dataLength=0;
	char temp;
	char mask;
	int m = 0;
	
		
		temp = codeData[0];
		mask = 0x80;
	//	LOGD("codeData %d =======> 0x%x \n ",i,codeData[i]);
		for (j=0;j<4;j++){

			if (temp&mask){
				bits[m++] = 1;
				bits[m++] = 0;
			}
			else {
				bits[m++] = 0;
				bits[m++] = 1;
			}
			temp <<= 1;
			dataLength += 2;
		//	LOGD("bits %d =======> %d \n ",m,bits[m]);
			
			}
		bits[m++]=0x00;
		dataLength++;
		bits[m++]=0x00;
		dataLength++;
		bits[m++]=0x01;
		dataLength++;
		bits[m++]=0x01;
		dataLength++;
		for (i=1;i<length+1;i++){
		temp = codeData[i];
		mask = 0x80;
	//	LOGD("codeData %d =======> 0x%x \n ",i,codeData[i]);
		for (j=0;j<8;j++){

			if (temp&mask){
				bits[m++] = 1;
				bits[m++] = 0;
			}
			else {
				bits[m++] = 0;
				bits[m++] = 1;
			}
			temp <<= 1;
			dataLength += 2;
		//	LOGD("bits %d =======> %d \n ",m,bits[m]);
			
			}
		}

		
  return dataLength;

}

int TCL2data2bits(char*bits,char* codeData,char length){
	int i,j, dataLength=0;
	char temp;
	char mask;
	int m = 0;
	
		for (i=0;i<length;i++){
		temp = codeData[i];
		mask = 0x01;
	//	LOGD("codeData %d =======> 0x%x \n ",i,codeData[i]);
		for (j=0;j<8;j++){

			if (temp&mask){
				bits[m++] = 0;
				bits[m++] = 1;
			}
			else {
				bits[m++] = 1;
				bits[m++] = 0;
			}
			temp >>= 1;
			dataLength += 2;
		//	LOGD("bits %d =======> %d \n ",m,bits[m]);
			
			}
		}

		
  return dataLength;

}


char edgeShiftLevel(char* bits,char* data,char length){
	char i=0,index=0,type,status =0;
	while (length--){
		if (data[index]){
			if (data[index+1]){		//	11
				if (data[index+2]){		//111
				LOGD("edgeshiftlevel out 111");
					return 0;
					}
				else {				// 110
						if (data[index+3]){		//1101
						index += 3;			//1101
						bits[i] = 4;
						i++;
						goto DATAOUT;
						}
					else {				// 1100
						if (data[index+4]){		//11001
							index += 4;			//11001
							bits[i] = 5;
							i++;
							goto DATAOUT;
							}
						else {				// 11000
						bits[i] = 4;
						i++;
						LOGD("edgeshiftlevel out 11000");
							return i;
							}
						}
					}
				}
			else {					//10
		//		LOGD("edgeshiftlevel  10   index =======> %d    data  =====> %d    ",index,data[index+2]);
				if (data[index+2]){	
					index += 2;			//101
					bits[i]=2;
					i++;
					goto DATAOUT;
				}
				else {			//	100
		//		LOGD("edgeshiftlevel  100   index =======> %d  data  =====> %d    ",index,data[index+3]);
					if (data[index+3]){		
					index += 3;			//1001
					bits[i] = 3;
					i++;
					goto DATAOUT;
					}
					else {			//	1000
					bits[i] = 2;
					i++;
		//			LOGD("edgeshiftlevel out 1000 index =======> %d  data  =====> %d    ",index,data[index+4]);
						return i;
					}
				}
			}
		
		}else {
		index++;
		}
		DATAOUT:

		LOGD("edgeshiftlevel index =======> %d   ",index);
		LOGD("edgeshiftlevel bits[%d] =======> 0x%x   ",i,bits[i]);
	}
	return i;

}

char TCLEdgeShiftLevel(char* bits,char* data,char start,char length){
	char i=start,index=0,type,status =0;
	while (length--){
		if (data[index]){
			if (data[index+1]){		//	11
				if (data[index+2]){		//111
				LOGD("edgeshiftlevel out 111");
					return 0;
					}
				else {				// 110
						if (data[index+3]){		//1101
						index += 3;			//1101
						bits[i] = 3;
						i++;
						goto DATAOUT;
						}
					else {				// 1100
						if (data[index+4]){		//11001
							index += 4;			//11001
							bits[i] = 4;
							i++;
							goto DATAOUT;
							}
						else {				// 11000
						bits[i] = 3;
						i++;
						LOGD("edgeshiftlevel out 11000");
							return (i-start);
							}
						}
					}
				}
			else {					//10
		//		LOGD("edgeshiftlevel  10   index =======> %d    data  =====> %d    ",index,data[index+2]);
				if (data[index+2]){	
					index += 2;			//101
					bits[i]=1;
					i++;
					goto DATAOUT;
				}
				else {			//	100
		//		LOGD("edgeshiftlevel  100   index =======> %d  data  =====> %d    ",index,data[index+3]);
					if (data[index+3]){		
					index += 3;			//1001
					bits[i] = 2;
					i++;
					goto DATAOUT;
					}
					else {			//	1000
					bits[i] = 1;
					i++;
		//			LOGD("edgeshiftlevel out 1000 index =======> %d  data  =====> %d    ",index,data[index+4]);
						return (i-start);
					}
				}
			}
		
		}else {
		index++;
		}
		DATAOUT:

		LOGD("edgeshiftlevel index =======> %d   ",index);
		LOGD("edgeshiftlevel bits[%d] =======> 0x%x   ",i,bits[i]);
	}
	return i;

}



void  bitsToByte(char* bits,char* data,char length){
	
	char i,j,temp;
	
	for (i=0;i<length;i++){
		temp = 0;
		for (j=0;j<8;j++){
			temp <<= 1;
			temp &= 0xfe;
			temp |= *bits++;
			}
		data[i] = temp;
		}
	
}


