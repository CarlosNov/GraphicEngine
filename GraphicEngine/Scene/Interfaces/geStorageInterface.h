#pragma once

#include "config.h"

namespace GraphicEngine
{
    class geNode;

    class geStorageInterface
    {
    public:
        geStorageInterface();
        ~geStorageInterface();

        bool addNode(geNode* geNode);
        bool removeNode(geNode* geNode);

        std::vector<geNode*> getChildren();
        void setChildren(std::vector<geNode*> geNodes);

    protected:
    std::vector<geNode*> _geNodes;
    };
}