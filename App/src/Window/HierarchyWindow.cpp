#include "HierarchyWindow.h"

#include "Renderer/Renderer.h"
#include "IMGUI/imgui.h"

namespace GraphicEngine
{
    HierarchyWindow::HierarchyWindow()
    {
        m_ActiveScene = nullptr;
        m_SelectedEntity = {};
    }

    HierarchyWindow::~HierarchyWindow()
    {

    }

    void HierarchyWindow::OnInit()
    {

    }

    void HierarchyWindow::OnUpdate()
    {

    }

    void HierarchyWindow::OnRender()
    {
        ImGui::Begin("Hierarchy");

        m_ActiveScene->m_Registry.each([&](auto id)
            {
                Entity entity{ id , m_ActiveScene };
                DrawEntity(entity);
            });

        if (ImGui::IsMouseDown(0) && ImGui::IsWindowHovered())
            m_SelectedEntity = {};

        if (ImGui::BeginPopupContextWindow(0, ImGuiPopupFlags_MouseButtonRight  | ImGuiPopupFlags_NoOpenOverItems))
        {
            if (ImGui::MenuItem("Create Empty Entity"))
                m_ActiveScene->CreateEntity("Empty Entity");

            ImGui::EndPopup();
        }
        ImGui::End();     

        if (m_SelectedEntity)
        {
            EntityClicked(m_SelectedEntity);
        }
    }

    void HierarchyWindow::DrawEntity(Entity entity)
    {
        auto& tag = entity.GetComponent<TagComponent>().Tag;

        ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick | ImGuiTreeNodeFlags_SpanAvailWidth;

        if (m_SelectedEntity == entity)
        {
            flags |= ImGuiTreeNodeFlags_Selected;
        }

        bool opened = ImGui::TreeNodeEx((void*)(uint64_t)(uint32_t)entity, flags, tag.c_str());

        if (ImGui::IsItemClicked())
        {
            m_SelectedEntity = entity;
        }

        bool entityDeleted = false;
        if (ImGui::BeginPopupContextItem())
        {
            if (ImGui::MenuItem("Delete Entity"))
                entityDeleted = true;

            ImGui::EndPopup();
        }

        if (opened)
        {
            ImGui::TreePop();
        }

        if (entityDeleted)
        {
            m_ActiveScene->DestroyEntity(entity);
            if (m_SelectedEntity == entity)
                m_SelectedEntity = {};
        }
    }

    /*
    void HierarchyPanel::ItemClicked(QTreeWidgetItem* clicked, int column)
    {
        /*
        TreeWidgetItem* item = dynamic_cast <TreeWidgetItem*>(clicked);

        if (item)
        {
            m_CurrentItem = item;
        }

        if (!m_CurrentItem)
            return;

        Entity& entity = m_CurrentItem->GetEntity();

        if (entity)
        {
            if (entity.HasComponent<TagComponent>())
            {
                emit SetTagPanelVisible(true);
                emit SetAddComponentButtonVisible(true);

                auto& tag = entity.GetComponent<TagComponent>();
                m_CurrentItem->setText(0, QString::fromStdString(tag.Tag));
                emit SetTag(&tag);
                emit SetID(entity.GetEntityID());
            }
            else
            {
                emit SetTagPanelVisible(false);
                emit SetAddComponentButtonVisible(false);
            }

            if (entity.HasComponent<TransformComponent>())
            {
                emit SetTransformPanelVisible(true);

                auto& transform = entity.GetComponent<TransformComponent>();
                emit SetTransform(&transform);
            }
            else
            {
                emit SetTransformPanelVisible(false);
            }

            if (entity.HasComponent<CameraComponent>())
            {
                emit SetCameraPanelVisible(true);

                auto& camera = entity.GetComponent<CameraComponent>();
                emit SetCamera(&camera);
            }
            else
            {
                emit SetCameraPanelVisible(false);
            }

            if (entity.HasComponent<MeshComponent>())
            {
                emit SetMeshPanelVisible(true);

                auto& mesh = entity.GetComponent<MeshComponent>();
                emit SetMesh(&mesh);
            }
            else
            {
                emit SetMeshPanelVisible(false);
            }

            if (entity.HasComponent<LightComponent>())
            {
                emit SetLightPanelVisible(true);

                auto& light = entity.GetComponent<LightComponent>();
                emit SetLight(&light);
            }
            else
            {
                emit SetLightPanelVisible(false);
            }
        }
        
    }

    void HierarchyPanel::ItemFinishedEditing()
    {
        //TODO : Exception
        if (!m_CurrentItem)
            return;

        Entity& entity = m_CurrentItem->GetEntity();

        //TODO : Exception
        if (!entity)
            return;

        if (entity.HasComponent<TagComponent>())
        {
            auto& tag = entity.GetComponent<TagComponent>().Tag;
            tag = m_CurrentItem->text(0).toStdString();
        }
    }

    void HierarchyPanel::CreateEntity()
    {
        if (m_CurrentScene)
        {
            Entity entity = m_CurrentScene->CreateEntity("Empty Entity");

            AddEntityToHierarchy(entity);
            this->clearSelection();
            this->setItemSelected(m_CurrentItem, true);
        }
    }

    void HierarchyPanel::DeleteEntity()
    {
        if (m_CurrentScene && m_CurrentItem)
        {
            m_CurrentScene->DestroyEntity(m_CurrentItem->GetEntity());

            this->removeItemWidget(m_CurrentItem, 0);
            this->setCurrentItem(nullptr);

            delete m_CurrentItem;
            m_CurrentItem = nullptr;

            emit SetTagPanelVisible(false);
            emit SetTransformPanelVisible(false);
            emit SetCameraPanelVisible(false);
            emit SetMeshPanelVisible(false);
            emit SetLightPanelVisible(false);
            emit SetAddComponentButtonVisible(false);
        }
    }

    void HierarchyPanel::AddTransformComponent()
    {
        //TODO : Exception
        if (!m_CurrentItem)
            return;

        Entity& entity = m_CurrentItem->GetEntity();

        //TODO : Exception
        if (entity)
            if (!entity.HasComponent<TransformComponent>())
                entity.AddComponent<TransformComponent>();
    }

    void HierarchyPanel::RemoveTransformComponent()
    {
        //TODO : Exception
        if (!m_CurrentItem)
            return;

        Entity& entity = m_CurrentItem->GetEntity();

        //TODO : Exception
        if (entity)
            if (entity.HasComponent<TransformComponent>())
                entity.RemoveComponent<TransformComponent>();
    }

    void  HierarchyPanel::AddCameraComponent()
    {
        //TODO : Exception
        if (!m_CurrentItem)
            return;

        Entity& entity = m_CurrentItem->GetEntity();

        //TODO : Exception
        if (entity)
            if (!entity.HasComponent<CameraComponent>())
            {
                CameraComponent& camera = entity.AddComponent<CameraComponent>();
                camera.Camera.InitCameraProjection();
            }

    }

    void  HierarchyPanel::RemoveCameraComponent()
    {
        //TODO : Exception
        if (!m_CurrentItem)
            return;

        Entity& entity = m_CurrentItem->GetEntity();

        //TODO : Exception
        if (entity)
            if (entity.HasComponent<CameraComponent>())
                entity.RemoveComponent<CameraComponent>();
    }

    void  HierarchyPanel::AddMeshComponent()
    {
        //TODO : Exception
        if (!m_CurrentItem)
            return;

        Entity& entity = m_CurrentItem->GetEntity();

        //TODO : Exception
        if (entity)
            if (!entity.HasComponent<MeshComponent>())
                entity.AddComponent<MeshComponent>();
    }

    void  HierarchyPanel::RemoveMeshComponent()
    {
        //TODO : Exception
        if (!m_CurrentItem)
            return;

        Entity& entity = m_CurrentItem->GetEntity();

        //TODO : Exception
        if (entity)
            if (entity.HasComponent<MeshComponent>())
                entity.RemoveComponent<MeshComponent>();
    }

    void  HierarchyPanel::AddLightComponent()
    {
        //TODO : Exception
        if (!m_CurrentItem)
            return;

        Entity& entity = m_CurrentItem->GetEntity();

        //TODO : Exception
        if (entity)
            if (!entity.HasComponent<LightComponent>())
                entity.AddComponent<LightComponent>();
    }

    void  HierarchyPanel::RemoveLightComponent()
    {
        //TODO : Exception
        if (!m_CurrentItem)
            return;

        Entity& entity = m_CurrentItem->GetEntity();

        //TODO : Exception
        if (entity)
            if (entity.HasComponent<LightComponent>())
                entity.RemoveComponent<LightComponent>();
    }

    void HierarchyPanel::GetCameras()
    {
        QStringList list = {};

        if (m_CurrentScene)
        {
            auto view = m_CurrentScene->m_Registry.view<TagComponent, CameraComponent>();
            for (auto entity : view)
            {
                auto [tag, camera] = view.get<TagComponent, CameraComponent>(entity);
                list.append(QString::fromUtf8(tag.Tag.c_str()));
            }
        }
        emit SetCameraList(list);
    }

    void HierarchyPanel::SetSelectedCamera(QString cameraTag)
    {
        if (m_CurrentScene)
        {
            auto view = m_CurrentScene->m_Registry.view<TagComponent, CameraComponent>();
            for (auto id : view)
            {
                auto [tag, camera] = view.get<TagComponent, CameraComponent>(id);

                if (!QString::compare(cameraTag, QString::fromUtf8(tag.Tag.c_str()), Qt::CaseInsensitive))
                {
                    Entity entity{ id , m_CurrentScene };
                    Renderer* renderer = m_CurrentScene->GetRenderer();
                    renderer->SetSelectedCamera(entity);
                }
            }
        }
    }

    void HierarchyPanel::UpdateUI()
    {
        if (m_CurrentScene)
        {
            emit SetCameraTexture(m_CurrentScene->GetCameraTexture());
        }
    }
    */
}
