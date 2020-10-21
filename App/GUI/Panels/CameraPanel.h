#pragma once

#include <QDoubleSpinBox>

#include "GUI/Panels/InspectorPanel.h"
#include "Scene/Components.h"

namespace GraphicEngine
{
	class CameraPanel : public InspectorPanel
	{
		Q_OBJECT

	public:
		CameraPanel(QWidget* parent = 0);
		~CameraPanel() {}

	public slots:
		void SetCamera(CameraComponent* camera);
		void UpdateUI();
	
	protected:
		void InitContent() override;
		void UpdateContent() override;

	private:
		CameraComponent* m_Camera;
	};
}


