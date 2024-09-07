#ifndef UEFWINDOW_H
#define UEFWINDOW_H

#include <jni.h>
#include <AppCore/Window.h>

using namespace ultralight;

extern "C" {
JNIEXPORT void JNICALL Java_net_rk4z_juef_UefApp_createWindow(JNIEnv *env, jobject obj, jint width, jint height,
                                                              jboolean fullscreen, jint flags);

JNIEXPORT void JNICALL Java_net_rk4z_juef_UefApp_setWindowTitle(JNIEnv *env, jobject obj, jstring title);
}


#endif //UEFWINDOW_H
