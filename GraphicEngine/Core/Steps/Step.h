#pragma once

#include "config.h"
#include "Core/FBO.h"
#include "Scene/geInterface.h"
#include "Scene/Camera.h"

namespace GraphicEngine
{
	class Step
	{
	public:
		Step();
		~Step();
		
		virtual void render(std::vector<geInterface*> toRenderNodes, Camera* camera) = 0;

	protected:
		FBO _fbo;
	};
}

