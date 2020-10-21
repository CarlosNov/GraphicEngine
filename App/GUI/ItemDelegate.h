#pragma once

#include <QStyledItemDelegate>
#include <QLineEdit>

#include "GUI/Panels/HierarchyPanel.h"

namespace GraphicEngine
{
    class ItemDelegate : public QStyledItemDelegate
    {

    public:
        ItemDelegate(HierarchyPanel* parent) 
        {
            m_Parent = parent;
        }

        QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const
        {
            QLineEdit* lineEdit = new QLineEdit(parent);

            QObject::connect(lineEdit, &QLineEdit::editingFinished, m_Parent, &GraphicEngine::HierarchyPanel::ItemFinishedEditing);

            return lineEdit;
        }

    private:
        HierarchyPanel* m_Parent;
    };
}


