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

JNIEXPORT jobject JNICALL Java_com_nlt_testjni_MainActivity_setStudentAge
        (JNIEnv *env, jobject obj, jobject students, jobject ages)
{
    jclass student_class = env->GetObjectClass(students);
    jclass ages_class = env->GetObjectClass(ages);

    // object,method,params
    jmethodID student_get = env->GetMethodID(student_class, "get", "(I)Ljava/lang/Object;");
    jmethodID student_size = env->GetMethodID(student_class, "size", "()I");

    jmethodID age_get = env->GetMethodID(ages_class, "get", "(I)Ljava/lang/Object;");
    jmethodID age_size = env->GetMethodID(ages_class, "size", "()I");

    int student_len = env->CallIntMethod(students, student_size);
    int age_len = env->CallIntMethod(ages, age_size);
    int len = student_len < age_len?student_len:age_len;

    jstring j_name;
    jint j_age;
    for(int i = 0; i< len; i++)
    {
        // ArrayList.get()
        jobject s = env->CallObjectMethod(students, student_get, i);
        // Get Student Class
        jclass s_class = env->GetObjectClass(s);
        // Get Name Field
        jfieldID s_name = env->GetFieldID(s_class, "Name", "Ljava/lang/String;");
        // Get Age Field
        jfieldID s_age = env->GetFieldID(s_class, "Age", "I");

        // ArrayList.get()
        jobject a = env->CallObjectMethod(ages, age_get, i);
        // Get Integer Class
        jclass a_class = env->GetObjectClass(a);
        // Get value Field
        jfieldID a_age = env->GetFieldID(a_class, "value", "I");
        // Get Field Value
        j_age = env->GetIntField(a, a_age);
        // Set Field Value
        env->SetIntField(s, s_age, j_age);

        // Get Field Value
        j_name = (jstring) env->GetObjectField(s, s_name);
        // Transform
        const char * name = env->GetStringUTFChars(j_name, NULL);
        // Get Field Vaule
        j_age = env->GetIntField(s, s_age);
        LOGE("index: %d, name: %s, age: %d",i, name, j_age);
        // Release Pointer
        env->ReleaseStringUTFChars(j_name, name);
    }
    return students;
}