
#include "GUI/DockTitleBar.h"
#include "GUI/GUIFunctions.h"

#include "qlabel.h"
#include "qpushbutton.h"
#include <Qt>
#include <iostream>
#include <QObject>

namespace GraphicEngine
{
	DockTitleBar::DockTitleBar(QWidget* parent) : QWidget(parent)
	{
		QHBoxLayout* mainLayout = new QHBoxLayout(this);
		mainLayout->setContentsMargins(0, 0, 0, 0);
		mainLayout->setSpacing(0);

		QFrame* mainFrame = new QFrame();
		mainFrame->setObjectName(QStringLiteral("mainFrame"));
		mainFrame->setMinimumHeight(20);
		mainFrame->setMaximumHeight(20);
		mainLayout->addWidget(mainFrame);

		QHBoxLayout* frameLayout = new QHBoxLayout(mainFrame);
		frameLayout->setContentsMargins(10, 0, 0, 0);
		frameLayout->setSpacing(0);

		QLabel* title = new QLabel("Hierarchy");
		title->setObjectName(QStringLiteral("titleLabel"));
		title->setMinimumHeight(20);
		title->setMaximumHeight(20);
		frameLayout->addWidget(title);

		QPushButton* closeButton = new QPushButton("x");

		frameLayout->addWidget(closeButton);
	}
}