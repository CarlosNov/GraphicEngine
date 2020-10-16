#pragma once

#include "qframe.h"

namespace GraphicEngine
{
	class TransformInspectorPanel : public QFrame
	{
		Q_OBJECT

	public:
		TransformInspectorPanel(QWidget* parent = 0);
		~TransformInspectorPanel() {}

		void CreateInspector();

	private:
		QWidget* m_Parent;
	};
}

