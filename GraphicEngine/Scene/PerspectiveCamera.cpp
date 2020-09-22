
#include "PerspectiveCamera.h"

#include "config.h"

namespace GraphicEngine
{
	void PerspectiveCamera::SetPerspective(float fov, float aspectRatio, float cameraNear, float cameraFar)
	{
		m_Fov = fov;
		m_AspectRatio = aspectRatio;
		m_Near = cameraNear;
		m_Far = cameraFar;
		RecalculateProjection();
	}

	void PerspectiveCamera::RecalculateProjection()
	{
		m_ProjMatrix = glm::perspective(glm::radians(m_Fov), m_AspectRatio, m_Near, m_Far);
	}
}