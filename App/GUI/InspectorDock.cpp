#include "InspectorDock.h"

#include <QWidget>
#include <QFrame>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QPushButton>

#include "GUI/GUIFunctions.h"

namespace GraphicEngine
{
	InspectorDock::InspectorDock(QWidget* parent) : QDockWidget(parent)
	{
        this->setStyleSheet(GUIFunctions::GetStyle(":/Styles/Styles/InspectorDock.qss"));

        this->setObjectName(QStringLiteral("InspectorDock"));
        this->setMinimumSize(QSize(200, 64));
        this->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

        QWidget* InspectorDockContents = new QWidget();
        InspectorDockContents->setObjectName(QStringLiteral("InspectorDockContents"));

        QGridLayout* InspectorContentLayout = new QGridLayout(InspectorDockContents);
        InspectorContentLayout->setSpacing(0);
        InspectorContentLayout->setObjectName(QStringLiteral("InspectorContentLayout"));
        InspectorContentLayout->setContentsMargins(0, 0, 0, 0);

        QFrame* InspectorFrame = new QFrame(InspectorDockContents);
        InspectorFrame->setObjectName(QStringLiteral("InspectorFrame"));
        InspectorFrame->setMinimumSize(QSize(230, 0));
        InspectorFrame->setFrameShape(QFrame::StyledPanel);
        InspectorFrame->setFrameShadow(QFrame::Raised);

        QVBoxLayout* InspectorFrameLayout = new QVBoxLayout(InspectorFrame);
        InspectorFrameLayout->setSpacing(0);
        InspectorFrameLayout->setObjectName(QStringLiteral("InspectorFrameLayout"));
        InspectorFrameLayout->setContentsMargins(0, 0, 0, 0);

        QFrame* InspectorFrameCenter = new QFrame(InspectorFrame);
        InspectorFrameCenter->setObjectName(QStringLiteral("InspectorFrameCenter"));
        InspectorFrameCenter->setMinimumSize(QSize(230, 30));
        InspectorFrameCenter->setFrameShape(QFrame::StyledPanel);
        InspectorFrameCenter->setFrameShadow(QFrame::Raised);

        QVBoxLayout* InspectorFrameCenterLayout = new QVBoxLayout(InspectorFrameCenter);
        InspectorFrameCenterLayout->setSpacing(0);
        InspectorFrameCenterLayout->setObjectName(QStringLiteral("InspectorFrameCenterLayout"));
        InspectorFrameCenterLayout->setContentsMargins(0, 0, 0, 0);
        InspectorFrameCenterLayout->setAlignment(Qt::AlignTop);

        TagPanel = new GraphicEngine::TagPanel(InspectorFrameCenter);
        TagPanel->setVisible(false);
        InspectorFrameCenterLayout->addWidget(TagPanel);

        TransformPanel = new GraphicEngine::TransformPanel(InspectorFrameCenter);
        TransformPanel->setVisible(false);
        InspectorFrameCenterLayout->addWidget(TransformPanel);

        CameraPanel = new GraphicEngine::CameraPanel(InspectorFrameCenter);
        CameraPanel->setVisible(false);
        InspectorFrameCenterLayout->addWidget(CameraPanel);

        MeshPanel = new GraphicEngine::MeshPanel(InspectorFrameCenter);
        MeshPanel->setVisible(false);
        InspectorFrameCenterLayout->addWidget(MeshPanel);

        LightPanel = new GraphicEngine::LightPanel(InspectorFrameCenter);
        LightPanel->setVisible(false);
        InspectorFrameCenterLayout->addWidget(LightPanel);

        QFrame* AddComponentFrame = new QFrame(InspectorFrameCenter);

        QGridLayout* AddComponentLayout = new QGridLayout(AddComponentFrame);
        AddComponentLayout->setSpacing(0);
        AddComponentLayout->setContentsMargins(5, 10, 5, 0);
        AddComponentLayout->setAlignment(Qt::AlignCenter);

        addComponentButton = new QPushButton(AddComponentFrame);
        addComponentButton->setObjectName(QStringLiteral("addComponentButton"));
        addComponentButton->setText("Add Component");
        addComponentButton->setMinimumHeight(25);
        addComponentButton->setMinimumWidth(200);
        addComponentButton->setVisible(false);

        ComponentMenu = new QMenu(addComponentButton);
        ComponentMenu->setMinimumWidth(200);

        AddTransformComponentAction = new QAction(tr("&Transform Component"), this);
        QObject::connect(AddTransformComponentAction, &QAction::triggered, [this]() { emit AddTransformComponent(); });

        AddCameraComponentAction = new QAction(tr("&Camera Component"), this);
        QObject::connect(AddCameraComponentAction, &QAction::triggered, [this]() { emit AddCameraComponent(); });

        AddMeshComponentAction = new QAction(tr("&Mesh Component"), this);
        QObject::connect(AddMeshComponentAction, &QAction::triggered, [this]() { emit AddMeshComponent(); });

        AddLightComponentAction = new QAction(tr("&Light Component"), this);
        QObject::connect(AddLightComponentAction, &QAction::triggered, [this]() { emit AddLightComponent(); });

        ComponentMenu->addAction(AddTransformComponentAction);
        ComponentMenu->addAction(AddCameraComponentAction);
        ComponentMenu->addAction(AddMeshComponentAction);
        ComponentMenu->addAction(AddLightComponentAction);
        addComponentButton->setMenu(ComponentMenu);

        AddComponentLayout->addWidget(addComponentButton);
        InspectorFrameCenterLayout->addWidget(AddComponentFrame);
        InspectorFrameLayout->addWidget(InspectorFrameCenter);

        InspectorContentLayout->addWidget(InspectorFrame, 0, 0, 1, 1);

        this->setWidget(InspectorDockContents);
	}

    /* SLOTS */

    void InspectorDock::InitAddComponentMenu(const QPoint& pos)
    {
        
    }

    void InspectorDock::UpdateUI()
    {
        if (TransformPanel->isVisible() && AddTransformComponentAction->icon().isNull())
        {
            AddTransformComponentAction->setIcon(QIcon(":/Assets/Assets/tick.png"));
        }
        else if (!TransformPanel->isVisible() && !AddTransformComponentAction->icon().isNull())
        {
            AddTransformComponentAction->setIcon(QIcon());
        }

        if (CameraPanel->isVisible() && AddCameraComponentAction->icon().isNull())
        {
            AddCameraComponentAction->setIcon(QIcon(":/Assets/Assets/tick.png"));
        }
        else if (!CameraPanel->isVisible() && !AddCameraComponentAction->icon().isNull())
        {
            AddCameraComponentAction->setIcon(QIcon());
        }


        if (MeshPanel->isVisible() && AddMeshComponentAction->icon().isNull())
        {
            AddMeshComponentAction->setIcon(QIcon(":/Assets/Assets/tick.png"));
        }
        else if (!MeshPanel->isVisible() && !AddMeshComponentAction->icon().isNull())
        {
            AddMeshComponentAction->setIcon(QIcon());
        }

        if (LightPanel->isVisible() && AddLightComponentAction->icon().isNull())
        {
            AddLightComponentAction->setIcon(QIcon(":/Assets/Assets/tick.png"));
        }
        else if (!LightPanel->isVisible() && !AddLightComponentAction->icon().isNull())
        {
            AddLightComponentAction->setIcon(QIcon());
        }
    }
}