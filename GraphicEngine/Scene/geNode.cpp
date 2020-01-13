#include "Scene\geNode.h"
#include "Auxiliar\ErrorHandling.h"

/***********************************************************************************************/
/*                              CONSTRUCTORS AND DESTRUCTORS                                   */
/***********************************************************************************************/

GraphicEngine::geNode::geNode(const char* name, int id)
{
	geNode::name = name;
	geNode::id = id;

	geNode::transform.position = glm::vec3(0.0);
	geNode::transform.rotation = glm::quat(1.0, 0.0, 0.0, 0.0);
	geNode::transform.scale = glm::vec3(1.0);
}

GraphicEngine::geNode::geNode(const char* name, int id, Transform transform)
{
	geNode::name = name;
	geNode::id = id;

	geNode::transform = transform;
}

GraphicEngine::geNode::~geNode()
{

}

/***********************************************************************************************/
/*                               GETTERS AND SETTERS										   */
/***********************************************************************************************/

const char* GraphicEngine::geNode::getName()
{
	return geNode::name;
}

int GraphicEngine::geNode::getId()
{
	return geNode::id;
}

GraphicEngine::geNode::Transform GraphicEngine::geNode::getTransform()
{
	return geNode::transform;
}

glm::vec3 GraphicEngine::geNode::getPosition()
{
	return geNode::transform.position;
}

glm::quat GraphicEngine::geNode::getRotation()
{
	return geNode::transform.rotation;
}

glm::vec3 GraphicEngine::geNode::getScale()
{
	return geNode::transform.scale;
}

void GraphicEngine::geNode::setName(const char* name)
{	
	if (name == nullptr)
	{
		throw ENullptrException();
	}

	geNode::name = name;
}

void GraphicEngine::geNode::setId(int id)
{
	geNode::id = id;
}

void GraphicEngine::geNode::setTransform(Transform transform)
{
	geNode::transform = transform;
}

void GraphicEngine::geNode::setPosition(glm::vec3 position)
{
	geNode::transform.position = position;
}

void GraphicEngine::geNode::setRotation(glm::quat rotation)
{
	geNode::transform.rotation = rotation;
}

void GraphicEngine::geNode::setScale(glm::vec3 scale)
{
	geNode::transform.scale = scale;
}
