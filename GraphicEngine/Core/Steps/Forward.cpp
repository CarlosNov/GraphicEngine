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

void GraphicEngine::Forward::render(std::map< int, geNode* > geNodes, geCamera* camera)
{
    _fbo->bindFBO();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (std::map<int, geNode* >::iterator it = geNodes.begin(); it != geNodes.end(); it++)
	{
		ActiveProgramVisitor* activeProgramV = new ActiveProgramVisitor;
		it->second->accept(activeProgramV);
		delete activeProgramV;

		SetModelViewMatrixVisitor* setMVMatrixV = new SetModelViewMatrixVisitor;
		setMVMatrixV->setView(camera->getViewMatrix());
		it->second->accept(setMVMatrixV);
		delete setMVMatrixV;

		SetModelViewProjectionMatrixVisitor* setMVPMatrixV = new SetModelViewProjectionMatrixVisitor;
		setMVPMatrixV->setView(camera->getViewMatrix());
		setMVPMatrixV->setProj(camera->getProjMatrix());
		it->second->accept(setMVPMatrixV);
		delete setMVPMatrixV;

		SetNormalMatrixVisitor* setNMatrixV = new SetNormalMatrixVisitor;
		setNMatrixV->setView(camera->getViewMatrix());
		it->second->accept(setNMatrixV);
		delete setNMatrixV;

		ActiveTexturesVisitor* activeTexturesV = new ActiveTexturesVisitor;
		it->second->accept(activeTexturesV);
		delete activeTexturesV;

		it->second->render();
	}
}

void GraphicEngine::Forward::setRender(geCamera* camera)
{

}
