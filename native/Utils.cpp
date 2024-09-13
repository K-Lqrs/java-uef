#include "Utils.hpp"

#include <cstring>

FaceWinding ConvertJavaFaceWindingToCpp(JNIEnv *env, jobject javaFaceWinding) {
    jclass enumClass = env->GetObjectClass(javaFaceWinding);
    jmethodID toStringMethod = env->GetMethodID(enumClass, "toString", "()Ljava/lang/String;");

    auto enumNameJava = (jstring) env->CallObjectMethod(javaFaceWinding, toStringMethod);
    const char *enumNameCStr = env->GetStringUTFChars(enumNameJava, nullptr);

    FaceWinding faceWinding;
    if (strcmp(enumNameCStr, "CounterClockwise") == 0) {
        faceWinding = FaceWinding::CounterClockwise;
    } else {
        faceWinding = FaceWinding::Clockwise;
    }

    env->ReleaseStringUTFChars(enumNameJava, enumNameCStr);
    return faceWinding;
}

FontHinting ConvertJavaFontHintingToCpp(JNIEnv *env, jobject javaFontHinting) {
    jclass enumClass = env->GetObjectClass(javaFontHinting);
    jmethodID toStringMethod = env->GetMethodID(enumClass, "toString", "()Ljava/lang/String;");

    const auto enumNameJava = (jstring) env->CallObjectMethod(javaFontHinting, toStringMethod);
    const char *enumNameCStr = env->GetStringUTFChars(enumNameJava, nullptr);

    FontHinting fontHinting;
    if (strcmp(enumNameCStr, "Smooth") == 0) {
        fontHinting = FontHinting::Smooth;
    } else if (strcmp(enumNameCStr, "Monochrome") == 0) {
        fontHinting = FontHinting::Monochrome;
    } else if (strcmp(enumNameCStr, "None") == 0) {
        fontHinting = FontHinting::None;
    } else {
        fontHinting = FontHinting::Normal;
    }

    env->ReleaseStringUTFChars(enumNameJava, enumNameCStr);
    return fontHinting;
}

EffectQuality ConvertJavaEffectQualityToCpp(JNIEnv *env, jobject javaEffectQuality) {
    jclass enumClass = env->GetObjectClass(javaEffectQuality);
    jmethodID toStringMethod = env->GetMethodID(enumClass, "toString", "()Ljava/lang/String;");

    const auto enumNameJava = (jstring) env->CallObjectMethod(javaEffectQuality, toStringMethod);
    const char *enumNameCStr = env->GetStringUTFChars(enumNameJava, nullptr);

    EffectQuality effectQuality;
    if (strcmp(enumNameCStr, "Low") == 0) {
        effectQuality = EffectQuality::Low;
    } else if (strcmp(enumNameCStr, "High") == 0) {
        effectQuality = EffectQuality::High;
    } else {
        effectQuality = EffectQuality::Medium;
    }

    env->ReleaseStringUTFChars(enumNameJava, enumNameCStr);
    return effectQuality;
}