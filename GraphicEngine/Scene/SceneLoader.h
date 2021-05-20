#pragma once

#include "Scene.h"

namespace GraphicEngine 
{

	class SceneLoader
	{
	public:
		SceneLoader(Scene* scene);

		void Save(const std::string& filepath);
		bool Load(const std::string& filepath);
		
	private:
		Scene* m_Scene;
	};

}