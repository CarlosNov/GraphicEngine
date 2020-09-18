#include "Entity.h"
#include "config.h"


namespace GraphicEngine
{
	Entity::Entity(entt::entity entity, Scene* scene)
	{
		m_Entity = entity;
		m_Scene = scene;
	}

	template<typename T,typename ... Args>
	T& Entity::AddComponent(Args&& ... args)
	{
		// TODO: Log Assert Message
		if (HasComponent<T>())
			std::cout << "Entity already has this component!";

		return m_Scene->m_Registry.emplace<T>(m_Entity, std::forward<Args>(args) ...);
	}

	template<typename T>
	T& Entity::GetComponent()
	{
		// TODO: Log Assert Message
		if (!HasComponent<T>())
			std::cout << "Entity does not have this component!";

		return m_Scene->m_Registry.get<T>(m_Entity);
	}

	template<typename T>
	void Entity::RemoveComponent()
	{
		// TODO: Log Assert Message
		if (!HasComponent<T>())
			std::cout << "Entity does not have this component!";

		m_Scene->m_Registry.remove<T>(m_Entity);
	}

	template<typename T>
	bool Entity::HasComponent()
	{
		return m_Scene->m_Registry.has<T>(m_Entity);
	}
}