#include "com_crayfish_ndkproject_AESjni.h"
#include <stdlib.h>
const char *DES_KEY = "12345678912345678912345678912345";
/*
* Class:     com_jzp_myapplication_JniUtils
* Method:    getString
* Signature: ()Ljava/lang/String;
*/
JNIEXPORT jstring JNICALL Java_com_crayfish_ndkproject_AESjni_myEncrypt
        (JNIEnv *env, jclass jclass1, jstring jstr)
{
    if (jstr == NULL) {
        return NULL;
    }
    jstring key;
    jstring result;
    jclass AESencrypt;
    jmethodID mid;

    AESencrypt = (*env)->FindClass(env, "com/crayfish/ndkproject/AESjni");
    if (NULL == AESencrypt) {
        return NULL;
    }
    mid = (*env)->GetStaticMethodID(env, AESencrypt, "encrypt",
                                    "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;");
    if (NULL == mid) {
        (*env)->DeleteLocalRef(env, AESencrypt);
        return NULL;
    }
    key = (*env)->NewStringUTF(env, DES_KEY);
    result = (*env)->CallStaticObjectMethod(env, AESencrypt, mid, key, jstr);
    (*env)->DeleteLocalRef(env, AESencrypt);
    (*env)->DeleteLocalRef(env, key);
    return result;
}

JNIEXPORT jstring JNICALL Java_com_crayfish_ndkproject_AESjni_myDecrypt
        (JNIEnv *env, jclass jclass1, jstring jstr)
{
    if (jstr == NULL) {
        return NULL;
    }
    jstring key;
    jstring result;
    jclass AESencrypt;
    jmethodID mid;

    AESencrypt = (*env)->FindClass(env, "com/crayfish/ndkproject/AESjni");
    if (NULL == AESencrypt) {
        return NULL;
    }
    mid = (*env)->GetStaticMethodID(env, AESencrypt, "decrypt",
                                    "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;");
    if (NULL == mid) {
        (*env)->DeleteLocalRef(env, AESencrypt);
        return NULL;
    }
    key = (*env)->NewStringUTF(env, DES_KEY);
    result = (*env)->CallStaticObjectMethod(env, AESencrypt, mid, key, jstr);
    (*env)->DeleteLocalRef(env, AESencrypt);
    (*env)->DeleteLocalRef(env, key);
    return result;
}