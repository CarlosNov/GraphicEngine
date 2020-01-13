#pragma once

#include "config.h"

namespace GraphicEngine
{
	class Camera
	{
	public:
		Camera();

		~Camera();

		glm::mat4 getProjMatrix();
		glm::mat4 getViewMatrix();

		void setWindowSize(int width, int height);

	private:
		glm::mat4 _projMatrix;
		glm::mat4 _viewMatrix;
	};
}

