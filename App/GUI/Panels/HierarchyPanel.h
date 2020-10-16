#pragma once

#include <QtWidgets/QTreeWidget>

#include "Scene/Scene.h"
#include "Scene/Entity.h"

namespace GraphicEngine
{
	class HierarchyPanel : public QTreeWidget
	{
	public:

		HierarchyPanel(QWidget * parent = nullptr);

	public slots:
		void SetScene(Scene* scene);
		void InitHierarchyDraw();

	private:
		void AddEntityToHierarchy(Entity entity);
		void AddComponentsToInspector(Entity entity);

	private:
		Scene* m_CurrentScene;
		Entity m_SelectionContext;
	};
}
