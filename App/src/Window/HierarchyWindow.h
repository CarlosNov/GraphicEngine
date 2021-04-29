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

		Scene* GetScene() { return m_ActiveScene; }
		void SetScene(Scene* scene) { m_ActiveScene = scene; }

		void OnInit();
		void OnUpdate();
		void OnRender();

	public:
		sigslot::signal<Entity> EntityClicked;

	private:
		void DrawEntity(Entity entity);

	private:
		Scene* m_ActiveScene;
		Entity m_SelectedEntity;
	};
}