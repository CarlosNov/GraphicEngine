#pragma once

#include "GraphicEngine.h"
#include "config.h"
#include <SIGSLOT/signal.hpp>

namespace GraphicEngine
{
	class InspectorWindow
	{

	public:
		InspectorWindow();
		~InspectorWindow();

		std::shared_ptr<Scene> GetScene() { return m_ActiveScene; }
		void SetScene(std::shared_ptr<Scene> scene) { m_ActiveScene = scene; }

		void OnInit();
		void OnUpdate();
		void OnRender();

	public:
		void OnSelectedEntity(Entity entity);

	private:
		void DrawComponents(Entity entity);
		void DrawTransformComponent(Entity entity);

		void DrawVec3(const std::string& label, glm::vec3& values, float resetValue = 0.0f, float columnWidth = 100.0f);
	private:
		std::shared_ptr<Scene> m_ActiveScene;
		Entity m_SelectedEntity;
	};
}

