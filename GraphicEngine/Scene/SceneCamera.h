#pragma once

#include "Renderer/Camera.h"

namespace GraphicEngine
{
	class SceneCamera : public Camera
	{
	public:
		enum class ProjectionType { Perspective = 0, Orthographic = 1 };

	public:

		SceneCamera() = default;
		virtual ~SceneCamera() = default;

		void SetPerspective(float fov, float cameraNear, float cameraFar);
		void SetOrtographic(float size, float cameraNear, float cameraFar);

		void SetCameraViewportSize(uint32_t width, uint32_t height);

		float GetPerspectiveFOV() { return m_PerspectiveFOV; }
		void SetPerspectiveFOV(float fov) { m_PerspectiveFOV = fov; RecalculateProjection(); }
		float GetPerspectiveNear() { return m_PerspectiveNear;  }
		void SetPerspectiveNear(float cameraNear) { m_PerspectiveNear = cameraNear; RecalculateProjection(); }
		float GetPerspectiveFar() { return m_PerspectiveFar; }
		void SetPerspectiveFar(float cameraFar) { m_PerspectiveFar = cameraFar; RecalculateProjection(); }

		float GetOrtographicSize() { return m_OrthographicSize; }
		void SetOrthographicSize(float fov) { m_OrthographicSize = fov; RecalculateProjection(); }
		float GetOrthographicNear() { return m_OrthographicNear; }
		void SetOrthographicNear(float cameraNear) { m_OrthographicNear = cameraNear; RecalculateProjection(); }
		float GetOrthographicFar() { return m_OrthographicFar; }
		void SetOrthographicFar(float cameraFar) { m_OrthographicFar = cameraFar; RecalculateProjection(); }

		ProjectionType GetProjectionType() const { return m_ProjectionType; }
		void SetProjectionType(ProjectionType type) { m_ProjectionType = type; RecalculateProjection(); }

	private:
		void RecalculateProjection();

	protected:
		ProjectionType m_ProjectionType = ProjectionType::Perspective;

		float m_PerspectiveFOV = glm::radians(60.0f);
		float m_PerspectiveNear = 0.01f, m_PerspectiveFar = 1000.0f;

		float m_OrthographicSize = 10.0f;
		float m_OrthographicNear = -1.0f, m_OrthographicFar = 1.0f;

		float m_AspectRatio = 1.0f;
	};
}