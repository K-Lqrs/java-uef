#include "UefWindow.h"
#include <AppCore/App.h>

RefPtr<Window> g_windowInstance;

extern "C" {

JNIEXPORT void JNICALL Java_net_rk4z_juef_UefApp_createWindow(JNIEnv *env, jobject obj, jint width, jint height, jboolean fullscreen, jint flags) {
    if (App::instance() != nullptr) {
        auto monitor = App::instance()->main_monitor();

        bool isFullscreen = static_cast<bool>(fullscreen);

        int windowFlags = 0;
        if (flags & kWindowFlags_Borderless) {
            windowFlags |= kWindowFlags_Borderless;
        }
        if (flags & kWindowFlags_Titled) {
            windowFlags |= kWindowFlags_Titled;
        }
        if (flags & kWindowFlags_Resizable) {
            windowFlags |= kWindowFlags_Resizable;
        }
        if (flags & kWindowFlags_Maximizable) {
            windowFlags |= kWindowFlags_Maximizable;
        }
        if (flags & kWindowFlags_Hidden) {
            windowFlags |= kWindowFlags_Hidden;
        }

        g_windowInstance = Window::Create(monitor, width, height, isFullscreen, windowFlags);
    }
}

JNIEXPORT void JNICALL Java_net_rk4z_juef_UefApp_setWindowTitle(JNIEnv *env, jobject obj, jstring title) {
    if (g_windowInstance) {
        const char *nativeTitle = env->GetStringUTFChars(title, 0);
        g_windowInstance->SetTitle(nativeTitle);
        env->ReleaseStringUTFChars(title, nativeTitle);
    }
}

JNIEXPORT void JNICALL Java_net_rk4z_juef_UefApp_closeWindow(JNIEnv *env, jobject obj) {
    if (g_windowInstance) {
        g_windowInstance->Close();
        g_windowInstance = nullptr;
    }
}

}
