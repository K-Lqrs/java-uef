#pragma once

#include <jni.h>

extern "C" {
    JNIEXPORT jboolean JNICALL Java_net_rk4z_juef_JUEFFileSystem_JUEF_1fileExists(JNIEnv* env, jobject obj, jstring path);
    JNIEXPORT jstring JNICALL Java_net_rk4z_juef_JUEFFileSystem_JUEF_1getFileMimeType(JNIEnv* env, jobject obj, jstring path);
    JNIEXPORT jstring JNICALL Java_net_rk4z_juef_JUEFFileSystem_JUEF_1getFileCharset(JNIEnv* env, jobject obj, jstring path);
    JNIEXPORT jbyteArray JNICALL Java_net_rk4z_juef_JUEFFileSystem_JUEF_1openFile(JNIEnv* env, jobject obj, jstring path);
}
