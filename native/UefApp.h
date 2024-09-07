#ifndef UEFAPP_H
#define UEFAPP_H

#include <jni.h>

extern "C" {
JNIEXPORT void JNICALL Java_net_rk4z_juef_UefApp_createApp(JNIEnv *env, jobject obj, jobject configObj,
                                                           jobject settingsObj);

JNIEXPORT void JNICALL Java_net_rk4z_juef_UefApp_createWindow(JNIEnv *env, jobject obj, jint width, jint height,
                                                              jboolean fullscreen, jint flags);

JNIEXPORT void JNICALL Java_net_rk4z_juef_UefApp_setWindowTitle(JNIEnv *env, jobject obj, jstring title);

JNIEXPORT void JNICALL Java_net_rk4z_juef_UefApp_closeWindow(JNIEnv *env, jobject obj);

JNIEXPORT void JNICALL Java_net_rk4z_juef_UefApp_run(JNIEnv *env, jobject obj);
}

#endif //UEFAPP_H
