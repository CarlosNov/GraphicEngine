#include "PostProcess.h"
#include "Scene/Derived/geNode.h"

GraphicEngine::PostProcess::PostProcess() : GraphicEngine::Step::Step()
{
}

GraphicEngine::PostProcess::~PostProcess()
{

}

void GraphicEngine::PostProcess::render(std::vector<geInterface*> toRenderNodes, Camera* camera)
{
	//_plane->addTexture(new Texture(_fbo.getColorBuffer(), Texture::DIFFUSE));
	//_plane->addTexture(new Texture(_fbo.getVertexBuffer(), Texture::VERTEX));
	

}