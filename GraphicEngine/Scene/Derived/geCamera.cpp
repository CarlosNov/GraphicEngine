#include "geCamera.h"


GraphicEngine::geCamera::geCamera(const char* name) : GraphicEngine::geNode::geNode(name)
{
	_projMatrix = glm::mat4(1.0f);
	_projMatrix = glm::perspective(glm::radians(60.0f), 1.0f, 1.0f, 50.0f);

	_viewMatrix = glm::mat4(1.0f);
	_viewMatrix = glm::translate(_viewMatrix, glm::vec3(0.0f, 0.0f, -7.0f));
}

GraphicEngine::geCamera::geCamera(const char* name, Transform transform) : GraphicEngine::geNode::geNode(name, transform)
{
	_projMatrix = glm::mat4(1.0f);
	_projMatrix = glm::perspective(glm::radians(60.0f), 1.0f, 1.0f, 50.0f);

	_viewMatrix = glm::mat4(1.0f);
	_viewMatrix = glm::translate(_viewMatrix, glm::vec3(0.0f, 0.0f, -7.0f));
}

GraphicEngine::geCamera::~geCamera()
{

}

void GraphicEngine::geCamera::render()
{

}

void GraphicEngine::geCamera::update()
{

}

void GraphicEngine::geCamera::accept(Visitor* visitor)
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

unsigned int GraphicEngine::geCamera::getWidth()
{
	return _windowWidth;
}

unsigned int GraphicEngine::geCamera::getHeight()
{
	return _windowHeight;
}

void GraphicEngine::geCamera::setWindowSize(int width, int height)
{
	_windowWidth = width;
	_windowHeight = height;
	_projMatrix = glm::perspective(glm::radians(60.0f), float(width) / float(height), 1.0f, 50.0f);
}
