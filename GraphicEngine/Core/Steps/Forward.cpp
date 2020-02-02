#include "Forward.h"

GraphicEngine::Forward::Forward() : GraphicEngine::Step::Step()
{

}

GraphicEngine::Forward::~Forward()
{

}

void GraphicEngine::Forward::render(std::vector<geInterface*> toRenderNodes, Camera* camera)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//_fbo.bindFBO();

	for (std::vector<geInterface* >::iterator it = toRenderNodes.begin(); it != toRenderNodes.end(); it++)
	{
		(*it)->setMatrix(camera->getViewMatrix(), camera->getProjMatrix());
		(*it)->render();
	}
}
