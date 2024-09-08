#ifndef UEFAPP_H
#define UEFAPP_H

#include <jni.h>
#include <AppCore/App.h>

using namespace ultralight;

extern RefPtr<App> app;

extern "C" {

JNIEXPORT void JNICALL Java_net_rk4z_juef_UefApp_createApp(JNIEnv *env, jobject obj, jobject configObj,
                                                           jobject settingsObj);

JNIEXPORT void JNICALL Java_net_rk4z_juef_UefApp_run(JNIEnv *env, jobject obj);
}

#endif //UEFAPP_H
