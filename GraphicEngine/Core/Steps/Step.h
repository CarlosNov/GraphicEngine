#pragma once

#include "config.h"
#include "Core/FBO.h"
#include "Renderer/Camera.h"
#include "Scene/Components.h"

#include "ENTT/entt.hpp"

namespace GraphicEngine
{
	class Step
	{
	public:
		Step();
		~Step();
		
		virtual void render(entt::registry& registry, Camera* camera, glm::mat4* cameraTransform) = 0;

		GLuint getColorBuffer();
		GLuint getDepthBuffer();
		GLuint getVertexBuffer();

		void setColorBuffer(GLuint color);
		void setDepthBuffer(GLuint depth);
		void setVertexBuffer(GLuint vertex);

		virtual void resizeFBO(int width, int height);
	protected:
		FBO* _fbo;
	};
}

