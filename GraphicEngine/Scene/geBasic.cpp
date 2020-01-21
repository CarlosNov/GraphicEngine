#include "geBasic.h"

static float angle = 0.0f;

GraphicEngine::geBasic* GraphicEngine::geBasic::geBasicCube(const char* name)
{
	return new geBasic(name, CUBE);
}

GraphicEngine::geBasic* GraphicEngine::geBasic::geBasicPlane(const char* name)
{
	return new geBasic(name, PLANE);
}

GraphicEngine::geBasic* GraphicEngine::geBasic::geBasicSphere(const char* name)
{
	return new geBasic(name, SPHERE);
}

GraphicEngine::geBasic::geBasic(const char* name, BasicNodes basicNodes) : GraphicEngine::geInterface::geInterface(name)
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
	
	Material* forwardRender = new Material(Material::FORDWARD, "shaders/fwRendering.v1.vert", "shaders/fwRendering.v1.frag");
	_material = forwardRender;

	Texture* colorTexId = new Texture("../Dependencies/img/color.png", Texture::DIFFUSE);
	_textures[Texture::DIFFUSE] = colorTexId;
	Texture* emiTexId = new Texture("../Dependencies/img/emissive.png", Texture::EMISIVE);
	_textures[Texture::EMISIVE] = emiTexId;
}

GraphicEngine::geBasic::geBasic(const char* name) : GraphicEngine::geInterface::geInterface(name)
{

}

GraphicEngine::geBasic::~geBasic() {


}

void GraphicEngine::geBasic::render(glm::mat4 viewMat, glm::mat4 projMat)
{
	_modelMatrix = glm::mat4(1.0f);


	if (angle > (3.1415f * 2.0f))
		angle = 0;
	else
		angle = angle + 0.01f;

	_modelMatrix = glm::rotate(_modelMatrix, angle, glm::vec3(1, 1, 0));

	_material->activateProgram(GraphicEngine::Material::FORDWARD);

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
}
