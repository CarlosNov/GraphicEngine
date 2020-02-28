#include "geLight.h"

GraphicEngine::geLight::geLight(const char* name) : GraphicEngine::geInterface::geInterface(name)
{
	_aIntensity = glm::vec3(0.3);
	_dIntensity = glm::vec3(1.0);
	_sIntensity = glm::vec3(1.0);
}

GraphicEngine::geLight::geLight(const char* name, Transform transform) : GraphicEngine::geInterface::geInterface(name, transform)
{
	_aIntensity = glm::vec3(0.3);
	_dIntensity = glm::vec3(1.0);
	_sIntensity = glm::vec3(1.0);
}

GraphicEngine::geLight::~geLight()
{

}

void GraphicEngine::geLight::render()
{

}

void GraphicEngine::geLight::update()
{

}

void GraphicEngine::geLight::accept(Visitor* visitor)
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

glm::vec3 GraphicEngine::geLight::getSpecularIntensity()
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
