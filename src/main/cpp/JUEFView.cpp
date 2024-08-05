#include <jni.h>
#include <Ultralight/View.h>

JNIEXPORT void JNICALL Java_net_rk4z_juef_JUEFView_loadHTML(JNIEnv* env, jobject obj, jlong viewHandle, jstring html) {
    const char* htmlStr = env->GetStringUTFChars(html, nullptr);
    auto* view = reinterpret_cast<ultralight::View*>(viewHandle);
    view->LoadHTML(ultralight::String(htmlStr));
    env->ReleaseStringUTFChars(html, htmlStr);
}

JNIEXPORT void JNICALL Java_net_rk4z_juef_JUEFView_evaluateScript(JNIEnv* env, jobject obj, jlong viewHandle, jstring script) {
    const char* scriptStr = env->GetStringUTFChars(script, nullptr);
    auto* view = reinterpret_cast<ultralight::View*>(viewHandle);
    view->EvaluateScript(ultralight::String(scriptStr));
    env->ReleaseStringUTFChars(script, scriptStr);
}

JNIEXPORT void JNICALL Java_net_rk4z_juef_JUEFView_createInspectorView(JNIEnv* env, jobject obj, jlong viewHandle) {
    auto* view = reinterpret_cast<ultralight::View*>(viewHandle);
    view->CreateLocalInspectorView();
}
