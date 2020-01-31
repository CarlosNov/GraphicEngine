#include "Forward.h"
#include "Scene/geInterface.h"

GraphicEngine::Forward::Forward() : GraphicEngine::Step::Step()
{

}

GraphicEngine::Forward::~Forward()
{

}

void GraphicEngine::Forward::render(Renderer* renderer)
{
	for (std::vector<geInterface*>::iterator it = renderer->getRenderNodes().begin(); it != renderer->getRenderNodes().end(); it++)
	{
		(*it)->getRenderable()->render(*renderer);
	}
}
