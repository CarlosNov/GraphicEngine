#pragma once

#include "Scene/Visitor/Visitor.h"
#include "Scene/Derived/geRenderNode.h"
#include "Scene/PerspectiveCamera.h"
#include "Scene/Derived/geLight.h"

namespace GraphicEngine
{
    class SetModelViewMatrixVisitor : public Visitor
    {
    public:
        void visitRenderNode(const geRenderNode* element) const override
        {
            element->setModelViewMatrix(_view);
        }

        void visitCamera(const geCamera* element) const override
        {

        }

        void visitLight(const geLight* element) const override
        {

        }

        void setView(glm::mat4 view)
        {
            _view = view;
        }

    private:
        glm::mat4 _view;
    };
}