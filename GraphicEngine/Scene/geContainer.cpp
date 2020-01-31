#include "geContainer.h"

GraphicEngine::geContainer::geContainer(const char* name) : GraphicEngine::geInterface::geInterface(name)
{
	_geNodes.clear();
}

GraphicEngine::geContainer::geContainer(const char* name, Transform transform): GraphicEngine::geInterface::geInterface(name, transform)
{
	_geNodes.clear();
}

GraphicEngine::geContainer::~geContainer()
{
	
}

bool GraphicEngine::geContainer::addNode(geInterface* geInterface)
{
	_geNodes[geInterface->getId()] =  geInterface;

	return true;
}

bool GraphicEngine::geContainer::removeNode(geInterface* geInterface)
{
	_geNodes.erase(geInterface->getId());

	return true;
}

std::map<int, GraphicEngine::geInterface*> GraphicEngine::geContainer::getNodeMap()
{
	return _geNodes;
}

void GraphicEngine::geContainer::update()
{

}



