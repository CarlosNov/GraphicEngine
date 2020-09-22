#include "Entity.h"


namespace GraphicEngine
{
	Entity::Entity(entt::entity entity, Scene* scene)
	{
		m_Entity = entity;
		m_Scene = scene;
	}
}