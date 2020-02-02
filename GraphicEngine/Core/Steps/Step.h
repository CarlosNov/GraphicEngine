#pragma once

#include "config.h"
#include "Core/FBO.h"
#include "Scene/geInterface.h"
#include "Scene/Derived/Camera.h"

namespace GraphicEngine
{
	class Step
	{
	public:
		Step();
		~Step();
		
		virtual void render(std::vector<geInterface*> toRenderNodes, Camera* camera) = 0;

		GLuint getColorBuffer();
		GLuint getDepthBuffer();
		GLuint getVertexBuffer();

		void setColorBuffer(GLuint color);
		void setDepthBuffer(GLuint depth);
		void setVertexBuffer(GLuint vertex);

	protected:
		FBO _fbo;
	};
}

