#pragma once

#include "Core/Steps/Step.h"
#include "Core/GBuffer.h"
#include "Core/FBO.h"
#include "Renderer/Shader.h"

#include "entt.hpp"


namespace GraphicEngine
{
	class Deferred : public Step
	{
	public:
		Deferred();
		~Deferred();

		void render(entt::registry& registry, Camera* camera, glm::mat4* cameraTransform);
		void resizeFBO(int width, int height) override;

		GBuffer* m_GBuffer;
		FBO* newfbo;
	private:
		
		Shader* shaderGeometry;
		Shader* shaderLighting;
	};
}

