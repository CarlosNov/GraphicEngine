#pragma once

#include "Core/Steps/Step.h"
#include "config.h"

namespace GraphicEngine
{
	class gePlane;
	class QTCopy : public Step
	{
	public:
		QTCopy();
		~QTCopy();

		void render(std::vector<geInterface*> toRenderNodes, Camera* camera);

	private:
		gePlane* _plane;
	};
}
