#include <jni.h>
#include <Ultralight/platform/Clipboard.h>
#include <Ultralight/platform/Platform.h>
#include <Ultralight/String.h>

JNIEXPORT void JNICALL Java_net_rk4z_juef_JUEFClipboard_clear(JNIEnv* env, jobject obj) {
    ultralight::Platform::instance().clipboard()->Clear();
}

JNIEXPORT jstring JNICALL Java_net_rk4z_juef_JUEFClipboard_readPlainText(JNIEnv* env, jobject obj) {
    ultralight::String text = ultralight::Platform::instance().clipboard()->ReadPlainText();
    return env->NewStringUTF(text.utf8().data());
}

JNIEXPORT void JNICALL Java_net_rk4z_juef_JUEFClipboard_writePlainText(JNIEnv* env, jobject obj, jstring text) {
    const char* textStr = env->GetStringUTFChars(text, nullptr);
    ultralight::Platform::instance().clipboard()->WritePlainText(textStr);
    env->ReleaseStringUTFChars(text, textStr);
}
