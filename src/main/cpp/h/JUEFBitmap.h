#pragma once

#include <jni.h>

extern "C" {
    JNIEXPORT jlong JNICALL Java_net_rk4z_juef_JUEFBitmap_JUEF_1createBitmap(JNIEnv* env, jobject obj, jint width, jint height);
    JNIEXPORT void JNICALL Java_net_rk4z_juef_JUEFBitmap_JUEF_1lockPixels(JNIEnv* env, jobject obj, jlong bitmapHandle);
    JNIEXPORT void JNICALL Java_net_rk4z_juef_JUEFBitmap_JUEF_1unlockPixels(JNIEnv* env, jobject obj, jlong bitmapHandle);
    JNIEXPORT void JNICALL Java_net_rk4z_juef_JUEFBitmap_JUEF_1writePNG(JNIEnv* env, jobject obj, jlong bitmapHandle, jstring path);
}
