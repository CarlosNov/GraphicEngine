#include "Scene.h"
#include "Components.h"
#include "Entity.h"
#include "Renderer/Renderer.h"
#include "GraphicEngine.h"

namespace GraphicEngine
{
	Scene::Scene() : Scene::Scene("Empty Scene")
	{
		m_Renderer = new Renderer();
		m_Renderer->SetRegistryReference(&m_Registry);
	}

	Scene::Scene(const std::string& sceneName)
	{
		m_SceneName = sceneName;
		m_Renderer = new Renderer();
		m_Renderer->SetRegistryReference(&m_Registry);
	}

	Scene::~Scene()
	{
	}

	Entity Scene::CreateEntity(const std::string& name)
	{
		Entity entity = Entity(m_Registry.create(), this);
		entity.AddComponent<TransformComponent>();
		name.empty() ? entity.AddComponent<TagComponent>("Empty Entity") : entity.AddComponent<TagComponent>(name);		
		return entity;
	}

	void Scene::DestroyEntity(Entity entity)
	{
		m_Registry.destroy(entity);
	}

	void Scene::OnUpdate()
	{
	}

	void Scene::OnRender()
	{
		m_Renderer->OnRender();
	}

	void Scene::OnViewResize(uint32_t width, uint32_t height)
	{
		m_Renderer->OnViewResize(width, height);
	}

	uint32_t Scene::GetViewWidth() 
	{ 
		return m_Renderer->GetViewWidth(); 
	}

	uint32_t Scene::GetViewHeight() 
	{ 
		return m_Renderer->GetViewHeight(); 
	}

	GLuint Scene::GetCameraTexture() 
	{ 
		return m_Renderer->GetCameraTexture();
	}
}
