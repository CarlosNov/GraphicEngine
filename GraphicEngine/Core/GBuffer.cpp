#include "GBuffer.h"

namespace GraphicEngine 
{
	GBuffer::GBuffer()
	{
		glGenFramebuffers(1, &m_gBuffer);
		glGenTextures(1, &m_gPosition);
		glGenTextures(1, &m_gNormal);
		glGenTextures(1, &m_gAlbedoSpec);
		glGenTextures(1, &m_depthBuffer);
	}

	GBuffer::~GBuffer()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		glDeleteFramebuffers(1, &m_gBuffer);
		glDeleteTextures(1, &m_gPosition);
		glDeleteTextures(1, &m_gNormal);
		glDeleteTextures(1, &m_gAlbedoSpec);
		glDeleteTextures(1, &m_depthBuffer);
	}

	void GBuffer::ResizeBuffer(uint32_t width, uint32_t height)
	{
		// TODO: Remove width and height
		m_Width = width;
		m_Height = height;

		glBindFramebuffer(GL_FRAMEBUFFER, m_gBuffer);

		glBindTexture(GL_TEXTURE_2D, m_gPosition);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_gPosition, 0);


		glBindTexture(GL_TEXTURE_2D, m_gNormal);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT1, GL_TEXTURE_2D, m_gNormal, 0);


		glBindTexture(GL_TEXTURE_2D, m_gAlbedoSpec);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT2, GL_TEXTURE_2D, m_gAlbedoSpec, 0);

		glBindTexture(GL_TEXTURE_2D, m_depthBuffer);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT24, width, height, 0, GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE, NULL);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, m_depthBuffer, 0);

		const GLenum buffers[3] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1, GL_COLOR_ATTACHMENT2 };
		glDrawBuffers(3, buffers);

		if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
			std::cout << "Framebuffer not complete!" << std::endl;
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	void GBuffer::BindBuffer()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_gBuffer);
	}

	void GBuffer::UnbindBuffer()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}
}
