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

UefOverlay* UefWindow::createOverlay(jlong window_ptr, int width, int height, int x, int y) {
    auto *window = reinterpret_cast<UefWindow *>(window_ptr);

    return new UefOverlay(window, width, height, x, y);
}

void UefWindow::destroy(jlong window_ptr) {
    auto *window = reinterpret_cast<UefWindow *>(window_ptr);
    delete window;
}

//>---------- Native methods(from java) ----------<\\

jlong Java_net_rk4z_uef_UefWindow_createWindow(JNIEnv *env, jobject obj, jstring title, jint width, jint height, jboolean fullscreen, jint flags) {
    const char *c_title = env->GetStringUTFChars(title, nullptr);

    auto *window = new UefWindow(c_title, width, height, fullscreen, flags);

    env->ReleaseStringUTFChars(title, c_title);

    return reinterpret_cast<jlong>(window);
}

jlong Java_net_rk4z_uef_UefWindow_createOverlay(JNIEnv *env, jobject obj, jlong window_ptr, jint width, jint height, jint x, jint y) {
    auto* overlay = UefWindow::createOverlay(window_ptr, width, height, x, y);

    return reinterpret_cast<jlong>(overlay);
}

void Java_net_rk4z_juef_UefWindow_destroy(JNIEnv *env, jobject obj, jlong window_ptr) {
    UefWindow::destroy(window_ptr);
}

//>---------- Native methods (from java) ----------<\\