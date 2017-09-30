//
// Created by lin on 2017/9/30.
//
#include "com_crayfish_ndkproject_AESUtil.h"
#include "aes.h"
#include <string.h>
#include <android/log.h>

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

#define CBC 1
#define ECB 1


// 获取数组的大小
# define NELEM(x) ((int) (sizeof(x) / sizeof((x)[0])))
// 指定要注册的类，对应完整的java类名
#define JNIREG_CLASS "com/crayfish/ndkproject/AESUtil"

const char *UNSIGNATURE = "UNSIGNATURE";

__attribute__((section (".mytext")))
char *getKey() {
    char *s = "NMTIzNDU2Nzg5MGFiY2RlZg";
    char *encode_str = s+1;
    return b64_decode(encode_str, strlen(encode_str));
}

__attribute__((section (".mytext")))
JNIEXPORT jstring JNICALL encrypt
        (JNIEnv *env, jobject obj, jstring str_, jstring k){
    return (*env)->NewStringUTF(env, str_);
//    uint8_t *AES_KEY = (uint8_t *) getKey();
//    const char *in = (*env)->GetStringUTFChars(env, str_, JNI_FALSE);
//    char *baseResult = AES_128_ECB_PKCS5Padding_Encrypt(in, AES_KEY);
//    (*env)->ReleaseStringUTFChars(env, str_, in);
//    return (*env)->NewStringUTF(env, baseResult);
}

__attribute__((section (".mytext")))
JNIEXPORT jstring JNICALL decrypt
        (JNIEnv *env, jobject obj, jstring str_, jstring k){
    return (*env)->NewStringUTF(env, str_);
//    uint8_t *AES_KEY = (uint8_t *) getKey();
//    const char *str = (*env)->GetStringUTFChars(env, str_, JNI_FALSE);
//    char *desResult = AES_128_ECB_PKCS5Padding_Decrypt(str, AES_KEY);
//    (*env)->ReleaseStringUTFChars(env, str_, str);
//    return (*env)->NewStringUTF(env, desResult);
}

jstring charToJstring(JNIEnv *envPtr, char *src) {
    JNIEnv env = *envPtr;

    jsize len = strlen(src);
    jclass clsstring = env->FindClass(envPtr, "java/lang/String");
    jstring strencode = env->NewStringUTF(envPtr, "UTF-8");
    jmethodID mid = env->GetMethodID(envPtr, clsstring, "<init>",
                                     "([BLjava/lang/String;)V");
    jbyteArray barr = env->NewByteArray(envPtr, len);
    env->SetByteArrayRegion(envPtr, barr, 0, len, (jbyte *) src);

    return (jstring) env->NewObject(envPtr, clsstring, mid, barr, strencode);
}

// Java和JNI函数的绑定表
static JNINativeMethod method_table[] = {
        { "decrypt", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", (void*)decrypt },
        { "encrypt", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", (void*)encrypt },
};

// 注册native方法到java中
static int registerNativeMethods(JNIEnv* env, const char* className,
                                 JNINativeMethod* gMethods, int numMethods)
{
    jclass clazz;
    clazz = (*env)->FindClass(env, className);
    if (clazz == NULL) {
        return JNI_FALSE;
    }
    if ((*env)->RegisterNatives(env, clazz, gMethods, numMethods) < 0) {
        return JNI_FALSE;
    }

    return JNI_TRUE;
}

int register_ndk_load(JNIEnv *env)
{
    // 调用注册方法
    return registerNativeMethods(env, JNIREG_CLASS,
                                 method_table, NELEM(method_table));
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
    JNIEnv* env = NULL;
    jint result = -1;

    if ((*vm)->GetEnv(vm, (void**) &env, JNI_VERSION_1_4) != JNI_OK) {
        return result;
    }

    register_ndk_load(env);

    // 返回jni的版本
    return JNI_VERSION_1_4;
}

//char* jstringTostring(JNIEnv* env, jstring jstr)
//{
//    char* rtn = NULL;
//    jclass clsstring = env->FindClass("java/lang/String");
//    jstring strencode = env->NewStringUTF("utf-8");
//    jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
//    jbyteArray barr= (jbyteArray)env->CallObjectMethod(jstr, mid, strencode);
//    jsize alen = env->GetArrayLength(barr);
//    jbyte* ba = env->GetByteArrayElements(barr, JNI_FALSE);
//    if (alen > 0)
//    {
//        rtn = (char*)malloc(alen + 1);
//
//        memcpy(rtn, ba, alen);
//        rtn[alen] = 0;
//    }
//    env->ReleaseByteArrayElements(barr, ba, 0);
//    return rtn;
//}