
#include <string.h>
#include "logo.h"
#include "Calculate.h"
#include "AirCode.h"


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


