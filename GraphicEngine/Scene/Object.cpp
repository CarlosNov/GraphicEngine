#include "Scene\Object.h"
#include "Auxiliar\ErrorHandling.h"

/***********************************************************************************************/
/*                              CONSTRUCTORS AND DESTRUCTORS                                   */
/***********************************************************************************************/

GraphicEngine::Object::Object(const char* name, int id)
{
	Object::name = name;
	Object::id = id;

	Object::transform.position = glm::vec3(0.0);
	Object::transform.rotation = glm::quat(1.0, 0.0, 0.0, 0.0);
	Object::transform.scale = glm::vec3(1.0);
}

GraphicEngine::Object::Object(const char* name, int id, Transform transform)
{
	Object::name = name;
	Object::id = id;

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

int GraphicEngine::Object::getId()
{
	return Object::id;
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

void GraphicEngine::Object::setId(int id)
{
	Object::id = id;
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
