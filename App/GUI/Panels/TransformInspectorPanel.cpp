#include "TransformInspectorPanel.h"

#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QVBoxLayout>

#include "Section.h"

namespace GraphicEngine 
{
    TransformInspectorPanel::TransformInspectorPanel(QWidget* parent) : QFrame(parent)
	{
        QVBoxLayout topLayout(this);

        QWidget* w1 = new QWidget();
        w1->setStyleSheet("background: black;");
        topLayout.addWidget(w1);
;
        Section* section = new Section(this);
        section->setStyleSheet("background: white;");
        topLayout.addWidget(section);

        QVBoxLayout inLayout(section);
        QPushButton* button = new QPushButton();
        button->setMinimumHeight(100);
        inLayout.addWidget(button);

        QWidget* w2 = new QWidget();
        w2->setStyleSheet("background: gray;");
        topLayout.addWidget(w2);

	}

    void TransformInspectorPanel::CreateInspector()
    {
        
    }
}

