#pragma once

namespace GraphicEngine
{
    class geRenderNode;
    class geCamera;
    class geLight;

    class Visitor {
    public:
        virtual void visitRenderNode(const geRenderNode* element) const = 0;
        virtual void visitCamera(const geCamera* element) const = 0;
        virtual void visitLight(const geLight* element) const = 0;
    };
}