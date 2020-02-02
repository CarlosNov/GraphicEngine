#pragma once

namespace GraphicEngine
{
    class geContainer;
    class geNode;
    class Camera;
    class Light;

    class Visitor {
    public:
        virtual void visitGeContainer(const geContainer* element) const = 0;
        virtual void visitGeNode(const geNode* element) const = 0;
        virtual void visitCamera(const Camera* element) const = 0;
        virtual void visitLight(const Light* element) const = 0;
    };
}