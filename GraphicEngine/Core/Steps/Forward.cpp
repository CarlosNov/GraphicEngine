#include "Forward.h"

GraphicEngine::Forward::Forward() : GraphicEngine::Step::Step()
{

}

GraphicEngine::Forward::~Forward()
{

}

void GraphicEngine::Forward::render(std::vector<geInterface*> toRenderNodes, Camera* camera)
{
	for (std::vector<geInterface* >::iterator it = toRenderNodes.begin(); it != toRenderNodes.end(); it++)
	{
		(*it)->render(camera->getViewMatrix(), camera->getProjMatrix());
	}
}
