#include "HierarchyPanel.h"
#include "GUI/GUIFunctions.h"
#include "GUI/TreeWidgetItem.h"
#include "GUI/ItemDelegate.h"
#include "Renderer/Renderer.h"

#include <QLineEdit>
#include <QAction>
#include <QMenu>

namespace GraphicEngine
{
    HierarchyPanel::HierarchyPanel(QWidget* parent) : QTreeWidget(parent)
    {
        m_CurrentItem = nullptr;
        m_CurrentScene = nullptr;

        setObjectName(QStringLiteral("HierarchyPanel"));
        setStyleSheet(GUIFunctions::GetStyle(":/Styles/Styles/HierarchyPanelStyle.qss"));
        setAutoScrollMargin(16);
        setDragEnabled(true);
        setDragDropOverwriteMode(true);
        setDragDropMode(QAbstractItemView::DragDrop);
        setDefaultDropAction(Qt::MoveAction);
        setIndentation(25);
        setAnimated(false);
        setColumnCount(1);

        ItemDelegate* m_ItemDelegate = new ItemDelegate(this);
        setItemDelegate(m_ItemDelegate);

        setContextMenuPolicy(Qt::CustomContextMenu);

        QObject::connect(this, &HierarchyPanel::customContextMenuRequested, this, &HierarchyPanel::InitMenu);
        QObject::connect(this, &GraphicEngine::HierarchyPanel::itemClicked, this, &GraphicEngine::HierarchyPanel::ItemClicked);
    }

    void HierarchyPanel::AddEntityToHierarchy(Entity entity)
    {
        auto& tag = entity.GetComponent<TagComponent>().Tag;

        TreeWidgetItem* tempItem = new TreeWidgetItem();
        tempItem->setFlags(tempItem->flags() | Qt::ItemIsEditable);
        tempItem->SetEntity(entity);
        tempItem->setText(0, QString::fromStdString(tag));

        m_CurrentItem = tempItem;
        insertTopLevelItem(0, tempItem);
    }

    /* SLOTS */

    void HierarchyPanel::SetScene(Scene* scene)
    {
        m_CurrentScene = scene;
    }

    void HierarchyPanel::InitHierarchy()
    {
        m_CurrentScene->m_Registry.each([&](auto id)
            {
                Entity entity{ id , m_CurrentScene };
                AddEntityToHierarchy(entity);
            });
    }

    void HierarchyPanel::InitMenu(const QPoint& pos)
    {
        QTreeWidgetItem* qtItem = itemAt(pos);
        TreeWidgetItem* treeWidgetItem = dynamic_cast <TreeWidgetItem*>(qtItem);

        QMenu menu(this);

        /* TREE ITEM WIDGET*/
        if (treeWidgetItem)
        {
            m_CurrentItem = treeWidgetItem;

            QAction* treeItemAction = new QAction(tr("&Delete Entity"), this);
            connect(treeItemAction, &QAction::triggered, this, &HierarchyPanel::DeleteEntity);
            menu.addAction(treeItemAction);
            menu.exec(mapToGlobal(pos));
            return;
        }

        /* TREE WIDGET */
        QAction* treeItemAction = new QAction(tr("&Create new entity"), this);
        connect(treeItemAction, &QAction::triggered, this, &HierarchyPanel::CreateEntity);
        menu.addAction(treeItemAction);
        menu.exec(mapToGlobal(pos));
    }

    void HierarchyPanel::ItemClicked(QTreeWidgetItem* clicked, int column)
    {
        TreeWidgetItem* item = dynamic_cast <TreeWidgetItem*>(clicked);

        if (item)
        {
            m_CurrentItem = item;
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
        //TODO : Exception
        if (!m_CurrentItem)
            return;
                      
        Entity& entity = m_CurrentItem->GetEntity();
            
        //TODO : Exception
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

        if (m_CurrentScene)
        {
            emit SetCameraTexture(m_CurrentScene->GetCameraTexture());
            emit SetCameraTextureSize(m_CurrentScene->GetViewWidth(), m_CurrentScene->GetViewHeight());
        }
    }
}