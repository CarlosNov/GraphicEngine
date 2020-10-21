
#include "HierarchyPanel.h"
#include "GUI/GUIFunctions.h"
#include "GUI/TreeWidgetItem.h"
#include "GUI/ItemDelegate.h"

#include <QLineEdit>

namespace GraphicEngine
{
    HierarchyPanel::HierarchyPanel(QWidget* parent) : QTreeWidget(parent)
    {
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

        QObject::connect(this, &GraphicEngine::HierarchyPanel::itemClicked, this, &GraphicEngine::HierarchyPanel::ItemClicked);
    }

    void HierarchyPanel::AddEntityToHierarchy(Entity entity)
    {
        auto& tag = entity.GetComponent<TagComponent>().Tag;

        TreeWidgetItem* tempItem = new TreeWidgetItem();

        m_CurrentItem = tempItem;

        tempItem->setFlags(tempItem->flags() | Qt::ItemIsEditable);
        tempItem->SetEntity(entity);
        tempItem->setText(0, QString::fromStdString(tag));
        insertTopLevelItem(0, tempItem);
    }

    void HierarchyPanel::AddComponentsToInspector(Entity entity)
    {
        if (entity)
        {
            if (entity.HasComponent<TagComponent>())
            {
                auto& tag = entity.GetComponent<TagComponent>();
                emit SetTag(&tag);
                emit SetID(entity.GetEntityID());
            }

            if (entity.HasComponent<TransformComponent>())
            {
                auto& transform = entity.GetComponent<TransformComponent>();
                emit SetTransform(&transform);
            }

            if (entity.HasComponent<CameraComponent>())
            {
                auto& camera = entity.GetComponent<CameraComponent>();
                emit SetCamera(&camera);
            }
        }
    }

    void HierarchyPanel::ResetUI(Entity entity)
    {
        emit DestroyPanels();

        if (entity.HasComponent<TagComponent>())
        {
            emit CreateTagPanel();
        }

        if (entity.HasComponent<TransformComponent>())
        {
            emit CreateTransformPanel();
        }

        if (entity.HasComponent<CameraComponent>())
        {
            emit CreateCameraPanel();
        }
    }

    /* SLOTS */

    void HierarchyPanel::SetScene(Scene* scene)
    {
        m_CurrentScene = scene;
    }

    void HierarchyPanel::InitHierarchyDraw()
    {
        m_CurrentScene->m_Registry.each([&](auto id)
            {
                Entity entity{ id , m_CurrentScene };
                AddEntityToHierarchy(entity);
            });
    }

    void HierarchyPanel::ItemClicked(QTreeWidgetItem* clicked, int column)
    {
        TreeWidgetItem* item = dynamic_cast <TreeWidgetItem*>(clicked);

        if (item)
        {
            m_CurrentItem = item;
            auto& entity = m_CurrentItem->GetEntity();

            ResetUI(entity);
            AddComponentsToInspector(entity);
        }
    }

    void HierarchyPanel::ItemFinishedEditing()
    {
        Entity& entity = m_CurrentItem->GetEntity();

        if (entity.HasComponent<TagComponent>())
        {
            auto& tag = entity.GetComponent<TagComponent>().Tag;
            tag = m_CurrentItem->text(0).toStdString();
        }
    }

    void HierarchyPanel::UpdateUI()
    {
        Entity& entity = m_CurrentItem->GetEntity();

        m_CurrentItem->setText(0, QString::fromStdString(entity.GetComponent<TagComponent>().Tag));

        if(entity)
            AddComponentsToInspector(entity);
    }
}