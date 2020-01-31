#pragma once

#include "config.h"
#include "Core/Render/Renderer.h"
#include "Core/FBO.h"

namespace GraphicEngine
{
	class Renderer;
	class Step
	{
	public:
		Step() {}
		~Step() {}
		
		virtual void render(Renderer* renderer) = 0;

		Program getProgram() { return _program; }

	protected:
		FBO _fbo;
		Program _program;
	};
}

