
#include "geInterface.h"
#include "Auxiliar/ErrorHandling.h"

/***********************************************************************************************/
/*                              CONSTRUCTORS AND DESTRUCTORS                                   */
/***********************************************************************************************/

GraphicEngine::geInterface::geInterface(const char* name)
{
	_name = name;

	_transform.position = glm::vec3(0.0);
	_transform.rotation = glm::vec3(0.0);
	_transform.scale = glm::vec3(1.0);
	_isActive = TRUE;
}

GraphicEngine::geInterface::geInterface(const char* name, Transform transform)
{
	_name = name;

	_transform = transform;
}

GraphicEngine::geInterface::~geInterface()
{

}

/***********************************************************************************************/
/*                               GETTERS AND SETTERS										   */
/***********************************************************************************************/

const char* GraphicEngine::geInterface::getName()
{
	return _name;
}

int GraphicEngine::geInterface::getId()
{
	return _id;
}

GraphicEngine::geInterface::Transform GraphicEngine::geInterface::getTransform()
{
	return _transform;
}

glm::vec3 GraphicEngine::geInterface::getPosition()
{
	return _transform.position;
}

glm::vec3 GraphicEngine::geInterface::getRotation()
{
	return _transform.rotation;
}

glm::vec3 GraphicEngine::geInterface::getScale()
{
	return _transform.scale;
}

void GraphicEngine::geInterface::setName(const char* name)
{	
	if (name == nullptr)
	{
		throw ENullptrException();
	}

	_name = name;
}

void GraphicEngine::geInterface::setId(int id)
{
	_id = id;
}

void GraphicEngine::geInterface::setTransform(Transform transform)
{
	_transform = transform;
}

void GraphicEngine::geInterface::setPosition(glm::vec3 position)
{
	_transform.position = position;
}

void GraphicEngine::geInterface::setRotation(glm::vec3 rotation)
{
	_transform.rotation = rotation;
}

void GraphicEngine::geInterface::setScale(glm::vec3 scale)
{
	_transform.scale = scale;
}

void GraphicEngine::geInterface::setForward(Forward* forward)
{
	_forward = forward;
}