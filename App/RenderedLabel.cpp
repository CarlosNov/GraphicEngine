#include "RenderedLabel.h"
#include "qpainter.h"
#include "qlabel.h"


App::RenderedLabel::RenderedLabel(QWidget* parent) :QLabel(parent)
{
	_colorTex = -1;
	std::cout << "LABEL: " << _colorTex;
}

App::RenderedLabel::~RenderedLabel()
{

}

void App::RenderedLabel::setColorTex(GLuint colorTex)
{
	_colorTex = colorTex;
}

void App::RenderedLabel::setRenderedImage(unsigned int width, unsigned int height)
{
	uchar* pixels = new uchar[width * height * 3];
	std::cout << "LABEL: " << _colorTex;
	glBindTexture(GL_TEXTURE_2D, _colorTex);
	glGetTexImage(GL_TEXTURE_2D, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels);

	_renderedImage = QImage(pixels, width, height, QImage::Format_RGB888);
	delete pixels;
}

void App::RenderedLabel::paintEvent(QPaintEvent* ev)
{	
	int w = _renderedImage.width();
	int h = _renderedImage.height();

	QPainter painter(&_renderedImage);

	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap));
	QFont font = painter.font();
	font.setPixelSize(30);
	painter.setFont(font);
	QPainterPath rectPath;
	glm::vec3 position;

	painter.setPen(Qt::white);
	rectPath.addRect(30, 30, 30, 30);
	painter.fillPath(rectPath,Qt::white);
	painter.drawPath(rectPath);

	painter.setPen(Qt::white);
	painter.drawText(QPoint(30 + 5, 30 + 25), "L");

	painter.end();

	QLabel::paintEvent(ev);
	ev->accept();
}