#include "UefApp.h"

#include <AppCore/App.h>

extern "C" {
using namespace ultralight;

JNIEXPORT void JNICALL Java_net_rk4z_juef_UefApp_createApp(JNIEnv *env, jobject obj, jobject configObj, jobject settingsObj) {
    jclass settingsClass = env->GetObjectClass(settingsObj);

    jfieldID developerNameField = env->GetFieldID(settingsClass, "developerName", "Ljava/lang/String;");
    jfieldID appNameField = env->GetFieldID(settingsClass, "appName", "Ljava/lang/String;");
    jfieldID fileSystemPathField = env->GetFieldID(settingsClass, "fileSystemPath", "Ljava/lang/String;");
    jfieldID loadShadersField = env->GetFieldID(settingsClass, "loadShadersFromFileSystem", "Z");
    jfieldID forceCpuField = env->GetFieldID(settingsClass, "forceCpuRenderer", "Z");

    auto developerNameJava = (jstring) env->GetObjectField(settingsObj, developerNameField);
    auto appNameJava = (jstring) env->GetObjectField(settingsObj, appNameField);
    auto fileSystemPathJava = (jstring) env->GetObjectField(settingsObj, fileSystemPathField);
    jboolean loadShaders = env->GetBooleanField(settingsObj, loadShadersField);
    jboolean forceCpu = env->GetBooleanField(settingsObj, forceCpuField);

    const char *developerNameCStr = env->GetStringUTFChars(developerNameJava, nullptr);
    String developerName(developerNameCStr);
    env->ReleaseStringUTFChars(developerNameJava, developerNameCStr);

    const char *appNameCStr = env->GetStringUTFChars(appNameJava, nullptr);
    String appName(appNameCStr);
    env->ReleaseStringUTFChars(appNameJava, appNameCStr);

    const char *fileSystemPathCStr = env->GetStringUTFChars(fileSystemPathJava, nullptr);
    String fileSystemPath(fileSystemPathCStr);
    env->ReleaseStringUTFChars(fileSystemPathJava, fileSystemPathCStr);

    Settings settings;
    settings.developer_name = developerName;
    settings.app_name = appName;
    settings.file_system_path = fileSystemPath;
    settings.load_shaders_from_file_system = static_cast<bool>(loadShaders);
    settings.force_cpu_renderer = static_cast<bool>(forceCpu);

    App::Create(settings);
}

JNIEXPORT void JNICALL Java_net_rk4z_juef_UefApp_run(JNIEnv *env, jobject obj) {
    if (App::instance() != nullptr) {
        App::instance()->Run();
    }
}
}
