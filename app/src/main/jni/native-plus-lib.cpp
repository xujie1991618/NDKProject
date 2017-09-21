//
// Created by crayfish on 2017/9/21.
//
#include "com_crayfish_ndkproject_PlusJni.h"

JNIEXPORT jint JNICALL
Java_com_crayfish_ndkproject_PlusJni_plusNumbers(JNIEnv *env, jobject instance, jint x, jint y) {
    // TODO
    return x+y;
}
