/*#pragma once

#include "glm.hpp"

namespace GraphicEngine
{
	class Camera
	{
	public:
		
		Camera() = default;
		Camera(const glm::mat4& projMatrix);

		virtual ~Camera();

		glm::mat4 GetProjMatrix() { return m_ProjMatrix; }

	private:
		glm::mat4 m_ProjMatrix = glm::mat4(1.0f);
	};
}
*/