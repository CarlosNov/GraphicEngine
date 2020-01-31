#include <iostream>

#include "Core\Core.h"

int main(int argc, char** argv)
{
	GraphicEngine::Core* core = GraphicEngine::Core::getCore(argc, argv);

	
	core->initContext(argc, argv);	
	core->initOGL();

	GraphicEngine::Camera* mainCamera = new GraphicEngine::Camera;
	core->addCamera(mainCamera);
	GraphicEngine::Light* mainLight = new GraphicEngine::Light;
	core->addLight(mainLight);

	GraphicEngine::geBasic* geCube = GraphicEngine::geBasic::geBasicCube("Cube");
	core->addNode(geCube);

	core->mainLoop();
}