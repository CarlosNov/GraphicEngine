#include "SceneWindow.h"

#include "IMGUI/imgui.h"

namespace GraphicEngine
{
	SceneWindow::SceneWindow()
	{

	}

	SceneWindow::~SceneWindow()
	{

	}

	void SceneWindow::OnInit()
	{
        
        std::vector<Step*> m_Steps;

        m_Steps.push_back(new Deferred());
        m_Steps.push_back(new PostProcess());

        m_Steps[1]->setColorBuffer(m_Steps[0]->getColorBuffer());

        m_RenderTextureID = m_Steps[1]->getColorBuffer();

        m_ActiveScene = new Scene();
        Renderer* renderer = m_ActiveScene->GetRenderer();
        renderer->AddMainStepsVector(m_Steps);
        
        Entity mainCamera = m_ActiveScene->CreateEntity("Main Camera");
        CameraComponent& cameraComponent = mainCamera.AddComponent<CameraComponent>();
        cameraComponent.MainCamera = true;
        TransformComponent& cameraTransform = mainCamera.GetComponent<TransformComponent>();
        cameraTransform.Translation.z = 10.0f;
        
        m_ActiveScene->GetRenderer()->SetMainCamera(mainCamera);
        m_ActiveScene->GetRenderer()->SetSelectedCamera(mainCamera);
        
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
        material.Material = Material("shaders/gBuffer.vert", "shaders/gBuffer.frag");
        Texture* colorTexId = new Texture("../Dependencies/img/color.png", Texture::TextureType::DIFFUSE);
        material.Material.AddTexture(colorTexId);
        Texture* emiTexId = new Texture("../Dependencies/img/emissive.png", Texture::TextureType::EMISIVE);
        material.Material.AddTexture(emiTexId);

        Entity sphere = m_ActiveScene->CreateEntity("Human Object");
        MeshComponent& sphereMesh = sphere.AddComponent<MeshComponent>();
        sphereMesh.Mesh = Mesh("../Dependencies/models/FinalBaseMesh.obj");
        sphereMesh.FileName = "FinalBaseMesh.obj";

        MaterialComponent& sphereMaterial = sphere.AddComponent<MaterialComponent>();
        sphereMaterial.Material = Material("shaders/gBuffer.vert", "shaders/gBuffer.frag");
        Texture* colorTexIdHuman = new Texture("../Dependencies/img/color.png", Texture::TextureType::DIFFUSE);
        sphereMaterial.Material.AddTexture(colorTexId);
        Texture* emiTexIdHuman = new Texture("../Dependencies/img/emissive.png", Texture::TextureType::EMISIVE);
        sphereMaterial.Material.AddTexture(emiTexId);
        
        TransformComponent& sphereTransform = sphere.GetComponent<TransformComponent>();
        sphereTransform.Translation.x = 3.0f;
	}

	void SceneWindow::OnUpdate()
	{        
        m_ActiveScene->OnUpdate();
	}

	void SceneWindow::OnRender()
	{  
		ImGui::Begin("Scene");

		ImVec2 viewportPanelSize = ImGui::GetContentRegionAvail();
        m_ViewportSize = { viewportPanelSize.x, viewportPanelSize.y };

        m_ActiveScene->OnRender();

		ImGui::Image(reinterpret_cast<void*>(m_RenderTextureID), ImVec2{ m_ViewportSize.x, m_ViewportSize.y }, ImVec2{ 0, 1 }, ImVec2{ 1, 0 });

		ImGui::End();
	}

    void SceneWindow::OnResize(int32_t width, int32_t height)
    {
        m_ViewportSize.x = width;
        m_ViewportSize.y = height;
        m_ActiveScene->OnViewResize(width, height);
    }
}