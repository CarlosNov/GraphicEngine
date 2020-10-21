#include "TagPanel.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

#include "GUI/Panels/TagPanel.h"

namespace GraphicEngine
{
	TagPanel::TagPanel(QWidget* parent) : QFrame(parent)
	{

		m_Tag = new TagComponent("Empty Tag");

        QHBoxLayout* horizontalLayout = new QHBoxLayout(this);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 0, 5, 0);

        QFrame* frameMain = new QFrame(this);
        frameMain->setObjectName(QStringLiteral("frameMain"));
        frameMain->setMinimumSize(QSize(120, 15));
        frameMain->setMaximumSize(QSize(16777215, 15));
        frameMain->setStyleSheet(QLatin1String("QFrame { background: #414453; border:  none; }"));
        frameMain->setFrameShape(QFrame::StyledPanel);
        frameMain->setFrameShadow(QFrame::Raised);

        QVBoxLayout* verticalLayout = new QVBoxLayout(frameMain);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(5, 0, 0, 0);

        lineEditTag = new QLineEdit(frameMain);
        lineEditTag->setObjectName(QStringLiteral("lineEditTag"));
        lineEditTag->setStyleSheet("QLineEdit{ border: none; background: #414453; color: white; }");
        lineEditTag->setMinimumSize(QSize(115, 15));
        lineEditTag->setMaximumSize(QSize(16777215, 15));

        QObject::connect(lineEditTag, &QLineEdit::editingFinished, [this]() { lineEditTag->clearFocus(); });
        QObject::connect(lineEditTag, &QLineEdit::editingFinished, [this]() { m_Tag->Tag = lineEditTag->text().toStdString(); });

        verticalLayout->addWidget(lineEditTag);
        horizontalLayout->addWidget(frameMain);

        labelID = new QLabel(this);
        labelID->setObjectName(QStringLiteral("labelID"));
        labelID->setMinimumSize(QSize(60, 15));
        labelID->setMaximumSize(QSize(16777215, 15));
        labelID->setLayoutDirection(Qt::RightToLeft);
        labelID->setStyleSheet(QStringLiteral("color: #252837;"));

        horizontalLayout->addWidget(labelID);

        horizontalLayout->setStretch(0, 1);
	}

	void TagPanel::UpdateContent()
	{

	}

	/* SLOTS */

	void TagPanel::SetTag(TagComponent* tag)
	{
        m_Tag = tag;
	}

    void TagPanel::SetID(uint32_t id)
    {
        m_EntityID = id;
    }

	void TagPanel::UpdateUI()
	{
        if(!lineEditTag->hasFocus())
            lineEditTag->setText(QString::fromStdString(m_Tag->Tag));

        labelID->setText(QString::number(m_EntityID));
	}
}