#ifndef AIRENCODE_H_
#define AIRENCODE_H_



typedef enum KEYVALUE{
	POWER_KEY,			//开关机键
	MODE_KEY,			//模式键
	SPEED_KEY,			//风量键
	TEMPER_INC_KEY,		//温度加键
	TEMPER_DEC_KEY,		//温度减键
	WIND_MANUAL_KEY,	//手动风向键
	WIND_AUTO_KEY,		//自动风向键
} vKey_enum;		//存放按下了哪个键

typedef enum {
	POWER_OFF = 0,			//关机
	POWER_ON = 1,			//开机
} vPower_enum;	//开关机状态

typedef enum {
	MODE_AUTO=0,			//自动
	MODE_COLD=1,			//制冷
	MODE_WET=2,			//除湿
	MODE_WIND=3,			//送风
	MODE_HOT=4,			//制热
} vMode_enum;		//模式状态

typedef enum {
	SPEED_AUTO=0,			//自动
	SPEED_LOW=1,			//小
	SPEED_MEDIUM=2,		//中
	SPEED_HIGH=3,			//大
} vSpeed_enum;		//风量状态

typedef enum {
	TEMPER_16=0,			//16度
	TEMPER_17=1,			//17度
	TEMPER_18=2,			//18度
	TEMPER_19=3,			//19度
	TEMPER_20=4,			//20度
	TEMPER_21=5,			//21度
	TEMPER_22=6,			//22度
	TEMPER_23=7,			//23度
	TEMPER_24=8,			//24度
	TEMPER_25=9,			//25度
	TEMPER_26=10,			//26度
	TEMPER_27=11,			//27度
	TEMPER_28=12,			//28度
	TEMPER_29=13,			//29度
	TEMPER_30=14,			//30度
} vTemper_enum;		//温度状态(16到30度)

typedef enum {
	WIND_MANUAL=0,		//手动风向
	WIND_AUTO=1,			//自动风向
} vWind_enum;		//手动风向or自动风向

typedef enum {
	MANUAL_WIND_1=0,		//风向1
	MANUAL_WIND_2=1,		//风向2
	MANUAL_WIND_3=2,		//风向3
	MANUAL_WIND_4=3,		//风向4
} vManualWind_enum;		//手动风向or自动风向

typedef struct AIR_STATUS{
	int				nAirCode;	//空调代码表中的代码
	vKey_enum 			vKey;		//
	vPower_enum 		vPower;		//
	vMode_enum	 		vMode;		//
	vSpeed_enum 		vSpeed;		//
	vTemper_enum 		vTemper;	//
	vWind_enum 			vWind;		//
	vManualWind_enum 	vManualWind;//
}AIR_status,AIR_STATUS;



unsigned char HandleAirRemote(AIR_status air_status , unsigned char *vAirBuffer);

#endif 


