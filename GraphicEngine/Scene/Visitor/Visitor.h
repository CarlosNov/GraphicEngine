#pragma once

namespace GraphicEngine
{
    class geContainer;
    class geNode;
    class geCamera;
    class geLight;

    class Visitor {
    public:
        virtual void visitGeContainer(const geContainer* element) const = 0;
        virtual void visitGeNode(const geNode* element) const = 0;
        virtual void visitCamera(const geCamera* element) const = 0;
        virtual void visitLight(const geLight* element) const = 0;
    };
}