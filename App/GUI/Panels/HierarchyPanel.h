#pragma once

#include <QtWidgets/QTreeWidget>
#include <QItemSelection>

#include "Scene/Scene.h"
#include "Scene/Entity.h"
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
		void SetTagPanelVisible(bool visible);
		void SetTransformPanelVisible(bool visible);
		void SetCameraPanelVisible(bool visible);
		void SetMeshPanelVisible(bool visible);
		void SetLightPanelVisible(bool visible);
		void SetAddComponentButtonVisible(bool visible);

		void SetTag(TagComponent* name);
		void SetID(uint32_t id);
		void SetTransform(TransformComponent* transform);
		void SetCamera(CameraComponent* camera);
		void SetMesh(MeshComponent* mesh);
		void SetLight(LightComponent* light);

		void SetCameraList(QStringList cameraList);
		void SetCameraTexture(GLuint colorTex);
		void SetCameraTextureSize(unsigned int width, unsigned int height);

	public slots:
		void SetScene(Scene* scene);
		void InitHierarchy();
		void InitMenu(const QPoint& pos);
		void ItemClicked(QTreeWidgetItem* item, int column);
		void ItemFinishedEditing();

		void CreateEntity();
		void DeleteEntity();

		void AddTransformComponent();
		void RemoveTransformComponent();
		void AddCameraComponent();
		void RemoveCameraComponent();
		void AddMeshComponent();
		void RemoveMeshComponent();
		void AddLightComponent();
		void RemoveLightComponent();

		void GetCameras();
		void SetSelectedCamera(QString cameraTag);

		void UpdateUI();

	private:
		void AddEntityToHierarchy(Entity entity);

	private:
		Scene* m_CurrentScene;
		TreeWidgetItem* m_CurrentItem;
	};
}
