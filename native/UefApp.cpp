#include "UefApp.h"
#include <AppCore/App.h>

extern "C" {
    using namespace ultralight;

    JNIEXPORT void JNICALL uef::UefApp::createApp(JNIEnv *env, jobject obj) {
        App::Create();
    }
}
