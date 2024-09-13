#include "UefPlatform.hpp"
#include "Utils.hpp"
#include <Ultralight/platform/Config.h>

void UefPlatform::setConfig(const Config& config) {
    Platform::instance().set_config(config);
}

void Java_net_rk4z_juef_UefPlatform_setConfig(JNIEnv *env, jobject obj, jobject config) {
    jclass configClass = env->GetObjectClass(config);

    jfieldID cachePathField = env->GetFieldID(configClass, "cachePath", "Ljava/lang/String;");
    jfieldID resourcePathPrefixField = env->GetFieldID(configClass, "resourcePathPrefix", "Ljava/lang/String;");
    jfieldID faceWindingField = env->GetFieldID(configClass, "faceWinding", "Lnet/rk4z/juef/util/FaceWinding;");
    jfieldID fontHintingField = env->GetFieldID(configClass, "fontHinting", "Lnet/rk4z/juef/util/FontHinting;");
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
    jfieldID effectQualityField = env->GetFieldID(configClass, "effectQuality", "Lnet/rk4z/juef/util/EffectQuality;");

    auto cachePathJava = (jstring) env->GetObjectField(config, cachePathField);
    auto resourcePathPrefixJava = (jstring) env->GetObjectField(config, resourcePathPrefixField);
    jdouble fontGamma = env->GetDoubleField(config, fontGammaField);
    auto userStylesheetJava = (jstring) env->GetObjectField(config, userStylesheetField);
    jboolean forceRepaint = env->GetBooleanField(config, forceRepaintField);
    jdouble animationTimerDelay = env->GetDoubleField(config, animationTimerDelayField);
    jdouble scrollTimerDelay = env->GetDoubleField(config, scrollTimerDelayField);
    jdouble recycleDelay = env->GetDoubleField(config, recycleDelayField);
    jlong memoryCacheSize = env->GetLongField(config, memoryCacheSizeField);
    jlong pageCacheSize = env->GetLongField(config, pageCacheSizeField);
    jlong overrideRamSize = env->GetLongField(config, overrideRamSizeField);
    jlong minLargeHeapSize = env->GetLongField(config, minLargeHeapSizeField);
    jlong minSmallHeapSize = env->GetLongField(config, minSmallHeapSizeField);
    jlong numRendererThreads = env->GetLongField(config, numRendererThreadsField);
    jdouble maxUpdateTime = env->GetDoubleField(config, maxUpdateTimeField);
    jlong bitmapAlignment = env->GetLongField(config, bitmapAlignmentField);

    const char *cachePathCStr = env->GetStringUTFChars(cachePathJava, nullptr);
    String cachePath(cachePathCStr);
    env->ReleaseStringUTFChars(cachePathJava, cachePathCStr);

    const char *resourcePathPrefixCStr = env->GetStringUTFChars(resourcePathPrefixJava, nullptr);
    String resourcePathPrefix(resourcePathPrefixCStr);
    env->ReleaseStringUTFChars(resourcePathPrefixJava, resourcePathPrefixCStr);

    const char *userStylesheetCStr = env->GetStringUTFChars(userStylesheetJava, nullptr);
    String userStylesheet(userStylesheetCStr);
    env->ReleaseStringUTFChars(userStylesheetJava, userStylesheetCStr);

    jobject javaFaceWinding = env->GetObjectField(config, faceWindingField);
    FaceWinding faceWinding = ConvertJavaFaceWindingToCpp(env, javaFaceWinding);

    jobject javaFontHinting = env->GetObjectField(config, fontHintingField);
    FontHinting fontHinting = ConvertJavaFontHintingToCpp(env, javaFontHinting);

    jobject javaEffectQuality = env->GetObjectField(config, effectQualityField);
    EffectQuality effectQuality = ConvertJavaEffectQualityToCpp(env, javaEffectQuality);

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
    config.effect_quality = effectQuality;

    UefPlatform::setConfig(config);
}