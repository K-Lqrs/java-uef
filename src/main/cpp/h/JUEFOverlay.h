#pragma once

#include <jni.h>

extern "C" {
    JNIEXPORT jlong JNICALL Java_net_rk4z_juef_JUEFOverlay_JUEF_1createOverlay(JNIEnv* env, jobject obj, jlong windowHandle, jint width, jint height, jint x, jint y);
    JNIEXPORT void JNICALL Java_net_rk4z_juef_JUEFOverlay_JUEF_1loadURL(JNIEnv* env, jobject obj, jlong overlayHandle, jstring url);
}
