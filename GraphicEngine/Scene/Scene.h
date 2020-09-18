#pragma once

#include "entt.hpp"

namespace GraphicEngine
{
	class Entity;

	class Scene
	{
	public:
		Scene();
		~Scene();

		Entity CreateEntity(const std::string& name);

	private:
		entt::registry m_Registry;

		friend class Entity;
	};
}


