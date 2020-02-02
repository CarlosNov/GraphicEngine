#pragma once

#include "Core/Steps/Step.h"

namespace GraphicEngine
{
	class PostProcess : public Step
	{
	public:
		PostProcess();
		~PostProcess();

		void render(std::vector<geInterface*> toRenderNodes, Camera* camera);

	private:
		geInterface* _plane;
	};
}
