#include <jni.h>
#include <Ultralight/Renderer.h>

extern ultralight::RefPtr<ultralight::Renderer> renderer;

JNIEXPORT void JNICALL Java_net_rk4z_juef_JUEFRenderer_createRenderer(JNIEnv* env, jobject obj) {
    renderer = ultralight::Renderer::Create();
}

JNIEXPORT void JNICALL Java_net_rk4z_juef_JUEFRenderer_updateRenderer(JNIEnv* env, jobject obj) {
    renderer->Update();
}

JNIEXPORT void JNICALL Java_net_rk4z_juef_JUEFRenderer_render(JNIEnv* env, jobject obj) {
    renderer->Render();
}
