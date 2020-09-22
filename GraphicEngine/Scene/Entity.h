#pragma once

#include "Scene.h"
#include "Components.h"

#include <entt.hpp>

namespace GraphicEngine
{
	class Entity
	{
	public:
		Entity() = default;
		Entity(entt::entity entity, Scene* scene);
		Entity(const Entity& other) = default;

		template<typename T, typename ... Args>
		T& AddComponent(Args&& ... args)
		{
			// TODO: Log Assert Message
			if (HasComponent<T>())
				std::cout << "Entity already has this component!";

			return m_Scene->m_Registry.emplace<T>(m_Entity, std::forward<Args>(args)...);
		}

		template<typename T>
		T& GetComponent()
		{
			// TODO: Log Assert Message
			if (!HasComponent<T>())
				std::cout << "Entity does not have this component!";

			return m_Scene->m_Registry.get<T>(m_Entity);
		}

		template<typename T>
		void RemoveComponent()
		{
			// TODO: Log Assert Message
			if (!HasComponent<T>())
				std::cout << "Entity does not have this component!";

			m_Scene->m_Registry.remove<T>(m_Entity);
		}

		template<typename T>
		bool HasComponent()
		{
			return m_Scene->m_Registry.has<T>(m_Entity);
		}

	private:
		entt::entity m_Entity {entt::null};
		Scene* m_Scene;
	};
}


