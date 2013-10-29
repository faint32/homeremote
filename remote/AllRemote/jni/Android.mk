LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := ETEKIRCore
LOCAL_SRC_FILES :=  libETEKIRCore.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE    := IRCore
LOCAL_SRC_FILES :=  libIRCore.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE    := RemoteCore
LOCAL_SRC_FILES :=  Encode.c 
LOCAL_LDLIBS += -L$(SYSROOT)/usr/lib -llog
LOCAL_SHARED_LIBRARY := ETEKIRCore IRCore

include $(BUILD_SHARED_LIBRARY)



