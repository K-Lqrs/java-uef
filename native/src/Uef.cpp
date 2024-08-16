#include <jni.h>
#include <string>
#include <AppCore/App.h>
#include <Ultralight/platform/Config.h>
#include <AppCore/Window.h>
#include <AppCore/Overlay.h>
#include <iostream>

using namespace ultralight;

extern "C" {
    JNIEXPORT jlong JNICALL Java_net_rk4z_juef_Ultralight_createWindow(JNIEnv* env, jobject obj, jint width, jint height) {
        std::cout << "Creating window with width: " << width << " and height: " << height << std::endl;

        Settings settings;
        Config config;

        RefPtr<App> app = App::Create(settings, config);
        if (!app) {
            std::cerr << "Failed to create Ultralight App instance." << std::endl;
            return 0;
        }

        RefPtr<Window> window = Window::Create(app->main_monitor(), width, height, false, kWindowFlags_Resizable);
        if (!window) {
            std::cerr << "Failed to create Window instance or window is invalid." << std::endl;
            return 0;
        }

        std::cout << "Window created successfully. Pointer: " << window.get() << std::endl;
        return reinterpret_cast<jlong>(window.get());
    }


    JNIEXPORT jlong JNICALL Java_net_rk4z_juef_Ultralight_createView(JNIEnv* env, jobject obj, jlong windowPtr, jint width, jint height) {
        std::cout << "Creating view with width: " << width << " and height: " << height << std::endl;

        auto* window = reinterpret_cast<Window*>(windowPtr);
        if (!window) {
            std::cerr << "Invalid window pointer." << std::endl;
            return 0;
        }

        RefPtr<Overlay> overlay = Overlay::Create(window, width, height, 0, 0);
        if (!overlay) {
            std::cerr << "Failed to create Overlay instance." << std::endl;
            return 0;
        }

        std::cout << "View created successfully. Pointer: " << overlay->view().get() << std::endl;
        return reinterpret_cast<jlong>(overlay->view().get());
    }

    JNIEXPORT void JNICALL Java_net_rk4z_juef_Ultralight_loadHTMLFile(JNIEnv* env, jobject obj, jlong viewPtr, jstring filePath) {
        std::cout << "Loading HTML file..." << std::endl;

        auto* view = reinterpret_cast<View*>(viewPtr);
        if (!view) {
            std::cerr << "Invalid view pointer." << std::endl;
            return;
        }

        const char* path = env->GetStringUTFChars(filePath, nullptr);
        std::string url = "file://";
        url += path;

        std::cout << "Loading URL: " << url << std::endl;
        view->LoadURL(url.c_str());

        env->ReleaseStringUTFChars(filePath, path);
    }

    JNIEXPORT void JNICALL Java_net_rk4z_juef_Ultralight_render(JNIEnv* env, jobject obj, jlong appPtr) {
        std::cout << "Starting render loop..." << std::endl;

        auto* app = reinterpret_cast<App*>(appPtr);
        if (!app) {
            std::cerr << "Invalid app pointer." << std::endl;
            return;
        }

        app->Run();
        std::cout << "Render loop finished." << std::endl;
    }
}
