#include <jni.h>
#include <string.h>
#include <fcntl.h>
#include "logo.h"
#include "AirEncode.h"

//#define DEBUG




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































