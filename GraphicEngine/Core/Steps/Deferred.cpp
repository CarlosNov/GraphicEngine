#include "Deferred.h"
#include <glm/gtc/type_ptr.hpp>


namespace GraphicEngine
{
	Deferred::Deferred() : Step::Step()
	{
		m_GBuffer = new GBuffer();

		shaderLighting = new Shader("Shaders/deferredShading.vert", "Shaders/deferredShading.frag");
	}

	Deferred::~Deferred()
	{

	}

	void Deferred::render(entt::registry& registry, Camera* camera, glm::mat4* cameraTransform)
	{
		std::vector<glm::vec3> lightPositions;
		std::vector<glm::vec3> lightColors;
		lightPositions.push_back(glm::vec3(0.0, 0.0, 5.0));
		lightColors.push_back(glm::vec3(1.0, 1.0, 1.0));

		m_GBuffer->BindBuffer();

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
		
		//Lighting Pass
		_fbo->bindFBO();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		shaderLighting->ActivateProgram();

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, m_GBuffer->GetPositionTex());
		shaderLighting->SetInt("gPosition", 0);
		glActiveTexture(GL_TEXTURE0 + 1);
		glBindTexture(GL_TEXTURE_2D, m_GBuffer->GetNormalTex());
		shaderLighting->SetInt("gNormal",1);
		glActiveTexture(GL_TEXTURE0 + 2);
		glBindTexture(GL_TEXTURE_2D, m_GBuffer->GetAlbedoSpecTex());
		shaderLighting->SetInt("gAlbedoSpec", 2);
		
		for (unsigned int i = 0; i < lightPositions.size(); i++)
		{
			shaderLighting->SetVec3("lights[" + std::to_string(i) + "].Position", lightPositions[i]);
			shaderLighting->SetVec3("lights[" + std::to_string(i) + "].Color", lightColors[i]);
			const float linear = 0.1;
			const float quadratic = 0.01;
			shaderLighting->SetFloat("lights[" + std::to_string(i) + "].Linear", linear);
			shaderLighting->SetFloat("lights[" + std::to_string(i) + "].Quadratic", quadratic);
		}

		float x = cameraTransform[3][0].x;
		float y = cameraTransform[3][1].x;
		float z = cameraTransform[3][2].x;

		glm::vec3 viewPos = glm::vec3(x, y, z);

		shaderLighting->SetVec3("viewPos", viewPos);
		
		unsigned int quadVAO = 0;
		unsigned int quadVBO;

		if (quadVAO == 0)
		{
			float quadVertices[] = {
				// positions        // texture Coords
				-1.0f,  1.0f, 0.0f, 0.0f, 1.0f,
				-1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
				 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,
				 1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
			};
			// setup plane VAO
			glGenVertexArrays(1, &quadVAO);
			glGenBuffers(1, &quadVBO);
			glBindVertexArray(quadVAO);
			glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
		}
		glBindVertexArray(quadVAO);
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
		glBindVertexArray(0);
		
		glBindFramebuffer(GL_FRAMEBUFFER, 0);	
	}

	void Deferred::resizeFBO(int width, int height)
	{
		_fbo->resizeFBO(width, height);
		m_GBuffer->ResizeBuffer(width, height);
	}
}
