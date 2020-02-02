#pragma once

#include "Scene/Visitor/Visitor.h"
#include "Scene/Derived/geNode.h"
#include "Scene/Derived/geContainer.h"
#include "Scene/Derived/Camera.h"
#include "Scene/Derived/Light.h"

namespace GraphicEngine
{
    class AddTextureVisitor : public Visitor
    {
    public:

        void visitGeContainer(const geContainer* element) const override
        {

        }

        void visitGeNode(const geNode* element) const override
        {
            element->addTexture(_texture);
        }

        void visitCamera(const Camera* element) const override
        {

        }

        void visitLight(const Light* element) const override
        {

        }

        void setTexture(Texture* texture)
        {
            _texture = texture;
        }

    private:
        Texture* _texture;
    };
}