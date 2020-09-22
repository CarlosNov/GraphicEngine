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

		void render(std::map< int, geNode* > geNodes, PerspectiveCamera* camera);

	private:
		gePlane* _plane;
	};
}
