#pragma once

#include "Core/Steps/Program.h"
#include "Core/Steps/Step.h"
#include "Scene/Camera.h"

namespace GraphicEngine
{
    class Step;
    class geInterface;

	class Renderer
	{
    public:

        void renderNodes();

        void addNode(geInterface* geInterface);
        void addStep(Step*step);
        void addCamera(Camera* camera);

        Camera* getCamera();

        std::vector<geInterface*> getRenderNodes();

    protected:
        Program* _activeProgram;
        Camera* _mainCamera;
        std::vector<Step*> _steps;
        std::vector<geInterface*> _toRenderNodes;
	};
}