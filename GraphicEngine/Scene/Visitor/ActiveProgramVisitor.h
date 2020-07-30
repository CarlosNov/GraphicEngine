#pragma once

#include "Scene/Visitor/Visitor.h"
#include "Scene/Derived/geRenderNode.h"
#include "Scene/Derived/geCamera.h"
#include "Scene/Derived/geLight.h"

namespace GraphicEngine
{
    class ActiveProgramVisitor : public Visitor
    {
    public:
        void visitRenderNode(const geRenderNode* element) const override
        {
            element->activateProgram();
        }

        void visitCamera(const geCamera* element) const override
        {

        }

        void visitLight(const geLight* element) const override
        {

        }
    };
}