#pragma once

#include "Core/Steps/Step.h"
#include "Scene/Derived/gePlane.h"
#include "config.h"

namespace App
{
	class QTCopy : public GraphicEngine::Step
	{
	public:
		QTCopy();
		~QTCopy();

		void render(std::map< int, GraphicEngine::geNode* > geNodes, GraphicEngine::geCamera* camera);
	private:
		GraphicEngine::gePlane* _plane;
	};
}
