#pragma once

#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QLabel>

namespace GraphicEngine
{
	class InspectorPanel : public QWidget
	{
		Q_OBJECT

	public:
		InspectorPanel(QWidget* parent = 0);
		~InspectorPanel() {}

	protected:

		virtual void expandCollapseEvent() noexcept
		{
			frameCenter->setVisible(showContent);

			QPixmap* resizeButtonPixmap;
			if(showContent)
				resizeButtonPixmap = new QPixmap(QString::fromUtf8(":/Assets/Assets/branch-open.png"));
			else
				resizeButtonPixmap = new QPixmap(QString::fromUtf8(":/Assets/Assets/branch-closed.png"));

			showContent = !showContent;

			QIcon resizeButtonIcon(*resizeButtonPixmap);
			resizeButton->setIcon(resizeButtonIcon);
			resizeButton->setIconSize(resizeButtonPixmap->rect().size());
		}

		virtual void InitContent() =  0;
		virtual void UpdateContent() = 0;

		void UpdatePanelName(QString name);

	protected:
		QFrame* frameCenter;

	private:
		QFrame* frameTop;
		QPushButton* resizeButton;
		QLabel* componentName;
		QPushButton* settingsButton;

		bool showContent = false;
	};
}

