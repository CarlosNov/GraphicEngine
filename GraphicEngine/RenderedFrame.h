#pragma once

#include <QtWidgets/qlabel.h>
#include "config.h"

namespace App
{
    class RenderedFrame : public QLabel
    {
        Q_OBJECT
    public:
        RenderedFrame(QWidget* parent);
        ~RenderedFrame();

        void setRenderedImage(unsigned int width, unsigned int height);
        
    public slots:
        void setColorTex(GLuint colorTex);

    protected:

        virtual void paintEvent(QPaintEvent* ev); 

        QImage _renderedImage;
        GLuint _colorTex;
    };
}

