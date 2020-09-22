#include "RenderQLabel.h"
#include "qpainter.h"
#include "qlabel.h"
#include "QtGui/qevent.h"

App::RenderQLabel::RenderQLabel(QWidget* parent) :QLabel(parent)
{
	_colorTex = -1;
}

App::RenderQLabel::~RenderQLabel()
{

}

void App::RenderQLabel::setColorTex(GLuint colorTex)
{
	_colorTex = colorTex;
}

void App::RenderQLabel::setRenderedImage(unsigned int width, unsigned int height)
{
	GLubyte* pixels = new GLubyte[width * height * 4];
		
	emit activateContextSignal();
	glBindTexture(GL_TEXTURE_2D, _colorTex);
	glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
	emit deactivateContextSignal();

	_renderedImage = QImage(pixels, width, height, QImage::Format_RGBA8888).copy().mirrored();

	GLuint r, g, b, a;

	size_t x = 0;
	size_t y = 0;

	size_t elmes_per_line = 256 * 4;

	size_t row = y * elmes_per_line;
	size_t col = x * 4;

	delete pixels;
}

void App::RenderQLabel::paintEvent(QPaintEvent* ev)
{	/*
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

	painter.end();

	this->setPixmap(QPixmap::fromImage(_renderedImage).scaled(350,350, Qt::KeepAspectRatio));

	QLabel::paintEvent(ev);
	ev->accept();
	*/
}