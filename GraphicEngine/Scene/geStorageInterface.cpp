#include "geStorageInterface.h"

#include "Scene/Derived/geContainer.h"
#include "Scene/Derived/geNode.h"
#include "Scene/Derived/geCamera.h"
#include "Scene/Derived/geLight.h"

GraphicEngine::geStorageInterface::geStorageInterface()
{
    _geContainers.clear();
    _geNodes.clear();
    _geCameras.clear();
    _geLights.clear();
}

GraphicEngine::geStorageInterface::~geStorageInterface(){}

bool GraphicEngine::geStorageInterface::addContainer(geContainer* geContainer)
{
    try
    {      
        _geContainers.push_back(geContainer);
        return true;
    }
    catch(const std::exception& e)
    {
        if(DEVELOPMENT)
            std::cerr << e.what() << '\n';
        return false;
    }
}

bool GraphicEngine::geStorageInterface::removeContainer(geContainer* geContainer)
{
    try
    {
        _geContainers.erase(std::remove(_geContainers.begin(), _geContainers.end(), geContainer), _geContainers.end());
        return true;
    }
    catch(const std::exception& e)
    {
        if(DEVELOPMENT)
            std::cerr << e.what() << '\n';
        return false;
    }
}

bool GraphicEngine::geStorageInterface::addNode(geNode* geNode)
{
    try
    {      
        _geNodes.push_back(geNode);
        return true;
    }
    catch(const std::exception& e)
    {
        if(DEVELOPMENT)
            std::cerr << e.what() << '\n';
        return false;
    }
}

bool GraphicEngine::geStorageInterface::removeNode(geNode* geNode)
{
    try
    {
        _geNodes.erase(std::remove(_geNodes.begin(), _geNodes.end(), geNode), _geNodes.end());
        return true;
    }
    catch(const std::exception& e)
    {
        if(DEVELOPMENT)
            std::cerr << e.what() << '\n';
        return false;
    }
}

bool GraphicEngine::geStorageInterface::addCamera(geCamera* geCamera)
{
    try
    {      
        _geCameras.push_back(geCamera);
        return true;
    }
    catch(const std::exception& e)
    {
        if(DEVELOPMENT)
            std::cerr << e.what() << '\n';
        return false;
    }
}

bool GraphicEngine::geStorageInterface::removeCamera(geCamera* geCamera)
{
    try
    {
        _geCameras.erase(std::remove(_geCameras.begin(), _geCameras.end(), geCamera), _geCameras.end());
        return true;
    }
    catch(const std::exception& e)
    {
        if(DEVELOPMENT)
            std::cerr << e.what() << '\n';
        return false;
    }
}

bool GraphicEngine::geStorageInterface::addLight(geLight* geLight)
{
    try
    {      
        _geLights.push_back(geLight);
        return true;
    }
    catch(const std::exception& e)
    {
        if(DEVELOPMENT)
            std::cerr << e.what() << '\n';
        return false;
    }
}

bool GraphicEngine::geStorageInterface::removeLight(geLight* geLight)
{
    try
    {
        _geLights.erase(std::remove(_geLights.begin(), _geLights.end(), geLight), _geLights.end());
        return true;
    }
    catch(const std::exception& e)
    {
        if(DEVELOPMENT)
            std::cerr << e.what() << '\n';
        return false;
    }
}

std::vector<GraphicEngine::geContainer*> GraphicEngine::geStorageInterface::getContainers()
{
    return _geContainers;
}

std::vector<GraphicEngine::geNode*> GraphicEngine::geStorageInterface::getNodes()
{
    return _geNodes;
}

std::vector<GraphicEngine::geCamera*> GraphicEngine::geStorageInterface::getCameras()
{
    return _geCameras;
}

std::vector<GraphicEngine::geLight*> GraphicEngine::geStorageInterface::getLights()
{
    return _geLights;
}

void GraphicEngine::geStorageInterface::setContainers(std::vector<geContainer*> geContainers)
{
    _geContainers = geContainers;
}

void GraphicEngine::geStorageInterface::setNodes(std::vector<geNode*> geNodes)
{
    _geNodes = geNodes;
}

void GraphicEngine::geStorageInterface::setCameras(std::vector<geCamera*> geCameras)
{
    _geCameras = geCameras;
}

void GraphicEngine::geStorageInterface::setLights(std::vector<geLight*> geLights)
{
    _geLights = geLights;
}