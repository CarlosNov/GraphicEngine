#pragma once

#include <entt.hpp>
#include <Core\Steps\Step.h>

namespace GraphicEngine
{
	class Entity;

	class Scene
	{
	public:
		Scene();
		Scene(const std::string& sceneName);
		~Scene();

		Entity CreateEntity(const std::string& name);
		void DestroyEntity(Entity entity);

		void OnUpdate();
		void OnRender();

		void OnViewResize(uint32_t width, uint32_t height);

		uint32_t GetViewWidth() { return m_ViewWidth;  }
		uint32_t GetViewHeight() { return m_ViewHeight; }

		void AddSteps(std::vector<Step*> steps);
	private:
		std::string m_SceneName;
		entt::registry m_Registry;
		uint32_t m_ViewWidth = 0, m_ViewHeight = 0;

		// TODO: Move this vector to the renderer
		std::vector<Step*> m_Steps;

		friend class Entity;
		friend class HierarchyPanel;
	};
}