#pragma once

#include "Scene/Visitor/Visitor.h"
#include "Scene/Derived/geNode.h"
#include "Scene/Derived/geContainer.h"
#include "Scene/Derived/Camera.h"
#include "Scene/Derived/Light.h"

namespace GraphicEngine
{
    class SetModelViewProjectionMatrixVisitor : public Visitor
    {
    public:
        void visitGeContainer(const geContainer* element) const override
        {

        }

        void visitGeNode(const geNode* element) const override
        {
            element->setModelViewProjectionMatrix(_view, _proj);
        }

        void visitCamera(const Camera* element) const override
        {

        }

        void visitLight(const Light* element) const override
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