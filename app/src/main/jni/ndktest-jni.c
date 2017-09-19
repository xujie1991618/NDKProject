//
// Created by lin on 2017/9/15.
//
#include "com_crayfish_ndkproject_NdkTest.h"

JNIEXPORT jstring JNICALL Java_com_crayfish_ndkproject_NdkTest_getString
        (JNIEnv *env, jobject obj){
    return (*env)->NewStringUTF(env,"this is hello jni");
}
