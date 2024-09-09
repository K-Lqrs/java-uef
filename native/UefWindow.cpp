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

            bool OnMouseEvent(const MouseEvent &evt) override {
                if (javaWindowListener_ && javaWindowListener_->listener) {
                    JNIEnv *env = javaWindowListener_->env;

                    jclass listenerClass = env->GetObjectClass(javaWindowListener_->listener);

                    jmethodID onMouseEventMethod = env->GetMethodID(listenerClass, "onMouseEvent", "(Lnet/rk4z/juef/event/UefMouseEvent;)Z");
                    if (onMouseEventMethod) {
                        jclass mouseEventClass = env->FindClass("net/rk4z/juef/event/UefMouseEvent");
                        jmethodID mouseEventConstructor = env->GetMethodID(mouseEventClass, "<init>", "(Lnet/rk4z/juef/event/UefMouseEvent$Type;IILnet/rk4z/juef/event/UefMouseEvent$Button;)V");

                        jclass mouseEventTypeClass = env->FindClass("net/rk4z/juef/event/UefMouseEvent$Type");
                        jfieldID typeFieldID;
                        switch (evt.type) {
                            case MouseEvent::kType_MouseMoved:
                                typeFieldID = env->GetStaticFieldID(mouseEventTypeClass, "MouseMoved", "Lnet/rk4z/juef/event/UefMouseEvent$Type;");
                                break;
                            case MouseEvent::kType_MouseDown:
                                typeFieldID = env->GetStaticFieldID(mouseEventTypeClass, "MouseDown", "Lnet/rk4z/juef/event/UefMouseEvent$Type;");
                                break;
                            case MouseEvent::kType_MouseUp:
                                typeFieldID = env->GetStaticFieldID(mouseEventTypeClass, "MouseUp", "Lnet/rk4z/juef/event/UefMouseEvent$Type;");
                                break;
                            default:
                                return false;
                        }
                        jobject mouseEventType = env->GetStaticObjectField(mouseEventTypeClass, typeFieldID);

                        jclass mouseButtonClass = env->FindClass("net/rk4z/juef/event/UefMouseEvent$Button");
                        jfieldID buttonFieldID;
                        switch (evt.button) {
                            case MouseEvent::kButton_Left:
                                buttonFieldID = env->GetStaticFieldID(mouseButtonClass, "Left", "Lnet/rk4z/juef/event/UefMouseEvent$Button;");
                                break;
                            case MouseEvent::kButton_Middle:
                                buttonFieldID = env->GetStaticFieldID(mouseButtonClass, "Middle", "Lnet/rk4z/juef/event/UefMouseEvent$Button;");
                                break;
                            case MouseEvent::kButton_Right:
                                buttonFieldID = env->GetStaticFieldID(mouseButtonClass, "Right", "Lnet/rk4z/juef/event/UefMouseEvent$Button;");
                                break;
                            default:
                                buttonFieldID = env->GetStaticFieldID(mouseButtonClass, "None", "Lnet/rk4z/juef/event/UefMouseEvent$Button;");
                                break;
                        }
                        jobject mouseButton = env->GetStaticObjectField(mouseButtonClass, buttonFieldID);

                        jobject mouseEvent = env->NewObject(mouseEventClass, mouseEventConstructor, mouseEventType, evt.x, evt.y, mouseButton);

                        jboolean result = env->CallBooleanMethod(javaWindowListener_->listener, onMouseEventMethod, mouseEvent);

                        env->DeleteLocalRef(mouseEvent);
                        env->DeleteLocalRef(mouseEventType);
                        env->DeleteLocalRef(mouseButton);

                        return result == JNI_TRUE;
                    }
                }
                return false;
            }

            bool OnScrollEvent(const ScrollEvent &evt) override {
                if (javaWindowListener_ && javaWindowListener_->listener) {
                    JNIEnv *env = javaWindowListener_->env;

                    jclass listenerClass = env->GetObjectClass(javaWindowListener_->listener);

                    jmethodID onScrollEventMethod = env->GetMethodID(listenerClass, "onScrollEvent", "(Lnet/rk4z/juef/event/UefScrollEvent;)Z");
                    if (onScrollEventMethod) {
                        jclass scrollEventClass = env->FindClass("net/rk4z/juef/event/UefScrollEvent");
                        jmethodID scrollEventConstructor = env->GetMethodID(scrollEventClass, "<init>", "(Lnet/rk4z/juef/event/UefScrollEvent$Type;II)V");

                        jclass scrollEventTypeClass = env->FindClass("net/rk4z/juef/event/UefScrollEvent$Type");
                        jfieldID typeFieldID;
                        switch (evt.type) {
                            case ScrollEvent::kType_ScrollByPixel:
                                typeFieldID = env->GetStaticFieldID(scrollEventTypeClass, "ScrollByPixel", "Lnet/rk4z/juef/event/UefScrollEvent$Type;");
                                break;
                            case ScrollEvent::kType_ScrollByPage:
                                typeFieldID = env->GetStaticFieldID(scrollEventTypeClass, "ScrollByPage", "Lnet/rk4z/juef/event/UefScrollEvent$Type;");
                                break;
                            default:
                                return false;
                        }
                        jobject scrollEventType = env->GetStaticObjectField(scrollEventTypeClass, typeFieldID);

                        jobject scrollEvent = env->NewObject(scrollEventClass, scrollEventConstructor, scrollEventType, evt.delta_x, evt.delta_y);

                        jboolean result = env->CallBooleanMethod(javaWindowListener_->listener, onScrollEventMethod, scrollEvent);

                        env->DeleteLocalRef(scrollEvent);
                        env->DeleteLocalRef(scrollEventType);

                        return result == JNI_TRUE;
                    }
                }
                return false;
            }

            void OnChangeCursor(View *caller, Cursor cursor) override {
                window_->SetCursor(cursor);
                if (javaViewListener_ && javaViewListener_->listener) {
                    JNIEnv *env = javaViewListener_->env;

                    jclass listenerClass = env->GetObjectClass(javaViewListener_->listener);
                    jmethodID onChangeCursorMethod = env->GetMethodID(listenerClass, "onChangeCursor", "(JLnet/rk4z/juef/event/UefCursor;)V");

                    if (onChangeCursorMethod) {
                        jclass uefCursorClass = env->FindClass("net/rk4z/juef/event/UefCursor");
                        jmethodID fromValueMethod = env->GetStaticMethodID(uefCursorClass, "fromValue", "(I)Lnet/rk4z/juef/event/UefCursor;");
                        jobject uefCursor = env->CallStaticObjectMethod(uefCursorClass, fromValueMethod, static_cast<int>(cursor));

                        env->CallVoidMethod(javaViewListener_->listener, onChangeCursorMethod, reinterpret_cast<jlong>(caller), uefCursor);

                        env->DeleteLocalRef(uefCursor);
                    }
                }
            }

            void OnChangeTitle(View *caller, const String &title) override {
                if (javaViewListener_ && javaViewListener_->listener) {
                    JNIEnv *env = javaViewListener_->env;

                    jclass listenerClass = env->GetObjectClass(javaViewListener_->listener);

                    jmethodID onChangeTitleMethod = env->GetMethodID(listenerClass, "onChangeTitle", "(JLjava/lang/String;)V");

                    if (onChangeTitleMethod) {
                        jstring jTitle = env->NewStringUTF(title.utf8().data());

                        env->CallVoidMethod(javaViewListener_->listener, onChangeTitleMethod, reinterpret_cast<jlong>(caller), jTitle);

                        env->DeleteLocalRef(jTitle);
                    }
                }
            }

            void OnChangeTooltip(View *caller, const String &tooltip) override {
                if (javaViewListener_ && javaViewListener_->listener) {
                    JNIEnv *env = javaViewListener_->env;

                    jclass listenerClass = env->GetObjectClass(javaViewListener_->listener);

                    jmethodID onChangeTooltipMethod = env->GetMethodID(listenerClass, "onChangeTooltip", "(JLjava/lang/String;)V");

                    if (onChangeTooltipMethod) {
                        jstring jTooltip = env->NewStringUTF(tooltip.utf8().data());

                        env->CallVoidMethod(javaViewListener_->listener, onChangeTooltipMethod, reinterpret_cast<jlong>(caller), jTooltip);

                        env->DeleteLocalRef(jTooltip);
                    }
                }
            }

            void OnRequestClose(View *caller) override {
                if (javaViewListener_ && javaViewListener_->listener) {
                    JNIEnv *env = javaViewListener_->env;

                    jclass listenerClass = env->GetObjectClass(javaViewListener_->listener);
                    jmethodID onRequestCloseMethod = env->GetMethodID(listenerClass, "onRequestClose", "(J)V");

                    if (onRequestCloseMethod) {
                        env->CallVoidMethod(javaViewListener_->listener, onRequestCloseMethod, reinterpret_cast<jlong>(caller));
                    }
                }
            }

            void OnAddConsoleMessage(View *caller, MessageSource source, MessageLevel level, const String &message, uint32_t line_number, uint32_t column_number,
                const String &source_id) override {
                    if (javaViewListener_ && javaViewListener_->listener) {
                        JNIEnv *env = javaViewListener_->env;

                        jclass listenerClass = env->GetObjectClass(javaViewListener_->listener);
                        jmethodID onAddConsoleMessageMethod = env->GetMethodID(listenerClass, "onAddConsoleMessage",
                            "(JLnet/rk4z/juef/event/UefMessageSource;Lnet/rk4z/juef/event/UefMessageLevel;Ljava/lang/String;IILjava/lang/String;)V");

                        if (onAddConsoleMessageMethod) {
                            jclass sourceClass = env->FindClass("net/rk4z/juef/event/UefMessageSource");
                            jmethodID fromValueSourceMethod = env->GetStaticMethodID(sourceClass, "fromValue", "(I)Lnet/rk4z/juef/event/UefMessageSource;");
                            jobject uefSource = env->CallStaticObjectMethod(sourceClass, fromValueSourceMethod, static_cast<int>(source));

                            jclass levelClass = env->FindClass("net/rk4z/juef/event/UefMessageLevel");
                            jmethodID fromValueLevelMethod = env->GetStaticMethodID(levelClass, "fromValue", "(I)Lnet/rk4z/juef/event/UefMessageLevel;");
                            jobject uefLevel = env->CallStaticObjectMethod(levelClass, fromValueLevelMethod, static_cast<int>(level));

                            jstring jMessage = env->NewStringUTF(message.utf8().data());
                            jstring jSourceId = env->NewStringUTF(source_id.utf8().data());

                            env->CallVoidMethod(javaViewListener_->listener, onAddConsoleMessageMethod, reinterpret_cast<jlong>(caller), uefSource, uefLevel, jMessage,
                                                line_number, column_number, jSourceId);

                            env->DeleteLocalRef(uefSource);
                            env->DeleteLocalRef(uefLevel);
                            env->DeleteLocalRef(jMessage);
                            env->DeleteLocalRef(jSourceId);
                        }
                    }
            }

            void OnChangeURL(View *caller, const String &url) override {
                if (javaViewListener_ && javaViewListener_->listener) {
                    JNIEnv *env = javaViewListener_->env;

                    jclass listenerClass = env->GetObjectClass(javaViewListener_->listener);
                    jmethodID onChangeURLMethod = env->GetMethodID(listenerClass, "onChangeURL", "(JLjava/lang/String;)V");

                    if (onChangeURLMethod) {
                        jstring jURL = env->NewStringUTF(url.utf8().data());
                        env->CallVoidMethod(javaViewListener_->listener, onChangeURLMethod, reinterpret_cast<jlong>(caller), jURL);
                        env->DeleteLocalRef(jURL);
                    }
                }
            }

            RefPtr<View> OnCreateChildView(View *caller, const String &opener_url, const String &target_url, bool is_popup, const IntRect &popup_rect) override {
                if (javaViewListener_ && javaViewListener_->listener) {
                    JNIEnv *env = javaViewListener_->env;

                    jclass listenerClass = env->GetObjectClass(javaViewListener_->listener);
                    jmethodID onCreateChildViewMethod = env->GetMethodID(listenerClass, "onCreateChildView",
                        "(JLjava/lang/String;Ljava/lang/String;ZLnet/rk4z/juef/util/IntRect;)J");

                    if (onCreateChildViewMethod) {
                        jstring jOpenerURL = env->NewStringUTF(opener_url.utf8().data());
                        jstring jTargetURL = env->NewStringUTF(target_url.utf8().data());

                        jclass intRectClass = env->FindClass("net/rk4z/juef/util/IntRect");
                        jmethodID intRectConstructor = env->GetMethodID(intRectClass, "<init>", "(IIII)V");
                        jobject jPopupRect = env->NewObject(intRectClass, intRectConstructor, popup_rect.left, popup_rect.top, popup_rect.right, popup_rect.bottom);

                        jlong newViewPtr = env->CallLongMethod(javaViewListener_->listener, onCreateChildViewMethod, reinterpret_cast<jlong>(caller), jOpenerURL, jTargetURL,
                                                               static_cast<jboolean>(is_popup), jPopupRect);

                        env->DeleteLocalRef(jOpenerURL);
                        env->DeleteLocalRef(jTargetURL);
                        env->DeleteLocalRef(jPopupRect);

                        return reinterpret_cast<View*>(newViewPtr);
                    }
                }
                return nullptr;
            }

            RefPtr<View> OnCreateInspectorView(View *caller, bool is_local, const String &inspected_url) override {
                if (javaViewListener_ && javaViewListener_->listener) {
                    JNIEnv *env = javaViewListener_->env;

                    jclass listenerClass = env->GetObjectClass(javaViewListener_->listener);
                    jmethodID onCreateInspectorViewMethod = env->GetMethodID(listenerClass, "onCreateInspectorView", "(JZLjava/lang/String;)J");

                    if (onCreateInspectorViewMethod) {
                        jstring jInspectedURL = env->NewStringUTF(inspected_url.utf8().data());

                        jlong newViewPtr = env->CallLongMethod(javaViewListener_->listener, onCreateInspectorViewMethod, reinterpret_cast<jlong>(caller),
                                                               static_cast<jboolean>(is_local), jInspectedURL);

                        env->DeleteLocalRef(jInspectedURL);
                        return reinterpret_cast<View*>(newViewPtr);
                    }
                }
                return nullptr;
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
