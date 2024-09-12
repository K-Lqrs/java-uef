#include <AppCore/App.h>
#include "UefWindow.hpp"
#include "UefOverlay.hpp"

UefWindow::UefWindow(const char *title, int width, int height, bool fullscreen, int flags) {
    window_ = Window::Create(App::instance()->main_monitor(), width, height, fullscreen, flags);
    window_->SetTitle(title);
}

UefWindow::~UefWindow() {
    window_.reset();
}

UefWindow* UefWindow::createWindow(const char *title, int width, int height, bool fullscreen, int flags) {
    return new UefWindow(title, width, height, fullscreen, flags);
}

UefOverlay* UefWindow::createOverlay(jlong window_ptr, int width, int height, int x, int y) {
    auto *window = reinterpret_cast<UefWindow *>(window_ptr);
    if (window) {
        return new UefOverlay(window, width, height, x, y);
    }
    return nullptr;
}

void UefWindow::setTitle(const char *title) const {
    if (window_) {
        window_->SetTitle(title);
    }
}

void UefWindow::moveTo(const int x, const int y) const {
    if (window_) {
        window_->MoveTo(x, y);
    }
}

void UefWindow::moveToCenter() const {
    if (window_) {
        window_->MoveToCenter();
    }
}

void UefWindow::destroy() const {
    if (window_) {
        delete window_;
    }
}

//>---------- Native methods(from java) ----------<\\

jlong Java_net_rk4z_uef_UefWindow_createWindow(JNIEnv *env, jobject obj, jstring title, jint width, jint height, jboolean fullscreen, jint flags) {
    const char *c_title = env->GetStringUTFChars(title, nullptr);

    auto *window = UefWindow::createWindow(c_title, width, height, fullscreen, flags);

    env->ReleaseStringUTFChars(title, c_title);

    return reinterpret_cast<jlong>(window);
}


jlong Java_net_rk4z_uef_UefWindow_createOverlay(JNIEnv *env, jobject obj, jlong window_ptr, jint width, jint height, jint x, jint y) {
    auto* overlay = UefWindow::createOverlay(window_ptr, width, height, x, y);

    return reinterpret_cast<jlong>(overlay);
}

void Java_net_rk4z_uef_UefWindow_setTitle(JNIEnv *env, jobject obj, jlong window_ptr, jstring title) {
    const char *c_title = env->GetStringUTFChars(title, nullptr);

    auto *window = reinterpret_cast<UefWindow*>(window_ptr);

    window->setTitle(c_title);

    env->ReleaseStringUTFChars(title, c_title);
}

void Java_net_rk4z_uef_UefWindow_moveTo(JNIEnv *env, jobject obj, jlong window_ptr, jint x, jint y) {
    auto *window = reinterpret_cast<UefWindow*>(window_ptr);

    window->moveTo(x, y);
}

void Java_net_rk4z_uef_UefWindow_moveToCenter(JNIEnv *env, jobject obj, jlong window_ptr) {
    auto *window = reinterpret_cast<UefWindow*>(window_ptr);

    window->moveToCenter();
}

void Java_net_rk4z_juef_UefWindow_destroy(JNIEnv *env, jobject obj, jlong window_ptr) {
    auto *window = reinterpret_cast<UefWindow*>(window_ptr);

    window->destroy();
}

//>---------- Native methods (from java) ----------<\\