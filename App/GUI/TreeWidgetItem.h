#pragma once

#include <QTreeWidget>

#include "Scene/Entity.h"

namespace GraphicEngine
{
	class TreeWidgetItem : public QObject, public QTreeWidgetItem
	{
		Q_OBJECT

	public:
		TreeWidgetItem();
		TreeWidgetItem(QObject* parent);

		void setText(int column, const QString& atext)
		{
			QTreeWidgetItem::setText(column, atext);
		}

		void addChild(QTreeWidgetItem* child)
		{
			QTreeWidgetItem::addChild(child);
		}

		void SetEntity(const Entity& entity);
		Entity& GetEntity();

	private:
		Entity m_Entity;
	};
}