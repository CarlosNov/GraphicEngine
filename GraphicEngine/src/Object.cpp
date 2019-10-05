#include "Object.h"
#include "ErrorHandling.h"

/***********************************************************************************************/
/*                              CONSTRUCTORS AND DESTRUCTORS                                   */
/***********************************************************************************************/

GraphicEngine::Object::Object(const char* name)
{
	Object::name = name;

	Object::transform.position = glm::vec3(0.0);
	Object::transform.rotation = glm::quat(1.0, 0.0, 0.0, 0.0);
	Object::transform.scale = glm::vec3(1.0);
}

GraphicEngine::Object::Object(const char* name, Transform transform)
{
	Object::name = name;
	Object::transform = transform;
}

GraphicEngine::Object::~Object()
{

}

/***********************************************************************************************/
/*                               GETTERS AND SETTERS										   */
/***********************************************************************************************/

const char* GraphicEngine::Object::getName()
{
	return Object::name;
}

GraphicEngine::Object::Transform GraphicEngine::Object::getTransform()
{
	return Object::transform;
}

glm::vec3 GraphicEngine::Object::getPosition()
{
	return Object::transform.position;
}

glm::quat GraphicEngine::Object::getRotation()
{
	return Object::transform.rotation;
}

glm::vec3 GraphicEngine::Object::getScale()
{
	return Object::transform.scale;
}

void GraphicEngine::Object::setName(const char* name)
{	
	if (name == nullptr)
	{
		throw ENullptrException();
	}

	Object::name = name;
}

void GraphicEngine::Object::setTransform(Transform transform)
{
	Object::transform = transform;
}

void GraphicEngine::Object::setPosition(glm::vec3 position)
{
	Object::transform.position = position;
}

void GraphicEngine::Object::setRotation(glm::quat rotation)
{
	Object::transform.rotation = rotation;
}

void GraphicEngine::Object::setScale(glm::vec3 scale)
{
	Object::transform.scale = scale;
}
