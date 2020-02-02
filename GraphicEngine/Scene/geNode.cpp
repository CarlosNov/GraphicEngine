#include "geNode.h"

static float angle = 0.0f;

GraphicEngine::geNode* GraphicEngine::geNode::geBasicCube(const char* name)
{
	return new geNode(name, CUBE);
}

GraphicEngine::geNode* GraphicEngine::geNode::geBasicPlane(const char* name)
{
	return new geNode(name, PLANE);
}

GraphicEngine::geNode* GraphicEngine::geNode::geBasicSphere(const char* name)
{
	return new geNode(name, SPHERE);
}

GraphicEngine::geNode::geNode(const char* name, BasicNodes basicNodes) : GraphicEngine::geInterface::geInterface(name)
{
	_textures.clear();
	_modelMatrix = glm::mat4(1.0f);

	switch (basicNodes)
	{
		case CUBE:
			_mesh = Mesh::meshCube();
			break;

		case PLANE:
			_mesh = Mesh::meshPlane();
			break;

		case SPHERE:
			_mesh = Mesh::meshSphere();
			break;

		default:
			break;
	}

	Material* forwardRender = new Material("shaders/fwRendering.v1.vert", "shaders/fwRendering.v1.frag");
	_material = forwardRender;

	Texture* colorTexId = new Texture("../Dependencies/img/color.png", Texture::DIFFUSE);
	_textures[Texture::DIFFUSE] = colorTexId;
	Texture* emiTexId = new Texture("../Dependencies/img/emissive.png", Texture::EMISIVE);
	_textures[Texture::EMISIVE] = emiTexId;
}

GraphicEngine::geNode::geNode(const char* name) : GraphicEngine::geInterface::geInterface(name)
{

}

GraphicEngine::geNode::~geNode() {


}

void GraphicEngine::geNode::render()
{
	_material->activateProgram();

	glm::mat4 modelView = _viewMatrix * _modelMatrix;
	glm::mat4 normal = glm::transpose(glm::inverse(modelView));

	_material->setModelViewMat(modelView);
	_material->setModelViewProjMat(modelView, _projMatrix);
	_material->setNormalMat(normal);

	for (std::map< int, Texture* >::iterator it = _textures.begin();
		it != _textures.end(); it++)
	{
		_material->activateTexture(it->second);
	}

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

void GraphicEngine::geNode::setMatrix(glm::mat4 viewMat, glm::mat4 projMat)
{
	_viewMatrix = viewMat;
	_projMatrix = projMat;
}