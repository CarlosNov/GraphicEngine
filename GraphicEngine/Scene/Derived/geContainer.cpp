#include "geContainer.h"

GraphicEngine::geContainer::geContainer(const char* name) : GraphicEngine::geInterface::geInterface(name)
{
}

GraphicEngine::geContainer::geContainer(const char* name, Transform transform): GraphicEngine::geInterface::geInterface(name, transform)
{
}

GraphicEngine::geContainer::~geContainer()
{
}

void GraphicEngine::geContainer::render()
{
	geInterface* node;
	for (std::map<int, geInterface* >::iterator it = _children.begin(); it != _children.end(); it++)
	{
		node = it->second;

		node->render();
	}
}

void GraphicEngine::geContainer::update()
{
	geInterface* node;

	for (std::map< int, geInterface* >::iterator it = _children.begin(); it != _children.end(); it++)
	{
		node = it->second;

		if (node->isActive())
		{
			node->update();
		}
	}
}

GraphicEngine::geInterface::geType GraphicEngine::geContainer::getType()
{
	return geType::geContainer;
}

std::vector<GraphicEngine::geInterface*> GraphicEngine::geContainer::getChildren()
{
	std::vector<geInterface*> vector;
	for (std::map< int, geInterface* >::iterator it = _children.begin(); it != _children.end(); it++)
	{
		vector.push_back(it->second);
	}
	return vector;
}

bool GraphicEngine::geContainer::add(GraphicEngine::geInterface* node)
{
	_children[node->getId()] = node;
	return true;
}

bool GraphicEngine::geContainer::remove(GraphicEngine::geInterface* node)
{
	delete _children[node->getId()];
	_children[node->getId()] = nullptr;
	return true;
}