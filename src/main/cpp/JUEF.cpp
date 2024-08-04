#include <jni.h>
#include <AppCore/App.h>
#include <AppCore/Window.h>
#include <AppCore/Overlay.h>

using namespace ultralight;

static RefPtr<App> app;
static RefPtr<Window> window;
static RefPtr<Overlay> overlay;

extern "C" {

    JNIEXPORT void JNICALL Java_net_rk4z_juef_JUEF_init(JNIEnv* env, jobject obj, jobject jSettings, jobject jConfig) {
        jclass settingsClass = env->GetObjectClass(jSettings);
        jfieldID developerNameField = env->GetFieldID(settingsClass, "developerName", "Ljava/lang/String;");
        jfieldID appNameField = env->GetFieldID(settingsClass, "appName", "Ljava/lang/String;");
        jfieldID fileSystemPathField = env->GetFieldID(settingsClass, "fileSystemPath", "Ljava/lang/String;");
        jfieldID loadShadersFromFileSystemField = env->GetFieldID(settingsClass, "loadShadersFromFileSystem", "Z");
        jfieldID forceCpuRendererField = env->GetFieldID(settingsClass, "forceCpuRenderer", "Z");

        auto developerName = static_cast<jstring>(env->GetObjectField(jSettings, developerNameField));
        auto appName = static_cast<jstring>(env->GetObjectField(jSettings, appNameField));
        auto fileSystemPath = static_cast<jstring>(env->GetObjectField(jSettings, fileSystemPathField));
        jboolean loadShadersFromFileSystem = env->GetBooleanField(jSettings, loadShadersFromFileSystemField);
        jboolean forceCpuRenderer = env->GetBooleanField(jSettings, forceCpuRendererField);

        const char* developerNameStr = env->GetStringUTFChars(developerName, nullptr);
        const char* appNameStr = env->GetStringUTFChars(appName, nullptr);
        const char* fileSystemPathStr = env->GetStringUTFChars(fileSystemPath, nullptr);

        Settings settings;
        settings.developer_name = developerNameStr;
        settings.app_name = appNameStr;
        settings.file_system_path = fileSystemPathStr;
        settings.load_shaders_from_file_system = loadShadersFromFileSystem;
        settings.force_cpu_renderer = forceCpuRenderer;

        env->ReleaseStringUTFChars(developerName, developerNameStr);
        env->ReleaseStringUTFChars(appName, appNameStr);
        env->ReleaseStringUTFChars(fileSystemPath, fileSystemPathStr);

        jclass configClass = env->GetObjectClass(jConfig);
        jfieldID cachePathField = env->GetFieldID(configClass, "cachePath", "Ljava/lang/String;");
        jfieldID resourcePathPrefixField = env->GetFieldID(configClass, "resourcePathPrefix", "Ljava/lang/String;");
        jfieldID fontGammaField = env->GetFieldID(configClass, "fontGamma", "D");
        jfieldID userStylesheetField = env->GetFieldID(configClass, "userStylesheet", "Ljava/lang/String;");
        jfieldID forceRepaintField = env->GetFieldID(configClass, "forceRepaint", "Z");

        auto cachePath = static_cast<jstring>(env->GetObjectField(jConfig, cachePathField));
        auto resourcePathPrefix = static_cast<jstring>(env->GetObjectField(jConfig, resourcePathPrefixField));
        jdouble fontGamma = env->GetDoubleField(jConfig, fontGammaField);
        auto userStylesheet = static_cast<jstring>(env->GetObjectField(jConfig, userStylesheetField));
        jboolean forceRepaint = env->GetBooleanField(jConfig, forceRepaintField);

        const char* cachePathStr = env->GetStringUTFChars(cachePath, nullptr);
        const char* resourcePathPrefixStr = env->GetStringUTFChars(resourcePathPrefix, nullptr);
        const char* userStylesheetStr = env->GetStringUTFChars(userStylesheet, nullptr);

        Config config;
        config.cache_path = cachePathStr;
        config.resource_path_prefix = resourcePathPrefixStr;
        config.font_gamma = fontGamma;
        config.user_stylesheet = userStylesheetStr;
        config.force_repaint = forceRepaint;

        env->ReleaseStringUTFChars(cachePath, cachePathStr);
        env->ReleaseStringUTFChars(resourcePathPrefix, resourcePathPrefixStr);
        env->ReleaseStringUTFChars(userStylesheet, userStylesheetStr);

        app = App::Create(settings, config);
    }

    JNIEXPORT jlong JNICALL Java_net_rk4z_juef_JUEF_createWindow(JNIEnv* env, jobject obj, jint width, jint height, jstring title) {
        const char* titleStr = env->GetStringUTFChars(title, nullptr);
        window = Window::Create(app->main_monitor(), width, height, false, kWindowFlags_Titled | kWindowFlags_Resizable);
        window->SetTitle(titleStr);
        env->ReleaseStringUTFChars(title, titleStr);
        return reinterpret_cast<jlong>(window.get());
    }

    JNIEXPORT jlong JNICALL Java_net_rk4z_juef_JUEF_createOverlay(JNIEnv* env, jobject obj, jlong windowHandle, jint width, jint height, jint x, jint y) {
        auto* win = reinterpret_cast<Window*>(windowHandle);
        overlay = Overlay::Create(win, width, height, x, y);
        return reinterpret_cast<jlong>(overlay.get());
    }

    JNIEXPORT void JNICALL Java_net_rk4z_juef_JUEF_loadURL(JNIEnv* env, jobject obj, jlong overlayHandle, jstring url) {
        const char* urlStr = env->GetStringUTFChars(url, nullptr);
        auto* ov = reinterpret_cast<Overlay*>(overlayHandle);
        ov->view()->LoadURL(urlStr);
        env->ReleaseStringUTFChars(url, urlStr);
    }

    JNIEXPORT void JNICALL Java_net_rk4z_juef_JUEF_loadHTML(JNIEnv* env, jobject obj, jlong overlayHandle, jstring html) {
        const char* htmlStr = env->GetStringUTFChars(html, nullptr);
        auto* ov = reinterpret_cast<Overlay*>(overlayHandle);
        ov->view()->LoadHTML(htmlStr);
        env->ReleaseStringUTFChars(html, htmlStr);
    }

    JNIEXPORT void JNICALL Java_net_rk4z_juef_JUEF_update(JNIEnv* env, jobject obj) {
        app->Run();
    }
}
