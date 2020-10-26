#pragma once

#include "GraphicEngine.h"
#include "Steps/QTCopy.h"
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qopenglwidget.h>
#include <QtGui/qopenglfunctions.h>
#include <QtCore/qbasictimer.h>
#include <qevent.h>
#include <qobject.h>

namespace GraphicEngine
{
    class OpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
    {
        Q_OBJECT
    public:
        OpenGLWidget(QWidget* parent = 0);
        ~OpenGLWidget();
        GLuint getColorTex();

    public slots:
        void activateGLContext();
        void deactivateGLContext();

    signals:
        void SetHierarchyScene(Scene* scene);
        void InitHierarchy();
        void AddEntityToHierarchy();
        void UpdateUI();

        void colorTexSignal(GLuint colorTex);
        void renderedImageSignal(unsigned int width, unsigned int height);

    protected:
        void mousePressEvent(QMouseEvent* e) override;
        void mouseReleaseEvent(QMouseEvent* e) override;
        void timerEvent(QTimerEvent* e) override;
        bool eventFilter(QObject* object, QEvent* e) override;

        void initializeGL() override;
        void resizeGL(int w, int h) override;
        void paintGL() override;

        void initShaders();
        void initTextures();

    private:
        QBasicTimer timer;
        Scene* m_ActiveScene;
        Core* _core;
        std::vector<Step*> m_Steps;
        GLuint _colorTex;
    };
}