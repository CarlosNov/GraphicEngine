#include "Light.h"

GraphicEngine::Light::Light()
{
	Ia = glm::vec3(0.3);
	Id = glm::vec3(1.0);
	Is = glm::vec3(1.0);
	lpos = glm::vec3(0.0, 1.0, 1.0);
}


GraphicEngine::Light::~Light()
{
}
