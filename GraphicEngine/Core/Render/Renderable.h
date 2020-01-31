#pragma once

#include "Core/Render/Renderer.h"

namespace GraphicEngine
{
    class Renderer;

    class Renderable
    {
    public:
        Renderable() {}
        ~Renderable() {}
        virtual void render(Renderer& renderer) const = 0;
    };
}

