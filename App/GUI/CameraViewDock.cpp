#include "CameraViewDock.h"

#include <QWidget>
#include <QFrame>
#include <QGridLayout>
#include <QHBoxLayout>

#include "GUI/GUIFunctions.h"

namespace GraphicEngine
{
    CameraViewDock::CameraViewDock(QWidget* parent) : QDockWidget(parent)
    {
        this->setStyleSheet(GUIFunctions::GetStyle(":/Styles/Styles/CameraViewDock.qss"));
        this->setObjectName(QStringLiteral("CameraViewDock"));
        this->setMinimumSize(QSize(200, 170));
        this->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

        QWidget* CameraViewDockContents = new QWidget();
        CameraViewDockContents->setObjectName(QStringLiteral("CameraViewDockContents"));
        CameraViewDockContents->setMinimumSize(QSize(200, 200));

        QGridLayout* contentLayout = new QGridLayout(CameraViewDockContents);
        contentLayout->setObjectName(QStringLiteral("contentLayout"));
        contentLayout->setSpacing(0);
        contentLayout->setContentsMargins(0, 0, 0, 0);

        /* CAMERA SELECTOR */

        QFrame* cameraSelectorFrame = new QFrame(CameraViewDockContents);
        cameraSelectorFrame->setMinimumSize(QSize(200, 35));
        cameraSelectorFrame->setMaximumHeight(35);

        QGridLayout* cameraSelectorLayout = new QGridLayout(cameraSelectorFrame);
        cameraSelectorLayout->setObjectName(QStringLiteral("lightTypeLayout"));
        cameraSelectorLayout->setContentsMargins(10, 2, 10, 2);
        cameraSelectorLayout->setAlignment(Qt::AlignCenter); 

        QLabel* cameraSelectorLabel = new QLabel(cameraSelectorFrame);
        cameraSelectorLabel->setStyleSheet(QStringLiteral("color: white; font: 8pt  'Roboto';"));
        cameraSelectorLabel->setText(QString::fromStdString("Selected Camera"));

        QFrame* cameraSelectorSeparator = new QFrame(cameraSelectorFrame);
        cameraSelectorSeparator->setStyleSheet("background: transparent; border-right: 1px solid #414453;");
        cameraSelectorSeparator->setMinimumWidth(1);
        cameraSelectorSeparator->setMinimumWidth(5);

        cameraSelectorComboBox = new QComboBox(cameraSelectorFrame);
        cameraSelectorComboBox->setMinimumWidth(100);
        cameraList << "None";
        cameraSelectorComboBox->insertItems(0, cameraList);

        cameraSelectorLayout->addWidget(cameraSelectorLabel, 0, 0);
        cameraSelectorLayout->addWidget(cameraSelectorSeparator, 0, 1);
        cameraSelectorLayout->addWidget(cameraSelectorComboBox, 0, 2);

        QFrame* frameCamera = new QFrame(CameraViewDockContents);
        frameCamera->setObjectName(QStringLiteral("frameCamera"));
        frameCamera->setMinimumSize(QSize(200, 165));
        frameCamera->setStyleSheet(QStringLiteral("background: #181B2A;"));
        frameCamera->setFrameShape(QFrame::StyledPanel);
        frameCamera->setFrameShadow(QFrame::Raised);

        QGridLayout* cameraLayout = new QGridLayout(frameCamera);
        cameraLayout->setSpacing(0);
        cameraLayout->setObjectName(QStringLiteral("cameraLayout"));
        cameraLayout->setContentsMargins(0, 0, 0, 0);

        CameraViewLabel = new GraphicEngine::CameraViewLabel(frameCamera);
        CameraViewLabel->setObjectName(QStringLiteral("CameraViewLabel"));
        CameraViewLabel->setStyleSheet(QStringLiteral("background: #333333;"));
        CameraViewLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

        cameraLayout->addWidget(CameraViewLabel, 0,0);

        contentLayout->addWidget(cameraSelectorFrame, 0, 0);
        contentLayout->addWidget(frameCamera, 1, 0);

        this->setWidget(CameraViewDockContents);

        QObject::connect(cameraSelectorComboBox, qOverload<int>(&QComboBox::currentIndexChanged), [this](int index)
            {
                if (index != -1 && index <= cameraList.size() - 1)
                {
                    emit SelectedCamera(cameraList.at(index));
                }
            });
    }

    void CameraViewDock::SetCameraList(QStringList cameras)
    {
        if (cameras.size() != cameraList.size())
        {
            cameraList = cameras;
            cameraSelectorComboBox->clear();
            cameraSelectorComboBox->insertItems(0, cameraList);
            return;
        }

        for (int i = 0; i < cameras.size(); i++)
        {
            if (!cameraList.contains(cameras.at(i)))
            {
                cameraList = cameras;
                cameraSelectorComboBox->clear();
                cameraSelectorComboBox->insertItems(0, cameraList);
                return;
            }
        }
    }

    void CameraViewDock::UpdateUI()
    {
        emit RequestCameras();
    } 
}