#pragma once

#include <QDockWidget>
#include <QComboBox>
#include <QStringList>

#include "GUI/CameraViewLabel.h"

namespace GraphicEngine
{
	class CameraViewDock : public QDockWidget
	{
		Q_OBJECT

	public:
		CameraViewDock(QWidget* parent = nullptr);

		CameraViewLabel* GetCameraViewLabel()
		{
			return CameraViewLabel;
		}

	signals:
		void RequestCameras();
		void SelectedCamera(QString cameraTag);

	public slots:
		void SetCameraList(QStringList cameras);
		void UpdateUI();

	private:
		QComboBox* cameraSelectorComboBox;
		CameraViewLabel* CameraViewLabel;

		QStringList cameraList;
	};
}


