#pragma once

#include "config.h"

namespace GraphicEngine {

	class Light
	{
	public:
		Light();
		~Light();

		glm::vec3 Ia;
		glm::vec3 Id;
		glm::vec3 Is;
		glm::vec3 lpos;
	};
}

