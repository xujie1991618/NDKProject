LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := HelloJniLibName
LOCAL_SRC_FILES := ndktest-jni.c
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := PlusJni
LOCAL_SRC_FILES := native-plus-lib.cpp
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := AESUtilsJni
LOCAL_SRC_FILES := aesutils-lib.c	\
                    aes.c \
                    base64.c

# LOCAL_SHARED_LIBRARIES := liblog libcutils
LOCAL_LDLIBS := -llog
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := AESjni
LOCAL_SRC_FILES := aesjni.c
include $(BUILD_SHARED_LIBRARY)

