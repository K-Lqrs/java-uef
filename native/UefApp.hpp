#ifndef UEFAPP_HPP
#define UEFAPP_HPP

#include <jni.h>
#include <AppCore/App.h>

using namespace ultralight;

FaceWinding ConvertJavaFaceWindingToCpp(JNIEnv *env, jobject javaFaceWinding);

FontHinting ConvertJavaFontHintingToCpp(JNIEnv *env, jobject javaFontHinting);

class UefApp {
public:
    static RefPtr<App> app_;

    static void createApp(JNIEnv *env, const Config& config, const Settings& settings);

    static void run(JNIEnv *env);

    static void stop(JNIEnv *env);

    static void destroy(JNIEnv *env);
};

extern "C" {
    JNIEXPORT void JNICALL Java_net_rk4z_juef_UefApp_createApp(JNIEnv *env, jobject obj, jobject configObj, jobject settingsObj);

    JNIEXPORT void JNICALL Java_net_rk4z_juef_UefApp_run(JNIEnv *env, jobject obj);

    JNIEXPORT void JNICALL Java_net_rk4z_juef_UefApp_stop(JNIEnv *env, jobject obj);

    JNIEXPORT void JNICALL Java_net_rk4z_juef_UefApp_destroy(JNIEnv *env, jobject obj);
}

#endif //UEFAPP_HPP
