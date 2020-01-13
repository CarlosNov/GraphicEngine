#include "geNodeContainer.h"

GraphicEngine::geNodeContainer::geNodeContainer(const char* name, int id) : GraphicEngine::geNode::geNode(name, id)
{
	setName(name);
	setId(id);
}

GraphicEngine::geNodeContainer::geNodeContainer(const char* name, int id, Transform transform): GraphicEngine::geNode::geNode(name, id, transform)
{
	setName(name);
	setId(id);
	setTransform(transform);
}

GraphicEngine::geNodeContainer::~geNodeContainer()
{
}

void GraphicEngine::geNodeContainer::initObject()
{

}

void GraphicEngine::geNodeContainer::renderObject()
{

}

void GraphicEngine::geNodeContainer::destroyObject()
{

}

