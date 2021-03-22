#include "OpenGLWidget.h"
#include "Renderer/Renderer.h"

#include <glm.hpp>
#include <QCoreApplication>

#include <IMGUI/QtImGui.h>
#include <IMGUI/imgui.h>
#include <IMGUI/implot.h>

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
        QtImGui::initialize(this);

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
        m_Steps.push_back(new Deferred());
        m_Steps.push_back(new PostProcess());
        m_Steps.push_back(new QTCopy());

        m_Steps[1]->setColorBuffer(m_Steps[0]->getColorBuffer());
        m_Steps[2]->setColorBuffer(m_Steps[1]->getColorBuffer());

        m_ActiveScene = new Scene();
        Renderer* renderer= m_ActiveScene->GetRenderer();
        renderer->AddMainStepsVector(m_Steps);

        Entity mainCamera = m_ActiveScene->CreateEntity("Main Camera");
        CameraComponent& cameraComponent = mainCamera.AddComponent<CameraComponent>();
        cameraComponent.MainCamera = true;
        TransformComponent &cameraTransform = mainCamera.GetComponent<TransformComponent>();
        cameraTransform.Translation.z = 10.0f;

        renderer->SetMainCamera(mainCamera);

        Entity light = m_ActiveScene->CreateEntity("Point Light");
        LightComponent& lightComponent = light.AddComponent<LightComponent>();
        lightComponent.Light.SetLightType(SceneLight::LightType::Point);
        TransformComponent& lightTransform = light.GetComponent<TransformComponent>();
        lightTransform.Translation.z = 10.0f;

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
        Texture* colorTexIdHuman = new Texture("../Dependencies/img/color.png", Texture::TextureType::DIFFUSE);
        sphereMaterial.Material.AddTexture(colorTexId);
        Texture* emiTexIdHuman = new Texture("../Dependencies/img/emissive.png", Texture::TextureType::EMISIVE);
        sphereMaterial.Material.AddTexture(emiTexId);

        TransformComponent& sphereTransform = sphere.GetComponent<TransformComponent>();
        sphereTransform.Translation.x = 3.0f;

        emit SetHierarchyScene(m_ActiveScene);
        emit InitHierarchy();
        
        timer.start(16, this);
    }

    void OpenGLWidget::resizeGL(int w, int h)
    {
        m_ActiveScene->OnViewResize(w, h);
        emit SetCameraTextureSize(w, h);
    }

    void OpenGLWidget::timerEvent(QTimerEvent* e)
    {
        m_ActiveScene->OnUpdate();
        emit UpdateUI();
        update();
    }

    void OpenGLWidget::paintGL()
    {   
        bool show_imgui_demo_window = true;
        bool show_implot_demo_window = false;
        ImVec4 clear_color = ImColor(114, 144, 154);

        makeCurrent();
        //m_ActiveScene->OnRender();
        QtImGui::newFrame();

        ImGui::ShowDemoWindow(&show_imgui_demo_window);
        ImGui::Render();
        QtImGui::render();
        glUseProgram(NULL);
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

            Renderer* renderer = m_ActiveScene->GetRenderer();
            Entity MainCamera = renderer->GetMainCamera();
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

            Renderer* renderer = m_ActiveScene->GetRenderer();
            Entity MainCamera = renderer->GetMainCamera();
            auto& transform = MainCamera.GetComponent<TransformComponent>();
            glm::mat4 cameraView = glm::inverse(transform.GetTransform());
            glm::vec3 lookAtVector = glm::vec3(-cameraView[0][2], -cameraView[1][2], -cameraView[2][2]);
            glm::vec3 upVector = glm::vec3(cameraView[0][1], cameraView[1][1], -cameraView[2][1]);
            glm::vec3 vector = glm::normalize(glm::cross(lookAtVector, glm::vec3(0,1,0)));

            std::cout << "Rotation: (" << glm::degrees(transform.Rotation.x) << ", " << transform.Rotation.y << ", " << glm::degrees(transform.Rotation.z) << ")" << std::endl;
            std::cout << "LookAt: (" << lookAtVector.x << ", " << lookAtVector.y << ", " << lookAtVector.z << ")" << std::endl;
            std::cout << "Vector: (" << vector.x << ", " << vector.y << ", " << vector.z << ")" << std::endl;
            std::cout << "Up: (" << upVector.x << ", " << upVector.y << ", " << upVector.z << ")" << std::endl;
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
            Renderer* renderer = m_ActiveScene->GetRenderer();
            Entity MainCamera = renderer->GetMainCamera();
            auto& transform = MainCamera.GetComponent<TransformComponent>();
            glm::mat4 cameraView = glm::inverse(transform.GetTransform());
            glm::vec3 lookAtVector = glm::vec3(cameraView[0][2], cameraView[1][2], cameraView[2][2]);
            transform.Translation += lookAtVector * 2.0f;
        }
        else
        {
            Renderer* renderer = m_ActiveScene->GetRenderer();
            Entity MainCamera = renderer->GetMainCamera();
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
            Renderer* renderer = m_ActiveScene->GetRenderer();
            Entity MainCamera = renderer->GetMainCamera();
            auto& transform = MainCamera.GetComponent<TransformComponent>();
            glm::mat4 cameraView = glm::inverse(transform.GetTransform());
            glm::vec3 lookAtVector = glm::vec3(cameraView[0][2], cameraView[1][2], cameraView[2][2]);
            transform.Translation -= lookAtVector * 0.2f;
        }

        if (e == Qt::Key_S)
        {
            Renderer* renderer = m_ActiveScene->GetRenderer();
            Entity MainCamera = renderer->GetMainCamera();
            auto& transform = MainCamera.GetComponent<TransformComponent>();
            glm::mat4 cameraView = glm::inverse(transform.GetTransform());
            glm::vec3 lookAtVector = glm::vec3(cameraView[0][2], cameraView[1][2], cameraView[2][2]);
            transform.Translation += lookAtVector * 0.2f;
        }

        if (e == Qt::Key_A)
        {
            Renderer* renderer = m_ActiveScene->GetRenderer();
            Entity MainCamera = renderer->GetMainCamera();
            auto& transform = MainCamera.GetComponent<TransformComponent>();
            glm::mat4 cameraView = glm::inverse(transform.GetTransform());
            glm::vec3 rightVector = glm::vec3(cameraView[0][0], cameraView[1][0], cameraView[2][0]);
            transform.Translation -= rightVector * 0.2f;
        }

        if (e == Qt::Key_D)
        {
            Renderer* renderer = m_ActiveScene->GetRenderer();
            Entity MainCamera = renderer->GetMainCamera();
            auto& transform = MainCamera.GetComponent<TransformComponent>();
            glm::mat4 cameraView = glm::inverse(transform.GetTransform());
            glm::vec3 rightVector = glm::vec3(cameraView[0][0], cameraView[1][0], cameraView[2][0]);
            transform.Translation += rightVector * 0.2f;
        }
    }
}