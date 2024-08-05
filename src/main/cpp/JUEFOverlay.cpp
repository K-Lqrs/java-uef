#include "h/JUEFOverlay.h"
#include <AppCore/Overlay.h>
#include "h/JUEF.h"

JNIEXPORT jlong JNICALL Java_net_rk4z_juef_JUEFOverlay_JUEF_1createOverlay(JNIEnv* env, jobject obj, jlong windowHandle, jint width, jint height, jint x, jint y) {
    auto* window = reinterpret_cast<Window*>(windowHandle);
    auto overlay = Overlay::Create(window, width, height, x, y);
    return reinterpret_cast<jlong>(overlay.get());
}

JNIEXPORT void JNICALL Java_net_rk4z_juef_JUEFOverlay_JUEF_1loadURL(JNIEnv* env, jobject obj, jlong overlayHandle, jstring url) {
    const char* urlStr = env->GetStringUTFChars(url, nullptr);
    auto* overlay = reinterpret_cast<Overlay*>(overlayHandle);
    overlay->view()->LoadURL(urlStr);
    env->ReleaseStringUTFChars(url, urlStr);
}
