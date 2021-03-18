#pragma once

#include "Core/Steps/Step.h"
#include "config.h"
#include "Renderer/Mesh.h"
#include "Renderer/Material.h"

namespace GraphicEngine
{
	class QTCopy : public GraphicEngine::Step
	{
	public:
		QTCopy();
		~QTCopy();

		void render(entt::registry& registry, GraphicEngine::Camera* camera, glm::mat4* cameraTransform);

	private:
		Mesh m_PlaneMesh;
		Material m_PlaneMaterial;
	};
}
