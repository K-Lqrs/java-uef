#include "UefRenderer.hpp"
#include <Ultralight/platform/Platform.h>

UefRenderer::UefRenderer(const Config &config) {
    //TODO: If need to implement FileSystem and FontLoader, do it here
    auto& platform = Platform::instance();
    platform.set_config(config);
    renderer_ = Renderer::Create();
}

UefRenderer::~UefRenderer() = default;

void UefRenderer::createSession(const jboolean isPersistent, const String& name) const {
    //TODO: Implement UefSession
    renderer_->CreateSession(isPersistent, name);
}

