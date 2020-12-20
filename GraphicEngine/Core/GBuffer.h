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


		uint32_t GetGBuffer() { return m_gBuffer; }
		uint32_t GetPositionTex() { return m_gPosition; }
		uint32_t GetNormalTex() { return m_gNormal; }
		uint32_t GetAlbedoSpecTex() { return m_gAlbedoSpec; }
		uint32_t GetDepthBuffer() { return m_depthBuffer; }

		uint32_t GetWidth() { return m_Width; }
		uint32_t GetHeight() { return m_Height; }

		void GetPositionTex(uint32_t position) { m_gPosition = position; }
		void GetNormalTex(uint32_t normal) { m_gNormal = normal; }
		void GetAlbedoSpecTex(uint32_t albedoSpec) { m_gAlbedoSpec = albedoSpec; }
		void GetDepthBuffer(uint32_t depth) { m_depthBuffer = depth; }

	private:
		uint32_t m_gBuffer;
		uint32_t m_gPosition;
		uint32_t m_gNormal;
		uint32_t m_gAlbedoSpec;
		uint32_t m_depthBuffer;

		uint32_t m_Width;
		uint32_t m_Height;
	};
}


