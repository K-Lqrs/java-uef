#include "UefRenderer.hpp"

RefPtr<Session> UefRenderer::session_ = nullptr;
RefPtr<Renderer> UefRenderer::renderer_ = nullptr;

void UefRenderer::create() {
    renderer_ = Renderer::Create();
    session_ = renderer_->default_session();
}

void UefRenderer::refreshDisplay(int displayId) {
    renderer_->RefreshDisplay(displayId);
}

RefPtr<View> UefRenderer::createView(int width, int height, const ViewConfig &config, const RefPtr<Session>& session) {
    return renderer_->CreateView(width, height, config, session ? session : session_);
}

void Java_net_rk4z_juef_UefRenderer_create(JNIEnv *env, jclass obj) {
    UefRenderer::create();
}

void Java_net_rk4z_juef_UefRenderer_refreshDisplay(JNIEnv *env, jclass obj, jint displayId) {
    UefRenderer::refreshDisplay(displayId);
}

jobject Java_net_rk4z_juef_UefRenderer_createView(JNIEnv *env, jclass obj, jint width, jint height, jobject config, jobject session) {
    jclass configClass = env->GetObjectClass(config);

    jfieldID displayID = env->GetFieldID(configClass, "displayId", "I");
    jfieldID isAccelerated = env->GetFieldID(configClass, "isAccelerated", "Z");
    jfieldID initialDeviceScale = env->GetFieldID(configClass, "initialDeviceScale", "D");
    jfieldID isTransparent = env->GetFieldID(configClass, "isTransparent", "Z");
    jfieldID initialFocus = env->GetFieldID(configClass, "initialFocus", "Z");
    jfieldID enableImages = env->GetFieldID(configClass, "enableImages", "Z");
    jfieldID enableJavaScript = env->GetFieldID(configClass, "enableJavaScript", "Z");
    jfieldID enableCompositor = env->GetFieldID(configClass, "enableCompositor", "Z");
    jfieldID fontFamilyStandard = env->GetFieldID(configClass, "fontFamilyStandard", "Ljava/lang/String;");
    jfieldID fontFamilyFixed = env->GetFieldID(configClass, "fontFamilyFixed", "Ljava/lang/String;");
    jfieldID fontFamilySerif = env->GetFieldID(configClass, "fontFamilySerif", "Ljava/lang/String;");
    jfieldID fontFamilySansSerif = env->GetFieldID(configClass, "fontFamilySansSerif", "Ljava/lang/String;");
    jfieldID userAgent = env->GetFieldID(configClass, "userAgent", "Ljava/lang/String;");

    auto displayIDJava = env->GetIntField(config, displayID);
    auto isAcceleratedJava = env->GetBooleanField(config, isAccelerated);
    auto initialDeviceScaleJava = env->GetDoubleField(config, initialDeviceScale);
    jboolean isTransparentJava = env->GetBooleanField(config, isTransparent);
    jboolean initialFocusJava = env->GetBooleanField(config, initialFocus);
    jboolean enableImagesJava = env->GetBooleanField(config, enableImages);
    jboolean enableJavaScriptJava = env->GetBooleanField(config, enableJavaScript);
    jboolean enableCompositorJava = env->GetBooleanField(config, enableCompositor);
    auto fontFamilyStandardJava = (jstring) env->GetObjectField(config, fontFamilyStandard);
    auto fontFamilyFixedJava = (jstring) env->GetObjectField(config, fontFamilyFixed);
    auto fontFamilySerifJava = (jstring) env->GetObjectField(config, fontFamilySerif);
    auto fontFamilySansSerifJava = (jstring) env->GetObjectField(config, fontFamilySansSerif);
    auto userAgentJava = (jstring) env->GetObjectField(config, userAgent);

    ViewConfig viewConfig;
    viewConfig.display_id = displayIDJava;
    viewConfig.is_accelerated = isAcceleratedJava;
    viewConfig.initial_device_scale = initialDeviceScaleJava;
    viewConfig.is_transparent = isTransparentJava;
    viewConfig.initial_focus = initialFocusJava;
    viewConfig.enable_images = enableImagesJava;
    viewConfig.enable_javascript = enableJavaScriptJava;
    viewConfig.enable_compositor = enableCompositorJava;
    viewConfig.font_family_standard = env->GetStringUTFChars(fontFamilyStandardJava, nullptr);
    viewConfig.font_family_fixed = env->GetStringUTFChars(fontFamilyFixedJava, nullptr);
    viewConfig.font_family_serif = env->GetStringUTFChars(fontFamilySerifJava, nullptr);
    viewConfig.font_family_sans_serif = env->GetStringUTFChars(fontFamilySansSerifJava, nullptr);
    viewConfig.user_agent = env->GetStringUTFChars(userAgentJava, nullptr);

    //TODO: Implement session
    UefRenderer::createView(width, height, viewConfig, nullptr);
}

