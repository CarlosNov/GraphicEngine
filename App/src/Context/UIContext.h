#pragma once

#include "Window/Window.h"

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

    protected:
        GraphicEngine::Window* m_Window;
    };
}


