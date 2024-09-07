#ifndef UEFAPP_H
#define UEFAPP_H

#include <jni.h>

namespace uef
{
    class UefApp
    {
    public:
        JNIEXPORT static void JNICALL Java_net_rk4z_juef_UefApp_createApp(JNIEnv *env, jobject obj, jobject configObj, jobject settingsObj);
    };
}

#endif //UEFAPP_H
