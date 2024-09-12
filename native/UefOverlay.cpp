#include "UefOverlay.hpp"
#include "UefWindow.hpp"

UefOverlay::UefOverlay(const UefWindow *window, int width, int height, int x, int y) {
    overlay_ = Overlay::Create(window->window_, width, height, x, y);
}

UefOverlay::~UefOverlay() = default;

void UefOverlay::moveTo(const int x, const int y) const {
    if (overlay_) {
        overlay_->MoveTo(x, y);
    }
}

void UefOverlay::resize(const int width, const int height) const {
    if (overlay_) {
        overlay_->Resize(width, height);
    }
}

void UefOverlay::destroy(UefOverlay* overlay) {
    delete overlay;
}

//>---------- Native methods(from java) ----------<\\

void Java_net_rk4z_uef_UefOverlay_moveTo(JNIEnv *env, jobject obj, jlong overlay_ptr, jint x, jint y) {
    auto *overlay = reinterpret_cast<UefOverlay *>(overlay_ptr);
    if (overlay) {
        overlay->moveTo(x, y);  // 安全に操作
    }
}


void Java_net_rk4z_uef_UefOverlay_destroy(JNIEnv *env, jobject obj, jlong overlay_ptr) {
    auto *overlay = reinterpret_cast<UefOverlay *>(overlay_ptr);
    if (overlay) {
        UefOverlay::destroy(overlay);
    }
}

//>---------- Native methods(from java) ----------<\\
