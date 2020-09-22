#include "geImported.h"

GraphicEngine::geImported::geImported(const char* name) : GraphicEngine::geRenderNode::geRenderNode(name)
{
	/*
	_mesh = Mesh::meshAssimp("../Dependencies/models/sphere.obj");

	Texture* colorTexId = new Texture("../Dependencies/img/color.png", Texture::TextureType::DIFFUSE);
	_material->addTexture(colorTexId);

	Texture* emiTexId = new Texture("../Dependencies/img/emissive.png", Texture::TextureType::EMISIVE);
	_material->addTexture(emiTexId);
	*/
}

GraphicEngine::geImported::geImported(const char* name, GraphicEngine::geInterface::Transform transform) : GraphicEngine::geRenderNode::geRenderNode(name, transform)
{
	/*
	_mesh = Mesh::meshAssimp("../Dependencies/models/sphere.obj");

	Texture* colorTexId = new Texture("../Dependencies/img/color.png", Texture::TextureType::DIFFUSE);
	_material->addTexture(colorTexId);

	Texture* emiTexId = new Texture("../Dependencies/img/emissive.png", Texture::TextureType::EMISIVE);
	_material->addTexture(emiTexId);
	*/
}