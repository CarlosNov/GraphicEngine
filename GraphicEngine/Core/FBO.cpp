#include "FBO.h"

GraphicEngine::FBO::FBO()
{
	//initFBO();
}

GraphicEngine::FBO::~FBO()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glDeleteFramebuffers(1, &_fbo);
	glDeleteTextures(1, &_colorBufferTex);
	glDeleteTextures(1, &_depthBufferTex);
}

void GraphicEngine::FBO::initFBO()
{
	glGenFramebuffers(1, &_fbo);
	glGenTextures(1, &_colorBufferTex);
	glGenTextures(1, &_depthBufferTex);
}

void GraphicEngine::FBO::resizeFBO(unsigned int w, unsigned int h)
{
	glBindTexture(GL_TEXTURE_2D, _colorBufferTex);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0,
		GL_RGBA, GL_FLOAT, NULL);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);

	glBindTexture(GL_TEXTURE_2D, _depthBufferTex);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT24, w, h, 0,
		GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glBindFramebuffer(GL_FRAMEBUFFER, _fbo);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
		GL_TEXTURE_2D, _colorBufferTex, 0);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,
		GL_TEXTURE_2D, _depthBufferTex, 0);

	const GLenum buffers[1] = { GL_COLOR_ATTACHMENT0 };	
	glDrawBuffers(1, buffers);

	if (GL_FRAMEBUFFER_COMPLETE != glCheckFramebufferStatus(GL_FRAMEBUFFER))
	{
		std::cerr << "Error: Configuration FBO" << std::endl;
		exit(1);
	}
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}