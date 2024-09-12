#ifndef UEFOVERLAY_HPP
#define UEFOVERLAY_HPP

#include <jni.h>
#include <AppCore/Overlay.h>

class UefWindow;

using namespace ultralight;

class UefOverlay {
public:
    RefPtr<Overlay> overlay_;

    UefOverlay(const UefWindow *window, int width, int height, int x, int y);
    ~UefOverlay();

    void moveTo(int x, int y) const;
    void resize(int width, int height) const;
    void focus() const;
    void unFocus() const;
    void show() const;
    void hide() const;

    static void destroy(UefOverlay* overlay);

    inline UefOverlay* get() {
        return this;
    }

    [[nodiscard]] inline const UefOverlay* get() const {
        return this;
    }
};

extern "C" {
    JNIEXPORT void JNICALL Java_net_rk4z_uef_UefOverlay_moveTo(JNIEnv *env, jobject obj, jlong overlay_ptr, jint x, jint y);

    JNIEXPORT void JNICALL Java_net_rk4z_uef_UefOverlay_resize(JNIEnv *env, jobject obj, jlong overlay_ptr, jint width, jint height);

    JNIEXPORT void JNICALL Java_net_rk4z_uef_UefOverlay_focus(JNIEnv *env, jobject obj, jlong overlay_ptr);

    JNIEXPORT void JNICALL Java_net_rk4z_uef_UefOverlay_unFocus(JNIEnv *env, jobject obj, jlong overlay_ptr);

    JNIEXPORT void JNICALL Java_net_rk4z_uef_UefOverlay_show(JNIEnv *env, jobject obj, jlong overlay_ptr);

    JNIEXPORT void JNICALL Java_net_rk4z_uef_UefOverlay_hide(JNIEnv *env, jobject obj, jlong overlay_ptr);

    JNIEXPORT void JNICALL Java_net_rk4z_uef_UefOverlay_destroy(JNIEnv *env, jobject obj, jlong overlay_ptr);
}

#endif //UEFOVERLAY_HPP
