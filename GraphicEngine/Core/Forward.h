#pragma once

#include "Core/Step.h"
#include "Scene/Camera.h"
#include "Scene/geInterface.h"

namespace GraphicEngine
{
	class geInterface;
	class Camera;

	class Forward : public Step
	{
	public:
		Forward();
		Forward(Camera* camera, std::map<int, geInterface*>* map);
		~Forward();

		void render();
		void update();

		void setVariables(Camera* camera, std::map<int, geInterface*>* map);
		void addToRender(geInterface* geNode);

	private:
		std::map<int, geInterface*>* _geNodes;
		std::vector<geInterface*> _toRenderNodes;
		Camera* _renderCamera;
	};
}

