#include "geLight.h"

GraphicEngine::geLight::geLight()
{
	Ia = glm::vec3(0.3);
	Id = glm::vec3(1.0);
	Is = glm::vec3(1.0);
}


GraphicEngine::geLight::~geLight()
{

}

glm::vec3 GraphicEngine::geLight::getAmbientIntensity()
{
	return _aIntensity;
}

glm::vec3 GraphicEngine::geLight::getDiffuseIntensity()
{
	return _dIntensity;
}

GraphicEngine::geLight::glm::vec3 getSpecularIntensity()
{
	return _sIntensity;
}

void GraphicEngine::geLight::setAmbientIntensity(glm::vec3 aIntensity)
{
	_aIntensity = aIntensity;
}

void GraphicEngine::geLight::setDiffuseIntensity(glm::vec3 dIntensity)
{
	_dIntensity = dIntensity;
}

void GraphicEngine::geLight::setSpecularIntensity(glm::vec3 sIntensity)
{
	_sIntensity = sIntensity;
}
