//
// Created by main on 24/09/08.
//

#ifndef UEFWINDOW_H
#define UEFWINDOW_H

#include <jni.h>

extern "C" {
    JNIEXPORT jlong JNICALL Java_net_rk4z_juef_UefWindow_createWindow(JNIEnv *env, jobject obj, jstring title, jstring url, jint x, jint y, jint width, jint height);

    JNIEXPORT void JNICALL Java_net_rk4z_juef_UefWindow_setNativeWindowListener(JNIEnv *env, jobject obj, jlong window_ptr, jobject listener);

    JNIEXPORT void JNICALL Java_net_rk4z_juef_UefWindow_resizeOverlay(JNIEnv *env, jobject obj, jlong window_ptr);

    JNIEXPORT void JNICALL Java_net_rk4z_juef_UefWindow_destroy(JNIEnv *env, jobject obj, jlong window_ptr);
}


#endif //UEFWINDOW_H
