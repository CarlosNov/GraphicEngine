#pragma once

#include "config.h"
#include "GraphicEngine.h"

namespace GraphicEngine
{
    class SceneWindow
    {
    public:
        SceneWindow();
        ~SceneWindow();

        Scene* GetScene() { return m_ActiveScene; }
        void SetScene(Scene* scene) { m_ActiveScene = scene; }

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

    private:
        Scene* m_ActiveScene;
        uint32_t m_RenderTextureID;

        glm::vec2 m_ViewportSize;
    };
}

