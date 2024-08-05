#include "h/JUEFBitmap.h"
#include <Ultralight/Bitmap.h>

JNIEXPORT jlong JNICALL Java_net_rk4z_juef_JUEFBitmap_JUEF_1createBitmap(JNIEnv* env, jobject obj, jint width, jint height) {
    auto bitmap = ultralight::Bitmap::Create(width, height, ultralight::BitmapFormat::BGRA8_UNORM_SRGB);
    return reinterpret_cast<jlong>(bitmap.get());
}

JNIEXPORT void JNICALL Java_net_rk4z_juef_JUEFBitmap_JUEF_1lockPixels(JNIEnv* env, jobject obj, jlong bitmapHandle) {
    auto* bitmap = reinterpret_cast<ultralight::Bitmap*>(bitmapHandle);
    bitmap->LockPixels();
}

JNIEXPORT void JNICALL Java_net_rk4z_juef_JUEFBitmap_JUEF_1unlockPixels(JNIEnv* env, jobject obj, jlong bitmapHandle) {
    auto* bitmap = reinterpret_cast<ultralight::Bitmap*>(bitmapHandle);
    bitmap->UnlockPixels();
}

JNIEXPORT void JNICALL Java_net_rk4z_juef_JUEFBitmap_JUEF_1writePNG(JNIEnv* env, jobject obj, jlong bitmapHandle, jstring path) {
    const char* pathStr = env->GetStringUTFChars(path, nullptr);
    auto* bitmap = reinterpret_cast<ultralight::Bitmap*>(bitmapHandle);
    bool success = bitmap->WritePNG(pathStr);
    env->ReleaseStringUTFChars(path, pathStr);

    if (!success) {
        jclass ioException = env->FindClass("java/io/IOException");
        if (ioException != nullptr) {
            env->ThrowNew(ioException, "Failed to write PNG file.");
        }
    }
}