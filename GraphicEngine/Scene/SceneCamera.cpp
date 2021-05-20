
#include "SceneCamera.h"

#include "config.h"

namespace GraphicEngine
{
	void SceneCamera::SetPerspective(float fov, float cameraNear, float cameraFar)
	{
		m_ProjectionType = ProjectionType::Perspective;
		m_PerspectiveFOV = fov;
		m_PerspectiveNear = cameraNear;
		m_PerspectiveFar = cameraFar;
		RecalculateProjection();
	}

	void SceneCamera::SetOrtographic(float size, float cameraNear, float cameraFar)
	{
		m_ProjectionType = ProjectionType::Orthographic;
		m_OrthographicSize = size;
		m_OrthographicNear = cameraNear;
		m_OrthographicFar = cameraFar;
		RecalculateProjection();
	}

	void SceneCamera::SetCameraViewportSize(uint32_t width, uint32_t height)
	{
		m_AspectRatio = (float) width / (float) height;
		RecalculateProjection();
	}

	void SceneCamera::RecalculateProjection()
	{
		if (m_ProjectionType == ProjectionType::Perspective)
		{
			m_ProjMatrix = glm::perspective(m_PerspectiveFOV, m_AspectRatio, m_PerspectiveNear, m_PerspectiveFar);
		}
		else
		{
			float orthoLeft = -m_OrthographicSize * m_AspectRatio * 0.5f;
			float orthoRight = m_OrthographicSize * m_AspectRatio * 0.5f;
			float orthoBottom = -m_OrthographicSize * 0.5f;
			float orthoTop = m_OrthographicSize * 0.5f;

			m_ProjMatrix = glm::ortho(orthoLeft, orthoRight, orthoBottom, orthoTop, m_OrthographicNear, m_OrthographicFar);
		}
	}
}