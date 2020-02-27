#include "geCamera.h"

GraphicEngine::geCamera::geCamera()
{
	_projMatrix = glm::mat4(1.0f);
	_projMatrix = glm::perspective(glm::radians(60.0f), 1.0f, 1.0f, 50.0f);

	_viewMatrix = glm::mat4(1.0f);
	_viewMatrix = glm::translate(_viewMatrix, glm::vec3(0.0f, 0.0f, -7.0f));
}


GraphicEngine::geCamera::~geCamera()
{
}

glm::mat4 GraphicEngine::geCamera::getProjMatrix()
{
	return _projMatrix;
}
glm::mat4 GraphicEngine::geCamera::getViewMatrix()
{
	return _viewMatrix;
}

void GraphicEngine::geCamera::setWindowSize(int width, int height)
{
	_projMatrix = glm::perspective(glm::radians(60.0f), float(width) / float(height), 1.0f, 50.0f);
}