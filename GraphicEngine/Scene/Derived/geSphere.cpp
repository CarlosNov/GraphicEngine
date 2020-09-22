#include "geSphere.h"

GraphicEngine::geSphere::geSphere(const char* name) : GraphicEngine::geRenderNode::geRenderNode(name)
{
	/*
	_mesh = new Mesh("../Dependencies/models/cuboAssimp.obj");

	Material* forwardRender = new Material("shaders/fwRendering.v2.vert", "shaders/fwRendering.v2.frag");
	_material = forwardRender;

	Texture* colorTexId = new Texture("../Dependencies/img/color.png", Texture::TextureType::DIFFUSE);
	_material->addTexture(colorTexId);

	Texture* emiTexId = new Texture("../Dependencies/img/emissive.png", Texture::TextureType::EMISIVE);
	_material->addTexture(emiTexId);
	*/
}

GraphicEngine::geSphere::geSphere(const char* name, GraphicEngine::geInterface::Transform transform) : GraphicEngine::geRenderNode::geRenderNode(name, transform)
{
	//_mesh = Mesh::meshCube();
}

GraphicEngine::geSphere::~geSphere()
{

}

void GraphicEngine::geSphere::setProgramShaders(const char* vShader, const char* fShader)
{
	/*
	delete _material;
	_material = new Material(vShader, fShader);
	*/
}

unsigned int GraphicEngine::geSphere::getVAO()
{
	return 1;
	//return _mesh->getVAO();
}