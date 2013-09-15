#include <jni.h>
#include <string.h>
#include <fcntl.h>
#include "logo.h"
#include "AirEncode.h"

#define DEBUG




static char CountBit(char air_byte){
	char i,temp=0;

	for(i=0;i<8;i++){
		if((air_byte>>i)&0x01){
			temp++;
		}
	}

	return temp;
}

char HiBitFst(char low_first)
{
	char i,j,temp=0;
	j = low_first;
	for(i=0;i!=8;i++)
	{
		temp<<=1;
		if(j&0x01)temp++;
		j>>= 1;
	}
	return temp;
}


void HBarray(char length, Air_para *Ch_para)
{
	char i;
	for(i=0;i<length;i++)Ch_para->COD[i]=HiBitFst(Ch_para->COD[i]);
}


char GetZeron(char air_code)
{
	char i,j,temp;
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
	char i,j,temp;
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

char Sumarray(char codnum, Air_para *air_para){
	char i,sum;
	for(i=0,sum=0;i<codnum;i++)
		sum+=air_para->COD[i];
	return sum;
}


void AirRemote000(AIR_status *air_status , Air_para *air_para){
	char i;
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x04;
	air_para->LDH_l=0x20;

	air_para->LDL_h=0x02;
	air_para->LDL_l=0x26;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0x86;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0x8c;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0x8d;


	air_para->BIC0=72;

	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[0]=0x01;
		break;

	case POWER_ON:
		air_para->COD[0]=0x05;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[1]|=0x00;
		break;

	case MODE_COLD:
		air_para->COD[1]|=0x08;
		break;

	case MODE_WET:
		air_para->COD[1]|=0x04;
		break;

	case MODE_WIND:
		air_para->COD[1]|=0x0c;
		break;

	case MODE_HOT:
		air_para->COD[1]|=0x02;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[2]=0x01;
		break;

	case SPEED_LOW:
		air_para->COD[2]=0x08;
		break;

	case SPEED_MEDIUM:
		air_para->COD[2]=0x04;
		break;

	case SPEED_HIGH:
		air_para->COD[2]=0x02;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[1]|=0x00;
		break;

	case TEMPER_17:
		air_para->COD[1]|=0x80;
		break;

	case TEMPER_18:
		air_para->COD[1]|=0x40;
		break;

	case TEMPER_19:
		air_para->COD[1]|=0xc0;
		break;

	case TEMPER_20:
		air_para->COD[1]|=0x20;
		break;

	case TEMPER_21:
		air_para->COD[1]|=0xa0;
		break;

	case TEMPER_22:
		air_para->COD[1]|=0x60;
		break;

	case TEMPER_23:
		air_para->COD[1]|=0xe0;
		break;

	case TEMPER_24:
		air_para->COD[1]|=0x10;
		break;

	case TEMPER_25:
		air_para->COD[1]|=0x90;
		break;

	case TEMPER_26:
		air_para->COD[1]|=0x50;
		break;

	case TEMPER_27:
		air_para->COD[1]|=0xd0;
		break;

	case TEMPER_28:
		air_para->COD[1]|=0x30;
		break;

	case TEMPER_29:
		air_para->COD[1]|=0xb0;
		break;

	case TEMPER_30:
		air_para->COD[1]|=0x70;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[2]|=0x00;
		break;

	case WIND_MANUAL:

		switch(air_status->vManualWind){
		case MANUAL_WIND_1:
			air_para->COD[2]|=0x20;
			break;
		case MANUAL_WIND_2:
			air_para->COD[2]|=0x80;
			break;
		case MANUAL_WIND_3:
			air_para->COD[2]|=0x40;
			break;
		case MANUAL_WIND_4:
			air_para->COD[2]|=0xc0;
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}

	air_para->COD[3]=0xc4;
	air_para->COD[4]=0x00;
	air_para->COD[5]=0x09;
	air_para->COD[6]=0x48;
	air_para->COD[7]=0x00;
	for(i=0;i!=8;i++)
		air_para->COD[i] = HiBitFst(air_para->COD[i]);

	air_para->COD[8]=(air_para->COD[0]+air_para->COD[1]+air_para->COD[2]+air_para->COD[3]+air_para->COD[4]+air_para->COD[5]+air_para->COD[6]+air_para->COD[7]);

}


void AirRemote001(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x04;
	air_para->LDH_l=0x29;

	air_para->LDL_h=0x02;
	air_para->LDL_l=0x1c;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0x92;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0x8a;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0x80;


	air_para->BIC0=112;

	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[5]=0x20;
		break;

	case POWER_ON:
		air_para->COD[5]=0x24;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[6]|=0x08;
		break;

	case MODE_COLD:
		air_para->COD[6]|=0x03;
		break;

	case MODE_WET:
		air_para->COD[6]|=0x02;
		break;

	case MODE_WIND:
		air_para->COD[6]|=0x07;
		break;

	case MODE_HOT:
		air_para->COD[6]|=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[8]=0x00;
		break;

	case SPEED_LOW:
		air_para->COD[8]=0x02;
		break;

	case SPEED_MEDIUM:
		air_para->COD[8]=0x03;
		break;

	case SPEED_HIGH:
		air_para->COD[8]=0x05;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[7]=0x8f;
		break;

	case TEMPER_17:
		air_para->COD[7]=0x8e;
		break;

	case TEMPER_18:
		air_para->COD[7]=0x8d;
		break;

	case TEMPER_19:
		air_para->COD[7]=0x8c;
		break;

	case TEMPER_20:
		air_para->COD[7]=0x8b;
		break;

	case TEMPER_21:
		air_para->COD[7]=0x8a;
		break;

	case TEMPER_22:
		air_para->COD[7]=0x89;
		break;

	case TEMPER_23:
		air_para->COD[7]=0x88;
		break;

	case TEMPER_24:
		air_para->COD[7]=0x87;
		break;

	case TEMPER_25:
		air_para->COD[7]=0x86;
		break;

	case TEMPER_26:
		air_para->COD[7]=0x85;
		break;

	case TEMPER_27:
		air_para->COD[7]=0x84;
		break;

	case TEMPER_28:
		air_para->COD[7]=0x83;
		break;

	case TEMPER_29:
		air_para->COD[7]=0x82;
		break;

	case TEMPER_30:
		air_para->COD[7]=0x81;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[8]|=0x38;
		break;

	case WIND_MANUAL:

		switch(air_status->vManualWind){
		case MANUAL_WIND_1:
			air_para->COD[8]|=0x00;
			break;
		case MANUAL_WIND_2:
			air_para->COD[8]|=0x10;
			break;
		case MANUAL_WIND_3:
			air_para->COD[8]|=0x20;
			break;
		case MANUAL_WIND_4:
			air_para->COD[8]|=0x28;
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}

	air_para->COD[0]=0x23;
	air_para->COD[1]=0xcb;
	air_para->COD[2]=0x26;
	air_para->COD[3]=0x01;
	air_para->COD[4]=0x00;
	air_para->COD[9]=0x00;
	air_para->COD[10]=0x00;
	air_para->COD[11]=0x00;
	air_para->COD[12]=0x00;

	air_para->COD[13]=(air_para->COD[0]+air_para->COD[1]+air_para->COD[2]+air_para->COD[3]+air_para->COD[4]+air_para->COD[5]+air_para->COD[6]+air_para->COD[7]+air_para->COD[8]+air_para->COD[9]+air_para->COD[10]+air_para->COD[11]+air_para->COD[12]);

}



void AirRemote002(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x01;


	air_para->LDH_h=0x07;
	air_para->LDH_l=0x2e;

	air_para->LDL_h=0x08;
	air_para->LDL_l=0xca;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xae;

	air_para->ZER_h=0x01;
	air_para->ZER_l=0xb5;

	air_para->ONE_h=0x04;
	air_para->ONE_l=0x14;

	air_para->STO_h=0x08;
	air_para->STO_l=0xca;


	air_para->BIC0=48;


	switch(air_status->vPower){

		case POWER_OFF:
			air_para->COD[3]|=0x00;
			break;

		case POWER_ON:
			air_para->COD[3]|=0x08;
			break;

		default:
			break;
	}

	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[3]|=0x00;
			break;

		case MODE_COLD:
			air_para->COD[3]|=0x01;
			break;

		case MODE_WET:
			air_para->COD[3]|=0x02;
			break;

		case MODE_WIND:
			air_para->COD[3]|=0x03;
			break;

		case MODE_HOT:
			air_para->COD[3]|=0x04;
			break;

		default:
			break;
	}

	switch(air_status->vSpeed){

		case SPEED_AUTO:
			air_para->COD[1]|=0x00;
			break;

		case SPEED_LOW:
			air_para->COD[1]|=0xc0;
			break;

		case SPEED_MEDIUM:
			air_para->COD[1]|=0x80;
			break;

		case SPEED_HIGH:
			air_para->COD[1]|=0x40;
			break;

		default:
			break;
	}

	switch(air_status->vTemper){

		case TEMPER_16:
			air_para->COD[3]|=0x10;
			break;

		case TEMPER_17:
			air_para->COD[3]|=0x10;
			break;

		case TEMPER_18:
			air_para->COD[3]|=0x10;
			break;

		case TEMPER_19:
			air_para->COD[3]|=0x20;
			break;

		case TEMPER_20:
			air_para->COD[3]|=0x30;
			break;

		case TEMPER_21:
			air_para->COD[3]|=0x40;
			break;

		case TEMPER_22:
			air_para->COD[3]|=0x50;
			break;

		case TEMPER_23:
			air_para->COD[3]|=0x60;
			break;

		case TEMPER_24:
			air_para->COD[3]|=0x70;
			break;

		case TEMPER_25:
			air_para->COD[3]|=0x80;
			break;

		case TEMPER_26:
			air_para->COD[3]|=0x90;
			break;

		case TEMPER_27:
			air_para->COD[3]|=0xa0;
			break;

		case TEMPER_28:
			air_para->COD[3]|=0xb0;
			break;

		case TEMPER_29:
			air_para->COD[3]|=0xc0;
			break;

		case TEMPER_30:
			air_para->COD[3]|=0xd0;
			break;

		default:
			break;
	}

	switch(air_status->vWind){

		case WIND_AUTO:
			air_para->COD[1]|=0x08;
			break;

		case WIND_MANUAL:
			air_para->COD[1]|=0x10;
			break;

		default:
			break;
	}

	air_para->COD[0]=~(air_para->COD[1]);
	air_para->COD[2]=~(air_para->COD[3]);
	air_para->COD[4]=0x2a;
	air_para->COD[5]=~(air_para->COD[4]);
}


void AirRemote003(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x02;


	air_para->LDH_h=0x05;
	air_para->LDH_l=0x52;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x40;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xb4;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0x99;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0xfd;

	air_para->STO_h=0x06;
	air_para->STO_l=0x62;


	air_para->BIC0=48;
	air_para->BIC1=48;


	switch(air_status->vSpeed){

		case SPEED_AUTO:
			air_para->COD[2]=0xfd;
			break;

		case SPEED_LOW:
			air_para->COD[2]=0xf9;
			break;

		case SPEED_MEDIUM:
			air_para->COD[2]=0xfa;
			break;

		case SPEED_HIGH:
			air_para->COD[2]=0xfc;
			break;

		default:
			break;
	}

	switch(air_status->vTemper){

		case TEMPER_16:
			air_para->COD[4]|=0x00;
			break;

		case TEMPER_17:
			air_para->COD[4]|=0x00;
			break;

		case TEMPER_18:
			air_para->COD[4]|=0x08;
			break;

		case TEMPER_19:
			air_para->COD[4]|=0x0c;
			break;

		case TEMPER_20:
			air_para->COD[4]|=0x04;
			break;

		case TEMPER_21:
			air_para->COD[4]|=0x06;
			break;

		case TEMPER_22:
			air_para->COD[4]|=0x0e;
			break;

		case TEMPER_23:
			air_para->COD[4]|=0x0a;
			break;

		case TEMPER_24:
			air_para->COD[4]|=0x02;
			break;

		case TEMPER_25:
			air_para->COD[4]|=0x03;
			break;

		case TEMPER_26:
			air_para->COD[4]|=0x0b;
			break;

		case TEMPER_27:
			air_para->COD[4]|=0x09;
			break;

		case TEMPER_28:
			air_para->COD[4]|=0x01;
			break;

		case TEMPER_29:
			air_para->COD[4]|=0x05;
			break;

		case TEMPER_30:
			air_para->COD[4]|=0x0d;
			break;

		default:
			break;
	}


	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[2]=0xf8;
			air_para->COD[4]|=0x10;
			break;

		case MODE_COLD:
			air_para->COD[4]|=0x00;
			break;

		case MODE_WET:
			air_para->COD[2]=0xf8;
			air_para->COD[4]|=0x20;
			break;

		case MODE_WIND:
			air_para->COD[4]=0x27;
			break;

		case MODE_HOT:
			air_para->COD[4]|=0x30;
			break;

		default:
			break;
	}


	switch(air_status->vKey){

		case POWER_KEY:

			switch(air_status->vPower){

				case POWER_OFF:
					air_para->COD[2]=0xde;
					air_para->COD[4]=0x07;
					break;

				case POWER_ON:
					break;

				default:
					break;
			}
			break;

		case WIND_MANUAL_KEY:
			air_para->COD[2]=0xf0;
			air_para->COD[4]=0x07;
			break;

		case WIND_AUTO_KEY:
			air_para->COD[2]=0xd6;
			air_para->COD[4]=0x07;
			break;

		default:
			break;
	}


	air_para->COD[0]=0x4d;
	air_para->COD[1]=~(air_para->COD[0]);
	air_para->COD[3]=~(air_para->COD[2]);
	air_para->COD[5]=~(air_para->COD[4]);

	air_para->COD[6]=air_para->COD[0];
	air_para->COD[7]=air_para->COD[1];
	air_para->COD[8]=air_para->COD[2];
	air_para->COD[9]=air_para->COD[3];
	air_para->COD[10]=air_para->COD[4];
	air_para->COD[11]=air_para->COD[5];

}



void AirRemote005(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x02;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xd6;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0xbe;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xac;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xf0;

	air_para->ONE_h=0x02;
	air_para->ONE_l=0x4a;

	air_para->STO_h=0x97;
	air_para->STO_l=0xd3;


	air_para->BIC0=32;
	air_para->BIC1=32;


	switch(air_status->vSpeed){

		case SPEED_AUTO:
			air_para->COD[1]|=0x00;
			break;

		case SPEED_LOW:
			air_para->COD[1]|=0x10;
			break;

		case SPEED_MEDIUM:
			air_para->COD[1]|=0x20;
			break;

		case SPEED_HIGH:
			air_para->COD[1]|=0x30;
			break;

		default:
			break;
	}

	switch(air_status->vTemper){

		case TEMPER_16:
			air_para->COD[2]=0x10;
			break;

		case TEMPER_17:
			air_para->COD[2]=0x11;
			break;

		case TEMPER_18:
			air_para->COD[2]=0x12;
			break;

		case TEMPER_19:
			air_para->COD[2]=0x13;
			break;

		case TEMPER_20:
			air_para->COD[2]=0x14;
			break;

		case TEMPER_21:
			air_para->COD[2]=0x15;
			break;

		case TEMPER_22:
			air_para->COD[2]=0x16;
			break;

		case TEMPER_23:
			air_para->COD[2]=0x17;
			break;

		case TEMPER_24:
			air_para->COD[2]=0x18;
			break;

		case TEMPER_25:
			air_para->COD[2]=0x19;
			break;

		case TEMPER_26:
			air_para->COD[2]=0x1a;
			break;

		case TEMPER_27:
			air_para->COD[2]=0x1b;
			break;

		case TEMPER_28:
			air_para->COD[2]=0x1c;
			break;

		case TEMPER_29:
			air_para->COD[2]=0x1d;
			break;

		case TEMPER_30:
			air_para->COD[2]=0x1e;
			break;

		default:
			break;
	}


	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[1]|=0x00;
			break;

		case MODE_COLD:
			air_para->COD[1]|=0x01;
			break;

		case MODE_WET:
			air_para->COD[1]|=0x02;
			break;

		case MODE_WIND:
			air_para->COD[1]|=0x03;
			break;

		case MODE_HOT:
			air_para->COD[1]|=0x04;
			break;

		default:
			break;
	}


	switch(air_status->vKey){

		case POWER_KEY:

			switch(air_status->vPower){

				case POWER_OFF:
					air_para->COD[1]|=0x80;
					break;

				case POWER_ON:
					air_para->COD[1]|=0x80;
					break;

				default:
					break;
			}
			break;

		default:
			break;
	}


	air_para->COD[0]=0xc0;
	air_para->COD[3]=~((air_para->COD[0])+(air_para->COD[1])+(air_para->COD[2]));

	air_para->COD[4]=air_para->COD[0];
	air_para->COD[5]=air_para->COD[1];
	air_para->COD[6]=air_para->COD[2];
	air_para->COD[7]=air_para->COD[3];

}



void AirRemote006(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x04;
	air_para->LDH_l=0x14;

	air_para->LDL_h=0x04;
	air_para->LDL_l=0x1d;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0x70;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0x97;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0x9c;


	air_para->BIC0=104;

	switch(air_status->vKey){

	case POWER_KEY:
		air_para->COD[11]=0x08;
		break;

	case MODE_KEY:
		air_para->COD[11]=0x00;
		break;

	case SPEED_KEY:
		air_para->COD[11]=0x00;
		break;

	case TEMPER_INC_KEY:
		air_para->COD[11]=0x00;
		break;

	case TEMPER_DEC_KEY:
		air_para->COD[11]=0x00;
		break;

	case WIND_MANUAL_KEY:
		air_para->COD[11]=0x20;
		break;

	case WIND_AUTO_KEY:
		air_para->COD[11]=0x20;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[5]|=0x07;
		break;

	case MODE_COLD:
		air_para->COD[5]|=0x06;
		break;

	case MODE_WET:
		air_para->COD[5]|=0x04;
		break;

	case MODE_WIND:
		air_para->COD[5]|=0x02;
		break;

	case MODE_HOT:
		air_para->COD[5]|=0x09;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[5]|=0x80;
		break;

	case SPEED_LOW:
		air_para->COD[5]|=0x10;
		break;

	case SPEED_MEDIUM:
		air_para->COD[5]|=0x20;
		break;

	case SPEED_HIGH:
		air_para->COD[5]|=0x40;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[6]=0x13;
		break;

	case TEMPER_17:
		air_para->COD[6]=0x15;
		break;

	case TEMPER_18:
		air_para->COD[6]=0x17;
		break;

	case TEMPER_19:
		air_para->COD[6]=0x19;
		break;

	case TEMPER_20:
		air_para->COD[6]=0x1b;
		break;

	case TEMPER_21:
		air_para->COD[6]=0x1d;
		break;

	case TEMPER_22:
		air_para->COD[6]=0x1f;
		break;

	case TEMPER_23:
		air_para->COD[6]=0x21;
		break;

	case TEMPER_24:
		air_para->COD[6]=0x23;
		break;

	case TEMPER_25:
		air_para->COD[6]=0x25;
		break;

	case TEMPER_26:
		air_para->COD[6]=0x27;
		break;

	case TEMPER_27:
		air_para->COD[6]=0x29;
		break;

	case TEMPER_28:
		air_para->COD[6]=0x2b;
		break;

	case TEMPER_29:
		air_para->COD[6]=0x2d;
		break;

	case TEMPER_30:
		air_para->COD[6]=0x2f;
		break;

	default:
		break;
	}


	air_para->COD[0]=0x4d;
	air_para->COD[1]=0x75;
	air_para->COD[2]=0xb2;
	air_para->COD[3]=0x8a;
	air_para->COD[4]=0x0f;
	air_para->COD[7]=0x00;
	air_para->COD[8]=0x00;
	air_para->COD[9]=0x00;
	air_para->COD[10]=0x00;

	air_para->COD[12]=(( (air_para->COD[0]>>4)+(air_para->COD[0]&0x0f)+
						 (air_para->COD[1]>>4)+(air_para->COD[1]&0x0f)+
						 (air_para->COD[2]>>4)+(air_para->COD[2]&0x0f)+
						 (air_para->COD[3]>>4)+(air_para->COD[3]&0x0f)+
						 (air_para->COD[4]>>4)+(air_para->COD[4]&0x0f)+
						 (air_para->COD[5]>>4)+(air_para->COD[5]&0x0f)+
						 (air_para->COD[6]>>4)+(air_para->COD[6]&0x0f)+
						 (air_para->COD[7]>>4)+(air_para->COD[7]&0x0f)+
						 (air_para->COD[8]>>4)+(air_para->COD[8]&0x0f)+
						 (air_para->COD[9]>>4)+(air_para->COD[9]&0x0f)+
						 (air_para->COD[10]>>4)+(air_para->COD[10]&0x0f)+
						 (air_para->COD[11]>>4)+(air_para->COD[11]&0x0f)-
						 0x0b)&0x0f|0x10);
}


void AirRemote008(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x07;
	air_para->LDH_l=0xaa;

	air_para->LDL_h=0x08;
	air_para->LDL_l=0x4a;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xa1;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xa0;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0xee;


	air_para->BIC0=46;


	air_para->COD[1]=0xc0;
	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[1]&=0xc7;
		break;

	case POWER_ON:
		air_para->COD[1]|=0x38;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[1]|=0x00;
		break;

	case MODE_COLD:
		air_para->COD[1]|=0x04;
		break;

	case MODE_WET:
		air_para->COD[1]|=0x02;
		break;

	case MODE_WIND:
		air_para->COD[1]|=0x01;
		break;

	case MODE_HOT:
		air_para->COD[1]|=0x07;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[2]=0x00;
		break;

	case SPEED_LOW:
		air_para->COD[2]=0x10;
		break;

	case SPEED_MEDIUM:
		air_para->COD[2]=0x30;
		break;

	case SPEED_HIGH:
		air_para->COD[2]=0x50;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[3]=0x02;
		break;

	case TEMPER_17:
		air_para->COD[3]=0x02;
		break;

	case TEMPER_18:
		air_para->COD[3]=0x02;
		break;

	case TEMPER_19:
		air_para->COD[3]=0x03;
		break;

	case TEMPER_20:
		air_para->COD[3]=0x04;
		break;

	case TEMPER_21:
		air_para->COD[3]=0x05;
		break;

	case TEMPER_22:
		air_para->COD[3]=0x06;
		break;

	case TEMPER_23:
		air_para->COD[3]=0x07;
		break;

	case TEMPER_24:
		air_para->COD[3]=0x08;
		break;

	case TEMPER_25:
		air_para->COD[3]=0x09;
		break;

	case TEMPER_26:
		air_para->COD[3]=0x0a;
		break;

	case TEMPER_27:
		air_para->COD[3]=0x0b;
		break;

	case TEMPER_28:
		air_para->COD[3]=0x0c;
		break;

	case TEMPER_29:
		air_para->COD[3]=0x0d;
		break;

	case TEMPER_30:
		air_para->COD[3]=0x0e;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[2]|=0x08;
		break;

	case WIND_MANUAL:

		switch(air_status->vManualWind){
		case MANUAL_WIND_1:
			air_para->COD[2]|=0x01;
			break;
		case MANUAL_WIND_2:
			air_para->COD[2]|=0x02;
			break;
		case MANUAL_WIND_3:
			air_para->COD[2]|=0x03;
			break;
		case MANUAL_WIND_4:
			air_para->COD[2]|=0x04;
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}

	air_para->COD[0]=0x15;
	air_para->COD[4]=0x1e;

	air_para->COD[5]=(CountBit(air_para->COD[0])+CountBit(air_para->COD[1])+CountBit(air_para->COD[2])+CountBit(air_para->COD[3])+CountBit(air_para->COD[4]))<<2;

	air_para->COD[0]=HiBitFst(air_para->COD[0]);
	air_para->COD[1]=HiBitFst(air_para->COD[1]);
	air_para->COD[2]=HiBitFst(air_para->COD[2]);
	air_para->COD[3]=HiBitFst(air_para->COD[3]);
	air_para->COD[4]=HiBitFst(air_para->COD[4]);
	air_para->COD[5]=HiBitFst(air_para->COD[5]);

}




void AirRemote010(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x07;
	air_para->LDH_l=0x88;

	air_para->LDL_h=0x07;
	air_para->LDL_l=0x92;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0x95;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xa1;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0xcb;


	air_para->BIC0=48;


	air_para->COD[1]=0xc0;


	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[1]|=0x00;
		break;

	case MODE_COLD:
		air_para->COD[1]|=0x04;
		break;

	case MODE_WET:
		air_para->COD[1]|=0x07;
		break;

	case MODE_WIND:
		air_para->COD[1]|=0x01;
		break;

	case MODE_HOT:
		air_para->COD[1]|=0x02;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[2]=0x00;
		break;

	case SPEED_LOW:
		air_para->COD[2]=0x10;
		break;

	case SPEED_MEDIUM:
		air_para->COD[2]=0x30;
		break;

	case SPEED_HIGH:
		air_para->COD[2]=0x50;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[3]=0x02;
		break;

	case TEMPER_17:
		air_para->COD[3]=0x02;
		break;

	case TEMPER_18:
		air_para->COD[3]=0x02;
		break;

	case TEMPER_19:
		air_para->COD[3]=0x03;
		break;

	case TEMPER_20:
		air_para->COD[3]=0x04;
		break;

	case TEMPER_21:
		air_para->COD[3]=0x05;
		break;

	case TEMPER_22:
		air_para->COD[3]=0x06;
		break;

	case TEMPER_23:
		air_para->COD[3]=0x07;
		break;

	case TEMPER_24:
		air_para->COD[3]=0x08;
		break;

	case TEMPER_25:
		air_para->COD[3]=0x09;
		break;

	case TEMPER_26:
		air_para->COD[3]=0x0a;
		break;

	case TEMPER_27:
		air_para->COD[3]=0x0b;
		break;

	case TEMPER_28:
		air_para->COD[3]=0x0c;
		break;

	case TEMPER_29:
		air_para->COD[3]=0x0d;
		break;

	case TEMPER_30:
		air_para->COD[3]=0x0e;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[2]|=0x00;
		air_para->COD[3]|=0x40;
		break;

	case WIND_MANUAL:

		switch(air_status->vManualWind){
		case MANUAL_WIND_1:
			air_para->COD[2]|=0x00;
			break;
		case MANUAL_WIND_2:
			air_para->COD[2]|=0x01;
			break;
		case MANUAL_WIND_3:
			air_para->COD[2]|=0x02;
			break;
		case MANUAL_WIND_4:
			air_para->COD[2]|=0x03;
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}


	switch(air_status->vPower){

		case POWER_OFF:
			air_para->COD[1]=0xc0;
			break;

		case POWER_ON:
			air_para->COD[1]|=0x38;
			break;

		default:
			break;
	}

	air_para->COD[0]=0x15;
	air_para->COD[4]=0x00;

	air_para->COD[5]=(CountBit(air_para->COD[0])+CountBit(air_para->COD[1])+CountBit(air_para->COD[2])+CountBit(air_para->COD[3])+CountBit(air_para->COD[4]));

	air_para->COD[0]=HiBitFst(air_para->COD[0]);
	air_para->COD[1]=HiBitFst(air_para->COD[1]);
	air_para->COD[2]=HiBitFst(air_para->COD[2]);
	air_para->COD[3]=HiBitFst(air_para->COD[3]);
	air_para->COD[4]=HiBitFst(air_para->COD[4]);
	air_para->COD[5]=HiBitFst(air_para->COD[5]);

}



void AirRemote011(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x01;


	air_para->LDH_h=0x07;
	air_para->LDH_l=0x2e;

	air_para->LDL_h=0x08;
	air_para->LDL_l=0xca;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xae;

	air_para->ZER_h=0x01;
	air_para->ZER_l=0xb5;

	air_para->ONE_h=0x04;
	air_para->ONE_l=0x14;

	air_para->STO_h=0x08;
	air_para->STO_l=0xca;


	air_para->BIC0=48;


	switch(air_status->vPower){

		case POWER_OFF:
			air_para->COD[3]|=0x00;
			break;

		case POWER_ON:
			air_para->COD[3]|=0x08;
			break;

		default:
			break;
	}

	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[3]|=0x00;
			break;

		case MODE_COLD:
			air_para->COD[3]|=0x01;
			break;

		case MODE_WET:
			air_para->COD[3]|=0x02;
			break;

		case MODE_WIND:
			air_para->COD[3]|=0x03;
			break;

		case MODE_HOT:
			air_para->COD[3]|=0x04;
			break;

		default:
			break;
	}

	switch(air_status->vSpeed){

		case SPEED_AUTO:
			air_para->COD[1]|=0x00;
			break;

		case SPEED_LOW:
			air_para->COD[1]|=0xc0;
			break;

		case SPEED_MEDIUM:
			air_para->COD[1]|=0x80;
			break;

		case SPEED_HIGH:
			air_para->COD[1]|=0x40;
			break;

		default:
			break;
	}

	switch(air_status->vTemper){

		case TEMPER_16:
			air_para->COD[3]|=0x10;
			break;

		case TEMPER_17:
			air_para->COD[3]|=0x10;
			break;

		case TEMPER_18:
			air_para->COD[3]|=0x10;
			break;

		case TEMPER_19:
			air_para->COD[3]|=0x20;
			break;

		case TEMPER_20:
			air_para->COD[3]|=0x30;
			break;

		case TEMPER_21:
			air_para->COD[3]|=0x40;
			break;

		case TEMPER_22:
			air_para->COD[3]|=0x50;
			break;

		case TEMPER_23:
			air_para->COD[3]|=0x60;
			break;

		case TEMPER_24:
			air_para->COD[3]|=0x70;
			break;

		case TEMPER_25:
			air_para->COD[3]|=0x80;
			break;

		case TEMPER_26:
			air_para->COD[3]|=0x90;
			break;

		case TEMPER_27:
			air_para->COD[3]|=0xa0;
			break;

		case TEMPER_28:
			air_para->COD[3]|=0xb0;
			break;

		case TEMPER_29:
			air_para->COD[3]|=0xc0;
			break;

		case TEMPER_30:
			air_para->COD[3]|=0xd0;
			break;

		default:
			break;
	}

	switch(air_status->vWind){

		case WIND_AUTO:
			air_para->COD[1]|=0x08;
			break;

		case WIND_MANUAL:
			air_para->COD[1]|=0x10;
			break;

		default:
			break;
	}

	air_para->COD[0]=~(air_para->COD[1]);
	air_para->COD[2]=~(air_para->COD[3]);
	air_para->COD[4]=0x2a;
	air_para->COD[5]=~(air_para->COD[4]);
}



void AirRemote012(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x04;
	air_para->LDH_l=0x29;

	air_para->LDL_h=0x02;
	air_para->LDL_l=0x1c;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0x92;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0x8a;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0x80;


	air_para->BIC0=112;

	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[5]=0x20;
		break;

	case POWER_ON:
		air_para->COD[5]=0x24;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[6]|=0x08;
		break;

	case MODE_COLD:
		air_para->COD[6]|=0x03;
		break;

	case MODE_WET:
		air_para->COD[6]|=0x02;
		break;

	case MODE_WIND:
		air_para->COD[6]|=0x07;
		break;

	case MODE_HOT:
		air_para->COD[6]|=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[8]=0x00;
		break;

	case SPEED_LOW:
		air_para->COD[8]=0x02;
		break;

	case SPEED_MEDIUM:
		air_para->COD[8]=0x03;
		break;

	case SPEED_HIGH:
		air_para->COD[8]=0x05;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[7]=0x0f;
		break;

	case TEMPER_17:
		air_para->COD[7]=0x0e;
		break;

	case TEMPER_18:
		air_para->COD[7]=0x0d;
		break;

	case TEMPER_19:
		air_para->COD[7]=0x0c;
		break;

	case TEMPER_20:
		air_para->COD[7]=0x0b;
		break;

	case TEMPER_21:
		air_para->COD[7]=0x0a;
		break;

	case TEMPER_22:
		air_para->COD[7]=0x09;
		break;

	case TEMPER_23:
		air_para->COD[7]=0x08;
		break;

	case TEMPER_24:
		air_para->COD[7]=0x07;
		break;

	case TEMPER_25:
		air_para->COD[7]=0x06;
		break;

	case TEMPER_26:
		air_para->COD[7]=0x05;
		break;

	case TEMPER_27:
		air_para->COD[7]=0x04;
		break;

	case TEMPER_28:
		air_para->COD[7]=0x03;
		break;

	case TEMPER_29:
		air_para->COD[7]=0x02;
		break;

	case TEMPER_30:
		air_para->COD[7]=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[8]|=0x38;
		break;

	case WIND_MANUAL:

		switch(air_status->vManualWind){
		case MANUAL_WIND_1:
			air_para->COD[8]|=0x00;
			break;
		case MANUAL_WIND_2:
			air_para->COD[8]|=0x10;
			break;
		case MANUAL_WIND_3:
			air_para->COD[8]|=0x20;
			break;
		case MANUAL_WIND_4:
			air_para->COD[8]|=0x28;
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}

	air_para->COD[0]=0x23;
	air_para->COD[1]=0xcb;
	air_para->COD[2]=0x26;
	air_para->COD[3]=0x01;
	air_para->COD[4]=0x00;
	air_para->COD[9]=0x00;
	air_para->COD[10]=0x00;
	air_para->COD[11]=0x00;
	air_para->COD[12]=0x00;

	air_para->COD[13]=(air_para->COD[0]+air_para->COD[1]+air_para->COD[2]+air_para->COD[3]+air_para->COD[4]+air_para->COD[5]+air_para->COD[6]+air_para->COD[7]+air_para->COD[8]+air_para->COD[9]+air_para->COD[10]+air_para->COD[11]+air_para->COD[12]);

}


void AirRemote013(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xfc;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x7e;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xb2;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xd3;

	air_para->ONE_h=0x02;
	air_para->ONE_l=0x1f;


	air_para->BIC0=80;


	switch(air_status->vKey){

		case POWER_KEY:
			air_para->COD[0]=0x03;
			break;

		case MODE_KEY:
			air_para->COD[0]=0x04;
			break;

		case SPEED_KEY:
			air_para->COD[0]=0x00;
			break;

		case TEMPER_INC_KEY:
			air_para->COD[0]=0x01;
			break;

		case TEMPER_DEC_KEY:
			air_para->COD[0]=0x02;
			break;

		case WIND_MANUAL_KEY:
			air_para->COD[0]=0x08;
			break;

		case WIND_AUTO_KEY:
			air_para->COD[0]=0x07;
			break;

		default:
			break;
	}


	switch(air_status->vPower){

		case POWER_OFF:
			air_para->COD[0]&=0x7f;
			break;

		case POWER_ON:
			air_para->COD[0]|=0x80;
			break;

		default:
			break;
	}

	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[0]|=0x40;
			break;

		case MODE_COLD:
			air_para->COD[0]|=0x00;
			break;

		case MODE_WET:
			air_para->COD[0]|=0x10;
			break;

		case MODE_WIND:
			air_para->COD[0]|=0x20;
			break;

		case MODE_HOT:
			air_para->COD[0]|=0x30;
			break;

		default:
			break;
	}

	switch(air_status->vSpeed){

		case SPEED_AUTO:
			air_para->COD[1]=0x00;
			break;

		case SPEED_LOW:
			air_para->COD[1]=0x30;
			break;

		case SPEED_MEDIUM:
			air_para->COD[1]=0x20;
			break;

		case SPEED_HIGH:
			air_para->COD[1]=0x10;
			break;

		default:
			break;
	}

	switch(air_status->vTemper){

		case TEMPER_16:
			air_para->COD[1]|=0x01;
			break;

		case TEMPER_17:
			air_para->COD[1]|=0x02;
			break;

		case TEMPER_18:
			air_para->COD[1]|=0x03;
			break;

		case TEMPER_19:
			air_para->COD[1]|=0x04;
			break;

		case TEMPER_20:
			air_para->COD[1]|=0x05;
			break;

		case TEMPER_21:
			air_para->COD[1]|=0x06;
			break;

		case TEMPER_22:
			air_para->COD[1]|=0x07;
			break;

		case TEMPER_23:
			air_para->COD[1]|=0x08;
			break;

		case TEMPER_24:
			air_para->COD[1]|=0x09;
			break;

		case TEMPER_25:
			air_para->COD[1]|=0x0a;
			break;

		case TEMPER_26:
			air_para->COD[1]|=0x0b;
			break;

		case TEMPER_27:
			air_para->COD[1]|=0x0c;
			break;

		case TEMPER_28:
			air_para->COD[1]|=0x0d;
			break;

		case TEMPER_29:
			air_para->COD[1]|=0x0e;
			break;

		case TEMPER_30:
			air_para->COD[1]|=0x0f;
			break;

		default:
			break;
	}

	switch(air_status->vWind){

		case WIND_AUTO:
			air_para->COD[2]|=0x04;
			break;

		case WIND_MANUAL:
			air_para->COD[2]|=0x00;
			break;

		default:
			break;
	}

	air_para->COD[3]=0x00;
	air_para->COD[4]=0x00;
	air_para->COD[5]=0x00;
	air_para->COD[6]=0x00;
	air_para->COD[7]=0x03;
	air_para->COD[8]=0x00;
	air_para->COD[9]=0xcc;

}



void AirRemote014(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xe9;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x78;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xb2;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xbb;

	air_para->ONE_h=0x02;
	air_para->ONE_l=0x22;


	air_para->BIC0=84;

	air_para->COD[2] = 0x10;
	switch(air_status->vKey){

	case POWER_KEY:
		air_para->COD[0]=0x03;
		break;

	case MODE_KEY:
		air_para->COD[0]=0x04;
		break;

	case SPEED_KEY:
		air_para->COD[0]=0x06;
		break;

	case TEMPER_INC_KEY:
		air_para->COD[0]=0x01;
		break;

	case TEMPER_DEC_KEY:
		air_para->COD[0]=0x02;
		break;

	case WIND_MANUAL_KEY:
		air_para->COD[0]=0x08;
		break;

	case WIND_AUTO_KEY:
		air_para->COD[0]=0x07;
		break;

	default:
		break;
	}


	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[0]&=0x7f;
		air_para->COD[2] |= 0x20;
		break;

	case POWER_ON:
		air_para->COD[0]|=0x80;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[0]|=0x40;
		break;

	case MODE_COLD:
		air_para->COD[0]|=0x00;
		break;

	case MODE_WET:
		air_para->COD[0]|=0x10;
		break;

	case MODE_WIND:
		air_para->COD[0]|=0x20;
		break;

	case MODE_HOT:
		air_para->COD[0]|=0x30;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[1]=0x00;
		break;

	case SPEED_LOW:
		air_para->COD[1]=0x10;
		break;

	case SPEED_MEDIUM:
		air_para->COD[1]=0x20;
		break;

	case SPEED_HIGH:
		air_para->COD[1]=0x30;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[1]|=0x00;
		break;

	case TEMPER_17:
		air_para->COD[1]|=0x01;
		break;

	case TEMPER_18:
		air_para->COD[1]|=0x02;
		break;

	case TEMPER_19:
		air_para->COD[1]|=0x03;
		break;

	case TEMPER_20:
		air_para->COD[1]|=0x04;
		break;

	case TEMPER_21:
		air_para->COD[1]|=0x05;
		break;

	case TEMPER_22:
		air_para->COD[1]|=0x06;
		break;

	case TEMPER_23:
		air_para->COD[1]|=0x07;
		break;

	case TEMPER_24:
		air_para->COD[1]|=0x08;
		break;

	case TEMPER_25:
		air_para->COD[1]|=0x09;
		break;

	case TEMPER_26:
		air_para->COD[1]|=0x0a;
		break;

	case TEMPER_27:
		air_para->COD[1]|=0x0b;
		break;

	case TEMPER_28:
		air_para->COD[1]|=0x0c;
		break;

	case TEMPER_29:
		air_para->COD[1]|=0x0d;
		break;

	case TEMPER_30:
		air_para->COD[1]|=0x0e;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[2] |= 0x04;
		break;

	case WIND_MANUAL:

		break;

	default:
		break;
	}

	air_para->COD[3]=0x00;
	air_para->COD[4]=0x00;
	air_para->COD[5]=0x10;
	air_para->COD[6]=0x00;
	air_para->COD[7]=0x92;
	air_para->COD[8]=0x20;
	air_para->COD[9]=0x39;
	air_para->COD[10]=0x03;

}



void AirRemote015(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xe9;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x78;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xb2;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xbb;

	air_para->ONE_h=0x02;
	air_para->ONE_l=0x22;


	air_para->BIC0=84;

	air_para->COD[2] = 0x10;
	switch(air_status->vKey){

	case POWER_KEY:
		air_para->COD[0]=0x03;
		break;

	case MODE_KEY:
		air_para->COD[0]=0x04;
		break;

	case SPEED_KEY:
		air_para->COD[0]=0x06;
		break;

	case TEMPER_INC_KEY:
		air_para->COD[0]=0x01;
		break;

	case TEMPER_DEC_KEY:
		air_para->COD[0]=0x02;
		break;

	case WIND_MANUAL_KEY:
		air_para->COD[0]=0x08;
		break;

	case WIND_AUTO_KEY:
		air_para->COD[0]=0x07;
		break;

	default:
		break;
	}


	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[0]&=0x7f;
		break;

	case POWER_ON:
		air_para->COD[0]|=0x80;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[0]|=0x40;
		break;

	case MODE_COLD:
		air_para->COD[0]|=0x00;
		break;

	case MODE_WET:
		air_para->COD[0]|=0x10;
		break;

	case MODE_WIND:
		air_para->COD[0]|=0x20;
		break;

	case MODE_HOT:
		air_para->COD[0]|=0x30;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[1]=0x00;
		break;

	case SPEED_LOW:
		air_para->COD[1]=0x10;
		break;

	case SPEED_MEDIUM:
		air_para->COD[1]=0x20;
		break;

	case SPEED_HIGH:
		air_para->COD[1]=0x30;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[1]|=0x00;
		break;

	case TEMPER_17:
		air_para->COD[1]|=0x01;
		break;

	case TEMPER_18:
		air_para->COD[1]|=0x02;
		break;

	case TEMPER_19:
		air_para->COD[1]|=0x03;
		break;

	case TEMPER_20:
		air_para->COD[1]|=0x04;
		break;

	case TEMPER_21:
		air_para->COD[1]|=0x05;
		break;

	case TEMPER_22:
		air_para->COD[1]|=0x06;
		break;

	case TEMPER_23:
		air_para->COD[1]|=0x07;
		break;

	case TEMPER_24:
		air_para->COD[1]|=0x08;
		break;

	case TEMPER_25:
		air_para->COD[1]|=0x09;
		break;

	case TEMPER_26:
		air_para->COD[1]|=0x0a;
		break;

	case TEMPER_27:
		air_para->COD[1]|=0x0b;
		break;

	case TEMPER_28:
		air_para->COD[1]|=0x0c;
		break;

	case TEMPER_29:
		air_para->COD[1]|=0x0d;
		break;

	case TEMPER_30:
		air_para->COD[1]|=0x0e;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[2] |= 0x04;
		break;

	case WIND_MANUAL:

		break;

	default:
		break;
	}

	air_para->COD[3]=0x00;
	air_para->COD[4]=0x00;
	air_para->COD[5]=0x00;
	air_para->COD[6]=0x00;
	air_para->COD[7]=0x00;
	air_para->COD[8]=0x00;
	air_para->COD[9]=0x30;
	air_para->COD[10]=0x03;

}




void AirRemote016(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xe9;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x78;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xb2;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xbb;

	air_para->ONE_h=0x02;
	air_para->ONE_l=0x22;


	air_para->BIC0=84;

	air_para->COD[2] = 0x10;
	switch(air_status->vKey){

	case POWER_KEY:
		air_para->COD[0]=0x03;
		break;

	case MODE_KEY:
		air_para->COD[0]=0x04;
		break;

	case SPEED_KEY:
		air_para->COD[0]=0x06;
		break;

	case TEMPER_INC_KEY:
		air_para->COD[0]=0x01;
		break;

	case TEMPER_DEC_KEY:
		air_para->COD[0]=0x02;
		break;

	case WIND_MANUAL_KEY:
		air_para->COD[0]=0x08;
		break;

	case WIND_AUTO_KEY:
		air_para->COD[0]=0x07;
		break;

	default:
		break;
	}


	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[0]&=0x7f;
		break;

	case POWER_ON:
		air_para->COD[0]|=0x80;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[0]|=0x40;
		break;

	case MODE_COLD:
		air_para->COD[0]|=0x00;
		break;

	case MODE_WET:
		air_para->COD[0]|=0x10;
		break;

	case MODE_WIND:
		air_para->COD[0]|=0x20;
		break;

	case MODE_HOT:
		air_para->COD[0]|=0x30;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[1]=0x00;
		break;

	case SPEED_LOW:
		air_para->COD[1]=0x10;
		break;

	case SPEED_MEDIUM:
		air_para->COD[1]=0x20;
		break;

	case SPEED_HIGH:
		air_para->COD[1]=0x30;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[1]|=0x00;
		break;

	case TEMPER_17:
		air_para->COD[1]|=0x01;
		break;

	case TEMPER_18:
		air_para->COD[1]|=0x02;
		break;

	case TEMPER_19:
		air_para->COD[1]|=0x03;
		break;

	case TEMPER_20:
		air_para->COD[1]|=0x04;
		break;

	case TEMPER_21:
		air_para->COD[1]|=0x05;
		break;

	case TEMPER_22:
		air_para->COD[1]|=0x06;
		break;

	case TEMPER_23:
		air_para->COD[1]|=0x07;
		break;

	case TEMPER_24:
		air_para->COD[1]|=0x08;
		break;

	case TEMPER_25:
		air_para->COD[1]|=0x09;
		break;

	case TEMPER_26:
		air_para->COD[1]|=0x0a;
		break;

	case TEMPER_27:
		air_para->COD[1]|=0x0b;
		break;

	case TEMPER_28:
		air_para->COD[1]|=0x0c;
		break;

	case TEMPER_29:
		air_para->COD[1]|=0x0d;
		break;

	case TEMPER_30:
		air_para->COD[1]|=0x0e;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[2] |= 0x04;
		break;

	case WIND_MANUAL:

		break;

	default:
		break;
	}

	air_para->COD[3]=0x00;
	air_para->COD[4]=0x00;
	air_para->COD[5]=0x00;
	air_para->COD[6]=0x00;
	air_para->COD[7]=0x00;
	air_para->COD[8]=0x00;
	air_para->COD[9]=0xc0;
	air_para->COD[10]=0x0c;

}



void AirRemote017(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xe9;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x78;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xb2;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xbb;

	air_para->ONE_h=0x02;
	air_para->ONE_l=0x22;


	air_para->BIC0=84;

	switch(air_status->vKey){

	case POWER_KEY:
		air_para->COD[0]=0x0c;
		break;

	case MODE_KEY:
		air_para->COD[0]=0x04;
		break;

	case SPEED_KEY:
		air_para->COD[0]=0x09;
		break;

	case TEMPER_INC_KEY:
		air_para->COD[0]=0x09;
		break;

	case TEMPER_DEC_KEY:
		air_para->COD[0]=0x06;
		break;

	case WIND_MANUAL_KEY:
		air_para->COD[0]=0x08;
		break;

	case WIND_AUTO_KEY:
		air_para->COD[0]=0x06;
		break;

	default:
		break;
	}


	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[0]&=0x7f;
		break;

	case POWER_ON:
		air_para->COD[0]|=0x80;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[0]|=0x40;
		break;

	case MODE_COLD:
		air_para->COD[0]|=0x00;
		break;

	case MODE_WET:
		air_para->COD[0]|=0x10;
		break;

	case MODE_WIND:
		air_para->COD[0]|=0x20;
		break;

	case MODE_HOT:
		air_para->COD[0]|=0x30;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[1]=0x00;
		break;

	case SPEED_LOW:
		air_para->COD[1]=0x10;
		break;

	case SPEED_MEDIUM:
		air_para->COD[1]=0x20;
		break;

	case SPEED_HIGH:
		air_para->COD[1]=0x30;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[1]|=0x00;
		break;

	case TEMPER_17:
		air_para->COD[1]|=0x01;
		break;

	case TEMPER_18:
		air_para->COD[1]|=0x02;
		break;

	case TEMPER_19:
		air_para->COD[1]|=0x03;
		break;

	case TEMPER_20:
		air_para->COD[1]|=0x04;
		break;

	case TEMPER_21:
		air_para->COD[1]|=0x05;
		break;

	case TEMPER_22:
		air_para->COD[1]|=0x06;
		break;

	case TEMPER_23:
		air_para->COD[1]|=0x07;
		break;

	case TEMPER_24:
		air_para->COD[1]|=0x08;
		break;

	case TEMPER_25:
		air_para->COD[1]|=0x09;
		break;

	case TEMPER_26:
		air_para->COD[1]|=0x0a;
		break;

	case TEMPER_27:
		air_para->COD[1]|=0x0b;
		break;

	case TEMPER_28:
		air_para->COD[1]|=0x0c;
		break;

	case TEMPER_29:
		air_para->COD[1]|=0x0d;
		break;

	case TEMPER_30:
		air_para->COD[1]|=0x0e;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[2] = 0x14;
		break;

	case WIND_MANUAL:
		switch(air_status->vManualWind){
		case MANUAL_WIND_1:
			air_para->COD[2]=0x30;
			break;
		case MANUAL_WIND_2:
			air_para->COD[2]=0x00;
			break;
		case MANUAL_WIND_3:
			air_para->COD[2]=0x10;
			break;
		case MANUAL_WIND_4:
			air_para->COD[2]=0x20;
			break;
		default:
			break;
		}

		break;

	default:
		break;
	}

	air_para->COD[3]=0x00;
	air_para->COD[4]=0x00;
	air_para->COD[5]=0x00;
	air_para->COD[6]=0x00;
	air_para->COD[7]=0x00;
	air_para->COD[8]=0x00;
	air_para->COD[9]=0x30;
	air_para->COD[10]=0x03;

}



void AirRemote018(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x04;
	air_para->LDH_l=0x27;

	air_para->LDL_h=0x02;
	air_para->LDL_l=0x1c;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0x87;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0x8b;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0x86;


	air_para->BIC0=112;

	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[5]=0x20;
		break;

	case POWER_ON:
		air_para->COD[5]=0x24;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[6]|=0x08;
		break;

	case MODE_COLD:
		air_para->COD[6]|=0x03;
		break;

	case MODE_WET:
		air_para->COD[6]|=0x02;
		break;

	case MODE_WIND:
		air_para->COD[6]|=0x07;
		break;

	case MODE_HOT:
		air_para->COD[6]|=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[8]=0x00;
		break;

	case SPEED_LOW:
		air_para->COD[8]=0x02;
		break;

	case SPEED_MEDIUM:
		air_para->COD[8]=0x03;
		break;

	case SPEED_HIGH:
		air_para->COD[8]=0x05;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[7]=0x0f;
		break;

	case TEMPER_17:
		air_para->COD[7]=0x0e;
		break;

	case TEMPER_18:
		air_para->COD[7]=0x0d;
		break;

	case TEMPER_19:
		air_para->COD[7]=0x0c;
		break;

	case TEMPER_20:
		air_para->COD[7]=0x0b;
		break;

	case TEMPER_21:
		air_para->COD[7]=0x0a;
		break;

	case TEMPER_22:
		air_para->COD[7]=0x09;
		break;

	case TEMPER_23:
		air_para->COD[7]=0x08;
		break;

	case TEMPER_24:
		air_para->COD[7]=0x07;
		break;

	case TEMPER_25:
		air_para->COD[7]=0x06;
		break;

	case TEMPER_26:
		air_para->COD[7]=0x05;
		break;

	case TEMPER_27:
		air_para->COD[7]=0x04;
		break;

	case TEMPER_28:
		air_para->COD[7]=0x03;
		break;

	case TEMPER_29:
		air_para->COD[7]=0x02;
		break;

	case TEMPER_30:
		air_para->COD[7]=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[8]|=0x38;
		break;

	case WIND_MANUAL:

		switch(air_status->vManualWind){
		case MANUAL_WIND_1:
			air_para->COD[8]|=0x00;
			break;
		case MANUAL_WIND_2:
			air_para->COD[8]|=0x10;
			break;
		case MANUAL_WIND_3:
			air_para->COD[8]|=0x20;
			break;
		case MANUAL_WIND_4:
			air_para->COD[8]|=0x28;
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}

	air_para->COD[0]=0x23;
	air_para->COD[1]=0xcb;
	air_para->COD[2]=0x26;
	air_para->COD[3]=0x01;
	air_para->COD[4]=0x00;
	air_para->COD[9]=0x00;
	air_para->COD[10]=0x00;
	air_para->COD[11]=0x00;
	air_para->COD[12]=0x00;

	air_para->COD[13]=(air_para->COD[0]+air_para->COD[1]+air_para->COD[2]+air_para->COD[3]+air_para->COD[4]+air_para->COD[5]+air_para->COD[6]+air_para->COD[7]+air_para->COD[8]+air_para->COD[9]+air_para->COD[10]+air_para->COD[11]+air_para->COD[12]);

}



void AirRemote019(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xe9;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x78;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xb2;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xbb;

	air_para->ONE_h=0x02;
	air_para->ONE_l=0x22;


	air_para->BIC0=84;

	air_para->COD[2] = 0x10;
	switch(air_status->vKey){

	case POWER_KEY:
		air_para->COD[0]=0x03;
		break;

	case MODE_KEY:
		air_para->COD[0]=0x04;
		break;

	case SPEED_KEY:
		air_para->COD[0]=0x06;
		break;

	case TEMPER_INC_KEY:
		air_para->COD[0]=0x01;
		break;

	case TEMPER_DEC_KEY:
		air_para->COD[0]=0x02;
		break;

	case WIND_MANUAL_KEY:
		air_para->COD[0]=0x08;
		break;

	case WIND_AUTO_KEY:
		air_para->COD[0]=0x07;
		break;

	default:
		break;
	}


	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[0]&=0x7f;
		break;

	case POWER_ON:
		air_para->COD[0]|=0x80;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[0]|=0x40;
		break;

	case MODE_COLD:
		air_para->COD[0]|=0x00;
		break;

	case MODE_WET:
		air_para->COD[0]|=0x10;
		break;

	case MODE_WIND:
		air_para->COD[0]|=0x20;
		break;

	case MODE_HOT:
		air_para->COD[0]|=0x30;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[1]=0x00;
		break;

	case SPEED_LOW:
		air_para->COD[1]=0x10;
		break;

	case SPEED_MEDIUM:
		air_para->COD[1]=0x20;
		break;

	case SPEED_HIGH:
		air_para->COD[1]=0x30;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[1]|=0x00;
		break;

	case TEMPER_17:
		air_para->COD[1]|=0x01;
		break;

	case TEMPER_18:
		air_para->COD[1]|=0x02;
		break;

	case TEMPER_19:
		air_para->COD[1]|=0x03;
		break;

	case TEMPER_20:
		air_para->COD[1]|=0x04;
		break;

	case TEMPER_21:
		air_para->COD[1]|=0x05;
		break;

	case TEMPER_22:
		air_para->COD[1]|=0x06;
		break;

	case TEMPER_23:
		air_para->COD[1]|=0x07;
		break;

	case TEMPER_24:
		air_para->COD[1]|=0x08;
		break;

	case TEMPER_25:
		air_para->COD[1]|=0x09;
		break;

	case TEMPER_26:
		air_para->COD[1]|=0x0a;
		break;

	case TEMPER_27:
		air_para->COD[1]|=0x0b;
		break;

	case TEMPER_28:
		air_para->COD[1]|=0x0c;
		break;

	case TEMPER_29:
		air_para->COD[1]|=0x0d;
		break;

	case TEMPER_30:
		air_para->COD[1]|=0x0e;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[2] |= 0x04;
		break;

	case WIND_MANUAL:

		break;

	default:
		break;
	}

	air_para->COD[3]=0x00;
	air_para->COD[4]=0x00;
	air_para->COD[5]=0x10;
	air_para->COD[6]=0x00;
	air_para->COD[7]=0x92;
	air_para->COD[8]=0x20;
	air_para->COD[9]=0x39;
	air_para->COD[10]=0x03;

}


void AirRemote020(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x03;
	air_para->LDH_l=0xef;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x4e;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0x90;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xc7;

	air_para->ONE_h=0x02;
	air_para->ONE_l=0x13;


	air_para->BIC0=96;

	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[5]=0x40;
		break;

	case POWER_ON:
		air_para->COD[5]=0x80;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[4]=0x50;
		break;

	case MODE_COLD:
		air_para->COD[4]=0x20;
		break;

	case MODE_WET:
		air_para->COD[4]=0x30;
		break;

	case MODE_WIND:
		air_para->COD[4]=0x40;
		break;

	case MODE_HOT:
		air_para->COD[4]=0x10;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[4]|=0x00;
		break;

	case SPEED_LOW:
		air_para->COD[4]|=0x01;
		break;

	case SPEED_MEDIUM:
		air_para->COD[4]|=0x02;
		break;

	case SPEED_HIGH:
		air_para->COD[4]|=0x03;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[1]=0x00;
		break;

	case TEMPER_17:
		air_para->COD[1]=0x01;
		break;

	case TEMPER_18:
		air_para->COD[1]=0x02;
		break;

	case TEMPER_19:
		air_para->COD[1]=0x03;
		break;

	case TEMPER_20:
		air_para->COD[1]=0x04;
		break;

	case TEMPER_21:
		air_para->COD[1]=0x05;
		break;

	case TEMPER_22:
		air_para->COD[1]=0x06;
		break;

	case TEMPER_23:
		air_para->COD[1]=0x07;
		break;

	case TEMPER_24:
		air_para->COD[1]=0x08;
		break;

	case TEMPER_25:
		air_para->COD[1]=0x09;
		break;

	case TEMPER_26:
		air_para->COD[1]=0x0a;
		break;

	case TEMPER_27:
		air_para->COD[1]=0x0b;
		break;

	case TEMPER_28:
		air_para->COD[1]=0x0c;
		break;

	case TEMPER_29:
		air_para->COD[1]=0x0d;
		break;

	case TEMPER_30:
		air_para->COD[1]=0x0e;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[5]|=0x01;
		break;

	case WIND_MANUAL:

		switch(air_status->vManualWind){
		case MANUAL_WIND_1:
			air_para->COD[5]|=0x02;
			break;
		case MANUAL_WIND_2:
			air_para->COD[5]|=0x03;
			break;
		case MANUAL_WIND_3:
			air_para->COD[5]|=0x04;
			break;
		case MANUAL_WIND_4:
			air_para->COD[5]|=0x05;
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}

	air_para->COD[0]=0xaa;
	air_para->COD[2]=0x20;
	air_para->COD[3]=0x00;
	air_para->COD[6]=0x00;
	air_para->COD[7]=0x00;
	air_para->COD[8]=0x00;
	air_para->COD[9]=0x00;
	air_para->COD[10]=0x00;

	air_para->COD[11]=(air_para->COD[0]+air_para->COD[1]+air_para->COD[2]+air_para->COD[3]+air_para->COD[4]+air_para->COD[5]+air_para->COD[6]+air_para->COD[7]+air_para->COD[8]+air_para->COD[9]+air_para->COD[10]);

}



void AirRemote021(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x03;
	air_para->LDH_l=0x9c;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x4e;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0x90;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xba;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0xf6;


	air_para->BIC0=96;

	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[5]=0x40;
		break;

	case POWER_ON:
		air_para->COD[5]=0x80;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[4]=0x50;
		break;

	case MODE_COLD:
		air_para->COD[4]=0x20;
		break;

	case MODE_WET:
		air_para->COD[4]=0x30;
		break;

	case MODE_WIND:
		air_para->COD[4]=0x40;
		break;

	case MODE_HOT:
		air_para->COD[4]=0x10;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[4]|=0x00;
		break;

	case SPEED_LOW:
		air_para->COD[4]|=0x01;
		break;

	case SPEED_MEDIUM:
		air_para->COD[4]|=0x02;
		break;

	case SPEED_HIGH:
		air_para->COD[4]|=0x03;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[1]=0x00;
		break;

	case TEMPER_17:
		air_para->COD[1]=0x01;
		break;

	case TEMPER_18:
		air_para->COD[1]=0x02;
		break;

	case TEMPER_19:
		air_para->COD[1]=0x03;
		break;

	case TEMPER_20:
		air_para->COD[1]=0x04;
		break;

	case TEMPER_21:
		air_para->COD[1]=0x05;
		break;

	case TEMPER_22:
		air_para->COD[1]=0x06;
		break;

	case TEMPER_23:
		air_para->COD[1]=0x07;
		break;

	case TEMPER_24:
		air_para->COD[1]=0x08;
		break;

	case TEMPER_25:
		air_para->COD[1]=0x09;
		break;

	case TEMPER_26:
		air_para->COD[1]=0x0a;
		break;

	case TEMPER_27:
		air_para->COD[1]=0x0b;
		break;

	case TEMPER_28:
		air_para->COD[1]=0x0c;
		break;

	case TEMPER_29:
		air_para->COD[1]=0x0d;
		break;

	case TEMPER_30:
		air_para->COD[1]=0x0e;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[5]|=0x01;
		break;

	case WIND_MANUAL:

		switch(air_status->vManualWind){
		case MANUAL_WIND_1:
			air_para->COD[5]|=0x02;
			break;
		case MANUAL_WIND_2:
			air_para->COD[5]|=0x03;
			break;
		case MANUAL_WIND_3:
			air_para->COD[5]|=0x04;
			break;
		case MANUAL_WIND_4:
			air_para->COD[5]|=0x05;
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}

	air_para->COD[0]=0xaa;
	air_para->COD[2]=0x60;
	air_para->COD[3]=0x00;
	air_para->COD[6]=0x00;
	air_para->COD[7]=0x00;
	air_para->COD[8]=0x00;
	air_para->COD[9]=0x00;
	air_para->COD[10]=0x00;

	air_para->COD[11]=(air_para->COD[0]+air_para->COD[1]+air_para->COD[2]+air_para->COD[3]+air_para->COD[4]+air_para->COD[5]+air_para->COD[6]+air_para->COD[7]+air_para->COD[8]+air_para->COD[9]+air_para->COD[10]);

}


void AirRemote022(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xe9;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x78;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xb2;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xbb;

	air_para->ONE_h=0x02;
	air_para->ONE_l=0x22;


	air_para->BIC0=84;

	air_para->COD[2] = 0x10;
	switch(air_status->vKey){

	case POWER_KEY:
		air_para->COD[0]=0x0c;
		break;

	case MODE_KEY:
		air_para->COD[0]=0x04;
		break;

	case SPEED_KEY:
		air_para->COD[0]=0x09;
		break;

	case TEMPER_INC_KEY:
		air_para->COD[0]=0x05;
		break;

	case TEMPER_DEC_KEY:
		air_para->COD[0]=0x07;
		break;

	case WIND_MANUAL_KEY:
		air_para->COD[0]=0x06;
		break;

	case WIND_AUTO_KEY:
		air_para->COD[0]=0x06;
		break;

	default:
		break;
	}


	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[0]&=0x7f;
		break;

	case POWER_ON:
		air_para->COD[0]|=0x80;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[0]|=0x40;
		break;

	case MODE_COLD:
		air_para->COD[0]|=0x00;
		break;

	case MODE_WET:
		air_para->COD[0]|=0x10;
		break;

	case MODE_WIND:
		air_para->COD[0]|=0x20;
		break;

	case MODE_HOT:
		air_para->COD[0]|=0x30;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[1]=0x00;
		break;

	case SPEED_LOW:
		air_para->COD[1]=0x10;
		break;

	case SPEED_MEDIUM:
		air_para->COD[1]=0x20;
		break;

	case SPEED_HIGH:
		air_para->COD[1]=0x30;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[1]|=0x00;
		break;

	case TEMPER_17:
		air_para->COD[1]|=0x01;
		break;

	case TEMPER_18:
		air_para->COD[1]|=0x02;
		break;

	case TEMPER_19:
		air_para->COD[1]|=0x03;
		break;

	case TEMPER_20:
		air_para->COD[1]|=0x04;
		break;

	case TEMPER_21:
		air_para->COD[1]|=0x05;
		break;

	case TEMPER_22:
		air_para->COD[1]|=0x06;
		break;

	case TEMPER_23:
		air_para->COD[1]|=0x07;
		break;

	case TEMPER_24:
		air_para->COD[1]|=0x08;
		break;

	case TEMPER_25:
		air_para->COD[1]|=0x09;
		break;

	case TEMPER_26:
		air_para->COD[1]|=0x0a;
		break;

	case TEMPER_27:
		air_para->COD[1]|=0x0b;
		break;

	case TEMPER_28:
		air_para->COD[1]|=0x0c;
		break;

	case TEMPER_29:
		air_para->COD[1]|=0x0d;
		break;

	case TEMPER_30:
		air_para->COD[1]|=0x0e;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[2] |= 0x08;
		break;

	case WIND_MANUAL:

		break;

	default:
		break;
	}

	air_para->COD[3]=0x00;
	air_para->COD[4]=0x00;
	air_para->COD[5]=0x00;
	air_para->COD[6]=0x00;
	air_para->COD[7]=0x00;
	air_para->COD[8]=0x00;
	air_para->COD[9]=0x50;
	air_para->COD[10]=0x05;

}


void AirRemote023(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x07;
	air_para->LDH_l=0xb2;

	air_para->LDL_h=0x08;
	air_para->LDL_l=0x40;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xa9;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0x97;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0xe4;


	air_para->BIC0=46;


	air_para->COD[1]=0xc0;
	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[1]&=0xc7;
		break;

	case POWER_ON:
		air_para->COD[1]|=0x38;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[1]|=0x00;
		break;

	case MODE_COLD:
		air_para->COD[1]|=0x04;
		break;

	case MODE_WET:
		air_para->COD[1]|=0x02;
		break;

	case MODE_WIND:
		air_para->COD[1]|=0x01;
		break;

	case MODE_HOT:
		air_para->COD[1]|=0x07;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[2]=0x00;
		break;

	case SPEED_LOW:
		air_para->COD[2]=0x10;
		break;

	case SPEED_MEDIUM:
		air_para->COD[2]=0x30;
		break;

	case SPEED_HIGH:
		air_para->COD[2]=0x50;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[3]=0x02;
		break;

	case TEMPER_17:
		air_para->COD[3]=0x02;
		break;

	case TEMPER_18:
		air_para->COD[3]=0x02;
		break;

	case TEMPER_19:
		air_para->COD[3]=0x03;
		break;

	case TEMPER_20:
		air_para->COD[3]=0x04;
		break;

	case TEMPER_21:
		air_para->COD[3]=0x05;
		break;

	case TEMPER_22:
		air_para->COD[3]=0x06;
		break;

	case TEMPER_23:
		air_para->COD[3]=0x07;
		break;

	case TEMPER_24:
		air_para->COD[3]=0x08;
		break;

	case TEMPER_25:
		air_para->COD[3]=0x09;
		break;

	case TEMPER_26:
		air_para->COD[3]=0x0a;
		break;

	case TEMPER_27:
		air_para->COD[3]=0x0b;
		break;

	case TEMPER_28:
		air_para->COD[3]=0x0c;
		break;

	case TEMPER_29:
		air_para->COD[3]=0x0d;
		break;

	case TEMPER_30:
		air_para->COD[3]=0x0e;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[2]|=0x08;
		break;

	case WIND_MANUAL:

		switch(air_status->vManualWind){
		case MANUAL_WIND_1:
			air_para->COD[2]|=0x01;
			break;
		case MANUAL_WIND_2:
			air_para->COD[2]|=0x02;
			break;
		case MANUAL_WIND_3:
			air_para->COD[2]|=0x03;
			break;
		case MANUAL_WIND_4:
			air_para->COD[2]|=0x04;
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}

	air_para->COD[0]=0x15;
	air_para->COD[4]=0x1e;

	air_para->COD[5]=(CountBit(air_para->COD[0])+CountBit(air_para->COD[1])+CountBit(air_para->COD[2])+CountBit(air_para->COD[3])+CountBit(air_para->COD[4]))<<2;

	air_para->COD[0]=HiBitFst(air_para->COD[0]);
	air_para->COD[1]=HiBitFst(air_para->COD[1]);
	air_para->COD[2]=HiBitFst(air_para->COD[2]);
	air_para->COD[3]=HiBitFst(air_para->COD[3]);
	air_para->COD[4]=HiBitFst(air_para->COD[4]);
	air_para->COD[5]=HiBitFst(air_para->COD[5]);

}


void AirRemote025(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x07;
	air_para->LDH_l=0x84;

	air_para->LDL_h=0x07;
	air_para->LDL_l=0x94;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0x99;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0x9a;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0xc5;


	air_para->BIC0=48;


	air_para->COD[1] = 0xf8;
	switch(air_status->vMode){
	case MODE_AUTO:
		break;

	case MODE_COLD:
		air_para->COD[1]|=0x04;
		break;

	case MODE_WET:
		air_para->COD[1]|=0x07;
		break;

	case MODE_WIND:
		air_para->COD[1]|=0x02;
		break;

	case MODE_HOT:
		air_para->COD[1]|=0x01;
		break;

	default:
		break;
	}
	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[1]&=0xc0;
		break;

	case POWER_ON:

		break;

	default:
		break;
	}


	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[2]=0x00;
		break;

	case SPEED_LOW:
		air_para->COD[2]=0x10;
		break;

	case SPEED_MEDIUM:
		air_para->COD[2]=0x30;
		break;

	case SPEED_HIGH:
		air_para->COD[2]=0x50;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[3]=0x02;
		break;

	case TEMPER_17:
		air_para->COD[3]=0x02;
		break;

	case TEMPER_18:
		air_para->COD[3]=0x02;
		break;

	case TEMPER_19:
		air_para->COD[3]=0x03;
		break;

	case TEMPER_20:
		air_para->COD[3]=0x04;
		break;

	case TEMPER_21:
		air_para->COD[3]=0x05;
		break;

	case TEMPER_22:
		air_para->COD[3]=0x06;
		break;

	case TEMPER_23:
		air_para->COD[3]=0x07;
		break;

	case TEMPER_24:
		air_para->COD[3]=0x08;
		break;

	case TEMPER_25:
		air_para->COD[3]=0x09;
		break;

	case TEMPER_26:
		air_para->COD[3]=0x0a;
		break;

	case TEMPER_27:
		air_para->COD[3]=0x0b;
		break;

	case TEMPER_28:
		air_para->COD[3]=0x0c;
		break;

	case TEMPER_29:
		air_para->COD[3]=0x0d;
		break;

	case TEMPER_30:
		air_para->COD[3]=0x0e;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[2]&=0xf0;
		air_para->COD[3]|=0x40;
		break;

	case WIND_MANUAL:

		switch(air_status->vManualWind){
		case MANUAL_WIND_1:
			break;
		case MANUAL_WIND_2:
			air_para->COD[2]|=0x01;
			break;
		case MANUAL_WIND_3:
			air_para->COD[2]|=0x02;
			break;
		case MANUAL_WIND_4:
			air_para->COD[2]|=0x03;
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}

	air_para->COD[0]=0x15;
	air_para->COD[4]=0x00;

	air_para->COD[5]=(CountBit(air_para->COD[0])+CountBit(air_para->COD[1])+CountBit(air_para->COD[2])+CountBit(air_para->COD[3])+CountBit(air_para->COD[4]));
	//air_para->COD[5] = HiBitFst(air_para->COD[5]);
	HBarray(6,air_para);
}


void AirRemote027(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x03;
	air_para->LDH_l=0xcc;

	air_para->LDL_h=0x0b;
	air_para->LDL_l=0x54;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0x95;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xaa;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0xee;


	air_para->BIC0=56;

	air_para->COD[2] = 0xad;
	air_para->COD[4] = 0x01;
	air_para->COD[6] = 0xc0;

	switch(air_status->vWind){

	case WIND_AUTO:
		break;

	case WIND_MANUAL:

		air_para->COD[2] |= 0x50;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[4]|=0x20;
		break;

	case TEMPER_17:
		air_para->COD[4]|=0x20;
		break;

	case TEMPER_18:
		air_para->COD[4]|=0x20;
		break;

	case TEMPER_19:
		air_para->COD[4]|=0x30;
		break;

	case TEMPER_20:
		air_para->COD[4]|=0x40;
		break;

	case TEMPER_21:
		air_para->COD[4]|=0x50;
		break;

	case TEMPER_22:
		air_para->COD[4]|=0x60;
		break;

	case TEMPER_23:
		air_para->COD[4]|=0x70;
		break;

	case TEMPER_24:
		air_para->COD[4]|=0x80;
		break;

	case TEMPER_25:
		air_para->COD[4]|=0x90;
		break;

	case TEMPER_26:
		air_para->COD[4]|=0xa0;
		break;

	case TEMPER_27:
		air_para->COD[4]|=0xb0;
		break;

	case TEMPER_28:
		air_para->COD[4]|=0xc0;
		break;

	case TEMPER_29:
		air_para->COD[4]|=0xd0;
		break;

	case TEMPER_30:
		air_para->COD[4]|=0xe0;
		break;

	default:
		break;
	}


	switch(air_status->vPower){

	case POWER_OFF:
		break;

	case POWER_ON:
		air_para->COD[6]|=0x30;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[5]=0x01;
		break;

	case SPEED_LOW:
		air_para->COD[5]=0x05;
		break;

	case SPEED_MEDIUM:
		air_para->COD[5]=0x09;
		break;

	case SPEED_HIGH:
		air_para->COD[5]=0x0b;
		break;

	default:
		break;
	}


	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[5]=0x0d;
		air_para->COD[4]=0x91;
		break;

	case MODE_COLD:
		air_para->COD[5]|=0x10;
		break;

	case MODE_WET:
		air_para->COD[5]|=0x20;
		break;

	case MODE_WIND:
		air_para->COD[5]|=0x30;
		break;

	case MODE_HOT:
		air_para->COD[5]|=0x40;
		break;

	default:
		break;
	}



	air_para->COD[0]=0x01;
	air_para->COD[1]=0x12;
	air_para->COD[3]=0x81;
	AdjustZero(air_para);

}


void AirRemote030(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x01;


	air_para->LDH_h=0x07;
	air_para->LDH_l=0x34;

	air_para->LDL_h=0x08;
	air_para->LDL_l=0xf7;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xa8;

	air_para->ZER_h=0x01;
	air_para->ZER_l=0xaa;

	air_para->ONE_h=0x04;
	air_para->ONE_l=0x2b;

	air_para->STO_h=0x08;
	air_para->STO_l=0xf7;

	air_para->BIC0=48;

	switch(air_status->vPower){

		case POWER_OFF:
			air_para->COD[3]|=0x00;
			break;

		case POWER_ON:
			air_para->COD[3]|=0x08;
			break;

		default:
			break;
	}

	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[3]|=0x00;
			break;

		case MODE_COLD:
			air_para->COD[3]|=0x01;
			break;

		case MODE_WET:
			air_para->COD[3]|=0x02;
			break;

		case MODE_WIND:
			air_para->COD[3]|=0x03;
			break;

		case MODE_HOT:
			air_para->COD[3]|=0x04;
			break;

		default:
			break;
	}

	switch(air_status->vSpeed){

		case SPEED_AUTO:
			air_para->COD[1]|=0x00;
			break;

		case SPEED_LOW:
			air_para->COD[1]|=0xc0;
			break;

		case SPEED_MEDIUM:
			air_para->COD[1]|=0x80;
			break;

		case SPEED_HIGH:
			air_para->COD[1]|=0x40;
			break;

		default:
			break;
	}

	switch(air_status->vTemper){

		case TEMPER_16:
			air_para->COD[3]|=0x10;
			break;

		case TEMPER_17:
			air_para->COD[3]|=0x10;
			break;

		case TEMPER_18:
			air_para->COD[3]|=0x10;
			break;

		case TEMPER_19:
			air_para->COD[3]|=0x20;
			break;

		case TEMPER_20:
			air_para->COD[3]|=0x30;
			break;

		case TEMPER_21:
			air_para->COD[3]|=0x40;
			break;

		case TEMPER_22:
			air_para->COD[3]|=0x50;
			break;

		case TEMPER_23:
			air_para->COD[3]|=0x60;
			break;

		case TEMPER_24:
			air_para->COD[3]|=0x70;
			break;

		case TEMPER_25:
			air_para->COD[3]|=0x80;
			break;

		case TEMPER_26:
			air_para->COD[3]|=0x90;
			break;

		case TEMPER_27:
			air_para->COD[3]|=0xa0;
			break;

		case TEMPER_28:
			air_para->COD[3]|=0xb0;
			break;

		case TEMPER_29:
			air_para->COD[3]|=0xc0;
			break;

		case TEMPER_30:
			air_para->COD[3]|=0xd0;
			break;

		default:
			break;
	}

	switch(air_status->vWind){

		case WIND_AUTO:
			air_para->COD[1]|=0x10;
			break;

		case WIND_MANUAL:
			air_para->COD[1]|=0x20;
			break;

		default:
			break;
	}

	air_para->COD[0]=~(air_para->COD[1]);
	air_para->COD[2]=~(air_para->COD[3]);
	air_para->COD[4]=0x15;
	air_para->COD[5]=~(air_para->COD[4]);

}



void AirRemote031(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x04;
	air_para->LDH_l=0x27;

	air_para->LDL_h=0x02;
	air_para->LDL_l=0x1c;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0x87;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0x8b;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0x86;


	air_para->BIC0=112;

	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[5]=0x20;
		break;

	case POWER_ON:
		air_para->COD[5]=0x24;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[6]=0x08;
		break;

	case MODE_COLD:
		air_para->COD[6]=0x03;
		break;

	case MODE_WET:
		air_para->COD[6]=0x02;
		break;

	case MODE_WIND:
		air_para->COD[6]=0x07;
		break;

	case MODE_HOT:
		air_para->COD[6]=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[8]=0x00;
		break;

	case SPEED_LOW:
		air_para->COD[8]=0x02;
		break;

	case SPEED_MEDIUM:
		air_para->COD[8]=0x03;
		break;

	case SPEED_HIGH:
		air_para->COD[8]=0x05;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[7]=0x0f;
		break;

	case TEMPER_17:
		air_para->COD[7]=0x0e;
		break;

	case TEMPER_18:
		air_para->COD[7]=0x0d;
		break;

	case TEMPER_19:
		air_para->COD[7]=0x0c;
		break;

	case TEMPER_20:
		air_para->COD[7]=0x0b;
		break;

	case TEMPER_21:
		air_para->COD[7]=0x0a;
		break;

	case TEMPER_22:
		air_para->COD[7]=0x09;
		break;

	case TEMPER_23:
		air_para->COD[7]=0x08;
		break;

	case TEMPER_24:
		air_para->COD[7]=0x07;
		break;

	case TEMPER_25:
		air_para->COD[7]=0x06;
		break;

	case TEMPER_26:
		air_para->COD[7]=0x05;
		break;

	case TEMPER_27:
		air_para->COD[7]=0x04;
		break;

	case TEMPER_28:
		air_para->COD[7]=0x03;
		break;

	case TEMPER_29:
		air_para->COD[7]=0x02;
		break;

	case TEMPER_30:
		air_para->COD[7]=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[8]|=0x38;
		break;

	case WIND_MANUAL:

		switch(air_status->vManualWind){
		case MANUAL_WIND_1:
			break;
		case MANUAL_WIND_2:
			air_para->COD[8]|=0x10;
			break;
		case MANUAL_WIND_3:
			air_para->COD[8]|=0x20;
			break;
		case MANUAL_WIND_4:
			air_para->COD[8]|=0x28;
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}

	air_para->COD[0]=0x11;
	air_para->COD[1]=0x11;
	air_para->COD[2]=0x11;
	air_para->COD[3]=0x11;
	air_para->COD[4]=0x11;
	air_para->COD[9]=0x00;
	air_para->COD[10]=0x00;
	air_para->COD[11]=0x00;
	air_para->COD[12]=0x00;

	air_para->COD[13]=(air_para->COD[0]+air_para->COD[1]+air_para->COD[2]+air_para->COD[3]+air_para->COD[4]+air_para->COD[5]+air_para->COD[6]+air_para->COD[7]+air_para->COD[8]+air_para->COD[9]+air_para->COD[10]+air_para->COD[11]+air_para->COD[12]);

}


void AirRemote032(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x01;
	air_para->LDH_l=0x4d;

	air_para->LDL_h=0x12;
	air_para->LDL_l=0x3c;

	air_para->HIG_h=0x01;
	air_para->HIG_l=0x4d;

	air_para->ZER_h=0x03;
	air_para->ZER_l=0xb7;

	air_para->ONE_h=0x08;
	air_para->ONE_l=0xaf;


	air_para->BIC0=17;


	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[0]=0x00;
		break;

	case SPEED_LOW:
		air_para->COD[0]=0x02;
		break;

	case SPEED_MEDIUM:
		air_para->COD[0]=0x04;
		break;

	case SPEED_HIGH:
		air_para->COD[0]=0x06;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[2]|=0x00;
		break;

	case MODE_COLD:
		air_para->COD[2]|=0x01;
		break;

	case MODE_WET:
		air_para->COD[2]|=0x02;
		break;

	case MODE_WIND:
		air_para->COD[2]|=0x03;
		break;

	case MODE_HOT:
		air_para->COD[2]|=0x04;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[0]|=0x20;
		break;

	case WIND_MANUAL:

		break;
	default:
		break;
	}

	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[0] &= 0x0f;
		air_para->COD[0] |= 0x40;
		air_para->COD[2] = 0x05;
		break;

	case POWER_ON:
		break;

	default:
		break;
	}



	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[1]=0x0a;
		break;

	case TEMPER_17:
		air_para->COD[1]=0x0b;
		break;

	case TEMPER_18:
		air_para->COD[1]=0x0c;
		break;

	case TEMPER_19:
		air_para->COD[1]=0x0d;
		break;

	case TEMPER_20:
		air_para->COD[1]=0x0e;
		break;

	case TEMPER_21:
		air_para->COD[1]=0x0f;
		break;

	case TEMPER_22:
		air_para->COD[1]=0x10;
		break;

	case TEMPER_23:
		air_para->COD[1]=0x11;
		break;

	case TEMPER_24:
		air_para->COD[1]=0x12;
		break;

	case TEMPER_25:
		air_para->COD[1]=0x13;
		break;

	case TEMPER_26:
		air_para->COD[1]=0x14;
		break;

	case TEMPER_27:
		air_para->COD[1]=0x15;
		break;

	case TEMPER_28:
		air_para->COD[1]=0x16;
		break;

	case TEMPER_29:
		air_para->COD[1]=0x17;
		break;

	case TEMPER_30:
		air_para->COD[1]=0x18;
		break;

	default:
		break;
	}


	air_para->COD[0] = HiBitFst(air_para->COD[0]);
	air_para->COD[1] = HiBitFst(air_para->COD[1]);
	air_para->COD[2] = HiBitFst(air_para->COD[2]);
	air_para->COD[1] >>= 3;
	//air_para->COD[2] <<= 5;
	air_para->COD[1] += air_para->COD[2];

	air_para->COD[2]=(CountBit(air_para->COD[0])+CountBit(air_para->COD[1]));
	air_para->COD[2]++;

}


void AirRemote033(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x04;
	air_para->LDH_l=0x27;

	air_para->LDL_h=0x02;
	air_para->LDL_l=0x1c;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0x87;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0x8b;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0x86;


	air_para->BIC0=112;

	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[5]=0x20;
		break;

	case POWER_ON:
		air_para->COD[5]=0x24;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[6]=0x08;
		break;

	case MODE_COLD:
		air_para->COD[6]=0x03;
		break;

	case MODE_WET:
		air_para->COD[6]=0x02;
		break;

	case MODE_WIND:
		air_para->COD[6]=0x07;
		break;

	case MODE_HOT:
		air_para->COD[6]=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[8]=0x00;
		break;

	case SPEED_LOW:
		air_para->COD[8]=0x02;
		break;

	case SPEED_MEDIUM:
		air_para->COD[8]=0x03;
		break;

	case SPEED_HIGH:
		air_para->COD[8]=0x05;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[7]=0x0f;
		break;

	case TEMPER_17:
		air_para->COD[7]=0x0e;
		break;

	case TEMPER_18:
		air_para->COD[7]=0x0d;
		break;

	case TEMPER_19:
		air_para->COD[7]=0x0c;
		break;

	case TEMPER_20:
		air_para->COD[7]=0x0b;
		break;

	case TEMPER_21:
		air_para->COD[7]=0x0a;
		break;

	case TEMPER_22:
		air_para->COD[7]=0x09;
		break;

	case TEMPER_23:
		air_para->COD[7]=0x08;
		break;

	case TEMPER_24:
		air_para->COD[7]=0x07;
		break;

	case TEMPER_25:
		air_para->COD[7]=0x06;
		break;

	case TEMPER_26:
		air_para->COD[7]=0x05;
		break;

	case TEMPER_27:
		air_para->COD[7]=0x04;
		break;

	case TEMPER_28:
		air_para->COD[7]=0x03;
		break;

	case TEMPER_29:
		air_para->COD[7]=0x02;
		break;

	case TEMPER_30:
		air_para->COD[7]=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[8]|=0x38;
		break;

	case WIND_MANUAL:

		switch(air_status->vManualWind){
		case MANUAL_WIND_1:
			break;
		case MANUAL_WIND_2:
			air_para->COD[8]|=0x10;
			break;
		case MANUAL_WIND_3:
			air_para->COD[8]|=0x20;
			break;
		case MANUAL_WIND_4:
			air_para->COD[8]|=0x28;
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}

	air_para->COD[0]=0x23;
	air_para->COD[1]=0xcb;
	air_para->COD[2]=0x26;
	air_para->COD[3]=0x01;
	air_para->COD[4]=0x00;
	air_para->COD[9]=0x00;
	air_para->COD[10]=0x00;
	air_para->COD[11]=0x00;
	air_para->COD[12]=0x00;

	air_para->COD[13]=(air_para->COD[0]+air_para->COD[1]+air_para->COD[2]+air_para->COD[3]+air_para->COD[4]+air_para->COD[5]+air_para->COD[6]+air_para->COD[7]+air_para->COD[8]+air_para->COD[9]+air_para->COD[10]+air_para->COD[11]+air_para->COD[12]);

}



void AirRemote036(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xeb;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x83;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xae;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xfc;

	air_para->ONE_h=0x02;
	air_para->ONE_l=0x49;


	air_para->BIC0=40;

	air_para->COD[0] = 0x40;



	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[1]=0x00;
		break;

	case MODE_COLD:
		air_para->COD[1]=0x01;
		break;

	case MODE_WET:
		air_para->COD[1]=0x02;
		break;

	case MODE_WIND:
		air_para->COD[1]=0x03;
		break;

	case MODE_HOT:
		air_para->COD[1]=0x04;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		break;

	case SPEED_LOW:
		air_para->COD[1]|=0x10;
		break;

	case SPEED_MEDIUM:
		air_para->COD[1]|=0x20;
		break;

	case SPEED_HIGH:
		air_para->COD[1]|=0x30;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[2]=0x10;
		break;

	case TEMPER_17:
		air_para->COD[2]=0x11;
		break;

	case TEMPER_18:
		air_para->COD[2]=0x12;
		break;

	case TEMPER_19:
		air_para->COD[2]=0x13;
		break;

	case TEMPER_20:
		air_para->COD[2]=0x14;
		break;

	case TEMPER_21:
		air_para->COD[2]=0x15;
		break;

	case TEMPER_22:
		air_para->COD[2]=0x16;
		break;

	case TEMPER_23:
		air_para->COD[2]=0x17;
		break;

	case TEMPER_24:
		air_para->COD[2]=0x18;
		break;

	case TEMPER_25:
		air_para->COD[2]=0x19;
		break;

	case TEMPER_26:
		air_para->COD[2]=0x1a;
		break;

	case TEMPER_27:
		air_para->COD[2]=0x1b;
		break;

	case TEMPER_28:
		air_para->COD[2]=0x1c;
		break;

	case TEMPER_29:
		air_para->COD[2]=0x1d;
		break;

	case TEMPER_30:
		air_para->COD[2]=0x1e;
		break;

	default:
		break;
	}

	switch(air_status->vKey){

	case POWER_KEY:
		air_para->COD[1]|=0x80;
		break;

	case WIND_MANUAL_KEY:
		air_para->COD[0]=0x51;
		air_para->COD[1]=0xae;
		break;

	case WIND_AUTO_KEY:
		air_para->COD[0]=0x50;
		air_para->COD[1]=0xaf;
		break;

	default:
		break;
	}

	air_para->COD[4]=0xae;
	air_para->COD[3]=air_para->COD[0]+air_para->COD[1]+air_para->COD[2];
	air_para->COD[3]=~air_para->COD[3];


}


void AirRemote037(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xed;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x84;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xb8;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xc1;

	air_para->ONE_h=0x02;
	air_para->ONE_l=0x02;


	air_para->BIC0=112;

	air_para->COD[2] = 0xf0;

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[7] = 0xb4;
		break;

	case WIND_MANUAL:
	     air_para->COD[7] = 0xa5;
		break;

	default:
		break;
	}


	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[3]=0xe1;
		break;

	case MODE_COLD:
		air_para->COD[3]=0xb4;
		break;

	case MODE_WET:
		air_para->COD[3]=0xd2;
		break;

	case MODE_WIND:
		air_para->COD[3]=0xf0;
		break;

	case MODE_HOT:
		air_para->COD[3]=0x78;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[6]=0xe1;
		break;

	case SPEED_LOW:
		air_para->COD[6]=0x78;
		break;

	case SPEED_MEDIUM:
		air_para->COD[6]=0xb4;
		break;

	case SPEED_HIGH:
		air_para->COD[6]=0xd2;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[4]|=0xe1;
		air_para->COD[5]|=0x96;
		break;

	case TEMPER_17:
		air_para->COD[4]|=0xe1;
		air_para->COD[5]|=0x87;
		break;

	case TEMPER_18:
		air_para->COD[4]|=0xe1;
		air_para->COD[5]|=0x78;
		break;

	case TEMPER_19:
		air_para->COD[4]|=0xe1;
		air_para->COD[5]|=0x69;
		break;

	case TEMPER_20:
		air_para->COD[4]|=0xd2;
		air_para->COD[5]|=0xf0;
		break;

	case TEMPER_21:
		air_para->COD[4]|=0xd2;
		air_para->COD[5]|=0xe1;
		break;

	case TEMPER_22:
		air_para->COD[4]|=0xd2;
		air_para->COD[5]|=0xd2;
		break;

	case TEMPER_23:
		air_para->COD[4]|=0xd2;
		air_para->COD[5]|=0xc3;
		break;

	case TEMPER_24:
		air_para->COD[4]|=0xd2;
		air_para->COD[5]|=0xb4;
		break;

	case TEMPER_25:
		air_para->COD[4]|=0xd2;
		air_para->COD[5]|=0xa5;
		break;

	case TEMPER_26:
		air_para->COD[4]|=0xd2;
		air_para->COD[5]|=0x96;
		break;

	case TEMPER_27:
		air_para->COD[4]|=0xd2;
		air_para->COD[5]|=0x87;
		break;

	case TEMPER_28:
		air_para->COD[4]|=0xd2;
		air_para->COD[5]|=0x78;
		break;

	case TEMPER_29:
		air_para->COD[4]|=0xd2;
		air_para->COD[5]|=0x69;
		break;

	case TEMPER_30:
		air_para->COD[4]|=0xc3;
		air_para->COD[5]|=0xf0;
		break;

	default:
		break;
	}

	air_para->COD[0]=0xd2;

	switch(air_status->vKey){

	case POWER_KEY:
		air_para->COD[1]=0xd2;
		break;

	case MODE_KEY:
	case SPEED_KEY:
	case TEMPER_INC_KEY:
	case TEMPER_DEC_KEY:
		air_para->COD[1]=0xc3;
		break;

	case WIND_MANUAL_KEY:
		air_para->COD[1]=0xa5;
	    air_para->BIC0=64;
		return;

	case WIND_AUTO_KEY:
		air_para->COD[1]=0xb4;
    	air_para->BIC0=64;
		return;

	default:
		break;
	}

	air_para->COD[8]=0xd2;
	air_para->COD[9]=0xe1;
	air_para->COD[10]=0xf0;
	air_para->COD[11]=0xe1;
	air_para->COD[12]=0xf0;
	air_para->COD[13]=0xf0;

}


void AirRemote038(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x04;
	air_para->LDH_l=0x1f;

	air_para->LDL_h=0x02;
	air_para->LDL_l=0x25;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0x7f;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0x93;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0x91;


	air_para->BIC0=112;

	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[5]=0x20;
		break;

	case POWER_ON:
		air_para->COD[5]=0x24;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[6]=0x08;
		break;

	case MODE_COLD:
		air_para->COD[6]=0x03;
		break;

	case MODE_WET:
		air_para->COD[6]=0x02;
		break;

	case MODE_WIND:
		air_para->COD[6]=0x07;
		break;

	case MODE_HOT:
		air_para->COD[6]=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[8]=0x04;
		break;

	case SPEED_LOW:
		air_para->COD[8]=0x02;
		break;

	case SPEED_MEDIUM:
		air_para->COD[8]=0x06;
		break;

	case SPEED_HIGH:
		air_para->COD[8]=0x04;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[7]=0x0f;
		break;

	case TEMPER_17:
		air_para->COD[7]=0x0e;
		break;

	case TEMPER_18:
		air_para->COD[7]=0x0d;
		break;

	case TEMPER_19:
		air_para->COD[7]=0x0c;
		break;

	case TEMPER_20:
		air_para->COD[7]=0x0b;
		break;

	case TEMPER_21:
		air_para->COD[7]=0x0a;
		break;

	case TEMPER_22:
		air_para->COD[7]=0x09;
		break;

	case TEMPER_23:
		air_para->COD[7]=0x08;
		break;

	case TEMPER_24:
		air_para->COD[7]=0x07;
		break;

	case TEMPER_25:
		air_para->COD[7]=0x06;
		break;

	case TEMPER_26:
		air_para->COD[7]=0x05;
		break;

	case TEMPER_27:
		air_para->COD[7]=0x04;
		break;

	case TEMPER_28:
		air_para->COD[7]=0x03;
		break;

	case TEMPER_29:
		air_para->COD[7]=0x02;
		break;

	case TEMPER_30:
		air_para->COD[7]=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[8]|=0x18;
		break;

	case WIND_MANUAL:
		air_para->COD[8]|=0x10;

		break;

	default:
		break;
	}

	air_para->COD[0]=0x11;
	air_para->COD[1]=0x11;
	air_para->COD[2]=0x11;
	air_para->COD[3]=0x11;
	air_para->COD[4]=0x11;
	air_para->COD[9]=0x00;
	air_para->COD[10]=0x00;
	air_para->COD[11]=0x00;
	air_para->COD[12]=0x00;

	air_para->COD[13]=(air_para->COD[0]+air_para->COD[1]+air_para->COD[2]+air_para->COD[3]+air_para->COD[4]+air_para->COD[5]+air_para->COD[6]+air_para->COD[7]+air_para->COD[8]+air_para->COD[9]+air_para->COD[10]+air_para->COD[11]+air_para->COD[12]);

}



void AirRemote039(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x04;
	air_para->LDH_l=0x1f;

	air_para->LDL_h=0x02;
	air_para->LDL_l=0x24;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0x80;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0x92;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0x8e;


	air_para->BIC0=112;

	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[5]=0x20;
		break;

	case POWER_ON:
		air_para->COD[5]=0x24;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[6]=0x08;
		break;

	case MODE_COLD:
		air_para->COD[6]=0x03;
		break;

	case MODE_WET:
		air_para->COD[6]=0x02;
		break;

	case MODE_WIND:
		air_para->COD[6]=0x07;
		break;

	case MODE_HOT:
		air_para->COD[6]=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[8]=0x00;
		break;

	case SPEED_LOW:
		air_para->COD[8]=0x02;
		break;

	case SPEED_MEDIUM:
		air_para->COD[8]=0x03;
		break;

	case SPEED_HIGH:
		air_para->COD[8]=0x05;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[7]=0x0f;
		break;

	case TEMPER_17:
		air_para->COD[7]=0x0e;
		break;

	case TEMPER_18:
		air_para->COD[7]=0x0d;
		break;

	case TEMPER_19:
		air_para->COD[7]=0x0c;
		break;

	case TEMPER_20:
		air_para->COD[7]=0x0b;
		break;

	case TEMPER_21:
		air_para->COD[7]=0x0a;
		break;

	case TEMPER_22:
		air_para->COD[7]=0x09;
		break;

	case TEMPER_23:
		air_para->COD[7]=0x08;
		break;

	case TEMPER_24:
		air_para->COD[7]=0x07;
		break;

	case TEMPER_25:
		air_para->COD[7]=0x06;
		break;

	case TEMPER_26:
		air_para->COD[7]=0x05;
		break;

	case TEMPER_27:
		air_para->COD[7]=0x04;
		break;

	case TEMPER_28:
		air_para->COD[7]=0x03;
		break;

	case TEMPER_29:
		air_para->COD[7]=0x02;
		break;

	case TEMPER_30:
		air_para->COD[7]=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[8]|=0x38;
		break;

	case WIND_MANUAL:

		switch(air_status->vManualWind){
		case MANUAL_WIND_1:
			break;
		case MANUAL_WIND_2:
			air_para->COD[8]|=0x10;
			break;
		case MANUAL_WIND_3:
			air_para->COD[8]|=0x20;
			break;
		case MANUAL_WIND_4:
			air_para->COD[8]|=0x28;
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}

	air_para->COD[0]=0x23;
	air_para->COD[1]=0xcb;
	air_para->COD[2]=0x26;
	air_para->COD[3]=0x01;
	air_para->COD[4]=0x00;
	air_para->COD[9]=0x00;
	air_para->COD[10]=0x00;
	air_para->COD[11]=0x00;
	air_para->COD[12]=0x00;

	air_para->COD[13]=(air_para->COD[0]+air_para->COD[1]+air_para->COD[2]+air_para->COD[3]+air_para->COD[4]+air_para->COD[5]+air_para->COD[6]+air_para->COD[7]+air_para->COD[8]+air_para->COD[9]+air_para->COD[10]+air_para->COD[11]+air_para->COD[12]);

}


void AirRemote040(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x01;


	air_para->LDH_h=0x07;
	air_para->LDH_l=0x34;

	air_para->LDL_h=0x08;
	air_para->LDL_l=0xf7;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xa8;

	air_para->ZER_h=0x01;
	air_para->ZER_l=0xaa;

	air_para->ONE_h=0x04;
	air_para->ONE_l=0x2b;

	air_para->STO_h=0x08;
	air_para->STO_l=0xf7;

	air_para->BIC0=48;

	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[2]=0x08;
		break;

	case POWER_ON:
		air_para->COD[2]=0x00;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[2]|=0x07;
		break;

	case MODE_COLD:
		air_para->COD[2]|=0x06;
		break;

	case MODE_WET:
		air_para->COD[2]|=0x05;
		break;

	case MODE_WIND:
		air_para->COD[2]|=0x04;
		break;

	case MODE_HOT:
		air_para->COD[2]|=0x03;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[0]=0xe7;
		break;

	case SPEED_LOW:
		air_para->COD[0]=0x87;
		break;

	case SPEED_MEDIUM:
		air_para->COD[0]=0xa7;
		break;

	case SPEED_HIGH:
		air_para->COD[0]=0xc7;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[2]|=0xe0;
		break;

	case TEMPER_17:
		air_para->COD[2]|=0xe0;
		break;

	case TEMPER_18:
		air_para->COD[2]|=0xe0;
		break;

	case TEMPER_19:
		air_para->COD[2]|=0xd0;
		break;

	case TEMPER_20:
		air_para->COD[2]|=0xc0;
		break;

	case TEMPER_21:
		air_para->COD[2]|=0xb0;
		break;

	case TEMPER_22:
		air_para->COD[2]|=0xa0;
		break;

	case TEMPER_23:
		air_para->COD[2]|=0x90;
		break;

	case TEMPER_24:
		air_para->COD[2]|=0x80;
		break;

	case TEMPER_25:
		air_para->COD[2]|=0x70;
		break;

	case TEMPER_26:
		air_para->COD[2]|=0x60;
		break;

	case TEMPER_27:
		air_para->COD[2]|=0x50;
		break;

	case TEMPER_28:
		air_para->COD[2]|=0x40;
		break;

	case TEMPER_29:
		air_para->COD[2]|=0x30;
		break;

	case TEMPER_30:
		air_para->COD[2]|=0x20;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[0]|=0x10;
		break;

	case WIND_MANUAL:
		air_para->COD[0]|=0x08;
		break;

	default:
		break;
	}


	air_para->COD[1]=~air_para->COD[0];
	air_para->COD[3]=~air_para->COD[2];
	air_para->COD[4]=0x2a;
	air_para->COD[5]=0xd5;

}



void AirRemote041(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x04;
	air_para->LDH_l=0x1f;

	air_para->LDL_h=0x02;
	air_para->LDL_l=0x25;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0x7f;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0x93;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0x91;


	air_para->BIC0=112;

	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[5]=0x20;
		break;

	case POWER_ON:
		air_para->COD[5]=0x24;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[6]=0x08;
		break;

	case MODE_COLD:
		air_para->COD[6]=0x03;
		break;

	case MODE_WET:
		air_para->COD[6]=0x02;
		break;

	case MODE_WIND:
		air_para->COD[6]=0x07;
		break;

	case MODE_HOT:
		air_para->COD[6]=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[8]=0x04;
		break;

	case SPEED_LOW:
		air_para->COD[8]=0x02;
		break;

	case SPEED_MEDIUM:
		air_para->COD[8]=0x02;
		break;

	case SPEED_HIGH:
		air_para->COD[8]=0x04;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[7]=0x0f;
		break;

	case TEMPER_17:
		air_para->COD[7]=0x0e;
		break;

	case TEMPER_18:
		air_para->COD[7]=0x0d;
		break;

	case TEMPER_19:
		air_para->COD[7]=0x0c;
		break;

	case TEMPER_20:
		air_para->COD[7]=0x0b;
		break;

	case TEMPER_21:
		air_para->COD[7]=0x0a;
		break;

	case TEMPER_22:
		air_para->COD[7]=0x09;
		break;

	case TEMPER_23:
		air_para->COD[7]=0x08;
		break;

	case TEMPER_24:
		air_para->COD[7]=0x07;
		break;

	case TEMPER_25:
		air_para->COD[7]=0x06;
		break;

	case TEMPER_26:
		air_para->COD[7]=0x05;
		break;

	case TEMPER_27:
		air_para->COD[7]=0x04;
		break;

	case TEMPER_28:
		air_para->COD[7]=0x03;
		break;

	case TEMPER_29:
		air_para->COD[7]=0x02;
		break;

	case TEMPER_30:
		air_para->COD[7]=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[8]|=0x18;
		break;

	case WIND_MANUAL:
		air_para->COD[8]|=0x10;

		break;

	default:
		break;
	}

	air_para->COD[0]=0x11;
	air_para->COD[1]=0x11;
	air_para->COD[2]=0x11;
	air_para->COD[3]=0x11;
	air_para->COD[4]=0x11;
	air_para->COD[9]=0x00;
	air_para->COD[10]=0x00;
	air_para->COD[11]=0x00;
	air_para->COD[12]=0x00;

	air_para->COD[13]=(air_para->COD[0]+air_para->COD[1]+air_para->COD[2]+air_para->COD[3]+air_para->COD[4]+air_para->COD[5]+air_para->COD[6]+air_para->COD[7]+air_para->COD[8]+air_para->COD[9]+air_para->COD[10]+air_para->COD[11]+air_para->COD[12]);

}


void AirRemote042(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x04;
	air_para->LDH_l=0x1f;

	air_para->LDL_h=0x02;
	air_para->LDL_l=0x24;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0x80;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0x92;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0x8e;


	air_para->BIC0=112;

	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[5]=0x20;
		break;

	case POWER_ON:
		air_para->COD[5]=0x24;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[6]=0x08;
		break;

	case MODE_COLD:
		air_para->COD[6]=0x03;
		break;

	case MODE_WET:
		air_para->COD[6]=0x02;
		break;

	case MODE_WIND:
		air_para->COD[6]=0x07;
		break;

	case MODE_HOT:
		air_para->COD[6]=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[8]=0x00;
		break;

	case SPEED_LOW:
		air_para->COD[8]=0x02;
		break;

	case SPEED_MEDIUM:
		air_para->COD[8]=0x03;
		break;

	case SPEED_HIGH:
		air_para->COD[8]=0x05;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[7]=0x0f;
		break;

	case TEMPER_17:
		air_para->COD[7]=0x0e;
		break;

	case TEMPER_18:
		air_para->COD[7]=0x0d;
		break;

	case TEMPER_19:
		air_para->COD[7]=0x0c;
		break;

	case TEMPER_20:
		air_para->COD[7]=0x0b;
		break;

	case TEMPER_21:
		air_para->COD[7]=0x0a;
		break;

	case TEMPER_22:
		air_para->COD[7]=0x09;
		break;

	case TEMPER_23:
		air_para->COD[7]=0x08;
		break;

	case TEMPER_24:
		air_para->COD[7]=0x07;
		break;

	case TEMPER_25:
		air_para->COD[7]=0x06;
		break;

	case TEMPER_26:
		air_para->COD[7]=0x05;
		break;

	case TEMPER_27:
		air_para->COD[7]=0x04;
		break;

	case TEMPER_28:
		air_para->COD[7]=0x03;
		break;

	case TEMPER_29:
		air_para->COD[7]=0x02;
		break;

	case TEMPER_30:
		air_para->COD[7]=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[8]|=0x38;
		break;

	case WIND_MANUAL:

		switch(air_status->vManualWind){
		case MANUAL_WIND_1:
			break;
		case MANUAL_WIND_2:
			air_para->COD[8]|=0x10;
			break;
		case MANUAL_WIND_3:
			air_para->COD[8]|=0x20;
			break;
		case MANUAL_WIND_4:
			air_para->COD[8]|=0x28;
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}

	air_para->COD[0]=0x23;
	air_para->COD[1]=0xcb;
	air_para->COD[2]=0x26;
	air_para->COD[3]=0x01;
	air_para->COD[4]=0x00;
	air_para->COD[9]=0x00;
	air_para->COD[10]=0x00;
	air_para->COD[11]=0x00;
	air_para->COD[12]=0x00;

	air_para->COD[13]=(air_para->COD[0]+air_para->COD[1]+air_para->COD[2]+air_para->COD[3]+air_para->COD[4]+air_para->COD[5]+air_para->COD[6]+air_para->COD[7]+air_para->COD[8]+air_para->COD[9]+air_para->COD[10]+air_para->COD[11]+air_para->COD[12]);

}


void AirRemote045(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x03;
	air_para->LDH_l=0x93;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x62;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0x96;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0x94;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0xf9;


	air_para->BIC0=96;

	air_para->COD[1] = 0x80;

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[4]=0x50;
		break;

	case MODE_COLD:
		air_para->COD[4]=0x20;
		break;

	case MODE_WET:
		air_para->COD[4]=0x30;
		break;

	case MODE_WIND:
		air_para->COD[4]=0x40;
		break;

	case MODE_HOT:
		air_para->COD[4]=0x10;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[4]|=0x00;
		break;

	case SPEED_LOW:
		air_para->COD[4]|=0x01;
		break;

	case SPEED_MEDIUM:
		air_para->COD[4]|=0x02;
		break;

	case SPEED_HIGH:
		air_para->COD[4]|=0x03;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[1]|=0x00;
		break;

	case TEMPER_17:
		air_para->COD[1]|=0x01;
		break;

	case TEMPER_18:
		air_para->COD[1]|=0x02;
		break;

	case TEMPER_19:
		air_para->COD[1]|=0x03;
		break;

	case TEMPER_20:
		air_para->COD[1]|=0x04;
		break;

	case TEMPER_21:
		air_para->COD[1]|=0x05;
		break;

	case TEMPER_22:
		air_para->COD[1]|=0x06;
		break;

	case TEMPER_23:
		air_para->COD[1]|=0x07;
		break;

	case TEMPER_24:
		air_para->COD[1]|=0x08;
		break;

	case TEMPER_25:
		air_para->COD[1]|=0x09;
		break;

	case TEMPER_26:
		air_para->COD[1]|=0x0a;
		break;

	case TEMPER_27:
		air_para->COD[1]|=0x0b;
		break;

	case TEMPER_28:
		air_para->COD[1]|=0x0c;
		break;

	case TEMPER_29:
		air_para->COD[1]|=0x0d;
		break;

	case TEMPER_30:
		air_para->COD[1]|=0x0e;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[5]=0x00;
		break;

	case WIND_MANUAL:
		air_para->COD[5]=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vKey){

	case POWER_KEY:
		air_para->COD[5]=0x80;
		break;
	default:
		break;
	}

	air_para->COD[0]=0xaa;
	air_para->COD[2]=0x60;
	air_para->COD[3]=0x00;
	air_para->COD[6]=0x00;
	air_para->COD[7]=0x00;
	air_para->COD[8]=0x00;
	air_para->COD[9]=0x00;
	air_para->COD[10]=0x00;

	air_para->COD[11]=(air_para->COD[0]+air_para->COD[1]+air_para->COD[2]+air_para->COD[3]+air_para->COD[4]+air_para->COD[5]+air_para->COD[6]+air_para->COD[7]+air_para->COD[8]+air_para->COD[9]+air_para->COD[10]);

}



void AirRemote046(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xeb;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x87;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xc1;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xc4;

	air_para->ONE_h=0x02;
	air_para->ONE_l=0x1c;


	air_para->BIC0=35;


	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[0]=0x00;
		break;

	case MODE_COLD:
		air_para->COD[0]=0x01;
		break;

	case MODE_WET:
		air_para->COD[0]=0x02;
		break;

	case MODE_WIND:
		air_para->COD[0]=0x03;
		break;

	case MODE_HOT:
		air_para->COD[0]=0x04;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[0] |= 0x40;
		break;

	case WIND_MANUAL:
		break;

	default:
		break;
	}



	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[0]|=0x00;
		break;

	case SPEED_LOW:
		air_para->COD[0]|=0x10;
		break;

	case SPEED_MEDIUM:
		air_para->COD[0]|=0x20;
		break;

	case SPEED_HIGH:
		air_para->COD[0]|=0x30;
		break;

	default:
		break;
	}


	switch(air_status->vPower){

	case POWER_ON:
		air_para->COD[0]|=0x08;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[1]=0x00;
		break;

	case TEMPER_17:
		air_para->COD[1]=0x01;
		break;

	case TEMPER_18:
		air_para->COD[1]=0x02;
		break;

	case TEMPER_19:
		air_para->COD[1]=0x03;
		break;

	case TEMPER_20:
		air_para->COD[1]=0x04;
		break;

	case TEMPER_21:
		air_para->COD[1]=0x05;
		break;

	case TEMPER_22:
		air_para->COD[1]=0x06;
		break;

	case TEMPER_23:
		air_para->COD[1]=0x07;
		break;

	case TEMPER_24:
		air_para->COD[1]=0x08;
		break;

	case TEMPER_25:
		air_para->COD[1]=0x09;
		break;

	case TEMPER_26:
		air_para->COD[1]=0x0a;
		break;

	case TEMPER_27:
		air_para->COD[1]=0x0b;
		break;

	case TEMPER_28:
		air_para->COD[1]=0x0c;
		break;

	case TEMPER_29:
		air_para->COD[1]=0x0d;
		break;

	case TEMPER_30:
		air_para->COD[1]=0x0e;
		break;

	default:
		break;
	}


	air_para->COD[2]=0x00;
	air_para->COD[3]=0x50;
	air_para->COD[4]=0x02;

}



void AirRemote047(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0x91;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x6e;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xc2;

	air_para->ZER_h=0x01;
	air_para->ZER_l=0x36;

	air_para->ONE_h=0x02;
	air_para->ONE_l=0x6a;


	air_para->BIC0=40;

	air_para->COD[3]=0x80;

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[1]=0x1f;
		break;

	case TEMPER_17:
		air_para->COD[1]=0x10;
		break;

	case TEMPER_18:
		air_para->COD[1]=0x11;
		break;

	case TEMPER_19:
		air_para->COD[1]=0x12;
		break;

	case TEMPER_20:
		air_para->COD[1]=0x13;
		break;

	case TEMPER_21:
		air_para->COD[1]=0x14;
		break;

	case TEMPER_22:
		air_para->COD[1]=0x15;
		break;

	case TEMPER_23:
		air_para->COD[1]=0x16;
		break;

	case TEMPER_24:
		air_para->COD[1]=0x17;
		break;

	case TEMPER_25:
		air_para->COD[1]=0x18;
		break;

	case TEMPER_26:
		air_para->COD[1]=0x19;
		break;

	case TEMPER_27:
		air_para->COD[1]=0x1a;
		break;

	case TEMPER_28:
		air_para->COD[1]=0x1b;
		break;

	case TEMPER_29:
		air_para->COD[1]=0x1c;
		break;

	case TEMPER_30:
		air_para->COD[1]=0x1d;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[2]=0x00;
		break;

	case SPEED_LOW:
		air_para->COD[2]=0x30;
		break;

	case SPEED_MEDIUM:
		air_para->COD[2]=0x20;
		break;

	case SPEED_HIGH:
		air_para->COD[2]=0x10;
		break;

	default:
		break;
	}


	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[2]|=0x80;
		break;

	case WIND_MANUAL:
		air_para->COD[2]|=0x40;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[3]|=0x00;
		break;

	case MODE_COLD:
		air_para->COD[3]|=0x01;
		break;

	case MODE_WET:
		air_para->COD[3]|=0x02;
		break;

	case MODE_WIND:
		air_para->COD[3]|=0x03;
		break;

	case MODE_HOT:
		air_para->COD[3]|=0x04;
		break;

	default:
		break;
	}



	switch(air_status->vKey){

	case POWER_KEY:
		air_para->COD[1]|=0x80;
		break;

	default:
		break;
	}
	air_para->COD[0] = 0x00;
	air_para->COD[4]=0x77;


}


void AirRemote048(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x09;
	air_para->LDH_l=0xc4;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x7e;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xd1;

	air_para->ZER_h=0x01;
	air_para->ZER_l=0x36;

	air_para->ONE_h=0x02;
	air_para->ONE_l=0x6b;


	air_para->BIC0=40;

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[2]=0x10;
		break;

	case TEMPER_17:
		air_para->COD[2]=0x11;
		break;

	case TEMPER_18:
		air_para->COD[2]=0x12;
		break;

	case TEMPER_19:
		air_para->COD[2]=0x13;
		break;

	case TEMPER_20:
		air_para->COD[2]=0x14;
		break;

	case TEMPER_21:
		air_para->COD[2]=0x15;
		break;

	case TEMPER_22:
		air_para->COD[2]=0x16;
		break;

	case TEMPER_23:
		air_para->COD[2]=0x17;
		break;

	case TEMPER_24:
		air_para->COD[2]=0x18;
		break;

	case TEMPER_25:
		air_para->COD[2]=0x19;
		break;

	case TEMPER_26:
		air_para->COD[2]=0x1a;
		break;

	case TEMPER_27:
		air_para->COD[2]=0x1b;
		break;

	case TEMPER_28:
		air_para->COD[2]=0x1c;
		break;

	case TEMPER_29:
		air_para->COD[2]=0x1d;
		break;

	case TEMPER_30:
		air_para->COD[2]=0x1e;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[1]=0x00;
		break;

	case SPEED_LOW:
		air_para->COD[1]=0x01;
		break;

	case SPEED_MEDIUM:
		air_para->COD[1]=0x02;
		break;

	case SPEED_HIGH:
		air_para->COD[1]=0x03;
		break;

	default:
		break;
	}


	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[3]=0x04;
		break;

	case WIND_MANUAL:
		air_para->COD[3]=0x00;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[1]|=0x30;
		break;

	case MODE_COLD:
		air_para->COD[1]|=0x00;
		break;

	case MODE_WET:
		air_para->COD[1]|=0x80;
		break;

	case MODE_WIND:
		air_para->COD[1]|=0x70;
		break;

	case MODE_HOT:
		air_para->COD[1]|=0x10;
		break;

	default:
		break;
	}



	switch(air_status->vKey){

	case POWER_KEY:
		air_para->COD[3]|=0x0b;
		break;

	default:
		break;
	}
	air_para->COD[0] = 0xa9;
	air_para->COD[4]=0x01;


}


void AirRemote049(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xeb;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x83;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xae;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xfc;

	air_para->ONE_h=0x02;
	air_para->ONE_l=0x49;


	air_para->BIC0=40;

	air_para->COD[0] = 0x40;


	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[2]=0x10;
		break;

	case TEMPER_17:
		air_para->COD[2]=0x11;
		break;

	case TEMPER_18:
		air_para->COD[2]=0x12;
		break;

	case TEMPER_19:
		air_para->COD[2]=0x13;
		break;

	case TEMPER_20:
		air_para->COD[2]=0x14;
		break;

	case TEMPER_21:
		air_para->COD[2]=0x15;
		break;

	case TEMPER_22:
		air_para->COD[2]=0x16;
		break;

	case TEMPER_23:
		air_para->COD[2]=0x17;
		break;

	case TEMPER_24:
		air_para->COD[2]=0x18;
		break;

	case TEMPER_25:
		air_para->COD[2]=0x19;
		break;

	case TEMPER_26:
		air_para->COD[2]=0x1a;
		break;

	case TEMPER_27:
		air_para->COD[2]=0x1b;
		break;

	case TEMPER_28:
		air_para->COD[2]=0x1c;
		break;

	case TEMPER_29:
		air_para->COD[2]=0x1d;
		break;

	case TEMPER_30:
		air_para->COD[2]=0x1e;
		break;

	default:
		break;
	}


	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[1]=0x00;
		air_para->COD[2]=0x1b;
		break;

	case MODE_COLD:
		air_para->COD[1]=0x01;
		break;

	case MODE_WET:
		air_para->COD[1]=0x02;
		break;

	case MODE_WIND:
		air_para->COD[1]=0x03;
		break;

	case MODE_HOT:
		air_para->COD[1]=0x04;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		break;

	case SPEED_LOW:
		air_para->COD[1]|=0x10;
		break;

	case SPEED_MEDIUM:
		air_para->COD[1]|=0x20;
		break;

	case SPEED_HIGH:
		air_para->COD[1]|=0x30;
		break;

	default:
		break;
	}


	switch(air_status->vKey){

	case POWER_KEY:
		air_para->COD[1]|=0x80;
		break;

	case WIND_MANUAL_KEY:
		air_para->COD[0]=0x51;
		air_para->COD[1]=0xae;
		break;

	case WIND_AUTO_KEY:
		air_para->COD[0]=0x50;
		air_para->COD[1]=0xaf;
		break;

	default:
		break;
	}

	air_para->COD[4]=0x00;
	air_para->COD[3]=air_para->COD[0]+air_para->COD[1]+air_para->COD[2];
	air_para->COD[3]=~air_para->COD[3];


}


void AirRemote050(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xeb;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x83;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xae;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xfc;

	air_para->ONE_h=0x02;
	air_para->ONE_l=0x49;


	air_para->BIC0=40;

	air_para->COD[0] = 0x40;


	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[2]=0x10;
		break;

	case TEMPER_17:
		air_para->COD[2]=0x11;
		break;

	case TEMPER_18:
		air_para->COD[2]=0x12;
		break;

	case TEMPER_19:
		air_para->COD[2]=0x13;
		break;

	case TEMPER_20:
		air_para->COD[2]=0x14;
		break;

	case TEMPER_21:
		air_para->COD[2]=0x15;
		break;

	case TEMPER_22:
		air_para->COD[2]=0x16;
		break;

	case TEMPER_23:
		air_para->COD[2]=0x17;
		break;

	case TEMPER_24:
		air_para->COD[2]=0x18;
		break;

	case TEMPER_25:
		air_para->COD[2]=0x19;
		break;

	case TEMPER_26:
		air_para->COD[2]=0x1a;
		break;

	case TEMPER_27:
		air_para->COD[2]=0x1b;
		break;

	case TEMPER_28:
		air_para->COD[2]=0x1c;
		break;

	case TEMPER_29:
		air_para->COD[2]=0x1d;
		break;

	case TEMPER_30:
		air_para->COD[2]=0x1e;
		break;

	default:
		break;
	}


	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[1]=0x00;
		air_para->COD[2]=0x1b;
		break;

	case MODE_COLD:
		air_para->COD[1]=0x01;
		break;

	case MODE_WET:
		air_para->COD[1]=0x02;
		break;

	case MODE_WIND:
		air_para->COD[1]=0x03;
		break;

	case MODE_HOT:
		air_para->COD[1]=0x04;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		break;

	case SPEED_LOW:
		air_para->COD[1]|=0x10;
		break;

	case SPEED_MEDIUM:
		air_para->COD[1]|=0x20;
		break;

	case SPEED_HIGH:
		air_para->COD[1]|=0x30;
		break;

	default:
		break;
	}


	switch(air_status->vKey){

	case POWER_KEY:
		air_para->COD[1]|=0x80;
		break;

	case WIND_MANUAL_KEY:
		air_para->COD[0]=0x51;
		air_para->COD[1]=0xae;
		break;

	case WIND_AUTO_KEY:
		air_para->COD[0]=0x50;
		air_para->COD[1]=0xaf;
		break;

	default:
		break;
	}

	air_para->COD[4]=0x11;
	air_para->COD[3]=air_para->COD[0]+air_para->COD[1]+air_para->COD[2];
	air_para->COD[3]=~air_para->COD[3];


}


void AirRemote052(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x04;
	air_para->LDH_l=0x20;

	air_para->LDL_h=0x02;
	air_para->LDL_l=0x26;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0x82;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0x92;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0x8e;


	air_para->BIC0=112;

	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[5]=0x20;
		break;

	case POWER_ON:
		air_para->COD[5]=0x24;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[6]=0x08;
		break;

	case MODE_COLD:
		air_para->COD[6]=0x03;
		break;

	case MODE_WET:
		air_para->COD[6]=0x02;
		break;

	case MODE_WIND:
		air_para->COD[6]=0x07;
		break;

	case MODE_HOT:
		air_para->COD[6]=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[8]=0x00;
		break;

	case SPEED_LOW:
		air_para->COD[8]=0x02;
		break;

	case SPEED_MEDIUM:
		air_para->COD[8]=0x03;
		break;

	case SPEED_HIGH:
		air_para->COD[8]=0x05;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[7]=0x0f;
		break;

	case TEMPER_17:
		air_para->COD[7]=0x0e;
		break;

	case TEMPER_18:
		air_para->COD[7]=0x0d;
		break;

	case TEMPER_19:
		air_para->COD[7]=0x0c;
		break;

	case TEMPER_20:
		air_para->COD[7]=0x0b;
		break;

	case TEMPER_21:
		air_para->COD[7]=0x0a;
		break;

	case TEMPER_22:
		air_para->COD[7]=0x09;
		break;

	case TEMPER_23:
		air_para->COD[7]=0x08;
		break;

	case TEMPER_24:
		air_para->COD[7]=0x07;
		break;

	case TEMPER_25:
		air_para->COD[7]=0x06;
		break;

	case TEMPER_26:
		air_para->COD[7]=0x05;
		break;

	case TEMPER_27:
		air_para->COD[7]=0x04;
		break;

	case TEMPER_28:
		air_para->COD[7]=0x03;
		break;

	case TEMPER_29:
		air_para->COD[7]=0x02;
		break;

	case TEMPER_30:
		air_para->COD[7]=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[8]|=0x38;
		break;

	case WIND_MANUAL:

		switch(air_status->vManualWind){
		case MANUAL_WIND_1:
			break;
		case MANUAL_WIND_2:
			air_para->COD[8]|=0x10;
			break;
		case MANUAL_WIND_3:
			air_para->COD[8]|=0x20;
			break;
		case MANUAL_WIND_4:
			air_para->COD[8]|=0x28;
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}

	air_para->COD[0]=0x23;
	air_para->COD[1]=0xcb;
	air_para->COD[2]=0x26;
	air_para->COD[3]=0x01;
	air_para->COD[4]=0x00;
	air_para->COD[9]=0x00;
	air_para->COD[10]=0x00;
	air_para->COD[11]=0x00;
	air_para->COD[12]=0x00;

	air_para->COD[13]=(air_para->COD[0]+air_para->COD[1]+air_para->COD[2]+air_para->COD[3]+air_para->COD[4]+air_para->COD[5]+air_para->COD[6]+air_para->COD[7]+air_para->COD[8]+air_para->COD[9]+air_para->COD[10]+air_para->COD[11]+air_para->COD[12]);

}


void AirRemote057(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x04;
	air_para->LDH_l=0x20;

	air_para->LDL_h=0x02;
	air_para->LDL_l=0x26;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0x82;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0x92;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0x8e;


	air_para->BIC0=112;

	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[5]=0x20;
		break;

	case POWER_ON:
		air_para->COD[5]=0x24;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[6]=0x08;
		break;

	case MODE_COLD:
		air_para->COD[6]=0x03;
		break;

	case MODE_WET:
		air_para->COD[6]=0x02;
		break;

	case MODE_WIND:
		air_para->COD[6]=0x07;
		break;

	case MODE_HOT:
		air_para->COD[6]=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[8]=0x00;
		break;

	case SPEED_LOW:
		air_para->COD[8]=0x02;
		break;

	case SPEED_MEDIUM:
		air_para->COD[8]=0x03;
		break;

	case SPEED_HIGH:
		air_para->COD[8]=0x05;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[7]=0x0f;
		break;

	case TEMPER_17:
		air_para->COD[7]=0x0e;
		break;

	case TEMPER_18:
		air_para->COD[7]=0x0d;
		break;

	case TEMPER_19:
		air_para->COD[7]=0x0c;
		break;

	case TEMPER_20:
		air_para->COD[7]=0x0b;
		break;

	case TEMPER_21:
		air_para->COD[7]=0x0a;
		break;

	case TEMPER_22:
		air_para->COD[7]=0x09;
		break;

	case TEMPER_23:
		air_para->COD[7]=0x08;
		break;

	case TEMPER_24:
		air_para->COD[7]=0x07;
		break;

	case TEMPER_25:
		air_para->COD[7]=0x06;
		break;

	case TEMPER_26:
		air_para->COD[7]=0x05;
		break;

	case TEMPER_27:
		air_para->COD[7]=0x04;
		break;

	case TEMPER_28:
		air_para->COD[7]=0x03;
		break;

	case TEMPER_29:
		air_para->COD[7]=0x02;
		break;

	case TEMPER_30:
		air_para->COD[7]=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[8]|=0x38;
		break;

	case WIND_MANUAL:

		switch(air_status->vManualWind){
		case MANUAL_WIND_1:
			break;
		case MANUAL_WIND_2:
			air_para->COD[8]|=0x10;
			break;
		case MANUAL_WIND_3:
			air_para->COD[8]|=0x20;
			break;
		case MANUAL_WIND_4:
			air_para->COD[8]|=0x28;
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}

	air_para->COD[0]=0x11;
	air_para->COD[1]=0x11;
	air_para->COD[2]=0x11;
	air_para->COD[3]=0x11;
	air_para->COD[4]=0x11;
	air_para->COD[9]=0x00;
	air_para->COD[10]=0x00;
	air_para->COD[11]=0x00;
	air_para->COD[12]=0x00;

	air_para->COD[13]=(air_para->COD[0]+air_para->COD[1]+air_para->COD[2]+air_para->COD[3]+air_para->COD[4]+air_para->COD[5]+air_para->COD[6]+air_para->COD[7]+air_para->COD[8]+air_para->COD[9]+air_para->COD[10]+air_para->COD[11]+air_para->COD[12]);

}


void AirRemote058(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x04;
	air_para->LDH_l=0x20;

	air_para->LDL_h=0x02;
	air_para->LDL_l=0x26;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0x82;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0x92;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0x8e;


	air_para->BIC0=112;

	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[5]=0x20;
		break;

	case POWER_ON:
		air_para->COD[5]=0x24;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[6]=0x08;
		break;

	case MODE_COLD:
		air_para->COD[6]=0x03;
		break;

	case MODE_WET:
		air_para->COD[6]=0x02;
		break;

	case MODE_WIND:
		air_para->COD[6]=0x07;
		break;

	case MODE_HOT:
		air_para->COD[6]=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[8]=0x00;
		break;

	case SPEED_LOW:
		air_para->COD[8]=0x02;
		break;

	case SPEED_MEDIUM:
		air_para->COD[8]=0x03;
		break;

	case SPEED_HIGH:
		air_para->COD[8]=0x05;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[7]=0x0f;
		break;

	case TEMPER_17:
		air_para->COD[7]=0x0e;
		break;

	case TEMPER_18:
		air_para->COD[7]=0x0d;
		break;

	case TEMPER_19:
		air_para->COD[7]=0x0c;
		break;

	case TEMPER_20:
		air_para->COD[7]=0x0b;
		break;

	case TEMPER_21:
		air_para->COD[7]=0x0a;
		break;

	case TEMPER_22:
		air_para->COD[7]=0x09;
		break;

	case TEMPER_23:
		air_para->COD[7]=0x08;
		break;

	case TEMPER_24:
		air_para->COD[7]=0x07;
		break;

	case TEMPER_25:
		air_para->COD[7]=0x06;
		break;

	case TEMPER_26:
		air_para->COD[7]=0x05;
		break;

	case TEMPER_27:
		air_para->COD[7]=0x04;
		break;

	case TEMPER_28:
		air_para->COD[7]=0x03;
		break;

	case TEMPER_29:
		air_para->COD[7]=0x02;
		break;

	case TEMPER_30:
		air_para->COD[7]=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[8]|=0x38;
		break;

	case WIND_MANUAL:

		switch(air_status->vManualWind){
		case MANUAL_WIND_1:
			break;
		case MANUAL_WIND_2:
			air_para->COD[8]|=0x10;
			break;
		case MANUAL_WIND_3:
			air_para->COD[8]|=0x20;
			break;
		case MANUAL_WIND_4:
			air_para->COD[8]|=0x28;
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}

	air_para->COD[0]=0x23;
	air_para->COD[1]=0xcb;
	air_para->COD[2]=0x26;
	air_para->COD[3]=0x01;
	air_para->COD[4]=0x00;
	air_para->COD[9]=0x00;
	air_para->COD[10]=0x00;
	air_para->COD[11]=0x00;
	air_para->COD[12]=0x00;

	air_para->COD[13]=(air_para->COD[0]+air_para->COD[1]+air_para->COD[2]+air_para->COD[3]+air_para->COD[4]+air_para->COD[5]+air_para->COD[6]+air_para->COD[7]+air_para->COD[8]+air_para->COD[9]+air_para->COD[10]+air_para->COD[11]+air_para->COD[12]);

}


void AirRemote062(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x04;
	air_para->LDH_l=0x20;

	air_para->LDL_h=0x02;
	air_para->LDL_l=0x26;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0x82;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0x92;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0x8e;


	air_para->BIC0=112;

	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[5]=0x20;
		break;

	case POWER_ON:
		air_para->COD[5]=0x24;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[6]=0x08;
		break;

	case MODE_COLD:
		air_para->COD[6]=0x03;
		break;

	case MODE_WET:
		air_para->COD[6]=0x02;
		break;

	case MODE_WIND:
		air_para->COD[6]=0x07;
		break;

	case MODE_HOT:
		air_para->COD[6]=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[8]=0x00;
		break;

	case SPEED_LOW:
		air_para->COD[8]=0x02;
		break;

	case SPEED_MEDIUM:
		air_para->COD[8]=0x03;
		break;

	case SPEED_HIGH:
		air_para->COD[8]=0x05;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[7]=0x0f;
		break;

	case TEMPER_17:
		air_para->COD[7]=0x0e;
		break;

	case TEMPER_18:
		air_para->COD[7]=0x0d;
		break;

	case TEMPER_19:
		air_para->COD[7]=0x0c;
		break;

	case TEMPER_20:
		air_para->COD[7]=0x0b;
		break;

	case TEMPER_21:
		air_para->COD[7]=0x0a;
		break;

	case TEMPER_22:
		air_para->COD[7]=0x09;
		break;

	case TEMPER_23:
		air_para->COD[7]=0x08;
		break;

	case TEMPER_24:
		air_para->COD[7]=0x07;
		break;

	case TEMPER_25:
		air_para->COD[7]=0x06;
		break;

	case TEMPER_26:
		air_para->COD[7]=0x05;
		break;

	case TEMPER_27:
		air_para->COD[7]=0x04;
		break;

	case TEMPER_28:
		air_para->COD[7]=0x03;
		break;

	case TEMPER_29:
		air_para->COD[7]=0x02;
		break;

	case TEMPER_30:
		air_para->COD[7]=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[8]|=0x38;
		break;

	case WIND_MANUAL:

		switch(air_status->vManualWind){
		case MANUAL_WIND_1:
			break;
		case MANUAL_WIND_2:
			air_para->COD[8]|=0x10;
			break;
		case MANUAL_WIND_3:
			air_para->COD[8]|=0x20;
			break;
		case MANUAL_WIND_4:
			air_para->COD[8]|=0x28;
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}

	air_para->COD[0]=0x23;
	air_para->COD[1]=0xcb;
	air_para->COD[2]=0x26;
	air_para->COD[3]=0x01;
	air_para->COD[4]=0x00;
	air_para->COD[9]=0x00;
	air_para->COD[10]=0x00;
	air_para->COD[11]=0x00;
	air_para->COD[12]=0x00;

	air_para->COD[13]=(air_para->COD[0]+air_para->COD[1]+air_para->COD[2]+air_para->COD[3]+air_para->COD[4]+air_para->COD[5]+air_para->COD[6]+air_para->COD[7]+air_para->COD[8]+air_para->COD[9]+air_para->COD[10]+air_para->COD[11]+air_para->COD[12]);

}



void AirRemote065(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xeb;

	air_para->LDL_h=0x02;
	air_para->LDL_l=0x81;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0x96;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xa9;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0x8f;


	air_para->BIC0=40;

	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[1]=0x00;
		break;

	case POWER_ON:
		air_para->COD[1]=0x10;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[2]=0x00;
		break;

	case MODE_COLD:
		air_para->COD[2]=0x01;
		break;

	case MODE_WET:
		air_para->COD[2]=0x02;
		break;

	case MODE_WIND:
		air_para->COD[2]=0x04;
		break;

	case MODE_HOT:
		air_para->COD[2]=0x03;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		break;

	case SPEED_LOW:
		air_para->COD[2]|=0x60;
		break;

	case SPEED_MEDIUM:
		air_para->COD[2]|=0x40;
		break;

	case SPEED_HIGH:
		air_para->COD[2]|=0x20;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[3]=0x18;
		break;

	case TEMPER_17:
		air_para->COD[3]=0x18;
		break;

	case TEMPER_18:
		air_para->COD[3]=0x18;
		break;

	case TEMPER_19:
		air_para->COD[3]=0x19;
		break;

	case TEMPER_20:
		air_para->COD[3]=0x20;
		break;

	case TEMPER_21:
		air_para->COD[3]=0x21;
		break;

	case TEMPER_22:
		air_para->COD[3]=0x22;
		break;

	case TEMPER_23:
		air_para->COD[3]=0x23;
		break;

	case TEMPER_24:
		air_para->COD[3]=0x24;
		break;

	case TEMPER_25:
		air_para->COD[3]=0x25;
		break;

	case TEMPER_26:
		air_para->COD[3]=0x26;
		break;

	case TEMPER_27:
		air_para->COD[3]=0x27;
		break;

	case TEMPER_28:
		air_para->COD[3]=0x28;
		break;

	case TEMPER_29:
		air_para->COD[3]=0x29;
		break;

	case TEMPER_30:
		air_para->COD[3]=0x30;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[2]|=0x10;
		break;

	case WIND_MANUAL:
		break;

	default:
		break;
	}

	air_para->COD[0]=0xaa;

	air_para->COD[4]=(air_para->COD[0]+air_para->COD[1]+air_para->COD[2]+air_para->COD[3]);

}



void AirRemote066(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0x1e;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x55;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xb7;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xc2;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0xf6;


	air_para->BIC0=32;

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[1]=0x00;
		break;

	case MODE_COLD:
		air_para->COD[1]=0x01;
		break;

	case MODE_WET:
		air_para->COD[1]=0x02;
		break;

	case MODE_WIND:
		air_para->COD[1]=0x03;
		break;

	case MODE_HOT:
		air_para->COD[1]=0x04;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		break;

	case SPEED_LOW:
		air_para->COD[1]|=0x10;
		break;

	case SPEED_MEDIUM:
		air_para->COD[1]|=0x20;
		break;

	case SPEED_HIGH:
		air_para->COD[1]|=0x30;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[2]=0x10;
		break;

	case TEMPER_17:
		air_para->COD[2]=0x11;
		break;

	case TEMPER_18:
		air_para->COD[2]=0x12;
		break;

	case TEMPER_19:
		air_para->COD[2]=0x13;
		break;

	case TEMPER_20:
		air_para->COD[2]=0x14;
		break;

	case TEMPER_21:
		air_para->COD[2]=0x15;
		break;

	case TEMPER_22:
		air_para->COD[2]=0x16;
		break;

	case TEMPER_23:
		air_para->COD[2]=0x17;
		break;

	case TEMPER_24:
		air_para->COD[2]=0x18;
		break;

	case TEMPER_25:
		air_para->COD[2]=0x19;
		break;

	case TEMPER_26:
		air_para->COD[2]=0x1a;
		break;

	case TEMPER_27:
		air_para->COD[2]=0x1b;
		break;

	case TEMPER_28:
		air_para->COD[2]=0x1c;
		break;

	case TEMPER_29:
		air_para->COD[2]=0x1d;
		break;

	case TEMPER_30:
		air_para->COD[2]=0x1e;
		break;

	default:
		break;
	}

	switch(air_status->vKey){

	case POWER_KEY:
		air_para->COD[1]|=0x80;
		break;

	case WIND_MANUAL_KEY:
		air_para->COD[0]=0xd1;
		air_para->COD[1]=0x2e;
    	air_para->BIC0=16;
		return;

	case WIND_AUTO_KEY:
		air_para->COD[0]=0xd0;
		air_para->COD[1]=0x2f;
	    air_para->BIC0=16;
		return;

	default:
		break;
	}

	air_para->COD[0]=0xc0;

	air_para->COD[3]=(air_para->COD[0]+air_para->COD[1]+air_para->COD[2]);
	air_para->COD[3]=~air_para->COD[3];

}


void AirRemote067(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xeb;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x82;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xce;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xc3;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0xe2;


	air_para->BIC0=96;

	switch(air_status->vKey){

	case POWER_KEY:
		air_para->COD[0]=0x00;
		break;

	case MODE_KEY:
		air_para->COD[0]=0x01;

		break;

	case SPEED_KEY:
		air_para->COD[0]=0x05;
		break;

	case TEMPER_INC_KEY:
		air_para->COD[0]=0x03;
		break;

	case TEMPER_DEC_KEY:
		air_para->COD[0]=0x04;
		break;

	case WIND_MANUAL_KEY:
		air_para->COD[0]=0x0d;
		break;

	case WIND_AUTO_KEY:
		air_para->COD[0]=0x0c;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		break;

	case MODE_COLD:
		air_para->COD[0]|=0x10;
		break;

	case MODE_WET:
		air_para->COD[0]|=0x20;
		break;

	case MODE_WIND:
		air_para->COD[0]|=0x40;
		break;

	case MODE_HOT:
		air_para->COD[0]|=0x80;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[9]=0x00;
		break;

	case SPEED_LOW:
		air_para->COD[9]=0x01;
		break;

	case SPEED_MEDIUM:
		air_para->COD[9]=0x02;
		break;

	case SPEED_HIGH:
		air_para->COD[9]=0x03;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[8]=0x18;
		break;

	case TEMPER_17:
		air_para->COD[8]=0x18;
		break;

	case TEMPER_18:
		air_para->COD[8]=0x18;
		break;

	case TEMPER_19:
		air_para->COD[8]=0x19;
		break;

	case TEMPER_20:
		air_para->COD[8]=0x20;
		break;

	case TEMPER_21:
		air_para->COD[8]=0x21;
		break;

	case TEMPER_22:
		air_para->COD[8]=0x22;
		break;

	case TEMPER_23:
		air_para->COD[8]=0x23;
		break;

	case TEMPER_24:
		air_para->COD[8]=0x24;
		break;

	case TEMPER_25:
		air_para->COD[8]=0x25;
		break;

	case TEMPER_26:
		air_para->COD[8]=0x26;
		break;

	case TEMPER_27:
		air_para->COD[8]=0x27;
		break;

	case TEMPER_28:
		air_para->COD[8]=0x28;
		break;

	case TEMPER_29:
		air_para->COD[8]=0x29;
		break;

	case TEMPER_30:
		air_para->COD[8]=0x30;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[9] |= 0x40;
		break;

	case WIND_MANUAL:

		break;

	default:
		break;
	}

	air_para->COD[1] = 0x12;
	air_para->COD[2] = 0x00;
	air_para->COD[3]=0x00;
	air_para->COD[4]=0x00;
	air_para->COD[5]=0x00;
	air_para->COD[6]=0x00;
	air_para->COD[7]=0x00;
	air_para->COD[10]=0x00;
	air_para->COD[11]=0x19;

}


void AirRemote096(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xf6;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x4c;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xcb;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xa2;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0xfd;


	air_para->BIC0=35;


	switch(air_status->vPower){

		case POWER_OFF:
			air_para->COD[0]|=0x00;
			break;

		case POWER_ON:
			air_para->COD[0]|=0x08;
			break;

		default:
			break;
	}

	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[0]|=0x00;
			break;

		case MODE_COLD:
			air_para->COD[0]|=0x01;
			break;

		case MODE_WET:
			air_para->COD[0]|=0x02;
			break;

		case MODE_WIND:
			air_para->COD[0]|=0x03;
			break;

		case MODE_HOT:
			air_para->COD[0]|=0x04;
			break;

		default:
			break;
	}

	switch(air_status->vSpeed){

		case SPEED_AUTO:
			air_para->COD[0]|=0x00;
			break;

		case SPEED_LOW:
			air_para->COD[0]|=0x10;
			break;

		case SPEED_MEDIUM:
			air_para->COD[0]|=0x20;
			break;

		case SPEED_HIGH:
			air_para->COD[0]|=0x30;
			break;

		default:
			break;
	}

	switch(air_status->vTemper){

		case TEMPER_16:
			air_para->COD[1]=0x00;
			break;

		case TEMPER_17:
			air_para->COD[1]=0x01;
			break;

		case TEMPER_18:
			air_para->COD[1]=0x02;
			break;

		case TEMPER_19:
			air_para->COD[1]=0x03;
			break;

		case TEMPER_20:
			air_para->COD[1]=0x04;
			break;

		case TEMPER_21:
			air_para->COD[1]=0x05;
			break;

		case TEMPER_22:
			air_para->COD[1]=0x06;
			break;

		case TEMPER_23:
			air_para->COD[1]=0x07;
			break;

		case TEMPER_24:
			air_para->COD[1]=0x08;
			break;

		case TEMPER_25:
			air_para->COD[1]=0x09;
			break;

		case TEMPER_26:
			air_para->COD[1]=0x0a;
			break;

		case TEMPER_27:
			air_para->COD[1]=0x0b;
			break;

		case TEMPER_28:
			air_para->COD[1]=0x0c;
			break;

		case TEMPER_29:
			air_para->COD[1]=0x0d;
			break;

		case TEMPER_30:
			air_para->COD[1]=0x0e;
			break;

		default:
			break;
	}


	switch(air_status->vWind){

		case WIND_AUTO:
			air_para->COD[0]|=0x40;
			break;

		case WIND_MANUAL:
			air_para->COD[0]|=0x00;
			break;

		default:
			break;
	}


	air_para->COD[2]=0x00;
	air_para->COD[3]=0x50;
	air_para->COD[4]=0x02;
}


void AirRemote115(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x04;
	air_para->LDH_l=0x29;

	air_para->LDL_h=0x02;
	air_para->LDL_l=0x1c;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0x92;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0x8a;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0x80;


	air_para->BIC0=112;

	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[5]=0x20;
		break;

	case POWER_ON:
		air_para->COD[5]=0x24;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[6]|=0x08;
		break;

	case MODE_COLD:
		air_para->COD[6]|=0x03;
		break;

	case MODE_WET:
		air_para->COD[6]|=0x02;
		break;

	case MODE_WIND:
		air_para->COD[6]|=0x07;
		break;

	case MODE_HOT:
		air_para->COD[6]|=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[8]=0x00;
		break;

	case SPEED_LOW:
		air_para->COD[8]=0x02;
		break;

	case SPEED_MEDIUM:
		air_para->COD[8]=0x03;
		break;

	case SPEED_HIGH:
		air_para->COD[8]=0x05;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[7]=0x0f;
		break;

	case TEMPER_17:
		air_para->COD[7]=0x0e;
		break;

	case TEMPER_18:
		air_para->COD[7]=0x0d;
		break;

	case TEMPER_19:
		air_para->COD[7]=0x0c;
		break;

	case TEMPER_20:
		air_para->COD[7]=0x0b;
		break;

	case TEMPER_21:
		air_para->COD[7]=0x0a;
		break;

	case TEMPER_22:
		air_para->COD[7]=0x09;
		break;

	case TEMPER_23:
		air_para->COD[7]=0x08;
		break;

	case TEMPER_24:
		air_para->COD[7]=0x07;
		break;

	case TEMPER_25:
		air_para->COD[7]=0x06;
		break;

	case TEMPER_26:
		air_para->COD[7]=0x05;
		break;

	case TEMPER_27:
		air_para->COD[7]=0x04;
		break;

	case TEMPER_28:
		air_para->COD[7]=0x03;
		break;

	case TEMPER_29:
		air_para->COD[7]=0x02;
		break;

	case TEMPER_30:
		air_para->COD[7]=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[8]|=0x38;
		break;

	case WIND_MANUAL:

		switch(air_status->vManualWind){
		case MANUAL_WIND_1:
			air_para->COD[8]|=0x00;
			break;
		case MANUAL_WIND_2:
			air_para->COD[8]|=0x10;
			break;
		case MANUAL_WIND_3:
			air_para->COD[8]|=0x20;
			break;
		case MANUAL_WIND_4:
			air_para->COD[8]|=0x28;
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}

	air_para->COD[0]=0x23;
	air_para->COD[1]=0xcb;
	air_para->COD[2]=0x26;
	air_para->COD[3]=0x01;
	air_para->COD[4]=0x00;

	air_para->COD[9]=0x00;
	air_para->COD[10]=0x00;
	air_para->COD[11]=0x00;
	air_para->COD[12]=0x00;

	air_para->COD[13]=(air_para->COD[0]+air_para->COD[1]+air_para->COD[2]+air_para->COD[3]+air_para->COD[4]+air_para->COD[5]+air_para->COD[6]+air_para->COD[7]+air_para->COD[8]+air_para->COD[9]+air_para->COD[10]+air_para->COD[11]+air_para->COD[12]);

}


void AirRemote123(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0x3b;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x3c;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xc2;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xc3;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0xf4;


	air_para->BIC0=32;


	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[1]|=0x00;
			break;

		case MODE_COLD:
			air_para->COD[1]|=0x01;
			break;

		case MODE_WET:
			air_para->COD[1]|=0x02;
			break;

		case MODE_WIND:
			air_para->COD[1]|=0x03;
			break;

		case MODE_HOT:
			air_para->COD[1]|=0x04;
			break;

		default:
			break;
	}

	switch(air_status->vSpeed){

		case SPEED_AUTO:
			air_para->COD[1]|=0x00;
			break;

		case SPEED_LOW:
			air_para->COD[1]|=0x10;
			break;

		case SPEED_MEDIUM:
			air_para->COD[1]|=0x20;
			break;

		case SPEED_HIGH:
			air_para->COD[1]|=0x30;
			break;

		default:
			break;
	}

	switch(air_status->vTemper){

		case TEMPER_16:
			air_para->COD[2]=0x10;
			break;

		case TEMPER_17:
			air_para->COD[2]=0x11;
			break;

		case TEMPER_18:
			air_para->COD[2]=0x12;
			break;

		case TEMPER_19:
			air_para->COD[2]=0x13;
			break;

		case TEMPER_20:
			air_para->COD[2]=0x14;
			break;

		case TEMPER_21:
			air_para->COD[2]=0x15;
			break;

		case TEMPER_22:
			air_para->COD[2]=0x16;
			break;

		case TEMPER_23:
			air_para->COD[2]=0x17;
			break;

		case TEMPER_24:
			air_para->COD[2]=0x18;
			break;

		case TEMPER_25:
			air_para->COD[2]=0x19;
			break;

		case TEMPER_26:
			air_para->COD[2]=0x1a;
			break;

		case TEMPER_27:
			air_para->COD[2]=0x1b;
			break;

		case TEMPER_28:
			air_para->COD[2]=0x1c;
			break;

		case TEMPER_29:
			air_para->COD[2]=0x1d;
			break;

		case TEMPER_30:
			air_para->COD[2]=0x1e;
			break;

		default:
			break;
	}


	switch(air_status->vKey){

		case POWER_KEY:
			air_para->COD[1]|=0x80;
			break;

		default:
			break;
	}

	air_para->COD[0]=0xc0;
	air_para->COD[3]=~((air_para->COD[0])+(air_para->COD[1])+(air_para->COD[2]));

}


void AirRemote124(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0x3b;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x3c;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xc2;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xc3;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0xf4;


	air_para->BIC0=32;


	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[1]|=0x00;
			break;

		case MODE_COLD:
			air_para->COD[1]|=0x01;
			break;

		case MODE_WET:
			air_para->COD[1]|=0x02;
			break;

		case MODE_WIND:
			air_para->COD[1]|=0x03;
			break;

		case MODE_HOT:
			air_para->COD[1]|=0x04;
			break;

		default:
			break;
	}

	switch(air_status->vSpeed){

		case SPEED_AUTO:
			air_para->COD[1]|=0x00;
			break;

		case SPEED_LOW:
			air_para->COD[1]|=0x10;
			break;

		case SPEED_MEDIUM:
			air_para->COD[1]|=0x20;
			break;

		case SPEED_HIGH:
			air_para->COD[1]|=0x30;
			break;

		default:
			break;
	}

	switch(air_status->vTemper){

		case TEMPER_16:
			air_para->COD[2]=0x10;
			break;

		case TEMPER_17:
			air_para->COD[2]=0x11;
			break;

		case TEMPER_18:
			air_para->COD[2]=0x12;
			break;

		case TEMPER_19:
			air_para->COD[2]=0x13;
			break;

		case TEMPER_20:
			air_para->COD[2]=0x14;
			break;

		case TEMPER_21:
			air_para->COD[2]=0x15;
			break;

		case TEMPER_22:
			air_para->COD[2]=0x16;
			break;

		case TEMPER_23:
			air_para->COD[2]=0x17;
			break;

		case TEMPER_24:
			air_para->COD[2]=0x18;
			break;

		case TEMPER_25:
			air_para->COD[2]=0x19;
			break;

		case TEMPER_26:
			air_para->COD[2]=0x1a;
			break;

		case TEMPER_27:
			air_para->COD[2]=0x1b;
			break;

		case TEMPER_28:
			air_para->COD[2]=0x1c;
			break;

		case TEMPER_29:
			air_para->COD[2]=0x1d;
			break;

		case TEMPER_30:
			air_para->COD[2]=0x1e;
			break;

		default:
			break;
	}


	switch(air_status->vKey){

		case POWER_KEY:
			air_para->COD[1]|=0x80;
			break;

		default:
			break;
	}

	air_para->COD[0]=0xc0;
	air_para->COD[3]=~((air_para->COD[0])+(air_para->COD[1])+(air_para->COD[2]));

}


void AirRemote125(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0x3b;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x3c;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xc2;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xc3;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0xf4;


	air_para->BIC0=32;


	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[1]|=0x00;
			break;

		case MODE_COLD:
			air_para->COD[1]|=0x01;
			break;

		case MODE_WET:
			air_para->COD[1]|=0x02;
			break;

		case MODE_WIND:
			air_para->COD[1]|=0x03;
			break;

		case MODE_HOT:
			air_para->COD[1]|=0x04;
			break;

		default:
			break;
	}

	switch(air_status->vSpeed){

		case SPEED_AUTO:
			air_para->COD[1]|=0x00;
			break;

		case SPEED_LOW:
			air_para->COD[1]|=0x10;
			break;

		case SPEED_MEDIUM:
			air_para->COD[1]|=0x20;
			break;

		case SPEED_HIGH:
			air_para->COD[1]|=0x30;
			break;

		default:
			break;
	}

	switch(air_status->vTemper){

		case TEMPER_16:
			air_para->COD[2]=0x10;
			break;

		case TEMPER_17:
			air_para->COD[2]=0x11;
			break;

		case TEMPER_18:
			air_para->COD[2]=0x12;
			break;

		case TEMPER_19:
			air_para->COD[2]=0x13;
			break;

		case TEMPER_20:
			air_para->COD[2]=0x14;
			break;

		case TEMPER_21:
			air_para->COD[2]=0x15;
			break;

		case TEMPER_22:
			air_para->COD[2]=0x16;
			break;

		case TEMPER_23:
			air_para->COD[2]=0x17;
			break;

		case TEMPER_24:
			air_para->COD[2]=0x18;
			break;

		case TEMPER_25:
			air_para->COD[2]=0x19;
			break;

		case TEMPER_26:
			air_para->COD[2]=0x1a;
			break;

		case TEMPER_27:
			air_para->COD[2]=0x1b;
			break;

		case TEMPER_28:
			air_para->COD[2]=0x1c;
			break;

		case TEMPER_29:
			air_para->COD[2]=0x1d;
			break;

		case TEMPER_30:
			air_para->COD[2]=0x1e;
			break;

		default:
			break;
	}


	switch(air_status->vKey){

		case POWER_KEY:
			air_para->COD[1]|=0x80;
			break;

		default:
			break;
	}

	air_para->COD[0]=0xc0;
	air_para->COD[3]=~((air_para->COD[0])+(air_para->COD[1])+(air_para->COD[2]));

}



void AirRemote126(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xf7;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x7a;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xd4;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xb7;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0xe4;


	air_para->BIC0=96;

	switch(air_status->vKey){

		case POWER_KEY:
			air_para->COD[0]|=0x00;
			break;

		case MODE_KEY:
			air_para->COD[0]|=0x01;
			break;

		case SPEED_KEY:
			air_para->COD[0]|=0x05;
			break;

		case TEMPER_INC_KEY:
			air_para->COD[0]|=0x03;
			break;

		case TEMPER_DEC_KEY:
			air_para->COD[0]|=0x04;
			break;

		case WIND_MANUAL_KEY:
			air_para->COD[0]|=0x0d;
			break;

		case WIND_AUTO_KEY:
			air_para->COD[0]|=0x0c;
			break;

		default:
			break;
	}

	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[0]|=0x00;
			break;

		case MODE_COLD:
			air_para->COD[0]|=0x10;
			break;

		case MODE_WET:
			air_para->COD[0]|=0x20;
			break;

		case MODE_WIND:
			air_para->COD[0]|=0x40;
			break;

		case MODE_HOT:
			air_para->COD[0]|=0x80;
			break;

		default:
			break;
	}

	switch(air_status->vSpeed){

		case SPEED_AUTO:
			air_para->COD[9]|=0x00;
			break;

		case SPEED_LOW:
			air_para->COD[9]|=0x01;
			break;

		case SPEED_MEDIUM:
			air_para->COD[9]|=0x02;
			break;

		case SPEED_HIGH:
			air_para->COD[9]|=0x03;
			break;

		default:
			break;
	}

	switch(air_status->vTemper){

		case TEMPER_16:
			air_para->COD[8]=0x18;
			break;

		case TEMPER_17:
			air_para->COD[8]=0x18;
			break;

		case TEMPER_18:
			air_para->COD[8]=0x18;
			break;

		case TEMPER_19:
			air_para->COD[8]=0x19;
			break;

		case TEMPER_20:
			air_para->COD[8]=0x20;
			break;

		case TEMPER_21:
			air_para->COD[8]=0x21;
			break;

		case TEMPER_22:
			air_para->COD[8]=0x22;
			break;

		case TEMPER_23:
			air_para->COD[8]=0x23;
			break;

		case TEMPER_24:
			air_para->COD[8]=0x24;
			break;

		case TEMPER_25:
			air_para->COD[8]=0x25;
			break;

		case TEMPER_26:
			air_para->COD[8]=0x26;
			break;

		case TEMPER_27:
			air_para->COD[8]=0x27;
			break;

		case TEMPER_28:
			air_para->COD[8]=0x28;
			break;

		case TEMPER_29:
			air_para->COD[8]=0x29;
			break;

		case TEMPER_30:
			air_para->COD[8]=0x30;
			break;

		default:
			break;
	}

	switch(air_status->vWind){

		case WIND_AUTO:
			air_para->COD[9]|=0x40;
			break;

		case WIND_MANUAL:
			air_para->COD[9]|=0x00;
			break;

		default:
			break;
	}


	air_para->COD[1]=0x12;
	air_para->COD[2]=0x00;
	air_para->COD[3]=0x00;
	air_para->COD[4]=0x00;
	air_para->COD[5]=0x00;
	air_para->COD[6]=0x00;
	air_para->COD[7]=0x00;

	air_para->COD[10]=0x00;
	air_para->COD[11]=0x19;

}


void AirRemote127(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x02;


	air_para->LDH_h=0x05;
	air_para->LDH_l=0x52;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x40;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xb4;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0x99;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0xfd;

	air_para->STO_h=0x06;
	air_para->STO_l=0x62;


	air_para->BIC0=48;
	air_para->BIC1=48;


	switch(air_status->vSpeed){

		case SPEED_AUTO:
			air_para->COD[2]=0xfd;
			break;

		case SPEED_LOW:
			air_para->COD[2]=0xf9;
			break;

		case SPEED_MEDIUM:
			air_para->COD[2]=0xfa;
			break;

		case SPEED_HIGH:
			air_para->COD[2]=0xfc;
			break;

		default:
			break;
	}

	switch(air_status->vTemper){

		case TEMPER_16:
			air_para->COD[4]|=0x00;
			break;

		case TEMPER_17:
			air_para->COD[4]|=0x00;
			break;

		case TEMPER_18:
			air_para->COD[4]|=0x08;
			break;

		case TEMPER_19:
			air_para->COD[4]|=0x0c;
			break;

		case TEMPER_20:
			air_para->COD[4]|=0x04;
			break;

		case TEMPER_21:
			air_para->COD[4]|=0x06;
			break;

		case TEMPER_22:
			air_para->COD[4]|=0x0e;
			break;

		case TEMPER_23:
			air_para->COD[4]|=0x0a;
			break;

		case TEMPER_24:
			air_para->COD[4]|=0x02;
			break;

		case TEMPER_25:
			air_para->COD[4]|=0x03;
			break;

		case TEMPER_26:
			air_para->COD[4]|=0x0b;
			break;

		case TEMPER_27:
			air_para->COD[4]|=0x09;
			break;

		case TEMPER_28:
			air_para->COD[4]|=0x01;
			break;

		case TEMPER_29:
			air_para->COD[4]|=0x05;
			break;

		case TEMPER_30:
			air_para->COD[4]|=0x0d;
			break;

		default:
			break;
	}


	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[2]=0xf8;
			air_para->COD[4]|=0x10;
			break;

		case MODE_COLD:
			air_para->COD[4]|=0x00;
			break;

		case MODE_WET:
			air_para->COD[2]=0xf8;
			air_para->COD[4]|=0x20;
			break;

		case MODE_WIND:
			air_para->COD[4]=0x27;
			break;

		case MODE_HOT:
			air_para->COD[4]|=0x30;
			break;

		default:
			break;
	}


	switch(air_status->vKey){

		case POWER_KEY:

			switch(air_status->vPower){

				case POWER_OFF:
					air_para->COD[2]=0xde;
					air_para->COD[4]=0x07;
					break;

				case POWER_ON:
					break;

				default:
					break;
			}
			break;

		case WIND_MANUAL_KEY:
			air_para->COD[2]=0xf0;
			air_para->COD[4]=0x07;
			break;

		case WIND_AUTO_KEY:
			air_para->COD[2]=0xd6;
			air_para->COD[4]=0x07;
			break;

		default:
			break;
	}


	air_para->COD[0]=0x4d;
	air_para->COD[1]=~(air_para->COD[0]);
	air_para->COD[3]=~(air_para->COD[2]);
	air_para->COD[5]=~(air_para->COD[4]);

	air_para->COD[6]=air_para->COD[0];
	air_para->COD[7]=air_para->COD[1];
	air_para->COD[8]=air_para->COD[2];
	air_para->COD[9]=air_para->COD[3];
	air_para->COD[10]=air_para->COD[4];
	air_para->COD[11]=air_para->COD[5];

}



void AirRemote128(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x04;
	air_para->LDH_l=0x20;

	air_para->LDL_h=0x02;
	air_para->LDL_l=0x2a;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0x7f;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0x95;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0x91;


	air_para->BIC0=112;

	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[5]=0x20;
		break;

	case POWER_ON:
		air_para->COD[5]=0x24;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[6]|=0x08;
		break;

	case MODE_COLD:
		air_para->COD[6]|=0x03;
		break;

	case MODE_WET:
		air_para->COD[6]|=0x02;
		break;

	case MODE_WIND:
		air_para->COD[6]|=0x07;
		break;

	case MODE_HOT:
		air_para->COD[6]|=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[8]|=0x00;
		break;

	case SPEED_LOW:
		air_para->COD[8]|=0x02;
		break;

	case SPEED_MEDIUM:
		air_para->COD[8]|=0x03;
		break;

	case SPEED_HIGH:
		air_para->COD[8]|=0x05;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[7]=0x0f;
		break;

	case TEMPER_17:
		air_para->COD[7]=0x0e;
		break;

	case TEMPER_18:
		air_para->COD[7]=0x0d;
		break;

	case TEMPER_19:
		air_para->COD[7]=0x0c;
		break;

	case TEMPER_20:
		air_para->COD[7]=0x0b;
		break;

	case TEMPER_21:
		air_para->COD[7]=0x0a;
		break;

	case TEMPER_22:
		air_para->COD[7]=0x09;
		break;

	case TEMPER_23:
		air_para->COD[7]=0x08;
		break;

	case TEMPER_24:
		air_para->COD[7]=0x07;
		break;

	case TEMPER_25:
		air_para->COD[7]=0x06;
		break;

	case TEMPER_26:
		air_para->COD[7]=0x05;
		break;

	case TEMPER_27:
		air_para->COD[7]=0x04;
		break;

	case TEMPER_28:
		air_para->COD[7]=0x03;
		break;

	case TEMPER_29:
		air_para->COD[7]=0x02;
		break;

	case TEMPER_30:
		air_para->COD[7]=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[8]|=0x38;
		break;

	case WIND_MANUAL:

		switch(air_status->vManualWind){
		case MANUAL_WIND_1:
			air_para->COD[8]|=0x00;
			break;
		case MANUAL_WIND_2:
			air_para->COD[8]|=0x10;
			break;
		case MANUAL_WIND_3:
			air_para->COD[8]|=0x20;
			break;
		case MANUAL_WIND_4:
			air_para->COD[8]|=0x28;
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}

	air_para->COD[0]=0x23;
	air_para->COD[1]=0xcb;
	air_para->COD[2]=0x26;
	air_para->COD[3]=0x01;
	air_para->COD[4]=0x00;

	air_para->COD[9]=0x00;
	air_para->COD[10]=0x00;
	air_para->COD[11]=0x00;
	air_para->COD[12]=0x00;

	air_para->COD[13]=(air_para->COD[0]+air_para->COD[1]+air_para->COD[2]+air_para->COD[3]+air_para->COD[4]+air_para->COD[5]+air_para->COD[6]+air_para->COD[7]+air_para->COD[8]+air_para->COD[9]+air_para->COD[10]+air_para->COD[11]+air_para->COD[12]);

}



void AirRemote186(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;

	air_para->LDH_h=0x0a;
	air_para->LDH_l=0x3b;

	air_para->LDL_h=0x04;
	air_para->LDL_l=0xbc;

	air_para->HIG_h=0x01;
	air_para->HIG_l=0x15;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0x70;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0xbe;


	air_para->BIC0=40;


	switch(air_status->vKey){

		case POWER_KEY:
			air_para->COD[0]|=0x03;
			break;

		case MODE_KEY:
			air_para->COD[0]|=0x0c;
			break;

		case SPEED_KEY:
			air_para->COD[0]|=0x0c;
			break;

		case TEMPER_INC_KEY:
			air_para->COD[0]|=0x0c;
			break;

		case TEMPER_DEC_KEY:
			air_para->COD[0]|=0x0c;
			break;

		case WIND_MANUAL_KEY:
			air_para->COD[0]|=0x0c;
			break;

		case WIND_AUTO_KEY:
			air_para->COD[0]|=0x0c;
			break;

		default:
			break;
	}


	switch(air_status->vPower){

		case POWER_OFF:
			air_para->COD[0]|=0x00;
			break;

		case POWER_ON:
			air_para->COD[0]|=0x80;
			break;

		default:
			break;
	}

	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[0]|=0x40;
			break;

		case MODE_COLD:
			air_para->COD[0]|=0x00;
			break;

		case MODE_WET:
			air_para->COD[0]|=0x10;
			break;

		case MODE_WIND:
			air_para->COD[0]|=0x20;
			break;

		case MODE_HOT:
			air_para->COD[0]|=0x30;
			break;

		default:
			break;
	}

	switch(air_status->vSpeed){

		case SPEED_AUTO:
			air_para->COD[1]|=0x00;
			break;

		case SPEED_LOW:
			air_para->COD[1]|=0x30;
			break;

		case SPEED_MEDIUM:
			air_para->COD[1]|=0x20;
			break;

		case SPEED_HIGH:
			air_para->COD[1]|=0x10;
			break;

		default:
			break;
	}

	switch(air_status->vTemper){

		case TEMPER_16:
			air_para->COD[1]|=0x00;
			break;

		case TEMPER_17:
			air_para->COD[1]|=0x01;
			break;

		case TEMPER_18:
			air_para->COD[1]|=0x02;
			break;

		case TEMPER_19:
			air_para->COD[1]|=0x03;
			break;

		case TEMPER_20:
			air_para->COD[1]|=0x04;
			break;

		case TEMPER_21:
			air_para->COD[1]|=0x05;
			break;

		case TEMPER_22:
			air_para->COD[1]|=0x06;
			break;

		case TEMPER_23:
			air_para->COD[1]|=0x07;
			break;

		case TEMPER_24:
			air_para->COD[1]|=0x08;
			break;

		case TEMPER_25:
			air_para->COD[1]|=0x09;
			break;

		case TEMPER_26:
			air_para->COD[1]|=0x0a;
			break;

		case TEMPER_27:
			air_para->COD[1]|=0x0b;
			break;

		case TEMPER_28:
			air_para->COD[1]|=0x0c;
			break;

		case TEMPER_29:
			air_para->COD[1]|=0x0d;
			break;

		case TEMPER_30:
			air_para->COD[1]|=0x0e;
			break;

		default:
			break;
	}

	switch(air_status->vWind){

		case WIND_AUTO:
			air_para->COD[2]|=0x8c;
			break;

		case WIND_MANUAL:

			switch(air_status->vManualWind){
				case MANUAL_WIND_1:
					air_para->COD[2]|=0x0c;
					break;
				case MANUAL_WIND_2:
					air_para->COD[2]|=0x0c;
					break;
				case MANUAL_WIND_3:
					air_para->COD[2]|=0x0c;
					break;
				case MANUAL_WIND_4:
					air_para->COD[2]|=0x0c;
					break;
				default:
					break;
			}
			break;

		default:
			break;
	}


	air_para->COD[3]=0x00;
	air_para->COD[4]=0xaa;

}



void AirRemote201(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0b;
	air_para->LDH_l=0x08;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0xc8;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xbb;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xaf;

	air_para->ONE_h=0x02;
	air_para->ONE_l=0x29;


	air_para->BIC0=88;

	switch(air_status->vKey){

		case POWER_KEY:
			air_para->COD[0]=0x03;
			break;

		case MODE_KEY:
			air_para->COD[0]=0x0c;
			break;

		case SPEED_KEY:
			air_para->COD[0]=0x0c;
			break;

		case TEMPER_INC_KEY:
			air_para->COD[0]=0x0c;
			break;

		case TEMPER_DEC_KEY:
			air_para->COD[0]=0x0c;
			break;

		case WIND_MANUAL_KEY:
			air_para->COD[0]=0x0c;
			break;

		case WIND_AUTO_KEY:
			air_para->COD[0]=0x0c;
			break;

		default:
			break;
	}

	switch(air_status->vPower){

		case POWER_OFF:
			air_para->COD[0]|=0x00;
			break;

		case POWER_ON:
			air_para->COD[0]|=0x80;
			break;

		default:
			break;
	}

	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[0]|=0x40;
			break;

		case MODE_COLD:
			air_para->COD[0]|=0x00;
			break;

		case MODE_WET:
			air_para->COD[0]|=0x20;
			break;

		case MODE_WIND:
			air_para->COD[0]|=0x50;
			break;

		case MODE_HOT:
			air_para->COD[0]|=0x10;
			break;

		default:
			break;
	}

	switch(air_status->vSpeed){

		case SPEED_AUTO:
			air_para->COD[1]|=0x00;
			break;

		case SPEED_LOW:
			air_para->COD[1]|=0x10;
			break;

		case SPEED_MEDIUM:
			air_para->COD[1]|=0x20;
			break;

		case SPEED_HIGH:
			air_para->COD[1]|=0x30;
			break;

		default:
			break;
	}

	switch(air_status->vTemper){

		case TEMPER_16:
			air_para->COD[1]|=0x00;
			break;

		case TEMPER_17:
			air_para->COD[1]|=0x01;
			break;

		case TEMPER_18:
			air_para->COD[1]|=0x02;
			break;

		case TEMPER_19:
			air_para->COD[1]|=0x03;
			break;

		case TEMPER_20:
			air_para->COD[1]|=0x04;
			break;

		case TEMPER_21:
			air_para->COD[1]|=0x05;
			break;

		case TEMPER_22:
			air_para->COD[1]|=0x06;
			break;

		case TEMPER_23:
			air_para->COD[1]|=0x07;
			break;

		case TEMPER_24:
			air_para->COD[1]|=0x08;
			break;

		case TEMPER_25:
			air_para->COD[1]|=0x09;
			break;

		case TEMPER_26:
			air_para->COD[1]|=0x0a;
			break;

		case TEMPER_27:
			air_para->COD[1]|=0x0b;
			break;

		case TEMPER_28:
			air_para->COD[1]|=0x0c;
			break;

		case TEMPER_29:
			air_para->COD[1]|=0x0d;
			break;

		case TEMPER_30:
			air_para->COD[1]|=0x0e;
			break;

		default:
			break;
	}

	switch(air_status->vWind){

		case WIND_AUTO:
			air_para->COD[2]=0x02;
			break;

		case WIND_MANUAL:
			air_para->COD[2]=0x00;
			break;

		default:
			break;
	}


	air_para->COD[3]=0x00;
	air_para->COD[4]=0x20;
	air_para->COD[5]=0x00;
	air_para->COD[6]=0x00;
	air_para->COD[7]=0x12;
	air_para->COD[8]=0x00;
	air_para->COD[9]=0x12;
	air_para->COD[10]=0xaa;

}


void AirRemote208(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xbe;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x4d;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xb2;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xa6;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0xd5;


	air_para->BIC0=40;


	switch(air_status->vKey){

		case POWER_KEY:
			switch(air_status->vPower){

				case POWER_OFF:
					air_para->COD[0]|=0x0b;
					break;

				case POWER_ON:
					air_para->COD[0]|=0x03;
					break;

				default:
					break;
			}
			break;

		case MODE_KEY:
			air_para->COD[0]|=0x0c;
			break;

		case SPEED_KEY:
			air_para->COD[0]|=0x0c;
			break;

		case TEMPER_INC_KEY:
			air_para->COD[0]|=0x0c;
			break;

		case TEMPER_DEC_KEY:
			air_para->COD[0]|=0x0c;
			break;

		case WIND_MANUAL_KEY:
			air_para->COD[0]|=0x0c;
			break;

		case WIND_AUTO_KEY:
			air_para->COD[0]|=0x0c;
			break;

		default:
			break;
	}


	switch(air_status->vPower){

		case POWER_OFF:
			air_para->COD[0]|=0x00;
			break;

		case POWER_ON:
			air_para->COD[0]|=0x80;
			break;

		default:
			break;
	}

	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[0]|=0x40;
			break;

		case MODE_COLD:
			air_para->COD[0]|=0x00;
			break;

		case MODE_WET:
			air_para->COD[0]|=0x20;
			break;

		case MODE_WIND:
			air_para->COD[0]|=0x30;
			break;

		case MODE_HOT:
			air_para->COD[0]|=0x10;
			break;

		default:
			break;
	}

	switch(air_status->vSpeed){

		case SPEED_AUTO:
			air_para->COD[1]|=0x30;
			break;

		case SPEED_LOW:
			air_para->COD[1]|=0x20;
			break;

		case SPEED_MEDIUM:
			air_para->COD[1]|=0x30;
			break;

		case SPEED_HIGH:
			air_para->COD[1]|=0x40;
			break;

		default:
			break;
	}

	switch(air_status->vTemper){

		case TEMPER_16:
			air_para->COD[1]|=0x00;
			break;

		case TEMPER_17:
			air_para->COD[1]|=0x01;
			break;

		case TEMPER_18:
			air_para->COD[1]|=0x02;
			break;

		case TEMPER_19:
			air_para->COD[1]|=0x03;
			break;

		case TEMPER_20:
			air_para->COD[1]|=0x04;
			break;

		case TEMPER_21:
			air_para->COD[1]|=0x05;
			break;

		case TEMPER_22:
			air_para->COD[1]|=0x06;
			break;

		case TEMPER_23:
			air_para->COD[1]|=0x07;
			break;

		case TEMPER_24:
			air_para->COD[1]|=0x08;
			break;

		case TEMPER_25:
			air_para->COD[1]|=0x09;
			break;

		case TEMPER_26:
			air_para->COD[1]|=0x0a;
			break;

		case TEMPER_27:
			air_para->COD[1]|=0x0b;
			break;

		case TEMPER_28:
			air_para->COD[1]|=0x0c;
			break;

		case TEMPER_29:
			air_para->COD[1]|=0x0d;
			break;

		case TEMPER_30:
			air_para->COD[1]|=0x0e;
			break;

		default:
			break;
	}


	air_para->COD[2]=0x04;
	air_para->COD[3]=0x10;
	air_para->COD[4]=0xdd;

}



void AirRemote209(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xf6;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x4f;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xc2;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xad;

	air_para->ONE_h=0x02;
	air_para->ONE_l=0x1c;


	air_para->BIC0=52;


	switch(air_status->vPower){

		case POWER_OFF:
			air_para->COD[0]|=0x00;
			break;

		case POWER_ON:
			air_para->COD[0]|=0x08;
			break;

		default:
			break;
	}

	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[0]|=0x04;
			break;

		case MODE_COLD:
			air_para->COD[0]|=0x00;
			break;

		case MODE_WET:
			air_para->COD[0]|=0x01;
			break;

		case MODE_WIND:
			air_para->COD[0]|=0x02;
			break;

		case MODE_HOT:
			air_para->COD[0]|=0x03;
			break;

		default:
			break;
	}

	switch(air_status->vSpeed){

		case SPEED_AUTO:
			air_para->COD[0]|=0x00;
			break;

		case SPEED_LOW:
			air_para->COD[0]|=0x10;
			break;

		case SPEED_MEDIUM:
			air_para->COD[0]|=0x20;
			break;

		case SPEED_HIGH:
			air_para->COD[0]|=0x30;
			break;

		default:
			break;
	}

	switch(air_status->vTemper){

		case TEMPER_16:
			air_para->COD[5]=0x20;
			break;

		case TEMPER_17:
			air_para->COD[5]=0x21;
			break;

		case TEMPER_18:
			air_para->COD[5]=0x22;
			break;

		case TEMPER_19:
			air_para->COD[5]=0x23;
			break;

		case TEMPER_20:
			air_para->COD[5]=0x24;
			break;

		case TEMPER_21:
			air_para->COD[5]=0x25;
			break;

		case TEMPER_22:
			air_para->COD[5]=0x26;
			break;

		case TEMPER_23:
			air_para->COD[5]=0x27;
			break;

		case TEMPER_24:
			air_para->COD[5]=0x28;
			break;

		case TEMPER_25:
			air_para->COD[5]=0x29;
			break;

		case TEMPER_26:
			air_para->COD[5]=0x2a;
			break;

		case TEMPER_27:
			air_para->COD[5]=0x2b;
			break;

		case TEMPER_28:
			air_para->COD[5]=0x2c;
			break;

		case TEMPER_29:
			air_para->COD[5]=0x2d;
			break;

		case TEMPER_30:
			air_para->COD[5]=0x2e;
			break;

		default:
			break;
	}

	switch(air_status->vWind){

		case WIND_AUTO:
			air_para->COD[0]|=0x40;
			break;

		case WIND_MANUAL:

			switch(air_status->vManualWind){
				case MANUAL_WIND_1:
					air_para->COD[0]|=0x00;
					break;
				case MANUAL_WIND_2:
					air_para->COD[0]|=0x00;
					break;
				case MANUAL_WIND_3:
					air_para->COD[0]|=0x00;
					break;
				case MANUAL_WIND_4:
					air_para->COD[0]|=0x00;
					break;
				default:
					break;
			}
			break;

		default:
			break;
	}

	air_para->COD[1]=0x00;
	air_para->COD[2]=0x01;
	air_para->COD[3]=0x00;
	air_para->COD[4]=0x02;
	air_para->COD[6]=0x02;
}



void AirRemote210(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xf6;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x4c;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xcb;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xa2;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0xfd;


	air_para->BIC0=35;


	switch(air_status->vPower){

		case POWER_OFF:
			air_para->COD[0]|=0x00;
			break;

		case POWER_ON:
			air_para->COD[0]|=0x08;
			break;

		default:
			break;
	}

	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[0]|=0x00;
			break;

		case MODE_COLD:
			air_para->COD[0]|=0x01;
			break;

		case MODE_WET:
			air_para->COD[0]|=0x02;
			break;

		case MODE_WIND:
			air_para->COD[0]|=0x03;
			break;

		case MODE_HOT:
			air_para->COD[0]|=0x04;
			break;

		default:
			break;
	}

	switch(air_status->vSpeed){

		case SPEED_AUTO:
			air_para->COD[0]|=0x00;
			break;

		case SPEED_LOW:
			air_para->COD[0]|=0x10;
			break;

		case SPEED_MEDIUM:
			air_para->COD[0]|=0x20;
			break;

		case SPEED_HIGH:
			air_para->COD[0]|=0x30;
			break;

		default:
			break;
	}

	switch(air_status->vTemper){

		case TEMPER_16:
			air_para->COD[1]=0x00;
			break;

		case TEMPER_17:
			air_para->COD[1]=0x01;
			break;

		case TEMPER_18:
			air_para->COD[1]=0x02;
			break;

		case TEMPER_19:
			air_para->COD[1]=0x03;
			break;

		case TEMPER_20:
			air_para->COD[1]=0x04;
			break;

		case TEMPER_21:
			air_para->COD[1]=0x05;
			break;

		case TEMPER_22:
			air_para->COD[1]=0x06;
			break;

		case TEMPER_23:
			air_para->COD[1]=0x07;
			break;

		case TEMPER_24:
			air_para->COD[1]=0x08;
			break;

		case TEMPER_25:
			air_para->COD[1]=0x09;
			break;

		case TEMPER_26:
			air_para->COD[1]=0x0a;
			break;

		case TEMPER_27:
			air_para->COD[1]=0x0b;
			break;

		case TEMPER_28:
			air_para->COD[1]=0x0c;
			break;

		case TEMPER_29:
			air_para->COD[1]=0x0d;
			break;

		case TEMPER_30:
			air_para->COD[1]=0x0e;
			break;

		default:
			break;
	}


	switch(air_status->vKey){

		case WIND_MANUAL_KEY:
			air_para->COD[0]|=0x40;
			break;

		case WIND_AUTO_KEY:
			air_para->COD[0]|=0x80;
			break;

		default:
			break;
	}


	air_para->COD[2]=0x40;
	air_para->COD[3]=0x08;
	air_para->COD[4]=0x00;
}



void AirRemote217(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x01;


	air_para->LDH_h=0x07;
	air_para->LDH_l=0x2e;

	air_para->LDL_h=0x08;
	air_para->LDL_l=0xca;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xae;

	air_para->ZER_h=0x01;
	air_para->ZER_l=0xb5;

	air_para->ONE_h=0x04;
	air_para->ONE_l=0x14;

	air_para->STO_h=0x08;
	air_para->STO_l=0xca;


	air_para->BIC0=48;


	switch(air_status->vPower){

		case POWER_OFF:
			air_para->COD[3]|=0x00;
			break;

		case POWER_ON:
			air_para->COD[3]|=0x08;
			break;

		default:
			break;
	}

	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[3]|=0x00;
			break;

		case MODE_COLD:
			air_para->COD[3]|=0x02;
			break;

		case MODE_WET:
			air_para->COD[3]|=0x01;
			break;

		case MODE_WIND:
			air_para->COD[3]|=0x03;
			break;

		case MODE_HOT:
			air_para->COD[3]|=0x04;
			break;

		default:
			break;
	}

	switch(air_status->vSpeed){

		case SPEED_AUTO:
			air_para->COD[1]|=0x00;
			break;

		case SPEED_LOW:
			air_para->COD[1]|=0xc0;
			break;

		case SPEED_MEDIUM:
			air_para->COD[1]|=0x80;
			break;

		case SPEED_HIGH:
			air_para->COD[1]|=0x40;
			break;

		default:
			break;
	}

	switch(air_status->vTemper){

		case TEMPER_16:
			air_para->COD[3]|=0x10;
			break;

		case TEMPER_17:
			air_para->COD[3]|=0x10;
			break;

		case TEMPER_18:
			air_para->COD[3]|=0x10;
			break;

		case TEMPER_19:
			air_para->COD[3]|=0x20;
			break;

		case TEMPER_20:
			air_para->COD[3]|=0x30;
			break;

		case TEMPER_21:
			air_para->COD[3]|=0x40;
			break;

		case TEMPER_22:
			air_para->COD[3]|=0x50;
			break;

		case TEMPER_23:
			air_para->COD[3]|=0x60;
			break;

		case TEMPER_24:
			air_para->COD[3]|=0x70;
			break;

		case TEMPER_25:
			air_para->COD[3]|=0x80;
			break;

		case TEMPER_26:
			air_para->COD[3]|=0x90;
			break;

		case TEMPER_27:
			air_para->COD[3]|=0xa0;
			break;

		case TEMPER_28:
			air_para->COD[3]|=0xb0;
			break;

		case TEMPER_29:
			air_para->COD[3]|=0xc0;
			break;

		case TEMPER_30:
			air_para->COD[3]|=0xd0;
			break;

		default:
			break;
	}

	switch(air_status->vWind){

		case WIND_AUTO:
			air_para->COD[1]|=0x10;
			break;

		case WIND_MANUAL:
			air_para->COD[1]|=0x20;
			break;

		default:
			break;
	}

	air_para->COD[0]=~(air_para->COD[1]);
	air_para->COD[2]=~(air_para->COD[3]);
	air_para->COD[4]=0x1d;
	air_para->COD[5]=~(air_para->COD[4]);
}



void AirRemote230(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x04;
	air_para->LDH_l=0x40;

	air_para->LDL_h=0x01;
	air_para->LDL_l=0xf2;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0x91;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0x82;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0x80;


	air_para->BIC0=136;


	switch(air_status->vPower){

		case POWER_OFF:
			air_para->COD[8]=0x03;
			break;

		case POWER_ON:
			air_para->COD[8]=0x23;
			break;

		default:
			break;
	}

	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[5]|=0x00;
			break;

		case MODE_COLD:
			air_para->COD[5]|=0x80;
			break;

		case MODE_WET:
			air_para->COD[5]|=0xc0;
			break;

		case MODE_WIND:
			air_para->COD[5]|=0x00;
			break;

		case MODE_HOT:
			air_para->COD[5]|=0x40;
			break;

		default:
			break;
	}

	switch(air_status->vSpeed){

		case SPEED_AUTO:
			air_para->COD[5]|=0x00;
			break;

		case SPEED_LOW:
			air_para->COD[5]|=0x08;
			break;

		case SPEED_MEDIUM:
			air_para->COD[5]|=0x0c;
			break;

		case SPEED_HIGH:
			air_para->COD[5]|=0x04;
			break;

		default:
			break;
	}

	switch(air_status->vTemper){

		case TEMPER_16:
			air_para->COD[6]=0x18;
			break;

		case TEMPER_17:
			air_para->COD[6]=0x1a;
			break;

		case TEMPER_18:
			air_para->COD[6]=0x1c;
			break;

		case TEMPER_19:
			air_para->COD[6]=0x1e;
			break;

		case TEMPER_20:
			air_para->COD[6]=0x20;
			break;

		case TEMPER_21:
			air_para->COD[6]=0x22;
			break;

		case TEMPER_22:
			air_para->COD[6]=0x24;
			break;

		case TEMPER_23:
			air_para->COD[6]=0x26;
			break;

		case TEMPER_24:
			air_para->COD[6]=0x28;
			break;

		case TEMPER_25:
			air_para->COD[6]=0x2a;
			break;

		case TEMPER_26:
			air_para->COD[6]=0x2c;
			break;

		case TEMPER_27:
			air_para->COD[6]=0x2e;
			break;

		case TEMPER_28:
			air_para->COD[6]=0x30;
			break;

		case TEMPER_29:
			air_para->COD[6]=0x32;
			break;

		case TEMPER_30:
			air_para->COD[6]=0x34;
			break;

		default:
			break;
	}


	switch(air_status->vWind){

		case WIND_AUTO:
			air_para->COD[13]|=0x01;
			break;

		case WIND_MANUAL:

			switch(air_status->vManualWind){
				case MANUAL_WIND_1:
					air_para->COD[13]|=0x02;
					break;
				case MANUAL_WIND_2:
					air_para->COD[13]|=0x03;
					break;
				case MANUAL_WIND_3:
					air_para->COD[13]|=0x04;
					break;
				case MANUAL_WIND_4:
					air_para->COD[13]|=0x05;
					break;
				default:
					break;
			}
			break;

		default:
			break;
	}


	switch(air_status->vKey){

		case POWER_KEY:
			switch(air_status->vPower){

				case POWER_OFF:
					air_para->COD[5]|=0x01;
					break;

				case POWER_ON:
					air_para->COD[5]|=0x02;
					break;

				default:
					break;
			}

			break;

		case WIND_MANUAL_KEY:
			air_para->COD[13]|=0x08;
			break;

		case WIND_AUTO_KEY:
			air_para->COD[13]|=0x08;
			break;

		default:
			break;
	}


	air_para->COD[0]=0x40;
	air_para->COD[1]=0x00;
	air_para->COD[2]=0x14;
	air_para->COD[3]=0x80;
	air_para->COD[4]=0x43;

	air_para->COD[7]=0x40;

	air_para->COD[9]=0x00;
	air_para->COD[10]=0x68;
	air_para->COD[11]=0x00;
	air_para->COD[12]=0x00;

	air_para->COD[14]=0x00;
	air_para->COD[15]=0x00;

	air_para->COD[16]=((air_para->COD[0])>>4)+((air_para->COD[0])&0x0f)+
					  ((air_para->COD[1])>>4)+((air_para->COD[1])&0x0f)+
					  ((air_para->COD[2])>>4)+((air_para->COD[2])&0x0f)+
					  ((air_para->COD[3])>>4)+((air_para->COD[3])&0x0f)+
					  ((air_para->COD[4])>>4)+((air_para->COD[4])&0x0f)+
					  ((air_para->COD[5])>>4)+((air_para->COD[5])&0x0f)+
					  ((air_para->COD[6])>>4)+((air_para->COD[6])&0x0f)+
					  ((air_para->COD[7])>>4)+((air_para->COD[7])&0x0f)+
					  ((air_para->COD[8])>>4)+((air_para->COD[8])&0x0f)+
					  ((air_para->COD[9])>>4)+((air_para->COD[9])&0x0f)+
					  ((air_para->COD[10])>>4)+((air_para->COD[10])&0x0f)+
					  ((air_para->COD[11])>>4)+((air_para->COD[11])&0x0f)+
					  ((air_para->COD[12])>>4)+((air_para->COD[12])&0x0f)+
					  ((air_para->COD[13])>>4)+((air_para->COD[13])&0x0f)+
					  ((air_para->COD[14])>>4)+((air_para->COD[14])&0x0f)+
					  ((air_para->COD[15])>>4)+((air_para->COD[15])&0x0f)-8;
}


void AirRemote233(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x04;
	air_para->LDH_l=0x40;

	air_para->LDL_h=0x01;
	air_para->LDL_l=0xf2;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0x91;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0x82;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0x80;


	air_para->BIC0=136;


	switch(air_status->vPower){

		case POWER_OFF:
			air_para->COD[8]=0x03;
			break;

		case POWER_ON:
			air_para->COD[8]=0x23;
			break;

		default:
			break;
	}

	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[5]|=0x00;
			air_para->COD[7]|=0x77;
			break;

		case MODE_COLD:
			air_para->COD[5]|=0x80;
			air_para->COD[7]|=0x77;
			break;

		case MODE_WET:
			air_para->COD[5]|=0xc0;
			air_para->COD[7]|=0x77;
			break;

		case MODE_WIND:
			air_para->COD[5]|=0x00;
			air_para->COD[7]|=0x77;
			break;

		case MODE_HOT:
			air_para->COD[5]|=0x40;
			air_para->COD[7]|=0x42;
			break;

		default:
			break;
	}

	switch(air_status->vSpeed){

		case SPEED_AUTO:
			air_para->COD[5]|=0x00;
			break;

		case SPEED_LOW:
			air_para->COD[5]|=0x08;
			break;

		case SPEED_MEDIUM:
			air_para->COD[5]|=0x0c;
			break;

		case SPEED_HIGH:
			air_para->COD[5]|=0x04;
			break;

		default:
			break;
	}

	switch(air_status->vTemper){

		case TEMPER_16:
			air_para->COD[6]=0x18;
			break;

		case TEMPER_17:
			air_para->COD[6]=0x1a;
			break;

		case TEMPER_18:
			air_para->COD[6]=0x1c;
			break;

		case TEMPER_19:
			air_para->COD[6]=0x1e;
			break;

		case TEMPER_20:
			air_para->COD[6]=0x20;
			break;

		case TEMPER_21:
			air_para->COD[6]=0x22;
			break;

		case TEMPER_22:
			air_para->COD[6]=0x24;
			break;

		case TEMPER_23:
			air_para->COD[6]=0x26;
			break;

		case TEMPER_24:
			air_para->COD[6]=0x28;
			break;

		case TEMPER_25:
			air_para->COD[6]=0x2a;
			break;

		case TEMPER_26:
			air_para->COD[6]=0x2c;
			break;

		case TEMPER_27:
			air_para->COD[6]=0x2e;
			break;

		case TEMPER_28:
			air_para->COD[6]=0x30;
			break;

		case TEMPER_29:
			air_para->COD[6]=0x32;
			break;

		case TEMPER_30:
			air_para->COD[6]=0x34;
			break;

		default:
			break;
	}


	switch(air_status->vWind){

		case WIND_AUTO:
			air_para->COD[13]|=0x01;
			break;

		case WIND_MANUAL:
			air_para->COD[13]|=0x02;
			break;

		default:
			break;
	}


	switch(air_status->vKey){

		case POWER_KEY:
			switch(air_status->vPower){

				case POWER_OFF:
					air_para->COD[5]|=0x01;
					break;

				case POWER_ON:
					air_para->COD[5]|=0x02;
					break;

				default:
					break;
			}

			break;

		case WIND_MANUAL_KEY:
			air_para->COD[13]|=0x08;
			break;

		case WIND_AUTO_KEY:
			air_para->COD[13]|=0x08;
			break;

		default:
			break;
	}


	air_para->COD[0]=0x40;
	air_para->COD[1]=0x00;
	air_para->COD[2]=0x14;
	air_para->COD[3]=0x80;
	air_para->COD[4]=0x43;

	air_para->COD[9]=0x00;
	air_para->COD[10]=0x68;
	air_para->COD[11]=0x00;
	air_para->COD[12]=0x00;

	air_para->COD[14]=0x00;
	air_para->COD[15]=0x00;

	air_para->COD[16]=((air_para->COD[0])>>4)+((air_para->COD[0])&0x0f)+
					  ((air_para->COD[1])>>4)+((air_para->COD[1])&0x0f)+
					  ((air_para->COD[2])>>4)+((air_para->COD[2])&0x0f)+
					  ((air_para->COD[3])>>4)+((air_para->COD[3])&0x0f)+
					  ((air_para->COD[4])>>4)+((air_para->COD[4])&0x0f)+
					  ((air_para->COD[5])>>4)+((air_para->COD[5])&0x0f)+
					  ((air_para->COD[6])>>4)+((air_para->COD[6])&0x0f)+
					  ((air_para->COD[7])>>4)+((air_para->COD[7])&0x0f)+
					  ((air_para->COD[8])>>4)+((air_para->COD[8])&0x0f)+
					  ((air_para->COD[9])>>4)+((air_para->COD[9])&0x0f)+
					  ((air_para->COD[10])>>4)+((air_para->COD[10])&0x0f)+
					  ((air_para->COD[11])>>4)+((air_para->COD[11])&0x0f)+
					  ((air_para->COD[12])>>4)+((air_para->COD[12])&0x0f)+
					  ((air_para->COD[13])>>4)+((air_para->COD[13])&0x0f)+
					  ((air_para->COD[14])>>4)+((air_para->COD[14])&0x0f)+
					  ((air_para->COD[15])>>4)+((air_para->COD[15])&0x0f)-8;
}


void AirRemote237(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0x9c;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x2a;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xa0;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xab;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0xd7;


	air_para->BIC0=72;


	switch(air_status->vPower){

		case POWER_OFF:
			air_para->COD[5]|=0x40;
			break;

		case POWER_ON:
			air_para->COD[5]|=0x80;
			break;

		default:
			break;
	}

	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[4]|=0x20;
			air_para->COD[2]=0x5d;
			break;

		case MODE_COLD:
			air_para->COD[4]|=0x20;
			air_para->COD[2]=0x5d;
			break;

		case MODE_WET:
			air_para->COD[4]|=0x30;
			air_para->COD[2]=0x5d;
			break;

		case MODE_WIND:
			air_para->COD[4]|=0x00;
			air_para->COD[2]=0x5d;
			break;

		case MODE_HOT:
			air_para->COD[4]|=0x10;
			air_para->COD[2]=0x41;
			break;

		default:
			break;
	}

	switch(air_status->vSpeed){

		case SPEED_AUTO:
			air_para->COD[4]|=0x00;
			break;

		case SPEED_LOW:
			air_para->COD[4]|=0x02;
			break;

		case SPEED_MEDIUM:
			air_para->COD[4]|=0x03;
			break;

		case SPEED_HIGH:
			air_para->COD[4]|=0x01;
			break;

		default:
			break;
	}

	switch(air_status->vTemper){

		case TEMPER_16:
			air_para->COD[1]=0x6c;
			break;

		case TEMPER_17:
			air_para->COD[1]=0x6d;
			break;

		case TEMPER_18:
			air_para->COD[1]=0x6e;
			break;

		case TEMPER_19:
			air_para->COD[1]=0x6f;
			break;

		case TEMPER_20:
			air_para->COD[1]=0x70;
			break;

		case TEMPER_21:
			air_para->COD[1]=0x71;
			break;

		case TEMPER_22:
			air_para->COD[1]=0x72;
			break;

		case TEMPER_23:
			air_para->COD[1]=0x73;
			break;

		case TEMPER_24:
			air_para->COD[1]=0x74;
			break;

		case TEMPER_25:
			air_para->COD[1]=0x75;
			break;

		case TEMPER_26:
			air_para->COD[1]=0x76;
			break;

		case TEMPER_27:
			air_para->COD[1]=0x77;
			break;

		case TEMPER_28:
			air_para->COD[1]=0x78;
			break;

		case TEMPER_29:
			air_para->COD[1]=0x79;
			break;

		case TEMPER_30:
			air_para->COD[1]=0x7a;
			break;

		default:
			break;
	}


	switch(air_status->vWind){

		case WIND_AUTO:
			air_para->COD[5]|=0x08;
			break;

		case WIND_MANUAL:

			switch(air_status->vManualWind){
				case MANUAL_WIND_1:
					air_para->COD[5]|=0x0a;
					break;
				case MANUAL_WIND_2:
					air_para->COD[5]|=0x0b;
					break;
				case MANUAL_WIND_3:
					air_para->COD[5]|=0x0c;
					break;
				case MANUAL_WIND_4:
					air_para->COD[5]|=0x0d;
					break;
				default:
					break;
			}
			break;

		default:
			break;
	}


	air_para->COD[0]=0x6a;

	air_para->COD[3]=0x00;

	air_para->COD[6]=0x00;
	air_para->COD[7]=0x00;

	air_para->COD[8]=((air_para->COD[0])>>4)+((air_para->COD[0])&0x0f)+
					 ((air_para->COD[1])>>4)+((air_para->COD[1])&0x0f)+
					 ((air_para->COD[2])>>4)+((air_para->COD[2])&0x0f)+
					 ((air_para->COD[3])>>4)+((air_para->COD[3])&0x0f)+
					 ((air_para->COD[4])>>4)+((air_para->COD[4])&0x0f)+
					 ((air_para->COD[5])>>4)+((air_para->COD[5])&0x0f)+
					 ((air_para->COD[6])>>4)+((air_para->COD[6])&0x0f)+
					 ((air_para->COD[7])>>4)+((air_para->COD[7])&0x0f);
}


void AirRemote238(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0x9c;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x2a;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xa0;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xab;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0xd7;


	air_para->BIC0=72;


	switch(air_status->vPower){

		case POWER_OFF:
			air_para->COD[5]|=0x40;
			break;

		case POWER_ON:
			air_para->COD[5]|=0x80;
			break;

		default:
			break;
	}

	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[4]|=0x20;
			break;

		case MODE_COLD:
			air_para->COD[4]|=0x20;
			break;

		case MODE_WET:
			air_para->COD[4]|=0x30;
			break;

		case MODE_WIND:
			air_para->COD[4]|=0x00;
			break;

		case MODE_HOT:
			air_para->COD[4]|=0x10;
			break;

		default:
			break;
	}

	switch(air_status->vSpeed){

		case SPEED_AUTO:
			air_para->COD[4]|=0x00;
			break;

		case SPEED_LOW:
			air_para->COD[4]|=0x02;
			break;

		case SPEED_MEDIUM:
			air_para->COD[4]|=0x03;
			break;

		case SPEED_HIGH:
			air_para->COD[4]|=0x01;
			break;

		default:
			break;
	}

	switch(air_status->vTemper){

		case TEMPER_16:
			air_para->COD[1]=0x6c;
			break;

		case TEMPER_17:
			air_para->COD[1]=0x6d;
			break;

		case TEMPER_18:
			air_para->COD[1]=0x6e;
			break;

		case TEMPER_19:
			air_para->COD[1]=0x6f;
			break;

		case TEMPER_20:
			air_para->COD[1]=0x70;
			break;

		case TEMPER_21:
			air_para->COD[1]=0x71;
			break;

		case TEMPER_22:
			air_para->COD[1]=0x72;
			break;

		case TEMPER_23:
			air_para->COD[1]=0x73;
			break;

		case TEMPER_24:
			air_para->COD[1]=0x74;
			break;

		case TEMPER_25:
			air_para->COD[1]=0x75;
			break;

		case TEMPER_26:
			air_para->COD[1]=0x76;
			break;

		case TEMPER_27:
			air_para->COD[1]=0x77;
			break;

		case TEMPER_28:
			air_para->COD[1]=0x78;
			break;

		case TEMPER_29:
			air_para->COD[1]=0x79;
			break;

		case TEMPER_30:
			air_para->COD[1]=0x7a;
			break;

		default:
			break;
	}


	switch(air_status->vWind){

		case WIND_AUTO:
			air_para->COD[5]|=0x00;
			break;

		case WIND_MANUAL:

			switch(air_status->vManualWind){
				case MANUAL_WIND_1:
					air_para->COD[5]|=0x02;
					break;
				case MANUAL_WIND_2:
					air_para->COD[5]|=0x03;
					break;
				case MANUAL_WIND_3:
					air_para->COD[5]|=0x04;
					break;
				case MANUAL_WIND_4:
					air_para->COD[5]|=0x05;
					break;
				default:
					break;
			}
			break;

		default:
			break;
	}


	air_para->COD[0]=0x6a;

	air_para->COD[2]=0x73;

	air_para->COD[3]=0x00;

	air_para->COD[6]=0x00;
	air_para->COD[7]=0x00;

	air_para->COD[8]=((air_para->COD[0])>>4)+((air_para->COD[0])&0x0f)+
					 ((air_para->COD[1])>>4)+((air_para->COD[1])&0x0f)+
					 ((air_para->COD[2])>>4)+((air_para->COD[2])&0x0f)+
					 ((air_para->COD[3])>>4)+((air_para->COD[3])&0x0f)+
					 ((air_para->COD[4])>>4)+((air_para->COD[4])&0x0f)+
					 ((air_para->COD[5])>>4)+((air_para->COD[5])&0x0f)+
					 ((air_para->COD[6])>>4)+((air_para->COD[6])&0x0f)+
					 ((air_para->COD[7])>>4)+((air_para->COD[7])&0x0f);
}


void AirRemote281(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xf6;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x4c;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xcb;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xa2;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0xfd;


	air_para->BIC0=35;


	switch(air_status->vPower){

		case POWER_OFF:
			air_para->COD[0]|=0x00;
			break;

		case POWER_ON:
			air_para->COD[0]|=0x08;
			break;

		default:
			break;
	}

	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[0]|=0x00;
			break;

		case MODE_COLD:
			air_para->COD[0]|=0x01;
			break;

		case MODE_WET:
			air_para->COD[0]|=0x02;
			break;

		case MODE_WIND:
			air_para->COD[0]|=0x03;
			break;

		case MODE_HOT:
			air_para->COD[0]|=0x04;
			break;

		default:
			break;
	}

	switch(air_status->vSpeed){

		case SPEED_AUTO:
			air_para->COD[0]|=0x00;
			break;

		case SPEED_LOW:
			air_para->COD[0]|=0x10;
			break;

		case SPEED_MEDIUM:
			air_para->COD[0]|=0x20;
			break;

		case SPEED_HIGH:
			air_para->COD[0]|=0x30;
			break;

		default:
			break;
	}

	switch(air_status->vTemper){

		case TEMPER_16:
			air_para->COD[1]=0x00;
			break;

		case TEMPER_17:
			air_para->COD[1]=0x01;
			break;

		case TEMPER_18:
			air_para->COD[1]=0x02;
			break;

		case TEMPER_19:
			air_para->COD[1]=0x03;
			break;

		case TEMPER_20:
			air_para->COD[1]=0x04;
			break;

		case TEMPER_21:
			air_para->COD[1]=0x05;
			break;

		case TEMPER_22:
			air_para->COD[1]=0x06;
			break;

		case TEMPER_23:
			air_para->COD[1]=0x07;
			break;

		case TEMPER_24:
			air_para->COD[1]=0x08;
			break;

		case TEMPER_25:
			air_para->COD[1]=0x09;
			break;

		case TEMPER_26:
			air_para->COD[1]=0x0a;
			break;

		case TEMPER_27:
			air_para->COD[1]=0x0b;
			break;

		case TEMPER_28:
			air_para->COD[1]=0x0c;
			break;

		case TEMPER_29:
			air_para->COD[1]=0x0d;
			break;

		case TEMPER_30:
			air_para->COD[1]=0x0e;
			break;

		default:
			break;
	}


	switch(air_status->vKey){

		case WIND_MANUAL_KEY:
			air_para->COD[0]|=0x40;
			break;

		case WIND_AUTO_KEY:
			air_para->COD[0]|=0x80;
			break;

		default:
			break;
	}


	air_para->COD[2]=0x00;
	air_para->COD[3]=0x00;
	air_para->COD[4]=0x02;
}


void AirRemote282(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xf6;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x4c;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xc2;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xb8;

	air_para->ONE_h=0x03;
	air_para->ONE_l=0x0d;


	air_para->BIC0=52;


	switch(air_status->vPower){

		case POWER_OFF:
			air_para->COD[0]|=0x00;
			break;

		case POWER_ON:
			air_para->COD[0]|=0x08;
			break;

		default:
			break;
	}

	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[0]|=0x04;
			break;

		case MODE_COLD:
			air_para->COD[0]|=0x00;
			break;

		case MODE_WET:
			air_para->COD[0]|=0x01;
			break;

		case MODE_WIND:
			air_para->COD[0]|=0x02;
			break;

		case MODE_HOT:
			air_para->COD[0]|=0x03;
			break;

		default:
			break;
	}

	switch(air_status->vSpeed){

		case SPEED_AUTO:
			air_para->COD[0]|=0x00;
			break;

		case SPEED_LOW:
			air_para->COD[0]|=0x10;
			break;

		case SPEED_MEDIUM:
			air_para->COD[0]|=0x20;
			break;

		case SPEED_HIGH:
			air_para->COD[0]|=0x30;
			break;

		default:
			break;
	}

	switch(air_status->vTemper){

		case TEMPER_16:
			air_para->COD[5]=0x20;
			break;

		case TEMPER_17:
			air_para->COD[5]=0x21;
			break;

		case TEMPER_18:
			air_para->COD[5]=0x22;
			break;

		case TEMPER_19:
			air_para->COD[5]=0x23;
			break;

		case TEMPER_20:
			air_para->COD[5]=0x24;
			break;

		case TEMPER_21:
			air_para->COD[5]=0x25;
			break;

		case TEMPER_22:
			air_para->COD[5]=0x26;
			break;

		case TEMPER_23:
			air_para->COD[5]=0x27;
			break;

		case TEMPER_24:
			air_para->COD[5]=0x28;
			break;

		case TEMPER_25:
			air_para->COD[5]=0x29;
			break;

		case TEMPER_26:
			air_para->COD[5]=0x2a;
			break;

		case TEMPER_27:
			air_para->COD[5]=0x2b;
			break;

		case TEMPER_28:
			air_para->COD[5]=0x2c;
			break;

		case TEMPER_29:
			air_para->COD[5]=0x2d;
			break;

		case TEMPER_30:
			air_para->COD[5]=0x2e;
			break;

		default:
			break;
	}

	switch(air_status->vWind){

		case WIND_AUTO:
			air_para->COD[0]|=0x40;
			break;

		case WIND_MANUAL:

			switch(air_status->vManualWind){
				case MANUAL_WIND_1:
					air_para->COD[0]|=0x00;
					break;
				case MANUAL_WIND_2:
					air_para->COD[0]|=0x00;
					break;
				case MANUAL_WIND_3:
					air_para->COD[0]|=0x00;
					break;
				case MANUAL_WIND_4:
					air_para->COD[0]|=0x00;
					break;
				default:
					break;
			}
			break;

		default:
			break;
	}

	air_para->COD[1]=0x00;
	air_para->COD[2]=0x01;
	air_para->COD[3]=0x00;
	air_para->COD[4]=0x02;
	air_para->COD[6]=0x02;
}


void AirRemote417(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x02;


	air_para->LDH_h=0x05;
	air_para->LDH_l=0x75;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x5b;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xb3;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xa0;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0xf0;

	air_para->STO_h=0x06;
	air_para->STO_l=0xe2;

	air_para->BIC0=48;
	air_para->BIC1=48;


	air_para->COD[2] = 0xf8;
	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[2]|=0x05;
		break;

	case SPEED_LOW:
		air_para->COD[2]|=0x01;
		break;

	case SPEED_MEDIUM:
		air_para->COD[2]|=0x02;
		break;

	case SPEED_HIGH:
		air_para->COD[2]|=0x04;
		break;

	default:
		break;
	}
	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[4]=0x00;
		break;

	case TEMPER_17:
		air_para->COD[4]=0x00;
		break;

	case TEMPER_18:
		air_para->COD[4]=0x08;
		break;

	case TEMPER_19:
		air_para->COD[4]=0x0c;
		break;

	case TEMPER_20:
		air_para->COD[4]=0x04;
		break;

	case TEMPER_21:
		air_para->COD[4]=0x06;
		break;

	case TEMPER_22:
		air_para->COD[4]=0x0e;
		break;

	case TEMPER_23:
		air_para->COD[4]=0x0a;
		break;

	case TEMPER_24:
		air_para->COD[4]=0x02;
		break;

	case TEMPER_25:
		air_para->COD[4]=0x03;
		break;

	case TEMPER_26:
		air_para->COD[4]=0x0b;
		break;

	case TEMPER_27:
		air_para->COD[4]=0x09;
		break;

	case TEMPER_28:
		air_para->COD[4]=0x01;
		break;

	case TEMPER_29:
		air_para->COD[4]=0x05;
		break;

	case TEMPER_30:
		air_para->COD[4]=0x0d;
		break;

	default:
		break;
	}
	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[4]=0x11;
		air_para->COD[2]&=0xf8;
		break;

	case MODE_COLD:
		break;

	case MODE_WET:
		air_para->COD[4]|=0x20;
		air_para->COD[2]&=0xf8;
		break;

	case MODE_WIND:
		air_para->COD[4]=0x27;
		break;

	case MODE_HOT:
		air_para->COD[4]|=0x30;
		break;

	default:
		break;
	}
	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[2]=0xde;
		air_para->COD[4]=0x07;
		break;

	case POWER_ON:

		break;

	default:
		break;
	}

	if(air_status->vKey==WIND_MANUAL_KEY||air_status->vKey==WIND_AUTO_KEY){
	air_para->COD[4]=0x07;

	if(air_status->vWind==WIND_AUTO)
		air_para->COD[2]=0xd6;
	else
		{
		air_para->COD[2]=0xf0;
	 	air_para->STRU=0x00;
		}
	}

	air_para->COD[0]=0x4d;
	air_para->COD[1]=~air_para->COD[0];
	air_para->COD[3]=~air_para->COD[2];
	air_para->COD[5]=~air_para->COD[4];
	air_para->COD[6]=air_para->COD[0];
	air_para->COD[7]=air_para->COD[1];
	air_para->COD[8]=air_para->COD[2];
	air_para->COD[9]=air_para->COD[3];
	air_para->COD[10]=air_para->COD[4];
	air_para->COD[11]=air_para->COD[5];
}



void AirRemote439(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x01;


	air_para->LDH_h=0x04;
	air_para->LDH_l=0x33;

	air_para->LDL_h=0x02;
	air_para->LDL_l=0x45;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xa0;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0x8a;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0xb2;

	air_para->STO_h=0x09;
	air_para->STO_l=0xf2;

	air_para->BIC0=112;

	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[5]=0x20;
		break;

	case POWER_ON:
		air_para->COD[5]=0x24;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[6]=0x03;
		break;

	case MODE_COLD:
		air_para->COD[6]=0x03;
		break;

	case MODE_WET:
		air_para->COD[6]=0x02;
		break;

	case MODE_WIND:
		air_para->COD[6]=0x02;
		break;

	case MODE_HOT:
		air_para->COD[6]=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[8]=0x02;
		break;

	case SPEED_LOW:
		air_para->COD[8]=0x02;
		break;

	case SPEED_MEDIUM:
		air_para->COD[8]=0x06;
		break;

	case SPEED_HIGH:
		air_para->COD[8]=0x04;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[7]=0x0d;
		break;

	case TEMPER_17:
		air_para->COD[7]=0x0d;
		break;

	case TEMPER_18:
		air_para->COD[7]=0x0d;
		break;

	case TEMPER_19:
		air_para->COD[7]=0x0c;
		break;

	case TEMPER_20:
		air_para->COD[7]=0x0b;
		break;

	case TEMPER_21:
		air_para->COD[7]=0x0a;
		break;

	case TEMPER_22:
		air_para->COD[7]=0x09;
		break;

	case TEMPER_23:
		air_para->COD[7]=0x08;
		break;

	case TEMPER_24:
		air_para->COD[7]=0x07;
		break;

	case TEMPER_25:
		air_para->COD[7]=0x06;
		break;

	case TEMPER_26:
		air_para->COD[7]=0x05;
		break;

	case TEMPER_27:
		air_para->COD[7]=0x04;
		break;

	case TEMPER_28:
		air_para->COD[7]=0x03;
		break;

	case TEMPER_29:
		air_para->COD[7]=0x02;
		break;

	case TEMPER_30:
		air_para->COD[7]=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[8]|=0x18;
		break;

	case WIND_MANUAL:
		air_para->COD[8]|=0x10;

		break;

	default:
		break;
	}

	air_para->COD[0]=air_para->COD[1]=air_para->COD[2]=air_para->COD[3]=air_para->COD[4]=0x11;


	air_para->COD[13]=Sumarray(13,air_para);

}



void AirRemote481(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x01;


	air_para->LDH_h=0x04;
	air_para->LDH_l=0x33;

	air_para->LDL_h=0x02;
	air_para->LDL_l=0x45;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xa0;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0x8a;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0xb2;

	air_para->STO_h=0x09;
	air_para->STO_l=0xf2;

	air_para->BIC0=112;

	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[5]=0x20;
		break;

	case POWER_ON:
		air_para->COD[5]=0x24;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[6]=0x03;
		break;

	case MODE_COLD:
		air_para->COD[6]=0x03;
		break;

	case MODE_WET:
		air_para->COD[6]=0x02;
		break;

	case MODE_WIND:
		air_para->COD[6]=0x02;
		break;

	case MODE_HOT:
		air_para->COD[6]=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[8]=0x02;
		break;

	case SPEED_LOW:
		air_para->COD[8]=0x02;
		break;

	case SPEED_MEDIUM:
		air_para->COD[8]=0x04;
		break;

	case SPEED_HIGH:
		air_para->COD[8]=0x04;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[7]=0x0d;
		break;

	case TEMPER_17:
		air_para->COD[7]=0x0d;
		break;

	case TEMPER_18:
		air_para->COD[7]=0x0d;
		break;

	case TEMPER_19:
		air_para->COD[7]=0x0c;
		break;

	case TEMPER_20:
		air_para->COD[7]=0x0b;
		break;

	case TEMPER_21:
		air_para->COD[7]=0x0a;
		break;

	case TEMPER_22:
		air_para->COD[7]=0x09;
		break;

	case TEMPER_23:
		air_para->COD[7]=0x08;
		break;

	case TEMPER_24:
		air_para->COD[7]=0x07;
		break;

	case TEMPER_25:
		air_para->COD[7]=0x06;
		break;

	case TEMPER_26:
		air_para->COD[7]=0x05;
		break;

	case TEMPER_27:
		air_para->COD[7]=0x04;
		break;

	case TEMPER_28:
		air_para->COD[7]=0x03;
		break;

	case TEMPER_29:
		air_para->COD[7]=0x02;
		break;

	case TEMPER_30:
		air_para->COD[7]=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[8]|=0x18;
		break;

	case WIND_MANUAL:
		air_para->COD[8]|=0x10;

		break;

	default:
		break;
	}

	air_para->COD[0]=air_para->COD[1]=air_para->COD[2]=air_para->COD[3]=air_para->COD[4]=0x11;


	air_para->COD[13]=Sumarray(13,air_para);

}


void AirRemote482(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x01;


	air_para->LDH_h=0x04;
	air_para->LDH_l=0x33;

	air_para->LDL_h=0x02;
	air_para->LDL_l=0x45;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xa0;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0x8a;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0xb2;

	air_para->STO_h=0x09;
	air_para->STO_l=0xf2;

	air_para->BIC0=112;

	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[5]=0x20;
		break;

	case POWER_ON:
		air_para->COD[5]=0x24;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[6]=0x03;
		break;

	case MODE_COLD:
		air_para->COD[6]=0x03;
		break;

	case MODE_WET:
		air_para->COD[6]=0x02;
		break;

	case MODE_WIND:
		air_para->COD[6]=0x02;
		break;

	case MODE_HOT:
		air_para->COD[6]=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[8]=0x00;
		break;

	case SPEED_LOW:
		air_para->COD[8]=0x02;
		break;

	case SPEED_MEDIUM:
		air_para->COD[8]=0x06;
		break;

	case SPEED_HIGH:
		air_para->COD[8]=0x04;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[7]=0x0d;
		break;

	case TEMPER_17:
		air_para->COD[7]=0x0d;
		break;

	case TEMPER_18:
		air_para->COD[7]=0x0d;
		break;

	case TEMPER_19:
		air_para->COD[7]=0x0c;
		break;

	case TEMPER_20:
		air_para->COD[7]=0x0b;
		break;

	case TEMPER_21:
		air_para->COD[7]=0x0a;
		break;

	case TEMPER_22:
		air_para->COD[7]=0x09;
		break;

	case TEMPER_23:
		air_para->COD[7]=0x08;
		break;

	case TEMPER_24:
		air_para->COD[7]=0x07;
		break;

	case TEMPER_25:
		air_para->COD[7]=0x06;
		break;

	case TEMPER_26:
		air_para->COD[7]=0x05;
		break;

	case TEMPER_27:
		air_para->COD[7]=0x04;
		break;

	case TEMPER_28:
		air_para->COD[7]=0x03;
		break;

	case TEMPER_29:
		air_para->COD[7]=0x02;
		break;

	case TEMPER_30:
		air_para->COD[7]=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[8]|=0x18;
		break;

	case WIND_MANUAL:
		switch(air_status->vManualWind){
		case MANUAL_WIND_1:
			break;
		case MANUAL_WIND_2:
			air_para->COD[8]|=0x10;
			break;
		case MANUAL_WIND_3:
			air_para->COD[8]|=0x20;
			break;
		case MANUAL_WIND_4:
			air_para->COD[8]|=0x28;
			break;
		default:
			break;
		}

		break;

	default:
		break;
	}

	air_para->COD[0]=air_para->COD[1]=air_para->COD[2]=air_para->COD[3]=air_para->COD[4]=0x11;


	air_para->COD[13]=Sumarray(13,air_para);

}


void AirRemote495(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x04;
	air_para->LDH_l=0x27;

	air_para->LDL_h=0x02;
	air_para->LDL_l=0x1c;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0x87;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0x8b;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0x86;


	air_para->BIC0=112;

	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[5]=0x20;
		break;

	case POWER_ON:
		air_para->COD[5]=0x24;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[6]=0x08;
		break;

	case MODE_COLD:
		air_para->COD[6]=0x03;
		break;

	case MODE_WET:
		air_para->COD[6]=0x02;
		break;

	case MODE_WIND:
		air_para->COD[6]=0x07;
		break;

	case MODE_HOT:
		air_para->COD[6]=0x01;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[8]=0x00;
		break;

	case SPEED_LOW:
		air_para->COD[8]=0x02;
		break;

	case SPEED_MEDIUM:
		air_para->COD[8]=0x03;
		break;

	case SPEED_HIGH:
		air_para->COD[8]=0x05;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[7]=0x0f;
		break;

	case TEMPER_17:
		air_para->COD[7]=0x0e;
		break;

	case TEMPER_18:
		air_para->COD[7]=0x0d;
		break;

	case TEMPER_19:
		air_para->COD[7]=0x0c;
		break;

	case TEMPER_20:
		air_para->COD[7]=0x0b;
		break;

	case TEMPER_21:
		air_para->COD[7]=0x0a;
		break;

	case TEMPER_22:
		air_para->COD[7]=0x09;
		break;

	case TEMPER_23:
		air_para->COD[7]=0x08;
		break;

	case TEMPER_24:
		air_para->COD[7]=0x07;
		break;

	case TEMPER_25:
		air_para->COD[7]=0x06;
		break;

	case TEMPER_26:
		air_para->COD[7]=0x05;
		break;

	case TEMPER_27:
		air_para->COD[7]=0x04;
		break;

	case TEMPER_28:
		air_para->COD[7]=0x03;
		break;

	case TEMPER_29:
		air_para->COD[7]=0x02;
		break;

	case TEMPER_30:
		air_para->COD[7]=0x01;
		break;

	default:
		break;
	}
	air_para->COD[7]|=0x80;

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[8]|=0x38;
		break;

	case WIND_MANUAL:

		switch(air_status->vManualWind){
		case MANUAL_WIND_1:
			air_para->COD[8]|=0x08;
			break;
		case MANUAL_WIND_2:
			air_para->COD[8]|=0x10;
			break;
		case MANUAL_WIND_3:
			air_para->COD[8]|=0x20;
			break;
		case MANUAL_WIND_4:
			air_para->COD[8]|=0x28;
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}

	air_para->COD[0]=0x23;
	air_para->COD[1]=0xcb;
	air_para->COD[2]=0x26;
	air_para->COD[3]=0x01;

	air_para->COD[13]=Sumarray(13,air_para);

}







char HandleAirRemote(AIR_status air_status , char *vAirBuffer){

	char i;

	Air_para *air_para;

	if((air_para=malloc(82))==NULL)return 0xff;

	memset(air_para, 0, 82);

	switch(air_status.nAirCode){


	case 5000:
		AirRemote000(&air_status,air_para);
		break;

	case 5001:
		AirRemote001(&air_status,air_para);
		break;

	case 5002:
		AirRemote002(&air_status,air_para);
		break;

	case 5003:
		AirRemote003(&air_status,air_para);
		break;

	case 5005:
		AirRemote005(&air_status,air_para);
		break;

	case 5006:
		AirRemote006(&air_status,air_para);
		break;

	case 5008:
		AirRemote008(&air_status,air_para);
		break;

	case 5010:
		AirRemote010(&air_status,air_para);
		break;

	case 5011:
		AirRemote011(&air_status,air_para);
		break;

	case 5012:
		AirRemote012(&air_status,air_para);
		break;

	case 5013:
		AirRemote013(&air_status,air_para);
		break;

	case 5014:
		AirRemote014(&air_status,air_para);
		break;

	case 5015:
		AirRemote015(&air_status,air_para);
		break;

	case 5016:
		AirRemote016(&air_status,air_para);
		break;

	case 5017:
		AirRemote017(&air_status,air_para);
		break;

	case 5018:
		AirRemote018(&air_status,air_para);
		break;

	case 5019:
		AirRemote019(&air_status,air_para);
		break;

	case 5020:
		AirRemote020(&air_status,air_para);
		break;

	case 5021:
		AirRemote021(&air_status,air_para);
		break;

	case 5022:
		AirRemote022(&air_status,air_para);
		break;

	case 5023:
		AirRemote023(&air_status,air_para);
		break;

	case 5025:
		AirRemote025(&air_status,air_para);
		break;

	case 5027:
		AirRemote027(&air_status,air_para);
		break;

	case 5030:
		AirRemote030(&air_status,air_para);
		break;

	case 5031:
		AirRemote031(&air_status,air_para);
		break;

	case 5032:
		AirRemote032(&air_status,air_para);
		break;

	case 5033:
		AirRemote033(&air_status,air_para);
		break;

	case 5036:
		AirRemote036(&air_status,air_para);
		break;

	case 5037:
		AirRemote037(&air_status,air_para);
		break;

	case 5038:
		AirRemote038(&air_status,air_para);
		break;

	case 5039:
		AirRemote039(&air_status,air_para);
		break;

	case 5040:
		AirRemote040(&air_status,air_para);
		break;

	case 5041:
		AirRemote041(&air_status,air_para);
		break;

	case 5042:
		AirRemote042(&air_status,air_para);
		break;

	case 5045:
		AirRemote045(&air_status,air_para);
		break;

	case 5046:
		AirRemote046(&air_status,air_para);
		break;

	case 5047:
		AirRemote047(&air_status,air_para);
		break;

	case 5048:
		AirRemote048(&air_status,air_para);
		break;

	case 5049:
		AirRemote049(&air_status,air_para);
		break;

	case 5050:
		AirRemote050(&air_status,air_para);
		break;

	case 5052:
		AirRemote052(&air_status,air_para);
		break;

	case 5057:
		AirRemote057(&air_status,air_para);
		break;

	case 5058:
		AirRemote058(&air_status,air_para);
		break;

	case 5062:
		AirRemote062(&air_status,air_para);
		break;

	case 5065:
		AirRemote065(&air_status,air_para);
		break;

	case 5066:
		AirRemote066(&air_status,air_para);
		break;

	case 5067:
		AirRemote067(&air_status,air_para);
		break;

	case 5096:
		AirRemote096(&air_status,air_para);
		break;

	case 5115:
		AirRemote115(&air_status,air_para);
		break;

	case 5123:
		AirRemote123(&air_status,air_para);
		break;

	case 5124:
		AirRemote124(&air_status,air_para);
		break;

	case 5125:
		AirRemote125(&air_status,air_para);
		break;

	case 5126:
		AirRemote126(&air_status,air_para);
		break;

	case 5127:
		AirRemote127(&air_status,air_para);
		break;

	case 5128:
		AirRemote128(&air_status,air_para);
		break;

	case 5186:
		AirRemote186(&air_status,air_para);
		break;

	case 5201:
		AirRemote201(&air_status,air_para);
		break;

	case 5208:
		AirRemote208(&air_status,air_para);
		break;

	case 5209:
		AirRemote209(&air_status,air_para);
		break;

	case 5210:
		AirRemote210(&air_status,air_para);
		break;

	case 5217:
		AirRemote217(&air_status,air_para);
		break;

	case 5230:
		AirRemote230(&air_status,air_para);
		break;

	case 5233:
		AirRemote233(&air_status,air_para);
		break;

	case 5237:
		AirRemote237(&air_status,air_para);
		break;

	case 5238:
		AirRemote238(&air_status,air_para);
		break;

	case 5281:
		AirRemote281(&air_status,air_para);
		break;

	case 5282:
		AirRemote282(&air_status,air_para);
		break;

	case 5417:
		AirRemote417(&air_status,air_para);
		break;

	case 5439:
		AirRemote439(&air_status,air_para);
		break;

	case 5481:
		AirRemote481(&air_status,air_para);
		break;

	case 5482:
		AirRemote482(&air_status,air_para);
		break;

	case 5495:
		AirRemote495(&air_status,air_para);
		break;

	default:
		free(air_para);
		return 0xff;
	}



	memset(vAirBuffer,0,128);
	vAirBuffer[0]=0x7f;
	vAirBuffer[1]=0x00;
	vAirBuffer[2]=0x00;
	vAirBuffer[3]=0x00;
	vAirBuffer[4]=0x00;
	vAirBuffer[5]=0x00;
	vAirBuffer[6]=0x00;
	vAirBuffer[7]=0x00;
	vAirBuffer[8]=0x00;
	vAirBuffer[9]=0x00;
	vAirBuffer[10]=0x00;
	vAirBuffer[11]=air_para->CARR;
	vAirBuffer[12]=air_para->STRU;
	vAirBuffer[13]=air_para->LDH_h;
	vAirBuffer[14]=air_para->LDH_l;
	vAirBuffer[15]=air_para->LDL_h;
	vAirBuffer[16]=air_para->LDL_l;
	vAirBuffer[17]=air_para->HIG_h;
	vAirBuffer[18]=air_para->HIG_l;
	vAirBuffer[19]=air_para->ZER_h;
	vAirBuffer[20]=air_para->ZER_l;
	vAirBuffer[21]=air_para->ONE_h;
	vAirBuffer[22]=air_para->ONE_l;
	vAirBuffer[23]=air_para->STO_h;
	vAirBuffer[24]=air_para->STO_l;
	vAirBuffer[25]=air_para->BIC0;
	vAirBuffer[26]=air_para->BIC1;
	vAirBuffer[27]=air_para->BIC2;
	vAirBuffer[28]=air_para->BIC3;
	for(i=0;i<64;i++){
		vAirBuffer[29+i]=air_para->COD[i];
	}

	free(air_para);

	return 0x00;
}



jbyteArray
Java_com_sommer_ircore_RemoteCore_getAirData( JNIEnv*  env,jobject jobj,jintArray data ){
	AIR_status airStatus;
//	unsigned char airDatas[20];
	unsigned char airSendData[128];
	int i, length=128;
	unsigned char err;
	int* airDatas = (int*)  (*env)->GetIntArrayElements(env, data, NULL);



    airStatus.nAirCode=airDatas[0];
    airStatus.vPower=airDatas[1];
    airStatus.vMode=airDatas[2];
    airStatus.vSpeed=airDatas[3];
    airStatus.vTemper=airDatas[4]-16;
    airStatus.vWind=airDatas[5];
    airStatus.vManualWind=airDatas[6];
    airStatus.vKey = airDatas[7];
#ifdef DEBUG
	LOGD("aircode ----> %d /n ",airStatus.nAirCode);
	LOGD("vPower ----> %d /n ",airStatus.vPower);
	LOGD("vMode ----> %d /n ",airStatus.vMode);
	LOGD("vSpeed ----> %d /n ",airStatus.vSpeed);
	LOGD("vTemper ----> %d /n ",airStatus.vTemper);
	LOGD("vWind ----> %d /n ",airStatus.vWind);
	LOGD("vManualWind ----> %d /n ",airStatus.vManualWind);
	LOGD("vKey ----> %d /n ",airStatus.vKey);
	#endif
	///////////////////////////////////////////////////////////////
	err=HandleAirRemote(airStatus,airSendData);


	jbyteArray byteArray = (*env)->NewByteArray(env,length);

	(*env)->SetByteArrayRegion(env,byteArray, 0, length, (jbyte*)airSendData);

	return byteArray;

}































