#include "PostProcess.h"

namespace GraphicEngine
{
	PostProcess::PostProcess() : GraphicEngine::Step::Step()
	{
		m_PlaneMesh = Mesh("../Dependencies/models/cube.obj");
		m_PlaneMaterial = Material("shaders/postProcessing.v1.vert", "shaders/postProcessing.v1.frag");
	}

	PostProcess::~PostProcess()
	{

	}

	void PostProcess::render(entt::registry& registry, Camera* camera, glm::mat4* cameraTransform)
	{
		_fbo->bindFBO();

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
}
