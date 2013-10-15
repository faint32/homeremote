/*
 * AirCode.h
 *
 *  Created on: 2013-10-10
 *      Author: work
 */

#ifndef AIRCODE_H_
#define AIRCODE_H_

typedef struct
{
	unsigned char CARR;
	unsigned char STRU;
	unsigned char LDH_h;
	unsigned char LDH_l;
	unsigned char LDL_h;
	unsigned char LDL_l;
	unsigned char HIG_h;
	unsigned char HIG_l;
	unsigned char ZER_h;
	unsigned char ZER_l;
	unsigned char ONE_h;
	unsigned char ONE_l;
	unsigned char STO_h;
	unsigned char STO_l;
	unsigned char BIC0;
	unsigned char BIC1;
	unsigned char BIC2;
	unsigned char BIC3;
	unsigned char COD[64];
}Air_para;



#endif /* AIRCODE_H_ */
