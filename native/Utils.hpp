#ifndef UTILS_HPP
#define UTILS_HPP

#include <jni.h>
#include <Ultralight/platform/Config.h>

using namespace ultralight;

FaceWinding ConvertJavaFaceWindingToCpp(JNIEnv *env, jobject javaFaceWinding);

FontHinting ConvertJavaFontHintingToCpp(JNIEnv *env, jobject javaFontHinting);

EffectQuality ConvertJavaEffectQualityToCpp(JNIEnv *env, jobject javaEffectQuality);

#endif //UTILS_HPP
