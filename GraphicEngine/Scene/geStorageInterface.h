#pragma once

#include "config.h"

#include "Scene/Derived/geContainer.h"
#include "Scene/Derived/geNode.h"
#include "Scene/Derived/geCamera.h"
#include "Scene/Derived/geLight.h"

namespace GraphicEngine
{
    class geContainer;
    class geNode;
    class geCamera;
    class geLight;

    class geStorageInterface
    {
    public:
        geStorageInterface();
        ~geStorageInterface();
    
        bool addContainer(geContainer* geContainer);
        bool removeContainer(geContainer* geContainer);

        bool addNode(geNode* geNode);
        bool removeNode(geNode* geNode);

        bool addCamera(geCamera* geCamera);
        bool removeCamera(geCamera* geCamera);

        bool addLight(geLight* geLight);
        bool removeLight(geLight* geLight);

        std::vector<geContainer*> getContainers();
        std::vector<geNode*> getNodes());
        std::vector<geCamera*> getCameras();
        std::vector<geLight*> getLights();

        void setContainers(std::vector<geContainer*> geContainers);
        void setNodes(std::vector<geNode*> geNodes);
        void setCameras(std::vector<geCamera*> geCameras);
        void setLights(std::vector<geLight*> geLights);
    protected:
    std::vector<geContainer*> _geContainers;
    std::vector<geNode*> _geNodes;
    std::vector<geCamera*> _geCameras;
    std::vector<geLight*> _geLights;
    };
}