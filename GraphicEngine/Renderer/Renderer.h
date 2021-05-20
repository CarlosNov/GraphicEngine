#pragma once

#include <ENTT/entt.hpp>
#include "Scene/Entity.h"
#include "Core/Steps/Step.h"
#include "config.h"

namespace GraphicEngine
{
	class Entity;

	class Renderer
	{
	public:
		Renderer();
		~Renderer();

		void OnRender();
		void OnViewResize(uint32_t width, uint32_t height);

		void AddMainStepsVector(std::vector<Step*> mainSteps);
		void AddMainStep(Step* mainStep);
		virtual void  InitSelectedCameraSteps();

		Entity GetMainCamera() { return m_SceneCamera; };
		Entity GetSelectedCamera() { return m_SelectedCamera; };
		void SetMainCamera(Entity entity) { m_SceneCamera = entity; };
		void SetSelectedCamera(Entity entity) { m_SelectedCamera = entity; };

		uint32_t GetViewWidth() { return m_ViewWidth; };
		uint32_t GetViewHeight() { return m_ViewHeight; };
		GLuint GetCameraTexture() { return m_SelectedCameraTexture; };

		void SetRegistryReference(entt::registry* reg) { m_Registry = reg; };

	protected:
		uint32_t m_ViewWidth = 0, m_ViewHeight = 0;

		std::vector<Step*> m_MainSteps;
		std::vector<Step*> m_SelectedCameraSteps;
		GLuint m_SelectedCameraTexture = -1;

		Entity m_SceneCamera;
		Entity m_SelectedCamera;

		entt::registry* m_Registry = nullptr;
	};
}

