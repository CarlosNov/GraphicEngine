#include "geCube.h"

GraphicEngine::geCube::geCube(const char* name) : GraphicEngine::geRenderNode::geRenderNode(name)
{
	_mesh = Mesh::meshCube();

	Texture* colorTexId = new Texture("../Dependencies/img/color.png", Texture::TextureType::DIFFUSE);
	_material->addTexture(colorTexId);

	Texture* emiTexId = new Texture("../Dependencies/img/emissive.png", Texture::TextureType::EMISIVE);
	_material->addTexture(emiTexId);
}

GraphicEngine::geCube::geCube(const char* name, GraphicEngine::geInterface::Transform transform) : GraphicEngine::geRenderNode::geRenderNode(name, transform)
{
	_mesh = Mesh::meshCube();

	Texture* colorTexId = new Texture("../Dependencies/img/color.png", Texture::TextureType::DIFFUSE);
	_material->addTexture(colorTexId);

	Texture* emiTexId = new Texture("../Dependencies/img/emissive.png", Texture::TextureType::EMISIVE);
	_material->addTexture(emiTexId);
}