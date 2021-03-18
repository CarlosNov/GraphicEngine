#pragma once

#include "GUI/Panels/InspectorPanel.h"
#include "Scene/Components.h"

#include <QComboBox>
#include <QFrame>
#include <QPushButton>
#include <QDoubleSpinBox>

namespace GraphicEngine
{
	class LightPanel : public InspectorPanel
	{
		Q_OBJECT

	public:
		LightPanel(QWidget* parent = 0);
		~LightPanel() {}

	signals:
		void RemoveLightComponent();

	public slots:
		void SetLight(LightComponent* light);
		void ChangeColor();
		void UpdateUI();
	
	protected:
		void InitContent() override;
		void UpdateContent() override;
		void InitSettingsButton() override;

	protected:
		QFrame* m_PointFrame;
		QFrame* m_DirectionalFrame;
		QFrame* m_SpotFrame;

		QComboBox* m_LightTypeComboBox;
		QFrame* m_ColorFrame;
		QFrame* m_ColorFrame2;
		QFrame* m_ColorFrame3;
		QPushButton* m_ColorSelectorButton;
		QPushButton* m_ColorSelectorButton2;
		QPushButton* m_ColorSelectorButton3;
		QDoubleSpinBox* m_ConstantSpinBox;
		QDoubleSpinBox* m_LinearSpinBox;
		QDoubleSpinBox* m_QuadraticSpinBox;
		QDoubleSpinBox* m_DirectionSpinBox1;
		QDoubleSpinBox* m_DirectionSpinBox2;
		QDoubleSpinBox* m_DirectionSpinBox3;
		QDoubleSpinBox* m_SpotSpinBox1;
		QDoubleSpinBox* m_SpotSpinBox2;
		QDoubleSpinBox* m_SpotSpinBox3;
		QDoubleSpinBox* m_CutOffSpinBox;

	private:
		LightComponent* m_Light;
	};
}


