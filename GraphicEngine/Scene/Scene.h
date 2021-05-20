#pragma once

#include <ENTT/entt.hpp>
#include "config.h"

namespace GraphicEngine
{
	class Entity;
	class Renderer;
	class SceneLoader;

	class Scene
	{
	public:
		Scene();
		Scene(const std::string& sceneName);
		~Scene();

		Entity CreateEntity(const std::string& name);
		void DestroyEntity(Entity entity);

		void OnUpdate();
		void OnRender();

		void OnViewResize(uint32_t width, uint32_t height);

		Renderer* GetRenderer() { return m_Renderer; };
		uint32_t GetViewWidth();
		uint32_t GetViewHeight();
		GLuint GetCameraTexture();

	private:
		std::string m_SceneName;
		entt::registry m_Registry;
		Renderer* m_Renderer;
		
		friend class Entity;
		friend class Renderer;
		friend class SceneLoader;
		friend class HierarchyWindow;
	};
}