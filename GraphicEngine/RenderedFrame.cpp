#include "RenderedFrame.h"


App::RenderedFrame::RenderedFrame(QWidget* parent) :QLabel(parent)
{
	_colorTex = -1;
}

App::RenderedFrame::~RenderedFrame()
{

}

void App::RenderedFrame::setRenderedImage(unsigned int width, unsigned int height)
{
	GLubyte* pixels = new GLubyte[256 * 256 * 3];
	glBindTexture(GL_TEXTURE_2D, _colorTex);
	glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);

	_renderedImage = QImage(pixels, width, height, QImage::Format_RGB888);
	delete pixels;
}

void App::RenderedFrame::paintEvent(QPaintEvent* ev)
{
	std::cout << "hola";
}

void App::RenderedFrame::setColorTex(GLuint colorTex)
{
	_colorTex = colorTex;
	std::cout << "Entra";
}