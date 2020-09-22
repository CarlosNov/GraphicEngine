#pragma once

#include "Renderer/Camera.h"

namespace GraphicEngine
{
	class PerspectiveCamera : public Camera
	{
	public:

		PerspectiveCamera() = default;
		virtual ~PerspectiveCamera() = default;

		void SetPerspective(float fov, float aspectRatio , float cameraNear, float cameraFar);

		float GetFov() { return m_Fov; }
		float GetAspectRatio() { return m_AspectRatio; }
		float GetNear() { return m_Near;  }
		float GetFar() { return m_Far; }

		void SetFov(float fov) { m_Fov = fov; RecalculateProjection(); }
		void SetAspectRatio(uint32_t width, uint32_t height) { m_AspectRatio = (float)width / (float)height;
															   RecalculateProjection(); }
		void SetAspectRatio(float aspectRatio) { m_AspectRatio = aspectRatio; RecalculateProjection(); }
		void SetNear(float cameraNear) { m_Near = cameraNear; RecalculateProjection(); }
		void SetFar(float cameraFar) { m_Far = cameraFar; RecalculateProjection(); }

	private:
		void RecalculateProjection();

	protected:
		float m_Fov = 60.0f;
		float m_AspectRatio = 1.0f;
		float m_Near = 1.0f, m_Far = 50.0f;
	};
}