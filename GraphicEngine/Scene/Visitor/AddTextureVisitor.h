#pragma once

#include "Scene/Visitor/Visitor.h"
#include "Scene/Derived/geRenderNode.h"
#include "Scene/Derived/geCamera.h"
#include "Scene/Derived/geLight.h"

namespace GraphicEngine
{
    class AddTextureVisitor : public Visitor
    {
    public:
        void visitRenderNode(const geRenderNode * element) const override
        {
            element->addTexture(_texture);
        }

        void visitCamera(const geCamera* element) const override
        {

        }

        void visitLight(const geLight* element) const override
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