#include "Renderer.h"
#include "Core/Steps/Deferred.h"
#include "Camera.h"

namespace GraphicEngine
{
	Renderer::Renderer()
	{
		InitSelectedCameraSteps();
	}

	Renderer::~Renderer()
	{
		for (std::vector<Step*>::iterator i = m_MainSteps.begin(); i != m_MainSteps.end(); ++i) 
		{
			delete* i;
		}

		for (std::vector<Step*>::iterator i = m_SelectedCameraSteps.begin(); i != m_SelectedCameraSteps.end(); ++i)
		{
			delete* i;
		}
	}

	void Renderer::OnRender()
	{
		if (m_Registry != nullptr)
		{
			Camera* sceneCamera = nullptr;
			glm::mat4* sceneCameraTransform = nullptr;

			if (m_SceneCamera && !m_MainSteps.empty())
			{
				auto view = m_Registry->view<TransformComponent, CameraComponent>();
				for (auto entity : view)
				{
					if (m_SceneCamera.GetEntityID() == (uint32_t)entity)
					{
						auto [transform, camera] = view.get<TransformComponent, CameraComponent>(entity);

						sceneCamera = &camera.Camera;
						glm::mat4 aux = transform.GetTransform();
						sceneCameraTransform = &aux;
					}
				}

				for (auto Step : m_MainSteps)
				{
					Step->render(*m_Registry, sceneCamera, sceneCameraTransform);
				}
				glUseProgram(NULL);
			}		

			Camera* selectedCamera = nullptr;
			glm::mat4* selectedCameraTransform = nullptr;

			if (m_SelectedCamera && !m_SelectedCameraSteps.empty())
			{
				auto view = m_Registry->view<TransformComponent, CameraComponent>();
				for (auto entity : view)
				{
					if (m_SelectedCamera.GetEntityID() == (uint32_t)entity)
					{
						auto [transform, camera] = view.get<TransformComponent, CameraComponent>(entity);

						selectedCamera = &camera.Camera;
						glm::mat4 aux = transform.GetTransform();
						selectedCameraTransform = &aux;
					}
				}

				for (auto Step : m_SelectedCameraSteps)
				{
					Step->render(*m_Registry, selectedCamera, selectedCameraTransform);
				}
				glUseProgram(NULL);
			}
		}
	}

	void Renderer::OnViewResize(uint32_t width, uint32_t height)
	{
		m_ViewWidth = width;
		m_ViewHeight = height;

		auto view = m_Registry->view<CameraComponent>();
		for (auto entity : view)
		{
			CameraComponent& cameraComponent = view.get<CameraComponent>(entity);

			// TODO: Fixed aspect ratio check
			cameraComponent.Camera.SetCameraViewportSize(width, height);
		}

		for (auto Step : m_MainSteps)
		{
			Step->resizeFBO(width, height);
		}

		for (auto Step : m_SelectedCameraSteps)
		{
			Step->resizeFBO(width, height);
		}
	}

	void Renderer::AddMainStepsVector(std::vector<Step*> mainSteps)
	{
		m_MainSteps = mainSteps;
	}

	void Renderer::AddMainStep(Step* mainStep)
	{
		if(mainStep != nullptr)
			m_MainSteps.push_back(mainStep);
	}

	void Renderer::InitSelectedCameraSteps()
	{
		m_SelectedCameraSteps.clear();
		m_SelectedCameraSteps.push_back(new Deferred());
		m_SelectedCameraTexture = m_SelectedCameraSteps[0]->getColorBuffer();
	}
}