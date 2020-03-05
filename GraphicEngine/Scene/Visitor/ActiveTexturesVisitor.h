#pragma once

#include "Scene/Visitor/Visitor.h"
#include "Scene/Derived/geRenderNode.h"
#include "Scene/Derived/geCamera.h"
#include "Scene/Derived/geLight.h"

namespace GraphicEngine
{
    class ActiveTexturesVisitor : public Visitor
    {
    public:
        void visitRenderNode(const geRenderNode* element) const override
        {
            element->activateTextures();
        }

        void visitCamera(const geCamera* element) const override
        {

        }

        void visitLight(const geLight* element) const override
        {

        }
    };
}