#include "Scene.h"
#include "Entity.h"
#include "Components.h"

namespace GraphicEngine
{
	Scene::Scene() 
	{
	}

	Scene::~Scene()
	{
	}

	Entity Scene::CreateEntity(const std::string& name)
	{
		Entity entity = Entity(m_Registry.create(), this);
		entity.AddComponent<TransformComponent>();
		name.empty() ? entity.AddComponent<TagComponent>(entity, "Empty Entity") : 
					   entity.AddComponent<TagComponent>(entity, name);
		return entity;
	}
}
