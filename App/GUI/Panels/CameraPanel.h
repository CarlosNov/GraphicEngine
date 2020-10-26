#pragma once

#include <QDoubleSpinBox>
#include <QComboBox>

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

	signals:
		void RemoveCameraComponent();

	public slots:
		void SetCamera(CameraComponent* camera);
		void UpdateUI();
	
	protected:
		void InitContent() override;
		void UpdateContent() override;
		void InitSettingsButton() override;

	protected:
		QFrame* m_PerspectiveFrame;
		QFrame* m_OrtographicFrame;

		QComboBox* m_ProjectionTypeComboBox;
		QDoubleSpinBox* m_FOVSpinBox;
		QDoubleSpinBox* m_PerspNearSpinBox;
		QDoubleSpinBox* m_PerspFarSpinBox;
		QDoubleSpinBox* m_SizeSpinBox;
		QDoubleSpinBox* m_OrthNearSpinBox;
		QDoubleSpinBox* m_OrthFarSpinBox;

	private:
		CameraComponent* m_Camera;		
	};
}


