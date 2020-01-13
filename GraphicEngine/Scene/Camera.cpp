#include "Camera.h"

GraphicEngine::Camera::Camera()
{
	_projMatrix = glm::mat4(1.0f);
	_projMatrix = glm::perspective(glm::radians(60.0f), 1.0f, 1.0f, 50.0f);

	_viewMatrix = glm::mat4(1.0f);
	glm::translate(_viewMatrix, glm::vec3(0.0f, 0.0f, -7.0f));
}


GraphicEngine::Camera::~Camera()
{
}
