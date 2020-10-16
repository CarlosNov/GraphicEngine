
#include "HierarchyPanel.h"
#include "GUI/GUIFunctions.h"

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
    }

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

    void HierarchyPanel::AddEntityToHierarchy(Entity entity)
    {
        auto& tag = entity.GetComponent<TagComponent>().Tag;

        std::cout << tag;

        QTreeWidgetItem* tempItem = new QTreeWidgetItem();
        tempItem->setText(0, QString::fromStdString(tag));
        insertTopLevelItem(0, tempItem);
    }
}