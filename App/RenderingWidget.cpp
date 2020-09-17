#include "RenderingWidget.h"
#include "qcoreapplication.h"

RenderingWidget::RenderingWidget(QWidget* parent) : QOpenGLWidget(parent)
{
    QCoreApplication::instance()->installEventFilter(this);
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
    /*

    GraphicEngine::QTCopy* qtCopy = new GraphicEngine::QTCopy();

    qtCopy->setColorBuffer(forward->getColorBuffer());
    qtCopy->setDepthBuffer(forward->getDepthBuffer());
    qtCopy->setVertexBuffer(forward->getVertexBuffer());

    _core->addStep(qtCopy);

    */

    _colorTex = forward->getColorBuffer();
    emit colorTexSignal(_colorTex);
    
    GraphicEngine::geInterface::Transform transform = { glm::vec3(0.0,0.0,10.0), glm::vec3(0.0,0.0,0.0), glm::vec3(1.0,1.0,1.0)};
    GraphicEngine::geCamera* mainCamera = new GraphicEngine::geCamera("Camera", transform);
    _core->addCamera(mainCamera);
    GraphicEngine::geLight* mainLight = new GraphicEngine::geLight("Light");
    _core->addLight(mainLight);

    GraphicEngine::geCube* geCube = new GraphicEngine::geCube("Cube");
    _core->addNode(geCube);
    
    GraphicEngine::geImported* geAssimp = new GraphicEngine::geImported("Assimp");
    glm::mat4 model = geAssimp->getModelMatrix();
    model = glm::translate(model, glm::vec3(0.0, 1.0, 0.0));
    geAssimp->setModelMatrix(model);
    _core->addNode(geAssimp);
    
    
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
    //std::cout << defaultFramebufferObject();
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

void RenderingWidget::activateGLContext()
{
    makeCurrent();
}

void RenderingWidget::deactivateGLContext()
{
    doneCurrent();
}

bool RenderingWidget::eventFilter(QObject* object, QEvent* e)
{
    if (e->type() == QEvent::KeyPress)
    {
        QKeyEvent* KeyEvent = (QKeyEvent*) e;
        _core->keyboardFunction(KeyEvent);
        return true;
    }

    if (e->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent* MouseEvent = (QMouseEvent*)e;
        std::cout << "\n" << "(" << MouseEvent->x() << "," << MouseEvent->y() << ")";
    }

    if (e->type() == QEvent::MouseMove)
    {
        QMouseEvent* MouseEvent = (QMouseEvent*)e;

    }

    return false;
}