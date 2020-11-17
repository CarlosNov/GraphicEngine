#pragma once

#include "config.h"

namespace GraphicEngine
{
	class GBuffer
	{
	public:
		GBuffer();
		~GBuffer();

		void ResizeBuffer(uint32_t width, uint32_t height);

		void BindBuffer();
		void UnbindBuffer();

		unsigned int getColorBuffer();
		unsigned int getDepthBuffer();
		unsigned int getVertexBuffer();

		void setColorBuffer(unsigned int color);
		void setDepthBuffer(unsigned int depth);
		void setVertexBuffer(unsigned int vertex);

	private:
		unsigned int m_gBuffer;
		unsigned int m_gPosition;
		unsigned int m_gNormal;
		unsigned int m_gAlbedoSpec;
		unsigned int m_depthBuffer;
	};
}


