#pragma once
 
#include <QtWidgets/qlabel.h>
#include "config.h"
#include <QtGui/qimage.h>

namespace App
{
    class RenderQLabel : public QLabel
    {
        Q_OBJECT
    public:
        RenderQLabel(QWidget* parent);
        ~RenderQLabel();
        
    public slots:
        void setColorTex(GLuint colorTex);
        void setRenderedImage(unsigned int width, unsigned int height);

    signals:
        void activateContextSignal();
        void deactivateContextSignal();

    protected:

        virtual void RenderQLabel::paintEvent(QPaintEvent* ev);

        QImage _renderedImage;
        GLuint _colorTex;
    };
}