#include <jni.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/time.h>
#include "logo.h"



#define		_DC6008_START_LEARND_		0x57
#define		_DC6008_STOP_LEARN_		0x5e
#define		_DC6008_SEND_REPEAT_		0x5f

#define   DC_CMD_START_LEARN	0
#define   DC_CMD_STOP_LEARN		1
#define   DC_CMD_REPEAT			2

struct timeval tv;


int fd;
#define  DEVICE_NAME  "/dev/ircontrol"  //device point

void IR_Send_Data(char *data,int Length){
	int i;

	write(fd,data,Length);

}




void Java_com_deco_ircore_RemoteCommunicate_sendIRCode(JNIEnv* env, jobject jobj, jbyteArray datas){
	int i;
	jbyte *sendDatasOld = (*env)->GetByteArrayElements(env, datas, NULL);
	char *sendDatas = (char*)sendDatasOld;
	jsize length = (*env)->GetArrayLength(env, datas);
//		for(i=0;i<arrayLength;i++){
//			LOGD("Sanded %d is 0x%x", i,sendDatas[i]);
//		}

//	IR_Send_Data(sendDatas,arrayLength);
	int err;
	err=write(fd,sendDatas,length);
	if(err == -1){
		LOGE(" %s    send remote code error ",DEVICE_NAME);
	}
}

void Java_com_deco_ircore_RemoteCommunicate_sendLearnCode(JNIEnv* env, jobject jobj, jbyteArray datas,jint arrayLength){
	int i;
	jbyte *sendDatasOld = (*env)->GetByteArrayElements(env, datas, NULL);

	char *sendDatas = (char*)sendDatasOld;

//	for(i=0;i<arrayLength;i++){
//		LOGD("Sanded %d is 0x%x", i,sendDatas[i]);
//	}
	IR_Send_Data(sendDatas,arrayLength);

}

void Java_com_deco_ircore_RemoteCommunicate_setLearnTimeout(JNIEnv* env, jobject jobj,jint setTime){
	int i;

	int time = (int)setTime;
	tv.tv_sec= 30;

}

jbyteArray Java_com_deco_ircore_RemoteCommunicate_readLearnIRCode(JNIEnv* env, jobject jobj,jint length){
	int i;
	char readDatas[128];
	int err;
		err=read(fd,readDatas,length);
		if(err == -1){
			LOGE(" %s    read code error  ",DEVICE_NAME);
			return 0;
		}

    jbyteArray byteArray = (*env)->NewByteArray(env,length);
    (*env)->SetByteArrayRegion(env,byteArray, 0, length, (jbyte*)readDatas);
//    for (i=0;i<length;i++){
//    	LOGD("read learn data %d is 0x%x", i,readDatas[i]);
//    }

   	return byteArray;
}


jint
Java_com_deco_ircore_RemoteCommunicate_IRinit( JNIEnv*  env )
{
  // LOGD("ircore_Init() /n");
   fd = open(DEVICE_NAME,O_RDWR);
   LOGD("ircontrol_init()-> fd = %d  /n",fd);
   if(fd == -1)
       {
           LOGE("open device %s error /n ",DEVICE_NAME);
           return 0;
   }
   else
       {
           return 1;
       }
}

jint
Java_com_deco_ircore_RemoteCommunicate_learnIRCodeStop( JNIEnv*  env ){
	 int err;
	 err = ioctl(fd,DC_CMD_STOP_LEARN,_DC6008_STOP_LEARN_);
	  if(err == -1)
	  {
	   LOGE("ioctl learn IR code stop   %s error /n ",DEVICE_NAME);
	   return 0;
	  }
	  else{
	   return 1;
	  }
}


jint
Java_com_deco_ircore_RemoteCommunicate_learnIRCodeMain( JNIEnv*  env ){
	int rc;
	fd_set fds;
	int dev;



	        FD_ZERO(&fds);
	        FD_SET(fd,&fds);

	        switch(select(fd+1,&fds,NULL,NULL,&tv))
	        {
	        LOGE(" learn IR code select loop   %s  /n ",DEVICE_NAME);
	         case -1:
	        	 LOGE(" learn IR code select error   %s error /n ",DEVICE_NAME);
	        	 dev=-1;
	             break;
	         case 0:
	        	 LOGE(" learn IR code select timeout   %s  /n ",DEVICE_NAME);
	        	 dev=0;

	        	break;
	            default:
	                  if(FD_ISSET(fd,&fds))
	                  {
	                	  dev=1;
				 LOGD(" learn IR code select   %s successful /n ",DEVICE_NAME);

	                 }
	                break;
	         }// end switch
		jint devStatus = dev;
		return devStatus;
}


jint
Java_com_deco_ircore_RemoteCommunicate_learnIRCodeStart( JNIEnv*  env ) {
	int err;
	err = ioctl(fd,DC_CMD_START_LEARN,_DC6008_START_LEARND_);
	 if(err == -1){
	 	LOGE("ioctl learn IR code start   %s error /n ",DEVICE_NAME);
	 	return 0;
	 	}
	else {
	 	 return 1;
	 	 }
}
jint
Java_com_deco_ircore_RemoteCommunicate_sendIRRepeat( JNIEnv*  env ){
	 	 	 int err;
	 	 	 err = ioctl(fd,DC_CMD_REPEAT,_DC6008_SEND_REPEAT_);
	 	 	    if(err == -1)
	 	 	        {
	 	 	            LOGE("ioctl repeat code send   %s error /n ",DEVICE_NAME);
	 	 	            return 0;
	 	 	    }
	 	 	    else
	 	 	        {
	 	 	           return 1;
	 	 	        }
	 	 	 }

void
Java_com_deco_ircore_RemoteCommunicate_Finish( JNIEnv*  env ){
	   LOGD("ircore_finish /n");
	   close(fd);

	}


