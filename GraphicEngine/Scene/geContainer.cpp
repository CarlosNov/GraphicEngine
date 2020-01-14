#include "Core\Core.h"

GraphicEngine::geContainer::geContainer(const char* name, int id) : GraphicEngine::geInterface::geInterface(name, id)
{
	setName(name);
	setId(id);
}

GraphicEngine::geContainer::geContainer(const char* name, int id, Transform transform): GraphicEngine::geInterface::geInterface(name, id, transform)
{
	setName(name);
	setId(id);
	setTransform(transform);
}

GraphicEngine::geContainer::~geContainer()
{
}

void GraphicEngine::geContainer::init()
{

}

void GraphicEngine::geContainer::render()
{

}

void GraphicEngine::geContainer::destroy()
{

}

