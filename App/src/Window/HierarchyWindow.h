#pragma once

#include "GraphicEngine.h"

#include <SIGSLOT/signal.hpp>

namespace GraphicEngine
{
	class HierarchyWindow
	{

	public:
		HierarchyWindow();
		~HierarchyWindow();

		std::shared_ptr<Scene> GetScene() { return m_ActiveScene; }
		void SetScene(std::shared_ptr<Scene> scene) { m_ActiveScene = scene; }

		void OnInit();
		void OnUpdate();
		void OnRender();

	public:
		sigslot::signal<Entity> EntityClicked;

	private:
		void DrawEntity(Entity entity);

	private:
		std::shared_ptr<Scene> m_ActiveScene;
		Entity m_SelectedEntity;
	};
}