#include "geStorageInterface.h"

GraphicEngine::geStorageInterface::geStorageInterface()
{
    _geContainers.clear();
    _geNodes.clear();
    _geCameras.clear();
    _geLight.clear();
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
        vec.erase(std::remove(_geContainers.begin(), _geContainers.end(), geContainer), _geContainers.end());
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
        vec.erase(std::remove(_geNodes.begin(), _geNodes.end(), geNode), _geNodes.end());
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
        vec.erase(std::remove(_geCameras.begin(), _geCameras.end(), geCamera), _geCameras.end());
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
        vec.erase(std::remove(_geLights.begin(), _geLights.end(), geLight), _geLights.end());
        return true;
    }
    catch(const std::exception& e)
    {
        if(DEVELOPMENT)
            std::cerr << e.what() << '\n';
        return false;
    }
}

std::vector<geContainer*> GraphicEngine::geStorageInterface::getContainers()
{
    return _geContainers;
}

std::vector<geNode*> GraphicEngine::geStorageInterface::getNodes())
{
    return _geNodes;
}

std::vector<geCamera*> GraphicEngine::geStorageInterface::getCameras()
{
    return _geCameras;
}

std::vector<geLight*> GraphicEngine::geStorageInterface::getLights()
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