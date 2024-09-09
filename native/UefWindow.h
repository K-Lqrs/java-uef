#ifndef UEFWINDOW_H
#define UEFWINDOW_H

#include <jni.h>
#include <AppCore/Window.h>
#include <AppCore/Overlay.h>
#include "UefApp.h"

using namespace ultralight;

extern "C" {
    JNIEXPORT jlong JNICALL Java_net_rk4z_juef_UefWindow_createWindow(JNIEnv *env, jobject obj, jstring title, jstring url, jint x, jint y, jint width, jint height, jint flags);

    JNIEXPORT void JNICALL Java_net_rk4z_juef_UefWindow_setWindowListener(JNIEnv *env, jobject obj, jlong window_ptr, jobject listener);

    JNIEXPORT void JNICALL Java_net_rk4z_juef_UefWindow_setViewListener(JNIEnv *env, jobject obj, jlong window_ptr, jobject listener);

    JNIEXPORT void JNICALL Java_net_rk4z_juef_UefWindow_moveTo(JNIEnv *env, jobject obj, jlong window_ptr, jint x, jint y);

    JNIEXPORT void JNICALL Java_net_rk4z_juef_UefWindow_show(JNIEnv *env, jobject obj, jlong window_ptr);

    JNIEXPORT void JNICALL Java_net_rk4z_juef_UefWindow_hide(JNIEnv *env, jobject obj, jlong window_ptr);

    JNIEXPORT void JNICALL Java_net_rk4z_juef_UefWindow_destroy(JNIEnv *env, jobject obj, jlong window_ptr);
}

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

    UefWindow(const char *title, const char *url, int x, int y, int width, int height, int flags);
    ~UefWindow() override;

    void moveTo(int x, int y) const;
    void show() const;
    void hide() const;

    void setJavaWindowListener(JavaListener *listener);
    void setJavaViewListener(JavaListener *listener);

    void OnClose(Window *window) override;
    void OnResize(Window *window, uint32_t width, uint32_t height) override;
    bool OnKeyEvent(const KeyEvent &evt) override;
    bool OnMouseEvent(const MouseEvent &evt) override;
    bool OnScrollEvent(const ScrollEvent &evt) override;
    void OnChangeCursor(View *caller, Cursor cursor) override;
    void OnChangeTitle(View *caller, const String &title) override;
    void OnChangeTooltip(View *caller, const String &tooltip) override;
    void OnRequestClose(View *caller) override;
    void OnAddConsoleMessage(View *caller, MessageSource source, MessageLevel level, const String &message, uint32_t line_number, uint32_t column_number, const String &source_id) override;
    void OnChangeURL(View *caller, const String &url) override;
    RefPtr<View> OnCreateChildView(View *caller, const String &opener_url, const String &target_url, bool is_popup, const IntRect &popup_rect) override;
    RefPtr<View> OnCreateInspectorView(View *caller, bool is_local, const String &inspected_url) override;
};

#endif //UEFWINDOW_H
