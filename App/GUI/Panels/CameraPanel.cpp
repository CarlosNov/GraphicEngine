#include "CameraPanel.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QSpinBox>
#include <iostream>
#include <QKeyEvent>

namespace GraphicEngine
{
	CameraPanel::CameraPanel(QWidget* parent) : InspectorPanel(parent)
	{
		m_Camera = new CameraComponent();
		InitContent();
		UpdatePanelName("Camera Component");
	}

	void CameraPanel::InitContent()
	{
		QGridLayout* cameraLayout = new QGridLayout(frameCenter);
		cameraLayout->setSpacing(5);
		cameraLayout->setObjectName(QStringLiteral("cameraLayout"));
		cameraLayout->setContentsMargins(15, 5, 15, 15);



		cameraLayout->setAlignment(frameCenter, Qt::AlignTop);
	}

	void CameraPanel::UpdateContent()
	{
		if (m_Camera)
		{

		}
	}

	/* SLOTS */

	void CameraPanel::SetCamera(CameraComponent* camera)
	{
		m_Camera = camera;
		UpdateContent();
	}

	void CameraPanel::UpdateUI()
	{
		UpdateContent();
	}
}