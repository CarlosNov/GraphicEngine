#pragma once

#include <QDockWidget>
#include <QAction>
#include <QMenu>

#include "GUI/Panels/TransformPanel.h"
#include "GUI/Panels/CameraPanel.h"
#include "GUI/Panels/TagPanel.h"
#include "GUI/Panels/MeshPanel.h"
#include "GUI/Panels/LightPanel.h"

namespace GraphicEngine
{
	class InspectorDock : public QDockWidget
	{
		Q_OBJECT

	public:
		InspectorDock(QWidget* parent = nullptr);

		TagPanel* GetTagPanel()
		{
			return TagPanel;
		}

		TransformPanel* GetTransformPanel()
		{
			return TransformPanel;
		}

		CameraPanel* GetCameraPanel()
		{
			return CameraPanel;
		}

		MeshPanel* GetMeshPanel()
		{
			return MeshPanel;
		}

		LightPanel* GetLightPanel()
		{
			return LightPanel;
		}

		QPushButton* GetAddComponentButton()
		{
			return addComponentButton;
		}

	signals:
		void AddTransformComponent();
		void AddCameraComponent();
		void AddMeshComponent();
		void AddLightComponent();

	public slots:
		void InitAddComponentMenu(const QPoint& pos);
		void UpdateUI();

	protected:
		QMenu* ComponentMenu;
		QAction* AddTransformComponentAction;
		QAction* AddCameraComponentAction;
		QAction* AddMeshComponentAction;
		QAction* AddLightComponentAction;
		QPushButton* addComponentButton;

	private:
		TagPanel* TagPanel;
		TransformPanel* TransformPanel;
		CameraPanel* CameraPanel;
		MeshPanel* MeshPanel;
		LightPanel* LightPanel;
	};
}


