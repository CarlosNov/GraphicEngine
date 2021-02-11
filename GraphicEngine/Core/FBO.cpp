#include "FBO.h"

GraphicEngine::FBO::FBO()
{
	glGenFramebuffers(1, &_fbo);
	glGenTextures(1, &_colorBufferTex);
	glGenTextures(1, &_depthBufferTex);
	glGenTextures(1, &_vertexBufferTex);
}

GraphicEngine::FBO::~FBO()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glDeleteFramebuffers(1, &_fbo);
	glDeleteTextures(1, &_colorBufferTex);
	glDeleteTextures(1, &_depthBufferTex);
	glDeleteTextures(1, &_vertexBufferTex);
}

void GraphicEngine::FBO::resizeFBO(unsigned int w, unsigned int h)
{
	glBindTexture(GL_TEXTURE_2D, _colorBufferTex);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);

	glBindTexture(GL_TEXTURE_2D, _depthBufferTex);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT24, w, h, 0, GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glBindTexture(GL_TEXTURE_2D, _vertexBufferTex);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB32F, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glBindFramebuffer(GL_FRAMEBUFFER, _fbo);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, _colorBufferTex, 0);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, _depthBufferTex, 0);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT1, GL_TEXTURE_2D, _vertexBufferTex, 0);

	const GLenum buffers[2] = { GL_COLOR_ATTACHMENT0,  GL_COLOR_ATTACHMENT1 };
	glDrawBuffers(2, buffers);

	if (GL_FRAMEBUFFER_COMPLETE != glCheckFramebufferStatus(GL_FRAMEBUFFER))
	{
		std::cerr << "Error: Configuration FBO" << std::endl;
		exit(1);
	}
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void GraphicEngine::FBO::bindFBO()
{
	glBindFramebuffer(GL_FRAMEBUFFER, _fbo);
}


unsigned int GraphicEngine::FBO::getColorBuffer()
{
	return _colorBufferTex;
}

unsigned int GraphicEngine::FBO::getDepthBuffer()
{
	return _depthBufferTex;
}

unsigned int GraphicEngine::FBO::getVertexBuffer()
{
	return _vertexBufferTex;
}

void GraphicEngine::FBO::setColorBuffer(unsigned int color)
{
	_colorBufferTex = color;
}

void GraphicEngine::FBO::setDepthBuffer(unsigned int depth)
{
	_depthBufferTex = depth;
}

void GraphicEngine::FBO::setVertexBuffer(unsigned int vertex)
{
	_vertexBufferTex = vertex;
}