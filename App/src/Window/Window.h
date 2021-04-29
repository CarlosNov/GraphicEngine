#pragma once

#include <iostream>

namespace GraphicEngine
{
    class Window
    {
    public:
        virtual void OnInit(int width, int height, const std::string& title) = 0;
        virtual void OnUpdate() = 0;
        virtual void OnRender() = 0;

        virtual uint32_t GetWidth() = 0;
        virtual uint32_t GetHeight() = 0;
        virtual std::string GetTitle() = 0;

        virtual void* GetNativeWindow() = 0;
        virtual void SetNativeWindow(void* window) = 0;

        virtual bool IsRunning() = 0;
        virtual bool IsMinimized() = 0;

        virtual void OnKey(int key, int scancode, int action, int mods) = 0;
        virtual void OnMouse(int button, int action, int mods) = 0;
        virtual void OnScroll(double yoffset) = 0;
        virtual void OnWindowResize(int width, int height) = 0;
        virtual void OnWindowClose() = 0;

    protected:
        int windowWidth;
        int windowHeight;
        std::string title;
    };
}

