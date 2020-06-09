#pragma once

#include <QtWidgets/qlabel.h>
#include "config.h"

namespace App
{
    class RenderedLabel : public QLabel
    {
        
    public:
        RenderedLabel(QWidget* parent);
        ~RenderedLabel(); 
        
    public slots:
        void setColorTex(GLuint colorTex);
        void setRenderedImage(unsigned int width, unsigned int height);

    protected:

        virtual void RenderedLabel::paintEvent(QPaintEvent* ev);

        QImage _renderedImage;
        GLuint _colorTex;
    };
}

