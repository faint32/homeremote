typedef enum {
	POWER_KEY,			//开关机键
	MODE_KEY,			//模式键
	SPEED_KEY,			//风量键
	TEMPER_INC_KEY,		//温度加键
	TEMPER_DEC_KEY,		//温度减键
	WIND_MANUAL_KEY,	//手动风向键
	WIND_AUTO_KEY		//自动风向键
} vKey_enum;		//存放按下了哪个键

typedef enum {
	POWER_OFF,			//关机
	POWER_ON			//开机
} vPower_enum;	//开关机状态

typedef enum {
	MODE_AUTO,			//自动
	MODE_COLD,			//制冷
	MODE_WET,			//除湿
	MODE_WIND,			//送风
	MODE_HOT			//制热
} vMode_enum;		//模式状态

typedef enum {
	SPEED_AUTO,			//自动
	SPEED_LOW,			//小
	SPEED_MEDIUM,		//中
	SPEED_HIGH			//大
} vSpeed_enum;		//风量状态

typedef enum {
	TEMPER_16,			//16度
	TEMPER_17,			//17度
	TEMPER_18,			//18度
	TEMPER_19,			//19度
	TEMPER_20,			//20度
	TEMPER_21,			//21度
	TEMPER_22,			//22度
	TEMPER_23,			//23度
	TEMPER_24,			//24度
	TEMPER_25,			//25度
	TEMPER_26,			//26度
	TEMPER_27,			//27度
	TEMPER_28,			//28度
	TEMPER_29,			//29度
	TEMPER_30			//30度
} vTemper_enum;		//温度状态(16到30度)

typedef enum {
	WIND_MANUAL,		//手动风向
	WIND_AUTO			//自动风向
} vWind_enum;		//手动风向or自动风向

typedef enum {
	MANUAL_WIND_1,		//风向1
	MANUAL_WIND_2,		//风向2
	MANUAL_WIND_3,		//风向3
	MANUAL_WIND_4		//风向4
} vManualWind_enum;		//手动风向or自动风向

typedef struct {
	int				nAirCode;	//空调代码表中的代码
	vKey_enum 			vKey;		//
	vPower_enum 		vPower;		//
	vMode_enum	 		vMode;		//
	vSpeed_enum 		vSpeed;		//
	vTemper_enum 		vTemper;	//
	vWind_enum 			vWind;		//
	vManualWind_enum 	vManualWind;//
}AIR_status;


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

