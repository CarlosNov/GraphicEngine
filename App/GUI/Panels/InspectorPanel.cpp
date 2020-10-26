#include "InspectorPanel.h"

#include <QVBoxLayout>
#include <QLabel>

#include "GUI/GUIFunctions.h"

namespace GraphicEngine 
{
    InspectorPanel::InspectorPanel(QWidget* parent) : QWidget(parent)
	{
        this->setMinimumSize(230, 35);
        this->setStyleSheet(GUIFunctions::GetStyle(":/Styles/Styles/InspectorPanel.qss"));

        QVBoxLayout* mainLayout = new QVBoxLayout(this);
        mainLayout->setSpacing(5);
        mainLayout->setObjectName(QStringLiteral("mainLayout"));
        mainLayout->setContentsMargins(0, 0, 0, 0);

        frameTop = new QFrame(this);
        frameTop->setObjectName(QStringLiteral("frameTop"));
        frameTop->setMinimumSize(QSize(230, 30));
        frameTop->setMaximumSize(QSize(16777215, 30));
        frameTop->setFrameShape(QFrame::StyledPanel);
        frameTop->setFrameShadow(QFrame::Raised);

        QHBoxLayout* horizontalLayout = new QHBoxLayout(frameTop);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 0, 5, 0);

        resizeButton = new QPushButton(frameTop);
        resizeButton->setObjectName(QStringLiteral("resizeButton"));
        resizeButton->setMinimumSize(20,20);
        resizeButton->setMaximumSize(20,20);

        QPixmap* resizeButtonPixmap = new QPixmap(QString::fromUtf8(":/Assets/Assets/branch-open.png"));
        QIcon resizeButtonIcon(*resizeButtonPixmap);
        resizeButton->setIcon(resizeButtonIcon);
        resizeButton->setIconSize(resizeButtonPixmap->rect().size());

        componentName = new QLabel(frameTop);
        componentName->setObjectName(QStringLiteral("componentName"));
        componentName->setMinimumSize(QSize(60, 15));
        componentName->setMaximumSize(QSize(16777215, 15));
        componentName->setLayoutDirection(Qt::RightToLeft);
        componentName->setText("Inspector Panel");

        m_SettingsButton = new QPushButton(frameTop);
        m_SettingsButton->setObjectName(QStringLiteral("settingsButton"));
        m_SettingsButton->setMinimumSize(20, 20);
        m_SettingsButton->setMaximumSize(20, 20);

        QPixmap* pixmap = new QPixmap(QString::fromUtf8(":/Assets/Assets/settings-button.png"));
        QIcon ButtonIcon(*pixmap);
        m_SettingsButton->setIcon(ButtonIcon);
        m_SettingsButton->setIconSize(pixmap->rect().size());

        horizontalLayout->setStretch(0, 1);

        horizontalLayout->addWidget(resizeButton);
        horizontalLayout->addWidget(componentName);
        horizontalLayout->addWidget(m_SettingsButton);


        frameCenter = new QFrame(this);
        frameCenter->setMinimumSize(230, 0);
        frameCenter->setObjectName(QStringLiteral("frameCenter"));

        mainLayout->addWidget(frameTop);
        mainLayout->setAlignment(frameTop, Qt::AlignTop);
        mainLayout->addWidget(frameCenter);
        mainLayout->setAlignment(frameCenter, Qt::AlignTop);

        QObject::connect(resizeButton, &QPushButton::clicked, this, &InspectorPanel::expandCollapseEvent);
	} 

    void InspectorPanel::UpdatePanelName(QString name)
    {
        componentName->setText(name);
    }
}

