#include "geContainer.h"

GraphicEngine::geContainer::geContainer(const char* name) : GraphicEngine::geInterface::geInterface(name)
{
	setName(name);
}

GraphicEngine::geContainer::geContainer(const char* name, Transform transform): GraphicEngine::geInterface::geInterface(name, transform)
{
	setName(name);
	setTransform(transform);
}

GraphicEngine::geContainer::~geContainer()
{
}

void GraphicEngine::geContainer::render()
{

}

bool GraphicEngine::geContainer::getIsRenderable()
{
	return true;
}


