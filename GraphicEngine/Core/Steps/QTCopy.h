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

		void render(std::map< int, geNode* > geNodes, geCamera* camera);

	private:
		gePlane* _plane;
	};
}
