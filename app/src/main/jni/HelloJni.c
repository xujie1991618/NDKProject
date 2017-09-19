//
// Created by crayfish on 2017/9/15.
//
#include"com_crayfish_ndkproject_HelloJni.h"

JNIEXPORT jstring JNICALL Java_com_crayfish_ndkproject_HelloJni_stringFromJNI
  (JNIEnv *env, jobject obj){
    return (*env)->NewStringUTF(env,"this is hello jni");
  }

