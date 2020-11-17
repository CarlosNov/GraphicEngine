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
	m_PlaneMesh = Mesh("../Dependencies/models/cube.obj");
	m_PlaneMaterial = Material("Shaders/postProcessing.v1.vert", "Shaders/postProcessing.v1.frag");
}

GraphicEngine::PostProcess::~PostProcess()
{

}

void GraphicEngine::PostProcess::render(entt::registry& registry, Camera* camera, glm::mat4* cameraTransform)
{
	glBindFramebuffer(GL_FRAMEBUFFER, 4);

	m_PlaneMaterial.AddTexture(new Texture(_fbo->getColorBuffer(), Texture::TextureType::DIFFUSE));
	m_PlaneMaterial.AddTexture(new Texture(_fbo->getVertexBuffer(), Texture::TextureType::VERTEX));
	m_PlaneMaterial.ActivateProgram();
	m_PlaneMesh.Bind();
	m_PlaneMaterial.ActivateTextures();

	glDisable(GL_CULL_FACE);
	glDisable(GL_DEPTH_TEST);

	m_PlaneMaterial.SetAttributes(m_PlaneMesh.GetPosVBO(), m_PlaneMesh.GetColorVBO(), m_PlaneMesh.GetNormalVBO(), m_PlaneMesh.GetTexCoordVBO());

	m_PlaneMesh.Bind();
	glDrawElements(GL_TRIANGLES, m_PlaneMesh.GetNumTriangleIndex(), GL_UNSIGNED_INT, (void*)0);

	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glUseProgram(NULL);
}