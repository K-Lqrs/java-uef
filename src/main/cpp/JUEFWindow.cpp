#include "h/JUEFWindow.h"
#include <AppCore/Window.h>
#include "h/JUEF.h"

JNIEXPORT jlong JNICALL Java_net_rk4z_juef_JUEFWindow_JUEF_1createWindow(JNIEnv* env, jobject obj, jint width, jint height, jstring title) {
    const char* titleStr = env->GetStringUTFChars(title, nullptr);
    auto window = Window::Create(app->main_monitor(), width, height, false, kWindowFlags_Titled | kWindowFlags_Resizable);
    window->SetTitle(titleStr);
    env->ReleaseStringUTFChars(title, titleStr);
    return reinterpret_cast<jlong>(window.get());
}
