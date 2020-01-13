#include <iostream>
#include "Core\Core.h"

int main(int argc, char** argv)
{
	std::locale::global(std::locale("spanish"));

	GraphicEngine::Core core = GraphicEngine::Core::Core();

	core.initContext(argc, argv);
	core.initOGL();

	GraphicEngine::Camera* mainCamera = new GraphicEngine::Camera;
	core.addCamera(mainCamera);

	core.mainLoop();
}