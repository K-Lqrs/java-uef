#include "h/JUEFFontLoader.h"
#include <Ultralight/platform/FontLoader.h>
#include <Ultralight/platform/Platform.h>
#include <Ultralight/String.h>

JNIEXPORT void JNICALL Java_net_rk4z_juef_JUEFFontLoader_JUEF_1loadFont(JNIEnv* env, jobject obj, jstring path) {
    const char* pathStr = env->GetStringUTFChars(path, nullptr);

    ultralight::String family(pathStr);
    int weight = 400;
    bool italic = false;

    auto fontFile = ultralight::Platform::instance().font_loader()->Load(family, weight, italic);
    env->ReleaseStringUTFChars(path, pathStr);

    if (!fontFile) {
        jclass ioException = env->FindClass("java/io/IOException");
        if (ioException != nullptr) {
            env->ThrowNew(ioException, "Failed to load font.");
        }
    }
}

JNIEXPORT void JNICALL Java_net_rk4z_juef_JUEFFontLoader_JUEF_1fallbackFont(JNIEnv* env, jobject obj) {
    // Call the method and ignore the result, since it returns void
    ultralight::Platform::instance().font_loader()->fallback_font();
}
