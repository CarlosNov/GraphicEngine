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

		void setPlane(geInterface* plane);
	private:
		geInterface* _plane;
	};
}
