#include <jni.h>
#include <AppCore/Window.h>
#include <AppCore/App.h>

extern ultralight::RefPtr<ultralight::App> app;

JNIEXPORT jlong JNICALL Java_net_rk4z_juef_JUEFWindow_createWindow(JNIEnv* env, jobject obj, jint width, jint height, jstring title) {
    const char* titleStr = env->GetStringUTFChars(title, nullptr);
    auto window = ultralight::Window::Create(app->main_monitor(), width, height, false, ultralight::kWindowFlags_Titled | ultralight::kWindowFlags_Resizable);
    window->SetTitle(titleStr);
    env->ReleaseStringUTFChars(title, titleStr);
    return reinterpret_cast<jlong>(window.get());
}
