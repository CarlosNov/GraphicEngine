#pragma once

#include "Core\FBO.h"

namespace GraphicEngine
{
	class Step
	{
	public:
		Step();
		~Step();
		
		virtual void render() = 0;
		virtual void update() = 0;

	protected:
		FBO _fbo;
	};
}

