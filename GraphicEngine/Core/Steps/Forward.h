#pragma once

#include "Core/Steps/Step.h"

namespace GraphicEngine
{
	class Forward : public Step
	{
	public:
		Forward();
		~Forward();

		void render(std::vector<geInterface*> toRenderNodes, Camera* camera);
	};
}
