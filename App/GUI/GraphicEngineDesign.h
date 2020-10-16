#ifndef GRAPHICENGINEDESIGN_H
#define GRAPHICENGINEDESIGN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>

#include "GUI/GUIFunctions.h"
#include "GUI/DockTitleBar.h"
#include "GUI/Panels/HierarchyPanel.h"
#include "GUI/OpenGLWidget.h"

#include "GUI/Panels/TransformInspectorPanel.h"

QT_BEGIN_NAMESPACE

namespace GraphicEngine
{
    class Ui_MainWindow
    {
    public:
        QWidget* centralwidget;
        QGridLayout* gridLayout;
        QFrame* frameMain;
        QVBoxLayout* verticalLayout_3;
        QFrame* frameTop;
        QVBoxLayout* verticalLayout_5;
        QFrame* frameStatusBar;
        QVBoxLayout* verticalLayout_4;
        QFrame* frameAppBar;
        QVBoxLayout* verticalLayout_6;
        QFrame* frameCenter;
        QVBoxLayout* verticalLayout_2;
        OpenGLWidget* OpenGLWidget;
        QDockWidget* dockWidgetInspector;
        QWidget* dockWidgetContentsInspector;
        QGridLayout* gridLayout_2;
        QFrame* frameInspector;
        QVBoxLayout* verticalLayout;
        QFrame* frameTopInspector;
        QHBoxLayout* horizontalLayout;
        QFrame* frame;
        QVBoxLayout* verticalLayout_7;
        QLabel* label_2;
        QLabel* label;
        QFrame* frameCenterInspector;
        QDockWidget* dockWidgetHierarchy;
        QWidget* dockWidgetContents;
        QGridLayout* gridLayout_3;
        QFrame* frameHierarchy;
        QVBoxLayout* verticalLayout_9;
        QFrame* frameTopHierarchy;
        QHBoxLayout* horizontalLayout_2;
        QFrame* frame_4;
        QHBoxLayout* horizontalLayout_3;
        QLabel* labelIcon;
        QLabel* label_4;
        QLabel* label_5;
        HierarchyPanel* HierarchyPanel;
        QDockWidget* dockWidgetCameraView;
        QWidget* dockWidgetContents_2;
        QGridLayout* gridLayout_5;
        QFrame* frame_2;
        QGridLayout* gridLayout_4;
        QLabel* label_3;
        QDockWidget* dockWidgetMaterial;
        QWidget* dockWidgetContents_3;
        QGridLayout* gridLayout_6;
        QFrame* frame_3;
        QDockWidget* dockWidgetConsole;
        QWidget* dockWidgetContents_4;
        QGridLayout* gridLayout_7;
        QFrame* frame_5;
        QMenuBar* menuBar;
        QMenu* menuFile;

        void setupUi(QMainWindow* MainWindow)
        {
            if (MainWindow->objectName().isEmpty())
                MainWindow->setObjectName(QStringLiteral("Main Window"));
            MainWindow->resize(1080, 720);
            MainWindow->setMinimumSize(QSize(0, 0));
            QPalette palette;
            QBrush brush(QColor(0, 0, 0, 0));
            brush.setStyle(Qt::SolidPattern);
            palette.setBrush(QPalette::Active, QPalette::Button, brush);
            palette.setBrush(QPalette::Active, QPalette::Base, brush);
            palette.setBrush(QPalette::Active, QPalette::Window, brush);
            palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
            palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
            palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
            palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
            palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
            palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
            MainWindow->setPalette(palette);
            MainWindow->setStyleSheet(GUIFunctions::GetStyle(":/Styles/Styles/MainWindowStyle.qss"));
            centralwidget = new QWidget(MainWindow);
            centralwidget->setObjectName(QStringLiteral("centralwidget"));
            centralwidget->setStyleSheet(QLatin1String("background: transparent;\n" "color: #ffffff;"));
            gridLayout = new QGridLayout(centralwidget);
            gridLayout->setObjectName(QStringLiteral("gridLayout"));
            gridLayout->setContentsMargins(0, 0, 0, 0);
            frameMain = new QFrame(centralwidget);
            frameMain->setObjectName(QStringLiteral("frameMain"));
            frameMain->setFrameShadow(QFrame::Raised);
            verticalLayout_3 = new QVBoxLayout(frameMain);
            verticalLayout_3->setSpacing(0);
            verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
            verticalLayout_3->setContentsMargins(0, 0, 0, 0);
            frameTop = new QFrame(frameMain);
            frameTop->setObjectName(QStringLiteral("frameTop"));
            frameTop->setMinimumSize(QSize(0, 60));
            frameTop->setMaximumSize(QSize(16777215, 60));
            verticalLayout_5 = new QVBoxLayout(frameTop);
            verticalLayout_5->setSpacing(0);
            verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
            verticalLayout_5->setContentsMargins(0, 0, 0, 0);
            frameStatusBar = new QFrame(frameTop);
            frameStatusBar->setObjectName(QStringLiteral("frameStatusBar"));
            frameStatusBar->setMinimumSize(QSize(0, 30));
            frameStatusBar->setMaximumSize(QSize(16777215, 30));
            frameStatusBar->setStyleSheet(QStringLiteral("background: #05060E;"));
            verticalLayout_4 = new QVBoxLayout(frameStatusBar);
            verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));

            verticalLayout_5->addWidget(frameStatusBar);

            frameAppBar = new QFrame(frameTop);
            frameAppBar->setObjectName(QStringLiteral("frameAppBar"));
            frameAppBar->setStyleSheet(QStringLiteral("background: #23242C;"));
            verticalLayout_6 = new QVBoxLayout(frameAppBar);
            verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));

            verticalLayout_5->addWidget(frameAppBar);


            verticalLayout_3->addWidget(frameTop);

            frameCenter = new QFrame(frameMain);
            frameCenter->setObjectName(QStringLiteral("frameCenter"));
            frameCenter->setStyleSheet(QStringLiteral("background: #1D1E24;"));
            verticalLayout_2 = new QVBoxLayout(frameCenter);
            verticalLayout_2->setSpacing(0);
            verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
            verticalLayout_2->setContentsMargins(0, 0, 0, 0);
            OpenGLWidget = new GraphicEngine::OpenGLWidget(frameCenter);
            OpenGLWidget->setObjectName(QStringLiteral("OpenGLWidget"));
            OpenGLWidget->setMinimumSize(QSize(340, 230));
            OpenGLWidget->setMaximumSize(QSize(16777215, 16777215));
            OpenGLWidget->setBaseSize(QSize(680, 360));

            verticalLayout_2->addWidget(OpenGLWidget);


            verticalLayout_3->addWidget(frameCenter);


            gridLayout->addWidget(frameMain, 0, 0, 1, 1);

            MainWindow->setCentralWidget(centralwidget);
            dockWidgetInspector = new QDockWidget(MainWindow);
            dockWidgetInspector->setObjectName(QStringLiteral("dockWidgetInspector"));
            dockWidgetInspector->setMinimumSize(QSize(200, 64));
            dockWidgetInspector->setStyleSheet(QLatin1String("QDockWidget {\n"
                "   color: white;\n"
                "}"));
            dockWidgetInspector->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
            dockWidgetContentsInspector = new QWidget();
            dockWidgetContentsInspector->setObjectName(QStringLiteral("dockWidgetContentsInspector"));
            gridLayout_2 = new QGridLayout(dockWidgetContentsInspector);
            gridLayout_2->setSpacing(0);
            gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
            gridLayout_2->setContentsMargins(0, 0, 0, 0);
            frameInspector = new QFrame(dockWidgetContentsInspector);
            frameInspector->setObjectName(QStringLiteral("frameInspector"));
            frameInspector->setMinimumSize(QSize(200, 0));
            frameInspector->setStyleSheet(QStringLiteral("background: #181B2A;"));
            frameInspector->setFrameShape(QFrame::StyledPanel);
            frameInspector->setFrameShadow(QFrame::Raised);
            verticalLayout = new QVBoxLayout(frameInspector);
            verticalLayout->setSpacing(0);
            verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
            verticalLayout->setContentsMargins(0, 0, 0, 0);
            frameTopInspector = new QFrame(frameInspector);
            frameTopInspector->setObjectName(QStringLiteral("frameTopInspector"));
            frameTopInspector->setMinimumSize(QSize(200, 30));
            frameTopInspector->setMaximumSize(QSize(16777215, 30));
            frameTopInspector->setStyleSheet(QLatin1String("QFrame\n"
                "{\n"
                "	background: #181B2A;\n"
                "	border-bottom: 1px solid #232932;\n"
                "}\n"
                "\n"
                "QLabel\n"
                "{\n"
                "	border: none;\n"
                "}"));
            frameTopInspector->setFrameShape(QFrame::StyledPanel);
            frameTopInspector->setFrameShadow(QFrame::Raised);
            horizontalLayout = new QHBoxLayout(frameTopInspector);
            horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
            horizontalLayout->setContentsMargins(5, 0, 5, 0);
            frame = new QFrame(frameTopInspector);
            frame->setObjectName(QStringLiteral("frame"));
            frame->setMinimumSize(QSize(120, 15));
            frame->setMaximumSize(QSize(16777215, 15));
            frame->setStyleSheet(QLatin1String("QFrame\n"
                "{\n"
                "	background: #414453;\n"
                "	border:  none;\n"
                "}\n"
                "\n"
                ""));
            frame->setFrameShape(QFrame::StyledPanel);
            frame->setFrameShadow(QFrame::Raised);
            verticalLayout_7 = new QVBoxLayout(frame);
            verticalLayout_7->setSpacing(0);
            verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
            verticalLayout_7->setContentsMargins(5, 0, 0, 0);
            label_2 = new QLabel(frame);
            label_2->setObjectName(QStringLiteral("label_2"));
            label_2->setMinimumSize(QSize(115, 15));
            label_2->setMaximumSize(QSize(16777215, 15));

            verticalLayout_7->addWidget(label_2);


            horizontalLayout->addWidget(frame);

            label = new QLabel(frameTopInspector);
            label->setObjectName(QStringLiteral("label"));
            label->setMinimumSize(QSize(60, 15));
            label->setMaximumSize(QSize(16777215, 15));
            label->setLayoutDirection(Qt::RightToLeft);
            label->setStyleSheet(QStringLiteral("color: #252837;"));

            horizontalLayout->addWidget(label);

            horizontalLayout->setStretch(0, 1);

            verticalLayout->addWidget(frameTopInspector);

            frameCenterInspector = new QFrame(frameInspector);
            frameCenterInspector->setObjectName(QStringLiteral("frameCenterInspector"));
            frameCenterInspector->setMinimumSize(QSize(0, 0));
            frameCenterInspector->setFrameShape(QFrame::StyledPanel);
            frameCenterInspector->setFrameShadow(QFrame::Raised);

            QVBoxLayout* verticalLayout_8 = new QVBoxLayout(frameCenterInspector);
            TransformInspectorPanel* transform = new TransformInspectorPanel(frameCenterInspector);

            verticalLayout_8->addWidget(transform);


            verticalLayout->addWidget(frameCenterInspector);


            gridLayout_2->addWidget(frameInspector, 0, 0, 1, 1);

            dockWidgetInspector->setWidget(dockWidgetContentsInspector);
            MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidgetInspector);
            dockWidgetHierarchy = new QDockWidget(MainWindow);
            dockWidgetHierarchy->setObjectName(QStringLiteral("dockWidgetHierarchy"));
            dockWidgetHierarchy->setStyleSheet(QLatin1String("QDockWidget {\n"
                "   color: white;\n"
                "}"));
            dockWidgetHierarchy->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

            /* TITLEBAR TEST */

            DockTitleBar* dockTitleBar = new DockTitleBar();
            dockTitleBar->setObjectName(QStringLiteral("dockTitleBar"));
            dockTitleBar->setStyleSheet(GUIFunctions::GetStyle(":/Styles/Styles/DockTitleBarStyle.qss"));
           // dockWidgetHierarchy->setTitleBarWidget(dockTitleBar);

            /* TITLEBAR TEST */

            dockWidgetContents = new QWidget();
            dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
            gridLayout_3 = new QGridLayout(dockWidgetContents);
            gridLayout_3->setSpacing(0);
            gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
            gridLayout_3->setContentsMargins(0, 0, 0, 0);
            frameHierarchy = new QFrame(dockWidgetContents);
            frameHierarchy->setObjectName(QStringLiteral("frameHierarchy"));
            frameHierarchy->setMinimumSize(QSize(200, 200));
            frameHierarchy->setStyleSheet(QStringLiteral("background: #181B2A; border: none;"));
            frameHierarchy->setFrameShape(QFrame::StyledPanel);
            frameHierarchy->setFrameShadow(QFrame::Raised);
            verticalLayout_9 = new QVBoxLayout(frameHierarchy);
            verticalLayout_9->setSpacing(0);
            verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
            verticalLayout_9->setContentsMargins(0, 0, 0, 0);
            frameTopHierarchy = new QFrame(frameHierarchy);
            frameTopHierarchy->setObjectName(QStringLiteral("frameTopHierarchy"));
            frameTopHierarchy->setMinimumSize(QSize(200, 30));
            frameTopHierarchy->setMaximumSize(QSize(16777215, 30));
            frameTopHierarchy->setStyleSheet(QLatin1String("QFrame\n"
                "{\n"
                "	background: #181B2A;\n"
                "	border-bottom: 1px solid #232932;\n"
                "}\n"
                "\n"
                "QLabel\n"
                "{\n"
                "	border: none;\n"
                "}"));
            frameTopHierarchy->setFrameShape(QFrame::StyledPanel);
            frameTopHierarchy->setFrameShadow(QFrame::Raised);
            horizontalLayout_2 = new QHBoxLayout(frameTopHierarchy);
            horizontalLayout_2->setSpacing(0);
            horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
            horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
            frame_4 = new QFrame(frameTopHierarchy);
            frame_4->setObjectName(QStringLiteral("frame_4"));
            frame_4->setMinimumSize(QSize(120, 30));
            frame_4->setMaximumSize(QSize(16777215, 30));

            frame_4->setFrameShape(QFrame::StyledPanel);
            frame_4->setFrameShadow(QFrame::Raised);
            horizontalLayout_3 = new QHBoxLayout(frame_4);
            horizontalLayout_3->setSpacing(10);
            horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
            horizontalLayout_3->setContentsMargins(10, 0, 10, 0);
            labelIcon = new QLabel(frame_4);
            labelIcon->setObjectName(QStringLiteral("labelIcon"));
            labelIcon->setPixmap(QPixmap(QString::fromUtf8(":/Assets/Assets/3d-cube.png")));

            horizontalLayout_3->addWidget(labelIcon, 0, Qt::AlignRight | Qt::AlignVCenter);

            label_4 = new QLabel(frame_4);
            label_4->setObjectName(QStringLiteral("label_4"));
            QFont f("Roboto", 9, QFont::Bold);
            label_4->setFont(f);

            horizontalLayout_3->addWidget(label_4, 0, Qt::AlignHCenter | Qt::AlignVCenter);

            label_5 = new QLabel(frame_4);
            label_5->setObjectName(QStringLiteral("label_5"));
            label_5->setPixmap(QPixmap(QString::fromUtf8(":/Assets/Assets/settings-button.png")));

            horizontalLayout_3->addWidget(label_5, 0, Qt::AlignRight | Qt::AlignVCenter);

            horizontalLayout_3->setStretch(2, 1);

            horizontalLayout_2->addWidget(frame_4);


            verticalLayout_9->addWidget(frameTopHierarchy);

            HierarchyPanel = new GraphicEngine::HierarchyPanel(frameHierarchy);
            HierarchyPanel->header()->setVisible(false);
            HierarchyPanel->header()->setDefaultSectionSize(200);
            HierarchyPanel->header()->setMinimumSectionSize(200);

            verticalLayout_9->addWidget(HierarchyPanel);


            gridLayout_3->addWidget(frameHierarchy, 0, 0, 1, 1);

            dockWidgetHierarchy->setWidget(dockWidgetContents);
            MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidgetHierarchy);
            dockWidgetCameraView = new QDockWidget(MainWindow);
            dockWidgetCameraView->setObjectName(QStringLiteral("dockWidgetCameraView"));
            dockWidgetCameraView->setMinimumSize(QSize(200, 170));
            dockWidgetCameraView->setBaseSize(QSize(200, 170));
            dockWidgetCameraView->setStyleSheet(QLatin1String("QDockWidget {\n"
                "   color: white;\n"
                "}"));
            dockWidgetCameraView->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
            dockWidgetContents_2 = new QWidget();
            dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
            dockWidgetContents_2->setMinimumSize(QSize(200, 170));
            dockWidgetContents_2->setBaseSize(QSize(200, 170));
            gridLayout_5 = new QGridLayout(dockWidgetContents_2);
            gridLayout_5->setSpacing(0);
            gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
            gridLayout_5->setContentsMargins(0, 0, 0, 0);
            frame_2 = new QFrame(dockWidgetContents_2);
            frame_2->setObjectName(QStringLiteral("frame_2"));
            frame_2->setMinimumSize(QSize(200, 170));
            frame_2->setBaseSize(QSize(200, 170));
            frame_2->setStyleSheet(QStringLiteral("background: #333333;"));
            frame_2->setFrameShape(QFrame::StyledPanel);
            frame_2->setFrameShadow(QFrame::Raised);
            gridLayout_4 = new QGridLayout(frame_2);
            gridLayout_4->setSpacing(0);
            gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
            gridLayout_4->setContentsMargins(0, 0, 0, 0);
            label_3 = new QLabel(frame_2);
            label_3->setObjectName(QStringLiteral("label_3"));
            label_3->setBaseSize(QSize(200, 170));

            gridLayout_4->addWidget(label_3, 0, 0, 1, 1);


            gridLayout_5->addWidget(frame_2, 0, 0, 1, 1);

            dockWidgetCameraView->setWidget(dockWidgetContents_2);
            MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidgetCameraView);
            dockWidgetMaterial = new QDockWidget(MainWindow);
            dockWidgetMaterial->setObjectName(QStringLiteral("dockWidgetMaterial"));
            dockWidgetMaterial->setStyleSheet(QLatin1String("QDockWidget {\n"
                "   color: white;\n"
                "}"));
            dockWidgetContents_3 = new QWidget();
            dockWidgetContents_3->setObjectName(QStringLiteral("dockWidgetContents_3"));
            gridLayout_6 = new QGridLayout(dockWidgetContents_3);
            gridLayout_6->setSpacing(0);
            gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
            gridLayout_6->setContentsMargins(0, 0, 0, 0);
            frame_3 = new QFrame(dockWidgetContents_3);
            frame_3->setObjectName(QStringLiteral("frame_3"));
            frame_3->setStyleSheet(QStringLiteral("background: #181B2A; border: none;"));
            frame_3->setFrameShape(QFrame::StyledPanel);
            frame_3->setFrameShadow(QFrame::Raised);

            gridLayout_6->addWidget(frame_3, 0, 0, 1, 1);

            dockWidgetMaterial->setWidget(dockWidgetContents_3);
            MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidgetMaterial);
            dockWidgetConsole = new QDockWidget(MainWindow);
            dockWidgetConsole->setObjectName(QStringLiteral("dockWidgetConsole"));
            dockWidgetConsole->setStyleSheet(QLatin1String("QDockWidget {\n"
                "   color: white;\n"
                "}"));
            dockWidgetContents_4 = new QWidget();
            dockWidgetContents_4->setObjectName(QStringLiteral("dockWidgetContents_4"));
            gridLayout_7 = new QGridLayout(dockWidgetContents_4);
            gridLayout_7->setSpacing(0);
            gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
            gridLayout_7->setContentsMargins(0, 0, 0, 0);
            frame_5 = new QFrame(dockWidgetContents_4);
            frame_5->setObjectName(QStringLiteral("frame_5"));
            frame_5->setStyleSheet(QStringLiteral("background: #181B2A; border: none;"));
            frame_5->setFrameShape(QFrame::StyledPanel);
            frame_5->setFrameShadow(QFrame::Raised);

            gridLayout_7->addWidget(frame_5, 0, 0, 1, 1);

            dockWidgetConsole->setWidget(dockWidgetContents_4);
            MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidgetConsole);
            menuBar = new QMenuBar(MainWindow);
            menuBar->setObjectName(QStringLiteral("menuBar"));
            menuBar->setGeometry(QRect(0, 0, 1080, 21));
            menuFile = new QMenu(menuBar);
            menuFile->setObjectName(QStringLiteral("menuFile"));
            MainWindow->setMenuBar(menuBar);

            menuBar->addAction(menuFile->menuAction());

            retranslateUi(MainWindow);

            /* CONNECT SIGNALS AND SLOTS */

            //QObject::connect(_RenderingWidget, &GraphicEngine::RenderingWidget::colorTexSignal, RenderQLabel, &App::RenderQLabel::setColorTex);
            //QObject::connect(_RenderingWidget, &GraphicEngine::RenderingWidget::renderedImageSignal, RenderQLabel, &App::RenderQLabel::setRenderedImage);

            //QObject::connect(RenderQLabel, &App::RenderQLabel::activateContextSignal, _RenderingWidget, &GraphicEngine::RenderingWidget::activateGLContext);
            //QObject::connect(RenderQLabel, &App::RenderQLabel::deactivateContextSignal, _RenderingWidget, &GraphicEngine::RenderingWidget::deactivateGLContext);

            QObject::connect(OpenGLWidget, &GraphicEngine::OpenGLWidget::SetHierarchyScene, HierarchyPanel, &GraphicEngine::HierarchyPanel::SetScene);
            QObject::connect(OpenGLWidget, &GraphicEngine::OpenGLWidget::InitHierarchyDraw, HierarchyPanel, &GraphicEngine::HierarchyPanel::InitHierarchyDraw);

            QMetaObject::connectSlotsByName(MainWindow);
        } 

        void retranslateUi(QMainWindow* MainWindow)
        {
            MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
            dockWidgetInspector->setWindowTitle(QApplication::translate("MainWindow", "Inspector", nullptr));
            label_2->setText(QApplication::translate("MainWindow", "Empty Entity", nullptr));
            label->setText(QApplication::translate("MainWindow", "451235c2412", nullptr));
            dockWidgetHierarchy->setWindowTitle(QApplication::translate("MainWindow", "Hierarchy", nullptr));
            labelIcon->setText(QString());
            label_4->setText(QApplication::translate("MainWindow", "Scene", nullptr));
            label_5->setText(QString());

            dockWidgetCameraView->setWindowTitle(QApplication::translate("MainWindow", "Camera View", nullptr));
            label_3->setText(QString());
            dockWidgetMaterial->setWindowTitle(QApplication::translate("MainWindow", "Material", nullptr));
            dockWidgetConsole->setWindowTitle(QApplication::translate("MainWindow", "Console", nullptr));
            menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        }
    };   
}

namespace GraphicEngine 
{
    class MainWindow : public Ui_MainWindow {};
}

QT_END_NAMESPACE

#endif
