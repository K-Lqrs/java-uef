#include "UefOverlay.h"

using namespace ultralight;

UefOverlay::UefOverlay(Window *window, int x, int y, int width, int height) {
    overlay_ = Overlay::Create(window, width, height, x, y);
}

UefOverlay::~UefOverlay() {
    overlay_ = nullptr;
}

void UefOverlay::moveTo(int x, int y) const {
    overlay_->MoveTo(x, y);
}

void UefOverlay::resize(int width, int height) const {
    overlay_->Resize(width, height);
}

void UefOverlay::loadUrl(const char *url) const {
    overlay_->view()->LoadURL(url);
}

void UefOverlay::destroy() {
    overlay_ = nullptr;
}

extern "C" {
    JNIEXPORT void JNICALL Java_net_rk4z_juef_UefOverlay_moveTo(JNIEnv *env, jobject obj, jlong overlay_ptr, jint x, jint y) {
        auto *overlay = reinterpret_cast<UefOverlay *>(overlay_ptr);
        overlay->moveTo(x, y);
    }

    JNIEXPORT void JNICALL Java_net_rk4z_juef_UefOverlay_resize(JNIEnv *env, jobject obj, jlong overlay_ptr, jint width, jint height) {
        auto *overlay = reinterpret_cast<UefOverlay *>(overlay_ptr);
        overlay->resize(width, height);
    }

    JNIEXPORT void JNICALL Java_net_rk4z_juef_UefOverlay_loadUrl(JNIEnv *env, jobject obj, jlong overlay_ptr, jstring url) {
        auto *overlay = reinterpret_cast<UefOverlay *>(overlay_ptr);
        const char *urlStr = env->GetStringUTFChars(url, nullptr);
        overlay->loadUrl(urlStr);
        env->ReleaseStringUTFChars(url, urlStr);
    }

    JNIEXPORT void JNICALL Java_net_rk4z_juef_UefOverlay_destroy(JNIEnv *env, jobject obj, jlong overlay_ptr) {
        auto *overlay = reinterpret_cast<UefOverlay *>(overlay_ptr);
        overlay->destroy();
        delete overlay;
    }
}


