#pragma once

#include "engine/window.h"
#include <SDL.h>
#include <utilities/time_utility.h>

namespace neko::sdl
{
class SdlWindow : neko::Window
{
public:
    virtual void Init() override;
    virtual void InitImGui();
    void Update(seconds dt) override;

    virtual void OnEvent(const SDL_Event& event);
    void Destroy() override;

protected:
    SDL_Window* window_ = nullptr;
};
}