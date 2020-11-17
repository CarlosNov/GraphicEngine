#pragma once

#include "GraphicEngine.h"
#include "Steps/QTCopy.h"
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qopenglwidget.h>
#include <QtGui/qopenglfunctions.h>
#include <QtCore/qbasictimer.h>
#include <QKeyEvent>
#include <QSet>
#include <QObject>

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
        void timerEvent(QTimerEvent* e) override;      

        void initializeGL() override;
        void resizeGL(int w, int h) override;
        void paintGL() override;
        void keyPressEvent(QKeyEvent* e) override;
        void keyReleaseEvent(QKeyEvent* e) override;
        void mousePressEvent(QMouseEvent* e) override;
        void mouseMoveEvent(QMouseEvent* e) override;
        void mouseReleaseEvent(QMouseEvent* e) override;
        void wheelEvent(QWheelEvent* e) override;

        void initShaders();
        void initTextures();

    private:
        void processKeyEvent(Qt::Key e);

    private:
        QBasicTimer timer;
        Scene* m_ActiveScene;
        std::vector<Step*> m_Steps;
        GLuint _colorTex;

        QSet<Qt::Key> keysPressed;
        bool m_bFirstRelease = false;

        float lastX;
        float lastY;
        bool m_MidButtonPressed = false;
        bool m_RightButtonPressed = false;
        float yaw;
        float pitch;
    };
}