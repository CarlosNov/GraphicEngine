#pragma once

#include "Core/Steps/Step.h"

namespace GraphicEngine
{
	class Forward : public Step
	{
	public:
		Forward();
		~Forward();

		void render(geContainer* geContainer, Camera* camera);

	private:
		void setRender(Camera* camera);
	};
}

