#include <iostream>
#include "Core\Core.h"

int main(int argc, char** argv)
{
	std::locale::global(std::locale("spanish"));

	GraphicEngine::Core core = GraphicEngine::Core::Core();

	core.initContext(argc, argv);

	std::cin.get();
}