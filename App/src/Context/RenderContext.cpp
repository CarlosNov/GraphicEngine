#include "RenderContext.h"


namespace GraphicEngine
{
    static void OnKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        auto WindowCallback = static_cast<GraphicEngine::Window*>(glfwGetWindowUserPointer(window));
        WindowCallback->OnKey(key, scancode, action, mods);
    }

    static void OnMouseCallback(GLFWwindow* window, int button, int action, int mods)
    {
        auto WindowCallback = static_cast<GraphicEngine::Window*>(glfwGetWindowUserPointer(window));
        WindowCallback->OnMouse(button, action, mods);
    }

    static void OnScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
    {
        auto WindowCallback = static_cast<GraphicEngine::Window*>(glfwGetWindowUserPointer(window));
        WindowCallback->OnScroll(yoffset);
    }

    static void OnWindowResizeCallback(GLFWwindow* window, int width, int height)
    {
        auto WindowCallback = static_cast<GraphicEngine::Window*>(glfwGetWindowUserPointer(window));
        WindowCallback->OnWindowResize(width, height);
    }

    static void OnWindowCloseCallback(GLFWwindow* window)
    {
        auto WindowCallback = static_cast<GraphicEngine::Window*>(glfwGetWindowUserPointer(window));
        WindowCallback->OnWindowClose();
    }

    void RenderContext::Begin()
    {
        if (!glfwInit())
        {
            fprintf(stderr, "Error: GLFW Window couldn't be initialized\n");
            return;
        }

        auto glWindow = glfwCreateWindow(m_Window->GetWidth(), m_Window->GetHeight(), m_Window->GetTitle().c_str(), nullptr, nullptr);
        m_Window->SetNativeWindow(glWindow);

        if (!glWindow)
        {
            fprintf(stderr, "Error: GLFW Window couldn't be created\n");
            return;
        }

        glfwSetWindowUserPointer(glWindow, m_Window);
        glfwSetKeyCallback(glWindow, OnKeyCallback);
        glfwSetMouseButtonCallback(glWindow, OnMouseCallback);
        glfwSetScrollCallback(glWindow, OnScrollCallback);
        glfwSetWindowSizeCallback(glWindow, OnWindowResizeCallback);
        glfwSetWindowCloseCallback(glWindow, OnWindowCloseCallback);
        glfwMakeContextCurrent(glWindow);

        GLenum err = glewInit();
        if (GLEW_OK != err)
        {
            fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
            return;
        }

        glEnable(GL_DEPTH_TEST);
    }

    void RenderContext::PreRender()
    {
        glViewport(0, 0, m_Window->GetWidth(), m_Window->GetHeight());
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void RenderContext::PostRender()
    {
        glfwPollEvents();
        glfwSwapBuffers((GLFWwindow*)m_Window->GetNativeWindow());
    }

    void RenderContext::End()
    {
        glfwDestroyWindow((GLFWwindow*)m_Window->GetNativeWindow());
        glfwTerminate();
    }
}
