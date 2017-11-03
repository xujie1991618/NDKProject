//
// Created by lin on 2017/11/1.
//
#include "com_crayfish_ndkproject_Base64Util.h"
#include "base64.h"

 * Class:     com_crayfish_ndkproject_Base64Util
 * Method:    b64_encode
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_crayfish_ndkproject_Base64Util_b64_1encode
        (JNIEnv *env, jclass jc, jstring js){
    return env->NewStringUTF(base64::b64_encode(js,js.lenght));
}

/*
 * Class:     com_crayfish_ndkproject_Base64Util
 * Method:    b64_decode
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_crayfish_ndkproject_Base64Util_b64_1decode
        (JNIEnv *env, jclass jc, jstring js){
    return env->NewStringUTF(js);
}
