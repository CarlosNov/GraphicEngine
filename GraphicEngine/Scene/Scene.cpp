#include "Scene.h"
#include "Components.h"
#include "Entity.h"

#include "config.h"

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

			if (angle > (3.1415f * 2.0f))
				angle = 0;
			else
				angle = angle + 0.00001f;

			transform.Transform = glm::rotate(transform.Transform, angle, glm::vec3(1.0f, 1.0f, 0.0f));
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
					std::cout << "Main Camera found!" << std::endl;
					mainCamera = &camera.Camera;
					cameraTransform = &transform.Transform;
					cameraView = glm::inverse(transform.Transform);
					break;
				}
			}
		}

		if (mainCamera)
		{
			glBindFramebuffer(GL_FRAMEBUFFER, 4);

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			auto group2 = m_Registry.group<TransformComponent>(entt::get<MeshComponent, MaterialComponent>);
			for (auto entity : group2)
			{
				std::cout << "Render Material Object found!" << std::endl;
				auto [transform, mesh, material] = group2.get<TransformComponent, MeshComponent, MaterialComponent>(entity);

				glm::mat4 modelViewProj = mainCamera->GetProjectionMatrix() * cameraView * transform.Transform;
				glm::mat4 modelView = cameraView * transform.Transform;
				glm::mat4 normal = glm::transpose(glm::inverse(modelView));

				material.Material.ActivateProgram();
				material.Material.SetModelViewProjMat(modelViewProj);
				material.Material.SetModelViewMat(modelView);
				material.Material.SetNormalMat(normal);			
				material.Material.ActivateTextures();

				mesh.Mesh.Bind();

				material.Material.SetAttributes(mesh.Mesh.GetPosVBO(), mesh.Mesh.GetColorVBO(), mesh.Mesh.GetNormalVBO(), mesh.Mesh.GetTexCoordVBO());

				mesh.Mesh.Bind();
				glDrawElements(GL_TRIANGLES, mesh.Mesh.GetNumTriangleIndex(), GL_UNSIGNED_INT, (void*)0);
			}
			
			/*
			Renderer2D::BeginScene(mainCamera->GetProjection(), *cameraTransform);

			auto group = m_Registry.group<TransformComponent>(entt::get<SpriteRendererComponent>);
			for (auto entity : group)
			{
				auto [transform, sprite] = group.get<TransformComponent, SpriteRendererComponent>(entity);

				Renderer2D::DrawQuad(transform, sprite.Color);
			}

			Renderer2D::EndScene();
			*/
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
}
