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

        void RecalculateImage();
        
    public slots:
        void SetCameraTexture(GLuint colorTex);
        void SetCameraTextureSize(unsigned int width, unsigned int height);

    signals:
        void activateContextSignal();
        void deactivateContextSignal();

    protected:

        virtual void paintEvent(QPaintEvent* ev);
       
        QImage _renderedImage;
        GLuint _colorTex;

        uint32_t imageWidth = 0;
        uint32_t imageHeight = 0;
    };
}