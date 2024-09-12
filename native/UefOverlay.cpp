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

void UefOverlay::focus() const {
    if (overlay_) {
        overlay_->Focus();
    }
}

void UefOverlay::unFocus() const {
    if (overlay_) {
        overlay_->Unfocus();
    }
}

void UefOverlay::show() const {
    if (overlay_) {
        overlay_->Show();
    }
}

void UefOverlay::hide() const {
    if (overlay_) {
        overlay_->Hide();
    }
}

void UefOverlay::destroy(UefOverlay* overlay) {
    if (overlay) {
        delete overlay;
        overlay = nullptr;
    }
}

//>---------- Native methods(from java) ----------<\\

void Java_net_rk4z_uef_UefOverlay_moveTo(JNIEnv *env, jobject obj, jlong overlay_ptr, jint x, jint y) {
    auto *overlay = reinterpret_cast<UefOverlay *>(overlay_ptr);
    if (overlay) {
        overlay->moveTo(x, y);
    }
}

void Java_net_rk4z_uef_UefOverlay_resize(JNIEnv *env, jobject obj, jlong overlay_ptr, jint width, jint height) {
    auto *overlay = reinterpret_cast<UefOverlay *>(overlay_ptr);
    if (overlay) {
        overlay->resize(width, height);
    }
}

void Java_net_rk4z_uef_UefOverlay_focus(JNIEnv *env, jobject obj, jlong overlay_ptr) {
    auto *overlay = reinterpret_cast<UefOverlay *>(overlay_ptr);
    if (overlay) {
        overlay->focus();
    }
}

void Java_net_rk4z_uef_UefOverlay_unFocus(JNIEnv *env, jobject obj, jlong overlay_ptr) {
    auto *overlay = reinterpret_cast<UefOverlay *>(overlay_ptr);
    if (overlay) {
        overlay->unFocus();
    }
}

void Java_net_rk4z_uef_UefOverlay_show(JNIEnv *env, jobject obj, jlong overlay_ptr) {
    auto *overlay = reinterpret_cast<UefOverlay *>(overlay_ptr);
    if (overlay) {
        overlay->show();
    }
}

void Java_net_rk4z_uef_UefOverlay_hide(JNIEnv *env, jobject obj, jlong overlay_ptr) {
    auto *overlay = reinterpret_cast<UefOverlay *>(overlay_ptr);
    if (overlay) {
        overlay->hide();
    }
}

void Java_net_rk4z_uef_UefOverlay_destroy(JNIEnv *env, jobject obj, jlong overlay_ptr) {
    auto *overlay = reinterpret_cast<UefOverlay *>(overlay_ptr);
    if (overlay) {
        UefOverlay::destroy(overlay);
    }
}

//>---------- Native methods(from java) ----------<\\