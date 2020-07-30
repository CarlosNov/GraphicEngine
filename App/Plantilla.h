#ifndef PLANTILLA_H
#define PLANTILLA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

#include "RenderingWidget.h"
#include "RenderQLabel.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget* MainWidget;
    QGridLayout* gridLayout;
    QFrame* MainFrame;
    QGridLayout* MainFrameLayout;
    QFrame* LeftFrame;
    QGridLayout* LeftFrameLayout;
    QTabWidget* ConsoleTabWidget;
    QWidget* ConsoleTab;
    QGridLayout* gridLayout_2;
    QTextEdit* textEdit;
    QTabWidget* SceneTabWidget;
    QWidget* SceneTab;
    QWidget* SceneWidget;
    RenderingWidget* _RenderingWidget;
    QWidget* SceneTabBar;
    QFrame* RightFrame;
    QGridLayout* gridLayout_3;
    QTabWidget* InspectorTabWidget;
    QWidget* Hierarchy;
    QGridLayout* gridLayout_4;
    QTreeWidget* treeWidget;
    QWidget* Inspector;
    QWidget* widget;
    QWidget* RenderedWidget;
    App::RenderQLabel* RenderQLabel;
    QMenuBar* menubar;
    QMenu* menuNew;
    QStatusBar* statusbar;

    void setupUi(QMainWindow* MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1080, 720);
        MainWindow->setMinimumSize(QSize(1080, 720));
        MainWindow->setMaximumSize(QSize(1080, 720));
        QPalette palette;
        QBrush brush(QColor(42, 40, 42, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        MainWindow->setPalette(palette);
        MainWindow->setAutoFillBackground(true);
        MainWindow->setTabShape(QTabWidget::Rounded);
        MainWidget = new QWidget(MainWindow);
        MainWidget->setObjectName(QStringLiteral("MainWidget"));
        MainWidget->setEnabled(true);
        MainWidget->setMinimumSize(QSize(1080, 720));
        MainWidget->setMaximumSize(QSize(1080, 720));
        gridLayout = new QGridLayout(MainWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        MainFrame = new QFrame(MainWidget);
        MainFrame->setObjectName(QStringLiteral("MainFrame"));
        MainFrame->setEnabled(true);
        MainFrame->setMinimumSize(QSize(1080, 720));
        MainFrame->setMaximumSize(QSize(1080, 720));
        MainFrame->setFrameShape(QFrame::StyledPanel);
        MainFrame->setFrameShadow(QFrame::Raised);
        MainFrameLayout = new QGridLayout(MainFrame);
        MainFrameLayout->setSpacing(0);
        MainFrameLayout->setObjectName(QStringLiteral("MainFrameLayout"));
        MainFrameLayout->setContentsMargins(0, 0, 0, 0);
        LeftFrame = new QFrame(MainFrame);
        LeftFrame->setObjectName(QStringLiteral("LeftFrame"));
        LeftFrame->setMinimumSize(QSize(648, 720));
        LeftFrame->setMaximumSize(QSize(648, 720));
        LeftFrame->setFrameShape(QFrame::StyledPanel);
        LeftFrame->setFrameShadow(QFrame::Raised);
        LeftFrameLayout = new QGridLayout(LeftFrame);
        LeftFrameLayout->setSpacing(0);
        LeftFrameLayout->setObjectName(QStringLiteral("LeftFrameLayout"));
        LeftFrameLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        LeftFrameLayout->setContentsMargins(0, 0, 0, 0);
        ConsoleTabWidget = new QTabWidget(LeftFrame);
        ConsoleTabWidget->setObjectName(QStringLiteral("ConsoleTabWidget"));
        ConsoleTabWidget->setMinimumSize(QSize(640, 150));
        ConsoleTabWidget->setMaximumSize(QSize(640, 150));
        ConsoleTabWidget->setStyleSheet(QLatin1String("QTabWidget::pane {\n"
            "    border: 4px solid #444344;\n"
            "	border-radius: 4px;\n"
            "	border-top-left-radius:0px;\n"
            "}\n"
            "\n"
            "QTabBar::tab {\n"
            "    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
            "                                stop: 0 #444344, stop: 0.4 #444344,\n"
            "                                stop: 0.5 #444344, stop: 1.0 #444344);\n"
            "    border: 2px solid #444344;\n"
            "    border-bottom-color: #444344;\n"
            "    border-top-left-radius: 4px;\n"
            "    border-top-right-radius: 4px;\n"
            "    min-width: 8ex;\n"
            "    padding: 2px;\n"
            "	color: white;\n"
            "}\n"
            "\n"
            "QTabBar::tab:selected, QTabBar::tab:hover {\n"
            "    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
            "                                stop: 0 #444344, stop: 0.4 #444344,\n"
            "                                stop: 0.5 #444344, stop: 1.0 #444344);\n"
            "}\n"
            "\n"
            "QTabBar::tab:selected {\n"
            "    border-color: #444344;\n"
            "    border-bottom-color: #444344; \n"
            "}\n"
            "\n"
            "QTabBar::tab:!selected {\n"
            "    margin-top: 2px; \n"
            "}"));
        ConsoleTabWidget->setDocumentMode(false);
        ConsoleTabWidget->setMovable(true);
        ConsoleTab = new QWidget();
        ConsoleTab->setObjectName(QStringLiteral("ConsoleTab"));
        ConsoleTab->setMinimumSize(QSize(640, 150));
        ConsoleTab->setMaximumSize(QSize(640, 150));
        gridLayout_2 = new QGridLayout(ConsoleTab);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(ConsoleTab);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout_2->addWidget(textEdit, 0, 0, 1, 1);

        ConsoleTabWidget->addTab(ConsoleTab, QString());

        LeftFrameLayout->addWidget(ConsoleTabWidget, 1, 0, 1, 1);

        SceneTabWidget = new QTabWidget(LeftFrame);
        SceneTabWidget->setObjectName(QStringLiteral("SceneTabWidget"));
        SceneTabWidget->setEnabled(true);
        SceneTabWidget->setMinimumSize(QSize(640, 480));
        SceneTabWidget->setMaximumSize(QSize(640, 480));
        SceneTabWidget->setAutoFillBackground(false);
        SceneTabWidget->setStyleSheet(QLatin1String("QTabWidget::pane {\n"
            "    border: 4px solid #444344;\n"
            "	border-radius: 4px;\n"
            "	border-top-left-radius:0px;\n"
            "}\n"
            "\n"
            "QTabBar::tab {\n"
            "    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
            "                                stop: 0 #444344, stop: 0.4 #444344,\n"
            "                                stop: 0.5 #444344, stop: 1.0 #444344);\n"
            "    border: 2px solid #444344;\n"
            "    border-bottom-color: #444344;\n"
            "    border-top-left-radius: 4px;\n"
            "    border-top-right-radius: 4px;\n"
            "    min-width: 8ex;\n"
            "    padding: 2px;\n"
            "	color: white;\n"
            "}\n"
            "\n"
            "QTabBar::tab:selected, QTabBar::tab:hover {\n"
            "    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
            "                                stop: 0 #444344, stop: 0.4 #444344,\n"
            "                                stop: 0.5 #444344, stop: 1.0 #444344);\n"
            "}\n"
            "\n"
            "QTabBar::tab:selected {\n"
            "    border-color: #444344;\n"
            "    border-bottom-color: #444344; \n"
            "}\n"
            "\n"
            "QTabBar::tab:!selected {\n"
            "    margin-top: 2px; \n"
            "}"));
        SceneTabWidget->setUsesScrollButtons(true);
        SceneTabWidget->setDocumentMode(false);
        SceneTabWidget->setTabsClosable(false);
        SceneTabWidget->setMovable(true);
        SceneTabWidget->setTabBarAutoHide(false);
        SceneTab = new QWidget();
        SceneTab->setObjectName(QStringLiteral("SceneTab"));
        SceneTab->setMinimumSize(QSize(640, 455));
        SceneTab->setMaximumSize(QSize(640, 455));
        SceneTab->setAutoFillBackground(false);
        SceneTab->setStyleSheet(QStringLiteral(""));
        SceneWidget = new QWidget(SceneTab);
        SceneWidget->setObjectName(QStringLiteral("SceneWidget"));
        SceneWidget->setGeometry(QRect(0, 0, 636, 455));
        SceneWidget->setMinimumSize(QSize(636, 455));
        SceneWidget->setMaximumSize(QSize(636, 455));
        SceneWidget->setAutoFillBackground(true);
        SceneWidget->setStyleSheet(QStringLiteral(""));

        _RenderingWidget = new RenderingWidget(SceneWidget);
        _RenderingWidget->setObjectName(QStringLiteral("RenderingWidget"));
        _RenderingWidget->setGeometry(QRect(0, 15, 632, 436));
        _RenderingWidget->setMinimumSize(QSize(632, 436));
        _RenderingWidget->setMaximumSize(QSize(632, 436));

        SceneTabBar = new QWidget(SceneWidget);
        SceneTabBar->setObjectName(QStringLiteral("SceneTabBar"));
        SceneTabBar->setGeometry(QRect(0, 0, 636, 15));
        SceneTabBar->setMinimumSize(QSize(636, 15));
        SceneTabBar->setMaximumSize(QSize(636, 15));
        QPalette palette1;
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush2(QColor(68, 67, 68, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        SceneTabBar->setPalette(palette1);
        SceneTabBar->setAutoFillBackground(true);
        SceneTabBar->setStyleSheet(QStringLiteral(""));
        SceneTabWidget->addTab(SceneTab, QString());

        LeftFrameLayout->addWidget(SceneTabWidget, 0, 0, 1, 1);


        MainFrameLayout->addWidget(LeftFrame, 0, 0, 1, 1);

        RightFrame = new QFrame(MainFrame);
        RightFrame->setObjectName(QStringLiteral("RightFrame"));
        RightFrame->setMinimumSize(QSize(360, 720));
        RightFrame->setMaximumSize(QSize(360, 720));
        RightFrame->setFrameShape(QFrame::StyledPanel);
        RightFrame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(RightFrame);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        InspectorTabWidget = new QTabWidget(RightFrame);
        InspectorTabWidget->setObjectName(QStringLiteral("InspectorTabWidget"));
        InspectorTabWidget->setMinimumSize(QSize(350, 480));
        InspectorTabWidget->setMaximumSize(QSize(350, 480));
        InspectorTabWidget->setStyleSheet(QLatin1String("QTabWidget::pane {\n"
            "    border: 4px solid #444344;\n"
            "	border-radius: 4px;\n"
            "	border-top-left-radius:0px;\n"
            "}\n"
            "\n"
            "QTabBar::tab {\n"
            "    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
            "                                stop: 0 #444344, stop: 0.4 #444344,\n"
            "                                stop: 0.5 #444344, stop: 1.0 #444344);\n"
            "    border: 2px solid #444344;\n"
            "    border-bottom-color: #444344;\n"
            "    border-top-left-radius: 4px;\n"
            "    border-top-right-radius: 4px;\n"
            "    min-width: 8ex;\n"
            "    padding: 2px;\n"
            "	color: white;\n"
            "}\n"
            "\n"
            "QTabBar::tab:selected, QTabBar::tab:hover {\n"
            "    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
            "                                stop: 0 #444344, stop: 0.4 #444344,\n"
            "                                stop: 0.5 #444344, stop: 1.0 #444344);\n"
            "}\n"
            "\n"
            "QTabBar::tab:selected {\n"
            "    border-color: #444344;\n"
            "    border-bottom-color: #444344; \n"
            "}\n"
            "\n"
            "QTabBar::tab:!selected {\n"
            "    margin-top: 2px; \n"
            "}"));
        InspectorTabWidget->setDocumentMode(false);
        InspectorTabWidget->setTabsClosable(false);
        InspectorTabWidget->setMovable(true);
        InspectorTabWidget->setTabBarAutoHide(false);
        Hierarchy = new QWidget();
        Hierarchy->setObjectName(QStringLiteral("Hierarchy"));
        Hierarchy->setMinimumSize(QSize(360, 100));
        Hierarchy->setMaximumSize(QSize(100, 16777215));
        gridLayout_4 = new QGridLayout(Hierarchy);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);

        /* QTREEWIDGET */
        treeWidget = new QTreeWidget(Hierarchy);
        treeWidget->setObjectName(QStringLiteral("TreeWidget"));

        QTreeWidgetItem* _sceneItem = new QTreeWidgetItem(treeWidget, 0);
        _sceneItem->setText(0, QStringLiteral("Scene"));

        QTreeWidgetItem* child = new QTreeWidgetItem(_sceneItem, 0);
        child->setText(0, QStringLiteral("Child"));

        treeWidget->setAcceptDrops(true);
        treeWidget->setDragEnabled(true);
        treeWidget->setDragDropMode(QAbstractItemView::InternalMove);

        gridLayout_4->addWidget(treeWidget, 0, 0, 1, 1);

        InspectorTabWidget->addTab(Hierarchy, QString());
        Inspector = new QWidget();
        Inspector->setObjectName(QStringLiteral("Inspector"));
        widget = new QWidget(Inspector);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 350, 480));
        widget->setMinimumSize(QSize(350, 480));
        widget->setMaximumSize(QSize(350, 480));
        InspectorTabWidget->addTab(Inspector, QString());

        gridLayout_3->addWidget(InspectorTabWidget, 0, 0, 1, 1);

        RenderedWidget = new QWidget(RightFrame);
        RenderedWidget->setObjectName(QStringLiteral("RenderedWidget"));
        RenderedWidget->setMinimumSize(QSize(350, 150));
        RenderedWidget->setMaximumSize(QSize(350, 150));
        RenderedWidget->setStyleSheet(QLatin1String("QWidget {\n"
            "    border: 4px solid #444344;\n"
            "	border-radius: 4px;\n"
            "	border-top-left-radius:0px;\n"
            "}"));


        
        RenderQLabel = new App::RenderQLabel(RenderedWidget);
        RenderQLabel->setObjectName(QStringLiteral("RenderQLabel"));
        RenderQLabel->setGeometry(QRect(0, 0, 350, 150));
        RenderQLabel->setMinimumSize(QSize(350, 150));
        RenderQLabel->setMaximumSize(QSize(350, 150));

        gridLayout_3->addWidget(RenderedWidget, 1, 0, 1, 1);


        MainFrameLayout->addWidget(RightFrame, 0, 1, 1, 1);


        gridLayout->addWidget(MainFrame, 0, 0, 1, 1);

        MainWindow->setCentralWidget(MainWidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1080, 21));
        menuNew = new QMenu(menubar);
        menuNew->setObjectName(QStringLiteral("menuNew"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuNew->menuAction());

        retranslateUi(MainWindow);

        ConsoleTabWidget->setCurrentIndex(0);
        SceneTabWidget->setCurrentIndex(0);
        InspectorTabWidget->setCurrentIndex(1);


        QObject::connect(_RenderingWidget, &RenderingWidget::colorTexSignal, RenderQLabel, &App::RenderQLabel::setColorTex);
        QObject::connect(_RenderingWidget, &RenderingWidget::renderedImageSignal, RenderQLabel, &App::RenderQLabel::setRenderedImage);

        QObject::connect(RenderQLabel, &App::RenderQLabel::activateContextSignal, _RenderingWidget, &RenderingWidget::activateGLContext);
        QObject::connect(RenderQLabel, &App::RenderQLabel::deactivateContextSignal, _RenderingWidget, &RenderingWidget::deactivateGLContext);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow* MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Graphic Engine", nullptr));
        ConsoleTabWidget->setTabText(ConsoleTabWidget->indexOf(ConsoleTab), QApplication::translate("MainWindow", "Console", nullptr));
        SceneTabWidget->setTabText(SceneTabWidget->indexOf(SceneTab), QApplication::translate("MainWindow", "Scene", nullptr));
        InspectorTabWidget->setTabText(InspectorTabWidget->indexOf(Hierarchy), QApplication::translate("MainWindow", "Hierarchy", nullptr));
        InspectorTabWidget->setTabText(InspectorTabWidget->indexOf(Inspector), QApplication::translate("MainWindow", "Inspector", nullptr));

        menuNew->setTitle(QApplication::translate("MainWindow", "New", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow : public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PLANTILLA_H


/*
#ifndef PLANTILLA_H
#define PLANTILLA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>
#include "RenderingWidget.h"
#include "RenderedFrame.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QFrame *frame_2;
    QGridLayout *gridLayout_3;
    QFrame *frame_4;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_7 ;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    RenderingWidget* renderingWidget;
    QFrame *frame_3;
    QGridLayout *gridLayout_4;
    QFrame *frame_5;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_6;
    QTreeView *treeView;
    QWidget *tab_2;
    QMenuBar *menubar;
    QMenu *menuNew;
    QStatusBar *statusbar;

    App::RenderedFrame *_renderedFrame;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1043, 746);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setMinimumSize(QSize(636, 624));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        frame_4 = new QFrame(frame_2);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setMinimumSize(QSize(616, 91));
        frame_4->setMaximumSize(QSize(616, 140));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame_4);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        scrollArea = new QScrollArea(frame_4);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 594, 118));
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_5->addWidget(scrollArea, 0, 0, 1, 1);


        gridLayout_3->addWidget(frame_4, 1, 0, 1, 1);

        renderingWidget = new RenderingWidget(frame_2);
        renderingWidget->setObjectName(QStringLiteral("openGLWidget"));
        renderingWidget->setMinimumSize(QSize(616, 501));
        renderingWidget->setMaximumSize(QSize(616, 501));

        gridLayout_3->addWidget(renderingWidget, 0, 0, 1, 1);


        gridLayout_2->addWidget(frame_2, 0, 0, 1, 1);

        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setMinimumSize(QSize(271, 624));
        frame_3->setMaximumSize(QSize(363, 667));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_3);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        frame_5 = new QFrame(frame_3);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setMinimumSize(QSize(343, 211));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(frame_5);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        _renderedFrame = new App::RenderedFrame(frame_5);
        _renderedFrame->setObjectName(QStringLiteral("RenderedFrame"));

        QObject::connect(renderingWidget, &RenderingWidget::colorTexSignal,_renderedFrame, &App::RenderedFrame::setColorTex);

        QObject::connect(renderingWidget, &RenderingWidget::renderedImageSignal,_renderedFrame, &App::RenderedFrame::setRenderedImage);

        gridLayout_7->addWidget(_renderedFrame, 0, 0, 1, 1);

        gridLayout_4->addWidget(frame_5, 1, 0, 1, 1);

        tabWidget = new QTabWidget(frame_3);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMinimumSize(QSize(343, 431));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_6 = new QGridLayout(tab);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        treeView = new QTreeView(tab);
        treeView->setObjectName(QStringLiteral("treeView"));

        gridLayout_6->addWidget(treeView, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        gridLayout_4->addWidget(tabWidget, 0, 0, 1, 1);


        gridLayout_2->addWidget(frame_3, 0, 1, 1, 1);


        gridLayout->addWidget(frame, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1043, 21));
        menuNew = new QMenu(menubar);
        menuNew->setObjectName(QStringLiteral("menuNew"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuNew->menuAction());

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", nullptr));
        menuNew->setTitle(QApplication::translate("MainWindow", "New", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PLANTILLA_H
*/