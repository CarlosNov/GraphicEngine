
#include "Application.h"

#include "config.h"
#include "IMGUI/imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_glfw.h"

namespace GraphicEngine
{
	Application::Application(const std::string& name)
	{
		m_Window = std::make_unique<GraphicEngine::MainWindow>();
		m_Window->OnInit(1080, 720, name);
	}

	void Application::Run()
	{
		while (m_Window->IsRunning())
		{
			m_Window->OnUpdate();
			m_Window->OnRender();
		}
	}
}