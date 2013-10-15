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

#endif /* AIRCODE_H_ */
