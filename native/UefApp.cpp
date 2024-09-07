#include "UefApp.h"

#include <AppCore/Window.h>
#include <AppCore/App.h>

extern "C" {
using namespace ultralight;
RefPtr<Window> g_windowInstance;  // グローバル変数でウィンドウインスタンスを保持

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

JNIEXPORT void JNICALL Java_net_rk4z_juef_UefApp_createWindow(JNIEnv *env, jobject obj, jint width, jint height, jboolean fullscreen, jint flags) {
    if (App::instance() != nullptr) {
        auto monitor = App::instance()->main_monitor();

        bool isFullscreen = static_cast<bool>(fullscreen);

        int windowFlags = 0;
        if (flags & kWindowFlags_Borderless) {
            windowFlags |= kWindowFlags_Borderless;
        }
        if (flags & kWindowFlags_Titled) {
            windowFlags |= kWindowFlags_Titled;
        }
        if (flags & kWindowFlags_Resizable) {
            windowFlags |= kWindowFlags_Resizable;
        }
        if (flags & kWindowFlags_Maximizable) {
            windowFlags |= kWindowFlags_Maximizable;
        }
        if (flags & kWindowFlags_Hidden) {
            windowFlags |= kWindowFlags_Hidden;
        }

        g_windowInstance = Window::Create(monitor, width, height, isFullscreen, windowFlags);
    }
}

JNIEXPORT void JNICALL Java_net_rk4z_juef_UefApp_setWindowTitle(JNIEnv *env, jobject obj, jstring title) {
    if (g_windowInstance) {
        const char *nativeTitle = env->GetStringUTFChars(title, nullptr);
        g_windowInstance->SetTitle(nativeTitle);
        env->ReleaseStringUTFChars(title, nativeTitle);
    }
}

JNIEXPORT void JNICALL Java_net_rk4z_juef_UefApp_closeWindow(JNIEnv *env, jobject obj) {
    if (g_windowInstance) {
        g_windowInstance->Close();
        g_windowInstance = nullptr;
    }
}

JNIEXPORT void JNICALL Java_net_rk4z_juef_UefApp_run(JNIEnv *env, jobject obj) {
    if (App::instance() != nullptr) {
        g_windowInstance->Show();
        App::instance()->Run();
    }
}
}
