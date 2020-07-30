#pragma once

#include "config.h"
#include "Core/FBO.h"
#include "Scene/geNode.h"
#include "Scene/Derived/geCamera.h"

namespace GraphicEngine
{
	class Step
	{
	public:
		Step();
		~Step();
		
		virtual void render(std::map< int, geNode* > geNodes, geCamera* camera) = 0;

		GLuint getColorBuffer();
		GLuint getDepthBuffer();
		GLuint getVertexBuffer();

		void setColorBuffer(GLuint color);
		void setDepthBuffer(GLuint depth);
		void setVertexBuffer(GLuint vertex);

		void resizeFBO(int width, int height);
	protected:
		FBO* _fbo;
	};
}

