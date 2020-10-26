#pragma once

#include <glm.hpp>
#include "config.h"

#include "Renderer/Mesh.h"
#include "Renderer/Material.h"
#include "Scene/SceneCamera.h"

namespace GraphicEngine
{
	struct TransformComponent
	{
		glm::vec3 Translation = { 0.0f, 0.0f, 0.0f };
		glm::vec3 Rotation = { 0.0f, 0.0f, 0.0f };
		glm::vec3 Scale = { 1.0f, 1.0f, 1.0f };

		TransformComponent() = default;
		TransformComponent(const TransformComponent&) = default;
		TransformComponent(const glm::vec3& position)
		{
			Translation = position;
		}

		glm::mat4 GetTransform() const
		{
			glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), Rotation.x, { 1, 0, 0 })
									 * glm::rotate(glm::mat4(1.0f), Rotation.y, { 0, 1, 0 })
									 * glm::rotate(glm::mat4(1.0f), Rotation.z, { 0, 0, 1 });

			return glm::translate(glm::mat4(1.0f), Translation) * rotationMatrix * glm::scale(glm::mat4(1.0f), Scale);
		}
	};

	struct TagComponent
	{
		std::string Tag;

		TagComponent() = default;
		TagComponent(const TagComponent&) = default;
		TagComponent(const std::string& tag)
		{
			Tag = tag;
		}
	};

	struct MeshComponent
	{
		Mesh Mesh;
		std::string FileName;

		MeshComponent() = default;
		MeshComponent(const MeshComponent&) = default;
	};

	struct MaterialComponent
	{
		Material Material;

		MaterialComponent() = default;
		MaterialComponent(const MaterialComponent&) = default;
	};

	struct CameraComponent
	{
		SceneCamera Camera;
		bool MainCamera = false;

		CameraComponent() = default;
		CameraComponent(const CameraComponent&) = default;
	};
}
