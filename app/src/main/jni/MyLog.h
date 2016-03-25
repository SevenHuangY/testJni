//
// Created by HuangYW on 2016/3/25.
//

#ifndef TESTJNI_MYLOG_H
#define TESTJNI_MYLOG_H

#include <android/log.h>
#ifndef LOG_TAG
#define LOG_TAG "Seven"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#endif

#endif //TESTJNI_MYLOG_H
