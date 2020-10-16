#pragma once

#include "Core/Steps/Step.h"
#include "config.h"
#include "Renderer/Mesh.h"
#include "Renderer/Material.h"

namespace GraphicEngine
{
	class PostProcess : public Step
	{
	public:
		PostProcess();
		~PostProcess();

		void render(entt::registry& registry, Camera* camera, glm::mat4* cameraTransform);

	private:
		Mesh m_PlaneMesh;
		Material m_PlaneMaterial;
	};
}
