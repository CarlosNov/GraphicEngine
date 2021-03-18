#include "Steps/QTCopy.h"
#include <QtGui\qopenglfunctions.h>

namespace GraphicEngine
{
	QTCopy::QTCopy() : GraphicEngine::Step::Step()
	{
		m_PlaneMesh = Mesh("../Dependencies/models/cube.obj");
		m_PlaneMaterial = Material("Shaders/postProcessing.v1.vert", "Shaders/postProcessing.v1.frag");
	}

	QTCopy::~QTCopy()
	{

	}

	void QTCopy::render(entt::registry& registry, GraphicEngine::Camera* camera, glm::mat4* cameraTransform)
	{
		QOpenGLFunctions* qf = new QOpenGLFunctions;
		if (qf)
		{
			qf->initializeOpenGLFunctions();
			qf->glBindFramebuffer(GL_FRAMEBUFFER, 0);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

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

		if (qf)
			qf->glUseProgram(NULL);
		delete qf;
	}
}
