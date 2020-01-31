#include "PostProcess.h"
#include "Scene/geInterface.h"

GraphicEngine::PostProcess::PostProcess() : GraphicEngine::Step::Step()
{

}

GraphicEngine::PostProcess::~PostProcess()
{

}

void GraphicEngine::PostProcess::render(std::vector<geInterface*> toRenderNodes, Camera* camera)
{
	/*
	for (std::vector<geInterface* >::iterator it = toRenderNodes.begin(); it != toRenderNodes.end(); it++)
	{
		(*it)->render(camera->getViewMatrix(), camera->getProjMatrix());
	}
	*/
}

void GraphicEngine::PostProcess::setPlane(geInterface* plane)
{
	_plane = plane;
}