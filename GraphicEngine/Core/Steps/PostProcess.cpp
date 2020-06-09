#include "PostProcess.h"
#include "Scene/geNode.h"
#include "Scene/Derived/gePlane.h"
#include "Scene/Visitor/AddTextureVisitor.h"
#include "Scene/Visitor/ActiveProgramVisitor.h"
#include "Scene/Visitor/ActiveTexturesVisitor.h"
#include "Scene/Visitor/SetModelViewMatrixVisitor.h"
#include "Scene/Visitor/SetModelViewProjectionMatrixVisitor.h"
#include "Scene/Visitor/SetNormalMatrixVisitor.h"

GraphicEngine::PostProcess::PostProcess() : GraphicEngine::Step::Step()
{
	_plane = new gePlane("Plane");

	_plane->setProgramShaders("Shaders/postProcessing.v1.vert", "Shaders/postProcessing.v1.frag");
}

GraphicEngine::PostProcess::~PostProcess()
{

}

void GraphicEngine::PostProcess::render(std::map< int, geNode* > geNodes, geCamera* camera)
{
	AddTextureVisitor* addColorTextureV = new AddTextureVisitor;
	addColorTextureV->setTexture(new Texture(_fbo->getColorBuffer(), Texture::TextureType::DIFFUSE));
	_plane->accept(addColorTextureV);
	delete addColorTextureV;

	AddTextureVisitor* addVertexTextureV = new AddTextureVisitor;
	addVertexTextureV->setTexture(new Texture(_fbo->getVertexBuffer(), Texture::TextureType::VERTEX));
	_plane->accept(addVertexTextureV);
	delete addVertexTextureV;

	ActiveProgramVisitor* activeProgramV = new ActiveProgramVisitor;
	_plane->accept(activeProgramV);
	delete activeProgramV;

	ActiveTexturesVisitor* activeTexturesV = new ActiveTexturesVisitor;
	_plane->accept(activeTexturesV);
	delete activeTexturesV;

	glDisable(GL_CULL_FACE);
	glDisable(GL_DEPTH_TEST);

	glBindVertexArray(_plane->getVAO());

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glUseProgram(NULL);
}