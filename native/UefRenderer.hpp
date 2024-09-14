#ifndef UEFRENDERER_HPP
#define UEFRENDERER_HPP

#include <jni.h>
#include <Ultralight/Renderer.h>

using namespace ultralight;

class UefRenderer {
public:
    static RefPtr<Session> session_;
    static RefPtr<Renderer> renderer_;

    static void create();
    static void refreshDisplay(int displayId);
    static RefPtr<View> createView(int width, int height, const ViewConfig &config, const RefPtr<Session>& session = nullptr);
};

extern "C" {
    JNIEXPORT void JNICALL Java_net_rk4z_juef_UefRenderer_create(JNIEnv *env, jclass obj);

    JNIEXPORT jobject JNICALL Java_net_rk4z_juef_UefRenderer_createView(JNIEnv *env, jclass obj, jint width, jint height, jobject config, jobject session);
}

#endif //UEFRENDERER_HPP
