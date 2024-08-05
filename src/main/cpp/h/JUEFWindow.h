#pragma once

#include <jni.h>

extern "C" {
    JNIEXPORT jlong JNICALL Java_net_rk4z_juef_JUEFWindow_JUEF_1createWindow(JNIEnv* env, jobject obj, jint width, jint height, jstring title);
}
