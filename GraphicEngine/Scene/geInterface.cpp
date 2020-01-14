
#include "Core\Core.h"

/***********************************************************************************************/
/*                              CONSTRUCTORS AND DESTRUCTORS                                   */
/***********************************************************************************************/

GraphicEngine::geInterface::geInterface(const char* name, int id)
{
	geInterface::name = name;
	geInterface::id = id;

	geInterface::transform.position = glm::vec3(0.0);
	geInterface::transform.rotation = glm::vec3(0.0);
	geInterface::transform.scale = glm::vec3(1.0);
}

GraphicEngine::geInterface::geInterface(const char* name, int id, Transform transform)
{
	geInterface::name = name;
	geInterface::id = id;

	geInterface::transform = transform;
}

GraphicEngine::geInterface::~geInterface()
{

}

/***********************************************************************************************/
/*                               GETTERS AND SETTERS										   */
/***********************************************************************************************/

const char* GraphicEngine::geInterface::getName()
{
	return geInterface::name;
}

int GraphicEngine::geInterface::getId()
{
	return geInterface::id;
}

GraphicEngine::geInterface::Transform GraphicEngine::geInterface::getTransform()
{
	return geInterface::transform;
}

glm::vec3 GraphicEngine::geInterface::getPosition()
{
	return geInterface::transform.position;
}

glm::vec3 GraphicEngine::geInterface::getRotation()
{
	return geInterface::transform.rotation;
}

glm::vec3 GraphicEngine::geInterface::getScale()
{
	return geInterface::transform.scale;
}

void GraphicEngine::geInterface::setName(const char* name)
{	
	if (name == nullptr)
	{
		throw ENullptrException();
	}

	geInterface::name = name;
}

void GraphicEngine::geInterface::setId(int id)
{
	geInterface::id = id;
}

void GraphicEngine::geInterface::setTransform(Transform transform)
{
	geInterface::transform = transform;
}

void GraphicEngine::geInterface::setPosition(glm::vec3 position)
{
	geInterface::transform.position = position;
}

void GraphicEngine::geInterface::setRotation(glm::vec3 rotation)
{
	geInterface::transform.rotation = rotation;
}

void GraphicEngine::geInterface::setScale(glm::vec3 scale)
{
	geInterface::transform.scale = scale;
}
