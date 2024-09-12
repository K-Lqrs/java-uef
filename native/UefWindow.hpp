#ifndef UEFWINDOW_HPP
#define UEFWINDOW_HPP

#include <jni.h>
#include <AppCore/Window.h>

class UefOverlay;

using namespace ultralight;

class UefWindow {
public:
    RefPtr<Window> window_;

    UefWindow(const char *title, int width, int height, bool fullscreen, int flags);
    ~UefWindow();

    static UefWindow *createWindow(const char *title, int width, int height, bool fullscreen, int flags);
    static UefOverlay* createOverlay(jlong window_ptr, int width, int height, int x, int y);
    void setTitle(const char *title) const;
    void moveTo(int x, int y) const;
    void moveToCenter() const;
    void destroy() const;
};

extern "C" {
    JNIEXPORT jlong JNICALL Java_net_rk4z_uef_UefWindow_createWindow(JNIEnv *env, jobject obj, jstring title, jint width, jint height, jboolean fullscreen, jint flags);

    JNIEXPORT jlong JNICALL Java_net_rk4z_uef_UefWindow_createOverlay(JNIEnv *env, jobject obj, jlong window_ptr, jint width, jint height, jint x, jint y);

    JNIEXPORT void JNICALL Java_net_rk4z_uef_UefWindow_setTitle(JNIEnv *env, jobject obj, jlong window_ptr, jstring title);

    JNIEXPORT void JNICALL Java_net_rk4z_uef_UefWindow_moveTo(JNIEnv *env, jobject obj, jlong window_ptr, jint x, jint y);

    JNIEXPORT void JNICALL Java_net_rk4z_uef_UefWindow_moveToCenter(JNIEnv *env, jobject obj, jlong window_ptr);

    JNIEXPORT void JNICALL Java_net_rk4z_juef_UefWindow_destroy(JNIEnv *env, jobject obj, jlong window_ptr);
}

#endif // UEFWINDOW_HPP
