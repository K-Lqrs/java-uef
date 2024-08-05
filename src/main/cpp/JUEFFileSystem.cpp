#include <jni.h>
#include <limits>
#include <Ultralight/platform/FileSystem.h>
#include <Ultralight/platform/Platform.h>
#include <Ultralight/String.h>

JNIEXPORT jboolean JNICALL Java_net_rk4z_juef_JUEFFileSystem_fileExists(JNIEnv* env, jobject obj, jstring path) {
    const char* pathStr = env->GetStringUTFChars(path, nullptr);
    bool exists = ultralight::Platform::instance().file_system()->FileExists(pathStr);
    env->ReleaseStringUTFChars(path, pathStr);
    return exists ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jstring JNICALL Java_net_rk4z_juef_JUEFFileSystem_getFileMimeType(JNIEnv* env, jobject obj, jstring path) {
    const char* pathStr = env->GetStringUTFChars(path, nullptr);
    ultralight::String mimeType = ultralight::Platform::instance().file_system()->GetFileMimeType(pathStr);
    env->ReleaseStringUTFChars(path, pathStr);
    return env->NewStringUTF(mimeType.utf8().data());
}

JNIEXPORT jstring JNICALL Java_net_rk4z_juef_JUEFFileSystem_getFileCharset(JNIEnv* env, jobject obj, jstring path) {
    const char* pathStr = env->GetStringUTFChars(path, nullptr);
    ultralight::String charset = ultralight::Platform::instance().file_system()->GetFileCharset(pathStr);
    env->ReleaseStringUTFChars(path, pathStr);
    return env->NewStringUTF(charset.utf8().data());
}

JNIEXPORT jbyteArray JNICALL Java_net_rk4z_juef_JUEFFileSystem_openFile(JNIEnv* env, jobject obj, jstring path) {
    const char* pathStr = env->GetStringUTFChars(path, nullptr);
    auto fileContent = ultralight::Platform::instance().file_system()->OpenFile(pathStr);
    env->ReleaseStringUTFChars(path, pathStr);

    if (fileContent->size() > static_cast<size_t>(std::numeric_limits<jsize>::max())) {
        jclass ioException = env->FindClass("java/io/IOException");
        if (ioException != nullptr) {
            env->ThrowNew(ioException, "File size is too large to be processed.");
        }
        return nullptr;
    }

    jsize arraySize = static_cast<jsize>(fileContent->size());
    jbyteArray byteArray = env->NewByteArray(arraySize);
    env->SetByteArrayRegion(byteArray, 0, arraySize, reinterpret_cast<const jbyte*>(fileContent->data()));
    return byteArray;
}
