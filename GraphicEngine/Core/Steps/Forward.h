#pragma once

#include "Core/Steps/Step.h"
#include "entt.hpp"

namespace GraphicEngine
{
	class Forward : public Step
	{
	public:
		Forward();
		~Forward();

		void render(entt::registry& registry, Camera* camera, glm::mat4* cameraTransform);

	};
}

