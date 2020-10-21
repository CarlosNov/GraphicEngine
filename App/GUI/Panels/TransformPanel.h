#pragma once

#include <QDoubleSpinBox>

#include "GUI/Panels/InspectorPanel.h"
#include "Scene/Components.h"

namespace GraphicEngine
{
	class TransformPanel : public InspectorPanel
	{
		Q_OBJECT

	public:
		TransformPanel(QWidget* parent = 0);
		~TransformPanel() {}

	public slots:
		void SetTransform(TransformComponent* transform);
		void UpdateUI();
	
	protected:
		void InitContent() override;
		void UpdateContent() override;

	protected:
		QDoubleSpinBox* translationSpinBox1;
		QDoubleSpinBox* translationSpinBox2;
		QDoubleSpinBox* translationSpinBox3;
		QDoubleSpinBox* rotationSpinBox1;
		QDoubleSpinBox* rotationSpinBox2;
		QDoubleSpinBox* rotationSpinBox3;
		QDoubleSpinBox* scaleSpinBox1;
		QDoubleSpinBox* scaleSpinBox2;
		QDoubleSpinBox* scaleSpinBox3;

	private:
		TransformComponent* m_Transform;
	};
}


