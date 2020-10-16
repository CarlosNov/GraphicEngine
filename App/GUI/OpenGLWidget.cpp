#include "OpenGLWidget.h"
#include "qcoreapplication.h"

namespace GraphicEngine
{

    OpenGLWidget::OpenGLWidget(QWidget* parent) : QOpenGLWidget(parent)
    {
        QCoreApplication::instance()->installEventFilter(this);
    }

    OpenGLWidget::~OpenGLWidget()
    {
        makeCurrent();
        delete(_core);
        doneCurrent();
    }

    void OpenGLWidget::mousePressEvent(QMouseEvent* e)
    {

    }

    void OpenGLWidget::mouseReleaseEvent(QMouseEvent* e)
    {
       
    }

    void OpenGLWidget::initializeGL()
    {
        initializeOpenGLFunctions();
        _core->initGlew();

        glClearColor(0.2f, 0.2f, 0.2f, 0.0f);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_CULL_FACE);

        m_Steps.push_back(new GraphicEngine::Forward());
        m_Steps.push_back(new GraphicEngine::PostProcess());
        m_Steps.push_back(new App::QTCopy());

        m_Steps[1]->setColorBuffer(m_Steps[0]->getColorBuffer());
        m_Steps[1]->setDepthBuffer(m_Steps[0]->getDepthBuffer());
        m_Steps[1]->setVertexBuffer(m_Steps[0]->getVertexBuffer());
        m_Steps[2]->setColorBuffer(m_Steps[1]->getColorBuffer());
        m_Steps[2]->setDepthBuffer(m_Steps[1]->getDepthBuffer());
        m_Steps[2]->setVertexBuffer(m_Steps[1]->getVertexBuffer());

        _colorTex = m_Steps[0]->getColorBuffer();
        emit colorTexSignal(_colorTex);

        // TODO: Variable transform, deleting from geInterface

        m_ActiveScene = new Scene();

        m_ActiveScene->AddSteps(m_Steps);

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

        Entity sphere = m_ActiveScene->CreateEntity("Human Object");
        MeshComponent& sphereMesh = sphere.AddComponent<MeshComponent>();
        sphereMesh.Mesh = Mesh("../Dependencies/models/FinalBaseMesh.obj");
        MaterialComponent& sphereMaterial = sphere.AddComponent<MaterialComponent>();
        sphereMaterial.Material = Material("Shaders/fwRendering.v1.vert", "Shaders/fwRendering.v1.frag");
        TransformComponent& sphereTransform = sphere.GetComponent<TransformComponent>();
        sphereTransform.Transform = glm::translate(sphereTransform.Transform, glm::vec3(3.0f, 3.0f, 0.0f));

        emit SetHierarchyScene(m_ActiveScene);
        emit InitHierarchyDraw();
        
        timer.start(12, this);
    }

    void OpenGLWidget::resizeGL(int w, int h)
    {
        m_ActiveScene->OnViewResize(w, h);
    }

    void OpenGLWidget::timerEvent(QTimerEvent* e)
    {
        m_ActiveScene->OnUpdate();
        update();
    }

    void OpenGLWidget::paintGL()
    {
        
        makeCurrent();
        std::cout << defaultFramebufferObject();
        m_ActiveScene->OnRender();

        glUseProgram(NULL);
        emit renderedImageSignal(m_ActiveScene->GetViewWidth(), m_ActiveScene->GetViewHeight());
        doneCurrent();
    }

    void OpenGLWidget::initShaders()
    {

    }

    void OpenGLWidget::initTextures()
    {

    }

    GLuint OpenGLWidget::getColorTex()
    {
        return _colorTex;
    }

    void OpenGLWidget::activateGLContext()
    {
        makeCurrent();
    }

    void OpenGLWidget::deactivateGLContext()
    {
        doneCurrent();
    }

    bool OpenGLWidget::eventFilter(QObject* object, QEvent* e)
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