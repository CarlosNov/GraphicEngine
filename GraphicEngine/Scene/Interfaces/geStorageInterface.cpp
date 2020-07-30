#include "geStorageInterface.h"

#include "Scene/geNode.h"

GraphicEngine::geStorageInterface::geStorageInterface()
{
    _geNodes.clear();
}

GraphicEngine::geStorageInterface::~geStorageInterface()
{

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

std::vector<GraphicEngine::geNode*> GraphicEngine::geStorageInterface::getChildren()
{
    return _geNodes;
}

void GraphicEngine::geStorageInterface::setChildren(std::vector<geNode*> geNodes)
{
    _geNodes = geNodes;
}