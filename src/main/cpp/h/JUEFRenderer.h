#pragma once

#include <jni.h>

extern "C" {
    JNIEXPORT void JNICALL Java_net_rk4z_juef_JUEFRenderer_JUEF_1createRenderer(JNIEnv* env, jobject obj);
    JNIEXPORT void JNICALL Java_net_rk4z_juef_JUEFRenderer_JUEF_1updateRenderer(JNIEnv* env, jobject obj);
    JNIEXPORT void JNICALL Java_net_rk4z_juef_JUEFRenderer_JUEF_1render(JNIEnv* env, jobject obj);
}
