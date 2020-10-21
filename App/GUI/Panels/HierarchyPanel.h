#pragma once

#include <QtWidgets/QTreeWidget>
#include <QItemSelection>

#include "Scene/Scene.h"
#include "Scene/Components.h"
#include "GUI/TreeWidgetItem.h"

namespace GraphicEngine
{
	class HierarchyPanel : public QTreeWidget
	{
		Q_OBJECT

	public:
		HierarchyPanel(QWidget * parent = nullptr);

	signals:
		void CreateTagPanel();
		void CreateTransformPanel();
		void CreateCameraPanel();
		void DestroyPanels();

		void SetTag(TagComponent* name);
		void SetID(uint32_t id);
		void SetTransform(TransformComponent* transform);
		void SetCamera(CameraComponent* transform);

	public slots:
		void SetScene(Scene* scene);
		void InitHierarchyDraw();
		void ItemClicked(QTreeWidgetItem* item, int column);
		void ItemFinishedEditing();
		void UpdateUI();

	private:
		void AddEntityToHierarchy(Entity entity);
		void AddComponentsToInspector(Entity entity);
		void ResetUI(Entity entity);

	private:
		Scene* m_CurrentScene;
		TreeWidgetItem* m_CurrentItem;
	};
}
