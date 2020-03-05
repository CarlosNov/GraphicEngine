#pragma once

#include "Core/Core.h"
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qopenglwidget.h>
#include <QtGui/qopenglfunctions.h>
#include <QtCore/qbasictimer.h>

class RenderingWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit RenderingWidget(QWidget* parent = 0);
    ~RenderingWidget();
    GLuint getColorTex();

signals:
    void colorTexSignal(GLuint colorTex);

protected:
    void mousePressEvent(QMouseEvent* e) override;
    void mouseReleaseEvent(QMouseEvent* e) override;
    void timerEvent(QTimerEvent* e) override;

    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    void initShaders();
    void initTextures();

private:
    
    QBasicTimer timer;

    GraphicEngine::Core* _core;
    GLuint _colorTex;
};

