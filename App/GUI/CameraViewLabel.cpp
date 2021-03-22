#include "CameraViewLabel.h"
#include "qpainter.h"
#include "qlabel.h"
#include "QtGui/qevent.h"

namespace GraphicEngine
{
	CameraViewLabel::CameraViewLabel(QWidget* parent) : QLabel(parent)
	{
		_colorTex = -1;
	}

	CameraViewLabel::~CameraViewLabel()
	{

	}

	void CameraViewLabel::SetCameraTexture(GLuint colorTex)
	{
		_colorTex = colorTex;
	}

	void CameraViewLabel::SetCameraTextureSize(unsigned int width, unsigned int height)
	{
		imageWidth = width;
		imageHeight = height;
	}

	void CameraViewLabel::RecalculateImage()
	{
		GLubyte* pixels = new GLubyte[imageWidth * imageHeight * 4];
		
		emit activateContextSignal();
		glBindTexture(GL_TEXTURE_2D, _colorTex);
		glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
		emit deactivateContextSignal();

		_renderedImage = QImage(pixels, imageWidth, imageHeight, QImage::Format_RGBA8888).copy().mirrored();

		delete pixels;
	}

	void CameraViewLabel::paintEvent(QPaintEvent* ev)
	{
		RecalculateImage();
		QPixmap* pixmap = new QPixmap(QPixmap::fromImage(_renderedImage).scaled(this->width() ,this->height(), Qt::KeepAspectRatio));
		this->setPixmap(*pixmap);
		delete pixmap;

		QLabel::paintEvent(ev);
		ev->accept();
	}
}
