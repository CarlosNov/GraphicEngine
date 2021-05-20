#pragma once

#include "config.h"
#include "Scene/Scene.h"
#include <SIGSLOT/signal.hpp>

namespace GraphicEngine
{
    class SceneWindow
    {
    public:
        SceneWindow();
        ~SceneWindow();

        std::shared_ptr<Scene> GetScene() { return m_ActiveScene; }
        void SetScene(std::shared_ptr<Scene> scene) { m_ActiveScene = scene; }

    /*
    signals:
        void SetHierarchyScene(Scene* scene);
        void SetCameraTextureSize(unsigned int width, unsigned int height);
        void InitHierarchy();
        void AddEntityToHierarchy();
        void UpdateUI();
    */

        void OnInit();
        void OnUpdate();
        void OnRender();
        void OnResize(int32_t width, int32_t height);

    public:
        void OpenScene(std::string filepath);
        void SaveScene(std::string filepath);

        sigslot::signal<std::shared_ptr<Scene>> SetHierarchyContext;

    private:
        std::shared_ptr<Scene> m_ActiveScene;
        uint32_t m_RenderTextureID;

        glm::vec2 m_ViewportSize;
    };
}

