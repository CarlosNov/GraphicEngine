#include "Forward.h"
#include "Scene/Visitor/ActiveProgramVisitor.h"
#include "Scene/Visitor/ActiveTexturesVisitor.h"
#include "Scene/Visitor/SetModelViewMatrixVisitor.h"
#include "Scene/Visitor/SetModelViewProjectionMatrixVisitor.h"
#include "Scene/Visitor/SetNormalMatrixVisitor.h"

GraphicEngine::Forward::Forward() : GraphicEngine::Step::Step()
{

}

GraphicEngine::Forward::~Forward()
{

}

void GraphicEngine::Forward::render(std::vector<geInterface*> toRenderNodes, Camera* camera)
{
    _fbo->bindFBO();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (std::vector<geInterface* >::iterator it = toRenderNodes.begin(); it != toRenderNodes.end(); it++)
	{
		ActiveProgramVisitor* activeProgramV = new ActiveProgramVisitor;
		(*it)->accept(activeProgramV);
		delete activeProgramV;

		SetModelViewMatrixVisitor* setMVMatrixV = new SetModelViewMatrixVisitor;
		setMVMatrixV->setView(camera->getViewMatrix());
		(*it)->accept(setMVMatrixV);
		delete setMVMatrixV;

		SetModelViewProjectionMatrixVisitor* setMVPMatrixV = new SetModelViewProjectionMatrixVisitor;
		setMVPMatrixV->setView(camera->getViewMatrix());
		setMVPMatrixV->setProj(camera->getProjMatrix());
		(*it)->accept(setMVPMatrixV);
		delete setMVPMatrixV;

		SetNormalMatrixVisitor* setNMatrixV = new SetNormalMatrixVisitor;
		setNMatrixV->setView(camera->getViewMatrix());
		(*it)->accept(setNMatrixV);
		delete setNMatrixV;

		ActiveTexturesVisitor* activeTexturesV = new ActiveTexturesVisitor;
		(*it)->accept(activeTexturesV);
		delete activeTexturesV;

		(*it)->render();
	}
}
