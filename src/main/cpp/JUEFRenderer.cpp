#include "h/JUEFRenderer.h"
#include <Ultralight/Renderer.h>
#include "h/JUEF.h"

JNIEXPORT void JNICALL Java_net_rk4z_juef_JUEFRenderer_JUEF_1createRenderer(JNIEnv* env, jobject obj) {
    renderer = Renderer::Create();
}

JNIEXPORT void JNICALL Java_net_rk4z_juef_JUEFRenderer_JUEF_1updateRenderer(JNIEnv* env, jobject obj) {
    renderer->Update();
}

JNIEXPORT void JNICALL Java_net_rk4z_juef_JUEFRenderer_JUEF_1render(JNIEnv* env, jobject obj) {
    renderer->Render();
}
