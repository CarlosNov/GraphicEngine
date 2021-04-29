#pragma once

#include "Window/Window.h"
#include "config.h"

namespace GraphicEngine
{
    class RenderContext
    {
    public:
        RenderContext() : m_Window(nullptr) {}

        void SetWindow(void* window) { m_Window = (GraphicEngine::Window*)window; }

        void Begin();
        void PreRender();
        void PostRender();
        void End();

    protected:
        GraphicEngine::Window* m_Window;
    };
}


