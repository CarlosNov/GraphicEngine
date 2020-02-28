#include <QtWidgets/qapplication.h>
#include <QtWidgets/qtreewidget.h>
#include <QtWidgets/qboxlayout.h>
#include "MainWidget.h"
#include "Plantilla.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	QSurfaceFormat format;
	format.setDepthBufferSize(24);
	format.setStencilBufferSize(8);
	format.setVersion(3, 2);
	format.setProfile(QSurfaceFormat::CoreProfile);
	
	app.setApplicationName("Graphic Engine");
	app.setApplicationVersion("0.1");

	QMainWindow* mainWindow = new QMainWindow;

	Ui::MainWindow window;
	window.setupUi(mainWindow);
	mainWindow->show();

	/*
	QTreeWidget* treeWidget = new QTreeWidget();
	treeWidget->setColumnCount(1);
	QList<QTreeWidgetItem*> items;
	for (int i = 0; i < 10; ++i)
		items.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("item: %1").arg(i))));
	treeWidget->insertTopLevelItems(0, items);

	layout->addWidget(treeWidget);*/
	//widget.setLayout(layout);
	//widget.show();

    return app.exec();
}