//
// Created by HuangYW on 2016/3/25.
//
#include "com_nlt_testjni_MainActivity.h"


JNIEXPORT jint JNICALL Java_com_nlt_testjni_MainActivity_getSum
        (JNIEnv *env, jobject jobj, jint a, jint b)
{
    LOGE("hello jni: %d", (a + b));
    return (a + b);
}