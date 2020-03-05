#include "geNode.h"

GraphicEngine::geNode::geNode(const char* name) : GraphicEngine::geInterface::geInterface(name)
{

}

GraphicEngine::geNode::geNode(const char* name, Transform transform) : GraphicEngine::geInterface::geInterface(name, transform)
{

}

GraphicEngine::geNode::~geNode() 
{

}

void GraphicEngine::geNode::render()
{

}

void GraphicEngine::geNode::update()
{

}

void GraphicEngine::geNode::accept(Visitor* visitor)
{
	
}