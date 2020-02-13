#include "Core/Steps/Step.h"

GraphicEngine::Step::Step()
{
	_fbo = new FBO();
}

GraphicEngine::Step::~Step()
{
	delete(_fbo);
}

GLuint GraphicEngine::Step::getColorBuffer()
{
	return _fbo->getColorBuffer();
}

GLuint GraphicEngine::Step::getDepthBuffer()
{
	return _fbo->getDepthBuffer();
}

GLuint GraphicEngine::Step::getVertexBuffer()
{
	return _fbo->getVertexBuffer();
}

void GraphicEngine::Step::setColorBuffer(GLuint color)
{
	_fbo->setColorBuffer(color);
}

void GraphicEngine::Step::setDepthBuffer(GLuint depth)
{
	_fbo->setDepthBuffer(depth);
}

void GraphicEngine::Step::setVertexBuffer(GLuint vertex)
{
	_fbo->setVertexBuffer(vertex);
}

void GraphicEngine::Step::resizeFBO(int width, int height)
{
	_fbo->resizeFBO(width, height);
}