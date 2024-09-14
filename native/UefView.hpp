#ifndef UEFVIEW_HPP
#define UEFVIEW_HPP

#include <jni.h>
#include <Ultralight/View.h>

class UefView {
public:
    void focus();
    void unFocus();
};

extern "C" {
    JNIEXPORT void JNICALL Java_net_rk4z_juef_UefView_focus(JNIEnv *env, jclass obj);
}

#endif //UEFVIEW_HPP
