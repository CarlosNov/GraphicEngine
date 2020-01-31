#include "geNodeRenderable.h"

GraphicEngine::geNodeRenderable::geNodeRenderable(geBasic& instance) : GraphicEngine::Renderable::Renderable()
{
	_geBasic = &instance;
}

void GraphicEngine::geNodeRenderable::render (Renderer& renderer) const
{
	std::cout << _geBasic->getName();
	/*
	_material->activateProgram();

	glm::mat4 modelView = viewMat * _modelMatrix;
	glm::mat4 normal = glm::transpose(glm::inverse(modelView));

	_material->setModelViewMat(modelView);
	_material->setModelViewProjMat(modelView, projMat);
	_material->setNormalMat(normal);

	for (std::map< int, Texture* >::iterator it = _textures.begin();
		it != _textures.end(); it++)
	{
		_material->activateTexture(it->second);
	}

	_material->setAttributes(_mesh->getposVBO(), _mesh->getcolorVBO(),
		_mesh->getnormalVBO(), _mesh->gettexCoordVBO());

	_mesh->renderMesh();
	*/
}