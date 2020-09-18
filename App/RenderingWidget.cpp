#include "RenderingWidget.h"
#include "qcoreapplication.h"

namespace GraphicEngine
{

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

        _core = new GraphicEngine::Core();

        std::vector<GraphicEngine::Step*> steps;
        steps.push_back(new GraphicEngine::Forward());
        steps.push_back(new GraphicEngine::PostProcess());
        steps.push_back(new App::QTCopy());

        steps[1]->setColorBuffer(steps[0]->getColorBuffer());
        steps[1]->setDepthBuffer(steps[0]->getDepthBuffer());
        steps[1]->setVertexBuffer(steps[0]->getVertexBuffer());
        steps[2]->setColorBuffer(steps[1]->getColorBuffer());
        steps[2]->setDepthBuffer(steps[1]->getDepthBuffer());
        steps[2]->setVertexBuffer(steps[1]->getVertexBuffer());

        _core->addSteps(steps);

        _colorTex = steps[2]->getColorBuffer();
        emit colorTexSignal(_colorTex);

        // TODO: Delete all pointers after initializing everything.

        geInterface::Transform transform = { glm::vec3(0.0,0.0,10.0), glm::vec3(0.0,0.0,0.0), glm::vec3(1.0,1.0,1.0) };
        geCamera* mainCamera = new geCamera("Camera", transform);
        _core->addCamera(mainCamera);
        geLight* mainLight = new geLight("Light");
        _core->addLight(mainLight);

        GraphicEngine::geCube* geCube = new GraphicEngine::geCube("Cube");
        _core->addNode(geCube);

        GraphicEngine::geImported* geAssimp = new GraphicEngine::geImported("Assimp");
        glm::mat4 model = geAssimp->getModelMatrix();
        model = glm::translate(model, glm::vec3(0.0, 1.0, 0.0));
        geAssimp->setModelMatrix(model);
        _core->addNode(geAssimp);

        
        //m_ActiveScene = new Scene();
        //auto cube = m_ActiveScene->CreateEntity("Cube");

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
            QKeyEvent* KeyEvent = (QKeyEvent*)e;
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
}