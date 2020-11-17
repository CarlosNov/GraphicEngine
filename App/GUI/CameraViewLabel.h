#pragma once
 
#include <QtWidgets/qlabel.h>
#include "config.h"
#include <QtGui/qimage.h>

namespace GraphicEngine
{
    class CameraViewLabel : public QLabel
    {
        Q_OBJECT
    public:
        CameraViewLabel(QWidget* parent);
        ~CameraViewLabel();
        
    public slots:
        void setColorTex(GLuint colorTex);
        void setRenderedImage(unsigned int width, unsigned int height);

    signals:
        void activateContextSignal();
        void deactivateContextSignal();

    protected:

        virtual void paintEvent(QPaintEvent* ev);

        QImage _renderedImage;
        GLuint _colorTex;
    };
}