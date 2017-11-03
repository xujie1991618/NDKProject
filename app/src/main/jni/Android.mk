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
LOCAL_MODULE := Base64Jni
LOCAL_SRC_FILES := base64Util.cpp	\
                    base64.c

# LOCAL_SHARED_LIBRARIES := liblog libcutils
LOCAL_LDLIBS := -llog
include $(BUILD_SHARED_LIBRARY)


