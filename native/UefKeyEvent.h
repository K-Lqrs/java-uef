#ifndef UEFKEYEVENT_H
#define UEFKEYEVENT_H

#include <jni.h>
#include <Ultralight/KeyEvent.h>

using namespace ultralight;

extern "C" {
    JNIEXPORT jstring JNICALL Java_net_rk4z_juef_KeyEvent_getKeyIdentifierFromVirtualKeyCode(JNIEnv* env, jclass clazz, jint virtualKeyCode);

    JNIEXPORT jstring JNICALL Java_net_rk4z_juef_KeyEvent_getKeyFromVirtualKeyCode(JNIEnv* env, jclass clazz, jint virtualKeyCode, jboolean shift);
}



#endif //UEFKEYEVENT_H
