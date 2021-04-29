#pragma once

#include "config.h"

#include "Window/Window.h"
#include "Window/SceneWindow.h"
#include "Window/HierarchyWindow.h"
#include "Window/InspectorWindow.h"
#include "Context/UIContext.h"
#include "Context/RenderContext.h"

namespace GraphicEngine
{
    class MainWindow : public Window
    {
    public:
        MainWindow();
        ~MainWindow();

        void OnInit(int width, int height, const std::string& title) override;

        void OnUpdate() override;
        void OnRender() override;

        uint32_t GetWidth() override { return windowWidth; }
        uint32_t GetHeight() override { return windowHeight; }
        std::string GetTitle() override { return title; }

        void* GetNativeWindow() override { return m_Window; }
        void SetNativeWindow(void* window) override { m_Window = (GLFWwindow*) window; }

        bool IsRunning() override { return m_Running; }
        bool IsMinimized() override { return m_Minimized; }

        void OnKey(int key, int scancode, int action, int mods) override;
        void OnMouse(int button, int action, int mods) override;
        void OnScroll(double yoffset) override;
        void OnWindowResize(int width, int height) override;
        void OnWindowClose() override;


    private:
        GLFWwindow* m_Window;

        std::unique_ptr<UIContext> m_UIContext;
        std::unique_ptr<RenderContext> m_RenderContext;

        std::unique_ptr<SceneWindow> m_SceneWindow;
        std::unique_ptr<HierarchyWindow> m_HierarchyWindow;
        std::unique_ptr<InspectorWindow> m_InspectorWindow;

        bool m_Running = true;
        bool m_Minimized = false;
    };
}

