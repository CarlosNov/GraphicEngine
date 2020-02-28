#include "geNode.h"

static float angle = 0.0f;

GraphicEngine::geNode::geNode(const char* name) : GraphicEngine::geInterface::geInterface(name)
{
	_modelMatrix = glm::mat4(1.0f);

	_mesh = nullptr;

	Material* forwardRender = new Material("shaders/fwRendering.v1.vert", "shaders/fwRendering.v1.frag");
	_material = forwardRender;
}

GraphicEngine::geNode::geNode(const char* name, Transform transform) : GraphicEngine::geInterface::geInterface(name, transform)
{
	_modelMatrix = glm::mat4(1.0f);

	_mesh = nullptr;

	Material* forwardRender = new Material("shaders/fwRendering.v1.vert", "shaders/fwRendering.v1.frag");
	_material = forwardRender;
}

GraphicEngine::geNode::~geNode() 
{
	_mesh->~Mesh();
	delete _mesh;

	_material->~Material();
	delete _material;
}

void GraphicEngine::geNode::render()
{
	_material->setAttributes(_mesh->getposVBO(), _mesh->getcolorVBO(),
		_mesh->getnormalVBO(), _mesh->gettexCoordVBO());

	_mesh->renderMesh();
}

void GraphicEngine::geNode::update()
{
	if (angle > (3.1415f * 2.0f))
		angle = 0;
	else
		angle = angle + 0.00001f;

	_modelMatrix = glm::rotate(_modelMatrix, angle, glm::vec3(1, 1, 0));
}

void GraphicEngine::geNode::accept(Visitor* visitor)
{
	visitor->visitGeNode(this);
}

void GraphicEngine::geNode::activateProgram() const
{
	_material->activateProgram();
}

void GraphicEngine::geNode::deactivateProgram() const
{
	_material->deactivateProgram();
}

void GraphicEngine::geNode::setModelViewMatrix(glm::mat4 view) const
{
	glm::mat4 modelView = view * _modelMatrix;
	_material->setModelViewMat(modelView);
}

void GraphicEngine::geNode::setModelViewProjectionMatrix(glm::mat4 view, glm::mat4 proj) const
{
	glm::mat4 modelView = view * _modelMatrix;
	_material->setModelViewProjMat(modelView, proj);
}

void GraphicEngine::geNode::setNormalMatrix(glm::mat4 view) const
{
	glm::mat4 modelView = view * _modelMatrix;
	glm::mat4 normal = glm::transpose(glm::inverse(modelView));
	_material->setNormalMat(normal);
}

void GraphicEngine::geNode::activateTextures() const
{
	_material->activateTextures();
}

void GraphicEngine::geNode::addTexture(Texture* texture) const
{
	_material->addTexture(texture);
}

glm::mat4 GraphicEngine::geNode::getModelMatrix()
{
	return _modelMatrix;
}

GraphicEngine::Mesh* GraphicEngine::geNode::getMesh()
{
	return _mesh;
}

GraphicEngine::Material* GraphicEngine::geNode::getMaterial()
{
	return _material;
}

void GraphicEngine::geNode::setModelMatrix(glm::mat4 modelMatrix)
{
	_modelMatrix = modelMatrix;
}

void GraphicEngine::geNode::setMesh(Mesh* mesh)
{
	_mesh = mesh;
}

void GraphicEngine::geNode::setMaterial(Material* material)
{
	_material = material;
}