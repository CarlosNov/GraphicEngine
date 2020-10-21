#include "TreeWidgetItem.h"

namespace GraphicEngine
{
	TreeWidgetItem::TreeWidgetItem() : QTreeWidgetItem(UserType)
	{

	}

	TreeWidgetItem::TreeWidgetItem(QObject* parent) : QTreeWidgetItem(UserType)
	{

	}

	void TreeWidgetItem::SetEntity(const Entity& entity)
	{
		m_Entity = entity;
	}

	Entity& TreeWidgetItem::GetEntity()
	{
		return m_Entity;
	}
}