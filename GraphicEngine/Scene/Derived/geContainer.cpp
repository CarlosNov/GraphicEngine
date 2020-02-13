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
	for (std::vector< geInterface* >::iterator it = _toRenderList.begin(); it != _toRenderList.end(); it++)
	{
		node = (*it);

		node->render();
	}
}

void GraphicEngine::geContainer::update()
{
	_toRenderList.clear();
	geInterface* node;

	for (std::map< int, geInterface* >::iterator it = _geNodeList.begin(); it != _geNodeList.end(); it++)
	{
		node = it->second;

		if (node->isActive())
		{
			node->update();

			if (node->isRenderable())
			{
				_toRenderList.push_back(node);
			}
		}
	}
}

bool GraphicEngine::geContainer::isRenderable()
{
	return !_toRenderList.empty();
}


