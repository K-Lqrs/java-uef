//
// Created by main on 24/09/08.
//

#include "UefKeyEvent.h"

JNIEXPORT jstring JNICALL Java_net_rk4z_juef_event_UefKeyEvent_getKeyIdentifierFromVirtualKeyCode(JNIEnv* env, jclass clazz, jint virtualKeyCode) {
    String key_identifier;
    GetKeyIdentifierFromVirtualKeyCode(static_cast<int>(virtualKeyCode), key_identifier);

    return env->NewStringUTF(key_identifier.utf8().data());
}

JNIEXPORT jstring JNICALL Java_net_rk4z_juef_event_UefKeyEvent_getKeyFromVirtualKeyCode(JNIEnv* env, jclass clazz, jint virtualKeyCode, jboolean shift) {
    String key_result;
    GetKeyFromVirtualKeyCode(static_cast<int>(virtualKeyCode), shift, key_result);

    return env->NewStringUTF(key_result.utf8().data());
}
