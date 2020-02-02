#pragma once

#include "Core/Steps/Step.h"
#include "config.h"

namespace GraphicEngine
{
	class gePlane;
	class PostProcess : public Step
	{
	public:
		PostProcess();
		~PostProcess();

		void render(std::vector<geInterface*> toRenderNodes, Camera* camera);

	private:
		gePlane* _plane;
	};
}
