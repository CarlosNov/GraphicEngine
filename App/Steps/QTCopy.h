#pragma once

#include "Core/Steps/Step.h"
#include "Scene/Derived/gePlane.h"
#include "config.h"

namespace App
{
	class QTCopy : public GraphicEngine::Step
	{
	public:
		QTCopy();
		~QTCopy();

		void render(entt::registry& registry, GraphicEngine::Camera* camera, glm::mat4* cameraTransform);

	private:
		GraphicEngine::gePlane* _plane;
	};
}
