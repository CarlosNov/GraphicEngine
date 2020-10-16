#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QFrame>

namespace GraphicEngine 
{
	class DockTitleBar : public QWidget
	{
		Q_OBJECT

	public:
		DockTitleBar(QWidget* parent = nullptr);
		void hola();
	private:
		QHBoxLayout* horizontalTitleBarLayout;
		QFrame* titleLeftFrame;
	};
}
