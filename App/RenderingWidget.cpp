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

    void RenderingWidget::initializeGL()
    {
        initializeOpenGLFunctions();
        _core->initGlew();

        glClearColor(0.2f, 0.2f, 0.2f, 0.0f);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_CULL_FACE);

        _core = new GraphicEngine::Core();

        m_Steps.push_back(new GraphicEngine::Forward());
        m_Steps.push_back(new GraphicEngine::PostProcess());
        m_Steps.push_back(new App::QTCopy());

        m_Steps[1]->setColorBuffer(m_Steps[0]->getColorBuffer());
        m_Steps[1]->setDepthBuffer(m_Steps[0]->getDepthBuffer());
        m_Steps[1]->setVertexBuffer(m_Steps[0]->getVertexBuffer());
        m_Steps[2]->setColorBuffer(m_Steps[1]->getColorBuffer());
        m_Steps[2]->setDepthBuffer(m_Steps[1]->getDepthBuffer());
        m_Steps[2]->setVertexBuffer(m_Steps[1]->getVertexBuffer());

        _core->addSteps(m_Steps);

        _colorTex = m_Steps[1]->getColorBuffer();
        emit colorTexSignal(_colorTex);

        // TODO: Delete all pointers after initializing everything.

        //geInterface::Transform transform = { glm::vec3(0.0,0.0,10.0), glm::vec3(0.0,0.0,0.0), glm::vec3(1.0,1.0,1.0) };

        /*
        geLight* mainLight = new geLight("Light");
        _core->addLight(mainLight);
        */

        /*
        GraphicEngine::geCube* geCube = new GraphicEngine::geCube("Cube");
        _core->addNode(geCube);

        GraphicEngine::geImported* geAssimp = new GraphicEngine::geImported("Assimp");
        glm::mat4 model = geAssimp->getModelMatrix();
        model = glm::translate(model, glm::vec3(0.0, 1.0, 0.0));
        geAssimp->setModelMatrix(model);
        _core->addNode(geAssimp);
        */

        // TODO: Variable transform, deleting from geInterface

        m_ActiveScene = new Scene();

        Entity mainCamera = m_ActiveScene->CreateEntity("Main Camera");
        mainCamera.AddComponent<CameraComponent>();
        TransformComponent &cameraTransform = mainCamera.GetComponent<TransformComponent>();
        cameraTransform.Transform = glm::translate(cameraTransform.Transform, glm::vec3(0.0f, 0.0f, 10.0f));

        Entity cube = m_ActiveScene->CreateEntity("Cube");
        MeshComponent& cubeMesh = cube.AddComponent<MeshComponent>();
        cubeMesh.Mesh = Mesh("../Dependencies/models/cube.obj");

        MaterialComponent& material = cube.AddComponent<MaterialComponent>();
        material.Material = Material("Shaders/fwRendering.v1.vert", "Shaders/fwRendering.v1.frag");
        Texture* colorTexId = new Texture("../Dependencies/img/color.png", Texture::TextureType::DIFFUSE);
        material.Material.AddTexture(colorTexId);
        Texture* emiTexId = new Texture("../Dependencies/img/emissive.png", Texture::TextureType::EMISIVE);
        material.Material.AddTexture(emiTexId);

        Entity sphere = m_ActiveScene->CreateEntity("Sphere");
        MeshComponent& sphereMesh = sphere.AddComponent<MeshComponent>();
        sphereMesh.Mesh = Mesh("../Dependencies/models/FinalBaseMesh.obj");
        MaterialComponent& sphereMaterial = sphere.AddComponent<MaterialComponent>();
        sphereMaterial.Material = Material("Shaders/fwRendering.v1.vert", "Shaders/fwRendering.v1.frag");
        TransformComponent& sphereTransform = sphere.GetComponent<TransformComponent>();
        sphereTransform.Transform = glm::translate(sphereTransform.Transform, glm::vec3(3.0f, 3.0f, 0.0f));
        
        timer.start(12, this);
    }

    void RenderingWidget::resizeGL(int w, int h)
    {
        m_ActiveScene->OnViewResize(w, h);
        _core->resizeFunction(w, h);
    }

    void RenderingWidget::timerEvent(QTimerEvent* e)
    {
        m_ActiveScene->OnUpdate();
        update();
    }

    void RenderingWidget::paintGL()
    {
        
        makeCurrent();
        //_core->renderFunction();

        m_ActiveScene->OnRender();

        for (std::vector<Step*>::iterator it = m_Steps.begin(); it != m_Steps.end(); it++)
        {
            //(*it)->render(_Core->_geNodes, _Core->_mainCamera);
        }

        glUseProgram(NULL);
        //emit renderedImageSignal(_core->getWindowWidth(), _core->getWindowHeight());
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