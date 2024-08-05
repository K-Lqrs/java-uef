#include <jni.h>
#include <AppCore/Overlay.h>
#include <AppCore/Window.h>

JNIEXPORT jlong JNICALL Java_net_rk4z_juef_JUEFOverlay_createOverlay(JNIEnv* env, jobject obj, jlong windowHandle, jint width, jint height, jint x, jint y) {
    auto* window = reinterpret_cast<ultralight::Window*>(windowHandle);
    auto overlay = ultralight::Overlay::Create(window, width, height, x, y);
    return reinterpret_cast<jlong>(overlay.get());
}

JNIEXPORT void JNICALL Java_net_rk4z_juef_JUEFOverlay_loadURL(JNIEnv* env, jobject obj, jlong overlayHandle, jstring url) {
    const char* urlStr = env->GetStringUTFChars(url, nullptr);
    auto* overlay = reinterpret_cast<ultralight::Overlay*>(overlayHandle);
    overlay->view()->LoadURL(urlStr);
    env->ReleaseStringUTFChars(url, urlStr);
}
