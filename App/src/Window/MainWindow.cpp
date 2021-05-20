#include "MainWindow.h"

#include <IMGUI/imgui.h>
#include <SIGSLOT/signal.hpp>

namespace GraphicEngine
{
    MainWindow::MainWindow() : m_Window(nullptr)
    {
        m_UIContext = std::make_unique<UIContext>();
        m_RenderContext = std::make_unique<RenderContext>();
        m_SceneWindow = std::make_unique<SceneWindow>();
        m_HierarchyWindow = std::make_unique<HierarchyWindow>();
        m_InspectorWindow = std::make_unique<InspectorWindow>();
    }

    MainWindow::~MainWindow()
    {
        m_RenderContext->End();
        m_UIContext->End();
    }

    void MainWindow::OnKey(int key, int scancode, int action, int mods)
    {

    }

    void MainWindow::OnMouse(int button, int action, int mods)
    {
        
    }

    void MainWindow::OnScroll(double delta)
    {
        
    }

    void MainWindow::OnWindowResize(int width, int height)
    {
        windowWidth = width;
        windowHeight = height;

        m_SceneWindow->OnResize(width, height);
        OnRender();
    }

    void MainWindow::OnWindowClose()
    {
        m_Running = false;
    }

    void MainWindow::OnInit(int width, int height, const std::string& title)
    {
        this->windowWidth = width;
        this->windowHeight = height;
        this->title = title;

        m_RenderContext->SetWindow(this);
        m_RenderContext->Begin();

        m_UIContext->SetWindow(this);
        m_UIContext->Begin();
   
        m_SceneWindow->OnInit();
        m_SceneWindow->OnResize(width, height);

        m_HierarchyWindow->SetScene(m_SceneWindow->GetScene());
        m_HierarchyWindow->OnInit();

        m_InspectorWindow->SetScene(m_SceneWindow->GetScene());
        m_InspectorWindow->OnInit();

        m_HierarchyWindow->EntityClicked.connect(&InspectorWindow::OnSelectedEntity, &*m_InspectorWindow);
        m_SceneWindow->SetHierarchyContext.connect(&HierarchyWindow::SetScene, &*m_HierarchyWindow);
        m_UIContext->OpenScene.connect(&SceneWindow::OpenScene, &*m_SceneWindow);
        m_UIContext->SaveScene.connect(&SceneWindow::SaveScene, &*m_SceneWindow);
    }

    void MainWindow::OnUpdate()
    {
        m_SceneWindow->OnUpdate();
        m_HierarchyWindow->OnUpdate();
        m_InspectorWindow->OnUpdate();
    }

    void MainWindow::OnRender()
    {
        m_RenderContext->PreRender();
        m_UIContext->PreRender();
   
        m_HierarchyWindow->OnRender();
        m_InspectorWindow->OnRender();

        m_SceneWindow->OnRender();

        m_UIContext->PostRender();
        m_RenderContext->PostRender();
    }
}