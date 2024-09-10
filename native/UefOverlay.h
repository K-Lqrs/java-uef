#ifndef UEFOVERLAY_H
#define UEFOVERLAY_H

#include <jni.h>
#include <AppCore/App.h>
#include <AppCore/Overlay.h>

using namespace ultralight;

extern "C" {
    JNIEXPORT void JNICALL Java_net_rk4z_juef_UefOverlay_moveTo(JNIEnv *env, jobject obj, jlong overlay_ptr, jint x, jint y);

    JNIEXPORT void JNICALL Java_net_rk4z_juef_UefOverlay_resize(JNIEnv *env, jobject obj, jlong overlay_ptr, jint width, jint height);

    JNIEXPORT void JNICALL Java_net_rk4z_juef_UefOverlay_loadUrl(JNIEnv *env, jobject obj, jlong overlay_ptr, jstring url);

    JNIEXPORT void JNICALL Java_net_rk4z_juef_UefOverlay_destroy(JNIEnv *env, jobject obj, jlong overlay_ptr);
}

class UefOverlay {
    public:
        RefPtr<Overlay> overlay_;

        UefOverlay(Window* window, int x, int y, int width, int height);
        ~UefOverlay();

        void moveTo(int x, int y) const;
        void resize(int width, int height) const;
        void loadUrl(const char* url) const;
        void destroy();
};



#endif //UEFOVERLAY_H
