#pragma once

#include "Window/MainWindow.h"

namespace GraphicEngine
{
	class Application
	{
	public:   
		Application(const std::string& name);
		static Application& GetInstance() { return *s_Instance; }

		void Run();	

	private:
		static Application* s_Instance;
		std::unique_ptr<GraphicEngine::MainWindow> m_Window;	
	};
}
