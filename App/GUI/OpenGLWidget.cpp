#include "OpenGLWidget.h"
#include "qcoreapplication.h"
#include <glm.hpp>

namespace GraphicEngine
{

    OpenGLWidget::OpenGLWidget(QWidget* parent) : QOpenGLWidget(parent)
    {
    }

    OpenGLWidget::~OpenGLWidget()
    {
       
    }

    void OpenGLWidget::initializeGL()
    {
        initializeOpenGLFunctions();

        glewExperimental = GL_TRUE;
        GLenum err = glewInit();
        if (GLEW_OK != err)
        {
            std::cout << "Error: " << glewGetErrorString(err) << std::endl;
            exit(-1);
        }
        const GLubyte* oglVersion = glGetString(GL_VERSION);
        std::cout << "This system supports OpenGL Version: " << oglVersion << std::endl;

        glClearColor(0.2f, 0.2f, 0.2f, 0.0f);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_CULL_FACE);

        //m_Steps.push_back(new GraphicEngine::Forward());
        m_Steps.push_back(new GraphicEngine::Deferred());
        m_Steps.push_back(new GraphicEngine::PostProcess());
        //m_Steps.push_back(new App::QTCopy());

        m_Steps[1]->setColorBuffer(m_Steps[0]->getColorBuffer());
        //m_Steps[1]->setDepthBuffer(m_Steps[0]->getDepthBuffer());
        //m_Steps[1]->setVertexBuffer(m_Steps[0]->getVertexBuffer());
        //m_Steps[2]->setColorBuffer(m_Steps[1]->getColorBuffer());
        //m_Steps[2]->setDepthBuffer(m_Steps[1]->getDepthBuffer());
        //m_Steps[2]->setVertexBuffer(m_Steps[1]->getVertexBuffer());

        _colorTex = m_Steps[0]->getColorBuffer();
        emit colorTexSignal(_colorTex);

        // TODO: Variable transform, deleting from geInterface

        m_ActiveScene = new Scene();

        m_ActiveScene->AddSteps(m_Steps);

        Entity mainCamera = m_ActiveScene->CreateEntity("Main Camera");
        CameraComponent& cameraComponent = mainCamera.AddComponent<CameraComponent>();
        cameraComponent.MainCamera = true;
        TransformComponent &cameraTransform = mainCamera.GetComponent<TransformComponent>();
        cameraTransform.Translation.z = 10.0f;

        Entity cube = m_ActiveScene->CreateEntity("Cube");
        MeshComponent& cubeMesh = cube.AddComponent<MeshComponent>();
        cubeMesh.Mesh = Mesh("../Dependencies/models/cube.obj");
        cubeMesh.FileName = "Cube.obj";

        MaterialComponent& material = cube.AddComponent<MaterialComponent>();
        //material.Material = Material("Shaders/fwRendering.v1.vert", "Shaders/fwRendering.v1.frag");
        material.Material = Material("Shaders/gBuffer.vert", "Shaders/gBuffer.frag");
        Texture* colorTexId = new Texture("../Dependencies/img/color.png", Texture::TextureType::DIFFUSE);
        material.Material.AddTexture(colorTexId);
        Texture* emiTexId = new Texture("../Dependencies/img/emissive.png", Texture::TextureType::EMISIVE);
        material.Material.AddTexture(emiTexId);

        Entity sphere = m_ActiveScene->CreateEntity("Human Object");
        MeshComponent& sphereMesh = sphere.AddComponent<MeshComponent>();
        sphereMesh.Mesh = Mesh("../Dependencies/models/FinalBaseMesh.obj");
        sphereMesh.FileName = "FinalBaseMesh.obj";
        MaterialComponent& sphereMaterial = sphere.AddComponent<MaterialComponent>();
        //sphereMaterial.Material = Material("Shaders/fwRendering.v1.vert", "Shaders/fwRendering.v1.frag");
        sphereMaterial.Material = Material("Shaders/gBuffer.vert", "Shaders/gBuffer.frag");
        TransformComponent& sphereTransform = sphere.GetComponent<TransformComponent>();
        sphereTransform.Translation.x = 3.0f;

        emit SetHierarchyScene(m_ActiveScene);
        emit InitHierarchy();
        
        timer.start(12, this);
    }

    void OpenGLWidget::resizeGL(int w, int h)
    {
        m_ActiveScene->OnViewResize(w, h);
    }

    void OpenGLWidget::timerEvent(QTimerEvent* e)
    {
        m_ActiveScene->OnUpdate();
        emit UpdateUI();
        update();
    }

    void OpenGLWidget::paintGL()
    {       
        makeCurrent();
        //std::cout << defaultFramebufferObject();
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

    void OpenGLWidget::keyPressEvent(QKeyEvent* e)
    {
        m_bFirstRelease = true;
        keysPressed.insert((Qt::Key) e->key());
    }

    void OpenGLWidget::keyReleaseEvent(QKeyEvent* e)
    {
        if (m_bFirstRelease) 
        {
            for (auto key : keysPressed)
            {
                processKeyEvent(key);
            }
        }

        m_bFirstRelease = false;
        keysPressed.remove((Qt::Key) e->key());
    }

    void OpenGLWidget::mousePressEvent(QMouseEvent* e)
    {
        if (e->button() == Qt::MidButton)
        {
            lastX = e->pos().x();
            lastY = e->pos().y();
            m_MidButtonPressed = true;
            this->setCursor(Qt::ClosedHandCursor);
        }

        if (e->button() == Qt::RightButton)
        {
            lastX = e->pos().x();
            lastY = e->pos().y();
            m_RightButtonPressed = true;
            yaw = 0.0;
            pitch = 0.0;
            this->setCursor(Qt::ClosedHandCursor);
        }
    }

    void OpenGLWidget::mouseMoveEvent(QMouseEvent* e)
    {
        if (m_MidButtonPressed)
        {
            float xoffset = e->pos().x() - lastX;
            float yoffset = lastY - e->pos().y();
            lastX = e->pos().x();
            lastY = e->pos().y();

            Entity MainCamera = m_ActiveScene->GetMainCamera();
            auto& transform = MainCamera.GetComponent<TransformComponent>();
            glm::mat4 cameraView = glm::inverse(transform.GetTransform());
            glm::vec3 rightVector = glm::vec3(cameraView[0][0], cameraView[1][0], cameraView[2][0]);
            glm::vec3 upVector = glm::vec3(cameraView[0][1], cameraView[1][1], cameraView[2][1]);

            transform.Translation -= upVector * 0.1f * yoffset;
            transform.Translation -= rightVector * 0.1f * xoffset;
        }

        if (m_RightButtonPressed)
        {
            double xoffset = e->pos().x() - lastX;
            double yoffset = lastY - e->pos().y();
            lastX = e->pos().x();
            lastY = e->pos().y();

            Entity MainCamera = m_ActiveScene->GetMainCamera();
            auto& transform = MainCamera.GetComponent<TransformComponent>();
            glm::mat4 cameraView = glm::inverse(transform.GetTransform());
            glm::vec3 lookAtVector = glm::vec3(-cameraView[0][2], -cameraView[1][2], -cameraView[2][2]);
            glm::vec3 upVector = glm::vec3(cameraView[0][1], cameraView[1][1], -cameraView[2][1]);
            glm::vec3 vector = glm::normalize(glm::cross(lookAtVector, glm::vec3(0,1,0)));

            std::cout << "Rotation: (" << glm::degrees(transform.Rotation.x) << ", " << transform.Rotation.y << ", " << glm::degrees(transform.Rotation.z) << ")" << std::endl;
            std::cout << "LookAt: (" << lookAtVector.x << ", " << lookAtVector.y << ", " << lookAtVector.z << ")" << std::endl;
            std::cout << "Vector: (" << vector.x << ", " << vector.y << ", " << vector.z << ")" << std::endl;
            std::cout << "Up: (" << upVector.x << ", " << upVector.y << ", " << upVector.z << ")" << std::endl;

            //glm::rotate(transform.GetTransform(), yoffset, glm::vec3(1, 0, 0))

            //transform.SetTransform();

            //transform.Rotation.x += glm::radians(glm::sin(angle) * yoffset);
            //transform.Rotation.y -= glm::radians(xoffset);
            //transform.Rotation.z += glm::radians(glm::cos(angle) * yoffset);
        }
    }

    void OpenGLWidget::mouseReleaseEvent(QMouseEvent* e)
    {
        if (e->button() == Qt::MidButton)
        {
            m_MidButtonPressed = false;
            this->setCursor(Qt::ArrowCursor);
        }

        if (e->button() == Qt::RightButton)
        {
            m_RightButtonPressed = false;
            this->setCursor(Qt::ArrowCursor);
        }      
    }

    void OpenGLWidget::wheelEvent(QWheelEvent* e)
    {
        QPoint numDegrees = e->angleDelta();

        if (numDegrees.y() <= 0)
        {
            Entity MainCamera = m_ActiveScene->GetMainCamera();
            auto& transform = MainCamera.GetComponent<TransformComponent>();
            glm::mat4 cameraView = glm::inverse(transform.GetTransform());
            glm::vec3 lookAtVector = glm::vec3(cameraView[0][2], cameraView[1][2], cameraView[2][2]);
            transform.Translation += lookAtVector * 2.0f;
        }
        else
        {
            Entity MainCamera = m_ActiveScene->GetMainCamera();
            auto& transform = MainCamera.GetComponent<TransformComponent>();
            glm::mat4 cameraView = glm::inverse(transform.GetTransform());
            glm::vec3 lookAtVector = glm::vec3(cameraView[0][2], cameraView[1][2], cameraView[2][2]);
            transform.Translation -= lookAtVector * 2.0f;
        }
    }

    void OpenGLWidget::processKeyEvent(Qt::Key e)
    {
        if (e == Qt::Key_W)
        {
            Entity MainCamera = m_ActiveScene->GetMainCamera();
            auto& transform = MainCamera.GetComponent<TransformComponent>();
            glm::mat4 cameraView = glm::inverse(transform.GetTransform());
            glm::vec3 lookAtVector = glm::vec3(cameraView[0][2], cameraView[1][2], cameraView[2][2]);
            transform.Translation -= lookAtVector * 0.2f;
        }

        if (e == Qt::Key_S)
        {
            Entity MainCamera = m_ActiveScene->GetMainCamera();
            auto& transform = MainCamera.GetComponent<TransformComponent>();
            glm::mat4 cameraView = glm::inverse(transform.GetTransform());
            glm::vec3 lookAtVector = glm::vec3(cameraView[0][2], cameraView[1][2], cameraView[2][2]);
            transform.Translation += lookAtVector * 0.2f;
        }

        if (e == Qt::Key_A)
        {
            Entity MainCamera = m_ActiveScene->GetMainCamera();
            auto& transform = MainCamera.GetComponent<TransformComponent>();
            glm::mat4 cameraView = glm::inverse(transform.GetTransform());
            glm::vec3 rightVector = glm::vec3(cameraView[0][0], cameraView[1][0], cameraView[2][0]);
            transform.Translation -= rightVector * 0.2f;
        }

        if (e == Qt::Key_D)
        {
            Entity MainCamera = m_ActiveScene->GetMainCamera();
            auto& transform = MainCamera.GetComponent<TransformComponent>();
            glm::mat4 cameraView = glm::inverse(transform.GetTransform());
            glm::vec3 rightVector = glm::vec3(cameraView[0][0], cameraView[1][0], cameraView[2][0]);
            transform.Translation += rightVector * 0.2f;
        }
    }
}