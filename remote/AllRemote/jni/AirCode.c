#include <jni.h>
#include <string.h>
#include <fcntl.h>
#include "logo.h"
#include "AirEncode.h"
#include "AirCode.h"
#include "FormData.h"
#include "Calculate.h"




#if 1
/**************		����***************/
/**************		5000		***************/
void AirRemote000(AIR_status *air_status , Air_para *air_para){
	unsigned char i;
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


/**************		涓夎彵閲嶅伐(09NV)	 ***************/
/**************		5001	 ***************/
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


/**************		涓夎彵鐢垫満(388) (003)	***************/
/*************     5002        **************/
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


/**************		涓滆姖1	(002) ***************/
/*************     5003        **************/
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


/**************			(000) ***************/
/*************     5005        **************/
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



void AirRemote060(AIR_status *air_status , Air_para *air_para){
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
		air_para->COD[0]|=0x20;
		break;
		
	case WIND_MANUAL:
		air_para->COD[0]|=0x10;
		break;

	default:
		break;
	}
	
	
	air_para->COD[1]=~air_para->COD[0];
	air_para->COD[3]=~air_para->COD[2];
	air_para->COD[4]=0x1d;
	air_para->COD[5]=0xe2;
	
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


/**************		涓滆姖1	 ***************/
/****************        5417(017)        ******************/
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


/**************		鍗庡噷1	 ***************/
/****************        5439(039)        ******************/
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


/**************		鍗庡噷1	 ***************/
/****************        5481(081)        ******************/
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


/**************		鍗庡噷1	 ***************/
/****************        5482(082)        ******************/
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


/**************		涓夎彵閲嶅伐(09NV)	 ***************/
/****************        5495(095)        ******************/
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

/****************       panasonic 973        ******************/
void Air_spca_panasonic_973(Air_para *air_para){
	air_para->CARR=0x20;
		air_para->STRU=0x06;
	
	
		air_para->LDH_h=0x04;
		air_para->LDH_l=0x46;
		
		air_para->LDL_h=0x04;
		air_para->LDL_l=0x46;
		
		air_para->HIG_h=0x01;
		air_para->HIG_l=0x0a;
		
		air_para->ZER_h=0x01;
		air_para->ZER_l=0x0a;
		
		air_para->ONE_h=0x03;
		air_para->ONE_l=0x0d;
	
		air_para->STO_h=0x10;
		air_para->STO_l=0xa6;
	
		air_para->BIC0=32;
		air_para->BIC1=32;
		air_para->BIC2=32;
		air_para->BIC3=32;

}

/****************       panasonic6 973        ******************/
void Air_spca_panasonic6_973(Air_para *air_para){
	air_para->CARR=0x20;
		air_para->STRU=0x06;
	
	
		air_para->LDH_h=0x04;
		air_para->LDH_l=0x46;
		
		air_para->LDL_h=0x04;
		air_para->LDL_l=0x46;
		
		air_para->HIG_h=0x01;
		air_para->HIG_l=0x0a;
		
		air_para->ZER_h=0x01;
		air_para->ZER_l=0x0a;
		
		air_para->ONE_h=0x03;
		air_para->ONE_l=0x0d;
	
		air_para->STO_h=0x10;
		air_para->STO_l=0xa6;
	
		air_para->BIC0=32;
		air_para->BIC1=32;
		air_para->BIC2=32;


}



/**************		鏉句笅1(973) 	 ***************/
/****************        5500(770)        ******************/
void AirRemote500(AIR_status *air_status , Air_para *air_para){
	
	Air_spca_panasonic_973(air_para);
	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[2]=0x0e;
		break;

	case MODE_COLD:
		air_para->COD[2]=0x0a;
		break;

	case MODE_WET:
		air_para->COD[2]=0x0b;
		break;

	case MODE_WIND:
		air_para->COD[2]=0x08;
		break;

	case MODE_HOT:
		air_para->COD[2]=0x0c;
		break;

	default:
		break;
	}
	
	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[0]|=0xf0;
		break;

	case SPEED_LOW:
		air_para->COD[0]|=0x20;
		break;

	case SPEED_MEDIUM:
		air_para->COD[0]|=0x40;
		break;

	case SPEED_HIGH:
		air_para->COD[0]|=0x60;
		break;

	default:
		break;
	}
	
	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[0]|=0x01;
		break;

	case TEMPER_17:
		air_para->COD[0]|=0x02;
		break;

	case TEMPER_18:
		air_para->COD[0]|=0x03;
		break;

	case TEMPER_19:
		air_para->COD[0]|=0x04;
		break;

	case TEMPER_20:
		air_para->COD[0]|=0x05;
		break;

	case TEMPER_21:
		air_para->COD[0]|=0x06;
		break;

	case TEMPER_22:
		air_para->COD[0]|=0x07;
		break;

	case TEMPER_23:
		air_para->COD[0]|=0x08;
		break;

	case TEMPER_24:
		air_para->COD[0]|=0x09;
		break;

	case TEMPER_25:
		air_para->COD[0]|=0x0a;
		break;

	case TEMPER_26:
		air_para->COD[0]|=0x0b;
		break;

	case TEMPER_27:
		air_para->COD[0]|=0x0c;
		break;

	case TEMPER_28:
		air_para->COD[0]|=0x0d;
		break;

	case TEMPER_29:
		air_para->COD[0]|=0x0e;
		break;

	case TEMPER_30:
		air_para->COD[0]|=0x0f;
		break;

	default:
		break;
	}

	switch(air_status->vKey){
	
		case POWER_KEY:
			air_para->COD[2]&=0xf7;
			break;

		default:
			break;
	}
	
	air_para->COD[1]=air_para->COD[0];
	air_para->COD[3]=air_para->COD[2];
	air_para->COD[4]=air_para->COD[0];
	air_para->COD[5]=air_para->COD[1];
	air_para->COD[6]=air_para->COD[2];
	air_para->COD[7]=air_para->COD[3];
	air_para->COD[8]=0x04;
	air_para->COD[9]=0x04;
	air_para->COD[10]=0x36;
	air_para->COD[11]=0x36;
	air_para->COD[12]=0x04;
	air_para->COD[13]=0x04;
	air_para->COD[14]=0x36;
	air_para->COD[15]=0x36;
}



/**************		TCL2	 ***************/
/*************     5501(771)        **************/
void AirRemote501(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x85;

	air_para->LDH_h=0x03;
	air_para->LDH_l=0x7a;
	
	air_para->LDL_h=0x03;
	air_para->LDL_l=0xa0;
	
	air_para->HIG_h=0x01;
	air_para->HIG_l=0x2f;
	
	air_para->STO_h=0x04;
	air_para->STO_l=0x94;

	air_para->BIC0=34;
	air_para->BIC1=34;
	air_para->BIC2=34;
	
	
	switch(air_status->vSpeed){
		case SPEED_AUTO:
			air_para->COD[0]|=0x0c;
			break;
		case SPEED_LOW:
			air_para->COD[0]|=0x00;
			break;
		case SPEED_MEDIUM:
			air_para->COD[0]|=0x04;
			break;
		case SPEED_HIGH:
			air_para->COD[0]|=0x08;
			break;
		default:
			break;
	}
	
	switch(air_status->vTemper){
	
		case TEMPER_16:
			air_para->COD[1]|=0x00;
			break;
			
		case TEMPER_17:
			air_para->COD[1]|=0x02;
			break;
			
		case TEMPER_18:
			air_para->COD[1]|=0x04;
			break;
			
		case TEMPER_19:
			air_para->COD[1]|=0x06;
			break;
			
		case TEMPER_20:
			air_para->COD[1]|=0x8;
			break;
			
		case TEMPER_21:
			air_para->COD[1]|=0x0a;
			break;
			
		case TEMPER_22:
			air_para->COD[1]|=0x0c;
			break;
			
		case TEMPER_23:
			air_para->COD[1]|=0x0e;
			break;
			
		case TEMPER_24:
			air_para->COD[1]|=0x10;
			break;
			
		case TEMPER_25:
			air_para->COD[1]|=0x12;
			break;
			
		case TEMPER_26:
			air_para->COD[1]|=0x14;
			break;
			
		case TEMPER_27:
			air_para->COD[1]|=0x16;
			break;
			
		case TEMPER_28:
			air_para->COD[1]|=0x18;
			break;
			
		case TEMPER_29:
			air_para->COD[1]|=0x1a;
			break;
			
		case TEMPER_30:
			air_para->COD[1]|=0x1c;
			break;
			
		default:
			break;
	}


	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[0]|=0x30;
			break;
		case MODE_COLD:
			air_para->COD[0]|=0x10;
			break;
		case MODE_WET:
			air_para->COD[0]|=0x40;
			break;
		case MODE_WIND:
			air_para->COD[0]|=0x50;
			break;
		case MODE_HOT:
			air_para->COD[0]|=0x20;
			break;
		default:
			break;
	}
	
	switch(air_status->vWind){
		case WIND_AUTO:
			air_para->COD[1]|=0x80;
			break;
		case WIND_MANUAL:
			air_para->COD[1]|=0x00;
			break;
		default:
			break;
	}
	
	
	switch(air_status->vKey){
	
		case POWER_KEY:
			air_para->COD[0]|=0x80;
			break;
			
		case WIND_MANUAL_KEY:
			switch(air_status->vWind){
				case WIND_AUTO:
					break;
				case WIND_MANUAL:
					air_para->COD[0]|=0x01;
					break;
				default:
					break;
			}
			break;
			
		case WIND_AUTO_KEY:
			switch(air_status->vWind){
				case WIND_AUTO:
					break;
				case WIND_MANUAL:
					air_para->COD[0]|=0x01;
					break;
				default:
					break;
			}
			break;
			
		default:
			break;
	}
	
	air_para->COD[0]=HiBitFst(air_para->COD[0]);
	air_para->COD[1]=HiBitFst(air_para->COD[1]);
	air_para->COD[2]=HiBitFst(0x00);
	air_para->COD[3]=HiBitFst(0x00);
	air_para->COD[4]=HiBitFst(0x02);
	air_para->COD[4]>>=6;
	air_para->COD[5]=air_para->COD[0];
	air_para->COD[6]=air_para->COD[1];
	air_para->COD[7]=air_para->COD[2];
	air_para->COD[8]=air_para->COD[3];
	air_para->COD[9]=air_para->COD[4];
	air_para->COD[10]=air_para->COD[0];
	air_para->COD[11]=air_para->COD[1];
	air_para->COD[12]=air_para->COD[2];
	air_para->COD[13]=air_para->COD[3];
	air_para->COD[14]=air_para->COD[4];
}



/**************		鏉炬牸2	 ***************/
/*************     5502(772)        **************/
void AirRemote502(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;

	air_para->LDH_h=0x04;
	air_para->LDH_l=0xe2;

	air_para->LDL_h=0x02;
	air_para->LDL_l=0x71;
	
	air_para->HIG_h=0x01;
	air_para->HIG_l=0x67;
	
	air_para->ZER_h=0x01;
	air_para->ZER_l=0x48;
	
	air_para->ONE_h=0x03;
	air_para->ONE_l=0xf8;


	air_para->BIC0=36;

	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[1]=0x00;
		break;

	case POWER_ON:
		air_para->COD[1]=0x07;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[1]|=0x10;
		break;

	case MODE_COLD:
		air_para->COD[1]|=0x00;
		break;

	case MODE_WET:
		air_para->COD[1]|=0x10;
		break;

	case MODE_WIND:
		air_para->COD[1]|=0x20;
		break;

	case MODE_HOT:
		air_para->COD[1]|=0x10;
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
		air_para->COD[3]|=0x00;
		break;

	case TEMPER_17:
		air_para->COD[3]|=0x01;
		break;

	case TEMPER_18:
		air_para->COD[3]|=0x02;
		break;

	case TEMPER_19:
		air_para->COD[3]|=0x03;
		break;

	case TEMPER_20:
		air_para->COD[3]|=0x04;
		break;

	case TEMPER_21:
		air_para->COD[3]|=0x05;
		break;

	case TEMPER_22:
		air_para->COD[3]|=0x06;
		break;

	case TEMPER_23:
		air_para->COD[3]|=0x07;
		break;

	case TEMPER_24:
		air_para->COD[3]|=0x08;
		break;

	case TEMPER_25:
		air_para->COD[3]|=0x09;
		break;

	case TEMPER_26:
		air_para->COD[3]|=0x0a;
		break;

	case TEMPER_27:
		air_para->COD[3]|=0x0b;
		break;

	case TEMPER_28:
		air_para->COD[3]|=0x0c;
		break;

	case TEMPER_29:
		air_para->COD[3]|=0x0d;
		break;

	case TEMPER_30:
		air_para->COD[3]|=0x0e;
		break;

	default:
		break;
	}

	switch(air_status->vWind){
	
	case WIND_AUTO:
		air_para->COD[4]|=0x00;
		break;

	case WIND_MANUAL:
		
		switch(air_status->vManualWind){
		case MANUAL_WIND_1:
			air_para->COD[4]|=0x01;
			break;
		case MANUAL_WIND_2:
			air_para->COD[4]|=0x02;
			break;
		case MANUAL_WIND_3:
			air_para->COD[4]|=0x03;
			break;
		case MANUAL_WIND_4:
			air_para->COD[4]|=0x04;
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}

	air_para->COD[0]=0x69;
	air_para->COD[2]=0x00;
}



/**************		LG2	 ***************/
/*************     5503(600)       **************/
void AirRemote503(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;

	air_para->LDH_h=0x0a;
	air_para->LDH_l=0x5d;
	
	air_para->LDL_h=0x05;
	air_para->LDL_l=0x0a;
	
	air_para->HIG_h=0x00;
	air_para->HIG_l=0xa6;
	
	air_para->ZER_h=0x00;
	air_para->ZER_l=0xa6;
	
	air_para->ONE_h=0x01;
	air_para->ONE_l=0xf7;

	air_para->BIC0=28;
	
	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[1]|=0x03;
		break;

	case MODE_COLD:
		air_para->COD[1]|=0x00;
		break;

	case MODE_WET:
		air_para->COD[1]|=0x01;
		break;

	case MODE_WIND:
		air_para->COD[1]|=0x02;
		break;

	case MODE_HOT:
		air_para->COD[1]|=0x04;
		break;

	default:
		break;
	}

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[2]|=0x05;
		break;

	case SPEED_LOW:
		air_para->COD[2]|=0x00;
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
		air_para->COD[2]=0x30;
		break;

	case TEMPER_17:
		air_para->COD[2]=0x30;
		break;

	case TEMPER_18:
		air_para->COD[2]=0x30;
		break;

	case TEMPER_19:
		air_para->COD[2]=0x40;
		break;

	case TEMPER_20:
		air_para->COD[2]=0x50;
		break;

	case TEMPER_21:
		air_para->COD[2]=0x60;
		break;

	case TEMPER_22:
		air_para->COD[2]=0x70;
		break;

	case TEMPER_23:
		air_para->COD[2]=0x80;
		break;

	case TEMPER_24:
		air_para->COD[2]=0x90;
		break;

	case TEMPER_25:
		air_para->COD[2]=0xa0;
		break;

	case TEMPER_26:
		air_para->COD[2]=0xb0;
		break;

	case TEMPER_27:
		air_para->COD[2]=0xc0;
		break;

	case TEMPER_28:
		air_para->COD[2]=0xd0;
		break;

	case TEMPER_29:
		air_para->COD[2]=0xe0;
		break;

	case TEMPER_30:
		air_para->COD[2]=0xf0;
		break;

	default:
		break;
	}

	switch(air_status->vKey){

		case POWER_KEY:
			switch(air_status->vPower){

				case POWER_OFF:
					air_para->COD[1]=0xc0;
					air_para->COD[2]=0x05;
					break;

				case POWER_ON:
					break;

				default:
					break;
			}

			break;

		case WIND_MANUAL_KEY:
			air_para->COD[1]=0x10;
			air_para->COD[2]=0x00;
			break;

		case WIND_AUTO_KEY:
			air_para->COD[1]=0x10;
			air_para->COD[2]=0x00;
			break;

		default:
			air_para->COD[1]|=0x08;
			break;
	}

	air_para->COD[0]=0x88;
	air_para->COD[3]=((air_para->COD[0]>>4)+(air_para->COD[0]&0x0f)+(air_para->COD[1]>>4)+(air_para->COD[1]&0x0f)+(air_para->COD[2]>>4)+(air_para->COD[2]))&0x0f;
	air_para->COD[0]=HiBitFst(air_para->COD[0]);
	air_para->COD[1]=HiBitFst(air_para->COD[1]);
	air_para->COD[2]=HiBitFst(air_para->COD[2]);
	air_para->COD[3]=HiBitFst(air_para->COD[3])>>4;
}






/**************		涓夎彵1	 ***************/
/*************     5504(232)      **************/

void AirRemote504(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;

	air_para->LDH_h=0x04;
	air_para->LDH_l=0x46;
	
	air_para->LDL_h=0x02;
	air_para->LDL_l=0x13;
	
	air_para->HIG_h=0x00;
	air_para->HIG_l=0x8d;
	
	air_para->ZER_h=0x00;
	air_para->ZER_l=0x8d;
	
	air_para->ONE_h=0x01;
	air_para->ONE_l=0x86;


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
			air_para->COD[7]=0xf7;
			break;

		case MODE_COLD:
			air_para->COD[5]|=0x80;
			air_para->COD[7]=0xf7;
			break;

		case MODE_WET:
			air_para->COD[5]|=0xc0;
			air_para->COD[7]=0xf7;
			break;

		case MODE_WIND:
			air_para->COD[5]|=0x00;
			air_para->COD[7]=0xf7;
			break;

		case MODE_HOT:
			air_para->COD[5]|=0x40;
			air_para->COD[7]=0xd6;
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



/**************		鏂拌	 ***************/
/*************     5505(233)        **************/
void AirRemote505(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;

	air_para->LDH_h=0x0a;
	air_para->LDH_l=0x4e;
	
	air_para->LDL_h=0x04;
	air_para->LDL_l=0xfb;
	
	air_para->HIG_h=0x00;
	air_para->HIG_l=0x9c;
	
	air_para->ZER_h=0x00;
	air_para->ZER_l=0xac;
	
	air_para->ONE_h=0x01;
	air_para->ONE_l=0xd5;

	air_para->BIC0=72;

	air_para->COD[0]=0x6a;
	air_para->COD[2]=0x5b;
	air_para->COD[3]=0x00;
	air_para->COD[6]=0x00;
	air_para->COD[7]=0x00;
	
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
			air_para->COD[4]|=0x40;
			break;
		case MODE_COLD:
			air_para->COD[4]|=0x20;
			break;
		case MODE_WET:
			air_para->COD[4]|=0x30;
			break;
		case MODE_WIND:
			air_para->COD[4]|=0x50;
			break;
		case MODE_HOT:
			air_para->COD[4]|=0x10;
			air_para->COD[2]=0x47;
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

	air_para->COD[8]=((air_para->COD[0])>>4)+((air_para->COD[0])&0x0f)+
					  ((air_para->COD[1])>>4)+((air_para->COD[1])&0x0f)+
					  ((air_para->COD[2])>>4)+((air_para->COD[2])&0x0f)+
					  ((air_para->COD[3])>>4)+((air_para->COD[3])&0x0f)+
					  ((air_para->COD[4])>>4)+((air_para->COD[4])&0x0f)+
					  ((air_para->COD[5])>>4)+((air_para->COD[5])&0x0f)+
					  ((air_para->COD[6])>>4)+((air_para->COD[6])&0x0f)+
					  ((air_para->COD[7])>>4)+((air_para->COD[7])&0x0f);
	
}



/**************		瀵屽＋閫�	 ***************/
/*************     5506(180)      **************/
void AirRemote506(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;

	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xfc;
	
	air_para->LDL_h=0x05;
	air_para->LDL_l=0x7e;
	
	air_para->HIG_h=0x00;
	air_para->HIG_l=0xaf;
	
	air_para->ZER_h=0x00;
	air_para->ZER_l=0xaf;
	
	air_para->ONE_h=0x02;
	air_para->ONE_l=0x0d;

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





/**************		濂ュ厠鏂�/3	 ***************/
/*************     5507(182)      **************/
void AirRemote507(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;

	air_para->LDH_h=0x09;
	air_para->LDH_l=0xe3;
	
	air_para->LDL_h=0x05;
	air_para->LDL_l=0x7e;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xbb;
	
	air_para->ZER_h=0x00;
	air_para->ZER_l=0xbb;
	
	air_para->ONE_h=0x02;
	air_para->ONE_l=0x0d;

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





/**************		濂ュ厠鏂�	 ***************/
/*************     5508(191)      **************/
void AirRemote508(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xfc;
	
	air_para->LDL_h=0x05;
	air_para->LDL_l=0x7e;
	
	air_para->HIG_h=0x00;
	air_para->HIG_l=0xcb;
	
	air_para->ZER_h=0x00;
	air_para->ZER_l=0xcb;
	
	air_para->ONE_h=0x01;
	air_para->ONE_l=0xf4;


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

	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[0]|=0x00;
			air_para->COD[8]=0xff;
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

	
	air_para->COD[1]=0x10;
	air_para->COD[2]=0x57;
	air_para->COD[3]=0x44;
	air_para->COD[4]=0x00;
	air_para->COD[5]=0x00;
	air_para->COD[6]=0x00;
	air_para->COD[7]=0x00;
	
	air_para->COD[10]=0x00;
	air_para->COD[11]=0x19;

}



/**************		濂ュ厠鏂�	 ***************/
/*************     5509(183)      **************/
void AirRemote509(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;

	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xfc;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x7e;
	
	air_para->HIG_h=0x00;
	air_para->HIG_l=0xcb;
	
	air_para->ZER_h=0x00;
	air_para->ZER_l=0xcb;
	
	air_para->ONE_h=0x01;
	air_para->ONE_l=0xf4;


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

	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[0]|=0x00;
			air_para->COD[8]=0xff;
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

	
	air_para->COD[1]=0x01;
	air_para->COD[2]=0x31;
	air_para->COD[3]=0x44;
	air_para->COD[4]=0x00;
	air_para->COD[5]=0x00;
	air_para->COD[6]=0x00;
	air_para->COD[7]=0x00;
	
	air_para->COD[10]=0x00;
	air_para->COD[11]=0x19;

}


/**************		婢虫煰鐜�	 ***************/
/*************     5510(196)      **************/
void AirRemote510(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;

	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xfc;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x7e;
	
	air_para->HIG_h=0x00;
	air_para->HIG_l=0xaf;
	
	air_para->ZER_h=0x00;
	air_para->ZER_l=0xaf;
	
	air_para->ONE_h=0x02;
	air_para->ONE_l=0x0d;

	air_para->BIC0=80;
	
	switch(air_status->vPower){
		case POWER_OFF:
			air_para->COD[4]=0x00;
			break;
		case POWER_ON:
			air_para->COD[4]=0x80;
			break;
		default:
			break;
	}
	
	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[4]|=0x10;
			break;
		case MODE_COLD:
			air_para->COD[4]|=0x00;
			break;
		case MODE_WET:
			air_para->COD[4]|=0x40;
			break;
		case MODE_WIND:
			air_para->COD[4]|=0x60;
			break;
		case MODE_HOT:
			air_para->COD[4]|=0x20;
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
			air_para->COD[4]|=0x00;
			break;
		case TEMPER_19:
			air_para->COD[4]|=0x01;
			break;
		case TEMPER_20:
			air_para->COD[4]|=0x02;
			break;
		case TEMPER_21:
			air_para->COD[4]|=0x03;
			break;
		case TEMPER_22:
			air_para->COD[4]|=0x04;
			break;
		case TEMPER_23:
			air_para->COD[4]|=0x05;
			break;
		case TEMPER_24:
			air_para->COD[4]|=0x06;
			break;
		case TEMPER_25:
			air_para->COD[4]|=0x07;
			break;
		case TEMPER_26:
			air_para->COD[4]|=0x08;
			break;
		case TEMPER_27:
			air_para->COD[4]|=0x09;
			break;
		case TEMPER_28:
			air_para->COD[4]|=0x0a;
			break;
		case TEMPER_29:
			air_para->COD[4]|=0x0b;
			break;
		case TEMPER_30:
			air_para->COD[4]|=0x0c;
			break;
		default:
			break;
	}
	
	air_para->COD[0]=0xfd;
	air_para->COD[1]=0xff;
	air_para->COD[2]=0xff;
	air_para->COD[3]=0xff;

	air_para->COD[5]=0xff-air_para->COD[0];
	air_para->COD[6]=0xff-air_para->COD[1];
	air_para->COD[7]=0xff-air_para->COD[2];
	air_para->COD[8]=0xff-air_para->COD[3];
	air_para->COD[9]=0xff-air_para->COD[4];
}



/**************		濂ュ厠鏂�	 ***************/
/*************     5511(198)      **************/
void AirRemote511(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;

	air_para->LDH_h=0x04;
	air_para->LDH_l=0xe2;

	air_para->LDL_h=0x02;
	air_para->LDL_l=0x71;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xaf;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0x83;
	
	air_para->ONE_h=0x01;
	air_para->ONE_l=0x23;

	air_para->BIC0=44;

	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[1]|=0x00;
			break;
		case MODE_COLD:
			air_para->COD[1]|=0x20;
			break;
		case MODE_WET:
			air_para->COD[1]|=0x40;
			break;
		case MODE_WIND:
			air_para->COD[1]|=0x60;
			break;
		case MODE_HOT:
			air_para->COD[1]|=0x00;
			break;
		default:
			break;
	}

	switch(air_status->vSpeed){
		case SPEED_AUTO:
			air_para->COD[1]|=0x00;
			break;
		case SPEED_LOW:
			air_para->COD[1]|=0x01;
			break;
		case SPEED_MEDIUM:
			air_para->COD[1]|=0x02;
			break;
		case SPEED_HIGH:
			air_para->COD[1]|=0x03;
			break;
		default:
			break;
	}
	
	switch(air_status->vTemper){
		case TEMPER_16:
			air_para->COD[2]=0x0e;
			break;
		case TEMPER_17:
			air_para->COD[2]=0x0d;
			break;
		case TEMPER_18:
			air_para->COD[2]=0x0c;
			break;
		case TEMPER_19:
			air_para->COD[2]=0x0b;
			break;
		case TEMPER_20:
			air_para->COD[2]=0x0a;
			break;
		case TEMPER_21:
			air_para->COD[2]=0x09;
			break;
		case TEMPER_22:
			air_para->COD[2]=0x08;
			break;
		case TEMPER_23:
			air_para->COD[2]=0x07;
			break;
		case TEMPER_24:
			air_para->COD[2]=0x06;
			break;
		case TEMPER_25:
			air_para->COD[2]=0x05;
			break;
		case TEMPER_26:
			air_para->COD[2]=0x04;
			break;
		case TEMPER_27:
			air_para->COD[2]=0x03;
			break;
		case TEMPER_28:
			air_para->COD[2]=0x02;
			break;
		case TEMPER_29:
			air_para->COD[2]=0x01;
			break;
		case TEMPER_30:
			air_para->COD[2]=0x00;
			break;
		default:
			break;
	}

	switch(air_status->vWind)
	{
		case WIND_AUTO:
			air_para->COD[2]|=0x70;
			break;
		case WIND_MANUAL:
			switch(air_status->vManualWind)
			{
				case MANUAL_WIND_1:
					air_para->COD[2]|=0x00;
					break;
				case MANUAL_WIND_2:
					air_para->COD[2]|=0x20;
					break;
				case MANUAL_WIND_3:
					air_para->COD[2]|=0x00;
					break;
				case MANUAL_WIND_4:
					air_para->COD[2]|=0x20;
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}

	switch(air_status->vKey)
	{
		case WIND_MANUAL_KEY:
			air_para->COD[2]|=0x80;
			break;
		default:
			break;
	}

	switch(air_status->vPower){
		case POWER_OFF:
			air_para->COD[1]&=0x7f;
			break;
		case POWER_ON:
			air_para->COD[1]|=0x80;
			break;
		default:
			break;
	}


	air_para->COD[0]=0x96;
	air_para->COD[3]=0x00;
	air_para->COD[4]=0x00;
	air_para->COD[5]=0x00;
}





/**************		鎯犺�娴�***************/
/*************     5512(5292)        **************/
void AirRemote512(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x11;

	air_para->LDH_h=0x05;
	air_para->LDH_l=0x7f;

	air_para->LDL_h=0x03;
	air_para->LDL_l=0x0d;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0x5e;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0x90;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0x38;

	air_para->STO_h=0x18;
	air_para->STO_l=0x6a;

	air_para->BIC0=140;

	air_para->COD[0]=0x00;
	air_para->COD[1]=0x00;
	air_para->COD[2]=0x00;
	air_para->COD[3]=0x00;
	air_para->COD[4]=0x00;
	air_para->COD[5]=0x00;
	air_para->COD[6]=0x00;
	air_para->COD[7]=0x00;
	air_para->COD[8]=0x00;
	air_para->COD[9]=0x00;
	air_para->COD[10]=0x00;
	air_para->COD[11]=0x00;
	air_para->COD[12]=0x00;
	air_para->COD[13]=0x00;

	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[15]|=0xa0;
			break;
		case MODE_COLD:
			air_para->COD[15]|=0x20;
			break;
		case MODE_WET:
			air_para->COD[15]|=0x10;
			break;
		case MODE_WIND:
			air_para->COD[15]|=0x40;
			break;
		case MODE_HOT:
			air_para->COD[15]|=0x80;
			break;
		default:
			break;
	}

	switch(air_status->vSpeed){
		case SPEED_AUTO:
			air_para->COD[15]|=0x01;
			break;
		case SPEED_LOW:
			air_para->COD[15]|=0x08;
			break;
		case SPEED_MEDIUM:
			air_para->COD[15]|=0x04;
			break;
		case SPEED_HIGH:
			air_para->COD[15]|=0x02;
			break;
		default:
			break;
	}

	switch(air_status->vTemper){
		case TEMPER_16:
			air_para->COD[16]=0x16;
			break;
		case TEMPER_17:
			air_para->COD[16]=0x17;
			break;
		case TEMPER_18:
			air_para->COD[16]=0x18;
			break;
		case TEMPER_19:
			air_para->COD[16]=0x19;
			break;
		case TEMPER_20:
			air_para->COD[16]=0x20;
			break;
		case TEMPER_21:
			air_para->COD[16]=0x21;
			break;
		case TEMPER_22:
			air_para->COD[16]=0x22;
			break;
		case TEMPER_23:
			air_para->COD[16]=0x23;
			break;
		case TEMPER_24:
			air_para->COD[16]=0x24;
			break;
		case TEMPER_25:
			air_para->COD[16]=0x25;
			break;
		case TEMPER_26:
			air_para->COD[16]=0x26;
			break;
		case TEMPER_27:
			air_para->COD[16]=0x27;
			break;
		case TEMPER_28:
			air_para->COD[16]=0x28;
			break;
		case TEMPER_29:
			air_para->COD[16]=0x29;
			break;
		case TEMPER_30:
			air_para->COD[16]=0x30;
			break;
		default:
			break;
	}

	switch(air_status->vWind){

		case WIND_AUTO:
			air_para->COD[14]|=0x10;
			break;
		case WIND_MANUAL:
			air_para->COD[14]|=0x00;
			break;
		default:
			break;
	}

	switch(air_status->vKey)
	{
		case POWER_KEY:
			air_para->COD[14]|=0x80;
			break;
		default:
			break;
	}

	air_para->COD[17]=(( (air_para->COD[0]>>4)+(air_para->COD[0]&0x0f)+
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
						 (air_para->COD[11]>>4)+(air_para->COD[11]&0x0f)+
						 (air_para->COD[12]>>4)+(air_para->COD[12]&0x0f)+
						 (air_para->COD[13]>>4)+(air_para->COD[13]&0x0f)+
						 (air_para->COD[14]>>4)+(air_para->COD[14]&0x0f)+
						 (air_para->COD[15]>>4)+(air_para->COD[15]&0x0f)+
						 (air_para->COD[16]>>4)+(air_para->COD[16]&0x0f))
						 &0x0f);
}



/**************		涓夎彵閲嶅伐(09NV)	 ***************/
/**************		5513(120)	 ***************/
void AirRemote513(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;

	air_para->LDH_h=0x04;
	air_para->LDH_l=0x3e;

	air_para->LDL_h=0x02;
	air_para->LDL_l=0x0c;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0x92;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0x7b;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0x80;

	air_para->BIC0=112;

	switch(air_status->vPower){
		case POWER_OFF:
			air_para->COD[5]=0x23;
			break;
		case POWER_ON:
			air_para->COD[5]=0x27;
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
				air_para->COD[8]|=0x08;
				break;
			case MANUAL_WIND_2:
				air_para->COD[8]|=0x10;
				break;
			case MANUAL_WIND_3:
				air_para->COD[8]|=0x18;
				break;
			case MANUAL_WIND_4:
				air_para->COD[8]|=0x20;
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





/**************		TCL1	***************/
/*************     5514 (130)       **************/
void AirRemote514(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x12;

	air_para->LDH_h=0x09;
	air_para->LDH_l=0x95;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x21;

	air_para->HIG_h=0x01;
	air_para->HIG_l=0xf4;

	air_para->ONE_h=0x00;
	air_para->ONE_l=0x9c;

	air_para->STO_h=0x25;
	air_para->STO_l=0x90;


	air_para->BIC0=64;
	air_para->BIC1=64;
	
	
	
	
	switch(air_status->vPower){
		case POWER_OFF:
			air_para->COD[5]=0xc0;
			break;
		case POWER_ON:
			air_para->COD[5]=0x30;
			break;
		default:
			break;
	}

	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[1]|=0x05;
			break;
		case MODE_COLD:
			air_para->COD[1]|=0x01;
			break;
		case MODE_WET:
			air_para->COD[1]|=0x04;
			break;
		case MODE_WIND:
			air_para->COD[1]|=0x03;
			break;
		case MODE_HOT:
			air_para->COD[1]|=0x02;
			break;
		default:
			break;
	}

	switch(air_status->vSpeed){
		case SPEED_AUTO:
			air_para->COD[1]|=0x40;
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
			air_para->COD[2]=0x20;
			break;
		case TEMPER_17:
			air_para->COD[2]=0x22;
			break;
		case TEMPER_18:
			air_para->COD[2]=0x24;
			break;
		case TEMPER_19:
			air_para->COD[2]=0x26;
			break;
		case TEMPER_20:
			air_para->COD[2]=0x28;
			break;
		case TEMPER_21:
			air_para->COD[2]=0x2a;
			break;
		case TEMPER_22:
			air_para->COD[2]=0x2c;
			break;
		case TEMPER_23:
			air_para->COD[2]=0x2e;
			break;
		case TEMPER_24:
			air_para->COD[2]=0x30;
			break;
		case TEMPER_25:
			air_para->COD[2]=0x32;
			break;
		case TEMPER_26:
			air_para->COD[2]=0x34;
			break;
		case TEMPER_27:
			air_para->COD[2]=0x36;
			break;
		case TEMPER_28:
			air_para->COD[2]=0x38;
			break;
		case TEMPER_29:
			air_para->COD[2]=0x3a;
			break;
		case TEMPER_30:
			air_para->COD[2]=0x3c;
			break;
		default:
			break;
	}

	switch(air_status->vWind)
	{
		case WIND_AUTO:
			air_para->COD[6]=0xc0;
			break;
		case WIND_MANUAL:
			air_para->COD[6]=0x00;
			break;
		default:
			break;
	}

	air_para->COD[0]=0x01;
	air_para->COD[3]=0x00;
	air_para->COD[4]=0x00;
	air_para->COD[7]=(air_para->COD[0]>>4)+(air_para->COD[0]&0x0f)+
					 (air_para->COD[1]>>4)+(air_para->COD[1]&0x0f)+
					 (air_para->COD[2]>>4)+(air_para->COD[2]&0x0f)+
					 (air_para->COD[3]>>4)+(air_para->COD[3]&0x0f)+
					 (air_para->COD[4]>>4)+(air_para->COD[4]&0x0f)+
					 (air_para->COD[5]>>4)+(air_para->COD[5]&0x0f)+
					 (air_para->COD[6]>>4)+(air_para->COD[6]&0x0f);

	air_para->COD[8]=air_para->COD[0];
	air_para->COD[9]=air_para->COD[1];
	air_para->COD[10]=air_para->COD[2];
	air_para->COD[11]=air_para->COD[3];
	air_para->COD[12]=air_para->COD[4];
	air_para->COD[13]=air_para->COD[5];
	air_para->COD[14]=air_para->COD[6];
	air_para->COD[15]=air_para->COD[7];
}



/**************		York2		***************/
/*************     5515(132)        **************/
void AirRemote515(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x11;

	air_para->LDH_h=0x05;
	air_para->LDH_l=0x7f;

	air_para->LDL_h=0x03;
	air_para->LDL_l=0x0d;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0x74;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0x74;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0x29;

	air_para->STO_h=0x18;
	air_para->STO_l=0x6a;

	air_para->BIC0=64;

	air_para->COD[0]=0x16;
	air_para->COD[2]=0x05;
	air_para->COD[3]=0x00;
	air_para->COD[4]=0x00;
	air_para->COD[5]=0x00;

	switch(air_status->vSpeed){
		case SPEED_AUTO:
			air_para->COD[1]|=0x10;
			break;
		case SPEED_LOW:
			air_para->COD[1]|=0x80;
			break;
		case SPEED_MEDIUM:
			air_para->COD[1]|=0x40;
			break;
		case SPEED_HIGH:
			air_para->COD[1]|=0x20;
			break;
		default:
			break;
	}

	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[1]|=0x0a;
			break;
		case MODE_COLD:
			air_para->COD[1]|=0x02;
			break;
		case MODE_WET:
			air_para->COD[1]=0x11;
			break;
		case MODE_WIND:
			air_para->COD[1]|=0x04;
			break;
		case MODE_HOT:
			air_para->COD[1]|=0x08;
			break;
		default:
			break;
	}

	switch(air_status->vTemper){
		case TEMPER_16:
			air_para->COD[6]=0x16;
			break;
		case TEMPER_17:
			air_para->COD[6]=0x17;
			break;
		case TEMPER_18:
			air_para->COD[6]=0x18;
			break;
		case TEMPER_19:
			air_para->COD[6]=0x19;
			break;
		case TEMPER_20:
			air_para->COD[6]=0x20;
			break;
		case TEMPER_21:
			air_para->COD[6]=0x21;
			break;
		case TEMPER_22:
			air_para->COD[6]=0x22;
			break;
		case TEMPER_23:
			air_para->COD[6]=0x23;
			break;
		case TEMPER_24:
			air_para->COD[6]=0x24;
			break;
		case TEMPER_25:
			air_para->COD[6]=0x25;
			break;
		case TEMPER_26:
			air_para->COD[6]=0x26;
			break;
		case TEMPER_27:
			air_para->COD[6]=0x27;
			break;
		case TEMPER_28:
			air_para->COD[6]=0x28;
			break;
		case TEMPER_29:
			air_para->COD[6]=0x29;
			break;
		case TEMPER_30:
			air_para->COD[6]=0x30;
			break;
		default:
			break;
	}

	switch(air_status->vWind){

		case WIND_AUTO:
			air_para->COD[7]|=0x01;
			break;
		case WIND_MANUAL:
			air_para->COD[7]|=0x00;
			break;
		default:
			break;
	}

	switch(air_status->vKey)
	{
		case POWER_KEY:
			air_para->COD[7]|=0x08;
			break;
		default:
			break;
	}

	air_para->COD[7]|=(( (air_para->COD[0]>>4)+(air_para->COD[0]&0x0f)+
						 (air_para->COD[1]>>4)+(air_para->COD[1]&0x0f)+
						 (air_para->COD[2]>>4)+(air_para->COD[2]&0x0f)+
						 (air_para->COD[3]>>4)+(air_para->COD[3]&0x0f)+
						 (air_para->COD[4]>>4)+(air_para->COD[4]&0x0f)+
						 (air_para->COD[5]>>4)+(air_para->COD[5]&0x0f)+
						 (air_para->COD[6]>>4)+(air_para->COD[6]&0x0f)+
						 (air_para->COD[7]&0x0f))&0x0f)<<4;
}


/**************		TCL2	 ***************/
/*************     5516(133)        **************/
void AirRemote516(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x85;

	air_para->LDH_h=0x03;
	air_para->LDH_l=0x7b;

	air_para->LDL_h=0x03;
	air_para->LDL_l=0xa0;

	air_para->HIG_h=0x01;
	air_para->HIG_l=0x2f;

	air_para->STO_h=0x04;
	air_para->STO_l=0x94;

	air_para->BIC0=34;
	air_para->BIC1=34;
	air_para->BIC2=34;


	switch(air_status->vSpeed){
		case SPEED_AUTO:
			air_para->COD[0]|=0x0c;
			break;
		case SPEED_LOW:
			air_para->COD[0]|=0x00;
			break;
		case SPEED_MEDIUM:
			air_para->COD[0]|=0x04;
			break;
		case SPEED_HIGH:
			air_para->COD[0]|=0x08;
			break;
		default:
			break;
	}

	switch(air_status->vTemper){

		case TEMPER_16:
			air_para->COD[1]|=0x00;
			break;

		case TEMPER_17:
			air_para->COD[1]|=0x02;
			break;

		case TEMPER_18:
			air_para->COD[1]|=0x04;
			break;

		case TEMPER_19:
			air_para->COD[1]|=0x06;
			break;

		case TEMPER_20:
			air_para->COD[1]|=0x08;
			break;

		case TEMPER_21:
			air_para->COD[1]|=0x0a;
			break;

		case TEMPER_22:
			air_para->COD[1]|=0x0c;
			break;

		case TEMPER_23:
			air_para->COD[1]|=0x0e;
			break;

		case TEMPER_24:
			air_para->COD[1]|=0x10;
			break;

		case TEMPER_25:
			air_para->COD[1]|=0x12;
			break;

		case TEMPER_26:
			air_para->COD[1]|=0x14;
			break;

		case TEMPER_27:
			air_para->COD[1]|=0x16;
			break;

		case TEMPER_28:
			air_para->COD[1]|=0x18;
			break;

		case TEMPER_29:
			air_para->COD[1]|=0x1a;
			break;

		case TEMPER_30:
			air_para->COD[1]|=0x1c;
			break;

		default:
			break;
	}


	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[0]|=0x30;
			break;
		case MODE_COLD:
			air_para->COD[0]|=0x10;
			break;
		case MODE_WET:
			air_para->COD[0]|=0x40;
			break;
		case MODE_WIND:
			air_para->COD[0]|=0x50;
			break;
		case MODE_HOT:
			air_para->COD[0]|=0x20;
			break;
		default:
			break;
	}

	switch(air_status->vWind){
		case WIND_AUTO:
			air_para->COD[1]|=0x80;
			break;
		case WIND_MANUAL:
			air_para->COD[1]|=0x00;
			break;
		default:
			break;
	}


	switch(air_status->vKey){

		case POWER_KEY:
			air_para->COD[0]|=0x80;
			break;

		case WIND_MANUAL_KEY:
			switch(air_status->vWind){
				case WIND_AUTO:
					break;
				case WIND_MANUAL:
					air_para->COD[0]|=0x01;
					break;
				default:
					break;
			}
			break;

		case WIND_AUTO_KEY:
			switch(air_status->vWind){
				case WIND_AUTO:
					break;
				case WIND_MANUAL:
					air_para->COD[0]|=0x01;
					break;
				default:
					break;
			}
			break;

		default:
			break;
	}

	air_para->COD[0]=HiBitFst(air_para->COD[0]);
	air_para->COD[1]=HiBitFst(air_para->COD[1]);
	air_para->COD[2]=HiBitFst(0x00);
	air_para->COD[3]=HiBitFst(0x00);
	air_para->COD[4]=HiBitFst(0x02);
	air_para->COD[4]>>=6;
	air_para->COD[5]=air_para->COD[0];
	air_para->COD[6]=air_para->COD[1];
	air_para->COD[7]=air_para->COD[2];
	air_para->COD[8]=air_para->COD[3];
	air_para->COD[9]=air_para->COD[4];
	air_para->COD[10]=air_para->COD[0];
	air_para->COD[11]=air_para->COD[1];
	air_para->COD[12]=air_para->COD[2];
	air_para->COD[13]=air_para->COD[3];
	air_para->COD[14]=air_para->COD[4];
}



/**************		TCL3	 ***************/
/*************     (5517)134        **************/
void AirRemote517(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x85;

	air_para->LDH_h=0x03;
	air_para->LDH_l=0x7a;

	air_para->LDL_h=0x03;
	air_para->LDL_l=0xa0;

	air_para->HIG_h=0x01;
	air_para->HIG_l=0x2f;

	air_para->STO_h=0x04;
	air_para->STO_l=0x94;

	air_para->BIC0=40;
	air_para->BIC1=40;
	air_para->BIC2=40;


	switch(air_status->vSpeed){
		case SPEED_AUTO:
			air_para->COD[0]|=0x0c;
			break;
		case SPEED_LOW:
			air_para->COD[0]|=0x00;
			break;
		case SPEED_MEDIUM:
			air_para->COD[0]|=0x04;
			break;
		case SPEED_HIGH:
			air_para->COD[0]|=0x08;
			break;
		default:
			break;
	}

	switch(air_status->vTemper){

		case TEMPER_16:
			air_para->COD[1]|=0x00;
			break;

		case TEMPER_17:
			air_para->COD[1]|=0x02;
			break;

		case TEMPER_18:
			air_para->COD[1]|=0x04;
			break;

		case TEMPER_19:
			air_para->COD[1]|=0x06;
			break;

		case TEMPER_20:
			air_para->COD[1]|=0x8;
			break;

		case TEMPER_21:
			air_para->COD[1]|=0x0a;
			break;

		case TEMPER_22:
			air_para->COD[1]|=0x0c;
			break;

		case TEMPER_23:
			air_para->COD[1]|=0x0e;
			break;

		case TEMPER_24:
			air_para->COD[1]|=0x10;
			break;

		case TEMPER_25:
			air_para->COD[1]|=0x12;
			break;

		case TEMPER_26:
			air_para->COD[1]|=0x14;
			break;

		case TEMPER_27:
			air_para->COD[1]|=0x16;
			break;

		case TEMPER_28:
			air_para->COD[1]|=0x18;
			break;

		case TEMPER_29:
			air_para->COD[1]|=0x1a;
			break;

		case TEMPER_30:
			air_para->COD[1]|=0x1c;
			break;

		default:
			break;
	}


	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[0]|=0x30;
			break;
		case MODE_COLD:
			air_para->COD[0]|=0x10;
			break;
		case MODE_WET:
			air_para->COD[0]|=0x40;
			break;
		case MODE_WIND:
			air_para->COD[0]|=0x50;
			break;
		case MODE_HOT:
			air_para->COD[0]|=0x20;
			break;
		default:
			break;
	}

	switch(air_status->vWind){
		case WIND_AUTO:
			air_para->COD[1]|=0x80;
			break;
		case WIND_MANUAL:
			air_para->COD[1]|=0x00;
			break;
		default:
			break;
	}


	switch(air_status->vKey){

		case POWER_KEY:
			air_para->COD[0]|=0x80;
			break;

		default:
			break;
	}

	air_para->COD[0]=HiBitFst(air_para->COD[0]);
	air_para->COD[1]=HiBitFst(air_para->COD[1]);
	air_para->COD[2]=HiBitFst(0x00);
	air_para->COD[3]=HiBitFst(0x00);
	air_para->COD[4]=HiBitFst(0x02);
	air_para->COD[5]=air_para->COD[0];
	air_para->COD[6]=air_para->COD[1];
	air_para->COD[7]=air_para->COD[2];
	air_para->COD[8]=air_para->COD[3];
	air_para->COD[9]=air_para->COD[4];
	air_para->COD[10]=air_para->COD[0];
	air_para->COD[11]=air_para->COD[1];
	air_para->COD[12]=air_para->COD[2];
	air_para->COD[13]=air_para->COD[3];
	air_para->COD[14]=air_para->COD[4];
}




/**************		TCL2	 ***************/
/*************     5518(135)        **************/
void AirRemote518(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x85;

	air_para->LDH_h=0x03;
	air_para->LDH_l=0x7b;

	air_para->LDL_h=0x03;
	air_para->LDL_l=0xa0;

	air_para->HIG_h=0x01;
	air_para->HIG_l=0x2f;

	air_para->STO_h=0x04;
	air_para->STO_l=0x94;

	air_para->BIC0=34;
	air_para->BIC1=34;
	air_para->BIC2=34;


	switch(air_status->vSpeed){
		case SPEED_AUTO:
			air_para->COD[0]|=0x0c;
			break;
		case SPEED_LOW:
			air_para->COD[0]|=0x00;
			break;
		case SPEED_MEDIUM:
			air_para->COD[0]|=0x04;
			break;
		case SPEED_HIGH:
			air_para->COD[0]|=0x08;
			break;
		default:
			break;
	}

	switch(air_status->vTemper){

		case TEMPER_16:
			air_para->COD[1]|=0x00;
			break;

		case TEMPER_17:
			air_para->COD[1]|=0x02;
			break;

		case TEMPER_18:
			air_para->COD[1]|=0x04;
			break;

		case TEMPER_19:
			air_para->COD[1]|=0x06;
			break;

		case TEMPER_20:
			air_para->COD[1]|=0x08;
			break;

		case TEMPER_21:
			air_para->COD[1]|=0x0a;
			break;

		case TEMPER_22:
			air_para->COD[1]|=0x0c;
			break;

		case TEMPER_23:
			air_para->COD[1]|=0x0e;
			break;

		case TEMPER_24:
			air_para->COD[1]|=0x10;
			break;

		case TEMPER_25:
			air_para->COD[1]|=0x12;
			break;

		case TEMPER_26:
			air_para->COD[1]|=0x14;
			break;

		case TEMPER_27:
			air_para->COD[1]|=0x16;
			break;

		case TEMPER_28:
			air_para->COD[1]|=0x18;
			break;

		case TEMPER_29:
			air_para->COD[1]|=0x1a;
			break;

		case TEMPER_30:
			air_para->COD[1]|=0x1c;
			break;

		default:
			break;
	}


	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[0]|=0x30;
			break;
		case MODE_COLD:
			air_para->COD[0]|=0x10;
			break;
		case MODE_WET:
			air_para->COD[0]|=0x40;
			break;
		case MODE_WIND:
			air_para->COD[0]|=0x50;
			break;
		case MODE_HOT:
			air_para->COD[0]|=0x20;
			break;
		default:
			break;
	}

	switch(air_status->vKey){

		case POWER_KEY:
			air_para->COD[0]|=0x80;
			break;

		default:
			break;
	}

	air_para->COD[0]=HiBitFst(air_para->COD[0]);
	air_para->COD[1]=HiBitFst(air_para->COD[1]);
	air_para->COD[2]=HiBitFst(0x00);
	air_para->COD[3]=HiBitFst(0x00);
	air_para->COD[4]=HiBitFst(0x02);
	air_para->COD[4]>>=6;
	air_para->COD[5]=air_para->COD[0];
	air_para->COD[6]=air_para->COD[1];
	air_para->COD[7]=air_para->COD[2];
	air_para->COD[8]=air_para->COD[3];
	air_para->COD[9]=air_para->COD[4];
	air_para->COD[10]=air_para->COD[0];
	air_para->COD[11]=air_para->COD[1];
	air_para->COD[12]=air_para->COD[2];
	air_para->COD[13]=air_para->COD[3];
	air_para->COD[14]=air_para->COD[4];
}



/**************		TCL2	 ***************/
/*************     5519(136)        **************/
void AirRemote519(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x85;

	air_para->LDH_h=0x03;
	air_para->LDH_l=0x7b;

	air_para->LDL_h=0x03;
	air_para->LDL_l=0xa0;

	air_para->HIG_h=0x01;
	air_para->HIG_l=0x2f;

	air_para->STO_h=0x04;
	air_para->STO_l=0x94;

	air_para->BIC0=34;
	air_para->BIC1=34;
	air_para->BIC2=34;


	switch(air_status->vSpeed){
		case SPEED_AUTO:
			air_para->COD[0]|=0x0c;
			break;
		case SPEED_LOW:
			air_para->COD[0]|=0x00;
			break;
		case SPEED_MEDIUM:
			air_para->COD[0]|=0x04;
			break;
		case SPEED_HIGH:
			air_para->COD[0]|=0x08;
			break;
		default:
			break;
	}

	switch(air_status->vTemper){

		case TEMPER_16:
			air_para->COD[1]|=0x00;
			break;

		case TEMPER_17:
			air_para->COD[1]|=0x02;
			break;

		case TEMPER_18:
			air_para->COD[1]|=0x04;
			break;

		case TEMPER_19:
			air_para->COD[1]|=0x06;
			break;

		case TEMPER_20:
			air_para->COD[1]|=0x08;
			break;

		case TEMPER_21:
			air_para->COD[1]|=0x0a;
			break;

		case TEMPER_22:
			air_para->COD[1]|=0x0c;
			break;

		case TEMPER_23:
			air_para->COD[1]|=0x0e;
			break;

		case TEMPER_24:
			air_para->COD[1]|=0x10;
			break;

		case TEMPER_25:
			air_para->COD[1]|=0x12;
			break;

		case TEMPER_26:
			air_para->COD[1]|=0x14;
			break;

		case TEMPER_27:
			air_para->COD[1]|=0x16;
			break;

		case TEMPER_28:
			air_para->COD[1]|=0x18;
			break;

		case TEMPER_29:
			air_para->COD[1]|=0x1a;
			break;

		case TEMPER_30:
			air_para->COD[1]|=0x1c;
			break;

		default:
			break;
	}


	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[0]|=0x30;
			break;
		case MODE_COLD:
			air_para->COD[0]|=0x10;
			break;
		case MODE_WET:
			air_para->COD[0]|=0x40;
			break;
		case MODE_WIND:
			air_para->COD[0]|=0x50;
			break;
		case MODE_HOT:
			air_para->COD[0]|=0x20;
			break;
		default:
			break;
	}

	switch(air_status->vWind){
		case WIND_AUTO:
			air_para->COD[1]|=0xa0;
			break;
		case WIND_MANUAL:
			air_para->COD[1]|=0x20;
			break;
		default:
			break;
	}


	switch(air_status->vKey){

		case POWER_KEY:
			air_para->COD[0]|=0x80;
			break;

		case WIND_MANUAL_KEY:
			switch(air_status->vWind){
				case WIND_AUTO:
					break;
				case WIND_MANUAL:
					air_para->COD[0]|=0x01;
					break;
				default:
					break;
			}
			break;

		case WIND_AUTO_KEY:
			switch(air_status->vWind){
				case WIND_AUTO:
					break;
				case WIND_MANUAL:
					air_para->COD[0]|=0x01;
					break;
				default:
					break;
			}
			break;

		default:
			break;
	}

	air_para->COD[0]=HiBitFst(air_para->COD[0]);
	air_para->COD[1]=HiBitFst(air_para->COD[1]);
	air_para->COD[2]=HiBitFst(0x00);
	air_para->COD[3]=HiBitFst(0x00);
	air_para->COD[4]=HiBitFst(0x02);
	air_para->COD[4]>>=6;
	air_para->COD[5]=air_para->COD[0];
	air_para->COD[6]=air_para->COD[1];
	air_para->COD[7]=air_para->COD[2];
	air_para->COD[8]=air_para->COD[3];
	air_para->COD[9]=air_para->COD[4];
	air_para->COD[10]=air_para->COD[0];
	air_para->COD[11]=air_para->COD[1];
	air_para->COD[12]=air_para->COD[2];
	air_para->COD[13]=air_para->COD[3];
	air_para->COD[14]=air_para->COD[4];
}



/**************		TCL3	 ***************/
/*************     (5520)137        **************/
void AirRemote520(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x85;

	air_para->LDH_h=0x03;
	air_para->LDH_l=0x7a;

	air_para->LDL_h=0x03;
	air_para->LDL_l=0xa0;

	air_para->HIG_h=0x01;
	air_para->HIG_l=0x2f;

	air_para->STO_h=0x04;
	air_para->STO_l=0x94;

	air_para->BIC0=40;
	air_para->BIC1=40;
	air_para->BIC2=40;


	switch(air_status->vSpeed){
		case SPEED_AUTO:
			air_para->COD[0]|=0x0c;
			break;
		case SPEED_LOW:
			air_para->COD[0]|=0x00;
			break;
		case SPEED_MEDIUM:
			air_para->COD[0]|=0x04;
			break;
		case SPEED_HIGH:
			air_para->COD[0]|=0x08;
			break;
		default:
			break;
	}

	switch(air_status->vTemper){

		case TEMPER_16:
			air_para->COD[1]|=0x00;
			break;

		case TEMPER_17:
			air_para->COD[1]|=0x02;
			break;

		case TEMPER_18:
			air_para->COD[1]|=0x04;
			break;

		case TEMPER_19:
			air_para->COD[1]|=0x06;
			break;

		case TEMPER_20:
			air_para->COD[1]|=0x8;
			break;

		case TEMPER_21:
			air_para->COD[1]|=0x0a;
			break;

		case TEMPER_22:
			air_para->COD[1]|=0x0c;
			break;

		case TEMPER_23:
			air_para->COD[1]|=0x0e;
			break;

		case TEMPER_24:
			air_para->COD[1]|=0x10;
			break;

		case TEMPER_25:
			air_para->COD[1]|=0x12;
			break;

		case TEMPER_26:
			air_para->COD[1]|=0x14;
			break;

		case TEMPER_27:
			air_para->COD[1]|=0x16;
			break;

		case TEMPER_28:
			air_para->COD[1]|=0x18;
			break;

		case TEMPER_29:
			air_para->COD[1]|=0x1a;
			break;

		case TEMPER_30:
			air_para->COD[1]|=0x1c;
			break;

		default:
			break;
	}


	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[0]|=0x30;
			break;
		case MODE_COLD:
			air_para->COD[0]|=0x10;
			break;
		case MODE_WET:
			air_para->COD[0]|=0x40;
			break;
		case MODE_WIND:
			air_para->COD[0]|=0x50;
			break;
		case MODE_HOT:
			air_para->COD[0]|=0x20;
			break;
		default:
			break;
	}

	switch(air_status->vWind){
		case WIND_AUTO:
			air_para->COD[1]|=0x80;
			break;
		case WIND_MANUAL:
			air_para->COD[1]|=0x00;
			break;
		default:
			break;
	}


	switch(air_status->vKey){

		case POWER_KEY:
			air_para->COD[0]|=0x80;
			break;

		default:
			break;
	}

	air_para->COD[0]=HiBitFst(air_para->COD[0]);
	air_para->COD[1]=HiBitFst(air_para->COD[1]);
	air_para->COD[2]=HiBitFst(0x00);
	air_para->COD[3]=HiBitFst(0x00);
	air_para->COD[4]=HiBitFst(0x0a);
	air_para->COD[5]=air_para->COD[0];
	air_para->COD[6]=air_para->COD[1];
	air_para->COD[7]=air_para->COD[2];
	air_para->COD[8]=air_para->COD[3];
	air_para->COD[9]=air_para->COD[4];
	air_para->COD[10]=air_para->COD[0];
	air_para->COD[11]=air_para->COD[1];
	air_para->COD[12]=air_para->COD[2];
	air_para->COD[13]=air_para->COD[3];
	air_para->COD[14]=air_para->COD[4];
}


/****************		 TCL4 	    ***************/
/****************        5521(138)        ******************/
void AirRemote521(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x10;

	air_para->LDH_h=0x07;
	air_para->LDH_l=0x53;

	air_para->LDL_h=0x01;
	air_para->LDL_l=0x8d;

	air_para->HIG_h=0x01;
	air_para->HIG_l=0x6e;

	air_para->ONE_h=0x00;
	air_para->ONE_l=0xb7;

	air_para->BIC0=84;

	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[0]|=0x03;
		break;

	case POWER_ON:
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
		air_para->COD[0]|=0x40;
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
		air_para->COD[1]|=0x01;
		break;

	case SPEED_MEDIUM:
		air_para->COD[1]|=0x02;
		break;

	case SPEED_HIGH:
		air_para->COD[1]|=0x03;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[2]=0x16;
		break;

	case TEMPER_17:
		air_para->COD[2]=0x17;
		break;

	case TEMPER_18:
		air_para->COD[2]=0x18;
		break;

	case TEMPER_19:
		air_para->COD[2]=0x19;
		break;

	case TEMPER_20:
		air_para->COD[2]=0x20;
		break;

	case TEMPER_21:
		air_para->COD[2]=0x21;
		break;

	case TEMPER_22:
		air_para->COD[2]=0x22;
		break;

	case TEMPER_23:
		air_para->COD[2]=0x23;
		break;

	case TEMPER_24:
		air_para->COD[2]=0x24;
		break;

	case TEMPER_25:
		air_para->COD[2]=0x25;
		break;

	case TEMPER_26:
		air_para->COD[2]=0x26;
		break;

	case TEMPER_27:
		air_para->COD[2]=0x27;
		break;

	case TEMPER_28:
		air_para->COD[2]=0x28;
		break;

	case TEMPER_29:
		air_para->COD[2]=0x29;
		break;

	case TEMPER_30:
		air_para->COD[2]=0x30;
		break;

	default:
		break;
	}

	switch(air_status->vWind){
		case WIND_AUTO:
			air_para->COD[1]|=0x70;
			break;
		case WIND_MANUAL:
			air_para->COD[1]|=0x30;
			break;
		default:
			break;
	}

	air_para->COD[3]=0x03;
	air_para->COD[4]=0x00;
	air_para->COD[5]=0x00;
	air_para->COD[6]=0x00;
	air_para->COD[7]=0x80;
	air_para->COD[8]=0x05;
	air_para->COD[9]=((((air_para->COD[0])&0x0f)+((air_para->COD[1])&0x0f)+((air_para->COD[2])&0x0f)+((air_para->COD[3])&0x0f)+((air_para->COD[4])&0x0f)+((air_para->COD[5])&0x0f)+((air_para->COD[6])&0x0f)+((air_para->COD[7])&0x0f)+((air_para->COD[8])&0x0f)+1)<<4)+1;
	air_para->COD[10]=(air_para->COD[0]>>4)+(air_para->COD[1]>>4)+(air_para->COD[2]>>4)+(air_para->COD[3]>>4)+(air_para->COD[4]>>4)+(air_para->COD[5]>>4)+(air_para->COD[6]>>4)+(air_para->COD[7]>>4)+(air_para->COD[8]>>4)+1;
}



/****************		 TCL4 	    ***************/
/****************        5522(139)        ******************/
void AirRemote522(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x10;

	air_para->LDH_h=0x07;
	air_para->LDH_l=0x53;

	air_para->LDL_h=0x01;
	air_para->LDL_l=0x8d;

	air_para->HIG_h=0x01;
	air_para->HIG_l=0x6e;

	air_para->ONE_h=0x00;
	air_para->ONE_l=0xb7;

	air_para->BIC0=84;

	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[0]|=0x05;
		break;

	case POWER_ON:
		air_para->COD[0]|=0x0a;
		break;

	default:
		break;
	}

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[0]|=0x00;
		break;

	case MODE_COLD:
		air_para->COD[0]|=0x40;
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
		air_para->COD[1]|=0x01;
		break;

	case SPEED_MEDIUM:
		air_para->COD[1]|=0x02;
		break;

	case SPEED_HIGH:
		air_para->COD[1]|=0x03;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){

	case TEMPER_16:
		air_para->COD[2]=0x16;
		break;

	case TEMPER_17:
		air_para->COD[2]=0x17;
		break;

	case TEMPER_18:
		air_para->COD[2]=0x18;
		break;

	case TEMPER_19:
		air_para->COD[2]=0x19;
		break;

	case TEMPER_20:
		air_para->COD[2]=0x20;
		break;

	case TEMPER_21:
		air_para->COD[2]=0x21;
		break;

	case TEMPER_22:
		air_para->COD[2]=0x22;
		break;

	case TEMPER_23:
		air_para->COD[2]=0x23;
		break;

	case TEMPER_24:
		air_para->COD[2]=0x24;
		break;

	case TEMPER_25:
		air_para->COD[2]=0x25;
		break;

	case TEMPER_26:
		air_para->COD[2]=0x26;
		break;

	case TEMPER_27:
		air_para->COD[2]=0x27;
		break;

	case TEMPER_28:
		air_para->COD[2]=0x28;
		break;

	case TEMPER_29:
		air_para->COD[2]=0x29;
		break;

	case TEMPER_30:
		air_para->COD[2]=0x30;
		break;

	default:
		break;
	}

	switch(air_status->vWind){
		case WIND_AUTO:
			air_para->COD[1]|=0x70;
			break;
		case WIND_MANUAL:
			air_para->COD[1]|=0x30;
			break;
		default:
			break;
	}

	air_para->COD[3]=0xa0;
	air_para->COD[4]=0xaa;
	air_para->COD[5]=0xaa;
	air_para->COD[6]=0xaa;
	air_para->COD[7]=0x9a;
	air_para->COD[8]=0x05;
	air_para->COD[9]=((((air_para->COD[0])&0x0f)+((air_para->COD[1])&0x0f)+((air_para->COD[2])&0x0f)+((air_para->COD[3])&0x0f)+((air_para->COD[4])&0x0f)+((air_para->COD[5])&0x0f)+((air_para->COD[6])&0x0f)+((air_para->COD[7])&0x0f)+((air_para->COD[8])&0x0f)+1)<<4)+1;
	air_para->COD[10]=(air_para->COD[0]>>4)+(air_para->COD[1]>>4)+(air_para->COD[2]>>4)+(air_para->COD[3]>>4)+(air_para->COD[4]>>4)+(air_para->COD[5]>>4)+(air_para->COD[6]>>4)+(air_para->COD[7]>>4)+(air_para->COD[8]>>4)+1;
}


/**************		鍗庡噷1 	 ***************/
/****************        5523(039)        ******************/
void AirRemote523(AIR_status *air_status , Air_para *air_para){
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




/**************		鏍煎姏6 subroutine		***************/
void Air_spca_4008(Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;
	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xeb;
	air_para->LDL_h=0x05;
	air_para->LDL_l=0x87;
	air_para->HIG_h=0x00;
	air_para->HIG_l=0xa9;
	air_para->ZER_h=0x00;
	air_para->ZER_l=0xb8;
	air_para->ONE_h=0x02;
	air_para->ONE_l=0x1d;
	air_para->BIC0=35;
}
void Air_mode_4008(AIR_status *air_status , Air_para *air_para){
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
}
void Air_mode_4008_1(AIR_status *air_status , Air_para *air_para){
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
		air_para->COD[0]=0x00;
		break;

	case MODE_HOT:
		air_para->COD[0]=0x03;
		break;

	default:
		break;
	}
}
void Air_wind_4008(AIR_status *air_status , Air_para *air_para){
	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[0] |= 0x40;
		break;

	case WIND_MANUAL:
		break;

	default:
		break;
	}
}
void Air_sptr_4008(AIR_status *air_status , Air_para *air_para){

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
 }
void Air_cust_4008(Air_para *air_para){
	air_para->COD[3]=0x50;
	air_para->COD[4]=0x02;
}
void Air_cust_4008_1(Air_para *air_para){
	air_para->COD[2]=0x40;
	air_para->COD[3]=0x08;
	air_para->COD[4]=0x00;
}
/******      CODE 5524(020)		*************/
void AirRemote524(AIR_status *air_status , Air_para *air_para){
	Air_spca_4008(air_para);
	Air_mode_4008_1(air_status , air_para);
	Air_wind_4008(air_status , air_para);
	Air_sptr_4008(air_status , air_para);
	Air_cust_4008_1(air_para);
}



/**************		鏍煎姏7 5 subroutine		***************/
void Air_spca_4143(Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xeb;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x87;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xa9;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xb8;

	air_para->ONE_h=0x02;
	air_para->ONE_l=0x1d;


	air_para->BIC0=52;
}
void Air_spca_4143_1(Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xeb;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x87;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xb3;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xca;

	air_para->ONE_h=0x03;
	air_para->ONE_l=0x1a;


	air_para->BIC0=52;
}
void Air_mode_4143(AIR_status *air_status , Air_para *air_para){
	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[0]=0x04;
		break;

	case MODE_COLD:
		air_para->COD[0]=0x00;
		break;

	case MODE_WET:
		air_para->COD[0]=0x01;
		break;

	case MODE_WIND:
		air_para->COD[0]=0x02;
		break;

	case MODE_HOT:
		air_para->COD[0]=0x03;
		break;

	default:
		break;
	}
}
/*
void Air_mode_4008_1(AIR_status *air_status , Air_para *air_para){
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
		air_para->COD[0]=0x00;
		break;

	case MODE_HOT:
		air_para->COD[0]=0x03;
		break;

	default:
		break;
	}
}
*/
void Air_wind_4143(AIR_status *air_status , Air_para *air_para){
	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[0] |= 0x80;
		break;

	case WIND_MANUAL:
		break;

	default:
		break;
	}
}
void Air_sptr_4143(AIR_status *air_status , Air_para *air_para){

	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[0]|=0x00;
		break;

	case SPEED_LOW:
		air_para->COD[0]|=0x30;
		break;

	case SPEED_MEDIUM:
		air_para->COD[0]|=0x20;
		break;

	case SPEED_HIGH:
		air_para->COD[0]|=0x10;
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
		air_para->COD[5]=0x00;
		break;

	case TEMPER_17:
		air_para->COD[5]=0x01;
		break;

	case TEMPER_18:
		air_para->COD[5]=0x02;
		break;

	case TEMPER_19:
		air_para->COD[5]=0x03;
		break;

	case TEMPER_20:
		air_para->COD[5]=0x04;
		break;

	case TEMPER_21:
		air_para->COD[5]=0x05;
		break;

	case TEMPER_22:
		air_para->COD[5]=0x06;
		break;

	case TEMPER_23:
		air_para->COD[5]=0x07;
		break;

	case TEMPER_24:
		air_para->COD[5]=0x08;
		break;

	case TEMPER_25:
		air_para->COD[5]=0x09;
		break;

	case TEMPER_26:
		air_para->COD[5]=0x0a;
		break;

	case TEMPER_27:
		air_para->COD[5]=0x0b;
		break;

	case TEMPER_28:
		air_para->COD[5]=0x0c;
		break;

	case TEMPER_29:
		air_para->COD[5]=0x0d;
		break;

	case TEMPER_30:
		air_para->COD[5]=0x0e;
		break;

	default:
		break;
	}
	air_para->COD[5]|=0x20;
 }
void Air_cust_4143(Air_para *air_para){
	air_para->COD[1]=0x41;
	air_para->COD[2]=0x04;
	air_para->COD[4]=0x01;
	air_para->COD[6]=0x02;
}

void Air_cust_4143_1(Air_para *air_para){
	air_para->COD[1]=0x43;
	air_para->COD[2]=0x04;
	air_para->COD[4]=0x01;
	air_para->COD[6]=0x02;
}
void Air_cust_4143_2(Air_para *air_para){
	air_para->COD[1]=0x03;
	air_para->COD[2]=0x06;
	air_para->COD[4]=0x01;
	air_para->COD[6]=0x02;
}

/**************		鏍煎姏7 		***************/
/******      CODE 5525(022)		*************/
void AirRemote525(AIR_status *air_status , Air_para *air_para){
	Air_spca_4143(air_para);
	Air_mode_4143(air_status , air_para);
	Air_wind_4143(air_status , air_para);
	Air_sptr_4143(air_status , air_para);
	Air_cust_4143(air_para);
}
/**************		鏍煎姏5 		***************/
/******      CODE 5526(023)		*************/
void AirRemote526(AIR_status *air_status , Air_para *air_para){
	Air_spca_4143_1(air_para);
	Air_mode_4143(air_status , air_para);
	Air_wind_4143(air_status , air_para);
	Air_sptr_4143(air_status , air_para);
	Air_cust_4143_1(air_para);
}
/**************		鏍煎姏5 		***************/
/******      CODE 5527(030)		*************/
void AirRemote527(AIR_status *air_status , Air_para *air_para){
	Air_spca_4143_1(air_para);
	Air_mode_4143(air_status , air_para);
	Air_wind_4143(air_status , air_para);
	Air_sptr_4143(air_status , air_para);
	Air_cust_4143_2(air_para);
}



/**************		钃濇尝2 subroutine	***************/
void Air_spca_10dd(Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;

	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xfe;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x7e;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xc1;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xb2;

	air_para->ONE_h=0x02;
	air_para->ONE_l=0x17;


	air_para->BIC0=40;
}
void Air_key_10dd(AIR_status *air_status,Air_para *air_para){
	switch(air_status->vKey){
	case POWER_KEY:
		switch(air_status->vPower)
		{
			case POWER_ON:
			air_para->COD[0]&=0x70;
			air_para->COD[0]|=0x0b;
			  break;
			case POWER_OFF:
			air_para->COD[0]^=0x0f;
				break;
			default:
				break;
		}
		break;
	default:
		break;
	}
}
void Air_mode_10dd(AIR_status *air_status,Air_para *air_para){
	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[0]=0xcc;
		break;

	case MODE_COLD:
		air_para->COD[0]=0x8c;
		break;

	case MODE_WET:
		air_para->COD[0]=0xac;
		break;

	case MODE_WIND:
		air_para->COD[0]=0xbc;
		break;

	case MODE_HOT:
		air_para->COD[0]=0x9c;
		break;

	default:
		break;
	}
}
void Air_sptp_10dd(AIR_status *air_status,Air_para *air_para){
	switch(air_status->vSpeed){
	
	case SPEED_AUTO:
		air_para->COD[1]=0x30;
		break;

	case SPEED_LOW:
		air_para->COD[1]=0x20;
		break;

	case SPEED_MEDIUM:
		air_para->COD[1]=0x30;
		break;

	case SPEED_HIGH:
		air_para->COD[1]=0x40;
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
}

void Air_cust_10dd(Air_para *air_para){
	air_para->COD[2]=0x04;
	air_para->COD[3]=0x10;
	air_para->COD[4]=0xdd;
	
}

/**************		钃濇尝2		***************/
/******      5528(024)		*************/
void AirRemote528(AIR_status *air_status , Air_para *air_para){
	Air_spca_10dd(air_para);
	Air_sptp_10dd(air_status,air_para);
	Air_mode_10dd(air_status,air_para);
	Air_key_10dd(air_status,air_para);
	Air_cust_10dd(air_para);
}


/**************		鏍煎姏9 subroutine		***************/
void Air_spca_2050(Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x22;
	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xfd;
	air_para->LDL_h=0x05;
	air_para->LDL_l=0x7b;
	air_para->HIG_h=0x00;
	air_para->HIG_l=0xc0;
	air_para->ZER_h=0x00;
	air_para->ZER_l=0xb3;
	air_para->ONE_h=0x02;
	air_para->ONE_l=0x0b;
	air_para->STO_h=0x18;
	air_para->STO_l=0x88;
	air_para->BIC0=35;
	air_para->BIC1=32;
}
void Air_spca_2050_1(Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;

	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xeb;
	
	air_para->LDL_h=0x05;
	air_para->LDL_l=0x71;
	
	air_para->HIG_h=0x00;
	air_para->HIG_l=0xba;
	
	air_para->ZER_h=0x00;
	air_para->ZER_l=0xb7;
	
	air_para->ONE_h=0x02;
	air_para->ONE_l=0x0f;

	air_para->BIC0=43;
}
void Air_mode_2050(AIR_status *air_status , Air_para *air_para){
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
}

void Air_wind_2050_1(AIR_status *air_status , Air_para *air_para){
	switch(air_status->vWind){
	
	case WIND_AUTO:
		air_para->COD[4] = 0x06;
		break;

	case WIND_MANUAL:
		switch(air_status->vManualWind){
		case MANUAL_WIND_1:
			air_para->COD[4]=0x00;
			break;
		case MANUAL_WIND_2:
			air_para->COD[4]=0x01;
			break;
		case MANUAL_WIND_3:
			air_para->COD[4]=0x02;
			break;
		case MANUAL_WIND_4:
			air_para->COD[4]=0x03;
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}
	air_para->COD[4] |= 0x50;
}

void Air_wind_2050(AIR_status *air_status , Air_para *air_para){
	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[0] |= 0x40;
		air_para->COD[5] = 0x01;
		break;

	case WIND_MANUAL:
		switch(air_status->vManualWind){
		case MANUAL_WIND_1:
			air_para->COD[5]=0x02;
			break;
		case MANUAL_WIND_2:
			air_para->COD[5]=0x03;
			break;
		case MANUAL_WIND_3:
			air_para->COD[5]=0x04;
			break;
		case MANUAL_WIND_4:
			air_para->COD[5]=0x05;
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}
}
void Air_sptr_2050(AIR_status *air_status , Air_para *air_para){
	
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
 }

void Air_cust_2050_1(Air_para *air_para){
	air_para->COD[3]=0x50;
	air_para->COD[4]=0x02;
	air_para->COD[6]=0x20;
	air_para->COD[8]=air_para->COD[1]+air_para->COD[0];
	air_para->COD[8]-=4;
	air_para->COD[8]<<=4;
}
	
void Air_cust_2050_2(Air_para *air_para){
	air_para->COD[3]=0x10;
	air_para->COD[5]=0x02;
}

/**************		鏍煎姏9 		***************/
/******      CODE 5529(027)		*************/
void AirRemote529(AIR_status *air_status , Air_para *air_para){
	Air_spca_2050(air_para);
	Air_mode_2050(air_status , air_para);
	Air_wind_2050(air_status , air_para);
	Air_sptr_2050(air_status , air_para);
	Air_cust_2050_1(air_para);
}
/**************		鏍煎姏10 		***************/
/******      CODE 5530(029)		*************/
void AirRemote530(AIR_status *air_status , Air_para *air_para){
	Air_spca_2050_1(air_para);
	Air_mode_2050(air_status , air_para);
	Air_wind_2050_1(air_status , air_para);
	Air_sptr_2050(air_status , air_para);
	Air_cust_2050_2(air_para);
}



/**************		鏍煎姏8 subroutine		***************/
void Air_spca_e004(Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x02;

	air_para->LDH_h=0x04;
	air_para->LDH_l=0x4d;
	
	air_para->LDL_h=0x02;
	air_para->LDL_l=0x20;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0x88;
	
	air_para->ZER_h=0x00;
	air_para->ZER_l=0x85;
	
	air_para->ONE_h=0x01;
	air_para->ONE_l=0x97;

	air_para->STO_h=0x0c;
	air_para->STO_l=0x3a;

	air_para->BIC0=64;
	air_para->BIC1=152;
}
void Air_mode_e004(AIR_status *air_status , Air_para *air_para){
	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[13]=0x00;
		break;

	case MODE_COLD:
		air_para->COD[13]=0x30;
		break;

	case MODE_WET:
		air_para->COD[13]=0x20;
		break;

	case MODE_WIND:
		air_para->COD[13]=0x60;
		break;

	case MODE_HOT:
		air_para->COD[13]=0x40;
		break;

	default:
		break;
	}
}


void Air_wind_e004(AIR_status *air_status , Air_para *air_para){
	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[16] = 0x0f;
		break;

	case WIND_MANUAL:
		switch(air_status->vManualWind){
		case MANUAL_WIND_1:
			air_para->COD[16]=0x01;
			break;
		case MANUAL_WIND_2:
			air_para->COD[16]=0x02;
			break;
		case MANUAL_WIND_3:
			air_para->COD[16]=0x03;
			break;
		case MANUAL_WIND_4:
			air_para->COD[16]=0x04;
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}
}
void Air_sptr_e004(AIR_status *air_status , Air_para *air_para){
	
	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[16]|=0xa0;
		break;

	case SPEED_LOW:
		air_para->COD[16]|=0x30;
		break;

	case SPEED_MEDIUM:
		air_para->COD[16]|=0x50;
		break;

	case SPEED_HIGH:
		air_para->COD[16]|=0x70;
		break;

	default:
		break;
	}
	

	switch(air_status->vPower){

	case POWER_ON:
		air_para->COD[13]++;
		break;

	default:
		break;
	}

	switch(air_status->vTemper){
	
	case TEMPER_16:
		air_para->COD[14]=0x20;
		break;

	case TEMPER_17:
		air_para->COD[14]=0x22;
		break;

	case TEMPER_18:
		air_para->COD[14]=0x24;
		break;

	case TEMPER_19:
		air_para->COD[14]=0x26;
		break;

	case TEMPER_20:
		air_para->COD[14]=0x28;
		break;

	case TEMPER_21:
		air_para->COD[14]=0x2a;
		break;

	case TEMPER_22:
		air_para->COD[14]=0x2c;
		break;

	case TEMPER_23:
		air_para->COD[14]=0x2e;
		break;

	case TEMPER_24:
		air_para->COD[14]=0x30;
		break;

	case TEMPER_25:
		air_para->COD[14]=0x32;
		break;

	case TEMPER_26:
		air_para->COD[14]=0x34;
		break;

	case TEMPER_27:
		air_para->COD[14]=0x36;
		break;

	case TEMPER_28:
		air_para->COD[14]=0x38;
		break;

	case TEMPER_29:
		air_para->COD[14]=0x3a;
		break;

	case TEMPER_30:
		air_para->COD[14]=0x3c;
		break;

	default:
		break;
	}
 }
void Air_cust_e004(Air_para *air_para){
	air_para->COD[0]=0x02;
	air_para->COD[1]=0x20;
	air_para->COD[2]=0xe0;
	air_para->COD[3]=0x04;
	air_para->COD[7]=0x06;
	air_para->COD[8]=0x02;
	air_para->COD[9]=0x20;
	air_para->COD[10]=0xe0;
	air_para->COD[11]=0x04;
	air_para->COD[15]=0x80;
	air_para->COD[19]=0x06;
	air_para->COD[20]=0x60;
	air_para->COD[23]=0x80;
	air_para->COD[25]=0x06;
	air_para->COD[26]=air_para->COD[13]+air_para->COD[14]+air_para->COD[16];
	air_para->COD[26]+=0x72;
}

/**************		鏍煎姏8 (000)		***************/
/******      CODE 5531(036)		*************/
void AirRemote531(AIR_status *air_status , Air_para *air_para){
	Air_spca_e004(air_para);
	Air_mode_e004(air_status , air_para);
	Air_wind_e004(air_status , air_para);
	Air_sptr_e004(air_status , air_para);
	Air_cust_e004(air_para);
}


/**************		鏉句笅1(973) 	 ***************/
/****************        5532(037)        ******************/
void AirRemote532(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x06;

	air_para->LDH_h=0x04;
	air_para->LDH_l=0x46;

	air_para->LDL_h=0x04;
	air_para->LDL_l=0x46;
	
	air_para->HIG_h=0x01;
	air_para->HIG_l=0x0a;
	
	air_para->ZER_h=0x01;
	air_para->ZER_l=0x0a;
	
	air_para->ONE_h=0x03;
	air_para->ONE_l=0x0d;

	air_para->STO_h=0x10;
	air_para->STO_l=0xa6;

	air_para->BIC0=32;
	air_para->BIC1=32;
	air_para->BIC2=32;
	air_para->BIC3=32;
	
	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[2]=0x0e;
		break;

	case MODE_COLD:
		air_para->COD[2]=0x0a;
		break;

	case MODE_WET:
		air_para->COD[2]=0x0b;
		break;

	case MODE_WIND:
		air_para->COD[2]=0x08;
		break;

	case MODE_HOT:
		air_para->COD[2]=0x0c;
		break;

	default:
		break;
	}
	
	switch(air_status->vSpeed){

	case SPEED_AUTO:
		air_para->COD[0]|=0xf0;
		break;

	case SPEED_LOW:
		air_para->COD[0]|=0x20;
		break;

	case SPEED_MEDIUM:
		air_para->COD[0]|=0x40;
		break;

	case SPEED_HIGH:
		air_para->COD[0]|=0x60;
		break;

	default:
		break;
	}
	
	switch(air_status->vTemper){
	
	case TEMPER_16:
		air_para->COD[0]|=0x01;
		break;

	case TEMPER_17:
		air_para->COD[0]|=0x02;
		break;

	case TEMPER_18:
		air_para->COD[0]|=0x03;
		break;

	case TEMPER_19:
		air_para->COD[0]|=0x04;
		break;

	case TEMPER_20:
		air_para->COD[0]|=0x05;
		break;

	case TEMPER_21:
		air_para->COD[0]|=0x06;
		break;

	case TEMPER_22:
		air_para->COD[0]|=0x07;
		break;

	case TEMPER_23:
		air_para->COD[0]|=0x08;
		break;

	case TEMPER_24:
		air_para->COD[0]|=0x09;
		break;

	case TEMPER_25:
		air_para->COD[0]|=0x0a;
		break;

	case TEMPER_26:
		air_para->COD[0]|=0x0b;
		break;

	case TEMPER_27:
		air_para->COD[0]|=0x0c;
		break;

	case TEMPER_28:
		air_para->COD[0]|=0x0d;
		break;

	case TEMPER_29:
		air_para->COD[0]|=0x0e;
		break;

	case TEMPER_30:
		air_para->COD[0]|=0x0f;
		break;

	default:
		break;
	}

	switch(air_status->vKey){
	
		case POWER_KEY:
			air_para->COD[2]&=0xf7;
			break;
			
		default:
			break;
	}
	
	air_para->COD[1]=air_para->COD[0];
	air_para->COD[3]=air_para->COD[2];
	air_para->COD[4]=air_para->COD[0];
	air_para->COD[5]=air_para->COD[1];
	air_para->COD[6]=air_para->COD[2];
	air_para->COD[7]=air_para->COD[3];
	air_para->COD[8]=0xf4;
	air_para->COD[9]=0xf4;
	air_para->COD[10]=0x36;
	air_para->COD[11]=0x36;
	air_para->COD[12]=0xf4;
	air_para->COD[13]=0xf4;
	air_para->COD[14]=0x36;
	air_para->COD[15]=0x36;
}




/**************		娴峰皵5 subroutine	***************/
void Air_spca_0e0f(Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x32;

	air_para->LDH_h=0x03;
	air_para->LDH_l=0xda;
	
	air_para->LDL_h=0x05;
	air_para->LDL_l=0x3b;
	
	air_para->HIG_h=0x00;
	air_para->HIG_l=0xab;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xae;

	air_para->ONE_h=0x02;
	air_para->ONE_l=0x00;

	air_para->STO_h=0x2e;
	air_para->STO_l=0xfc;

	air_para->BIC0=56;
	air_para->BIC1=56;
		
	air_para->COD[4] = 0x0f;
}
void Air_sptr_0e0f(AIR_status *air_status , Air_para *air_para){
	switch(air_status->vSpeed){
	
	case SPEED_AUTO:
		air_para->COD[3]=0x0f;
		break;
		
	case SPEED_LOW:
		air_para->COD[3]=0x3c;
		break;
		
	case SPEED_MEDIUM:
		air_para->COD[3]=0x2d;
		break;
		
	case SPEED_HIGH:
		air_para->COD[3]=0x1e;
		break;
		
	default:
		break;
	}
	switch(air_status->vTemper){
	
	case TEMPER_16:
		air_para->COD[5]=0x0f;
		break;
		
	case TEMPER_17:
		air_para->COD[5]=0x1e;
		break;
		
	case TEMPER_18:
		air_para->COD[5]=0x2d;
		break;
		
	case TEMPER_19:
		air_para->COD[5]=0x3c;
		break;
		
	case TEMPER_20:
		air_para->COD[5]=0x4b;
		break;
		
	case TEMPER_21:
		air_para->COD[5]=0x5a;
		break;
		
	case TEMPER_22:
		air_para->COD[5]=0x69;
		break;
		
	case TEMPER_23:
		air_para->COD[5]=0x78;
		break;
		
	case TEMPER_24:
		air_para->COD[5]=0x87;
		break;
		
	case TEMPER_25:
		air_para->COD[5]=0x96;
		break;
		
	case TEMPER_26:
		air_para->COD[5]=0xa5;
		break;
		
	case TEMPER_27:
		air_para->COD[5]=0xb4;
		break;
		
	case TEMPER_28:
		air_para->COD[5]=0xc3;
		break;

	case TEMPER_29:
		air_para->COD[5]=0xd2;
		break;

	case TEMPER_30:
		air_para->COD[5]=0xe1;
		break;

	default:
		break;
	}
}
/*
void Air_mode_f007(AIR_status *air_status , Air_para *air_para){
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
		air_para->COD[4]|=0x27;
		break;

	case MODE_HOT:
		air_para->COD[4]|=0x30;
		break;

	default:
		break;
	}
}
*/
void Air_mode_0e0f_1(AIR_status *air_status , Air_para *air_para){
 	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[2] = 0xc3;
		break;
	case MODE_COLD:
		air_para->COD[2] = 0x4b;
		break;
	case MODE_WET:
		air_para->COD[2] = 0x87;
		break;
	case MODE_WIND:
		air_para->COD[2] = 0x87;
		break;
	case MODE_HOT:
		air_para->COD[2] = 0xc3;
		break;
	default:
		break;
	}
}
void Air_pwr_0e0f(AIR_status *air_status , Air_para *air_para){
	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[2]=0x0f;
		break;

	case POWER_ON:

		break;

	default:
		break;
	}
}
/*
void Air_key_0e0f(AIR_status *air_status , Air_para *air_para){
 	switch(air_status->vKey){
	case POWER_KEY:
		air_para->COD[2]=0xfd;
		air_para->COD[4]=0x00;
		break;
	case WIND_MANUAL_KEY:
	case WIND_AUTO_KEY:
		air_para->COD[2]=0xf0;
		air_para->COD[4]=0x07;
	 	air_para->STRU=0x00;
		break;
	default:
		break;
	}
}
*/
/*
void Air_wind_f007(AIR_status *air_status , Air_para *air_para){
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
}
*/
/*
void Air_wind_f007_1(AIR_status *air_status , Air_para *air_para){
	if(air_status->vKey==WIND_MANUAL_KEY||air_status->vKey==WIND_AUTO_KEY){
	air_para->COD[4]=0x07;
	air_para->COD[2]=0xf0;
	air_para->STRU=0x00;
	}
}
*/
void Air_wind_0e0f_2(AIR_status *air_status , Air_para *air_para){
	if(air_status->vKey==WIND_MANUAL_KEY||air_status->vKey==WIND_AUTO_KEY){
	air_para->COD[4]=0x4b;
	}
}
void Air_cust_0e0f(Air_para *air_para){
	air_para->COD[0] = 0x0e;
	air_para->COD[1] = 0xf1;
	air_para->COD[6] = 0x0f;
	air_para->COD[7]=air_para->COD[0];
	air_para->COD[8]=air_para->COD[1];
	air_para->COD[9]=air_para->COD[2];
	air_para->COD[10]=air_para->COD[3];
	air_para->COD[11]=air_para->COD[4];
	air_para->COD[12]=air_para->COD[5];
	air_para->COD[13]=air_para->COD[6];
}

/**************		娴峰皵 5 (000)	***************/
/*************    5533( 001)        **************/
void AirRemote533(AIR_status *air_status , Air_para *air_para){
	Air_spca_0e0f(air_para);
 	Air_sptr_0e0f(air_status,air_para);
	Air_mode_0e0f_1(air_status,air_para);
	Air_pwr_0e0f(air_status,air_para);
	Air_wind_0e0f_2(air_status,air_para);
	Air_cust_0e0f(air_para);
	HBarray(14,air_para);
}



/**************		娴峰皵6	subroutine	***************/
void Air_spca_1900(Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x20;

	air_para->LDH_h=0x03;
	air_para->LDH_l=0xda;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x3b;
	
	air_para->HIG_h=0x00;
	air_para->HIG_l=0xab;
	
	air_para->ZER_h=0x00;
	air_para->ZER_l=0xae;
	
	air_para->ONE_h=0x02;
	air_para->ONE_l=0x00;

	air_para->BIC0=72;
}
	
void Air_mode_1900(AIR_status *air_status , Air_para *air_para){
	switch(air_status->vMode){
	case MODE_AUTO:
		break;
		
	case MODE_COLD:
		air_para->COD[6]=0x20;
		break;
		
	case MODE_WET:
		air_para->COD[6]=0x40;
		break;

	case MODE_WIND:
		air_para->COD[6]=0x80;
		break;
		
	case MODE_HOT:
		air_para->COD[6]=0x60;
		break;
		
	default:
		break;
	}
}
void Air_key_1900(AIR_status *air_status , Air_para *air_para){
	switch(air_status->vKey){
	case POWER_KEY:

	if(air_status->vPower == POWER_ON)
 		air_para->COD[1]|=0x01;

		break;
	case SPEED_KEY:
		air_para->COD[1]|=0x03;
		break;
	case MODE_KEY:
		air_para->COD[1]|=0x02;
		break;
	case WIND_MANUAL_KEY:
		air_para->COD[1]|=0x05;
		break;
	case WIND_AUTO_KEY:
		air_para->COD[1]|=0x04;
		break;
	case TEMPER_INC_KEY:
		air_para->COD[1]|=0x06;
		break;
	case TEMPER_DEC_KEY:
		air_para->COD[1]|=0x07;
		break;
	default:
		break;
	}
}
void Air_sptr_1900(AIR_status *air_status , Air_para *air_para){
	switch(air_status->vSpeed){
	
	case SPEED_AUTO:
		air_para->COD[5]=0x00;
		break;
		
	case SPEED_LOW:
		air_para->COD[5]=0xc0;
		break;
		
	case SPEED_MEDIUM:
		air_para->COD[5]=0x80;
		break;
		
	case SPEED_HIGH:
		air_para->COD[5]=0x40;
		break;
		
	default:
		break;
	}
	
	switch(air_status->vTemper){
	
	case TEMPER_16:
		air_para->COD[1]=0x00;
		break;
		
	case TEMPER_17:
		air_para->COD[1]=0x10;
		break;
		
	case TEMPER_18:
		air_para->COD[1]=0x20;
		break;

	case TEMPER_19:
		air_para->COD[1]=0x30;
		break;
		
	case TEMPER_20:
		air_para->COD[1]=0x40;
		break;
		
	case TEMPER_21:
		air_para->COD[1]=0x50;
		break;

	case TEMPER_22:
		air_para->COD[1]=0x60;
		break;
		
	case TEMPER_23:
		air_para->COD[1]=0x70;
		break;
		
	case TEMPER_24:
		air_para->COD[1]=0x80;
		break;
		
	case TEMPER_25:
		air_para->COD[1]=0x90;
		break;
		
	case TEMPER_26:
		air_para->COD[1]=0xa0;
		break;
		
	case TEMPER_27:
		air_para->COD[1]=0xb0;
		break;

	case TEMPER_28:
		air_para->COD[1]=0xc0;
		break;
		
	case TEMPER_29:
		air_para->COD[1]=0xd0;
		break;
		
	case TEMPER_30:
		air_para->COD[1]=0xe0;
		break;
		
	default:
		break;
	}
}
void Air_wind_1900(AIR_status *air_status , Air_para *air_para){
	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[2]=0x00;
		//air_para->COD[3]|=0x40;
		break;
		
	case WIND_MANUAL:
		air_para->COD[2]=0x20;
/*
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
*/
		break;

	default:
		break;
	}
}
void Air_cust_1900(Air_para *air_para){
	air_para->COD[0]=0xa5;
	air_para->COD[3]=0x19;

}
void Air_cust_1900_1(Air_para *air_para){
	air_para->COD[0]=0xa5;
	air_para->COD[3]=0x33;
}


/**************		娴峰皵6 	***************/
/*************     5534(002)        **************/
void AirRemote534(AIR_status *air_status , Air_para *air_para){
	Air_spca_1900(air_para);
	Air_sptr_1900(air_status , air_para);
	Air_key_1900(air_status , air_para);
	Air_mode_1900(air_status , air_para);
	Air_wind_1900(air_status , air_para);
	Air_cust_1900(air_para);
	air_para->COD[8]=Sumarray(8,air_para);
	HBarray(9,air_para);
}
/*************     5535(012)        **************/
void AirRemote535(AIR_status *air_status , Air_para *air_para){
	Air_spca_1900(air_para);
	Air_sptr_1900(air_status , air_para);
	Air_key_1900(air_status , air_para);
	Air_mode_1900(air_status , air_para);
	Air_wind_1900(air_status , air_para);
	Air_cust_1900_1(air_para);
	air_para->COD[8]=Sumarray(8,air_para);
	HBarray(9,air_para);
}




/**************		娴峰皵7	subroutine	***************/
void Air_spca_a602(Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x20;

	air_para->LDH_h=0x03;
	air_para->LDH_l=0xda;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x3b;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xab;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xae;
	
	air_para->ONE_h=0x02;
	air_para->ONE_l=0x00;

	air_para->BIC0=112;
}
	
void Air_mode_a602(AIR_status *air_status , Air_para *air_para){
	switch(air_status->vMode){
	case MODE_AUTO:
		break;
		
	case MODE_COLD:
		air_para->COD[7]=0x20;
		break;
		
	case MODE_WET:
		air_para->COD[7]=0x40;
		break;
		
	case MODE_WIND:
		air_para->COD[7]=0xc0;
		break;
		
	case MODE_HOT:
		air_para->COD[7]=0x80;
		break;
		
	default:
		break;
	}
}
void Air_pwr_a602(AIR_status *air_status , Air_para *air_para){
	switch(air_status->vPower){
	case POWER_ON:
		air_para->COD[4]|=0x40;
		break;
	case POWER_OFF:
		break;
	default:
		break;
	}
}
void Air_pwr_a602_1(AIR_status *air_status , Air_para *air_para){
	air_para->COD[4] = 0x15;
	Air_pwr_a602(air_status , air_para);
}
void Air_pwr_a602_2(AIR_status *air_status , Air_para *air_para){
	air_para->COD[4] = 0x12;
	Air_pwr_a602(air_status , air_para);
}
void Air_pwr_a602_3(AIR_status *air_status , Air_para *air_para){
	air_para->COD[4] = 0x10;
	Air_pwr_a602(air_status , air_para);
}
void Air_pwr_a602_4(AIR_status *air_status , Air_para *air_para){
	air_para->COD[4] = 0x05;
	Air_pwr_a602(air_status , air_para);
}
void Air_pwr_a602_5(AIR_status *air_status , Air_para *air_para){
	air_para->COD[4] = 0x2a;
	Air_pwr_a602(air_status , air_para);
}
void Air_pwr_a602_6(AIR_status *air_status , Air_para *air_para){
	air_para->COD[4] = 0x24;
	Air_pwr_a602(air_status , air_para);
}
void Air_pwr_a602_7(AIR_status *air_status , Air_para *air_para){
	air_para->COD[4] = 0x3b;
	Air_pwr_a602(air_status , air_para);
}
void Air_pwr_a602_8(AIR_status *air_status , Air_para *air_para){
	air_para->COD[4] = 0x3a;
	Air_pwr_a602(air_status , air_para);
}
void Air_key_a602(AIR_status *air_status , Air_para *air_para){
	switch(air_status->vKey){
	case POWER_KEY:
 		air_para->COD[12]=0x05;
		break;
	case SPEED_KEY:
		air_para->COD[12]=0x04;
		break;
	case MODE_KEY:
		air_para->COD[12]=0x06;
		break;
	case WIND_MANUAL_KEY:
		air_para->COD[12]=0x02;
		break;
	case WIND_AUTO_KEY:
		air_para->COD[12]=0x02;
		break;
	case TEMPER_INC_KEY:
		air_para->COD[12]=0x00;
		break;
	case TEMPER_DEC_KEY:
		air_para->COD[12]=0x01;
		break;
	default:
		break;
	}
}
void Air_sptr_a602(AIR_status *air_status , Air_para *air_para){
	switch(air_status->vSpeed){
	
	case SPEED_AUTO:
		air_para->COD[5]=0xa0;
		break;

	case SPEED_LOW:
		air_para->COD[5]=0x60;
		break;
		
	case SPEED_MEDIUM:
		air_para->COD[5]=0x40;
		break;
		
	case SPEED_HIGH:
		air_para->COD[5]=0x20;
		break;

	default:
		break;
	}
	
	switch(air_status->vTemper){
	
	case TEMPER_16:
		air_para->COD[1]=0x00;
		break;

	case TEMPER_17:
		air_para->COD[1]=0x10;
		break;
		
	case TEMPER_18:
		air_para->COD[1]=0x20;
		break;
		
	case TEMPER_19:
		air_para->COD[1]=0x30;
		break;
		
	case TEMPER_20:
		air_para->COD[1]=0x40;
		break;
		
	case TEMPER_21:
		air_para->COD[1]=0x50;
		break;
		
	case TEMPER_22:
		air_para->COD[1]=0x60;
		break;

	case TEMPER_23:
		air_para->COD[1]=0x70;
		break;
		
	case TEMPER_24:
		air_para->COD[1]=0x80;
		break;
		
	case TEMPER_25:
		air_para->COD[1]=0x90;
		break;
		
	case TEMPER_26:
		air_para->COD[1]=0xa0;
		break;
		
	case TEMPER_27:
		air_para->COD[1]=0xb0;
		break;
		
	case TEMPER_28:
		air_para->COD[1]=0xc0;
		break;

	case TEMPER_29:
		air_para->COD[1]=0xd0;
		break;
		
	case TEMPER_30:
		air_para->COD[1]=0xe0;
		break;

	default:
		break;
	}
}
void Air_mWind_a602(AIR_status *air_status , Air_para *air_para){
	switch(air_status->vManualWind){
	case MANUAL_WIND_1:
		air_para->COD[1]|=0x08;
		break;
	case MANUAL_WIND_2:
		air_para->COD[1]|=0x02;
		break;
	case MANUAL_WIND_3:
		air_para->COD[1]|=0x04;
		break;
	case MANUAL_WIND_4:
		air_para->COD[1]|=0x06;
		break;
	default:
		break;
	}
}
void Air_wind_a602_1(AIR_status *air_status , Air_para *air_para){
	switch(air_status->vWind){
	
	case WIND_AUTO:
		air_para->COD[2]=0xe0;
		air_para->COD[1]|=0x0c;
		break;
		
	case WIND_MANUAL:
		Air_mWind_a602(air_status , air_para);
		air_para->COD[2]=air_para->COD[1];
		air_para->COD[2]<<=4;
		break;

	default:
		break;
	}
}
void Air_wind_a602_2(AIR_status *air_status , Air_para *air_para){
	switch(air_status->vWind){
	
	case WIND_AUTO:
		air_para->COD[2]=0xe0;
		break;
		
	case WIND_MANUAL:
		Air_mWind_a602(air_status , air_para);
		break;

	default:
		break;
	}
}
void Air_wind_a602_3(AIR_status *air_status , Air_para *air_para){
	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[1]|=0x0c;
		break;
		
	case WIND_MANUAL:
		Air_mWind_a602(air_status , air_para);
		break;

	default:
		break;
	}
}
void Air_wind_a602_4(AIR_status *air_status , Air_para *air_para){
	Air_wind_a602_1(air_status,air_para);
	air_para->COD[2]+=3;
}
void Air_wind_a602_5(AIR_status *air_status , Air_para *air_para){
	Air_wind_a602_2(air_status,air_para);
	air_para->COD[2]+=3;
}
void Air_cust_a602_0(Air_para *air_para){
	air_para->COD[0]=0xa6;
	air_para->COD[12]=0x05;
}
void Air_cust_a602(Air_para *air_para){
	Air_cust_a602_0(air_para);
	air_para->COD[9]=0x80;
}
void Air_cust_a602_1(Air_para *air_para){
	air_para->COD[3]=0x02;
	Air_cust_a602(air_para);
}
void Air_cust_a602_2(Air_para *air_para){
	air_para->COD[2]=0x63;
	Air_cust_a602_1(air_para);
}


/**************		娴峰皵7 	***************/
/*************     5536(003)        **************/
void AirRemote536(AIR_status *air_status , Air_para *air_para){
	Air_spca_a602(air_para);
	Air_sptr_a602(air_status , air_para);
	Air_mode_a602(air_status , air_para);
	Air_wind_a602_1(air_status , air_para);
	Air_pwr_a602_1(air_status , air_para);
	Air_cust_a602_1(air_para);
	Air_key_a602(air_status , air_para);
	air_para->COD[13]=Sumarray(13,air_para);
	HBarray(14,air_para);
}
/*************     5537(004)        **************/
void AirRemote537(AIR_status *air_status , Air_para *air_para){
	Air_spca_a602(air_para);
	Air_sptr_a602(air_status , air_para);
	Air_mode_a602(air_status , air_para);
	Air_wind_a602_1(air_status , air_para);
	Air_pwr_a602_2(air_status , air_para);
	Air_cust_a602(air_para);
	Air_key_a602(air_status , air_para);
	air_para->COD[13]=Sumarray(13,air_para);
	HBarray(14,air_para);
}
/*************     5538(005)        **************/
void AirRemote538(AIR_status *air_status , Air_para *air_para){
	Air_spca_a602(air_para);
	Air_sptr_a602(air_status , air_para);
	Air_mode_a602(air_status , air_para);
	Air_wind_a602_2(air_status , air_para);
	Air_pwr_a602_3(air_status , air_para);
	Air_cust_a602(air_para);
	Air_key_a602(air_status , air_para);
	air_para->COD[13]=Sumarray(13,air_para);
	HBarray(14,air_para);
}
/*************     5539(007)        **************/
void AirRemote539(AIR_status *air_status , Air_para *air_para){
	Air_spca_a602(air_para);
	Air_sptr_a602(air_status , air_para);
	Air_mode_a602(air_status , air_para);
	Air_wind_a602_2(air_status , air_para);
	Air_pwr_a602_4(air_status , air_para);
	Air_cust_a602_0(air_para);
	Air_key_a602(air_status , air_para);
	air_para->COD[13]=Sumarray(13,air_para);
	HBarray(14,air_para);
}
/*************     5540(008)        **************/
void AirRemote540(AIR_status *air_status , Air_para *air_para){
	Air_spca_a602(air_para);
	Air_sptr_a602(air_status , air_para);
	Air_mode_a602(air_status , air_para);
	Air_wind_a602_3(air_status , air_para);
	Air_pwr_a602_5(air_status , air_para);
	Air_cust_a602_2(air_para);
	Air_key_a602(air_status , air_para);
	air_para->COD[13]=Sumarray(13,air_para);
	HBarray(14,air_para);
}
/*************     5541(013)        **************/
void AirRemote541(AIR_status *air_status , Air_para *air_para){
	Air_spca_a602(air_para);
	Air_sptr_a602(air_status , air_para);
	Air_mode_a602(air_status , air_para);
	Air_wind_a602_4(air_status , air_para);
	Air_pwr_a602_6(air_status , air_para);
	Air_cust_a602_1(air_para);
	Air_key_a602(air_status , air_para);
	air_para->COD[13]=Sumarray(13,air_para);
	HBarray(14,air_para);
}
/*************     5542(014)        **************/
void AirRemote542(AIR_status *air_status , Air_para *air_para){
	Air_spca_a602(air_para);
	Air_sptr_a602(air_status , air_para);
	Air_mode_a602(air_status , air_para);
	Air_wind_a602_2(air_status , air_para);
	Air_pwr_a602_7(air_status , air_para);
	Air_cust_a602(air_para);
	Air_key_a602(air_status , air_para);
	air_para->COD[13]=Sumarray(13,air_para);
	HBarray(14,air_para);
}
/*************     5543(016)        **************/
void AirRemote543(AIR_status *air_status , Air_para *air_para){
	Air_spca_a602(air_para);
	Air_sptr_a602(air_status , air_para);
	Air_mode_a602(air_status , air_para);
	Air_wind_a602_5(air_status , air_para);
	Air_pwr_a602_8(air_status , air_para);
	Air_cust_a602(air_para);
	Air_key_a602(air_status , air_para);
	air_para->COD[13]=Sumarray(13,air_para);
	HBarray(14,air_para);
}




/**************		娴峰皵9	subroutine	***************/
void Air_spca_a60a(Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x20;

	air_para->LDH_h=0x03;
	air_para->LDH_l=0xda;
	
	air_para->LDL_h=0x05;
	air_para->LDL_l=0x3b;
	
	air_para->HIG_h=0x00;
	air_para->HIG_l=0xab;
	
	air_para->ZER_h=0x00;
	air_para->ZER_l=0xae;
	
	air_para->ONE_h=0x02;
	air_para->ONE_l=0x00;

	air_para->BIC0=88;
}
	
void Air_mode_a60a(AIR_status *air_status , Air_para *air_para){
	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[6]=0x00;
		break;
		
	case MODE_COLD:
		air_para->COD[6]=0x20;
		break;
		
	case MODE_WET:
		air_para->COD[6]=0x80;
		break;
		
	case MODE_WIND:
		air_para->COD[6]=0x60;
		break;
		
	case MODE_HOT:
		air_para->COD[6]=0x40;
		break;
		
	default:
		break;
	}
}
void Air_pwr_a60a(AIR_status *air_status , Air_para *air_para){
	switch(air_status->vPower){
	case POWER_ON:
		air_para->COD[1]|=0x01;
		break;
	case POWER_OFF:
		break;
	default:
		break;
	}
}
void Air_sptr_a60a(AIR_status *air_status , Air_para *air_para){
	switch(air_status->vSpeed){
	
	case SPEED_AUTO:
		air_para->COD[4]=0xa0;
		break;
		
	case SPEED_LOW:
		air_para->COD[4]=0x60;
		break;
		
	case SPEED_MEDIUM:
		air_para->COD[4]=0x40;
		break;
		
	case SPEED_HIGH:
		air_para->COD[4]=0x20;
		break;
		
	default:
		break;
	}
	
	switch(air_status->vTemper){
	
	case TEMPER_16:
		air_para->COD[1]=0x00;
		break;
		
	case TEMPER_17:
		air_para->COD[1]=0x10;
		break;
		
	case TEMPER_18:
		air_para->COD[1]=0x20;
		break;
		
	case TEMPER_19:
		air_para->COD[1]=0x30;
		break;
		
	case TEMPER_20:
		air_para->COD[1]=0x40;
		break;
		
	case TEMPER_21:
		air_para->COD[1]=0x50;
		break;
		
	case TEMPER_22:
		air_para->COD[1]=0x60;
		break;
		
	case TEMPER_23:
		air_para->COD[1]=0x70;
		break;
		
	case TEMPER_24:
		air_para->COD[1]=0x80;
		break;
		
	case TEMPER_25:
		air_para->COD[1]=0x90;
		break;
		
	case TEMPER_26:
		air_para->COD[1]=0xa0;
		break;
		
	case TEMPER_27:
		air_para->COD[1]=0xb0;
		break;
		
	case TEMPER_28:
		air_para->COD[1]=0xc0;
		break;
		
	case TEMPER_29:
		air_para->COD[1]=0xd0;
		break;
		
	case TEMPER_30:
		air_para->COD[1]=0xe0;
		break;
		
	default:
		break;
	}
}
void Air_wind_a60a(AIR_status *air_status , Air_para *air_para){
	switch(air_status->vWind){
	
	case WIND_AUTO:
		air_para->COD[2]|=0x20;
		break;

	case WIND_MANUAL:
		break;

	default:
		break;
	}
}
void Air_wind_a60a_1(AIR_status *air_status , Air_para *air_para){
	//air_para->COD[1]=0x03;
	Air_wind_a60a(air_status , air_para);
}
void Air_cust_a60a_0(Air_para *air_para){
	air_para->COD[0]=0xa6;
	air_para->COD[7]=0x00;
}
void Air_cust_a60a(Air_para *air_para){
	Air_cust_a60a_0(air_para);
	air_para->COD[3]=0x0a;
}
void Air_cust_a60a_1(Air_para *air_para){
	Air_cust_a60a_0(air_para);
	air_para->COD[3]=0x34;
}

/**************		娴峰皵9 	***************/
/*************     5544(006)        **************/
void AirRemote544(AIR_status *air_status , Air_para *air_para){
	Air_spca_a60a(air_para);
	Air_sptr_a60a(air_status , air_para);
	Air_mode_a60a(air_status , air_para);
	Air_wind_a60a(air_status , air_para);
	Air_pwr_a60a(air_status , air_para);
	Air_cust_a60a(air_para);
	air_para->COD[10]=Sumarray(10,air_para);
	HBarray(11,air_para);
}
/*************     5545(015)        **************/
void AirRemote545(AIR_status *air_status , Air_para *air_para){
	Air_spca_a60a(air_para);
	Air_sptr_a60a(air_status , air_para);
	Air_mode_a60a(air_status , air_para);
	Air_wind_a60a_1(air_status , air_para);
	Air_pwr_a60a(air_status , air_para);
	Air_cust_a60a_1(air_para);
	air_para->COD[10]=Sumarray(10,air_para);
	HBarray(11,air_para);
}


/**************		娴峰皵10 subroutine	***************/
void Air_spca_00aa(Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0x4c;
	
	air_para->LDL_h=0x04;
	air_para->LDL_l=0xd2;
	
	air_para->HIG_h=0x00;
	air_para->HIG_l=0xf4;
	
	air_para->ZER_h=0x00;
	air_para->ZER_l=0x95;
												  
	air_para->ONE_h=0x01;
	air_para->ONE_l=0xcf;

									  
	air_para->BIC0=40;
}
void Air_key_00aa(AIR_status *air_status,Air_para *air_para){
	switch(air_status->vKey){
	case POWER_KEY:
		air_para->COD[0]&=0xf0;
		air_para->COD[0]|=0x03;
		break;
	default:
		break;
	}
}
void Air_mode_00aa(AIR_status *air_status,Air_para *air_para){
	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[0]|=0x4c;
		break;
		
	case MODE_COLD:
		air_para->COD[0]|=0x0c;
		break;
		
	case MODE_WET:
		air_para->COD[0]|=0x1c;
		break;
		
	case MODE_WIND:
		air_para->COD[0]|=0x2c;
		break;
		
	case MODE_HOT:
		air_para->COD[0]|=0x3c;
		break;
		
	default:
		break;
	}

}
void Air_sptp_00aa(AIR_status *air_status,Air_para *air_para){

	switch(air_status->vPower)
	{
		case POWER_ON:
			air_para->COD[0]|=0x80;
			break;
		case POWER_OFF:
			break;
		default:
			break;
	}

	switch(air_status->vWind){

		case WIND_AUTO:
			air_para->COD[2]=0x8c;
			break;

		case WIND_MANUAL:
			air_para->COD[2]=0x0c;
			break;

		default:
			break;
	}

	switch(air_status->vSpeed){
	
	case SPEED_AUTO:
		air_para->COD[1]=0x00;
		break;
		
	case SPEED_LOW:
		air_para->COD[1]=0x20;
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
}

void Air_cust_00aa(Air_para *air_para){
	air_para->COD[4]=0xaa;
	
}
/**************		娴峰皵10		***************/
/******      5546(010)		*************/
void AirRemote546(AIR_status *air_status , Air_para *air_para){
	Air_spca_00aa(air_para);
	Air_sptp_00aa(air_status,air_para);
	Air_mode_00aa(air_status,air_para);
	Air_key_00aa(air_status,air_para);
	Air_cust_00aa(air_para);
}



/**************		娴峰皵2 	 ***************/
/****************        5547(009)        ******************/
void AirRemote547(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x11;

	air_para->LDH_h=0x00;
	air_para->LDH_l=0xa4;
	
	air_para->LDL_h=0x04;
	air_para->LDL_l=0x07;
	
	air_para->HIG_h=0x00;
	air_para->HIG_l=0xa4;
	
	air_para->ZER_h=0x00;
	air_para->ZER_l=0xa4;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0xd4;

	air_para->STO_h=0x04;
	air_para->STO_l=0x22;

	air_para->BIC0=52;

	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[0]=0x80;
		break;

	case POWER_ON:
		air_para->COD[0]=0x83;
		break;

	default:
		break;
	}
	
	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[5]=0x30;
		break;
		
	case MODE_COLD:
		air_para->COD[5]=0x10;
		break;
		
	case MODE_WET:
		air_para->COD[5]=0x30;
		break;
		
	case MODE_WIND:
		air_para->COD[5]=0x40;
		break;
		
	case MODE_HOT:
		air_para->COD[5]=0x20;
		break;
		
	default:
		break;
	}
	
	switch(air_status->vSpeed){
	
	case SPEED_AUTO:
		air_para->COD[4]=0x00;
		break;
		
	case SPEED_LOW:
		air_para->COD[4]=0x02;
		break;
		
	case SPEED_MEDIUM:
		air_para->COD[4]=0x02;
		break;
		
	case SPEED_HIGH:
		air_para->COD[4]=0x01;
		break;
		
	default:
		break;
	}
	switch(air_status->vWind){
	case WIND_AUTO:
		air_para->COD[4]|=0x04;
		break;
	case WIND_MANUAL:
		break;
	default:
		break;
	}
	switch(air_status->vTemper){
	
	case TEMPER_16:
		break;
		
	case TEMPER_17:
		air_para->COD[5]|=0x01;
		break;
		
	case TEMPER_18:
		air_para->COD[5]|=0x02;
		break;
		
	case TEMPER_19:
		air_para->COD[5]|=0x03;
		break;
		
	case TEMPER_20:
		air_para->COD[5]|=0x04;
		break;
		
	case TEMPER_21:
		air_para->COD[5]|=0x05;
		break;
		
	case TEMPER_22:
		air_para->COD[5]|=0x06;
		break;
		
	case TEMPER_23:
		air_para->COD[5]|=0x07;
		break;
		
	case TEMPER_24:
		air_para->COD[5]|=0x08;
		break;
		
	case TEMPER_25:
		air_para->COD[5]|=0x09;
		break;
		
	case TEMPER_26:
		air_para->COD[5]|=0x0a;
		break;
		
	case TEMPER_27:
		air_para->COD[5]|=0x0b;
		break;
		
	case TEMPER_28:
		air_para->COD[5]|=0x0c;
		break;
		
	case TEMPER_29:
		air_para->COD[5]|=0x0d;
		break;
		
	case TEMPER_30:
		air_para->COD[5]|=0x0e;
		break;
		
	default:
		break;
	}
	
	air_para->COD[6]=NSarray(6,air_para);
	HBarray(8,air_para);
	air_para->COD[6]>>=4;
	air_para->COD[6]=~(air_para->COD[6]);

}
#endif



/**************		缇庣殑4	***************/
/*************     5548(040)        **************/
void AirRemote548(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x21;

	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xfc;
	
	air_para->LDL_h=0x05;
	air_para->LDL_l=0x7e;
	
	air_para->HIG_h=0x00;
	air_para->HIG_l=0xbb;
	
	air_para->ZER_h=0x00;
	air_para->ZER_l=0xbb;
	
	air_para->ONE_h=0x01;
	air_para->ONE_l=0xfb;

	air_para->STO_h=0x01;
	air_para->STO_l=0x70;

	air_para->BIC0=40;

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


/**************		缇庣殑3 subroutine	***************/
void Air_spca_1212(Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;

	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xdd;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0xaa;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0x9e;
	
	air_para->ZER_h=0x00;
	air_para->ZER_l=0xe0;

	air_para->ONE_h=0x02;
	air_para->ONE_l=0x33;


	air_para->BIC0=88;
}
void Air_key_1212(AIR_status *air_status,Air_para *air_para){
	switch(air_status->vKey){
		
	case WIND_MANUAL_KEY:
		
	case WIND_AUTO_KEY:
		air_para->COD[2]=0x02;
		break;
		
	default:
		break;
	}
}
void Air_pwr_1212(AIR_status *air_status,Air_para *air_para){
	switch(air_status->vPower){
	
	case POWER_OFF:
		air_para->COD[0]^=0x8f;
		break;
		
	default:
		break;
	}
}
void Air_mode_1212(AIR_status *air_status,Air_para *air_para){
	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[0]=0xcc;
		break;
		
	case MODE_COLD:
		air_para->COD[0]=0x8c;
		break;
		
	case MODE_WET:
		air_para->COD[0]=0xac;
		break;
		
	case MODE_WIND:
		air_para->COD[0]=0xbc;
		break;
		
	case MODE_HOT:
		air_para->COD[0]=0x9c;
		break;
		
	default:
		break;
	}
}
void Air_sptp_1212(AIR_status *air_status,Air_para *air_para){
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
}

void Air_cust_1212(Air_para *air_para){
	air_para->COD[4]=0x20;
	air_para->COD[7]=0x12;
	air_para->COD[9]=0x12;
	air_para->COD[10]=0xaa;
}

/**************		缇庣殑3	***************/
/******      5549(041)		*************/
void AirRemote549(AIR_status *air_status , Air_para *air_para){
	Air_spca_1212(air_para);
	Air_sptp_1212(air_status,air_para);
	Air_key_1212(air_status,air_para);
	Air_pwr_1212(air_status,air_para);
	Air_mode_1212(air_status,air_para);
	Air_cust_1212(air_para);
}


/**************		涓滆姖1 subroutine	***************/
void Air_spca_f007(Air_para *air_para){
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
}
void Air_sptr_f007(AIR_status *air_status , Air_para *air_para){
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
}
void Air_mode_f007(AIR_status *air_status , Air_para *air_para){
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
		air_para->COD[4]|=0x27;
		break;
		
	case MODE_HOT:
		air_para->COD[4]|=0x30;
		break;
		
	default:
		break;
	}
}
void Air_mode_f007_1(AIR_status *air_status , Air_para *air_para){
 	switch(air_status->vMode){
	case MODE_AUTO: 
		air_para->COD[4] |= 0x90;
		break;
	case MODE_COLD: 
		air_para->COD[4] |= 0x80;
		break;
	case MODE_WET: 					
		air_para->COD[4] |= 0xa0;
		break;
	case MODE_WIND: 
		air_para->COD[4] |= 0xa0;
		break;
	case MODE_HOT:
		air_para->COD[4] |=	0xb0;
		break;
	default:
		break;
	}
}
void Air_pwr_f007(AIR_status *air_status , Air_para *air_para){
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
}
void Air_key_f007(AIR_status *air_status , Air_para *air_para){
 	switch(air_status->vKey){
	case POWER_KEY: 
		air_para->COD[2]=0xfd;
		air_para->COD[4]=0x00;
		break;
	case WIND_MANUAL_KEY: 
	case WIND_AUTO_KEY: 
		air_para->COD[2]=0xf0;
		air_para->COD[4]=0x07;
	 	air_para->STRU=0x00;
		break;
	default:
		break;
	}
}
/*
void Air_wind_f007(AIR_status *air_status , Air_para *air_para){
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
}
*/
void Air_wind_f007_1(AIR_status *air_status , Air_para *air_para){
	if(air_status->vKey==WIND_MANUAL_KEY||air_status->vKey==WIND_AUTO_KEY){
	air_para->COD[4]=0x07;
	air_para->COD[2]=0xf0;
	air_para->STRU=0x00;
	}
}
void Air_wind_f007_2(AIR_status *air_status , Air_para *air_para){
	if(air_status->vKey==WIND_MANUAL_KEY||air_status->vKey==WIND_AUTO_KEY){
	air_para->COD[4]=0x07;
	air_para->COD[2]=0xd6;
	}
}
void Air_cust_f007(Air_para *air_para){
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
/**************		涓滆姖1 	***************/
/*************     5550(045)        **************/
void AirRemote550(AIR_status *air_status , Air_para *air_para){
	Air_spca_f007(air_para);
 	Air_sptr_f007(air_status,air_para);
	Air_mode_f007(air_status,air_para);
	Air_pwr_f007(air_status,air_para);
	Air_wind_f007_1(air_status,air_para);
	Air_cust_f007(air_para);
}
/*************     5551(047)        **************/
void AirRemote551(AIR_status *air_status , Air_para *air_para){
	Air_spca_f007(air_para);
 	Air_sptr_f007(air_status,air_para);
	Air_mode_f007(air_status,air_para);
	Air_pwr_f007(air_status,air_para);
	Air_wind_f007_2(air_status,air_para);
	Air_cust_f007(air_para);
}
/*************     5552(048)        **************/
void AirRemote552(AIR_status *air_status , Air_para *air_para){
	Air_spca_f007(air_para);
 	Air_sptr_f007(air_status,air_para);
	Air_mode_f007_1(air_status,air_para);
	Air_key_f007(air_status,air_para);
	Air_cust_f007(air_para);
}


/**************		鏂拌 subroutine	 ***************/
void Air_sptr_6a73(AIR_status *air_status,Air_para *air_para){
 	switch(air_status->vSpeed){
	
	case SPEED_AUTO:
		air_para->COD[4]=0x00;
		break;
		
	case SPEED_LOW:
		air_para->COD[4]=0x02;
		break;
		
	case SPEED_MEDIUM:
		air_para->COD[4]=0x03;
		break;
		
	case SPEED_HIGH:
		air_para->COD[4]=0x01;
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

}
void Air_spca_6a73(AIR_status *air_status,Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0x50;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x07;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0x9a;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xaf;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0xe2;


	air_para->BIC0=72;

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
	Air_sptr_6a73(air_status,air_para);
	air_para->COD[0] = 0x6a;
}
void Air_spca_2a2c(AIR_status *air_status,Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0x4b;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x0d;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xc3;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0x96;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0xd6;


	air_para->BIC0=120;
	Air_sptr_6a73(air_status,air_para);
	air_para->COD[0]=0x56;
	air_para->COD[13]=0x01;

}
void Air_spca_6a7e(AIR_status *air_status,Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0a;
	air_para->LDH_l=0x32;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x05;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0x9a;
	
	air_para->ZER_h=0x00;
	air_para->ZER_l=0xaf;
	
	air_para->ONE_h=0x01;
	air_para->ONE_l=0xf6;


	air_para->BIC0=48;
	Air_sptr_6a73(air_status,air_para);
	air_para->COD[0]=0x6a;
	air_para->COD[5]=0x09;
	if(air_status->vWind == WIND_MANUAL)
		air_para->COD[5]-=1;
	if(air_status->vPower == POWER_OFF){
		air_para->COD[1] = 0x60;
		air_para->COD[5]-=4;
	}

}
void Air_mode_6a73(AIR_status *air_status , Air_para *air_para){
	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[4]|=0x40;
		break;
		
	case MODE_COLD:
		air_para->COD[4]|=0x20;
		break;
		
	case MODE_WET:
		air_para->COD[4]|=0x30;
		break;
		
	case MODE_WIND:
		air_para->COD[4]|=0x50;
		break;
		
	case MODE_HOT:
		air_para->COD[4]|=0x10;
		break;
		
	default:
		break;
	}
}
void Air_mode_6a7e(AIR_status *air_status , Air_para *air_para){
	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[4]|=0x20;
		break;
		
	case MODE_COLD:
		air_para->COD[4]|=0x10;
		break;
		
	case MODE_WET:
		air_para->COD[4]|=0x40;
		break;
		
	case MODE_WIND:
		air_para->COD[4]|=0x00;
		break;
		
	case MODE_HOT:
		air_para->COD[4]|=0x30;
		break;
		
	default:
		break;
	}
}
void Air_mode_6a7e_1(AIR_status *air_status,Air_para *air_para){
 	Air_mode_6a7e(air_status,air_para);
	if(air_para->COD[4]&0xf0 == 0x20)
		air_para->COD[2] = 0x79;
	if(air_para->COD[4]&0xf0 == 0x30)
		air_para->COD[2] = 0x6d;
}
void Air_key_2a2c(AIR_status *air_status,Air_para *air_para){
	switch(air_status->vKey){

	case POWER_KEY:
		if(air_status->vPower == POWER_OFF)
			air_para->COD[5]=0xc0;
		break;
	case WIND_MANUAL_KEY:
	case WIND_AUTO_KEY:
		air_para->COD[5] = 0x02;
		break;
	default:
		break;
	}
}
void Air_key_2a2c_1(AIR_status *air_status,Air_para *air_para){
	switch(air_status->vKey){

	case POWER_KEY:
		if(air_status->vPower == POWER_OFF)
			air_para->COD[5]=0xc0;
		break;
	case WIND_AUTO_KEY:
		air_para->COD[5] = 0x03;
		break;
	case WIND_MANUAL_KEY:
		air_para->COD[5] = 0x02;
		break;
	default:
		break;
	}
}
void Air_mode_6a73_1(AIR_status *air_status , Air_para *air_para){
	Air_mode_6a73(air_status,air_para);
	if(air_para->COD[4]&0xf0 == 0x10)
		air_para->COD[2]=0x4c;
}
void Air_mode_6a73_2(AIR_status *air_status , Air_para *air_para){
	Air_mode_6a73(air_status,air_para);
	if(air_para->COD[4]&0xf0 == 0x10)
		air_para->COD[2]=0x47;
}
void Air_wind_6a73_3(AIR_status *air_status , Air_para *air_para){
 	switch(air_status->vWind){
	case WIND_AUTO:
		air_para->COD[5] |= 0x08;
		break;
	case WIND_MANUAL:
		break;
	default:
		break;
	}
}
void Air_wind_6a73_2(AIR_status *air_status , Air_para *air_para){
 	switch(air_status->vWind){
	case WIND_AUTO:
		break;
	case WIND_MANUAL:
		air_para->COD[5] |= 0x04;
		break;
	default:
		break;
	}
}
void Air_wind_6a73_1(AIR_status *air_status , Air_para *air_para){
	switch(air_status->vWind){
	
	case WIND_AUTO:
		break;
		
	case WIND_MANUAL:

		switch(air_status->vManualWind){
		case MANUAL_WIND_1:
			air_para->COD[5]|=0x02;
			break;
		case MANUAL_WIND_2:
			air_para->COD[8]|=0x03;
			break;
		case MANUAL_WIND_3:
			air_para->COD[8]|=0x04;
			break;
		case MANUAL_WIND_4:
			air_para->COD[8]|=0x05;
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}
}

//void Air_cust_6a73_1(Air_para *air_para){
//	air_para->COD[0]=0x6a;
//	air_para->COD[2]=0x73;
//}
//void Air_cust_6a73_2(Air_para *air_para){
//	air_para->COD[0]=0x6a;
//	air_para->COD[2]=0x54;
//}
//void Air_cust_6a73_3(Air_para *air_para){
//	air_para->COD[0] = 0x6a;
//	air_para->COD[2] = 0x55;
//}
//void Air_cust_6a73_4(Air_para *air_para){
//	air_para->COD[0] = 0x6a;
//	air_para->COD[2] = 0x5b;
//}

/**************		鏂拌 	 ***************/
/************     5553(060)       *********************/
void AirRemote553(AIR_status *air_status , Air_para *air_para){
	Air_spca_6a73(air_status,air_para);
	Air_wind_6a73_1(air_status , air_para);
	air_para->COD[2]=0x73;
	Air_mode_6a73(air_status,air_para);
	//Air_cust_6a73_1(air_para);
	air_para->COD[8]=NSarray(8,air_para);

}
/************     5554(065)       *********************/
void AirRemote554(AIR_status *air_status , Air_para *air_para){
 	Air_spca_6a73(air_status,air_para);
	Air_wind_6a73_1(air_status , air_para);
	air_para->COD[2]=0x54;
	Air_mode_6a73(air_status,air_para);
	//Air_cust_6a73_2(air_para);
	air_para->COD[8]=NSarray(8,air_para);
}
/************     5555(067)       *********************/
void AirRemote555(AIR_status *air_status , Air_para *air_para){
 	Air_spca_6a73(air_status , air_para);
	Air_wind_6a73_2(air_status , air_para);
	air_para->COD[2]=0x55;
	Air_mode_6a73(air_status,air_para);
	//Air_cust_6a73_3(air_para);
	air_para->COD[8] = NSarray(8 , air_para);
}
/************     5556(077)       *********************/
void AirRemote556(AIR_status *air_status , Air_para *air_para){
 	Air_spca_6a73(air_status , air_para);
	Air_wind_6a73_1(air_status , air_para);
	air_para->COD[2]=0x5b;
	Air_mode_6a73_1(air_status,air_para);
	//Air_cust_6a73_4(air_para);
	air_para->COD[5] |= 0x08;
	air_para->COD[8] = NSarray(8 , air_para);
}
/************     5557(078)       *********************/
void AirRemote557(AIR_status *air_status , Air_para *air_para){
 	Air_spca_6a73(air_status , air_para);
	Air_wind_6a73_3(air_status , air_para);
	air_para->COD[2]=0x5b;
	Air_mode_6a73_1(air_status,air_para);
	air_para->COD[8] = NSarray(8 , air_para);
}
/************     5558(079)       *********************/
void AirRemote558(AIR_status *air_status , Air_para *air_para){
 	Air_spca_6a73(air_status , air_para);
	Air_wind_6a73_1(air_status , air_para);
	air_para->COD[2]=0x5b;
	Air_mode_6a73_2(air_status , air_para);
	air_para->COD[8] = NSarray(8 , air_para);
}


/**************		闀胯櫣2 subroutine	***************/
void Air_spca_1251(Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0b;
	air_para->LDH_l=0x01;

	air_para->LDL_h=0x05;
	air_para->LDL_l=0x69;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xdf;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0x99;

	air_para->ONE_h=0x02;
	air_para->ONE_l=0x02;


	air_para->BIC0=84;
}
void Air_spca_1251_1(Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;


	air_para->LDH_h=0x0b;
	air_para->LDH_l=0x01;
	
	air_para->LDL_h=0x05;
	air_para->LDL_l=0x69;
	
	air_para->HIG_h=0x00;
	air_para->HIG_l=0xbd;
	
	air_para->ZER_h=0x00;
	air_para->ZER_l=0xae;

	air_para->ONE_h=0x02;
	air_para->ONE_l=0x19;


	air_para->BIC0=84;
}
void Air_key_1251_1(AIR_status *air_status,Air_para *air_para){
	switch(air_status->vKey){

	case POWER_KEY:
		air_para->COD[0]=0x0c;
		break;

	case MODE_KEY:
		air_para->COD[0]=0x0b;
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
		air_para->COD[0]=0x08;
		break;

	case WIND_AUTO_KEY:
		air_para->COD[0]=0x06;
		break;

	default:
		break;
	}
}
void Air_key_1251_2(AIR_status *air_status,Air_para *air_para){
	switch(air_status->vKey){

	case POWER_KEY:
		air_para->COD[0]=0x0c;
		break;

	case MODE_KEY:
		air_para->COD[0]=0x0b;
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
}
void Air_mode_1251(AIR_status *air_status,Air_para *air_para){
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
}
void Air_mode_1251_1(AIR_status *air_status,Air_para *air_para){
	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[0]|=0x40;
		break;
		
	case MODE_COLD:
		air_para->COD[0]|=0x60;
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
}
void Air_spwr_1251(AIR_status *air_status,Air_para *air_para){
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
		air_para->COD[1]|=0x00;
		break;
		
	case TEMPER_18:
		air_para->COD[1]|=0x00;
		break;
		
	case TEMPER_19:
		air_para->COD[1]|=0x01;
		break;
		
	case TEMPER_20:
		air_para->COD[1]|=0x02;
		break;
		
	case TEMPER_21:
		air_para->COD[1]|=0x03;
		break;
		
	case TEMPER_22:
		air_para->COD[1]|=0x04;
		break;
		
	case TEMPER_23:
		air_para->COD[1]|=0x05;
		break;
		
	case TEMPER_24:
		air_para->COD[1]|=0x06;
		break;
		
	case TEMPER_25:
		air_para->COD[1]|=0x07;
		break;
		
	case TEMPER_26:
		air_para->COD[1]|=0x08;
		break;
		
	case TEMPER_27:
		air_para->COD[1]|=0x09;
		break;
		
	case TEMPER_28:
		air_para->COD[1]|=0x0a;
		break;
		
	case TEMPER_29:
		air_para->COD[1]|=0x0b;
		break;
		
	case TEMPER_30:
		air_para->COD[1]|=0x0c;
		break;
		
	default:
		break;
	}

	air_para->COD[2] = 0x30;
	switch(air_status->vWind){
	
	case WIND_AUTO:
		air_para->COD[2] |= 0x08;
		break;
		
	case WIND_MANUAL:

		break;

	default:
		break;
	}
}
void Air_cust_1251(Air_para *air_para){
	air_para->COD[5]=0x32;
	air_para->COD[7]=0x92;
	air_para->COD[8]=0x20;
	air_para->COD[9]=0x39;
	air_para->COD[10]=0x03;
}
void Air_cust_1251_1(Air_para *air_para){
	//air_para->COD[3]=0x00;
	air_para->COD[4]=0x31;
	Air_cust_1251(air_para);
}
void Air_cust_1251_2(Air_para *air_para){
	//air_para->COD[3]=0x00;
	air_para->COD[4]=0x01;
	Air_cust_1251(air_para);

}
void Air_cust_1251_3(Air_para *air_para){
	air_para->COD[4]=0x41;
	air_para->COD[5]=0x31;
	air_para->COD[7]=0x12;
	air_para->COD[8]=0x20;
	air_para->COD[9]=0x51;
	air_para->COD[10]=0x05;
}
void Air_cust_1251_4(Air_para *air_para){
	air_para->COD[4]=0x41;
	Air_cust_1251(air_para);
}
/**************		闀胯櫣2		***************/
/******      5559(070)		*************/
void AirRemote559(AIR_status *air_status , Air_para *air_para){
	Air_spca_1251(air_para);
	Air_key_1251_2(air_status,air_para);
	Air_spwr_1251(air_status,air_para);
	Air_mode_1251_1(air_status,air_para);
//	Air_sptp_1251(air_status,air_para);
//	Air_wind_1251(air_status,air_para);
	Air_cust_1251_1(air_para);
}
/******      5560(071)		*************/
void AirRemote560(AIR_status *air_status , Air_para *air_para){
	Air_spca_1251_1(air_para);
	Air_key_1251_1(air_status,air_para);
	Air_spwr_1251(air_status,air_para);
	Air_mode_1251(air_status,air_para);
//	Air_sptp_1251(air_status,air_para);
//	Air_wind_1251(air_status,air_para);
	Air_cust_1251_1(air_para);
}
/******      5561(072)		*************/
void AirRemote561(AIR_status *air_status , Air_para *air_para){
	Air_spca_1251_1(air_para);
	Air_key_1251_2(air_status,air_para);
	Air_spwr_1251(air_status,air_para);
	Air_mode_1251(air_status,air_para);
//	Air_sptp_1251(air_status,air_para);
//	Air_wind_1251(air_status,air_para);
	Air_cust_1251_3(air_para);
}
/******      5562(073)		*************/
void AirRemote562(AIR_status *air_status , Air_para *air_para){
	Air_spca_1251(air_para);
	Air_key_1251_1(air_status,air_para);
	Air_spwr_1251(air_status,air_para);
	Air_mode_1251(air_status,air_para);
//	Air_sptp_1251(air_status,air_para);
//	Air_wind_1251(air_status,air_para);
	Air_cust_1251_4(air_para);
}



/**************		闀胯櫣3 	 ***************/
/****************       5563(062)        ******************/
void AirRemote563(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;

	air_para->LDH_h=0x04;
	air_para->LDH_l=0xf3;
	
	air_para->LDL_h=0x01;
	air_para->LDL_l=0xef;
	
	air_para->HIG_h=0x00;
	air_para->HIG_l=0xa2;
	
	air_para->ZER_h=0x00;
	air_para->ZER_l=0xa0;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0x3a;

	air_para->BIC0=96;

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
		air_para->COD[2]=0x03;
		break;
		
	case MODE_HOT:
		air_para->COD[2]=0x04;
		break;
		
	default:
		break;
	}
	
	switch(air_status->vSpeed){
	
	case SPEED_AUTO:
		air_para->COD[2]|=0x00;
		break;
		
	case SPEED_LOW:
		air_para->COD[2]|=0x10;
		break;
		
	case SPEED_MEDIUM:
		air_para->COD[2]|=0x20;
		break;
		
	case SPEED_HIGH:
		air_para->COD[2]|=0x30;
		break;

	default:
		break;
	}

	switch(air_status->vPower){

	case POWER_OFF:
		air_para->COD[2]|=0x00;
		break;

	case POWER_ON:
		air_para->COD[2]|=0x80;
		break;
		
	default:
		break;
	}
	
	switch(air_status->vTemper){
	
	case TEMPER_16:
		air_para->COD[3]=0x00;
		break;
		
	case TEMPER_17:
		air_para->COD[3]=0x01;
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
	air_para->COD[3]|=0x10;

	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[4]=0x02;
		break;
		
	case WIND_MANUAL:
		air_para->COD[4]=0x00;
		break;

	default:
		break;
	}

	air_para->COD[0]=0x1a;
	air_para->COD[6]=0x1c;
	air_para->COD[9]=0x0c;

	air_para->COD[11]=Sumarray(11,air_para);
	HBarray(12,air_para);
}


/**************		闀胯櫣4	 ***************/
/************     5564(063)       *********************/
void AirRemote564(AIR_status *air_status , Air_para *air_para){
	Air_spca_2a2c(air_status,air_para);
	Air_mode_6a73(air_status,air_para);
	Air_key_2a2c(air_status,air_para);
	air_para->COD[12]=0x2a;
	air_para->COD[14]=NSarray(14,air_para);
	
}
/************     5565(064)       *********************/
void AirRemote565(AIR_status *air_status , Air_para *air_para){
 	Air_spca_2a2c(air_status,air_para);
	air_para->COD[12]=0x2f;
	Air_mode_6a73(air_status,air_para);
	Air_key_2a2c_1(air_status,air_para);
	air_para->COD[14]=NSarray(14,air_para);
}


/**************		涓夎彵1 subroutine	 ***************/
void Air_spca_4000(Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;

	air_para->LDH_h=0x04;
	air_para->LDH_l=0x47;
	
	air_para->LDL_h=0x01;
	air_para->LDL_l=0xf3;
	
	air_para->HIG_h=0x00;
	air_para->HIG_l=0x91;
	
	air_para->ZER_h=0x00;
	air_para->ZER_l=0x76;
	
	air_para->ONE_h=0x01;
	air_para->ONE_l=0x80;


	air_para->BIC0=136;
}
void Air_pwr_4000(AIR_status *air_status,Air_para *air_para){
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
}
void Air_mode_4000(AIR_status *air_status,Air_para *air_para){
	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[6]|=0x80;
		break;
		
	case MODE_COLD:
		air_para->COD[5]=0x80;
		break;
		
	case MODE_WET:
		air_para->COD[5]=0xc0;
		break;
		
	case MODE_WIND:
		break;
		
	case MODE_HOT:
		air_para->COD[5]=0x40;
		break;
		
	default:
		break;
	}

}
void Air_mode_4000_1(AIR_status *air_status , Air_para *air_para){
 	air_para->COD[7] = 0xf7;
	Air_mode_4000(air_status,air_para);
	if(air_para->COD[5]&0xf0 == 0x40)
		air_para->COD[7] = 0xd6;
}
void Air_sptr_4000(AIR_status *air_status,Air_para *air_para){
	switch(air_status->vSpeed){
	
	case SPEED_AUTO:
		air_para->COD[5]=0x00;
		break;
		
	case SPEED_LOW:
		air_para->COD[5]=0x08;
		break;
		
	case SPEED_MEDIUM:
		air_para->COD[5]=0x0c;
		break;
		
	case SPEED_HIGH:
		air_para->COD[5]=0x04;
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
}
void Air_wnmn_4000(AIR_status *air_status , Air_para *air_para){
		switch(air_status->vManualWind){
		case MANUAL_WIND_1:
			air_para->COD[13]=0x02;
			break;
		case MANUAL_WIND_2:
			air_para->COD[13]=0x03;
			break;
		case MANUAL_WIND_3:
			air_para->COD[13]=0x04;
			break;
		case MANUAL_WIND_4:
			air_para->COD[13]=0x05;
			break;
		default:
			break;
		}
}
void Air_wind_4000_1(AIR_status *air_status,Air_para *air_para){
	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[13]=0x07;
		break;

	case WIND_MANUAL:

		Air_wnmn_4000(air_status,air_para);
		break;

	default:
		break;
	}
}
void Air_wind_4000_2(AIR_status *air_status,Air_para *air_para){
	switch(air_status->vWind){

	case WIND_AUTO:
		air_para->COD[13]=0x01;
		break;

	case WIND_MANUAL:
		Air_wnmn_4000(air_status,air_para);
		break;

	default:
		break;
	}
}
void Air_key_4000(AIR_status *air_status,Air_para *air_para){
	switch(air_status->vKey){

	case POWER_KEY:
		air_para->COD[5]|=0x01;
		if(air_status->vPower == POWER_ON)
			air_para->COD[5]++;
		break;
	case WIND_MANUAL_KEY:
	case WIND_AUTO_KEY:
		air_para->COD[13] |= 0x08;
		break;
	default:
		break;
	}
}
void Air_cust_4000(Air_para *air_para){
	air_para->COD[0]=0x40;
	air_para->COD[1]=0x00;
	air_para->COD[2]=0x14;
	air_para->COD[3]=0x80;
	air_para->COD[4]=0x43;
	air_para->COD[10]=0x68;
}
void Air_cust_4000_1(Air_para *air_para){
	Air_cust_4000(air_para);
	air_para->COD[7]=0xec;
}
void Air_cust_4000_2(Air_para *air_para){
	Air_cust_4000(air_para);
	air_para->COD[7]=0x46;
}
/**************		涓夎彵1 	 ***************/
/****************        5566(061)        ******************/
void AirRemote566(AIR_status *air_status , Air_para *air_para){
	Air_spca_4000(air_para);
	Air_pwr_4000(air_status,air_para);
	Air_sptr_4000(air_status,air_para);
	Air_mode_4000(air_status,air_para);
	Air_wind_4000_1(air_status,air_para);
	Air_key_4000(air_status,air_para);
	Air_cust_4000_1(air_para);
	air_para->COD[16]=NSarray(16,air_para);
	air_para->COD[16]-=8;
}
/****************       5567(066)        ******************/
void AirRemote567(AIR_status *air_status , Air_para *air_para){
	Air_spca_4000(air_para);
	Air_pwr_4000(air_status,air_para);
	Air_sptr_4000(air_status,air_para);
	Air_mode_4000(air_status,air_para);
	Air_wind_4000_2(air_status,air_para);
	Air_key_4000(air_status,air_para);
	Air_cust_4000_2(air_para);
	air_para->COD[16]=NSarray(16,air_para);
	air_para->COD[16]-=8;
}
/****************        5568(068)        ******************/
void AirRemote568(AIR_status *air_status , Air_para *air_para){
	Air_spca_4000(air_para);
	Air_pwr_4000(air_status,air_para);
	Air_sptr_4000(air_status,air_para);
	Air_mode_4000_1(air_status,air_para);
	Air_wind_4000_2(air_status,air_para);
	Air_key_4000(air_status,air_para);
	Air_cust_4000(air_para);
	air_para->COD[16]=NSarray(16,air_para);
	air_para->COD[16]-=8;
}
/****************        5569(074)        ******************/
void AirRemote569(AIR_status *air_status , Air_para *air_para){
	Air_spca_4000(air_para);
	Air_pwr_4000(air_status,air_para);
	Air_sptr_4000(air_status,air_para);
	Air_mode_4000(air_status,air_para);
	Air_wind_4000_2(air_status,air_para);
	Air_key_4000(air_status,air_para);
	Air_cust_4000_1(air_para);
	air_para->COD[16]=NSarray(16,air_para);
	air_para->COD[16]-=8;
}


/**************		涓夋磱 NEC 2 	 ***************/
/************     5570(075)       *********************/
void AirRemote570(AIR_status *air_status , Air_para *air_para){
	Air_spca_6a7e(air_status,air_para);
	air_para->COD[2]=0x7e;
	Air_mode_6a7e(air_status,air_para);
	//Air_cust_6a73_1(air_para);
	air_para->COD[5]+=NSarray(6,air_para)<<4;
	
}
/************     5571(076)       *********************/
void AirRemote571(AIR_status *air_status , Air_para *air_para){
 	Air_spca_6a7e(air_status,air_para);
	air_para->COD[2]=0x7d;
	Air_mode_6a7e_1(air_status,air_para);
	//Air_cust_6a73_2(air_para);
	air_para->COD[5]+=NSarray(6,air_para)<<4;
}

/**************		鏍煎姏9 subroutine		***************/
void Air_cust_2050_3(Air_para *air_para){
	air_para->COD[2]=0x20;
	air_para->COD[3]=0x50;
	air_para->COD[4]=0x02;
	air_para->COD[6]=0x20;
	air_para->COD[8]=air_para->COD[1]+air_para->COD[0];
	air_para->COD[8]-=4;
	air_para->COD[8]<<=4;
}
void Air_cust_2050_4(AIR_status *air_status ,Air_para *air_para){
	air_para->COD[2]=0x20;
		air_para->COD[3]=0x70;
		air_para->COD[4]=0x02;
		air_para->COD[5]=0x00;
		air_para->COD[6]=0x00;

		switch(air_status->vSpeed)
		{
			case SPEED_AUTO:
				air_para->COD[7]|=0x00;
				break;
			case SPEED_LOW:
				air_para->COD[7]|=0x10;
				break;
			case SPEED_MEDIUM:
				air_para->COD[7]|=0x20;
				break;
			case SPEED_HIGH:
				air_para->COD[7]|=0x30;
				break;
			default:
				break;
		}

		air_para->COD[8]=(air_para->COD[1])+((air_para->COD[0])&0x0f);
		air_para->COD[8]-=6;
		air_para->COD[8]+=((air_para->COD[7])>>4);
		air_para->COD[8]<<=4;

}



/**************		鏍煎姏9 		***************/
/******      CODE 5572(027)		*************/
void AirRemote572(AIR_status *air_status , Air_para *air_para){
	Air_spca_2050(air_para);
	Air_mode_2050(air_status , air_para);
	Air_wind_2050(air_status , air_para);
	Air_sptr_2050(air_status , air_para);
	Air_cust_2050_3(air_para);
}
/******      CODE 5573(027)		*************/
void AirRemote573(AIR_status *air_status , Air_para *air_para){
	Air_spca_2050(air_para);
	Air_mode_2050(air_status , air_para);
	Air_wind_2050(air_status , air_para);
	Air_sptr_2050(air_status , air_para);
	Air_cust_2050_4(air_status, air_para);
}
/**************		蹇楅珮(ZH/JT-03)(鏃�	***************/
/*************     5574        **************/
void AirRemote574(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x01;

	air_para->LDH_h=0x07;
	air_para->LDH_l=0x72;

	air_para->LDL_h=0x08;
	air_para->LDL_l=0xff;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xaf;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xaf;

	air_para->ONE_h=0x01;
	air_para->ONE_l=0xff;

	air_para->STO_h=0x08;
	air_para->STO_l=0xff;

	air_para->BIC0=96;

	switch(air_status->vKey)
	{
		case POWER_KEY:
			air_para->COD[5]=0x00;
			break;
		case MODE_KEY:
			air_para->COD[5]=0x01;
			break;
		case SPEED_KEY:
			air_para->COD[5]=0x05;
			break;
		case TEMPER_INC_KEY:
			air_para->COD[5]=0x02;
			break;
		case TEMPER_DEC_KEY:
			air_para->COD[5]=0x03;
			break;
		case WIND_MANUAL_KEY:
			air_para->COD[5]=0x07;
			break;
		case WIND_AUTO_KEY:
			air_para->COD[5]=0x04;
			break;
		default:
			break;
	}

	switch(air_status->vPower){
		case POWER_OFF:
			air_para->COD[7]|=0x00;
			break;
		case POWER_ON:
			air_para->COD[7]|=0x02;
			break;
		default:
			break;
	}

	switch(air_status->vMode){
		case MODE_AUTO:
			air_para->COD[9]|=0x00;
			break;
		case MODE_COLD:
			air_para->COD[9]|=0x20;
			break;
		case MODE_WET:
			air_para->COD[9]|=0x40;
			break;
		case MODE_WIND:
			air_para->COD[9]|=0x60;
			break;
		case MODE_HOT:
			air_para->COD[9]|=0x80;
			break;
		default:
			break;
	}

	switch(air_status->vSpeed){
		case SPEED_AUTO:
			air_para->COD[7]|=0x00;
			break;
		case SPEED_LOW:
			air_para->COD[7]|=0x60;
			break;
		case SPEED_MEDIUM:
			air_para->COD[7]|=0x40;
			break;
		case SPEED_HIGH:
			air_para->COD[7]|=0x20;
			break;
		default:
			break;
	}

	switch(air_status->vTemper){
		case TEMPER_16:
			air_para->COD[9]|=0x00;
			break;
		case TEMPER_17:
			air_para->COD[9]|=0x01;
			break;
		case TEMPER_18:
			air_para->COD[9]|=0x02;
			break;
		case TEMPER_19:
			air_para->COD[9]|=0x03;
			break;
		case TEMPER_20:
			air_para->COD[9]|=0x04;
			break;
		case TEMPER_21:
			air_para->COD[9]|=0x05;
			break;
		case TEMPER_22:
			air_para->COD[9]|=0x06;
			break;
		case TEMPER_23:
			air_para->COD[9]|=0x07;
			break;
		case TEMPER_24:
			air_para->COD[9]|=0x08;
			break;
		case TEMPER_25:
			air_para->COD[9]|=0x09;
			break;
		case TEMPER_26:
			air_para->COD[9]|=0x0a;
			break;
		case TEMPER_27:
			air_para->COD[9]|=0x0b;
			break;
		case TEMPER_28:
			air_para->COD[9]|=0x0c;
			break;
		case TEMPER_29:
			air_para->COD[9]|=0x0d;
			break;
		case TEMPER_30:
			air_para->COD[9]|=0x0e;
			break;
		default:
			break;
	}

	switch(air_status->vWind){
		case WIND_AUTO:
			air_para->COD[7]|=0x00;
			break;
		case WIND_MANUAL:
			air_para->COD[7]|=0x10;
			break;
		default:
			break;
	}

	switch(air_status->vManualWind){
		case MANUAL_WIND_1:
			air_para->COD[7]|=0x00;
			break;
		case MANUAL_WIND_2:
			air_para->COD[7]|=0x04;
			break;
		case MANUAL_WIND_3:
			air_para->COD[7]|=0x08;
			break;
		case MANUAL_WIND_4:
			air_para->COD[7]|=0x00;
			break;
		default:
			break;
	}
	air_para->COD[11]=0xd5;
	air_para->COD[0]=~(air_para->COD[1]);
	air_para->COD[2]=~(air_para->COD[3]);
	air_para->COD[4]=~(air_para->COD[5]);
	air_para->COD[6]=~(air_para->COD[7]);
	air_para->COD[8]=~(air_para->COD[9]);
	air_para->COD[10]=~(air_para->COD[11]);
}
/**************		锟斤拷锟斤拷2 (锟斤拷锟斤拷遥锟斤拷锟斤拷)	***************/
/*************     5575        **************/
void AirRemote575(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;
	air_para->LDH_h=0x0b;
	air_para->LDH_l=0x03;
	air_para->LDL_h=0x05;
	air_para->LDL_l=0x86;
	air_para->HIG_h=0x00;
	air_para->HIG_l=0xc1;
	air_para->ZER_h=0x00;
	air_para->ZER_l=0xa8;
	air_para->ONE_h=0x01;
	air_para->ONE_l=0xf0;
	air_para->BIC0=72;

	switch(air_status->vKey)
	{
		case POWER_KEY:
			air_para->COD[0]|=0x80;
			break;
		case MODE_KEY:
			air_para->COD[0]|=0x80;
			break;
		case SPEED_KEY:
			air_para->COD[0]|=0x80;
			break;
		case TEMPER_INC_KEY:
			air_para->COD[0]|=0x80;
			break;
		case TEMPER_DEC_KEY:
			air_para->COD[0]|=0x80;
			break;
		case WIND_MANUAL_KEY:
			air_para->COD[0]|=0xa0;
			break;
		case WIND_AUTO_KEY:
			air_para->COD[0]|=0xa0;
			break;
		default:
			break;
	}
	
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
			air_para->COD[2]|=0x00;
			break;
			
		case SPEED_LOW:
			air_para->COD[2]|=0x03;
			break;
			
		case SPEED_MEDIUM:
			air_para->COD[2]|=0x02;
			break;
			
		case SPEED_HIGH:
			air_para->COD[2]|=0x01;
			break;
			
		default:
			break;
	}
	
	switch(air_status->vTemper){
		case TEMPER_16:
			air_para->COD[1]=0x19;
			break;
		case TEMPER_17:
			air_para->COD[1]=0x1a;
			break;
		case TEMPER_18:
			air_para->COD[1]=0x1b;
			break;
		case TEMPER_19:
			air_para->COD[1]=0x1c;
			break;
		case TEMPER_20:
			air_para->COD[1]=0x1d;
			break;
		case TEMPER_21:
			air_para->COD[1]=0x1e;
			break;
		case TEMPER_22:
			air_para->COD[1]=0x1f;
			break;
		case TEMPER_23:
			air_para->COD[1]=0x20;
			break;
		case TEMPER_24:
			air_para->COD[1]=0x21;
			break;
		case TEMPER_25:
			air_para->COD[1]=0x22;
			break;
		case TEMPER_26:
			air_para->COD[1]=0x23;
			break;
		case TEMPER_27:
			air_para->COD[1]=0x24;
			break;
		case TEMPER_28:
			air_para->COD[1]=0x25;
			break;
		case TEMPER_29:
			air_para->COD[1]=0x26;
			break;
		case TEMPER_30:
			air_para->COD[1]=0x27;
			break;
		default:
			break;
	}
	
	switch(air_status->vWind){
		case WIND_AUTO:
			air_para->COD[2]|=0x08;
			break;
		case WIND_MANUAL:
			air_para->COD[2]|=0x00;
			break;
		default:
			break;
	}
	
	air_para->COD[3]=0x00;
	air_para->COD[4]=0x30;
	air_para->COD[5]=0x03;
	air_para->COD[6]=0x00;
	air_para->COD[7]=0x00;
	air_para->COD[8]=0x0c;
}




/**************		锟斤拷锟斤拷1	***************/
/*************     5576        **************/
void AirRemote576(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;
	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xf5;
	air_para->LDL_h=0x05;
	air_para->LDL_l=0x86;
	air_para->HIG_h=0x00;
	air_para->HIG_l=0xb1;
	air_para->ZER_h=0x00;
	air_para->ZER_l=0xb8;
	air_para->ONE_h=0x01;
	air_para->ONE_l=0xf0;
	air_para->BIC0=40;
	
	switch(air_status->vKey)
		{
			case POWER_KEY:
				air_para->COD[0]|=0x03;
				break;
			default:
				air_para->COD[0]|=0x0c;
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
			air_para->COD[1]|=0x80;
			break;
		case WIND_MANUAL:
			air_para->COD[1]|=0x00;
			break;
		default:
			break;
	}
	
	air_para->COD[2]=0x0c;
	air_para->COD[3]=0x10;
	air_para->COD[4]=0xaa;
}


/**************		锟斤拷锟斤拷1	***************/
/*************     5577        **************/
void AirRemote577(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;
	air_para->LDH_h=0x0a;
	air_para->LDH_l=0xf5;
	air_para->LDL_h=0x05;
	air_para->LDL_l=0x86;
	air_para->HIG_h=0x00;
	air_para->HIG_l=0xb1;
	air_para->ZER_h=0x00;
	air_para->ZER_l=0xb8;
	air_para->ONE_h=0x01;
	air_para->ONE_l=0xf0;
	air_para->BIC0=40;
	
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
			air_para->COD[2]|=0x00;
			break;
			
		case SPEED_LOW:
			air_para->COD[2]|=0x03;
			break;
			
		case SPEED_MEDIUM:
			air_para->COD[2]|=0x02;
			break;
			
		case SPEED_HIGH:
			air_para->COD[2]|=0x01;
			break;
			
		default:
			break;
	}
	
	switch(air_status->vTemper){
		case TEMPER_16:
			air_para->COD[1]=0x10;
			break;
		case TEMPER_17:
			air_para->COD[1]=0x11;
			break;
		case TEMPER_18:
			air_para->COD[1]=0x12;
			break;
		case TEMPER_19:
			air_para->COD[1]=0x13;
			break;
		case TEMPER_20:
			air_para->COD[1]=0x14;
			break;
		case TEMPER_21:
			air_para->COD[1]=0x15;
			break;
		case TEMPER_22:
			air_para->COD[1]=0x16;
			break;
		case TEMPER_23:
			air_para->COD[1]=0x17;
			break;
		case TEMPER_24:
			air_para->COD[1]=0x18;
			break;
		case TEMPER_25:
			air_para->COD[1]=0x19;
			break;
		case TEMPER_26:
			air_para->COD[1]=0x1a;
			break;
		case TEMPER_27:
			air_para->COD[1]=0x1b;
			break;
		case TEMPER_28:
			air_para->COD[1]=0x1c;
			break;
		case TEMPER_29:
			air_para->COD[1]=0x1d;
			break;
		case TEMPER_30:
			air_para->COD[1]=0x1e;
			break;
		default:
			break;
	}
	
	switch(air_status->vWind){
		case WIND_AUTO:
			air_para->COD[2]|=0x08;
			break;
		case WIND_MANUAL:
			air_para->COD[2]|=0x00;
			break;
		default:
			break;
	}
	
	air_para->COD[3]=0x10;
	air_para->COD[4]=0x0c;
}

/*************     5620        **************/
// sinco  (200)
/*************     5620        **************/
//sinco

void AirRemote620(AIR_status *air_status , Air_para *air_para){
		air_para->CARR=0x20;
		air_para->STRU=0x07;
	
	
		air_para->LDH_h=0x01;
		air_para->LDH_l=0x00;
		
		air_para->LDL_h=0x0e;
		air_para->LDL_l=0x4e;
		
		air_para->HIG_h=0x01;
		air_para->HIG_l=0x00;
		
		air_para->ZER_h=0x05;
		air_para->ZER_l=0x00;
		
		air_para->ONE_h=0x09;
		air_para->ONE_l=0x48;
	
		air_para->STO_h=0x2a;
		air_para->STO_l=0x4c;
	
		air_para->BIC0=8;
		air_para->BIC1=8;
		air_para->BIC2=8;
		air_para->COD[0] = 0xbf;
		air_para->COD[1] = air_sinco1_temp[air_status->vTemper];
		if (air_status->vPower){
			
			air_para->COD[2] = air_sinco1_mode[air_status->vMode];
			air_para->COD[2] += air_sinco1_speed[air_status->vSpeed];
			}else {
			air_para->COD[2] = 0x02;
		}


}

/*************     5621        **************/
// sinco  (201)
/*************     5621        **************/
//sinco
void Air_spc_sinco2(Air_para *air_para){
		air_para->CARR=0x20;
		air_para->STRU=0x02;
		
		air_para->LDH_h=0x03;
		air_para->LDH_l=0xf2;
		
		air_para->LDL_h=0x03;
		air_para->LDL_l=0xef;
		
		air_para->HIG_h=0x00;
		air_para->HIG_l=0x8b;
		
		air_para->ZER_h=0x00;
		air_para->ZER_l=0x7a;
		
		air_para->ONE_h=0x01;
		air_para->ONE_l=0x90;
	
		air_para->STO_h=0xb3;
		air_para->STO_l=0x0d;
		
		air_para->BIC0=96;
		air_para->BIC1=96;
}

void AirRemote621(AIR_status *air_status , Air_para *air_para){
		
	int i;
	char temp=0;
		Air_spc_sinco2(air_para);
		memcpy(air_para->COD,air_sinco2_data,sizeof(air_sinco2_data));

		
		air_para->COD[2] = air_sinco2_temp[air_status->vTemper];
		air_para->COD[2] |= air_sinco2_mode[air_status->vMode];
		if (air_status->vMode==MODE_WET){
			air_para->COD[2] = 0x4b;
			}
		if (air_status->vMode==MODE_HOT){
			air_para->COD[9] = 0x8a;
			}else {
			air_para->COD[9] = 0xb8;	
				}
		air_para->COD[10] = air_sinco2_speed[air_status->vSpeed];
		if (air_status->vPower==0){
			air_para->COD[2] -= 8;
			}

	if (air_status->vManualWind==WIND_AUTO){
			air_para->COD[3] = 0x80;
			}else {
			air_para->COD[3] = 0x00;
				}
  
			
	for (i=0;i<11;i++){
		air_para->COD[i] = HiBitFst(air_para->COD[i]);
		}
	for (i=2;i<11;i++){
		temp += (air_para->COD[i]>>4 )&0x0f;
		temp += (air_para->COD[i])&0x0f;
		}
	air_para->COD[11] =temp;
	air_para->COD[11] = HiBitFst(air_para->COD[11]);
	for (i=0;i<12;i++){
		 air_para->COD[i+12] = air_para->COD[i];
		}
		
}

/*************     5622        **************/
// sinco  (202)
/*************     5622        **************/
//sinco   sinco2
void Air_spc_sinco3(Air_para *air_para){
		air_para->CARR=0x20;
		air_para->STRU=0x09;
		
		air_para->LDH_h=0x01;
		air_para->LDH_l=0x32;
		
		air_para->LDL_h=0x0d;
		air_para->LDL_l=0x62;
		
		air_para->HIG_h=0x01;
		air_para->HIG_l=0x32;
		
		air_para->ZER_h=0x03;
		air_para->ZER_l=0xac;
		
		air_para->ONE_h=0x08;
		air_para->ONE_l=0x8b;
	
		air_para->STO_h=0x33;
		air_para->STO_l=0xe1;
		
		air_para->BIC0=8;
		air_para->BIC1=8;
		air_para->BIC2=8;
		air_para->BIC3=8;
		air_para->BIC4=8;
}

void AirRemote622(AIR_status *air_status , Air_para *air_para){
		
	int i;
	char temp=0;
		Air_spc_sinco3(air_para);
		memcpy(air_para->COD,air_sinco3_data,sizeof(air_sinco3_data));

		
		air_para->COD[3] = air_sinco3_temp[air_status->vTemper];
		air_para->COD[4] = air_sinco3_mode[air_status->vMode];
		air_para->COD[4] += air_sinco3_speed[air_status->vSpeed];

	if (air_status->vWind==WIND_AUTO){
			air_para->COD[3] |= 0x10;
			}else {
			air_para->COD[3] |= 0x00;
				}
  if (air_status->vKey==POWER_KEY){
			air_para->COD[3] |=0x80;
			
			}
	if(air_status->vPower==POWER_OFF){
			air_para->COD[4] &=0xf0;
		}
	
		
	for (i=0;i<5;i++){
		air_para->COD[i] = HiBitFst(air_para->COD[i]);
		}

		
}


/*************     5623       **************/
// AUX  ()
/*************     5623        **************/
//AUX    AUX7
void Air_spc_AUX7(Air_para *air_para){
		air_para->CARR=0x20;
		air_para->STRU=0x00;

		air_para->LDH_h=0x0A;
		air_para->LDH_l=0xFC;

		air_para->LDL_h=0x05;
		air_para->LDL_l=0x7E;

		air_para->HIG_h=0x00;
		air_para->HIG_l=0xAF;

		air_para->ZER_h=0x00;
		air_para->ZER_l=0x9C;

		air_para->ONE_h=0x01;
		air_para->ONE_l=0xFA;

		air_para->BIC0=104;

}


void AirRemote623(AIR_status *air_status , Air_para *air_para){

	int i;
	char temp=0;
	Air_spc_AUX7(air_para);
		memcpy(air_para->COD,air_aux7_data,sizeof(air_aux7_data));


		air_para->COD[1] = air_aux7_temp[air_status->vTemper];
		air_para->COD[6] = air_aux7_mode[air_status->vMode];
		air_para->COD[4] = air_aux7_speed[air_status->vSpeed];
		air_para->COD[11] = air_aux7_key[air_status->vKey];
	if (air_status->vWind==WIND_AUTO){
			air_para->COD[1] |= 0x07;
			}
  if (air_status->vPower==POWER_ON){
			air_para->COD[9] = 0x20;

			}else {
			air_para->COD[9] = 0x00;
			}

  for (i=0;i<12;i++){
  		air_para->COD[12] += air_para->COD[i];
  		}


}

/*************     5624       **************/
// panasonic  (669)
/*************     5624        **************/
//panasonic     panasonic 973

void AirRemote624(AIR_status *air_status , Air_para *air_para){

	Air_spca_panasonic_973(air_para);
	memcpy(air_para->COD,air_pana669_data,sizeof(air_pana669_data));


		air_para->COD[0] = air_pana669_temp[air_status->vTemper];
		air_para->COD[2] = air_pana669_mode[air_status->vMode];
		air_para->COD[0] |= air_pana669_speed[air_status->vSpeed];


  	if (air_status->vPower==POWER_OFF){
		air_para->COD[2] -=8;

			}
	if (air_status->vMode==MODE_AUTO){
		air_para->COD[0] =0x28;

			}

 	air_para->COD[1]=air_para->COD[0];
	air_para->COD[3]=air_para->COD[2];
	air_para->COD[4]=air_para->COD[0];
	air_para->COD[5]=air_para->COD[1];
	air_para->COD[6]=air_para->COD[2];
	air_para->COD[7]=air_para->COD[3];


}


/*************     5625      **************/
// panasonic  (661)
/*************     5625        **************/
//panasonic     panasonic6 973

void AirRemote625(AIR_status *air_status , Air_para *air_para){

	Air_spca_panasonic6_973(air_para);
	memcpy(air_para->COD,air_pana669_data,sizeof(air_pana669_data));


		air_para->COD[0] = air_pana669_temp[air_status->vTemper];
		air_para->COD[2] = air_pana669_mode[air_status->vMode];
		air_para->COD[0] |= air_pana669_speed[air_status->vSpeed];


  	if (air_status->vPower==POWER_OFF){
		air_para->COD[2] -=8;

			}
	if (air_status->vMode==MODE_AUTO){
		air_para->COD[0] =0x28;

			}

 	air_para->COD[1]=air_para->COD[0];
	air_para->COD[3]=air_para->COD[2];
	air_para->COD[4]=air_para->COD[0];
	air_para->COD[5]=air_para->COD[1];
	air_para->COD[6]=air_para->COD[2];
	air_para->COD[7]=air_para->COD[3];
	air_para->COD[8]=air_para->COD[0];
	air_para->COD[9]=air_para->COD[1];
	air_para->COD[10]=air_para->COD[2];
	air_para->COD[11]=air_para->COD[3];


}
/*************     5626     **************/
// panasonic  (660)
/*************     5626       **************/
//     lesheng1
void Air_spca_lesheng_1(Air_para *air_para){
		air_para->CARR=0x20;
		air_para->STRU=0x07;
	
	
		air_para->LDH_h=0x04;
		air_para->LDH_l=0x45;
		
		air_para->LDL_h=0x04;
		air_para->LDL_l=0x45;
		
		air_para->HIG_h=0x01;
		air_para->HIG_l=0x19;
		
		air_para->ZER_h=0x01;
		air_para->ZER_l=0x10;
		
		air_para->ONE_h=0x03;
		air_para->ONE_l=0x26;
	
		air_para->STO_h=0x23;
		air_para->STO_l=0x2e;
	
		air_para->BIC0=26;
		air_para->BIC1=26;
		air_para->BIC2=26;
	


}


void AirRemote626(AIR_status *air_status , Air_para *air_para){

	Air_spca_lesheng_1(air_para);
	memcpy(air_para->COD,air_pana660_data,sizeof(air_pana660_data));

	if (air_status->vKey==POWER_KEY){
		air_para->COD[1] = 0x00;
		}else {
		air_para->COD[1] = 0x10;
			}
	
	
	air_para->COD[0] = air_pana660_mode[air_status->vMode];
	air_para->COD[0] += air_pana660_speed[air_status->vSpeed];
	air_para->COD[0] |= air_pana660_temp[air_status->vTemper];


    air_para->COD[4]=air_para->COD[0];
	air_para->COD[5]=air_para->COD[1];
	air_para->COD[6]=air_para->COD[2];
    air_para->COD[7]=air_para->COD[3];
    air_para->COD[8]=air_para->COD[0];
	air_para->COD[9]=air_para->COD[1];
	air_para->COD[10]=air_para->COD[2];
    air_para->COD[1]=air_para->COD[3];

	

}

/*************     5632     **************/
// panasonic  (672)
/*************     5632        **************/
//panasonic     lesheng2
void Air_spca_lesheng_2(Air_para *air_para){
		air_para->CARR=0x20;
		air_para->STRU=0x0a;
	
	
		air_para->LDH_h=0x04;
		air_para->LDH_l=0x58;
		
		air_para->LDL_h=0x02;
		air_para->LDL_l=0x10;
		
		air_para->HIG_h=0x00;
		air_para->HIG_l=0x90;
		
		air_para->ZER_h=0x00;
		air_para->ZER_l=0x90;
		
		air_para->ONE_h=0x01;
		air_para->ONE_l=0x91;
	
		air_para->STO_h=0x5b;
		air_para->STO_l=0xf2;
	
		air_para->BIC0=64;
		air_para->BIC1=64;
		air_para->BIC2=64;
		air_para->BIC3=72;
		air_para->BIC4=72;
		air_para->BIC5=72;


}


void AirRemote632(AIR_status *air_status , Air_para *air_para){

	Air_spca_lesheng_2(air_para);
	memcpy(air_para->COD,air_pana672_data,sizeof(air_pana672_data));

	if (air_status->vKey==POWER_KEY){
		memcpy(air_para->COD,air_pana672_power,sizeof(air_pana672_power));	
		air_para->BIC0=72;
		air_para->BIC1=72;
		air_para->BIC2=72;
		return;
		}
	
	if (air_status->vKey==WIND_AUTO_KEY||air_status->vKey==WIND_MANUAL_KEY){
		memcpy(air_para->COD,air_pana672_wind,sizeof(air_pana672_wind));
		switch (air_status->vWind){
			case MANUAL_WIND_1:
				air_para->COD[4] = 0x54;
				air_para->COD[6] = 0x54;
				break;
			case MANUAL_WIND_2:
				air_para->COD[4] = 0x53;
				air_para->COD[6] = 0x53;
				break;
			case MANUAL_WIND_3:
				air_para->COD[4] = 0x52;
				air_para->COD[6] = 0x52;
				break;
			case MANUAL_WIND_4:
				air_para->COD[4] = 0x55;
				air_para->COD[6] = 0x55;
				break;
			default:
				break;
			}
		air_para->COD[11]=air_para->COD[4];
		air_para->COD[13]=air_para->COD[4];
	    air_para->COD[20]=air_para->COD[4];
		air_para->COD[18]=air_para->COD[4];
		air_para->BIC0=56;
		air_para->BIC1=56;
		air_para->BIC2=56;
		return;
		}
	
	air_para->COD[5] = air_pana672_temp[air_status->vTemper];
	air_para->COD[4] = air_pana672_mode[air_status->vMode];
	air_para->COD[6] = air_pana672_speed[air_status->vSpeed];
	air_para->COD[7] = lowBitAdd(air_para);

    air_para->COD[12]=air_para->COD[4];
	air_para->COD[13]=air_para->COD[5];
	air_para->COD[14]=air_para->COD[6];
    air_para->COD[15]=air_para->COD[7];
    air_para->COD[20]=air_para->COD[4];
	air_para->COD[21]=air_para->COD[5];
	air_para->COD[22]=air_para->COD[6];
    air_para->COD[23]=air_para->COD[7];

	

}


/*************     5740        **************/
//锟斤拷锟�  (740)
/*************     5740        **************/
//锟斤拷锟�
 void Air_spc_dajin1(Air_para *air_para){
	air_para->CARR=0x20;
		air_para->STRU=0x02;
	
		air_para->LDH_h=0x06;
		air_para->LDH_l=0x3c;
	
		air_para->LDL_h=0x02;
		air_para->LDL_l=0xa9;
	
		air_para->HIG_h=0x00;
		air_para->HIG_l=0x70;
	
		air_para->ZER_h=0x00;
		air_para->ZER_l=0xe4;
	
		air_para->ONE_h=0x02;
		air_para->ONE_l=0x38;
	
		air_para->STO_h=0x23;
		air_para->STO_l=0xbe;
	
		air_para->BIC0=56;
		air_para->BIC1=104;
}
//锟斤拷锟�
 void Air_spc_dajin6(Air_para *air_para){
	air_para->CARR=0x20;
		air_para->STRU=0x02;
	
		air_para->LDH_h=0x06;
		air_para->LDH_l=0x3c;
	
		air_para->LDL_h=0x02;
		air_para->LDL_l=0xa9;
	
		air_para->HIG_h=0x00;
		air_para->HIG_l=0x70;
	
		air_para->ZER_h=0x00;
		air_para->ZER_l=0xe4;
	
		air_para->ONE_h=0x02;
		air_para->ONE_l=0x38;
	
		air_para->STO_h=0x23;
		air_para->STO_l=0xbe;
	
		air_para->BIC0=56;
		air_para->BIC1=120;
}
 void Air_spc_dajin03(Air_para *air_para){
	air_para->CARR=0x20;
		air_para->STRU=0x02;
	
		air_para->LDH_h=0x04;
		air_para->LDH_l=0x52;
	
		air_para->LDL_h=0x01;
		air_para->LDL_l=0xfa;
	
		air_para->HIG_h=0x00;
		air_para->HIG_l=0xa2;
	
		air_para->ZER_h=0x00;
		air_para->ZER_l=0x8f;
	
		air_para->ONE_h=0x01;
		air_para->ONE_l=0x75;
	
		air_para->STO_h=0x21;
		air_para->STO_l=0xdf;
	
		air_para->BIC0=64;
		air_para->BIC1=152;
}
  void Air_spc_dajin02(Air_para *air_para){
	 air_para->CARR=0x20;
		 air_para->STRU=0x00;
	 
		 air_para->LDH_h=0x05;
		 air_para->LDH_l=0xd9;
	 
		 air_para->LDL_h=0x02;
		 air_para->LDL_l=0xe5;
	 
		 air_para->HIG_h=0x00;
		 air_para->HIG_l=0x7b;
	 
		 air_para->ZER_h=0x00;
		 air_para->ZER_l=0xfa;
	 
		 air_para->ONE_h=0x01;
		 air_para->ONE_l=0xdd;
	 
		 air_para->BIC0=56;
 }




void AirRemote740(AIR_status *air_status , Air_para *air_para){
	
		Air_spc_dajin1(air_para);

		memcpy(air_para->COD,air_dakin1_data,sizeof(air_dakin1_data));
		air_para->COD[12] |=air_dakin1_power[air_status->vPower];
		air_para->COD[12] |=air_dakin1_mode[air_status->vMode];
		air_para->COD[16] =air_dakin1_temp[air_status->vTemper];
		air_para->COD[17] =air_dakin1_speed[air_status->vSpeed];

		air_para->COD[19] = air_para->COD[7] +air_para->COD[8]+air_para->COD[9] +air_para->COD[10] +air_para->COD[11] 
			+air_para->COD[12] +air_para->COD[13] +air_para->COD[14] +air_para->COD[15] +air_para->COD[16] +air_para->COD[17]
			+air_para->COD[18];

}

void AirRemote741(AIR_status *air_status , Air_para *air_para){

		Air_spc_dajin1(air_para);
		memcpy(air_para->COD,air_dakin2_data,sizeof(air_dakin2_data));
		air_para->COD[12] |=air_dakin1_power[air_status->vPower];
		air_para->COD[12] |=air_dakin1_mode[air_status->vMode];
		air_para->COD[16] =air_dakin1_temp[air_status->vTemper];
		air_para->COD[17] =air_dakin1_speed[air_status->vSpeed];

		air_para->COD[19] = air_para->COD[7] +air_para->COD[8]+air_para->COD[9] +air_para->COD[10] +air_para->COD[11] 
			+air_para->COD[12] +air_para->COD[13] +air_para->COD[14] +air_para->COD[15] +air_para->COD[16] +air_para->COD[17]
			+air_para->COD[18];

		
}

void AirRemote744(AIR_status *air_status , Air_para *air_para){
		int size;
		
		Air_spc_dajin1(air_para);
		memcpy(air_para->COD,air_dakin3_data,sizeof(air_dakin3_data));
		air_para->COD[12] |=air_dakin1_power[air_status->vPower];
		air_para->COD[12] |=air_dakin1_mode[air_status->vMode];
		air_para->COD[16] =air_dakin1_temp[air_status->vTemper];
		air_para->COD[17] =air_dakin1_speed[air_status->vSpeed];
		

		air_para->COD[19] = air_para->COD[7] +air_para->COD[8]+air_para->COD[9] +air_para->COD[10] +air_para->COD[11] 
			+air_para->COD[12] +air_para->COD[13] +air_para->COD[14] +air_para->COD[15] +air_para->COD[16] +air_para->COD[17]
			+air_para->COD[18];

		
}

void AirRemote748(AIR_status *air_status , Air_para *air_para){

		int size;
		
		Air_spc_dajin6(air_para);
	
	//	Air_data_initial(air_para,air_dakin3_data,20);
		memcpy(air_para->COD,air_dakin6_data,sizeof(air_dakin6_data));
		air_para->COD[13] =air_dakin6_key[air_status->vKey];
		air_para->COD[14] |=air_dakin1_power[air_status->vPower];
		air_para->COD[14] |=air_dakin6_mode[air_status->vMode];
		air_para->COD[17] =air_dakin1_temp[air_status->vTemper];
		air_para->COD[18] |=air_dakin6_speed[air_status->vSpeed];
		air_para->COD[18] |=air_dakin6_wind[air_status->vManualWind];	
		
		air_para->COD[21] = air_para->COD[7] +air_para->COD[8]+air_para->COD[9] +air_para->COD[10] +air_para->COD[11] 
			+air_para->COD[12] +air_para->COD[13] +air_para->COD[14] +air_para->COD[15] +air_para->COD[16] +air_para->COD[17]
			+air_para->COD[18]+air_para->COD[19]+air_para->COD[20]+air_para->COD[21]-1;

		
}

void AirRemote752(AIR_status *air_status , Air_para *air_para){

	
		Air_spc_dajin03(air_para);
	//	Air_data_initial(air_para,air_dakin3_data,20);
		memcpy(air_para->COD,air_dakin03_data,sizeof(air_dakin03_data));
	
		air_para->COD[13] |=air_dakin1_power[air_status->vPower];
		air_para->COD[13] |=air_dakin03_mode[air_status->vMode];
		air_para->COD[14] =air_dakin03_temp[air_status->vTemper];
		air_para->COD[16] =air_dakin03_speed[air_status->vSpeed];
		air_para->COD[17] =air_dakin03_wind[air_status->vManualWind];	
		
		air_para->COD[26] = air_para->COD[8]+air_para->COD[9] +air_para->COD[10] +air_para->COD[11] 
			+air_para->COD[12] +air_para->COD[13] +air_para->COD[14] +air_para->COD[15] +air_para->COD[16] +air_para->COD[17]
			+air_para->COD[18]+air_para->COD[19]+air_para->COD[20]+air_para->COD[21]+air_para->COD[22]+air_para->COD[23]
			+air_para->COD[24]+air_para->COD[25];

		
}

void AirRemote753(AIR_status *air_status , Air_para *air_para){

	int i;
	char temp;
		Air_spc_dajin02(air_para);
	//	Air_data_initial(air_para,air_dakin3_data,20);
		memcpy(air_para->COD,air_dakin02_data,sizeof(air_dakin02_data));
	
	
		air_para->COD[1] |=air_dakin02_mode[air_status->vMode];
		if (air_status->vPower==POWER_OFF){
		air_para->COD[1] -=0xc0;	
			}
		air_para->COD[4] =air_dakin02_temp[air_status->vTemper];
		air_para->COD[5] =air_dakin02_speed[air_status->vSpeed];
		if (air_status->vManualWind==WIND_MANUAL){
		air_para->COD[5] =air_dakin02_wind[air_status->vManualWind]+air_para->COD[5];	
		
			}
		else{
			air_para->COD[5] =0x1c+air_para->COD[5];	
			}
		temp = air_para->COD[1];
		temp = (temp>>4)&0x0f;
		air_para->COD[6] += temp;
		temp = air_para->COD[1];
		temp = temp&0x0f;
		air_para->COD[6] += temp;
		temp = air_para->COD[4];
		temp = (temp>>4)&0x0f;
		air_para->COD[6] += temp;
		temp = air_para->COD[4];
		temp = temp&0x0f;
		air_para->COD[6] += temp;
		temp = air_para->COD[5];
		temp = (temp>>4)&0x0f;
		air_para->COD[6] += temp;
		temp = air_para->COD[5];
		temp = temp&0x0f;
		air_para->COD[6] += temp;
		
	     air_para->COD[6] = (~air_para->COD[6] )&0x0f;
		 for (i=0;i<7;i++){
		 air_para->COD[i] =	HiBitFst(air_para->COD[i]);
		// LOGD(" COD[%d]  =====> 0X%X  ",i,air_para->COD[i]);
		 	}
		
}



void AirRemote754(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x06;


	air_para->LDH_h=0x04;
	air_para->LDH_l=0x46;
	
	air_para->LDL_h=0x04;
	air_para->LDL_l=0x46;
	
	air_para->HIG_h=0x01;
	air_para->HIG_l=0x0a;
	
	air_para->ZER_h=0x01;
	air_para->ZER_l=0x0a;
	
	air_para->ONE_h=0x03;
	air_para->ONE_l=0x0d;

	air_para->STO_h=0x10;
	air_para->STO_l=0xa6;

	air_para->BIC0=32;
	air_para->BIC1=32;
	air_para->BIC2=32;
	air_para->BIC3=32;

	
	memcpy(air_para->COD,air_panasonic01_data,sizeof(air_panasonic01_data));
	air_para->COD[0] =air_panasonic01_temp[air_status->vTemper];
	air_para->COD[0] |=air_panasonic01_speed[air_status->vSpeed];

	switch(air_status->vMode){
	case MODE_AUTO:
		air_para->COD[2]=0x4e;
		air_para->COD[0] &=0xf0;
		air_para->COD[0] |=0x08;
		break;

	case MODE_COLD:
		air_para->COD[2]=0x4a;
		break;

	case MODE_WET:
		air_para->COD[2]=0x4b;
		break;

	case MODE_WIND:
		air_para->COD[2]=0x49;
		break;

	case MODE_HOT:
		air_para->COD[2]=0x4c;
		break;

	default:
		break;
	}
	
	

	
	switch(air_status->vKey){
	
		case POWER_KEY:
			air_para->COD[2]-=8;
			break;

		default:
			break;
	}
	
	air_para->COD[1]=air_para->COD[0];
	air_para->COD[3]=air_para->COD[2];
	air_para->COD[4]=air_para->COD[0];
	air_para->COD[5]=air_para->COD[1];
	air_para->COD[6]=air_para->COD[2];
	air_para->COD[7]=air_para->COD[3];
	
}


#define SPECIAL_Airet4003	0x00
#define LOGIC_Airet4003	0x01
#define END_Airet4003	0x02


void AirRemote755(AIR_status *air_status , Air_para *air_para){

	
		Air_spc_dajin03(air_para);
	//	Air_data_initial(air_para,air_dakin3_data,20);
		memcpy(air_para->COD,air_dakin03_data,sizeof(air_dakin03_data));
	
		air_para->COD[13] =air_dakin1_power[air_status->vPower];
		air_para->COD[13] |=air_dakin03_mode[air_status->vMode];
		air_para->COD[14] =air_dakin03_temp[air_status->vTemper];
		air_para->COD[16] =air_dakin03_speed[air_status->vSpeed];
		air_para->COD[16] |=air_dakin03_wind[air_status->vManualWind];	
		
		air_para->COD[26] = air_para->COD[8]+air_para->COD[9] +air_para->COD[10] +air_para->COD[11] 
			+air_para->COD[12] +air_para->COD[13] +air_para->COD[14] +air_para->COD[15] +air_para->COD[16] +air_para->COD[17]
			+air_para->COD[18]+air_para->COD[19]+air_para->COD[20]+air_para->COD[21]+air_para->COD[22]+air_para->COD[23]
			+air_para->COD[24]+air_para->COD[25];

		

		
}





/**************		 涓夎彵7	***************/
/*************     5578   (551)     **************/
void AirRemote578(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x01;
	air_para->LDH_h=0x07;
	air_para->LDH_l=0x69;
	air_para->LDL_h=0x09;
	air_para->LDL_l=0x26;
	air_para->HIG_h=0x00;
	air_para->HIG_l=0xa1;
	air_para->ZER_h=0x01;
	air_para->ZER_l=0xdd;
	air_para->ONE_h=0x04;
	air_para->ONE_l=0x3a;
	air_para->STO_h=0x09;
	air_para->STO_l=0x26;
	air_para->BIC0=64;

	switch(air_status->vPower)
	{
		case POWER_OFF:
			air_para->COD[2]|=0x00;
			break;
		case POWER_ON:
			air_para->COD[2]|=0x80;
			break;
		default:
			break;
	}

	switch(air_status->vMode)
	{
		case MODE_AUTO:
			air_para->COD[2]|=0x00;
			break;
		case MODE_COLD:
			air_para->COD[2]|=0x20;
			break;
		case MODE_WET:
			air_para->COD[2]|=0x10;
			break;
		case MODE_WIND:
			air_para->COD[2]|=0x30;
			break;
		case MODE_HOT:
			air_para->COD[2]|=0x40;
			break;
		default:
			break;
	}

	switch(air_status->vSpeed)
	{
		case SPEED_AUTO:
			air_para->COD[1]|=0x00;
			break;
		case SPEED_LOW:
			air_para->COD[1]|=0x00;
			break;
		case SPEED_MEDIUM:
			air_para->COD[1]|=0x10;
			break;
		case SPEED_HIGH:
			air_para->COD[1]|=0x20;
			break;
		default:
			break;
	}

	switch(air_status->vTemper)
	{
		case TEMPER_16:
			air_para->COD[2]|=0x02;
			break;
		case TEMPER_17:
			air_para->COD[2]|=0x02;
			break;
		case TEMPER_18:
			air_para->COD[2]|=0x02;
			break;
		case TEMPER_19:
			air_para->COD[2]|=0x03;
			break;
		case TEMPER_20:
			air_para->COD[2]|=0x04;
			break;
		case TEMPER_21:
			air_para->COD[2]|=0x05;
			break;
		case TEMPER_22:
			air_para->COD[2]|=0x06;
			break;
		case TEMPER_23:
			air_para->COD[2]|=0x07;
			break;
		case TEMPER_24:
			air_para->COD[2]|=0x08;
			break;
		case TEMPER_25:
			air_para->COD[2]|=0x09;
			break;
		case TEMPER_26:
			air_para->COD[2]|=0x0a;
			break;
		case TEMPER_27:
			air_para->COD[2]|=0x0b;
			break;
		case TEMPER_28:
			air_para->COD[2]|=0x0c;
			break;
		case TEMPER_29:
			air_para->COD[2]|=0x0d;
			break;
		case TEMPER_30:
			air_para->COD[2]|=0x0e;
			break;
		default:
			break;
	}

	switch(air_status->vWind)
	{
		case WIND_AUTO:
			air_para->COD[1]|=0x40;
			break;
		case WIND_MANUAL:
			air_para->COD[1]|=0x00;
			switch(air_status->vManualWind)
			{
				case MANUAL_WIND_1:
					air_para->COD[3]|=0x00;
					break;
				case MANUAL_WIND_2:
					air_para->COD[3]|=0x10;
					break;
				case MANUAL_WIND_3:
					air_para->COD[3]|=0x20;
					break;
				case MANUAL_WIND_4:
					air_para->COD[3]|=0x30;
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}

	air_para->COD[0]=0x0a;
	air_para->COD[4]=~(air_para->COD[0]);
	air_para->COD[5]=~(air_para->COD[1]);
	air_para->COD[6]=~(air_para->COD[2]);
	air_para->COD[7]=~(air_para->COD[3]);
}



/**************		 涓夎彵8	***************/
/*************     5579   (552)     **************/
void AirRemote579(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x01;
	air_para->LDH_h=0x04;
	air_para->LDH_l=0x7e;
	air_para->LDL_h=0x04;
	air_para->LDL_l=0x35;
	air_para->HIG_h=0x00;
	air_para->HIG_l=0x82;
	air_para->ZER_h=0x01;
	air_para->ZER_l=0xd9;
	air_para->ONE_h=0x04;
	air_para->ONE_l=0x35;
	air_para->STO_h=0x09;
	air_para->STO_l=0x82;
	air_para->BIC0=48;

	switch(air_status->vKey)
	{
		case POWER_KEY:
			air_para->COD[2]|=0x80;
			break;
		default:
			break;
	}

	switch(air_status->vMode)
	{
		case MODE_AUTO:
			air_para->COD[2]|=0x00;
			break;
		case MODE_COLD:
			air_para->COD[2]|=0x20;
			break;
		case MODE_WET:
			air_para->COD[2]|=0x10;
			break;
		case MODE_WIND:
			air_para->COD[2]|=0x30;
			break;
		case MODE_HOT:
			air_para->COD[2]|=0x40;
			break;
		default:
			break;
	}

	switch(air_status->vSpeed)
	{
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

	switch(air_status->vTemper)
	{
		case TEMPER_16:
			air_para->COD[2]|=0x02;
			break;
		case TEMPER_17:
			air_para->COD[2]|=0x02;
			break;
		case TEMPER_18:
			air_para->COD[2]|=0x02;
			break;
		case TEMPER_19:
			air_para->COD[2]|=0x03;
			break;
		case TEMPER_20:
			air_para->COD[2]|=0x04;
			break;
		case TEMPER_21:
			air_para->COD[2]|=0x05;
			break;
		case TEMPER_22:
			air_para->COD[2]|=0x06;
			break;
		case TEMPER_23:
			air_para->COD[2]|=0x07;
			break;
		case TEMPER_24:
			air_para->COD[2]|=0x08;
			break;
		case TEMPER_25:
			air_para->COD[2]|=0x09;
			break;
		case TEMPER_26:
			air_para->COD[2]|=0x0a;
			break;
		case TEMPER_27:
			air_para->COD[2]|=0x0b;
			break;
		case TEMPER_28:
			air_para->COD[2]|=0x0c;
			break;
		case TEMPER_29:
			air_para->COD[2]|=0x0d;
			break;
		case TEMPER_30:
			air_para->COD[2]|=0x0e;
			break;
		default:
			break;
	}

	switch(air_status->vWind)
	{
		case WIND_AUTO:
			air_para->COD[1]|=0x40;
			break;
		case WIND_MANUAL:
			air_para->COD[1]|=0x00;
			break;
		default:
			break;
	}

	air_para->COD[0]=0xdd;
	air_para->COD[3]=~(air_para->COD[0]);
	air_para->COD[4]=~(air_para->COD[1]);
	air_para->COD[5]=~(air_para->COD[2]);
}


/**************		涓夎彵鐢垫満(388) 	***************/
/*************  		鍝佺墝:	涓夎彵 **************/
void Constant_SanLingDianJi388(Air_para *air_para)
{
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
}
void vPower_SanLingDianJi388(AIR_status *air_status , Air_para *air_para)
{
	switch(air_status->vPower)
	{
		case POWER_OFF:
			air_para->COD[3]|=0x00;
			break;
		case POWER_ON:
			air_para->COD[3]|=0x08;
			break;
		default:
			break;
	}
}
void vMode_SanLingDianJi388(AIR_status *air_status , Air_para *air_para)
{
	switch(air_status->vMode)
	{
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
}
void vMode_SanLingDianJi388_580(AIR_status *air_status , Air_para *air_para)
{
	switch(air_status->vMode)
	{
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
}
void vSpeed_SanLingDianJi388(AIR_status *air_status , Air_para *air_para)
{
	switch(air_status->vSpeed)
	{
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
}
void vSpeed_SanLingDianJi388_595(AIR_status *air_status , Air_para *air_para)
{
	switch(air_status->vSpeed)
	{
		case SPEED_AUTO:
			air_para->COD[1]|=0x80;
			break;
		case SPEED_LOW:
			air_para->COD[1]|=0x80;
			break;
		case SPEED_MEDIUM:
			air_para->COD[1]|=0x40;
			break;
		case SPEED_HIGH:
			air_para->COD[1]|=0x40;
			break;
		default:
			break;
	}
}

void vTemper_SanLingDianJi388(AIR_status *air_status , Air_para *air_para)
{
	switch(air_status->vTemper)
	{
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
}
void vWind_SanLingDianJi388_580(AIR_status *air_status , Air_para *air_para)
{
	switch(air_status->vWind)
	{
		case WIND_AUTO:
			air_para->COD[1]|=0x10;
			break;
		case WIND_MANUAL:
			air_para->COD[1]|=0x20;
			break;
		default:
			break;
	}
}
void vWind_SanLingDianJi388_581(AIR_status *air_status , Air_para *air_para)
{
	switch(air_status->vWind)
	{
		case WIND_AUTO:
			air_para->COD[1]|=0x10;
			break;
		case WIND_MANUAL:
			air_para->COD[1]|=0x00;
			break;
		default:
			break;
	}
}
void Misc_SanLingDianJi388_580(Air_para *air_para)
{
	air_para->COD[0]=~(air_para->COD[1]);
	air_para->COD[2]=~(air_para->COD[3]);
	air_para->COD[4]=0x10;
	air_para->COD[5]=~(air_para->COD[4]);
}
void Misc_SanLingDianJi388_581(Air_para *air_para)
{
	air_para->COD[0]=~(air_para->COD[1]);
	air_para->COD[2]=~(air_para->COD[3]);
	air_para->COD[4]=0x5e;
	air_para->COD[5]=~(air_para->COD[4]);
}
void Misc_SanLingDianJi388_582(Air_para *air_para)
{
	air_para->COD[0]=~(air_para->COD[1]);
	air_para->COD[2]=~(air_para->COD[3]);
	air_para->COD[4]=0x34;
	air_para->COD[5]=~(air_para->COD[4]);
}
void Misc_SanLingDianJi388_583(Air_para *air_para)
{
	air_para->COD[0]=~(air_para->COD[1]);
	air_para->COD[2]=~(air_para->COD[3]);
	air_para->COD[4]=0x1b;
	air_para->COD[5]=~(air_para->COD[4]);
}
void Misc_SanLingDianJi388_584(Air_para *air_para)
{
	air_para->COD[0]=~(air_para->COD[1]);
	air_para->COD[2]=~(air_para->COD[3]);
	air_para->COD[4]=0x3c;
	air_para->COD[5]=~(air_para->COD[4]);
}
void Misc_SanLingDianJi388_585(Air_para *air_para)
{
	air_para->COD[0]=~(air_para->COD[1]);
	air_para->COD[2]=~(air_para->COD[3]);
	air_para->COD[4]=0x13;
	air_para->COD[5]=~(air_para->COD[4]);
}
void Misc_SanLingDianJi388_586(Air_para *air_para)
{
	air_para->COD[0]=~(air_para->COD[1]);
	air_para->COD[2]=~(air_para->COD[3]);
	air_para->COD[4]=0x3d;
	air_para->COD[5]=~(air_para->COD[4]);
}


/*************     5580   (556)     **************/
void AirRemote580(AIR_status *air_status , Air_para *air_para)
{
	Constant_SanLingDianJi388(air_para);
	vPower_SanLingDianJi388(air_status,air_para);
	vMode_SanLingDianJi388_580(air_status,air_para);
	vSpeed_SanLingDianJi388(air_status,air_para);
	vTemper_SanLingDianJi388(air_status,air_para);
	vWind_SanLingDianJi388_580(air_status,air_para);
	Misc_SanLingDianJi388_580(air_para);
}
/*************     5581   (557)     **************/
void AirRemote581(AIR_status *air_status , Air_para *air_para)
{
	Constant_SanLingDianJi388(air_para);
	vPower_SanLingDianJi388(air_status,air_para);
	vMode_SanLingDianJi388(air_status,air_para);
	vSpeed_SanLingDianJi388(air_status,air_para);
	vTemper_SanLingDianJi388(air_status,air_para);
	vWind_SanLingDianJi388_581(air_status,air_para);
	Misc_SanLingDianJi388_581(air_para);
}
/*************     5582   (558)     **************/
void AirRemote582(AIR_status *air_status , Air_para *air_para)
{
	Constant_SanLingDianJi388(air_para);
	vPower_SanLingDianJi388(air_status,air_para);
	vMode_SanLingDianJi388_580(air_status,air_para);
	vSpeed_SanLingDianJi388(air_status,air_para);
	vTemper_SanLingDianJi388(air_status,air_para);
	vWind_SanLingDianJi388_580(air_status,air_para);
	Misc_SanLingDianJi388_582(air_para);
}
/*************     5583   (559)     **************/
void AirRemote583(AIR_status *air_status , Air_para *air_para)
{
	Constant_SanLingDianJi388(air_para);
	vPower_SanLingDianJi388(air_status,air_para);
	vMode_SanLingDianJi388_580(air_status,air_para);
	vSpeed_SanLingDianJi388(air_status,air_para);
	vTemper_SanLingDianJi388(air_status,air_para);
	vWind_SanLingDianJi388_580(air_status,air_para);
	Misc_SanLingDianJi388_583(air_para);
}
/*************     5584   (560)     **************/
void AirRemote584(AIR_status *air_status , Air_para *air_para)
{
	Constant_SanLingDianJi388(air_para);
	vPower_SanLingDianJi388(air_status,air_para);
	vMode_SanLingDianJi388_580(air_status,air_para);
	vSpeed_SanLingDianJi388(air_status,air_para);
	vTemper_SanLingDianJi388(air_status,air_para);
	vWind_SanLingDianJi388_580(air_status,air_para);
	Misc_SanLingDianJi388_584(air_para);
}
/*************     5585   (561)     **************/
void AirRemote585(AIR_status *air_status , Air_para *air_para)
{
	Constant_SanLingDianJi388(air_para);
	vPower_SanLingDianJi388(air_status,air_para);
	vMode_SanLingDianJi388_580(air_status,air_para);
	vSpeed_SanLingDianJi388(air_status,air_para);
	vTemper_SanLingDianJi388(air_status,air_para);
	vWind_SanLingDianJi388_580(air_status,air_para);
	Misc_SanLingDianJi388_585(air_para);
}
/*************     5586   (562)     **************/
void AirRemote586(AIR_status *air_status , Air_para *air_para)
{
	Constant_SanLingDianJi388(air_para);
	vPower_SanLingDianJi388(air_status,air_para);
	vMode_SanLingDianJi388_580(air_status,air_para);
	vSpeed_SanLingDianJi388(air_status,air_para);
	vTemper_SanLingDianJi388(air_status,air_para);
	vWind_SanLingDianJi388_580(air_status,air_para);
	Misc_SanLingDianJi388_586(air_para);
}


/**************		涓夎彵7	***************/
/*************  		鍝佺墝:	涓夎彵 **************/
void Constant_SanLing7(Air_para *air_para)
{
	air_para->CARR=0x20;
	air_para->STRU=0x01;
	air_para->LDH_h=0x07;
	air_para->LDH_l=0x4a;
	air_para->LDL_h=0x09;
	air_para->LDL_l=0x2e;
	air_para->HIG_h=0x00;
	air_para->HIG_l=0x96;
	air_para->ZER_h=0x01;
	air_para->ZER_l=0xe8;
	air_para->ONE_h=0x04;
	air_para->ONE_l=0x44;
	air_para->STO_h=0x09;
	air_para->STO_l=0x4e;
	air_para->BIC0=64;
}
void vPower_SanLing7(AIR_status *air_status , Air_para *air_para)
{
	switch(air_status->vPower)
	{
		case POWER_OFF:
			air_para->COD[5]|=0x00;
			break;
		case POWER_ON:
			air_para->COD[5]|=0x08;
			break;
		default:
			break;
	}
}
void vPower_SanLing7_588(AIR_status *air_status , Air_para *air_para)
{
	switch(air_status->vPower)
	{
		case POWER_OFF:
			air_para->COD[3]|=0x00;
			break;
		case POWER_ON:
			air_para->COD[3]|=0x08;
			break;
		default:
			break;
	}
}

void vMode_SanLing7(AIR_status *air_status , Air_para *air_para)
{
	switch(air_status->vMode)
	{
		case MODE_AUTO:
			air_para->COD[5]|=0x00;
			break;
		case MODE_COLD:
			air_para->COD[5]|=0x01;
			break;
		case MODE_WET:
			air_para->COD[5]|=0x02;
			break;
		case MODE_WIND:
			air_para->COD[5]|=0x03;
			break;
		case MODE_HOT:
			air_para->COD[5]|=0x04;
			break;
		default:
			break;
	}
}
void vMode_SanLing7_588(AIR_status *air_status , Air_para *air_para)
{
	switch(air_status->vMode)
	{
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
}
void vSpeed_SanLing7(AIR_status *air_status , Air_para *air_para)
{
	switch(air_status->vSpeed)
	{
		case SPEED_AUTO:
			air_para->COD[3]|=0x00;
			break;
		case SPEED_LOW:
			air_para->COD[3]|=0x60;
			break;
		case SPEED_MEDIUM:
			air_para->COD[3]|=0x40;
			break;
		case SPEED_HIGH:
			air_para->COD[3]|=0x20;
			break;
		default:
			break;
	}
}
void vSpeed_SanLing7_588(AIR_status *air_status , Air_para *air_para)
{
	switch(air_status->vSpeed)
	{
		case SPEED_AUTO:
			air_para->COD[1]|=0x00;
			break;
		case SPEED_LOW:
			air_para->COD[1]|=0x60;
			break;
		case SPEED_MEDIUM:
			air_para->COD[1]|=0x50;
			break;
		case SPEED_HIGH:
			air_para->COD[1]|=0x40;
			break;
		default:
			break;
	}
}
void vTemper_SanLing7(AIR_status *air_status , Air_para *air_para)
{
	switch(air_status->vTemper)
	{
		case TEMPER_16:
			air_para->COD[5]|=0x10;
			break;
		case TEMPER_17:
			air_para->COD[5]|=0x10;
			break;
		case TEMPER_18:
			air_para->COD[5]|=0x10;
			break;
		case TEMPER_19:
			air_para->COD[5]|=0x20;
			break;
		case TEMPER_20:
			air_para->COD[5]|=0x30;
			break;
		case TEMPER_21:
			air_para->COD[5]|=0x40;
			break;
		case TEMPER_22:
			air_para->COD[5]|=0x50;
			break;
		case TEMPER_23:
			air_para->COD[5]|=0x60;
			break;
		case TEMPER_24:
			air_para->COD[5]|=0x70;
			break;
		case TEMPER_25:
			air_para->COD[5]|=0x80;
			break;
		case TEMPER_26:
			air_para->COD[5]|=0x90;
			break;
		case TEMPER_27:
			air_para->COD[5]|=0xa0;
			break;
		case TEMPER_28:
			air_para->COD[5]|=0xb0;
			break;
		case TEMPER_29:
			air_para->COD[5]|=0xc0;
			break;
		case TEMPER_30:
			air_para->COD[5]|=0xd0;
			break;
		default:
			break;
	}
}
void vTemper_SanLing7_588(AIR_status *air_status , Air_para *air_para)
{
	switch(air_status->vTemper)
	{
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
}
void vWind_SanLing7(AIR_status *air_status , Air_para *air_para)
{
	switch(air_status->vWind)
	{
		case WIND_AUTO:
			air_para->COD[3]|=0x08;
			break;
		case WIND_MANUAL:
			air_para->COD[3]|=0x00;
			break;
		default:
			break;
	}
}
void vWind_SanLing7_588(AIR_status *air_status , Air_para *air_para)
{
	switch(air_status->vWind)
	{
		case WIND_AUTO:
			air_para->COD[1]|=0x00;
			break;
		case WIND_MANUAL:
			air_para->COD[1]|=0x08;
			break;
		default:
			break;
	}
}
void vWind_SanLing7_589(AIR_status *air_status , Air_para *air_para)
{
	switch(air_status->vWind)
	{
		case WIND_AUTO:
			air_para->COD[5]|=0x01;
			break;
		case WIND_MANUAL:
			air_para->COD[5]|=0x04;
			break;
		default:
			break;
	}
}

void Misc_SanLing7_587(Air_para *air_para)
{
	air_para->COD[1]=0x00;
	air_para->COD[7]=0xd5;
	air_para->COD[0]=~(air_para->COD[1]);
	air_para->COD[2]=~(air_para->COD[3]);
	air_para->COD[4]=~(air_para->COD[5]);
	air_para->COD[6]=~(air_para->COD[7]);
}
void Misc_SanLing7_588(Air_para *air_para)
{
	air_para->COD[5]=0x00;
	air_para->COD[7]=0xe3;
	air_para->COD[0]=~(air_para->COD[1]);
	air_para->COD[2]=~(air_para->COD[3]);
	air_para->COD[4]=~(air_para->COD[5]);
	air_para->COD[6]=~(air_para->COD[7]);
}
void Misc_SanLing7_589(Air_para *air_para)
{
	air_para->COD[7]=0xe2;
	air_para->COD[0]=~(air_para->COD[1]);
	air_para->COD[2]=~(air_para->COD[3]);
	air_para->COD[4]=~(air_para->COD[5]);
	air_para->COD[6]=~(air_para->COD[7]);
}


/*************     5587   (564)     **************/
void AirRemote587(AIR_status *air_status , Air_para *air_para)
{
	Constant_SanLing7(air_para);
	vPower_SanLing7(air_status,air_para);
	vMode_SanLing7(air_status,air_para);
	vSpeed_SanLing7(air_status,air_para);
	vTemper_SanLing7(air_status,air_para);
	vWind_SanLing7(air_status,air_para);
	Misc_SanLing7_587(air_para);
}
/*************     5588   (565)     **************/
void AirRemote588(AIR_status *air_status , Air_para *air_para)
{
	Constant_SanLing7(air_para);
	vPower_SanLing7_588(air_status,air_para);
	vMode_SanLing7_588(air_status,air_para);
	vSpeed_SanLing7_588(air_status,air_para);
	vTemper_SanLing7_588(air_status,air_para);
	vWind_SanLing7_588(air_status,air_para);
	Misc_SanLing7_588(air_para);
}
/*************     5589   (566)     **************/
void AirRemote589(AIR_status *air_status , Air_para *air_para)
{
	Constant_SanLing7(air_para);
	vPower_SanLing7_588(air_status,air_para);
	vMode_SanLing7_588(air_status,air_para);
	vSpeed_SanLing7_588(air_status,air_para);
	vTemper_SanLing7_588(air_status,air_para);
	vWind_SanLing7_589(air_status,air_para);
	Misc_SanLing7_589(air_para);
}



/**************		涓夎彵10	***************/
/*************  		鍝佺墝:	涓夎彵 **************/
/*************     5590   (567)     **************/
void AirRemote590(AIR_status *air_status , Air_para *air_para)
{
	air_para->CARR=0x20;
	air_para->STRU=0x01;
	air_para->LDH_h=0x07;
	air_para->LDH_l=0x59;
	air_para->LDL_h=0x09;
	air_para->LDL_l=0x0f;
	air_para->HIG_h=0x00;
	air_para->HIG_l=0xc7;
	air_para->ZER_h=0x01;
	air_para->ZER_l=0xb7;
	air_para->ONE_h=0x04;
	air_para->ONE_l=0x34;
	air_para->STO_h=0x09;
	air_para->STO_l=0x40;
	air_para->BIC0=80;

	switch(air_status->vPower)
	{
		case POWER_OFF:
			air_para->COD[3]|=0x00;
			break;
		case POWER_ON:
			air_para->COD[3]|=0x08;
			break;
		default:
			break;
	}

	switch(air_status->vMode)
	{
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

	switch(air_status->vSpeed)
	{
		case SPEED_AUTO:
			air_para->COD[1]|=0x00;
			break;
		case SPEED_LOW:
			air_para->COD[1]|=0x20;
			break;
		case SPEED_MEDIUM:
			air_para->COD[1]|=0x10;
			break;
		case SPEED_HIGH:
			air_para->COD[1]|=0x08;
			break;
		default:
			break;
	}

	switch(air_status->vTemper)
	{
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

	switch(air_status->vWind)
	{
		case WIND_AUTO:
			air_para->COD[5]|=0x2b;
			break;
		case WIND_MANUAL:
			air_para->COD[5]|=0x23;
			break;
		default:
			break;
	}

	air_para->COD[7]=0x00;
	air_para->COD[9]=0xd0;
	air_para->COD[0]=~(air_para->COD[1]);
	air_para->COD[2]=~(air_para->COD[3]);
	air_para->COD[4]=~(air_para->COD[5]);
	air_para->COD[6]=~(air_para->COD[7]);
	air_para->COD[8]=~(air_para->COD[9]);
}

/*************     5591   (568)     **************/
void AirRemote591(AIR_status *air_status , Air_para *air_para)
{
	air_para->CARR=0x20;
	air_para->STRU=0x01;
	air_para->LDH_h=0x07;
	air_para->LDH_l=0x59;
	air_para->LDL_h=0x09;
	air_para->LDL_l=0x0f;
	air_para->HIG_h=0x00;
	air_para->HIG_l=0xc7;
	air_para->ZER_h=0x01;
	air_para->ZER_l=0xb7;
	air_para->ONE_h=0x04;
	air_para->ONE_l=0x34;
	air_para->STO_h=0x09;
	air_para->STO_l=0x40;
	air_para->BIC0=80;

	switch(air_status->vPower)
	{
		case POWER_OFF:
			air_para->COD[3]|=0x00;
			break;
		case POWER_ON:
			air_para->COD[3]|=0x08;
			break;
		default:
			break;
	}

	switch(air_status->vMode)
	{
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

	switch(air_status->vSpeed)
	{
		case SPEED_AUTO:
			air_para->COD[1]|=0x00;
			break;
		case SPEED_LOW:
			air_para->COD[1]|=0x00;
			break;
		case SPEED_MEDIUM:
			air_para->COD[1]|=0x40;
			break;
		case SPEED_HIGH:
			air_para->COD[1]|=0x40;
			break;
		default:
			break;
	}

	switch(air_status->vTemper)
	{
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

	switch(air_status->vWind)
	{
		case WIND_AUTO:
			air_para->COD[5]|=0x01;
			break;
		case WIND_MANUAL:
			air_para->COD[5]|=0x06;
			break;
		default:
			break;
	}

	air_para->COD[7]=0x0d;
	air_para->COD[9]=0xe8;
	air_para->COD[0]=~(air_para->COD[1]);
	air_para->COD[2]=~(air_para->COD[3]);
	air_para->COD[4]=~(air_para->COD[5]);
	air_para->COD[6]=~(air_para->COD[7]);
	air_para->COD[8]=~(air_para->COD[9]);
}

/*************     5592   (570)     **************/
void AirRemote592(AIR_status *air_status , Air_para *air_para)
{
	air_para->CARR=0x20;
	air_para->STRU=0x01;
	air_para->LDH_h=0x07;
	air_para->LDH_l=0x59;
	air_para->LDL_h=0x09;
	air_para->LDL_l=0x0f;
	air_para->HIG_h=0x00;
	air_para->HIG_l=0xc7;
	air_para->ZER_h=0x01;
	air_para->ZER_l=0xb7;
	air_para->ONE_h=0x04;
	air_para->ONE_l=0x34;
	air_para->STO_h=0x09;
	air_para->STO_l=0x40;
	air_para->BIC0=80;

	switch(air_status->vPower)
	{
		case POWER_OFF:
			air_para->COD[5]|=0x00;
			break;
		case POWER_ON:
			air_para->COD[5]|=0x20;
			break;
		default:
			break;
	}

	switch(air_status->vMode)
	{
		case MODE_AUTO:
			air_para->COD[5]|=0x00;
			break;
		case MODE_COLD:
			air_para->COD[5]|=0x08;
			break;
		case MODE_WET:
			air_para->COD[5]|=0x10;
			break;
		case MODE_WIND:
			air_para->COD[5]|=0x00;
			break;
		case MODE_HOT:
			air_para->COD[5]|=0x18;
			break;
		default:
			break;
	}

	switch(air_status->vSpeed)
	{
		case SPEED_AUTO:
			air_para->COD[5]|=0x00;
			break;
		case SPEED_LOW:
			air_para->COD[5]|=0x06;
			break;
		case SPEED_MEDIUM:
			air_para->COD[5]|=0x04;
			break;
		case SPEED_HIGH:
			air_para->COD[5]|=0x02;
			break;
		default:
			break;
	}

	switch(air_status->vTemper)
	{
		case TEMPER_16:
			air_para->COD[3]|=0x21;
			break;
		case TEMPER_17:
			air_para->COD[3]|=0x21;
			break;
		case TEMPER_18:
			air_para->COD[3]|=0x21;
			break;
		case TEMPER_19:
			air_para->COD[3]|=0x22;
			break;
		case TEMPER_20:
			air_para->COD[3]|=0x23;
			break;
		case TEMPER_21:
			air_para->COD[3]|=0x24;
			break;
		case TEMPER_22:
			air_para->COD[3]|=0x25;
			break;
		case TEMPER_23:
			air_para->COD[3]|=0x26;
			break;
		case TEMPER_24:
			air_para->COD[3]|=0x27;
			break;
		case TEMPER_25:
			air_para->COD[3]|=0x28;
			break;
		case TEMPER_26:
			air_para->COD[3]|=0x29;
			break;
		case TEMPER_27:
			air_para->COD[3]|=0x2a;
			break;
		case TEMPER_28:
			air_para->COD[3]|=0x2b;
			break;
		case TEMPER_29:
			air_para->COD[3]|=0x2c;
			break;
		case TEMPER_30:
			air_para->COD[3]|=0x2d;
			break;
		default:
			break;
	}

	switch(air_status->vWind)
	{
		case WIND_AUTO:
			air_para->COD[1]|=0x40;
			break;
		case WIND_MANUAL:
			air_para->COD[1]|=0x80;
			break;
		default:
			break;
	}

	air_para->COD[7]=0x00;
	air_para->COD[9]=0xd2;
	air_para->COD[0]=~(air_para->COD[1]);
	air_para->COD[2]=~(air_para->COD[3]);
	air_para->COD[4]=~(air_para->COD[5]);
	air_para->COD[6]=~(air_para->COD[7]);
	air_para->COD[8]=~(air_para->COD[9]);
}


/**************		涓夎彵12	 ***************/
/*************  		鍝佺墝:	涓夎彵 **************/
/*************     5593   (569)     **************/
void AirRemote593(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;
	air_para->LDH_h=0x03;
	air_para->LDH_l=0xd4;
	air_para->LDL_h=0x01;
	air_para->LDL_l=0xfc;
	air_para->HIG_h=0x00;
	air_para->HIG_l=0x82;
	air_para->ZER_h=0x00;
	air_para->ZER_l=0x84;
	air_para->ONE_h=0x01;
	air_para->ONE_l=0x79;
	air_para->BIC0=88;

	switch(air_status->vPower)
	{
		case POWER_OFF:
			air_para->COD[10]|=0x00;
			break;
		case POWER_ON:
			air_para->COD[10]|=0x08;
			break;
		default:
			break;
	}

	switch(air_status->vMode)
	{
		case MODE_AUTO:
			air_para->COD[10]|=0x00;
			break;
		case MODE_COLD:
			air_para->COD[10]|=0x01;
			break;
		case MODE_WET:
			air_para->COD[10]|=0x02;
			break;
		case MODE_WIND:
			air_para->COD[10]|=0x03;
			break;
		case MODE_HOT:
			air_para->COD[10]|=0x04;
			break;
		default:
			break;
	}

	switch(air_status->vSpeed)
	{
		case SPEED_AUTO:
			air_para->COD[8]|=0x00;
			break;
		case SPEED_LOW:
			air_para->COD[8]|=0x20;
			break;
		case SPEED_MEDIUM:
			air_para->COD[8]|=0x60;
			break;
		case SPEED_HIGH:
			air_para->COD[8]|=0xa0;
			break;
		default:
			break;
	}

	switch(air_status->vTemper)
	{
		case TEMPER_16:
			air_para->COD[10]|=0x10;
			break;
		case TEMPER_17:
			air_para->COD[10]|=0x10;
			break;
		case TEMPER_18:
			air_para->COD[10]|=0x10;
			break;
		case TEMPER_19:
			air_para->COD[10]|=0x20;
			break;
		case TEMPER_20:
			air_para->COD[10]|=0x30;
			break;
		case TEMPER_21:
			air_para->COD[10]|=0x40;
			break;
		case TEMPER_22:
			air_para->COD[10]|=0x50;
			break;
		case TEMPER_23:
			air_para->COD[10]|=0x60;
			break;
		case TEMPER_24:
			air_para->COD[10]|=0x70;
			break;
		case TEMPER_25:
			air_para->COD[10]|=0x80;
			break;
		case TEMPER_26:
			air_para->COD[10]|=0x90;
			break;
		case TEMPER_27:
			air_para->COD[10]|=0xa0;
			break;
		case TEMPER_28:
			air_para->COD[10]|=0xb0;
			break;
		case TEMPER_29:
			air_para->COD[10]|=0xc0;
			break;
		case TEMPER_30:
			air_para->COD[10]|=0xd0;
			break;
		default:
			break;
	}

	switch(air_status->vWind)
	{
		case WIND_AUTO:
			air_para->COD[0]|=0x08;
			break;
		case WIND_MANUAL:
			air_para->COD[0]|=0x00;
			break;
		default:
			break;
	}

	air_para->COD[0]=0x52;
	air_para->COD[1]=0xae;
	air_para->COD[2]=0xc3;
	air_para->COD[4]=0xd9;
	air_para->COD[6]=0x00;
	air_para->COD[3]=~(air_para->COD[4]);
	air_para->COD[5]=~(air_para->COD[6]);
	air_para->COD[7]=~(air_para->COD[8]);
	air_para->COD[9]=~(air_para->COD[10]);
}

/*************     5594   (571)     **************/
void AirRemote594(AIR_status *air_status , Air_para *air_para){
	air_para->CARR=0x20;
	air_para->STRU=0x00;
	air_para->LDH_h=0x03;
	air_para->LDH_l=0xd4;
	air_para->LDL_h=0x01;
	air_para->LDL_l=0xfc;
	air_para->HIG_h=0x00;
	air_para->HIG_l=0x82;
	air_para->ZER_h=0x00;
	air_para->ZER_l=0x84;
	air_para->ONE_h=0x01;
	air_para->ONE_l=0x79;
	air_para->BIC0=88;

	switch(air_status->vPower)
	{
		case POWER_OFF:
			air_para->COD[10]|=0x00;
			break;
		case POWER_ON:
			air_para->COD[10]|=0x08;
			break;
		default:
			break;
	}

	switch(air_status->vMode)
	{
		case MODE_AUTO:
			air_para->COD[10]|=0x00;
			break;
		case MODE_COLD:
			air_para->COD[10]|=0x01;
			break;
		case MODE_WET:
			air_para->COD[10]|=0x02;
			break;
		case MODE_WIND:
			air_para->COD[10]|=0x03;
			break;
		case MODE_HOT:
			air_para->COD[10]|=0x04;
			break;
		default:
			break;
	}

	switch(air_status->vSpeed)
	{
		case SPEED_AUTO:
			air_para->COD[8]|=0x00;
			break;
		case SPEED_LOW:
			air_para->COD[8]|=0x40;
			break;
		case SPEED_MEDIUM:
			air_para->COD[8]|=0x60;
			break;
		case SPEED_HIGH:
			air_para->COD[8]|=0x80;
			break;
		default:
			break;
	}

	switch(air_status->vTemper)
	{
		case TEMPER_16:
			air_para->COD[10]|=0x10;
			break;
		case TEMPER_17:
			air_para->COD[10]|=0x10;
			break;
		case TEMPER_18:
			air_para->COD[10]|=0x10;
			break;
		case TEMPER_19:
			air_para->COD[10]|=0x20;
			break;
		case TEMPER_20:
			air_para->COD[10]|=0x30;
			break;
		case TEMPER_21:
			air_para->COD[10]|=0x40;
			break;
		case TEMPER_22:
			air_para->COD[10]|=0x50;
			break;
		case TEMPER_23:
			air_para->COD[10]|=0x60;
			break;
		case TEMPER_24:
			air_para->COD[10]|=0x70;
			break;
		case TEMPER_25:
			air_para->COD[10]|=0x80;
			break;
		case TEMPER_26:
			air_para->COD[10]|=0x90;
			break;
		case TEMPER_27:
			air_para->COD[10]|=0xa0;
			break;
		case TEMPER_28:
			air_para->COD[10]|=0xb0;
			break;
		case TEMPER_29:
			air_para->COD[10]|=0xc0;
			break;
		case TEMPER_30:
			air_para->COD[10]|=0xd0;
			break;
		default:
			break;
	}

	switch(air_status->vWind)
	{
		case WIND_AUTO:
			air_para->COD[6]|=0xc8;
			break;
		case WIND_MANUAL:
			air_para->COD[6]|=0x82;
			switch(air_status->vManualWind){
				case MANUAL_WIND_1:
					air_para->COD[8]|=0x00;
					break;
				case MANUAL_WIND_2:
					air_para->COD[8]|=0x08;
					break;
				case MANUAL_WIND_3:
					air_para->COD[8]|=0x10;
					break;
				case MANUAL_WIND_4:
					air_para->COD[8]|=0x18;
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}

	air_para->COD[0]=0x52;
	air_para->COD[1]=0xae;
	air_para->COD[2]=0xc3;
	air_para->COD[4]=0xd9;
	air_para->COD[3]=~(air_para->COD[4]);
	air_para->COD[5]=~(air_para->COD[6]);
	air_para->COD[7]=~(air_para->COD[8]);
	air_para->COD[9]=~(air_para->COD[10]);
}


/**************		涓夎彵鐢垫満(388) 	***************/
/*************  		鍝佺墝:	涓夎彵 **************/
/*************    	 5595   (572)     **************/
void AirRemote595(AIR_status *air_status , Air_para *air_para)
{
	Constant_SanLingDianJi388(air_para);
	vPower_SanLingDianJi388(air_status,air_para);
	vMode_SanLingDianJi388(air_status,air_para);
	vSpeed_SanLingDianJi388_595(air_status,air_para);
	vTemper_SanLingDianJi388(air_status,air_para);
	vWind_SanLingDianJi388_580(air_status,air_para);
	Misc_SanLingDianJi388_581(air_para);
}



/**************		涓夎彵閲嶅伐(09NV)	 ***************/
/*************  		鍝佺墝:	涓夎彵 **************/
void Constant_SanLing09NV(Air_para *air_para)
{
	air_para->CARR=0x20;
	air_para->STRU=0x00;
	air_para->LDH_h=0x04;
	air_para->LDH_l=0x33;
	air_para->LDL_h=0x02;
	air_para->LDL_l=0x13;
	air_para->HIG_h=0x00;
	air_para->HIG_l=0x8d;
	air_para->ZER_h=0x00;
	air_para->ZER_l=0x81;
	air_para->ONE_h=0x01;
	air_para->ONE_l=0x86;
	air_para->BIC0=112;
}
void vPower_SanLing09NV(AIR_status *air_status , Air_para *air_para)
{
	switch(air_status->vPower)
	{
		case POWER_OFF:
			air_para->COD[5]=0x20;
			break;
		case POWER_ON:
			air_para->COD[5]=0x24;
			break;
		default:
			break;
	}
}
void vPower_SanLing09NV_1(AIR_status *air_status , Air_para *air_para)
{
	switch(air_status->vPower)
	{
		case POWER_OFF:
			air_para->COD[5]=0xa0;
			break;
		case POWER_ON:
			air_para->COD[5]=0xa4;
			break;
		default:
			break;
	}
}
void vMode_SanLing09NV(AIR_status *air_status , Air_para *air_para)
{
	switch(air_status->vMode)
	{
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
}
void vMode_SanLing09NV_1(AIR_status *air_status , Air_para *air_para)
{
	switch(air_status->vMode)
	{
		case MODE_AUTO:
			air_para->COD[6]=0x0b;
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
}
void vSpeed_SanLing09NV(AIR_status *air_status , Air_para *air_para)
{
	switch(air_status->vSpeed)
	{
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
}
void vTemper_SanLing09NV(AIR_status *air_status , Air_para *air_para)
{
	switch(air_status->vTemper)
	{
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
}
void vWind_SanLing09NV(AIR_status *air_status , Air_para *air_para)
{
	switch(air_status->vWind)
	{
		case WIND_AUTO:
			air_para->COD[8]|=0x38;
			break;
		case WIND_MANUAL:
			switch(air_status->vManualWind)
			{
				case MANUAL_WIND_1:
					air_para->COD[8]|=0x08;
					break;
				case MANUAL_WIND_2:
					air_para->COD[8]|=0x10;
					break;
				case MANUAL_WIND_3:
					air_para->COD[8]|=0x18;
					break;
				case MANUAL_WIND_4:
					air_para->COD[8]|=0x20;
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
}
void vWind_SanLing09NV_1(AIR_status *air_status , Air_para *air_para)
{
	switch(air_status->vWind)
	{
		case WIND_AUTO:
			air_para->COD[8]|=0x00;
			break;
		case WIND_MANUAL:
			switch(air_status->vManualWind)
			{
				case MANUAL_WIND_1:
					air_para->COD[8]|=0x08;
					break;
				case MANUAL_WIND_2:
					air_para->COD[8]|=0x10;
					break;
				case MANUAL_WIND_3:
					air_para->COD[8]|=0x18;
					break;
				case MANUAL_WIND_4:
					air_para->COD[8]|=0x20;
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
}
void vWind_SanLing09NV_2(AIR_status *air_status , Air_para *air_para)
{
	switch(air_status->vWind)
	{
		case WIND_AUTO:
			air_para->COD[8]|=0x00;
			break;
		case WIND_MANUAL:
			air_para->COD[8]|=0x08;
			break;
		default:
			break;
	}
}
void vWind_SanLing09NV_3(AIR_status *air_status , Air_para *air_para)
{
	switch(air_status->vWind)
	{
		case WIND_AUTO:
			air_para->COD[8]|=0x02;
			break;
		case WIND_MANUAL:
			air_para->COD[8]|=0x0a;
			break;
		default:
			break;
	}
}
void Misc_SanLing09NV(Air_para *air_para)
{
	air_para->COD[0]=0x23;
	air_para->COD[1]=0xcb;
	air_para->COD[2]=0x26;
	air_para->COD[3]=0x01;
	air_para->COD[13]=Sumarray(13,air_para);
}

/*************     5596   (578)     **************/
void AirRemote596(AIR_status *air_status , Air_para *air_para)
{
	Constant_SanLing09NV(air_para);
	vPower_SanLing09NV_1(air_status,air_para);
	vMode_SanLing09NV(air_status,air_para);
	vSpeed_SanLing09NV(air_status,air_para);
	vTemper_SanLing09NV(air_status,air_para);
	air_para->COD[7]|=0x80;
	vWind_SanLing09NV_1(air_status,air_para);
	Misc_SanLing09NV(air_para);
}
/*************     5597   (579)     **************/
void AirRemote597(AIR_status *air_status , Air_para *air_para)
{
	Constant_SanLing09NV(air_para);
	vPower_SanLing09NV(air_status,air_para);
	vMode_SanLing09NV_1(air_status,air_para);
	vSpeed_SanLing09NV(air_status,air_para);
	vTemper_SanLing09NV(air_status,air_para);
	air_para->COD[7]|=0x20;
	vWind_SanLing09NV_2(air_status,air_para);
	Misc_SanLing09NV(air_para);
}
/*************     5598   (580)     **************/
void AirRemote598(AIR_status *air_status , Air_para *air_para)
{
	Constant_SanLing09NV(air_para);
	vPower_SanLing09NV(air_status,air_para);
	vMode_SanLing09NV_1(air_status,air_para);
	vSpeed_SanLing09NV(air_status,air_para);
	vTemper_SanLing09NV(air_status,air_para);
	air_para->COD[7]|=0x20;
	vWind_SanLing09NV_3(air_status,air_para);
	Misc_SanLing09NV(air_para);
}


/**************		涓夎彵4	 ***************/
/*************  		鍝佺墝:	涓夎彵 **************/
void Constant_SanLing4(AIR_status *air_status , Air_para *air_para)
{
	air_para->CARR=0x20;
	air_para->STRU=0x02;

	air_para->LDH_h=0x07;
	air_para->LDH_l=0x46;

	air_para->LDL_h=0x02;
	air_para->LDL_l=0x6a;

	air_para->HIG_h=0x00;
	air_para->HIG_l=0xa6;

	air_para->ZER_h=0x00;
	air_para->ZER_l=0xf2;

	air_para->ONE_h=0x02;
	air_para->ONE_l=0x5a;

	air_para->STO_h=0x0b;
	air_para->STO_l=0xa3;

	air_para->BIC0=51;
	air_para->BIC1=51;

	switch(air_status->vPower)
	{
		case POWER_OFF:
			air_para->COD[0]=0x90;
			break;
		case POWER_ON:
			air_para->COD[0]=0x93;
			break;
		default:
			break;
	}

	switch(air_status->vMode)
	{
		case MODE_AUTO:
			air_para->COD[1]=0x88;
			break;
		case MODE_COLD:
			air_para->COD[1]=0x83;
			break;
		case MODE_WET:
			air_para->COD[1]=0x82;
			break;
		case MODE_WIND:
			air_para->COD[1]=0x87;
			break;
		case MODE_HOT:
			air_para->COD[1]=0x81;
			break;
		default:
			break;
	}

	switch(air_status->vSpeed)
	{
		case SPEED_AUTO:
			air_para->COD[2]|=0x08;
			break;
		case SPEED_LOW:
			air_para->COD[2]|=0x0d;
			break;
		case SPEED_MEDIUM:
			air_para->COD[2]|=0x0b;
			break;
		case SPEED_HIGH:
			air_para->COD[2]|=0x09;
			break;
		default:
			break;
	}

	switch(air_status->vTemper)
	{
		case TEMPER_16:
			air_para->COD[2]|=0xf0;
			break;
		case TEMPER_17:
			air_para->COD[2]|=0xe0;
			break;
		case TEMPER_18:
			air_para->COD[2]|=0xd0;
			break;
		case TEMPER_19:
			air_para->COD[2]|=0xc0;
			break;
		case TEMPER_20:
			air_para->COD[2]|=0xb0;
			break;
		case TEMPER_21:
			air_para->COD[2]|=0xa0;
			break;
		case TEMPER_22:
			air_para->COD[2]|=0x90;
			break;
		case TEMPER_23:
			air_para->COD[2]|=0x80;
			break;
		case TEMPER_24:
			air_para->COD[2]|=0x70;
			break;
		case TEMPER_25:
			air_para->COD[2]|=0x60;
			break;
		case TEMPER_26:
			air_para->COD[2]|=0x50;
			break;
		case TEMPER_27:
			air_para->COD[2]|=0x40;
			break;
		case TEMPER_28:
			air_para->COD[2]|=0x30;
			break;
		case TEMPER_29:
			air_para->COD[2]|=0x20;
			break;
		case TEMPER_30:
			air_para->COD[2]|=0x10;
			break;
		default:
			break;
	}

	air_para->COD[4]=0x00;
	air_para->COD[5]=0x00;
	air_para->COD[6]=0x00;
}
void vWind_SanLing4(AIR_status *air_status , Air_para *air_para)
{
	switch(air_status->vWind)
	{
		case WIND_AUTO:
			air_para->COD[3]|=0x0e;
			break;
		case WIND_MANUAL:
			switch(air_status->vManualWind)
			{
				case MANUAL_WIND_1:
					air_para->COD[3]|=0x09;
					break;
				case MANUAL_WIND_2:
					air_para->COD[3]|=0x0a;
					break;
				case MANUAL_WIND_3:
					air_para->COD[3]|=0x0b;
					break;
				case MANUAL_WIND_4:
					air_para->COD[3]|=0x0c;
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
}
void vWind_SanLing4_1(AIR_status *air_status , Air_para *air_para)
{
	switch(air_status->vWind)
	{
		case WIND_AUTO:
			air_para->COD[3]|=0x0f;
			break;
		case WIND_MANUAL:
			air_para->COD[3]|=0x08;
			break;
		default:
			break;
	}
}
/*************     5599   (583)     **************/
void AirRemote599(AIR_status *air_status , Air_para *air_para)
{
	Constant_SanLing4(air_status,air_para);
	vWind_SanLing4_1(air_status,air_para);
}
/*************     5600   (584)     **************/
void AirRemote600(AIR_status *air_status , Air_para *air_para)
{
	Constant_SanLing4(air_status,air_para);
	vWind_SanLing4_1(air_status,air_para);
}

void AirRemote900(AIR_status *air_status, unsigned char *vAirBuffer)
{
	memset(vAirBuffer,0,128);

	switch(air_status->vMode){
		case MODE_AUTO:
			vAirBuffer[30]=0x00;
			break;

		case MODE_COLD:
			vAirBuffer[30]=0x01;
			break;

		case MODE_WET:
			vAirBuffer[30]=0x02;
			break;

		case MODE_WIND:
			vAirBuffer[30]=0x03;
			break;

		case MODE_HOT:
			vAirBuffer[30]=0x04;
			break;

		default:
			break;
	}


	switch(air_status->vWind){

		case WIND_AUTO:
			vAirBuffer[30]|= 0x40;
			vAirBuffer[41]= 0x01;
			break;

		case WIND_MANUAL:
			switch(air_status->vManualWind){
				case MANUAL_WIND_1:
					vAirBuffer[41]=0x02;
					break;
				case MANUAL_WIND_2:
					vAirBuffer[41]=0x03;
					break;
				case MANUAL_WIND_3:
					vAirBuffer[41]=0x04;
					break;
				case MANUAL_WIND_4:
					vAirBuffer[41]=0x05;
					break;
				default:
					break;
			}
			break;

		default:
			break;
	}


	switch(air_status->vSpeed){

		case SPEED_AUTO:
			vAirBuffer[30]|=0x00;
			vAirBuffer[65]|=0x00;
			break;

		case SPEED_LOW:
			vAirBuffer[30]|=0x10;
			vAirBuffer[65]|=0x10;
			break;

		case SPEED_MEDIUM:
			vAirBuffer[30]|=0x20;
			vAirBuffer[65]|=0x20;
			break;

		case SPEED_HIGH:
			vAirBuffer[30]|=0x30;
			vAirBuffer[65]|=0x30;
			break;

		default:
			break;
	}


	switch(air_status->vPower){

		case POWER_ON:
			vAirBuffer[30]|=0x08;
			break;

		default:
			break;
	}

	switch(air_status->vTemper){

		case TEMPER_16:
			vAirBuffer[31]=0x00;
			break;

		case TEMPER_17:
			vAirBuffer[31]=0x01;
			break;

		case TEMPER_18:
			vAirBuffer[31]=0x02;
			break;

		case TEMPER_19:
			vAirBuffer[31]=0x03;
			break;

		case TEMPER_20:
			vAirBuffer[31]=0x04;
			break;

		case TEMPER_21:
			vAirBuffer[31]=0x05;
			break;

		case TEMPER_22:
			vAirBuffer[31]=0x06;
			break;

		case TEMPER_23:
			vAirBuffer[31]=0x07;
			break;

		case TEMPER_24:
			vAirBuffer[31]=0x08;
			break;

		case TEMPER_25:
			vAirBuffer[31]=0x09;
			break;

		case TEMPER_26:
			vAirBuffer[31]=0x0a;
			break;

		case TEMPER_27:
			vAirBuffer[31]=0x0b;
			break;

		case TEMPER_28:
			vAirBuffer[31]=0x0c;
			break;

		case TEMPER_29:
			vAirBuffer[31]=0x0d;
			break;

		case TEMPER_30:
			vAirBuffer[31]=0x0e;
			break;

		default:
			break;
	}


	vAirBuffer[0]=0x7e;
	vAirBuffer[1]=0x20;
	vAirBuffer[2]=0x00;
	vAirBuffer[3]=0x98;

	vAirBuffer[4]=0x80;
	vAirBuffer[5]=0xcb;
	vAirBuffer[6]=0x00;
	vAirBuffer[7]=0xaf;

	vAirBuffer[8]=0x80;
	vAirBuffer[9]=0xcb;
	vAirBuffer[10]=0x02;
	vAirBuffer[11]=0x06;

	vAirBuffer[12]=0x0a;
	vAirBuffer[13]=0xfc;
	vAirBuffer[14]=0x05;
	vAirBuffer[15]=0x7e;

	vAirBuffer[16]=0x00;
	vAirBuffer[17]=0xcb;
	vAirBuffer[18]=0x18;
	vAirBuffer[19]=0x6a;

	vAirBuffer[20]=0x00;
	vAirBuffer[21]=0xcb;
	vAirBuffer[22]=0x30;
	vAirBuffer[23]=0xd4;

	vAirBuffer[24]=SPECIAL_Airet4003;
	vAirBuffer[25]=1;
	vAirBuffer[26]=0<<2;

	vAirBuffer[27]=LOGIC_Airet4003;
	vAirBuffer[28]=4;
	vAirBuffer[29]=3;
	//vAirBuffer[30]=;
	//vAirBuffer[31]=;
	vAirBuffer[32]=0x20;
	vAirBuffer[33]=0x50;
	vAirBuffer[34]=0x02;

	vAirBuffer[35]=SPECIAL_Airet4003;
	vAirBuffer[36]=1;
	vAirBuffer[37]=1<<2;

	vAirBuffer[38]=LOGIC_Airet4003;
	vAirBuffer[39]=4;
	vAirBuffer[40]=0;
	//vAirBuffer[41]=;
	vAirBuffer[42]=0x20;
	vAirBuffer[43]=0x00;
	//vAirBuffer[44]=;
	vAirBuffer[44]=vAirBuffer[31]+vAirBuffer[30];
	vAirBuffer[44]-=4;
	vAirBuffer[44]+=(vAirBuffer[41]>>4);
	vAirBuffer[44]<<=4;


	vAirBuffer[45]=SPECIAL_Airet4003;
	vAirBuffer[46]=2;
	vAirBuffer[47]=2<<2;
	vAirBuffer[48]=0<<2;

	vAirBuffer[49]=LOGIC_Airet4003;
	vAirBuffer[50]=4;
	vAirBuffer[51]=3;
	vAirBuffer[52]=vAirBuffer[30];
	vAirBuffer[53]=vAirBuffer[31];
	vAirBuffer[54]=0x20;
	vAirBuffer[55]=0x70;
	vAirBuffer[56]=0x02;

	vAirBuffer[57]=SPECIAL_Airet4003;
	vAirBuffer[58]=1;
	vAirBuffer[59]=1<<2;

	vAirBuffer[60]=LOGIC_Airet4003;
	vAirBuffer[61]=4;
	vAirBuffer[62]=0;
	vAirBuffer[63]=0x00;
	vAirBuffer[64]=0x00;
	//vAirBuffer[65]=0x10;
	//vAirBuffer[66]=;
	vAirBuffer[66]=vAirBuffer[53]+(vAirBuffer[52]&0x0f);
	vAirBuffer[66]-=6;
	vAirBuffer[66]+=(vAirBuffer[65]>>4);
	vAirBuffer[66]<<=4;

	vAirBuffer[67]=SPECIAL_Airet4003;
	vAirBuffer[68]=1;
	vAirBuffer[69]=1<<2;

	vAirBuffer[70]=END_Airet4003;




}




unsigned char vAirBuffer6122G[]={0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x0a,0xfc,0x05,0x7e,0x00,0xaf,0x00,0xaf,0x02,0x0d,0x02,0xbf,0x00,0x00,0x00,0x00,0x32,0x6a,0x73,0x4c};

/**************		锟铰匡拷斯6121G	***************/
/*************     5901        **************/
void AirRemote901(AIR_status *air_status, unsigned char *vAirBuffer)
{
	memset(vAirBuffer,0,128);
	memcpy(vAirBuffer,vAirBuffer6122G,sizeof(vAirBuffer6122G));
	vAirBuffer[1]=0x01;
	vAirBuffer[2]=0x7e;
	switch(air_status->vKey)
	{
		case POWER_KEY:
			vAirBuffer[3]=0x08;
			break;
		case MODE_KEY:
		
		switch(air_status->vMode)
			{
			case MODE_COLD:
			vAirBuffer[3]=0x12;
			break;
			case MODE_WET:
			vAirBuffer[3]=0x11;
			break;
			case MODE_HOT:
			vAirBuffer[3]=0x10;
			break;
			default:
			break;
			}
		
		break;
		case SPEED_KEY:
			vAirBuffer[3]=0x04;
			break;
		case TEMPER_INC_KEY:
			vAirBuffer[3]=0x0d;
			break;
		case TEMPER_DEC_KEY:
			vAirBuffer[3]=0x05;
			break;
		case WIND_MANUAL_KEY:
			vAirBuffer[3]=0x0c;
			break;
		//case WIND_AUTO_KEY:
		//	vAirBuffer[3]=0x04;
		//	break;
		default:
			break;
	}
	

}

/**************	锟斤拷锟斤拷6121G	***************/
/*************     5902    (173)    **************/
void AirRemote902(AIR_status *air_status, unsigned char *vAirBuffer)
{
	memset(vAirBuffer,0,128);
	memcpy(vAirBuffer,vAirBuffer6122G,sizeof(vAirBuffer6122G));

	vAirBuffer[1]=0x08;
	vAirBuffer[2]=0xf7;

	switch(air_status->vKey)
	{
		case POWER_KEY:
			vAirBuffer[3]=0x38;
			break;
		case MODE_KEY:
			vAirBuffer[3]=0xb0;
			break;
		case SPEED_KEY:
			vAirBuffer[3]=0x30;
			break;
		case TEMPER_INC_KEY:
			vAirBuffer[3]=0x28;
			break;
		case TEMPER_DEC_KEY:
			vAirBuffer[3]=0x18;
			break;
		case WIND_MANUAL_KEY:
			vAirBuffer[3]=0x08;
			break;
		default:
			break;
	}
}




/**************		锟斤拷锟斤拷RCH-2609	***************/
/*************     5903       **************/
void AirRemote903(AIR_status *air_status, unsigned char *vAirBuffer)
{

	memset(vAirBuffer,0,128);
	
	vAirBuffer[0]=0x7e;
	vAirBuffer[1]=0x20;
	vAirBuffer[2]=0x00;
	vAirBuffer[3]=0x94;
	
	vAirBuffer[4]=0x80;
	vAirBuffer[5]=0xb2;
	vAirBuffer[6]=0x00;
	vAirBuffer[7]=0xb2;
	
	vAirBuffer[8]=0x80;
	vAirBuffer[9]=0xb2;
	vAirBuffer[10]=0x02;
	vAirBuffer[11]=0x0b;

	vAirBuffer[12]=0x0a;
	vAirBuffer[13]=0xef;
	vAirBuffer[14]=0x05;
	vAirBuffer[15]=0x77;
	
	vAirBuffer[16]=0x00;
	vAirBuffer[17]=0xb2;
	vAirBuffer[18]=0x09;
	vAirBuffer[19]=0xa3;

	vAirBuffer[20]=SPECIAL_Airet4003;
	vAirBuffer[21]=1;
	vAirBuffer[22]=0<<2;
	
	vAirBuffer[23]=LOGIC_Airet4003;
	vAirBuffer[24]=6;
	vAirBuffer[25]=0;
	vAirBuffer[26]=0x83;
	vAirBuffer[27]=0x06;
	if (air_status->vKey==POWER_KEY){
		vAirBuffer[28]=0x04;
		}else {
		vAirBuffer[28]=0x00;
			}

	vAirBuffer[29]=air_hisense903_temp[air_status->vTemper];
	vAirBuffer[29] |=air_hisense903_mode[air_status->vMode];
	vAirBuffer[30]=0x00;
	vAirBuffer[31]=0x00;

	vAirBuffer[32]=SPECIAL_Airet4003;
	vAirBuffer[33]=1;
	vAirBuffer[34]=1<<2;
	
	vAirBuffer[35]=LOGIC_Airet4003;
	vAirBuffer[36]=8;
	vAirBuffer[37]=0;
	vAirBuffer[38]=0x00;
	vAirBuffer[39]=0x00;
	
	if (air_status->vWind==WIND_AUTO){
			vAirBuffer[40]=0x80;
			}else {
			vAirBuffer[40]=0x00;
				}
	vAirBuffer[41]=0x00;
	vAirBuffer[42]=0x00;
	vAirBuffer[43]=0x00;
	vAirBuffer[44]=0x00;
	vAirBuffer[45]=vAirBuffer[28]+vAirBuffer[29]+vAirBuffer[40];

	vAirBuffer[46]=SPECIAL_Airet4003;
	vAirBuffer[47]=1;
	vAirBuffer[48]=1<<2;

	vAirBuffer[49]=LOGIC_Airet4003;
	vAirBuffer[50]=7;
	vAirBuffer[51]=0;
	vAirBuffer[52]=0x00;
	vAirBuffer[53]=air_hisense903_key[air_status->vKey];
	vAirBuffer[54]=0x00;
	vAirBuffer[55]=0x00;
	vAirBuffer[56]=0x00;
	vAirBuffer[57]=0x00;
	vAirBuffer[58]=air_hisense903_key[air_status->vKey];

	vAirBuffer[59]=SPECIAL_Airet4003;
	vAirBuffer[60]=1;
	vAirBuffer[61]=1<<2;

	vAirBuffer[62]=END_Airet4003;

/***********************************
		锟秸碉拷状态锟斤拷卮锟斤拷锟�
***********************************/




	
}


/**************		HISENSE01	***************/
/*************            **************/
	void AirRemote904(AIR_status *air_status, unsigned char *vAirBuffer){


	vAirBuffer[0]=0x7e;
	vAirBuffer[1]=0x20;
	vAirBuffer[2]=0x00;
	vAirBuffer[3]=0x94;
	
	vAirBuffer[4]=0x81;
	vAirBuffer[5]=0x25;
	vAirBuffer[6]=0x01;
	vAirBuffer[7]=0x33;
	
	vAirBuffer[8]=0x01;
	vAirBuffer[9]=0x22;
	vAirBuffer[10]=0x81;
	vAirBuffer[11]=0x30;

	vAirBuffer[12]=0x03;
	vAirBuffer[13]=0x7b;
	vAirBuffer[14]=0x03;
	vAirBuffer[15]=0xa0;
	
	vAirBuffer[16]=0x04;
	vAirBuffer[17]=0xc0;
	vAirBuffer[18]=0x03;
	vAirBuffer[19]=0xa0;

	vAirBuffer[20]=SPECIAL_Airet4003;
	vAirBuffer[21]=1;
	vAirBuffer[22]=0<<2;
	
	vAirBuffer[23]=LOGIC_Airet4003;
	vAirBuffer[24]=4;
	vAirBuffer[25]=2;
	//vAirBuffer[26]=;
	//vAirBuffer[27]=;
	//vAirBuffer[28]=;
	//vAirBuffer[29]=;
	//vAirBuffer[30]=;

	vAirBuffer[31]=SPECIAL_Airet4003;
	vAirBuffer[32]=1;
	vAirBuffer[33]=0<<2;
	
	vAirBuffer[34]=LOGIC_Airet4003;
	vAirBuffer[35]=4;
	vAirBuffer[36]=2;
	//vAirBuffer[37]=;
	//vAirBuffer[38]=;
	//vAirBuffer[39]=;
	//vAirBuffer[40]=;
	//vAirBuffer[41]=;

	vAirBuffer[42]=SPECIAL_Airet4003;
	vAirBuffer[43]=1;
	vAirBuffer[44]=0<<2;

	vAirBuffer[45]=LOGIC_Airet4003;
	vAirBuffer[46]=4;
	vAirBuffer[47]=2;
	//vAirBuffer[48]=;
	//vAirBuffer[49]=;
	//vAirBuffer[50]=;
	//vAirBuffer[51]=;
	//vAirBuffer[52]=;

	vAirBuffer[53]=SPECIAL_Airet4003;
	vAirBuffer[54]=1;
	vAirBuffer[55]=1<<2;

	vAirBuffer[56]=END_Airet4003;
}

unsigned char HandleAirRemote(AIR_status air_status , unsigned char *vAirBuffer){

	unsigned char i;

	Air_para *air_para;

	if(air_status.nAirCode>5899)
	{
		switch(air_status.nAirCode)
		{
			case 5900:
			//	LOGD("code ----> %d /n ",5900);
				AirRemote900(&air_status, vAirBuffer);
			//	for (i=0;i<70;i++){
			//		LOGD("vAirBuffer[%d] ----> 0x%x /n ",i,vAirBuffer[i]);
			//	}
				break;
			
			case 5901:
				AirRemote901(&air_status, vAirBuffer);
				break;
			case 5902:
				AirRemote902(&air_status, vAirBuffer);
				break;
			case 5903:
				AirRemote903(&air_status, vAirBuffer);
				break;

			default:
				return 0xff;
		}

		return 0x00;
	}


	
	if((air_para=malloc(94))==NULL)return 0xff;
	


	memset(air_para, 0, 94);

	switch(air_status.nAirCode){

	#if 1
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

	case 5060:
		AirRemote060(&air_status,air_para);
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

	case 5500:   //sanling
		AirRemote500(&air_status,air_para);
		break;

	case 5501:
		AirRemote501(&air_status,air_para);
		break;

	case 5502:
		AirRemote502(&air_status,air_para);
		break;

	case 5503:
		AirRemote503(&air_status,air_para);
		break;

	case 5504:
		AirRemote504(&air_status,air_para);
		break;

	case 5505:
		AirRemote505(&air_status,air_para);
		break;

	case 5506:
		AirRemote506(&air_status,air_para);
		break;

	case 5507:
		AirRemote507(&air_status,air_para);
		break;

	case 5508:
		AirRemote508(&air_status,air_para);
		break;

	case 5509:
		AirRemote509(&air_status,air_para);
		break;

	case 5510:
		AirRemote510(&air_status,air_para);
		break;

	case 5511:
		AirRemote511(&air_status,air_para);
		break;

	case 5512:
		AirRemote512(&air_status,air_para);
		break;

	case 5513:
		AirRemote513(&air_status,air_para);
		break;

	case 5514:
		AirRemote514(&air_status,air_para);
		break;

	case 5515:
		AirRemote515(&air_status,air_para);
		break;

	case 5516:
		AirRemote516(&air_status,air_para);
		break;

	case 5517:
		AirRemote517(&air_status,air_para);
		break;

	case 5518:
		AirRemote518(&air_status,air_para);
		break;

	case 5519:
		AirRemote519(&air_status,air_para);
		break;

	case 5520:
		AirRemote520(&air_status,air_para);
		break;

	case 5521:
		AirRemote521(&air_status,air_para);
		break;

	case 5522:
		AirRemote522(&air_status,air_para);
		break;

	case 5523:
		AirRemote523(&air_status,air_para);
		break;

	case 5524:
		AirRemote524(&air_status,air_para);
		break;

	case 5525:
		AirRemote525(&air_status,air_para);
		break;

	case 5526:
		AirRemote526(&air_status,air_para);
		break;

	case 5527:
		AirRemote527(&air_status,air_para);
		break;

	case 5528:
		AirRemote528(&air_status,air_para);
		break;

	case 5529:
		AirRemote529(&air_status,air_para);
		break;

	case 5530:
		AirRemote530(&air_status,air_para);
		break;

	case 5531:
		AirRemote531(&air_status,air_para);
		break;

	case 5532:
		AirRemote532(&air_status,air_para);
		break;
	#endif

	case 5533:
		AirRemote533(&air_status,air_para);
		break;

	case 5534:
		AirRemote534(&air_status,air_para);
		break;

	case 5535:
		AirRemote535(&air_status,air_para);
		break;

	case 5536:
		AirRemote536(&air_status,air_para);
		break;

	case 5537:
		AirRemote537(&air_status,air_para);
		break;

	case 5538:
		AirRemote538(&air_status,air_para);
		break;

	case 5539:
		AirRemote539(&air_status,air_para);
		break;

	case 5540:
		AirRemote540(&air_status,air_para);
		break;

	case 5541:
		AirRemote541(&air_status,air_para);
		break;

	case 5542:
		AirRemote542(&air_status,air_para);
		break;

	case 5543:
		AirRemote543(&air_status,air_para);
		break;

	case 5544:
		AirRemote544(&air_status,air_para);
		break;

	case 5545:
		AirRemote545(&air_status,air_para);
		break;

	case 5546:
		AirRemote546(&air_status,air_para);
		break;

	case 5547:
		AirRemote547(&air_status,air_para);
		break;

	case 5548:
		AirRemote548(&air_status,air_para);
		break;

	case 5549:
		AirRemote549(&air_status,air_para);
		break;

	case 5550:
		AirRemote550(&air_status,air_para);
		break;

	case 5551:
		AirRemote551(&air_status,air_para);
		break;

	case 5552:
		AirRemote552(&air_status,air_para);
		break;

	case 5553:
		AirRemote553(&air_status,air_para);
		break;

	case 5554:
		AirRemote554(&air_status,air_para);
		break;

	case 5555:
		AirRemote555(&air_status,air_para);
		break;

	case 5556:
		AirRemote556(&air_status,air_para);
		break;

	case 5557:
		AirRemote557(&air_status,air_para);
		break;

	case 5558:
		AirRemote558(&air_status,air_para);
		break;

	case 5559:
		AirRemote559(&air_status,air_para);
		break;

	case 5560:
		AirRemote560(&air_status,air_para);
		break;

	case 5561:
		AirRemote561(&air_status,air_para);
		break;

	case 5562:
		AirRemote562(&air_status,air_para);
		break;

	case 5563:
		AirRemote563(&air_status,air_para);
		break;

	case 5564:
		AirRemote564(&air_status,air_para);
		break;

	case 5565:
		AirRemote565(&air_status,air_para);
		break;

	case 5566:
		AirRemote566(&air_status,air_para);
		break;

	case 5567:
		AirRemote567(&air_status,air_para);
		break;

	case 5568:
		AirRemote568(&air_status,air_para);
		break;

	case 5569:
		AirRemote569(&air_status,air_para);
		break;

	case 5570:
		AirRemote570(&air_status,air_para);
		break;

	case 5571:
		AirRemote571(&air_status,air_para);
		break;
		
	case 5572:
		AirRemote572(&air_status,air_para);
		break;

	case 5573:
		AirRemote573(&air_status,air_para);
		break;

	case 5574:
		AirRemote574(&air_status,air_para);
		break;
	case 5575:
		AirRemote575(&air_status,air_para);
		break;
	case 5576:
		AirRemote576(&air_status,air_para);
		break;
	case 5577:
		AirRemote577(&air_status,air_para);
		break;
	case 5740:
		AirRemote740(&air_status,air_para);
		break;
	case 5741:
		AirRemote741(&air_status,air_para);
		break;
	case 5744:
		AirRemote744(&air_status,air_para);
		break;
	case 5748:
		AirRemote748(&air_status,air_para);
		break;
	case 5752:
		AirRemote752(&air_status,air_para);
		break;
	case 5753:
		AirRemote753(&air_status,air_para);
		break;
	case 5754:
		AirRemote754(&air_status,air_para);
		break;
	case 5755:
		AirRemote755(&air_status,air_para);
		break;
	case 5620:
		AirRemote620(&air_status,air_para);
		break;
	case 5621:
		AirRemote621(&air_status,air_para);
		break;
	case 5622:
		AirRemote622(&air_status,air_para);
		break;
	case 5623:
		AirRemote623(&air_status,air_para);
		break;
	case 5624:
		AirRemote624(&air_status,air_para);
		break;
	case 5625:
		AirRemote625(&air_status,air_para);
		break;
	case 5626:
		AirRemote626(&air_status,air_para);
		break;
	case 5632:
		AirRemote632(&air_status,air_para);

		break;
	case 5578:	AirRemote578(&air_status,air_para);				break;
	case 5579:	AirRemote579(&air_status,air_para);				break;
	case 5580:	AirRemote580(&air_status,air_para);				break;
	case 5581:	AirRemote581(&air_status,air_para);				break;
	case 5582:	AirRemote582(&air_status,air_para);				break;
	case 5583:	AirRemote583(&air_status,air_para);				break;
	case 5584:	AirRemote584(&air_status,air_para);				break;
	case 5585:	AirRemote585(&air_status,air_para);				break;
	case 5586:	AirRemote586(&air_status,air_para);				break;
	case 5587:	AirRemote587(&air_status,air_para);				break;
	case 5588:	AirRemote588(&air_status,air_para);				break;
	case 5589:	AirRemote589(&air_status,air_para);				break;
	case 5590:	AirRemote590(&air_status,air_para);				break;
	case 5591:	AirRemote591(&air_status,air_para);				break;
	case 5592:	AirRemote592(&air_status,air_para);				break;
	case 5593:	AirRemote593(&air_status,air_para);				break;
	case 5594:	AirRemote594(&air_status,air_para);				break;
	case 5595:	AirRemote595(&air_status,air_para);				break;
	case 5596:	AirRemote596(&air_status,air_para);				break;
	case 5597:	AirRemote597(&air_status,air_para);				break;
	case 5598:	AirRemote598(&air_status,air_para);				break;
	case 5599:	AirRemote599(&air_status,air_para);				break;
	case 5600:	AirRemote600(&air_status,air_para);				break;



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
	if(((vAirBuffer[12]&0x0f)>=7)&&((vAirBuffer[12]&0x0f)<=12))
		{
			vAirBuffer[25]=air_para->BIC0;
			vAirBuffer[26]=air_para->BIC1;
			vAirBuffer[27]=air_para->BIC2;
			vAirBuffer[28]=air_para->BIC3;
			vAirBuffer[29]=air_para->BIC4;
			vAirBuffer[30]=air_para->BIC5;
			vAirBuffer[31]=air_para->BIC6;
			vAirBuffer[32]=air_para->BIC7;
			for(i=0;i<72;i++)
			{
				vAirBuffer[33+i]=air_para->COD[i];
			}
		}
		else
		{
			vAirBuffer[25]=air_para->BIC0;
			vAirBuffer[26]=air_para->BIC1;
			vAirBuffer[27]=air_para->BIC2;
			vAirBuffer[28]=air_para->BIC3;
			for(i=0;i<64;i++)
			{
				vAirBuffer[29+i]=air_para->COD[i];
			}
		}

#ifdef DEBUG
		LOGD("air_para->LDH_h  ----->0x%x  ",air_para->LDH_h);
		LOGD("air_para->LDH_l  ----->0x%x  ",air_para->LDH_l);
		LOGD("air_para->LDL_h  ----->0x%x  ",air_para->LDL_h);
		LOGD("air_para->LDL_l  ----->0x%x  ",air_para->LDL_l);
		LOGD("air_para->HIG_h  ----->0x%x  ",air_para->HIG_h);
		LOGD("air_para->HIG_l  ----->0x%x  ",air_para->HIG_l);
		LOGD("air_para->ZER_h  ----->0x%x  ",air_para->ZER_h);
		LOGD("air_para->ZER_l  ----->0x%x  ",air_para->ZER_l);
		LOGD("air_para->ONE_h  ----->0x%x  ",air_para->ONE_h);
		LOGD("air_para->ONE_l  ----->0x%x  ",air_para->ONE_l);
		LOGD("air_para->STO_h  ----->0x%x  ",air_para->STO_h);
		LOGD("air_para->STO_l  ----->0x%x  ",air_para->STO_l);
		LOGD("air_para->BIC0  ----->0x%x  ",air_para->BIC0);
		LOGD("air_para->BIC1  ----->0x%x  ",air_para->BIC1);
#endif
	free(air_para);
//for (i=0;i<128;i++){
//	LOGD("vAirBuffer[%d]  ----->0x%x  ",i,vAirBuffer[i]);
//}
	return 0x00;
}




