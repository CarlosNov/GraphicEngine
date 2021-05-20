#pragma once

#include "Window/Window.h"
#include "SIGSLOT/signal.hpp"

namespace GraphicEngine
{
    class UIContext
    {
    public:
        UIContext() : m_Window(nullptr) {}

        void SetWindow(void* window) { m_Window = (GraphicEngine::Window*) window; }

        void Begin();
        void PreRender();
        void PostRender();
        void End();

    public:
        sigslot::signal<std::string> OpenScene;
        sigslot::signal<std::string> SaveScene;

    protected:
        GraphicEngine::Window* m_Window;
    };
}


