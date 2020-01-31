#include "Renderer.h"

void GraphicEngine::Renderer::renderNodes()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (std::vector<Step*>::iterator it = _steps.begin(); it != _steps.end(); it++)
    {
        (*it)->render(this);
    }

    glUseProgram(NULL);

    glutSwapBuffers();
}

void GraphicEngine::Renderer::addNode(geInterface* geInterface)
{
    _toRenderNodes.push_back(geInterface);
}

void GraphicEngine::Renderer::addStep(Step* step)
{
    _steps.push_back(step);
}

void GraphicEngine::Renderer::addCamera(Camera* camera)
{
    _mainCamera = camera;
}

std::vector<GraphicEngine::geInterface*> GraphicEngine::Renderer::getRenderNodes()
{
    return _toRenderNodes;
}

GraphicEngine::Camera* GraphicEngine::Renderer::getCamera()
{
    return _mainCamera;
}