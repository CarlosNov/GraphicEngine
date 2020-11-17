#include "Forward.h"


namespace GraphicEngine
{
	Forward::Forward() : Step::Step()
	{

	}

	Forward::~Forward()
	{

	}

	void Forward::render(entt::registry& registry, Camera* camera, glm::mat4* cameraTransform)
	{
		_fbo->bindFBO();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glm::mat4 cameraView = glm::inverse(*cameraTransform);

		auto group2 = registry.group<TransformComponent>(entt::get<MeshComponent, MaterialComponent>);
		for (auto entity : group2)
		{
			auto [transform, mesh, material] = group2.get<TransformComponent, MeshComponent, MaterialComponent>(entity);

			glm::mat4 modelViewProj = camera->GetProjectionMatrix() * cameraView * transform.GetTransform();
			glm::mat4 modelView = cameraView * transform.GetTransform();
			glm::mat4 normal = glm::transpose(glm::inverse(modelView));

			material.Material.ActivateProgram();
			material.Material.SetModelViewProjMat(modelViewProj);
			material.Material.SetModelViewMat(modelView);
			material.Material.SetNormalMat(normal);
			material.Material.ActivateTextures();

			mesh.Mesh.Bind();

			material.Material.SetAttributes(mesh.Mesh.GetPosVBO(), mesh.Mesh.GetColorVBO(), mesh.Mesh.GetNormalVBO(), mesh.Mesh.GetTexCoordVBO());

			mesh.Mesh.Bind();
			glDrawElements(GL_TRIANGLES, mesh.Mesh.GetNumTriangleIndex(), GL_UNSIGNED_INT, (void*)0);
		}

		//TO DO: Move to another Step
		glLineWidth(5);
		
		glBegin(GL_LINES);
		glColor3f(0., 0., 1.);
		glVertex3f(0., -1000., 0.);
		glVertex3f(0., 1000., 0.);
		glEnd();

		glBegin(GL_LINES);
		glColor3f(0., 1., 0.);
		glVertex3f(0., 0., -1000.);
		glVertex3f(0., 0., 1000.);
		glEnd();

		glBegin(GL_LINES);
		glColor4f(1.0, 0.0, 0.0, 1.0);
		glVertex3f(-1000., 0., 0.);
		glVertex3f(1000., 0., 0.);
		glEnd();
	}
}
