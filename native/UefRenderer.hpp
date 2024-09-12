#ifndef UEFRENDERER_HPP
#define UEFRENDERER_HPP

#include <jni.h>
#include <Ultralight/Renderer.h>
#include <Ultralight/platform/Config.h>

using namespace ultralight;

class UefRenderer {
public:
    RefPtr<Renderer> renderer_;

    explicit UefRenderer(const Config &config);
    ~UefRenderer();

    void createSession(jboolean isPersistent, String name);
};



#endif //UEFRENDERER_HPP
