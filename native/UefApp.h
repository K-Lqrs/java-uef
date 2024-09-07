#ifndef UEFAPP_H
#define UEFAPP_H

#include <jni.h>

namespace uef
{
    class UefApp
    {
    public:
        JNIEXPORT static void JNICALL createApp(JNIEnv *env, jobject obj);
    };
}

#endif //UEFAPP_H
