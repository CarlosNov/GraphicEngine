#include <iostream>

#include "Core\Core.h"

int main(int argc, char** argv)
{
	GraphicEngine::Core* core = GraphicEngine::Core::getCore(argc, argv);

	
	core->initContext(argc, argv);	
	core->initOGL();

	GraphicEngine::Forward* forward = new GraphicEngine::Forward();
	core->addStep(forward);

	GraphicEngine::PostProcess* postProcess = new GraphicEngine::PostProcess();
	core->addStep(postProcess);

	GraphicEngine::Camera* mainCamera = new GraphicEngine::Camera();
	core->addCamera(mainCamera); 
	GraphicEngine::Light* mainLight = new GraphicEngine::Light();
	core->addLight(mainLight);

	GraphicEngine::geCube* geCube = new GraphicEngine::geCube("Cube");
	core->addNode(geCube);

	core->mainLoop();
}