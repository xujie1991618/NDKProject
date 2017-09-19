LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := HelloJniLibName
LOCAL_SRC_FILES := ndktest-jni.c
include $(BUILD_SHARED_LIBRARY)