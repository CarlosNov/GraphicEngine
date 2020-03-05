#include "gePlane.h"

GraphicEngine::gePlane::gePlane(const char* name) : GraphicEngine::geRenderNode::geRenderNode(name)
{
	_mesh = Mesh::meshPlane();
}

GraphicEngine::gePlane::gePlane(const char* name, GraphicEngine::geInterface::Transform transform) : GraphicEngine::geRenderNode::geRenderNode(name, transform)
{
	_mesh = Mesh::meshPlane();
}

GraphicEngine::gePlane::~gePlane()
{

}

void GraphicEngine::gePlane::setProgramShaders(const char* vShader, const char* fShader)
{
	delete _material;
	_material = new Material(vShader, fShader);
}

unsigned int GraphicEngine::gePlane::getVAO()
{
	return _mesh->getVAO();
}