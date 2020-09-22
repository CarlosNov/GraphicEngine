#include "Steps/QTCopy.h"
#include "Scene/geNode.h"
#include "Scene/Visitor/AddTextureVisitor.h"
#include "Scene/Visitor/ActiveProgramVisitor.h"
#include "Scene/Visitor/ActiveTexturesVisitor.h"
#include "Scene/Visitor/SetModelViewMatrixVisitor.h"
#include "Scene/Visitor/SetModelViewProjectionMatrixVisitor.h"
#include "Scene/Visitor/SetNormalMatrixVisitor.h"
#include <QtGui\qopenglfunctions.h>

App::QTCopy::QTCopy() : GraphicEngine::Step::Step()
{
	/*
	_plane = new GraphicEngine::gePlane("Plane");

	_plane->setProgramShaders("../GraphicEngine/Shaders/postProcessing.v1.vert", "../GraphicEngine/Shaders/postProcessing.v1.frag");
	*/
}

App::QTCopy::~QTCopy()
{

}

void App::QTCopy::render(std::map< int, GraphicEngine::geNode* > geNodes, GraphicEngine::PerspectiveCamera* camera)
{
	/*
	QOpenGLFunctions* qf = new QOpenGLFunctions;
	if (qf)
	{
		qf->initializeOpenGLFunctions();
		qf->glBindFramebuffer(GL_FRAMEBUFFER, 0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	GraphicEngine::AddTextureVisitor* addColorTextureV = new GraphicEngine::AddTextureVisitor;
	addColorTextureV->setTexture(new GraphicEngine::Texture(_fbo->getColorBuffer(), GraphicEngine::Texture::TextureType::DIFFUSE));
	_plane->accept(addColorTextureV);
	delete addColorTextureV;

	GraphicEngine::AddTextureVisitor* addVertexTextureV = new GraphicEngine::AddTextureVisitor;
	addVertexTextureV->setTexture(new GraphicEngine::Texture(_fbo->getVertexBuffer(), GraphicEngine::Texture::TextureType::VERTEX));
	_plane->accept(addVertexTextureV);
	delete addVertexTextureV;

	GraphicEngine::ActiveProgramVisitor* activeProgramV = new GraphicEngine::ActiveProgramVisitor;
	_plane->accept(activeProgramV);
	delete activeProgramV;

	GraphicEngine::ActiveTexturesVisitor* activeTexturesV = new GraphicEngine::ActiveTexturesVisitor;
	_plane->accept(activeTexturesV);
	delete activeTexturesV;

	glDisable(GL_CULL_FACE);
	glDisable(GL_DEPTH_TEST);

	glBindVertexArray(_plane->getVAO());

	_plane->setAttributes();

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);

	if(qf)
		qf->glUseProgram(NULL);
	delete qf;
	*/
}