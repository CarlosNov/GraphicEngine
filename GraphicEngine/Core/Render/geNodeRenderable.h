#pragma once

#include "Scene/geBasic.h"

namespace GraphicEngine
{
    class geNodeRenderable : public Renderable
    {
    public:
        geNodeRenderable(geBasic& instance);

        void render(Renderer& renderer) const;

    protected:
        geBasic* _geBasic;
    };
}


