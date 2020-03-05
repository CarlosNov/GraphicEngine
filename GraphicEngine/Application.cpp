#include <QtWidgets/qapplication.h>
#include <QtWidgets/qtreewidget.h>
#include <QtWidgets/qboxlayout.h>
#include "RenderingWidget.h"
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

    return app.exec();
}