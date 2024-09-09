#include "UefApp.h"

#include <stdexcept>
#include <AppCore/App.h>

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

RefPtr<App> app;

extern "C" {
using namespace ultralight;
    JNIEXPORT void JNICALL Java_net_rk4z_juef_UefApp_createApp(JNIEnv *env, jobject obj, jobject configObj, jobject settingsObj) {
        if (app.get() != nullptr) {
            jclass runtimeExceptionClass = env->FindClass("java/lang/RuntimeException");
            env->ThrowNew(runtimeExceptionClass, "App already created");
            return;
        }

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

        jclass configClass = env->GetObjectClass(configObj);

        jfieldID cachePathField = env->GetFieldID(configClass, "cachePath", "Ljava/lang/String;");
        jfieldID resourcePathPrefixField = env->GetFieldID(configClass, "resourcePathPrefix", "Ljava/lang/String;");
        jfieldID faceWindingField = env->GetFieldID(configClass, "faceWinding", "Lnet/rk4z/juef/FaceWinding;");
        jfieldID fontHintingField = env->GetFieldID(configClass, "fontHinting", "Lnet/rk4z/juef/FontHinting;");
        jfieldID fontGammaField = env->GetFieldID(configClass, "fontGamma", "D");
        jfieldID userStylesheetField = env->GetFieldID(configClass, "userStylesheet", "Ljava/lang/String;");
        jfieldID forceRepaintField = env->GetFieldID(configClass, "forceRepaint", "Z");
        jfieldID animationTimerDelayField = env->GetFieldID(configClass, "animationTimerDelay", "D");
        jfieldID scrollTimerDelayField = env->GetFieldID(configClass, "scrollTimerDelay", "D");
        jfieldID recycleDelayField = env->GetFieldID(configClass, "recycleDelay", "D");
        jfieldID memoryCacheSizeField = env->GetFieldID(configClass, "memoryCacheSize", "J");
        jfieldID pageCacheSizeField = env->GetFieldID(configClass, "pageCacheSize", "J");
        jfieldID overrideRamSizeField = env->GetFieldID(configClass, "overrideRamSize", "J");
        jfieldID minLargeHeapSizeField = env->GetFieldID(configClass, "minLargeHeapSize", "J");
        jfieldID minSmallHeapSizeField = env->GetFieldID(configClass, "minSmallHeapSize", "J");
        jfieldID numRendererThreadsField = env->GetFieldID(configClass, "numRendererThreads", "J");
        jfieldID maxUpdateTimeField = env->GetFieldID(configClass, "maxUpdateTime", "D");
        jfieldID bitmapAlignmentField = env->GetFieldID(configClass, "bitmapAlignment", "J");

        auto cachePathJava = (jstring) env->GetObjectField(configObj, cachePathField);
        auto resourcePathPrefixJava = (jstring) env->GetObjectField(configObj, resourcePathPrefixField);
        jdouble fontGamma = env->GetDoubleField(configObj, fontGammaField);
        auto userStylesheetJava = (jstring) env->GetObjectField(configObj, userStylesheetField);
        jboolean forceRepaint = env->GetBooleanField(configObj, forceRepaintField);
        jdouble animationTimerDelay = env->GetDoubleField(configObj, animationTimerDelayField);
        jdouble scrollTimerDelay = env->GetDoubleField(configObj, scrollTimerDelayField);
        jdouble recycleDelay = env->GetDoubleField(configObj, recycleDelayField);
        jlong memoryCacheSize = env->GetLongField(configObj, memoryCacheSizeField);
        jlong pageCacheSize = env->GetLongField(configObj, pageCacheSizeField);
        jlong overrideRamSize = env->GetLongField(configObj, overrideRamSizeField);
        jlong minLargeHeapSize = env->GetLongField(configObj, minLargeHeapSizeField);
        jlong minSmallHeapSize = env->GetLongField(configObj, minSmallHeapSizeField);
        jlong numRendererThreads = env->GetLongField(configObj, numRendererThreadsField);
        jdouble maxUpdateTime = env->GetDoubleField(configObj, maxUpdateTimeField);
        jlong bitmapAlignment = env->GetLongField(configObj, bitmapAlignmentField);

        const char *cachePathCStr = env->GetStringUTFChars(cachePathJava, nullptr);
        String cachePath(cachePathCStr);
        env->ReleaseStringUTFChars(cachePathJava, cachePathCStr);

        const char *resourcePathPrefixCStr = env->GetStringUTFChars(resourcePathPrefixJava, nullptr);
        String resourcePathPrefix(resourcePathPrefixCStr);
        env->ReleaseStringUTFChars(resourcePathPrefixJava, resourcePathPrefixCStr);

        const char *userStylesheetCStr = env->GetStringUTFChars(userStylesheetJava, nullptr);
        String userStylesheet(userStylesheetCStr);
        env->ReleaseStringUTFChars(userStylesheetJava, userStylesheetCStr);

        jobject javaFaceWinding = env->GetObjectField(configObj, faceWindingField);
        FaceWinding faceWinding = ConvertJavaFaceWindingToCpp(env, javaFaceWinding);

        jobject javaFontHinting = env->GetObjectField(configObj, fontHintingField);
        FontHinting fontHinting = ConvertJavaFontHintingToCpp(env, javaFontHinting);

        Config config;
        config.cache_path = cachePath;
        config.resource_path_prefix = resourcePathPrefix;
        config.face_winding = faceWinding;
        config.font_hinting = fontHinting;
        config.font_gamma = fontGamma;
        config.user_stylesheet = userStylesheet;
        config.force_repaint = static_cast<bool>(forceRepaint);
        config.animation_timer_delay = animationTimerDelay;
        config.scroll_timer_delay = scrollTimerDelay;
        config.recycle_delay = recycleDelay;
        config.memory_cache_size = memoryCacheSize;
        config.page_cache_size = pageCacheSize;
        config.override_ram_size = overrideRamSize;
        config.min_large_heap_size = minLargeHeapSize;
        config.min_small_heap_size = minSmallHeapSize;
        config.num_renderer_threads = numRendererThreads;
        config.max_update_time = maxUpdateTime;
        config.bitmap_alignment = bitmapAlignment;

        app = App::Create(settings, config);
    }

    JNIEXPORT void JNICALL Java_net_rk4z_juef_UefApp_run(JNIEnv *env, jobject obj) {
        if (app.get() != nullptr && !app->is_running()) {
            app->Run();
        }
    }

    JNIEXPORT void JNICALL Java_net_rk4z_juef_UefApp_stop(JNIEnv *env, jobject obj) {
        if (app.get() != nullptr && app->is_running()) {
            app->Quit();
        }
    }

    JNIEXPORT void JNICALL Java_net_rk4z_juef_UefApp_destroy(JNIEnv *env, jobject obj) {
        if (app.get() != nullptr) {
            if (app->is_running()) {
                app->Quit();
            }
            app.reset();
        }
    }
}
