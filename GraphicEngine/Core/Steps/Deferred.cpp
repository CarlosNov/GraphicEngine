#include "Deferred.h"
#include <glm/gtc/type_ptr.hpp>


namespace GraphicEngine
{
	Deferred::Deferred() : Step::Step()
	{
		m_GBuffer = new GBuffer();

		m_PlaneMesh = Mesh("../Dependencies/models/cube.obj");
		m_PlaneMaterial = Material("Shaders/deferredShading.vert", "Shaders/deferredShading.frag");
		shaderLighting = new Shader("Shaders/deferredShading.vert", "Shaders/deferredShading.frag");
	}

	Deferred::~Deferred()
	{

	}

	void Deferred::render(entt::registry& registry, Camera* camera, glm::mat4* cameraTransform)
	{
		std::vector<glm::vec3> PointPositions;
		std::vector<glm::vec3> PointColors;
		std::vector<float> PointLinear;
		std::vector<float> PointQuadratic;

		std::vector<glm::vec3> DirectionalColors;
		std::vector<glm::vec3> DirectionalDirections;

		auto view = registry.view<TransformComponent, LightComponent>();
		for (auto entity : view)
		{
			auto [transform, light] = view.get<TransformComponent, LightComponent>(entity);

			if (light.Light.GetLightType() == SceneLight::LightType::Point)
			{
				PointPositions.push_back(transform.Translation);
				glm::vec4 color = light.Light.GetColor();
				PointColors.push_back(glm::vec3(color.x / 255, color.y / 255, color.z / 255));
				PointLinear.push_back(light.Light.GetPointLinear());
				PointQuadratic.push_back(light.Light.GetPointQuadratic());
			}	
			else
			{
				glm::vec4 color = light.Light.GetColor();
				DirectionalColors.push_back(glm::vec3(color.x / 255, color.y / 255, color.z / 255));
				glm::vec3 direction = light.Light.GetDirection();
				DirectionalDirections.push_back(glm::vec3(direction.x, direction.y, direction.z));
			}
		}

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
		
		for (unsigned int i = 0; i < PointColors.size(); i++)
		{
			shaderLighting->SetVec3("PointLights[" + std::to_string(i) + "].Position", PointPositions[i]);
			shaderLighting->SetVec3("PointLights[" + std::to_string(i) + "].Color", PointColors[i]);
			shaderLighting->SetFloat("PointLights[" + std::to_string(i) + "].Linear", PointLinear[i]);
			shaderLighting->SetFloat("PointLights[" + std::to_string(i) + "].Quadratic", PointQuadratic[i]);
		}

		for (unsigned int i = 0; i < DirectionalColors.size(); i++)
		{
			shaderLighting->SetVec3("DirectionalLights[" + std::to_string(i) + "].Color", DirectionalColors[i]);
			shaderLighting->SetVec3("DirectionalLights[" + std::to_string(i) + "].Direction", DirectionalDirections[i]);
		}
		
		float x = cameraTransform[3][0].x;
		float y = cameraTransform[3][1].x;
		float z = cameraTransform[3][2].x;

		glm::vec3 viewPos = glm::vec3(x, y, z);

		shaderLighting->SetVec3("viewPos", viewPos);
		
		/*
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
		*/

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
