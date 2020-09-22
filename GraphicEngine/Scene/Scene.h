#pragma once

#include <entt.hpp>

namespace GraphicEngine
{
	class Entity;

	class Scene
	{
	public:
		Scene();
		~Scene();

		Entity CreateEntity(const std::string& name);

		void OnUpdate();
		void OnRender();

		void OnViewResize(uint32_t width, uint32_t height);

	private:
		entt::registry m_Registry;
		uint32_t m_ViewWidth = 0, m_ViewHeight = 0;

		friend class Entity;
	};
}