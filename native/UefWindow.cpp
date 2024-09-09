#include "UefWindow.h"
#include <jni.h>
#include <AppCore/Window.h>
#include <AppCore/Overlay.h>
#include "UefApp.h"

extern "C" {
using namespace ultralight;

    struct JavaListener {
        jobject listener;
        JNIEnv *env;
    };

    class UefWindow : public WindowListener, public ViewListener {
    public:
        RefPtr<Window> window_;
        RefPtr<Overlay> overlay_;
        JavaListener *javaWindowListener_;
        JavaListener *javaViewListener_;

        UefWindow(const char *title, const char *url, int x, int y, int width, int height, int flags)
            : javaWindowListener_(nullptr), javaViewListener_(nullptr) {
            window_ = Window::Create(App::instance()->main_monitor(), width, height, false, flags);
            window_->MoveTo(x, y);
            window_->SetTitle(title);
            window_->Show();
            window_->set_listener(this);

            overlay_ = Overlay::Create(window_, window_->width(), window_->height(), 0, 0);
            overlay_->view()->LoadURL(url);
            overlay_->view()->set_view_listener(this);
        }

        ~UefWindow() override {
            if (javaWindowListener_ != nullptr) {
                JNIEnv *env = javaWindowListener_->env;
                env->DeleteGlobalRef(javaWindowListener_->listener);
                delete javaWindowListener_;
            }

            if (javaViewListener_ != nullptr) {
                JNIEnv *env = javaViewListener_->env;
                env->DeleteGlobalRef(javaViewListener_->listener);
                delete javaViewListener_;
            }
        }

        void setJavaWindowListener(JavaListener *listener) {
            if (javaWindowListener_ != nullptr) {
                JNIEnv *env = javaWindowListener_->env;
                env->DeleteGlobalRef(javaWindowListener_->listener);
                delete javaWindowListener_;
            }
            javaWindowListener_ = listener;
        }

        void setJavaViewListener(JavaListener *listener) {
            if (javaViewListener_ != nullptr) {
                JNIEnv *env = javaViewListener_->env;
                env->DeleteGlobalRef(javaViewListener_->listener);
                delete javaViewListener_;
            }
            javaViewListener_ = listener;
        }

        void OnClose(Window *window) override {
            if (javaWindowListener_ && javaWindowListener_->listener) {
                JNIEnv *env = javaWindowListener_->env;
                jclass listenerClass = env->GetObjectClass(javaWindowListener_->listener);
                jmethodID onCloseMethod = env->GetMethodID(listenerClass, "onClose", "()V");
                if (onCloseMethod) {
                    env->CallVoidMethod(javaWindowListener_->listener, onCloseMethod);
                }
            }
        }

        void OnResize(Window *window, uint32_t width, uint32_t height) override {
            if (javaWindowListener_ && javaWindowListener_->listener) {
                JNIEnv *env = javaWindowListener_->env;
                jclass listenerClass = env->GetObjectClass(javaWindowListener_->listener);
                jmethodID onResizeMethod = env->GetMethodID(listenerClass, "onResize", "(II)V");
                if (onResizeMethod) {
                    env->CallVoidMethod(javaWindowListener_->listener, onResizeMethod, width, height);
                }
            }
        }

        bool OnKeyEvent(const KeyEvent &evt) override {
            if (javaWindowListener_ && javaWindowListener_->listener) {
                JNIEnv *env = javaWindowListener_->env;

                jclass listenerClass = env->GetObjectClass(javaWindowListener_->listener);

                jmethodID onKeyEventMethod = env->GetMethodID(listenerClass, "onKeyEvent", "(Lnet/rk4z/juef/event/UefKeyEvent;)Z");

                if (onKeyEventMethod) {
                    jclass keyEventClass = env->FindClass("net/rk4z/juef/event/UefKeyEvent");
                    jmethodID keyEventConstructor = env->GetMethodID(keyEventClass, "<init>", "(Lnet/rk4z/juef/event/UefKeyEvent$Type;IIZ)V");

                    jclass keyEventTypeClass = env->FindClass("net/rk4z/juef/event/UefKeyEvent$Type");
                    jfieldID typeFieldID;
                    switch (evt.type) {
                        case KeyEvent::kType_KeyDown:
                            typeFieldID = env->GetStaticFieldID(keyEventTypeClass, "KeyDown", "Lnet/rk4z/juef/event/UefKeyEvent$Type;");
                            break;
                        case KeyEvent::kType_KeyUp:
                            typeFieldID = env->GetStaticFieldID(keyEventTypeClass, "KeyUp", "Lnet/rk4z/juef/event/UefKeyEvent$Type;");
                            break;
                        case KeyEvent::kType_RawKeyDown:
                            typeFieldID = env->GetStaticFieldID(keyEventTypeClass, "RawKeyDown", "Lnet/rk4z/juef/event/UefKeyEvent$Type;");
                            break;
                        case KeyEvent::kType_Char:
                            typeFieldID = env->GetStaticFieldID(keyEventTypeClass, "Char", "Lnet/rk4z/juef/event/UefKeyEvent$Type;");
                            break;
                        default:
                            return false;
                    }

                    jobject keyEventType = env->GetStaticObjectField(keyEventTypeClass, typeFieldID);

                    jobject keyEvent = env->NewObject(keyEventClass, keyEventConstructor, keyEventType, evt.virtual_key_code, evt.native_key_code, evt.is_system_key);

                    jboolean result = env->CallBooleanMethod(javaWindowListener_->listener, onKeyEventMethod, keyEvent);

                    env->DeleteLocalRef(keyEvent);
                    env->DeleteLocalRef(keyEventType);

                    return result == JNI_TRUE;
                }
            }
            return false;
        }

        void OnChangeCursor(View *caller, Cursor cursor) override {
            if (javaViewListener_ && javaViewListener_->listener) {
                JNIEnv *env = javaViewListener_->env;
                jclass listenerClass = env->GetObjectClass(javaViewListener_->listener);
                jmethodID onChangeCursorMethod = env->GetMethodID(listenerClass, "onChangeCursor", "(I)V");
                if (onChangeCursorMethod) {
                    env->CallVoidMethod(javaViewListener_->listener, onChangeCursorMethod, cursor);
                }
            }
        }
    };

    JNIEXPORT jlong JNICALL Java_net_rk4z_juef_UefWindow_createWindow(JNIEnv *env, jobject obj, jstring title, jstring url, jint x, jint y, jint width, jint
    height, jint flags) {
        const char *c_title = env->GetStringUTFChars(title, nullptr);
        const char *c_url = env->GetStringUTFChars(url, nullptr);

        auto *window = new UefWindow(c_title, c_url, x, y, width, height, flags);

        env->ReleaseStringUTFChars(title, c_title);
        env->ReleaseStringUTFChars(url, c_url);

        return reinterpret_cast<jlong>(window);
    }

    JNIEXPORT void JNICALL Java_net_rk4z_juef_UefWindow_setWindowListener(JNIEnv *env, jobject obj, jlong window_ptr, jobject listener) {
        auto *window = reinterpret_cast<UefWindow *>(window_ptr);

        auto *javaListener = new JavaListener();
        javaListener->listener = env->NewGlobalRef(listener);
        javaListener->env = env;

        window->setJavaWindowListener(javaListener);
    }

    JNIEXPORT void JNICALL Java_net_rk4z_juef_UefWindow_setViewListener(JNIEnv *env, jobject obj, jlong window_ptr, jobject listener) {
        auto *window = reinterpret_cast<UefWindow *>(window_ptr);

        auto *javaListener = new JavaListener();
        javaListener->listener = env->NewGlobalRef(listener);
        javaListener->env = env;

        window->setJavaViewListener(javaListener);
    }

    JNIEXPORT void JNICALL Java_net_rk4z_juef_UefWindow_resizeOverlay(JNIEnv *env, jobject obj, jlong window_ptr) {
        auto *window = reinterpret_cast<UefWindow *>(window_ptr);
        window->overlay_->Resize(window->window_->width(), window->window_->height());
    }

    JNIEXPORT void JNICALL Java_net_rk4z_juef_UefWindow_destroy(JNIEnv *env, jobject obj, jlong window_ptr) {
        auto *window = reinterpret_cast<UefWindow *>(window_ptr);
        delete window;
    }
}
