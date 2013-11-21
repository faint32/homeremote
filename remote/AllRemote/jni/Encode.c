#include <jni.h>
#include <string.h>
#include "logo.h"
#include "Encode.h"
#include "Calculate.h"


//#define DEBUG





jbyteArray
Java_com_deco_ircore_RemoteCommunicate_remoteEncode( JNIEnv*  env,jobject jobj,jbyteArray data,jstring codeType )
{
	int i,length=0;
	char* uData = (char*)  (*env)->GetByteArrayElements(env, data, NULL);
	char* type = (char *) (*env)->GetStringUTFChars(env, codeType, 0);
	char sendData[128];
	if (strcmp(type, T48BAU) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T48BAU \n ");
#endif

		length = remoteEncode_LC7461M_PANASONIC(sendData, uData);
	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T42BBB) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T42BBB \n ");
#endif
		length = remoteEncode_LC7461F_C1(sendData, uData);

	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T42AAF) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T42AAF \n ");
#endif
		length = remoteEncode_LC7461M_C13(sendData, uData);

	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T32DCA) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T32DCA \n ");
#endif
	length=	remoteEncode_NEC6122_C1(sendData,uData);
		
	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T32DBZ) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T32DBZ \n ");
#endif
	length=	remoteEncode_TC9028_C1(sendData,uData);

	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T32DBU) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T32DBU \n ");
#endif
	length=	remoteEncode_NEC6122_C1(sendData,uData);
	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T32CAM) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T32CAM \n ");
#endif

	length=	remoteEncode_TC9012_C1(sendData,uData);
	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T22ABN) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T22ABN \n ");
#endif
length=	remoteEncode_MN6014W_C5D6_1(sendData,uData);
		
	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T16GAA) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T16GAA \n ");
#endif
	length=	remoteEncode_KONKA_KK_Y261(sendData,uData);

	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T16DAI) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T16DAI \n ");
#endif
	length=	remoteEncode_VICTOR_C8D8(sendData,uData);
		
	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T16BAT) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T16BAT \n ");
#endif
	length =	remoteEncode_M50560(sendData,uData);


	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T16AAR) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T16AAR \n ");
#endif
	length =	remoteEncode_MIT_C8D8(sendData,uData);

	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T15AAE) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T15AAE \n ");
#endif
	length =	remoteEncode_SHARP_IX0773CE(sendData,uData);

	
	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T11CAE) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T11CAE \n ");
#endif
	length =	remoteEncode_UPD6124(sendData,uData);

		

	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T11AAQ) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T11AAQ \n ");
#endif
	length =	remoteEncode_M3004_6C(sendData,uData);

		

	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T10ACQ) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T10ACQ \n ");
#endif
	
	length =	remoteEncode_M50119P(sendData,uData);
		

	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T06AAB) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T06AAB \n ");
#endif
	length =	remoteEncode_CUSTOM_6BIT(sendData,uData);

	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, P14ABG) == 0) {
#ifdef DEBUG
		LOGD("code type ======= P14ABG \n ");
#endif
	length =	remoteEncode_SAA3010_RC_5(sendData,uData);


	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, P14ABD) == 0) {
#ifdef DEBUG
		LOGD("code type ======= P14ABD \n ");
#endif
	length =	remoteEncode_SAA3010_RC_5(sendData,uData);

	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, V08ADE) == 0) {
#ifdef DEBUG
		LOGD("code type ======= V08ADE \n ");
#endif

	length =	remoteEncode_UPD1986(sendData,uData);

	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T48AAA) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T48AAA \n ");
#endif
	length =	remoteEncode_CUSTOM_48BITA(sendData,uData);

		

	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T32DCP) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T32DCP \n ");
#endif
	length =	remoteEncode_CUSTOM_32BITA(sendData,uData);

	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T32DCO) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T32DCO \n ");
#endif
	length =	remoteEncode_NEC6121_50K(sendData,uData);



	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T32BAR) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T32BAR \n ");
#endif
	length =	remoteEncode_PD6121F(sendData,uData);



	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T32ABO) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T32ABO \n ");
#endif
	length= remoteEncode_CUSTOM_32BITB(sendData,uData);

	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T32ABD) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T32ABD \n ");
#endif


	length= remoteEncode_TC9012F(sendData,uData);	

	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T32AAI) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T32AAI \n ");
#endif

		length= remoteEncode_TC9012F(sendData,uData);

	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T24CAG) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T24CAG \n ");
#endif

	length=	remoteEncode_RCA_01_56K(sendData,uData);	

	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T24ACL) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T24ACL \n ");
#endif
	length= remoteEncode_RCA_56K(sendData,uData);

	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T24ACK) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T24ACK \n ");
#endif
	length= remoteEncode_KONKA_KK_Y261(sendData,uData);

	
	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T24ACC) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T24ACC \n ");
#endif

	length=	remoteEncode_RCA_56K(sendData,uData);	
	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T24ABE) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T24ABE \n ");
#endif
	length= remoteEncode_MN6014A_C6D6(sendData,uData);

	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T24AAG) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T24AAG \n ");
#endif
	length= remoteEncode_MN6014A_C6D6_38K(sendData,uData);


	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T22ABH) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T22ABH \n ");
#endif
	length= remoteEncode_MN6014A_C5D6(sendData,uData);


	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T16AAT) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T16AAT \n ");
#endif
	length=	remoteEncode_MIT_C8D8_33K(sendData,uData);

//	length=	remoteEncode_M50462(sendData,uData);	
	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T16AAS) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T16AAS \n ");
#endif

	length=	remoteEncode_MIT_C8D8_40K(sendData,uData);	
	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T16AAP) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T16AAP \n ");
#endif

	length=	remoteEncode_M50462(sendData,uData);	

	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T16AAU) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T16AAU \n ");
#endif

	length=	remoteEncode_M50462(sendData,uData);	

	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T15AIB) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T15AIB \n ");
#endif

	length=	remoteEncode_SHARP_10P(sendData,uData);	

	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T14BAF) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T14BAF \n ");
#endif

	length=	remoteEncode_ZENITH_S7(sendData,uData);	

	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T12BAE) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T12BAE \n ");
#endif
	length= remoteEncode_NEC6122_C1(sendData,uData);        //zenith

	
	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T12ACF) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T12ACF \n ");
#endif

	length=	remoteEncode_SHARP_C3D9(sendData,uData);	
	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T11BBH) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T11BBH \n ");
#endif

	length=	remoteEncode_M9148(sendData,uData);	

	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T10ECC) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T10ECC \n ");
#endif

	length=	remoteEncode_CUSTOM_1OBITA(sendData,uData);	

	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T10BBE) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T10BBE \n ");
#endif
	length= remoteEncode_NEC6122_C1(sendData,uData);  //zenithd5

		
	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T10AGN) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T10AGN \n ");
#endif
	length= remoteEncode_XY04_A(sendData,uData);

	

	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T10AGM) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T10AGM \n ");
#endif
	length= remoteEncode_CUSTOM_10PB(sendData,uData);


	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T10AEE) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T10AEE \n ");
#endif
	length= remoteEncode_MN6027B_D5(sendData,uData);


	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T10AED) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T10AED \n ");
#endif
	length= remoteEncode_MN6027B_D5(sendData,uData);

	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T10ACT) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T10ACT \n ");
#endif
	length= remoteEncode_M50119P(sendData,uData);

	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T10ACS) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T10ACS \n ");
#endif

	length= remoteEncode_M50119P_01(sendData,uData);

	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T10ACR) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T10ACR \n ");
#endif

	length= remoteEncode_M50119P(sendData,uData);

	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T10ACH) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T10ACH \n ");
#endif
	length= remoteEncode_M50119P(sendData,uData);


	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T06AAP) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T06AAP \n ");
#endif

	length= remoteEncode_CUSTOM_6PB(sendData,uData);


	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T06AAO) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T06AAO \n ");
#endif

	length= remoteEncode_CUSTOM_6PC(sendData,uData);


	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, P21BAC) == 0) {
#ifdef DEBUG
		LOGD("code type ======= P21BAC \n ");
#endif
	length=	remoteEncode_RC6(sendData,uData);

	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, N11BFO) == 0) {
#ifdef DEBUG
		LOGD("code type ======= N11BFO \n ");
#endif
	length= remoteEncode_IRT1250C5D6(sendData,uData);


	}
////////////////////////////////////////////////////////////////////////
	if (strcmp(type, N11BAC) == 0) {
#ifdef DEBUG
		LOGD("code type ======= N11BFO \n ");
#endif
	length= remoteEncode_IRT1250C5D6(sendData,uData);


	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, N11AAD) == 0) {
#ifdef DEBUG
		LOGD("code type ======= N11AAD \n ");
#endif
	length= remoteEncode_LG3004_6C_33K(sendData,uData);

	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, N05AAI) == 0) {
#ifdef DEBUG
		LOGD("code type ======= N05AAI \n ");
#endif

	length= remoteEncode_SL490_01_0HZ(sendData,uData);


	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T48BAV) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T48BAV \n ");
#endif

	length= remoteEncode_PAN_7051(sendData,uData);

	}
	////////////////////////////////////////////////////////////////////////
		if (strcmp(type, T40DAA) == 0) {
#ifdef DEBUG
			LOGD("code type ======= T40DAA \n ");
#endif
	
		length= remoteEncode_DVB_40BIT(sendData,uData);
	
		}

	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, T12AAB) == 0) {
#ifdef DEBUG
		LOGD("code type ======= T12AAB \n ");
#endif

	length= remoteEncode_THOMSON_RCT311(sendData,uData);


	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, P36AAE) == 0) {
#ifdef DEBUG
		LOGD("code type ======= P36AAE \n ");
#endif

	length= remoteEncode_PHILIPS_RC_6(sendData,uData);


	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, E00ABG) == 0) {
#ifdef DEBUG
		LOGD("code type ======= E00ABG \n ");
#endif

	length= remoteEncode_NEC6122_C1(sendData,uData);


	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, N05AAA) == 0) {
#ifdef DEBUG
		LOGD("code type ======= N05AAA \n ");
#endif
	length= remoteEncode_SL490_0HZ(sendData,uData);


	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, E13AAA) == 0) {
#ifdef DEBUG
		LOGD("code type ======= E13AAA \n ");
#endif
	length= remoteEncode_SPEC_C6D7(sendData,uData);


	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, E12CGD) == 0) {
#ifdef DEBUG
		LOGD("code type ======= E12CGD \n ");
#endif
	length= remoteEncode_NEC6122_C1(sendData,uData);



	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, E12CGC) == 0) {
#ifdef DEBUG
		LOGD("code type ======= E12CGC \n ");
#endif

	length=	remoteEncode_NEC6122_C1(sendData,uData);

	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, E00ACI) == 0) {
#ifdef DEBUG
		LOGD("code type ======= E00ACI \n ");
#endif

	length= remoteEncode_SPEC_C6D7(sendData,uData);


	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, E00ACH) == 0) {
#ifdef DEBUG
		LOGD("code type ======= E00ACH \n ");
#endif

	length= remoteEncode_NEC6122_C1(sendData,uData);


	}
	////////////////////////////////////////////////////////////////////////
	if (strcmp(type, E00ACG) == 0) {
#ifdef DEBUG
		LOGD("code type ======= E00ACG \n ");
#endif

	length= remoteEncode_SAF1039(sendData,uData);


	}
////////////////////////////////////////////////////////////////////////
	if (strcmp(type,T15UPD)==0){
	#ifdef DEBUG
		LOGD("code type ======= T15UPD \n ");
	#endif
			
		length= remoteEncode_UPD6124_D7C8(sendData,uData);
			
			
		}
////////////////////////////////////////////////////////////////////////
	if (strcmp(type,T20UPD)==0){
	#ifdef DEBUG
		LOGD("code type ======= T20UPD \n ");
	#endif
					
		length= remoteEncode_UPD6124_D7C13(sendData,uData);
					
			
					
		}
////////////////////////////////////////////////////////////////////////
	if (strcmp(type,T32PIO)==0){
		#ifdef DEBUG
		LOGD("code type ======= T32PIO \n ");
		#endif
							
		length= remoteEncode_PIONEER(sendData,uData);
	}
	
////////////////////////////////////////////////////////////////////////

	
	if (length ==0){
		length = 10;
	}
	jbyteArray byteArray = (*env)->NewByteArray(env,length);

	(*env)->SetByteArrayRegion(env,byteArray, 0, length, (jbyte*)sendData);

	return byteArray;

}


