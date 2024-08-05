#pragma once

#include <jni.h>

extern "C" {
    JNIEXPORT void JNICALL Java_net_rk4z_juef_JUEFFontLoader_JUEF_1loadFont(JNIEnv* env, jobject obj, jstring path);
    JNIEXPORT void JNICALL Java_net_rk4z_juef_JUEFFontLoader_JUEF_1fallbackFont(JNIEnv* env, jobject obj);
}
