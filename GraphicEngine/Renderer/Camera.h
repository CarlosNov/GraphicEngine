#pragma once

#include "glm.hpp"

namespace GraphicEngine
{
	class Camera
	{
	public:

		Camera() = default;
		Camera(const glm::mat4& projMatrix)
		{
			m_ProjMatrix = projMatrix;
		}

		virtual ~Camera() = default;

		const glm::mat4& GetProjectionMatrix() const { return m_ProjMatrix; }

	protected:
		glm::mat4 m_ProjMatrix = glm::mat4(1.0f);
	};
}