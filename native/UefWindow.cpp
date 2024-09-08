#include "UefWindow.h"
#include <jni.h>
#include <AppCore/Window.h>
#include <AppCore/Overlay.h>
#include "UefApp.h"

extern "C" {
using namespace ultralight;

struct JavaWindowListener {
    jobject listener;
    JNIEnv *env;
};

class UefWindow : public WindowListener, public ViewListener {
    RefPtr<Window> window_;
    RefPtr<Overlay> overlay_;
    JavaWindowListener *javaListener_;

public:
    UefWindow(const char *title, const char *url, int x, int y, int width, int height)
        : javaListener_(nullptr) {
        window_ = Window::Create(App::instance()->main_monitor(), width, height, false,
                                 kWindowFlags_Titled | kWindowFlags_Resizable | kWindowFlags_Maximizable |
                                 kWindowFlags_Hidden);
        window_->MoveTo(x, y);
        window_->SetTitle(title);
        window_->Show();
        window_->set_listener(this);

        overlay_ = Overlay::Create(window_, window_->width(), window_->height(), 0, 0);
        overlay_->view()->LoadURL(url);
        overlay_->view()->set_view_listener(this);
    }

    ~UefWindow() override {
        if (javaListener_ != nullptr) {
            JNIEnv *env = javaListener_->env;
            env->DeleteGlobalRef(javaListener_->listener);
            delete javaListener_;
        }
    }

    void setJavaListener(JavaWindowListener *listener) {
        if (javaListener_ != nullptr) {
            delete javaListener_;
        }
        javaListener_ = listener;
    }

    void OnClose(Window *window) override {
        if (javaListener_ && javaListener_->listener) {
            JNIEnv *env = javaListener_->env;
            jclass listenerClass = env->GetObjectClass(javaListener_->listener);
            jmethodID onCloseMethod = env->GetMethodID(listenerClass, "onClose", "()V");
            if (onCloseMethod) {
                env->CallVoidMethod(javaListener_->listener, onCloseMethod);
            }
        }
        app->Quit();
    }

    void OnResize(Window *window, uint32_t width, uint32_t height) override {
        if (javaListener_ && javaListener_->listener) {
            JNIEnv *env = javaListener_->env;
            jclass listenerClass = env->GetObjectClass(javaListener_->listener);
            jmethodID onResizeMethod = env->GetMethodID(listenerClass, "onResize", "(II)V");
            if (onResizeMethod) {
                env->CallVoidMethod(javaListener_->listener, onResizeMethod, width, height);
            }
        }
        overlay_->Resize(width, height);
    }

    void OnChangeCursor(View *caller, Cursor cursor) override {
        window_->SetCursor(cursor);
    }
};

JNIEXPORT jlong JNICALL Java_net_rk4z_juef_UefWindow_createWindow(JNIEnv *env, jobject obj, jstring title, jstring url,
                                                                  jint x, jint y, jint width, jint height) {
    const char *c_title = env->GetStringUTFChars(title, nullptr);
    const char *c_url = env->GetStringUTFChars(url, nullptr);

    auto *window = new UefWindow(c_title, c_url, x, y, width, height);

    env->ReleaseStringUTFChars(title, c_title);
    env->ReleaseStringUTFChars(url, c_url);

    return reinterpret_cast<jlong>(window);
}

JNIEXPORT void JNICALL Java_net_rk4z_juef_UefWindow_setNativeWindowListener(
    JNIEnv *env, jobject obj, jlong window_ptr, jobject listener) {
    auto *window = reinterpret_cast<UefWindow *>(window_ptr);

    auto *javaListener = new JavaWindowListener();
    javaListener->listener = env->NewGlobalRef(listener);
    javaListener->env = env;

    window->setJavaListener(javaListener);
}

JNIEXPORT void JNICALL Java_net_rk4z_juef_UefWindow_destroyWindow(JNIEnv *env, jobject obj, jlong window_ptr) {
    auto *window = reinterpret_cast<UefWindow *>(window_ptr);
    delete window;
}
}
