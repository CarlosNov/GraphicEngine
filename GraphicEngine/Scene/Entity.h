#pragma once

#include "Scene.h"
#include "entt.hpp"

namespace GraphicEngine
{
	class Entity
	{
	public:
		Entity() = default;
		Entity(entt::entity entity, Scene* scene);
		Entity(const Entity& other) = default;

		template<typename T, typename ... Args>
		T& AddComponent(Args&& ... args);

		template<typename T>
		T& GetComponent();

		template<typename T>
		void RemoveComponent();

		template<typename T>
		bool HasComponent();

	private:
		entt::entity m_Entity;
		Scene* m_Scene;
	};
}


