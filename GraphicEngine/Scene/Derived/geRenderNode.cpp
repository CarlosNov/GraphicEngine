#include "geRenderNode.h"

static float angle = 0.0f;

GraphicEngine::geRenderNode::geRenderNode(const char* name) : GraphicEngine::geNode::geNode(name)
{
	_modelMatrix = glm::mat4(1.0f);

	_mesh = nullptr;

	Material* forwardRender = new Material("Shaders/fwRendering.v1.vert", "Shaders/fwRendering.v1.frag");
	_material = forwardRender;
}

GraphicEngine::geRenderNode::geRenderNode(const char* name, Transform transform) : GraphicEngine::geNode::geNode(name, transform)
{
	_modelMatrix = glm::mat4(1.0f);

	_mesh = nullptr;

	Material* forwardRender = new Material("Shaders/fwRendering.v1.vert", "Shaders/fwRendering.v1.frag");
	_material = forwardRender;
}

GraphicEngine::geRenderNode::~geRenderNode()
{
	_mesh->~Mesh();
	delete _mesh;

	_material->~Material();
	delete _material;
}

void GraphicEngine::geRenderNode::render()
{
	glBindVertexArray(_mesh->getVAO());
	_material->setAttributes(_mesh->getposVBO(), _mesh->getcolorVBO(),
		_mesh->getnormalVBO(), _mesh->gettexCoordVBO());

	_mesh->renderMesh();
}

void GraphicEngine::geRenderNode::update()
{
	if (angle > (3.1415f * 2.0f))
		angle = 0;
	else
		angle = angle + 0.00001f;

	_modelMatrix = glm::rotate(_modelMatrix, angle, glm::vec3(1, 1, 0));
}

void GraphicEngine::geRenderNode::accept(Visitor* visitor)
{
	visitor->visitRenderNode(this);
}

void GraphicEngine::geRenderNode::activateProgram() const
{
	_material->activateProgram();
}

void GraphicEngine::geRenderNode::deactivateProgram() const
{
	_material->deactivateProgram();
}

void GraphicEngine::geRenderNode::setModelViewMatrix(glm::mat4 view) const
{
	glm::mat4 modelView = view * _modelMatrix;
	_material->setModelViewMat(modelView);
}

void GraphicEngine::geRenderNode::setModelViewProjectionMatrix(glm::mat4 view, glm::mat4 proj) const
{
	glm::mat4 modelView = view * _modelMatrix;
	_material->setModelViewProjMat(modelView, proj);
}

void GraphicEngine::geRenderNode::setNormalMatrix(glm::mat4 view) const
{
	glm::mat4 modelView = view * _modelMatrix;
	glm::mat4 normal = glm::transpose(glm::inverse(modelView));
	_material->setNormalMat(normal);
}

void GraphicEngine::geRenderNode::activateTextures() const
{
	_material->activateTextures();
}

void GraphicEngine::geRenderNode::addTexture(Texture* texture) const
{
	_material->addTexture(texture);
}

glm::mat4 GraphicEngine::geRenderNode::getModelMatrix()
{
	return _modelMatrix;
}

GraphicEngine::Mesh* GraphicEngine::geRenderNode::getMesh()
{
	return _mesh;
}

GraphicEngine::Material* GraphicEngine::geRenderNode::getMaterial()
{
	return _material;
}

void GraphicEngine::geRenderNode::setModelMatrix(glm::mat4 modelMatrix)
{
	_modelMatrix = modelMatrix;
}

void GraphicEngine::geRenderNode::setMesh(Mesh* mesh)
{
	_mesh = mesh;
}

void GraphicEngine::geRenderNode::setMaterial(Material* material)
{
	_material = material;
}