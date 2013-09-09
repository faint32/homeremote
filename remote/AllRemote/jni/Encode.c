#include <jni.h>
#include <string.h>
#include <fcntl.h>
#include "logo.h"
#include "Encode.h"

//#define DEBUG






jbyteArray
Java_com_sommer_ircomm_RemoteCore_Encode( JNIEnv*  env,jobject jobj,jbyteArray data,jstring codeType ){

	unsigned char sendCode[128];
	int i, length;
	unsigned char covData;
	char* sendData = (char*)  (*env)->GetByteArrayElements(env, data, NULL);

	char* type = (char *) (*env)->GetStringUTFChars(env, codeType, 0);
	#ifdef DEBUG
	LOGD("code type ----> %s /n ",type);
	LOGD("sendData ----> %s /n ",sendData);
	#endif
	///////////////////////////////////////////////////////////////
	if (strcmp(type,T48BAU)==0){
		#ifdef DEBUG
		LOGD("code type ======= T48BAU /n ");
		#endif

				length =  sizeof(T48BAU_FORM) / sizeof(char);

					for (i=0;i<length;i++){
						sendCode[i]= T48BAU_FORM[i];
					//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
					}
					sendCode[1]= *sendData;
					sendData++;
					sendCode[2]= *sendData;
					sendData++;
					sendCode[3]= *sendData;
					sendData++;
					sendCode[4]= *sendData;
					sendData++;
					sendCode[5]= *sendData;
					covData = *sendData;
					covData = ~covData;
					sendCode[6]= covData;
			}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type,T42BBB)==0){
			#ifdef DEBUG
			LOGD("code type ======= T42BBB /n ");
			#endif

				length =  sizeof(T42BBB_FORM) / sizeof(char);

					for (i=0;i<length;i++){
						sendCode[i]= T42BBB_FORM[i];
						LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
					}
					sendCode[1]= *sendData;
					sendData++;
					sendCode[2]= *sendData;
					sendData++;
					sendCode[3]= *sendData;
					sendData++;
					sendCode[4]= *sendData;
					sendData++;
					sendCode[5]= *sendData;
					covData = *sendData;
					covData = ~covData;
					sendCode[6]= covData;
					for (i=0;i<7;i++){
					LOGD("sendData T42BBB %d ----> 0x%x /n ",i,sendCode[i]);
					}
				}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T42AAF)==0){
			#ifdef DEBUG
			LOGD("code type ======= T42AAF /n ");
			#endif

			length =  sizeof(T42AAF_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T42AAF_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;
			sendData++;
			sendCode[3]= *sendData;
			sendData++;
			sendCode[4]= *sendData;
			sendData++;
			sendCode[5]= *sendData;
			covData = *sendData;
			covData = ~covData;
			sendCode[6]= covData;
		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T32DCA)==0){
			#ifdef DEBUG
			LOGD("code type ======= T32DCA /n ");
			#endif

			length =  sizeof(T32DCA_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T32DCA_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;
			sendData++;
			sendCode[3]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T32DBZ)==0){
			#ifdef DEBUG
			LOGD("code type ======= T32DBZ /n ");
			#endif

			length =  sizeof(T32DBZ_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T32DBZ_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;
			sendData++;
			sendCode[3]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T32DBU)==0){
			#ifdef DEBUG
			LOGD("code type ======= T32DBU /n ");
			#endif

			length =  sizeof(T32DBU_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T32DBU_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;
			sendData++;
			sendCode[3]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T32CAM)==0){
			#ifdef DEBUG
			LOGD("code type ======= T32CAM /n ");
			#endif

			length =  sizeof(T32CAM_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T32CAM_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;
			sendData++;
			sendCode[3]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T22ABN)==0){
			#ifdef DEBUG
			LOGD("code type ======= T22ABN /n ");
			#endif

			length =  sizeof(T22ABN_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T22ABN_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[3]= *sendData;
			sendData++;
			sendCode[2]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T16GAA)==0){
			#ifdef DEBUG
			LOGD("code type ======= T16GAA /n ");
			#endif

			length =  sizeof(T16GAA_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T16GAA_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T16DAI)==0){
			#ifdef DEBUG
			LOGD("code type ======= T16DAI /n ");
			#endif

			length =  sizeof(T16DAI_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T16DAI_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T16BAT)==0){
			#ifdef DEBUG
			LOGD("code type ======= T16BAT /n ");
			#endif

			length =  sizeof(T16BAT_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T16BAT_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T16AAR)==0){
			#ifdef DEBUG
			LOGD("code type ======= T16AAR /n ");
			#endif

			length =  sizeof(T16AAR_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T16AAR_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T15AAE)==0){
			#ifdef DEBUG
			LOGD("code type ======= T15AAE /n ");
			#endif

			length =  sizeof(T15AAE_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T15AAE_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;
			sendData++;
			sendCode[3]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T11CAE)==0){
			#ifdef DEBUG
			LOGD("code type ======= T11CAE /n ");
			#endif

			length =  sizeof(T11CAE_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T11CAE_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[2]= *sendData;
			sendData++;
			sendCode[1]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T11AAQ)==0){
			#ifdef DEBUG
			LOGD("code type ======= T11AAQ /n ");
			#endif

			length =  sizeof(T11AAQ_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T11AAQ_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;
			sendData++;
			sendCode[3]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T10ACQ)==0){
			#ifdef DEBUG
			LOGD("code type ======= T10ACQ /n ");
			#endif

			length =  sizeof(T10ACQ_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T10ACQ_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T06AAB)==0){
			#ifdef DEBUG
			LOGD("code type ======= T06AAB /n ");
			#endif

			length =  sizeof(T06AAB_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T06AAB_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,P14ABG)==0){
			#ifdef DEBUG
			LOGD("code type ======= P14ABG /n ");
			#endif

			length =  sizeof(P14ABG_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= P14ABG_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;
			sendData++;
			sendCode[3]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,P14ABD)==0){
			#ifdef DEBUG
			LOGD("code type ======= P14ABD /n ");
			#endif

			length =  sizeof(P14ABD_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= P14ABD_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;
			sendData++;
			sendCode[3]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T48AAA)==0){
			#ifdef DEBUG
			LOGD("code type ======= T48AAA /n ");
			#endif

			length =  sizeof(T48AAA_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T48AAA_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;
			sendData++;
			sendCode[3]= *sendData;
			sendData++;
			sendCode[4]= *sendData;
			sendData++;
			sendCode[5]= *sendData;
			covData = *sendData;
			covData = ~covData;
			sendCode[6]= covData;
		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T32DCP)==0){
			#ifdef DEBUG
			LOGD("code type ======= T32DCP /n ");
			#endif

			length =  sizeof(T32DCP_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T32DCP_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;
			sendData++;
			sendCode[3]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T32DCO)==0){
			#ifdef DEBUG
			LOGD("code type ======= T32DCO /n ");
			#endif

			length =  sizeof(T32DCO_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T32DCO_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;
			sendData++;
			sendCode[3]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T32BAR)==0){
			#ifdef DEBUG
			LOGD("code type ======= T32BAR /n ");
			#endif

			length =  sizeof(T32BAR_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T32BAR_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;
			sendData++;
			sendCode[3]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T32ABO)==0){
			#ifdef DEBUG
			LOGD("code type ======= T32ABO /n ");
			#endif

			length =  sizeof(T32ABO_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T32ABO_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;
			sendData++;
			sendCode[3]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T32ABD)==0){
			#ifdef DEBUG
			LOGD("code type ======= T32ABD /n ");
			#endif

			length =  sizeof(T32ABD_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T32ABD_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;
			sendData++;
			sendCode[3]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T32AAI)==0){
			#ifdef DEBUG
			LOGD("code type ======= T32AAI /n ");
			#endif

			length =  sizeof(T32AAI_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T32AAI_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;
			sendData++;
			sendCode[3]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T24CAG)==0){
			#ifdef DEBUG
			LOGD("code type ======= T24CAG /n ");
			#endif

			length =  sizeof(T24CAG_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T24CAG_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[3]= *sendData;
			sendData++;
			sendCode[2]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T24ACL)==0){
			#ifdef DEBUG
			LOGD("code type ======= T24ACL /n ");
			#endif

			length =  sizeof(T24ACL_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T24ACL_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[3]= *sendData;
			sendData++;
			sendCode[2]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T24ACK)==0){
			#ifdef DEBUG
			LOGD("code type ======= T24ACK /n ");
			#endif

			length =  sizeof(T24ACK_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T24ACK_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[3]= *sendData;
			sendData++;
			sendCode[2]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T24ACC)==0){
			#ifdef DEBUG
			LOGD("code type ======= T24ACC /n ");
			#endif

			length =  sizeof(T24ACC_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T24ACC_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[3]= *sendData;
			sendData++;
			sendCode[2]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T24ABE)==0){
			#ifdef DEBUG
			LOGD("code type ======= T24ABE /n ");
			#endif

			length =  sizeof(T24ABE_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T24ABE_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[3]= *sendData;
			sendData++;
			sendCode[2]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T24AAG)==0){
			#ifdef DEBUG
			LOGD("code type ======= T24AAG /n ");
			#endif

			length =  sizeof(T24AAG_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T24AAG_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[3]= *sendData;
			sendData++;
			sendCode[2]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T22ABH)==0){
			#ifdef DEBUG
			LOGD("code type ======= T22ABH /n ");
			#endif

			length =  sizeof(T22ABH_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T22ABH_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[3]= *sendData;
			sendData++;
			sendCode[2]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T16AAT)==0){
			#ifdef DEBUG
			LOGD("code type ======= T16AAT /n ");
			#endif

			length =  sizeof(T16AAT_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T16AAT_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T16AAS)==0){
			#ifdef DEBUG
			LOGD("code type ======= T16AAS /n ");
			#endif

			length =  sizeof(T16AAS_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T16AAS_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T16AAP)==0){
			#ifdef DEBUG
			LOGD("code type ======= T16AAP /n ");
			#endif

			length =  sizeof(T16AAP_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T16AAP_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;


		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T15AIB)==0){
			#ifdef DEBUG
			LOGD("code type ======= T15AIB /n ");
			#endif

			length =  sizeof(T15AIB_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T15AIB_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[3]= *sendData;
			sendData++;
			sendCode[2]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T14BAF)==0){
			#ifdef DEBUG
			LOGD("code type ======= T14BAF /n ");
			#endif

			length =  sizeof(T14BAF_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T14BAF_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[2]= *sendData;
			sendData++;
			sendCode[1]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T12BAE)==0){
			#ifdef DEBUG
			LOGD("code type ======= T12BAE /n ");
			#endif

			length =  sizeof(T12BAE_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T12BAE_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T12ACF)==0){
			#ifdef DEBUG
			LOGD("code type ======= T12ACF /n ");
			#endif

			length =  sizeof(T12ACF_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T12ACF_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;
			sendData++;
			sendCode[3]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T11BBH)==0){
			#ifdef DEBUG
			LOGD("code type ======= T11BBH /n ");
			#endif

			length =  sizeof(T11BBH_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T11BBH_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T10ECC)==0){
			#ifdef DEBUG
			LOGD("code type ======= T10ECC /n ");
			#endif

			length =  sizeof(T10ECC_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T10ECC_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T10BBE)==0){
			#ifdef DEBUG
			LOGD("code type ======= T10BBE /n ");
			#endif

			length =  sizeof(T10BBE_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T10BBE_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T10AGN)==0){
			#ifdef DEBUG
			LOGD("code type ======= T10AGN /n ");
			#endif

			length =  sizeof(T10AGN_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T10AGN_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T10AGM)==0){
			#ifdef DEBUG
			LOGD("code type ======= T10AGM /n ");
			#endif

			length =  sizeof(T10AGM_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T10AGM_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T10AEE)==0){
			#ifdef DEBUG
			LOGD("code type ======= T10AEE /n ");
			#endif

			length =  sizeof(T10AEE_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T10AEE_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T10AED)==0){
			#ifdef DEBUG
			LOGD("code type ======= T10AED /n ");
			#endif

			length =  sizeof(T10AED_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T10AED_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T10ACT)==0){
			#ifdef DEBUG
			LOGD("code type ======= T10ACT /n ");
			#endif

			length =  sizeof(T10ACT_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T10ACT_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T10ACS)==0){
			#ifdef DEBUG
			LOGD("code type ======= T10ACS /n ");
			#endif

			length =  sizeof(T10ACS_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T10ACS_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T10ACR)==0){
			#ifdef DEBUG
			LOGD("code type ======= T10ACR /n ");
			#endif

			length =  sizeof(T10ACR_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T10ACR_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T10ACH)==0){
			#ifdef DEBUG
			LOGD("code type ======= T10ACH /n ");
			#endif

			length =  sizeof(T10ACH_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T10ACH_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T06AAP)==0){
			#ifdef DEBUG
			LOGD("code type ======= T06AAP /n ");
			#endif

			length =  sizeof(T06AAP_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T06AAP_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T06AAO)==0){
			#ifdef DEBUG
			LOGD("code type ======= T06AAO /n ");
			#endif

			length =  sizeof(T06AAO_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T06AAO_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,P21BAC)==0){
			#ifdef DEBUG
			LOGD("code type ======= P21BAC /n ");
			#endif

			length =  sizeof(P21BAC_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= P21BAC_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;
			sendData++;
			sendCode[3]= *sendData;
			sendData++;
			sendCode[4]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,N11BFO)==0){
			#ifdef DEBUG
			LOGD("code type ======= N11BFO /n ");
			#endif

			length =  sizeof(N11BFO_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= N11BFO_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;
			sendData++;
			sendCode[3]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,N11AAD)==0){
			#ifdef DEBUG
			LOGD("code type ======= N11AAD /n ");
			#endif

			length =  sizeof(N11AAD_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= N11AAD_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;
			sendData++;
			sendCode[3]= *sendData;
		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,N05AAI)==0){
			#ifdef DEBUG
			LOGD("code type ======= N05AAI /n ");
			#endif

			length =  sizeof(N05AAI_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= N05AAI_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T48BAV)==0){
			#ifdef DEBUG
			LOGD("code type ======= T48BAV /n ");
			#endif

			length =  sizeof(T48BAV_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T48BAV_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;
			sendData++;
			sendCode[3]= *sendData;
			sendData++;
			sendCode[4]= *sendData;
			sendData++;
			sendCode[5]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,T40DAA)==0){
			#ifdef DEBUG
			LOGD("code type ======= T40DAA /n ");
			#endif

			length =  sizeof(T40DAA_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= T40DAA_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;
			sendData++;
			sendCode[3]= *sendData;
			sendData++;
			sendCode[4]= *sendData;


		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,P36AAE)==0){
			#ifdef DEBUG
			LOGD("code type ======= P36AAE /n ");
			#endif

			length =  sizeof(P36AAE_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= P36AAE_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;
			sendData++;
			sendCode[3]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,E00ABG)==0){
			#ifdef DEBUG
			LOGD("code type ======= E00ABG /n ");
			#endif

			length =  sizeof(E00ABG_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= E00ABG_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,N05AAA)==0){
			#ifdef DEBUG
			LOGD("code type ======= N05AAA /n ");
			#endif

			length =  sizeof(N05AAA_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= N05AAA_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,E13AAA)==0){
			#ifdef DEBUG
			LOGD("code type ======= E13AAA /n ");
			#endif

			length =  sizeof(E13AAA_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= E13AAA_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,E12CGD)==0){
			#ifdef DEBUG
			LOGD("code type ======= E12CGD /n ");
			#endif

			length =  sizeof(E12CGD_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= E12CGD_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;


		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,E12CGC)==0){
			#ifdef DEBUG
			LOGD("code type ======= E12CGC /n ");
			#endif

			length =  sizeof(E12CGC_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= E12CGC_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;
			sendData++;
			sendCode[2]= *sendData;

		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,E00ACI)==0){
			#ifdef DEBUG
			LOGD("code type ======= E00ACI /n ");
			#endif

			length =  sizeof(E00ACI_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= E00ACI_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;


		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,E00ACH)==0){
			#ifdef DEBUG
			LOGD("code type ======= E00ACH /n ");
			#endif

			length =  sizeof(E00ACH_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= E00ACH_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;


		}
////////////////////////////////////////////////////////////////////////
		if (strcmp(type,E00ACG)==0){
			#ifdef DEBUG
			LOGD("code type ======= E00ACG /n ");
			#endif

			length =  sizeof(E00ACG_FORM) / sizeof(char);

			for (i=0;i<length;i++){
			sendCode[i]= E00ACG_FORM[i];
						//	LOGD("sendData %d ----> 0x%x /n ",i,sendCode[i]);
			}
			sendCode[1]= *sendData;

		}


	jbyteArray byteArray = (*env)->NewByteArray(env,length);

	(*env)->SetByteArrayRegion(env,byteArray, 0, length, (jbyte*)sendCode);

	return byteArray;

}


