#include <jni.h>
#include <Ultralight/platform/FontLoader.h>
#include <Ultralight/platform/Platform.h>
#include <Ultralight/String.h>

JNIEXPORT void JNICALL Java_net_rk4z_juef_JUEFFontLoader_loadFont(JNIEnv* env, jobject obj, jstring family, jint weight, jboolean italic) {
    const char* familyStr = env->GetStringUTFChars(family, nullptr);

    ultralight::String familyName(familyStr);
    bool isItalic = static_cast<bool>(italic);

    auto fontFile = ultralight::Platform::instance().font_loader()->Load(familyName, weight, isItalic);
    env->ReleaseStringUTFChars(family, familyStr);

    if (!fontFile) {
        jclass ioException = env->FindClass("java/io/IOException");
        if (ioException != nullptr) {
            env->ThrowNew(ioException, "Failed to load font.");
        }
    }
}
