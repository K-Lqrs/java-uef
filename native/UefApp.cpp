#include "UefApp.h"

#include <string>
#include <AppCore/App.h>

extern "C" {
using namespace ultralight;

JNIEXPORT void JNICALL uef::UefApp::Java_net_rk4z_juef_UefApp_createApp(JNIEnv *env, jobject obj, jobject configObj,
                                                                        jobject settingsObj) {
    jclass settingsClass = env->GetObjectClass(settingsObj);

    jmethodID getDeveloperName = env->GetMethodID(settingsClass, "getDeveloperName", "()Ljava/lang/String;");
    jmethodID getAppName = env->GetMethodID(settingsClass, "getAppName", "()Ljava/lang/String;");
    jmethodID getFileSystemPath = env->GetMethodID(settingsClass, "getFileSystemPath", "()Ljava/lang/String;");
    jmethodID getLoadShadersFromFileSystem = env->GetMethodID(settingsClass, "isLoadShadersFromFileSystem", "()Z");
    jmethodID getForceCpuRenderer = env->GetMethodID(settingsClass, "isForceCpuRenderer", "()Z");

    auto developerNameJava = (jstring) env->CallObjectMethod(settingsObj, getDeveloperName);
    auto appNameJava = (jstring) env->CallObjectMethod(settingsObj, getAppName);
    auto fileSystemPathJava = (jstring) env->CallObjectMethod(settingsObj, getFileSystemPath);
    jboolean loadShadersFromFileSystem = env->CallBooleanMethod(settingsObj, getLoadShadersFromFileSystem);
    jboolean forceCpuRenderer = env->CallBooleanMethod(settingsObj, getForceCpuRenderer);

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
    settings.load_shaders_from_file_system = static_cast<bool>(loadShadersFromFileSystem);
    settings.force_cpu_renderer = static_cast<bool>(forceCpuRenderer);

    jclass configClass = env->GetObjectClass(configObj);

    jmethodID getCachePath = env->GetMethodID(configClass, "getCachePath", "()Ljava/lang/String;");
    jmethodID getMemoryCacheSize = env->GetMethodID(configClass, "getMemoryCacheSize", "()J");
    jmethodID getFontGamma = env->GetMethodID(configClass, "getFontGamma", "()D");
    jmethodID getUserStylesheet = env->GetMethodID(configClass, "getUserStylesheet", "()Ljava/lang/String;");
    jmethodID getForceRepaint = env->GetMethodID(configClass, "isForceRepaint", "()Z");
    jmethodID getPageCacheSize = env->GetMethodID(configClass, "getPageCacheSize", "()J");
    jmethodID getOverrideRamSize = env->GetMethodID(configClass, "getOverrideRamSize", "()J");
    jmethodID getMinLargeHeapSize = env->GetMethodID(configClass, "getMinLargeHeapSize", "()J");
    jmethodID getMinSmallHeapSize = env->GetMethodID(configClass, "getMinSmallHeapSize", "()J");
    jmethodID getNumRendererThreads = env->GetMethodID(configClass, "getNumRendererThreads", "()J");
    jmethodID getMaxUpdateTime = env->GetMethodID(configClass, "getMaxUpdateTime", "()D");
    jmethodID getBitmapAlignment = env->GetMethodID(configClass, "getBitmapAlignment", "()J");

    auto cachePathJava = (jstring) env->CallObjectMethod(configObj, getCachePath);
    jlong memoryCacheSize = env->CallLongMethod(configObj, getMemoryCacheSize);
    jdouble fontGamma = env->CallDoubleMethod(configObj, getFontGamma);
    auto userStylesheetJava = (jstring) env->CallObjectMethod(configObj, getUserStylesheet);
    jboolean forceRepaint = env->CallBooleanMethod(configObj, getForceRepaint);
    jlong pageCacheSize = env->CallLongMethod(configObj, getPageCacheSize);
    jlong overrideRamSize = env->CallLongMethod(configObj, getOverrideRamSize);
    jlong minLargeHeapSize = env->CallLongMethod(configObj, getMinLargeHeapSize);
    jlong minSmallHeapSize = env->CallLongMethod(configObj, getMinSmallHeapSize);
    jlong numRendererThreads = env->CallLongMethod(configObj, getNumRendererThreads);
    jdouble maxUpdateTime = env->CallDoubleMethod(configObj, getMaxUpdateTime);
    jlong bitmapAlignment = env->CallLongMethod(configObj, getBitmapAlignment);

    const char *cachePathCStr = env->GetStringUTFChars(cachePathJava, NULL);
    String cachePath(cachePathCStr);
    env->ReleaseStringUTFChars(cachePathJava, cachePathCStr);

    const char *userStylesheetCStr = env->GetStringUTFChars(userStylesheetJava, NULL);
    String userStylesheet(userStylesheetCStr);
    env->ReleaseStringUTFChars(userStylesheetJava, userStylesheetCStr);

    Config config;
    config.cache_path = cachePath;
    config.memory_cache_size = static_cast<uint32_t>(memoryCacheSize);
    config.font_gamma = fontGamma;
    config.user_stylesheet = userStylesheet;
    config.force_repaint = static_cast<bool>(forceRepaint);
    config.page_cache_size = static_cast<uint32_t>(pageCacheSize);
    config.override_ram_size = static_cast<uint32_t>(overrideRamSize);
    config.min_large_heap_size = static_cast<uint32_t>(minLargeHeapSize);
    config.min_small_heap_size = static_cast<uint32_t>(minSmallHeapSize);
    config.num_renderer_threads = static_cast<uint32_t>(numRendererThreads);
    config.max_update_time = maxUpdateTime;
    config.bitmap_alignment = static_cast<uint32_t>(bitmapAlignment);

    App::Create(settings, config);
}
}
