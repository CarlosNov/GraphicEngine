#pragma once

#include "Core/Steps/Step.h"

namespace GraphicEngine
{
	class Forward : public Step
	{
	public:
		Forward();
		~Forward();

		void render(std::map< int, geNode* > geNodes, geCamera* camera);

	private:
		void setRender(geCamera* camera);
	};
}

