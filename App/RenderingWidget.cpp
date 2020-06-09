#include "RenderingWidget.h"

RenderingWidget::RenderingWidget(QWidget* parent) : QOpenGLWidget(parent)
{
}

RenderingWidget::~RenderingWidget()
{
    makeCurrent();
    delete(_core);
    doneCurrent();
}

void RenderingWidget::mousePressEvent(QMouseEvent* e)
{

}

void RenderingWidget::mouseReleaseEvent(QMouseEvent* e)
{

}

void RenderingWidget::timerEvent(QTimerEvent* e)
{
    _core->updateFunction();
    update();
}

void RenderingWidget::initializeGL()
{
    initializeOpenGLFunctions();

    _core->initGlew();

    glClearColor(0.2f, 0.2f, 0.2f, 0.0f);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    makeCurrent();

    _core = new GraphicEngine::Core();

    GraphicEngine::Forward* forward = new GraphicEngine::Forward();
    _core->addStep(forward);

    GraphicEngine::PostProcess* postProcess = new GraphicEngine::PostProcess();

    postProcess->setColorBuffer(forward->getColorBuffer());
    postProcess->setDepthBuffer(forward->getDepthBuffer());
    postProcess->setVertexBuffer(forward->getVertexBuffer());
    
    _core->addStep(postProcess);

    GraphicEngine::QTCopy* qtCopy = new GraphicEngine::QTCopy();

    qtCopy->setColorBuffer(postProcess->getColorBuffer());
    qtCopy->setDepthBuffer(postProcess->getDepthBuffer());
    qtCopy->setVertexBuffer(postProcess->getVertexBuffer());

    _colorTex = qtCopy->getColorBuffer();
    emit colorTexSignal(_colorTex);
    std::cout << "WIDGET: " << _colorTex;

    _core->addStep(qtCopy);

    GraphicEngine::geCamera* mainCamera = new GraphicEngine::geCamera("Camera");
    _core->addCamera(mainCamera);
    GraphicEngine::geLight* mainLight = new GraphicEngine::geLight("Light");
    _core->addLight(mainLight);

    GraphicEngine::geCube* geCube = new GraphicEngine::geCube("Cube");
    _core->addNode(geCube);

    doneCurrent();
    timer.start(12, this);
}

void RenderingWidget::resizeGL(int w, int h)
{
    _core->resizeFunction(w, h);
}

void RenderingWidget::paintGL()
{
    makeCurrent();
    _core->renderFunction();
    emit renderedImageSignal(_core->getWindowWidth(), _core->getWindowHeight());
    doneCurrent();
}

void RenderingWidget::initShaders()
{

}

void RenderingWidget::initTextures()
{

}

GLuint RenderingWidget::getColorTex()
{
    return _colorTex;
}