#include "CameraPanel.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QSpinBox>
#include <QComboBox>
#include <iostream>
#include <QKeyEvent>
#include <QMenu>
#include <QAction>

namespace GraphicEngine
{
	CameraPanel::CameraPanel(QWidget* parent) : InspectorPanel(parent)
	{
		m_Camera = new CameraComponent();
		InitContent();
		InitSettingsButton();
		UpdatePanelName("Camera Component");

		QObject::connect(m_ProjectionTypeComboBox, qOverload<int>(&QComboBox::currentIndexChanged), [this](int index) 
			{ 
				switch (index)
				{
				case 0:
					m_Camera->Camera.SetProjectionType(SceneCamera::ProjectionType::Perspective);
					break;

				case 1:
					m_Camera->Camera.SetProjectionType(SceneCamera::ProjectionType::Orthographic);
					break;
				}
			});

		QObject::connect(m_FOVSpinBox, &QDoubleSpinBox::textChanged, [this]() {m_Camera->Camera.SetPerspectiveFOV(glm::radians(m_FOVSpinBox->value())); });
		QObject::connect(m_FOVSpinBox, &QDoubleSpinBox::editingFinished, m_FOVSpinBox, &QDoubleSpinBox::clearFocus);
		QObject::connect(m_PerspNearSpinBox, &QDoubleSpinBox::textChanged, [this]() {m_Camera->Camera.SetPerspectiveNear(m_PerspNearSpinBox->value()); });
		QObject::connect(m_PerspNearSpinBox, &QDoubleSpinBox::editingFinished, m_PerspNearSpinBox, &QDoubleSpinBox::clearFocus);
		QObject::connect(m_PerspFarSpinBox, &QDoubleSpinBox::textChanged, [this]() {m_Camera->Camera.SetPerspectiveFar(m_PerspFarSpinBox->value()); });
		QObject::connect(m_PerspFarSpinBox, &QDoubleSpinBox::editingFinished, m_PerspFarSpinBox, &QDoubleSpinBox::clearFocus);

		QObject::connect(m_SizeSpinBox, &QDoubleSpinBox::textChanged, [this]() {m_Camera->Camera.SetOrthographicSize(m_SizeSpinBox->value()); });
		QObject::connect(m_SizeSpinBox, &QDoubleSpinBox::editingFinished, m_SizeSpinBox, &QDoubleSpinBox::clearFocus);
		QObject::connect(m_OrthNearSpinBox, &QDoubleSpinBox::textChanged, [this]() {m_Camera->Camera.SetOrthographicNear(m_OrthNearSpinBox->value()); });
		QObject::connect(m_OrthNearSpinBox, &QDoubleSpinBox::editingFinished, m_OrthNearSpinBox, &QDoubleSpinBox::clearFocus);
		QObject::connect(m_OrthFarSpinBox, &QDoubleSpinBox::textChanged, [this]() {m_Camera->Camera.SetOrthographicFar(m_OrthFarSpinBox->value()); });
		QObject::connect(m_OrthFarSpinBox, &QDoubleSpinBox::editingFinished, m_OrthFarSpinBox, &QDoubleSpinBox::clearFocus);
	}

	void CameraPanel::InitContent()
	{
		QVBoxLayout* cameraLayout = new QVBoxLayout(frameCenter);
		cameraLayout->setSpacing(0);
		cameraLayout->setObjectName(QStringLiteral("cameraLayout"));
		cameraLayout->setContentsMargins(0, 0, 0, 0);
		cameraLayout->setAlignment(Qt::AlignTop);

		QFrame* projectionFrame = new QFrame(frameCenter);
		projectionFrame->setStyleSheet("QFrame { background: transparent; }");

		QGridLayout* projectionLayout = new QGridLayout(projectionFrame);
		projectionLayout->setSpacing(5);
		projectionLayout->setObjectName(QStringLiteral("projectionLayout"));
		projectionLayout->setContentsMargins(15, 5, 15, 15);
		projectionLayout->setAlignment(Qt::AlignTop);

		QLabel* projectionLabel = new QLabel(projectionFrame);
		projectionLabel->setStyleSheet(QStringLiteral("color: white; font: 8pt  'Roboto';"));
		projectionLabel->setText(QString::fromStdString("Projection Type"));

		QFrame* projectionSeparator = new QFrame(projectionFrame);
		projectionSeparator->setStyleSheet("background: transparent; border-right: 1px solid #414453;");
		projectionSeparator->setMinimumWidth(1);
		projectionSeparator->setMinimumWidth(5);

		m_ProjectionTypeComboBox = new QComboBox(projectionFrame);
		m_ProjectionTypeComboBox->setMinimumWidth(100);

		QStringList projectionList = { "Perspective", "Ortographic" };
		m_ProjectionTypeComboBox->insertItems(0, projectionList);

		projectionLayout->addWidget(projectionLabel, 0, 0);
		projectionLayout->addWidget(projectionSeparator, 0, 1);
		projectionLayout->addWidget(m_ProjectionTypeComboBox, 0, 2);

		projectionLayout->setColumnStretch(2, 1);

		/* PERSPECTIVE PROJECTION */

		m_PerspectiveFrame = new QFrame(frameCenter);
		m_PerspectiveFrame->setStyleSheet("QFrame { background: transparent; }");

		QGridLayout* perspectiveLayout = new QGridLayout(m_PerspectiveFrame);
		perspectiveLayout->setSpacing(5);
		perspectiveLayout->setObjectName(QStringLiteral("perspectiveLayout"));
		perspectiveLayout->setContentsMargins(15, 0, 15, 15);
		perspectiveLayout->setAlignment(Qt::AlignTop);
		perspectiveLayout->setColumnStretch(2, 1);

		QLabel* FOVLabel = new QLabel(m_PerspectiveFrame);
		FOVLabel->setStyleSheet(QStringLiteral("color: white; font: 8pt  'Roboto';"));
		FOVLabel->setText(QString::fromStdString("FOV"));

		QFrame* FOVSeparator = new QFrame(m_PerspectiveFrame);
		FOVSeparator->setStyleSheet("background: transparent; border-right: 1px solid #414453;");
		FOVSeparator->setMinimumWidth(1);
		FOVSeparator->setMinimumWidth(5);

		m_FOVSpinBox = new QDoubleSpinBox(m_PerspectiveFrame);
		m_FOVSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
		m_FOVSpinBox->setRange(-999999, 999999);
		m_FOVSpinBox->setSingleStep(1);
		m_FOVSpinBox->setValue(0);
		m_FOVSpinBox->setMinimumWidth(40);

		perspectiveLayout->addWidget(FOVLabel, 0, 0);
		perspectiveLayout->addWidget(FOVSeparator, 0, 1);
		perspectiveLayout->addWidget(m_FOVSpinBox, 0, 2);

		QLabel* PerspNearLabel = new QLabel(m_PerspectiveFrame);
		PerspNearLabel->setStyleSheet(QStringLiteral("color: white; font: 8pt  'Roboto';"));
		PerspNearLabel->setText(QString::fromStdString("Near"));

		QFrame* PerspNearSeparator = new QFrame(m_PerspectiveFrame);
		PerspNearSeparator->setStyleSheet("background: transparent; border-right: 1px solid #414453;");
		PerspNearSeparator->setMinimumWidth(1);
		PerspNearSeparator->setMinimumWidth(5);

		m_PerspNearSpinBox = new QDoubleSpinBox(m_PerspectiveFrame);
		m_PerspNearSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
		m_PerspNearSpinBox->setRange(-999999, 999999);
		m_PerspNearSpinBox->setSingleStep(1);
		m_PerspNearSpinBox->setValue(0);
		m_PerspNearSpinBox->setMinimumWidth(40);

		perspectiveLayout->addWidget(PerspNearLabel, 1, 0);
		perspectiveLayout->addWidget(PerspNearSeparator, 1, 1);
		perspectiveLayout->addWidget(m_PerspNearSpinBox, 1, 2);

		QLabel* PesrpFarLabel = new QLabel(m_PerspectiveFrame);
		PesrpFarLabel->setStyleSheet(QStringLiteral("color: white; font: 8pt  'Roboto';"));
		PesrpFarLabel->setText(QString::fromStdString("Far"));

		QFrame* PerspFarSeparator = new QFrame(m_PerspectiveFrame);
		PerspFarSeparator->setStyleSheet("background: transparent; border-right: 1px solid #414453;");
		PerspFarSeparator->setMinimumWidth(1);
		PerspFarSeparator->setMinimumWidth(5);

		m_PerspFarSpinBox = new QDoubleSpinBox(m_PerspectiveFrame);
		m_PerspFarSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
		m_PerspFarSpinBox->setRange(-999999, 999999);
		m_PerspFarSpinBox->setSingleStep(1);
		m_PerspFarSpinBox->setValue(0);
		m_PerspFarSpinBox->setMinimumWidth(40);

		perspectiveLayout->addWidget(PesrpFarLabel, 2, 0);
		perspectiveLayout->addWidget(PerspFarSeparator, 2, 1);
		perspectiveLayout->addWidget(m_PerspFarSpinBox, 2, 2);

		/* ORTOGRAPHIC PROJECTION */

		m_OrtographicFrame = new QFrame(frameCenter);
		m_OrtographicFrame->setStyleSheet("QFrame { background: transparent; }");

		QGridLayout* ortographicLayout = new QGridLayout(m_OrtographicFrame);
		ortographicLayout->setSpacing(5);
		ortographicLayout->setObjectName(QStringLiteral("ortographicLayout"));
		ortographicLayout->setContentsMargins(15, 0, 15, 15);
		ortographicLayout->setAlignment(Qt::AlignTop);
		ortographicLayout->setColumnStretch(2, 1);

		QLabel* SizeLabel = new QLabel(m_OrtographicFrame);
		SizeLabel->setStyleSheet(QStringLiteral("color: white; font: 8pt  'Roboto';"));
		SizeLabel->setText(QString::fromStdString("Size"));

		QFrame* SizeSeparator = new QFrame(m_OrtographicFrame);
		SizeSeparator->setStyleSheet("background: transparent; border-right: 1px solid #414453;");
		SizeSeparator->setMinimumWidth(1);
		SizeSeparator->setMinimumWidth(5);

		m_SizeSpinBox = new QDoubleSpinBox(m_OrtographicFrame);
		m_SizeSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
		m_SizeSpinBox->setRange(-999999, 999999);
		m_SizeSpinBox->setSingleStep(1);
		m_SizeSpinBox->setValue(0);
		m_SizeSpinBox->setMinimumWidth(40);

		ortographicLayout->addWidget(SizeLabel, 0, 0);
		ortographicLayout->addWidget(SizeSeparator, 0, 1);
		ortographicLayout->addWidget(m_SizeSpinBox, 0, 2);

		QLabel* OrthNearLabel = new QLabel(m_OrtographicFrame);
		OrthNearLabel->setStyleSheet(QStringLiteral("color: white; font: 8pt  'Roboto';"));
		OrthNearLabel->setText(QString::fromStdString("Near"));

		QFrame* OrthNearSeparator = new QFrame(m_OrtographicFrame);
		OrthNearSeparator->setStyleSheet("background: transparent; border-right: 1px solid #414453;");
		OrthNearSeparator->setMinimumWidth(1);
		OrthNearSeparator->setMinimumWidth(5);

		m_OrthNearSpinBox = new QDoubleSpinBox(m_OrtographicFrame);
		m_OrthNearSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
		m_OrthNearSpinBox->setRange(-999999, 999999);
		m_OrthNearSpinBox->setSingleStep(1);
		m_OrthNearSpinBox->setValue(0);
		m_OrthNearSpinBox->setMinimumWidth(40);

		ortographicLayout->addWidget(OrthNearLabel, 1, 0);
		ortographicLayout->addWidget(OrthNearSeparator, 1, 1);
		ortographicLayout->addWidget(m_OrthNearSpinBox, 1, 2);

		QLabel* OrthFarLabel = new QLabel(m_OrtographicFrame);
		OrthFarLabel->setStyleSheet(QStringLiteral("color: white; font: 8pt  'Roboto';"));
		OrthFarLabel->setText(QString::fromStdString("Far"));

		QFrame* OrthFarSeparator = new QFrame(m_OrtographicFrame);
		OrthFarSeparator->setStyleSheet("background: transparent; border-right: 1px solid #414453;");
		OrthFarSeparator->setMinimumWidth(1);
		OrthFarSeparator->setMinimumWidth(5);

		m_OrthFarSpinBox = new QDoubleSpinBox(m_OrtographicFrame);
		m_OrthFarSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
		m_OrthFarSpinBox->setRange(-999999, 999999);
		m_OrthFarSpinBox->setSingleStep(1);
		m_OrthFarSpinBox->setValue(0);
		m_OrthFarSpinBox->setMinimumWidth(40);

		ortographicLayout->addWidget(OrthFarLabel, 2, 0);
		ortographicLayout->addWidget(OrthFarSeparator, 2, 1);
		ortographicLayout->addWidget(m_OrthFarSpinBox, 2, 2);


		cameraLayout->addWidget(projectionFrame);
		cameraLayout->addWidget(m_PerspectiveFrame);
		cameraLayout->addWidget(m_OrtographicFrame);

		m_OrtographicFrame->setVisible(false);
	}

	void CameraPanel::UpdateContent()
	{
		if (m_Camera)
		{
			if (m_Camera->Camera.GetProjectionType() == SceneCamera::ProjectionType::Perspective)
			{
				m_OrtographicFrame->setVisible(false);
				m_PerspectiveFrame->setVisible(true);
				
				if (!m_ProjectionTypeComboBox->hasFocus())
					m_ProjectionTypeComboBox->setCurrentIndex(0);

				if(!m_FOVSpinBox->hasFocus())
					m_FOVSpinBox->setValue(glm::degrees(m_Camera->Camera.GetPerspectiveFOV()));
				if (!m_PerspNearSpinBox->hasFocus())
					m_PerspNearSpinBox->setValue(m_Camera->Camera.GetPerspectiveNear());
				if (!m_PerspFarSpinBox->hasFocus())
					m_PerspFarSpinBox->setValue(m_Camera->Camera.GetPerspectiveFar());
			}
			else if (m_Camera->Camera.GetProjectionType() == SceneCamera::ProjectionType::Orthographic)
			{
				m_PerspectiveFrame->setVisible(false);
				m_OrtographicFrame->setVisible(true);

				if (!m_ProjectionTypeComboBox->hasFocus())
					m_ProjectionTypeComboBox->setCurrentIndex(1);

				if (!m_SizeSpinBox->hasFocus())
					m_SizeSpinBox->setValue(m_Camera->Camera.GetOrtographicSize());
				if (!m_OrthNearSpinBox->hasFocus())
					m_OrthNearSpinBox->setValue(m_Camera->Camera.GetOrthographicNear());
				if (!m_OrthFarSpinBox->hasFocus())
					m_OrthFarSpinBox->setValue(m_Camera->Camera.GetOrthographicFar());
			}
		}
	}

	void CameraPanel::InitSettingsButton()
	{
		QMenu* SettingsMenu = new QMenu(m_SettingsButton);

		QAction* RemoveCameraComponentAction = new QAction(tr("&Remove Component"), this);
		QObject::connect(RemoveCameraComponentAction, &QAction::triggered, [this]() { emit RemoveCameraComponent(); });

		SettingsMenu->addAction(RemoveCameraComponentAction);
		m_SettingsButton->setMenu(SettingsMenu);
	}

	/* SLOTS */

	void CameraPanel::SetCamera(CameraComponent* camera)
	{
		m_Camera = camera;
		UpdateContent();
	}

	void CameraPanel::UpdateUI()
	{
		UpdateContent();
	}
}