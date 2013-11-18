/*
 * AirCode.h
 *
 *  Created on: 2013-10-10
 *      Author: work
 */

#ifndef CALCULATE_H_
#define CALCULATE_H_


#include "AirCode.h"

unsigned char HiBitFst(unsigned char low_first);
unsigned char CountBit(unsigned char air_byte);
void HBarray(unsigned char length, Air_para *Ch_para);
unsigned char GetZeron(unsigned char air_code);
void AdjustZero(Air_para *rmt_array);
unsigned char Sumarray(unsigned char codnum, Air_para *air_para);
void ShBitLft(unsigned char length,Air_para *Ch_para);
unsigned char NSarray(unsigned char length,Air_para *Ch_para);
unsigned char SBarray(unsigned char length,Air_para *Ch_para);


/*
 *   data to bitsdata left shift
 */
int airDataToBitsTypeR(char* bits,char* codeData,char bitStart,char dataLen,char dataLenOdd);
/*
 *   data to bitsdata left shift
 */
int airDataToBitsTypeL(char* bits,char* codeData,char bitStart,char dataLen,char dataLenOdd);

char edgeShiftLevel(char* bits,char* data,char length);
int RC5data2bits(char*bits,char* codeData,char* bitLen,char length);


/*
 * push bits to sendData
 */
char compressData (char* bits,char* data,int length,int start);
/*
 * get data xor value
 */
char getDataCRC(char* data,char length);

void shiftAirData(char* data,char shiftIndex,char length);
int WrapUpSendData(char* sendData,char* data,char cmd,char length);



#endif /* AIRCODE_H_ */
