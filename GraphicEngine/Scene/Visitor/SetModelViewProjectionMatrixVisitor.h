#pragma once

#include "Scene/Visitor/Visitor.h"
#include "Scene/Derived/geRenderNode.h"
#include "Scene/SceneCamera.h"
#include "Scene/Derived/geLight.h"

namespace GraphicEngine
{
    class SetModelViewProjectionMatrixVisitor : public Visitor
    {
    public:

        void visitRenderNode(const geRenderNode* element) const override
        {
            element->setModelViewProjectionMatrix(_view, _proj);
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

        void setProj(glm::mat4 proj)
        {
            _proj = proj;
        }

    private:
        glm::mat4 _view;
        glm::mat4 _proj;
    };
}