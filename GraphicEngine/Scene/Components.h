#pragma once

#include <glm.hpp>
#include "config.h"

#include "Renderer/Mesh.h"
#include "Renderer/Material.h"
#include "Scene/PerspectiveCamera.h"

namespace GraphicEngine
{
	struct TransformComponent
	{
		glm::mat4 Transform{ 1.0f };

		TransformComponent() = default;
		TransformComponent(const TransformComponent&) = default;
		TransformComponent(const glm::mat4& transform)
		{
			Transform = transform;
		}

		operator glm::mat4& () { return Transform; }
		operator const glm::mat4& () const { return Transform; }
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
		PerspectiveCamera Camera;
		bool MainCamera = true;

		CameraComponent() = default;
		CameraComponent(const CameraComponent&) = default;
	};
}
