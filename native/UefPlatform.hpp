#ifndef UEFPLATFORM_HPP
#define UEFPLATFORM_HPP

#include <jni.h>
#include <Ultralight/platform/Platform.h>

using namespace ultralight;

class UefPlatform {
public:
    static void setConfig(const Config& config);
};

extern "C" {
    JNIEXPORT void JNICALL Java_net_rk4z_juef_UefPlatform_setConfig(JNIEnv *env, jobject obj, jobject config);
}

#endif //UEFPLATFORM_HPP
