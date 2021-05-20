#pragma once

#include "Scene.h"
#include "Components.h"

#include <ENTT/entt.hpp>

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

		uint32_t GetEntityID()
		{
			return (uint32_t) m_Entity;
		}

		operator bool() const { return m_Entity != entt::null; }
		operator uint32_t() const { return (uint32_t)m_Entity; }
		operator entt::entity() const { return m_Entity; }

		bool operator==(const Entity& other) const
		{
			return m_Entity == other.m_Entity && m_Scene == other.m_Scene;
		}

		bool operator!=(const Entity& other) const
		{
			return !(*this == other);
		}

	private:
		entt::entity m_Entity {entt::null};
		Scene* m_Scene;
	};
}