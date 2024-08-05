#pragma once

#include <jni.h>
#include <AppCore/App.h>
#include <AppCore/Window.h>
#include <Ultralight/Renderer.h>
#include <Ultralight/Session.h>

using namespace ultralight;

extern RefPtr<App> app;
extern RefPtr<Renderer> renderer;
extern RefPtr<Session> session;

extern "C" {
    JNIEXPORT void JNICALL Java_net_rk4z_juef_JUEF_JUEF_1init(JNIEnv* env, jobject obj, jobject jSettings, jobject jConfig);
    JNIEXPORT void JNICALL Java_net_rk4z_juef_JUEF_JUEF_1update(JNIEnv* env, jobject obj);
}
