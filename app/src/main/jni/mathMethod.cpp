//
// Created by HuangYW on 2016/3/25.
//
#include "com_nlt_testjni_MainActivity.h"
#include "MyLog.h"
#include <string.h>
#include <stdio.h>

JNIEXPORT jint JNICALL Java_com_nlt_testjni_MainActivity_getSum
        (JNIEnv *env, jobject obj, jint a, jint b)
{
    LOGE("hello jni: %d", (a + b));
    return (a + b);
}

JNIEXPORT jstring JNICALL Java_com_nlt_testjni_MainActivity_subString
        (JNIEnv *env, jobject obj, jstring string, jint start, jint len)
{

    const char *tmp = env->GetStringUTFChars(string, (jboolean *) JNI_FALSE);
    int l = env->GetStringUTFLength(string);

//    LOGE("l: %d, start: %d, len: %d", l, start, len);
    if(start > l || start < 0 || len < 0)
    {
        return NULL;
    }

    if((start + len) > l)
    {
        len = l - start;
    }

    char buf[len + 1];
    int i = 0;
    for(; i < len; i++)
    {
        buf[i] = *(tmp + start + i);
    }
    buf[i] = '\0';
    env->ReleaseStringUTFChars(string, tmp);
    return env->NewStringUTF(buf);

}