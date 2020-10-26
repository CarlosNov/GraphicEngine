#pragma once

#include <QDockWidget>
#include <QAction>
#include <QMenu>

#include "GUI/Panels/TransformPanel.h"
#include "GUI/Panels/CameraPanel.h"
#include "GUI/Panels/TagPanel.h"
#include "GUI/Panels/MeshPanel.h"

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

		QPushButton* GetAddComponentButton()
		{
			return addComponentButton;
		}

	signals:
		void AddTransformComponent();
		void AddCameraComponent();

	public slots:
		void InitAddComponentMenu(const QPoint& pos);
		void UpdateUI();

	protected:
		QMenu* ComponentMenu;
		QAction* AddTransformComponentAction;
		QAction* AddCameraComponentAction;
		QPushButton* addComponentButton;

	private:
		TagPanel* TagPanel;
		TransformPanel* TransformPanel;
		CameraPanel* CameraPanel;
		MeshPanel* MeshPanel;
	};
}


