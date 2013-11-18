LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := IRDataBase
LOCAL_SRC_FILES :=  libIRDataBase.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE    := IRCore
LOCAL_SRC_FILES := IRCore.c  Encode.c  AirEncode.c AirCode.c Calculate.c remote.c
LOCAL_SHARED_LIBRARY := IRDataBase 					
LOCAL_LDLIBS += -L$(SYSROOT)/usr/lib -llog

include $(BUILD_SHARED_LIBRARY)
