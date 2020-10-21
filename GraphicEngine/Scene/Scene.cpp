#include "Scene.h"
#include "Components.h"
#include "Entity.h"

#include "config.h"

namespace GraphicEngine
{
	Scene::Scene() : Scene::Scene("Empty Scene")
	{
	}

	Scene::Scene(const std::string& sceneName)
	{
		m_SceneName = sceneName;
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

	static float angle = 0.0f;

	void Scene::OnUpdate()
	{
		auto group2 = m_Registry.group<TransformComponent>(entt::get<MeshComponent, MaterialComponent>);
		for (auto entity : group2)
		{
			auto [transform, mesh, material] = group2.get<TransformComponent, MeshComponent, MaterialComponent>(entity);

		}
	}

	void Scene::OnRender()
	{
		Camera* mainCamera = nullptr;
		glm::mat4* cameraTransform = nullptr;
		glm::mat4 cameraView;

		{
			auto view = m_Registry.view<TransformComponent, CameraComponent>();
			for (auto entity : view)
			{
				auto [transform, camera] = view.get<TransformComponent, CameraComponent>(entity);

				if (camera.MainCamera)
				{
					mainCamera = &camera.Camera;
					cameraTransform = &transform.GetTransform();
					cameraView = glm::inverse(transform.GetTransform());
					break;
				}
			}
		}

		if (mainCamera && !m_Steps.empty())
		{
			for (auto Step : m_Steps)
			{
				Step->render(m_Registry, mainCamera, cameraTransform);
			}
			glUseProgram(NULL);
		}
	}

	void Scene::OnViewResize(uint32_t width, uint32_t height)
	{
		m_ViewWidth = width;
		m_ViewHeight = height;

		auto view = m_Registry.view<CameraComponent>();
		for (auto entity : view)
		{
			CameraComponent	&cameraComponent = view.get<CameraComponent>(entity);

			// TODO: Fixed aspect ratio check
			cameraComponent.Camera.SetAspectRatio(width, height);
		}
	}

	void Scene::AddSteps(std::vector<Step*> steps)
	{
		m_Steps = steps;
	}
}
