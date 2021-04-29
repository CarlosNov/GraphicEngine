#include "application.h"

int main(void)
{
	auto Application = std::make_unique<GraphicEngine::Application>("Educational Graphic Engine");
	Application->Run();
	return 0;
}