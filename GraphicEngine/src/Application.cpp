#include <iostream>
#include "Core.h"

int main()
{
	GraphicEngine::Object obj = GraphicEngine::Object::Object("Objeto");

	GraphicEngine::Object::Transform t;
	t.position = glm::vec3(10, 10, 10);
	obj.setPosition(t.position);

	std::cout << t.position.x;

	std::cin.get();
}