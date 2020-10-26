#include "TransformPanel.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QSpinBox>
#include <QApplication>
#include <QKeyEvent>
#include <QMenu>
#include <QAction>

namespace GraphicEngine
{
	TransformPanel::TransformPanel(QWidget* parent) : InspectorPanel(parent)
	{
		m_Transform = new TransformComponent(glm::vec3(1.0));
		InitContent();
		InitSettingsButton();
		UpdatePanelName("Transform Component");

		QObject::connect(translationSpinBox1, &QDoubleSpinBox::textChanged, [this]() {m_Transform->Translation.x = translationSpinBox1->value(); });
		QObject::connect(translationSpinBox1, &QDoubleSpinBox::editingFinished, translationSpinBox1, &QDoubleSpinBox::clearFocus);
		QObject::connect(translationSpinBox2, &QDoubleSpinBox::textChanged, [this]() {m_Transform->Translation.y = translationSpinBox2->value(); });
		QObject::connect(translationSpinBox2, &QDoubleSpinBox::editingFinished, translationSpinBox2, &QDoubleSpinBox::clearFocus);
		QObject::connect(translationSpinBox3, &QDoubleSpinBox::textChanged, [this]() {m_Transform->Translation.z = translationSpinBox3->value(); });
		QObject::connect(translationSpinBox3, &QDoubleSpinBox::editingFinished, translationSpinBox3, &QDoubleSpinBox::clearFocus);

		QObject::connect(rotationSpinBox1, &QDoubleSpinBox::textChanged, [this]() {m_Transform->Rotation.x = glm::radians(rotationSpinBox1->value()); });
		QObject::connect(rotationSpinBox1, &QDoubleSpinBox::editingFinished, rotationSpinBox1, &QDoubleSpinBox::clearFocus);
		QObject::connect(rotationSpinBox2, &QDoubleSpinBox::textChanged, [this]() {m_Transform->Rotation.y = glm::radians(rotationSpinBox2->value()); });
		QObject::connect(rotationSpinBox2, &QDoubleSpinBox::editingFinished, rotationSpinBox2, &QDoubleSpinBox::clearFocus);
		QObject::connect(rotationSpinBox3, &QDoubleSpinBox::textChanged, [this]() {m_Transform->Rotation.z = glm::radians(rotationSpinBox3->value()); });
		QObject::connect(rotationSpinBox3, &QDoubleSpinBox::editingFinished, rotationSpinBox3, &QDoubleSpinBox::clearFocus);

		QObject::connect(scaleSpinBox1, &QDoubleSpinBox::textChanged, [this]() {m_Transform->Scale.x = scaleSpinBox1->value(); });
		QObject::connect(scaleSpinBox1, &QDoubleSpinBox::editingFinished, scaleSpinBox1, &QDoubleSpinBox::clearFocus);
		QObject::connect(scaleSpinBox2, &QDoubleSpinBox::textChanged, [this]() {m_Transform->Scale.y = scaleSpinBox2->value(); });
		QObject::connect(scaleSpinBox2, &QDoubleSpinBox::editingFinished, scaleSpinBox2, &QDoubleSpinBox::clearFocus);
		QObject::connect(scaleSpinBox3, &QDoubleSpinBox::textChanged, [this]() {m_Transform->Scale.z = scaleSpinBox3->value(); });
		QObject::connect(scaleSpinBox3, &QDoubleSpinBox::editingFinished, scaleSpinBox3, &QDoubleSpinBox::clearFocus);
	}

	void TransformPanel::InitContent()
	{
		QGridLayout* transformLayout = new QGridLayout(frameCenter);
		transformLayout->setSpacing(5);
		transformLayout->setObjectName(QStringLiteral("translationLayout"));
		transformLayout->setContentsMargins(15, 5, 15, 15);


		/* TRANSLATION */
		QLabel* translationLabel = new QLabel(frameCenter);
		translationLabel->setStyleSheet(QStringLiteral("color: white; font: 8pt  'Roboto';"));
		translationLabel->setText(QString::fromStdString("Position"));

		QFrame* translationSeparator = new QFrame(frameCenter);
		translationSeparator->setStyleSheet("background: transparent; border-right: 1px solid #414453;");
		translationSeparator->setMinimumWidth(1);

		translationSpinBox1 = new QDoubleSpinBox(frameCenter);
		translationSpinBox1->setButtonSymbols(QAbstractSpinBox::NoButtons);
		translationSpinBox1->setRange(-999999, 999999);
		translationSpinBox1->setSingleStep(1);
		translationSpinBox1->setValue(0);
		translationSpinBox1->setMinimumWidth(40);

		translationSpinBox2 = new QDoubleSpinBox(frameCenter);
		translationSpinBox2->setButtonSymbols(QAbstractSpinBox::NoButtons);
		translationSpinBox2->setRange(-999999, 999999);
		translationSpinBox2->setSingleStep(1);
		translationSpinBox2->setValue(0);
		translationSpinBox2->setMinimumWidth(40);

		translationSpinBox3 = new QDoubleSpinBox(frameCenter);
		translationSpinBox3->setButtonSymbols(QAbstractSpinBox::NoButtons);
		translationSpinBox3->setRange(-999999, 999999);
		translationSpinBox3->setSingleStep(1);
		translationSpinBox3->setValue(0);
		translationSpinBox3->setMinimumWidth(40);

		transformLayout->addWidget(translationLabel,0,0);
		transformLayout->addWidget(translationSeparator,0,1);
		transformLayout->addWidget(translationSpinBox1,0,2);
		transformLayout->addWidget(translationSpinBox2,0,3);
		transformLayout->addWidget(translationSpinBox3,0,4);

		/* ROTATION */
		QLabel* rotationLabel = new QLabel(frameCenter);
		rotationLabel->setStyleSheet(QStringLiteral("color: white; font: 8pt  'Roboto';"));
		rotationLabel->setText(QString::fromStdString("Rotation"));

		QFrame* rotationSeparator = new QFrame(frameCenter);
		rotationSeparator->setStyleSheet("background: transparent; border-right: 1px solid #414453;");
		rotationSeparator->setMinimumWidth(1);

		rotationSpinBox1 = new QDoubleSpinBox(frameCenter);
		rotationSpinBox1->setButtonSymbols(QAbstractSpinBox::NoButtons);
		rotationSpinBox1->setRange(-999999, 999999);
		rotationSpinBox1->setSingleStep(1);
		rotationSpinBox1->setValue(0);
		rotationSpinBox1->setMinimumWidth(30);

		rotationSpinBox2 = new QDoubleSpinBox(frameCenter);
		rotationSpinBox2->setButtonSymbols(QAbstractSpinBox::NoButtons);
		rotationSpinBox2->setRange(-999999, 999999);
		rotationSpinBox2->setSingleStep(1);
		rotationSpinBox2->setValue(0);
		rotationSpinBox2->setMinimumWidth(30);

		rotationSpinBox3 = new QDoubleSpinBox(frameCenter);
		rotationSpinBox3->setButtonSymbols(QAbstractSpinBox::NoButtons);
		rotationSpinBox3->setRange(-999999, 999999);
		rotationSpinBox3->setSingleStep(1);
		rotationSpinBox3->setValue(0);
		rotationSpinBox3->setMinimumWidth(30);

		transformLayout->addWidget(rotationLabel, 1, 0);
		transformLayout->addWidget(rotationSeparator, 1, 1);
		transformLayout->addWidget(rotationSpinBox1, 1, 2);
		transformLayout->addWidget(rotationSpinBox2, 1, 3);
		transformLayout->addWidget(rotationSpinBox3, 1, 4);

		/* SCALE */
		QLabel* scaleLabel = new QLabel(frameCenter);
		scaleLabel->setStyleSheet(QStringLiteral("color: white; font: 8pt  'Roboto';"));
		scaleLabel->setText(QString::fromStdString("Scale"));

		QFrame* scaleSeparator = new QFrame(frameCenter);
		scaleSeparator->setStyleSheet("background: transparent; border-right: 1px solid #414453;");
		scaleSeparator->setMinimumWidth(1);

		scaleSpinBox1 = new QDoubleSpinBox(frameCenter);
		scaleSpinBox1->setButtonSymbols(QAbstractSpinBox::NoButtons);
		scaleSpinBox1->setRange(-999999, 999999);
		scaleSpinBox1->setSingleStep(1);
		scaleSpinBox1->setValue(0);
		scaleSpinBox1->setMinimumWidth(30);

		scaleSpinBox2 = new QDoubleSpinBox(frameCenter);
		scaleSpinBox2->setButtonSymbols(QAbstractSpinBox::NoButtons);
		scaleSpinBox2->setRange(-999999, 999999);
		scaleSpinBox2->setSingleStep(1);
		scaleSpinBox2->setValue(0);
		scaleSpinBox2->setMinimumWidth(30);

		scaleSpinBox3 = new QDoubleSpinBox(frameCenter);
		scaleSpinBox3->setButtonSymbols(QAbstractSpinBox::NoButtons);
		scaleSpinBox3->setRange(-999999, 999999);
		scaleSpinBox3->setSingleStep(1);
		scaleSpinBox3->setValue(0);
		scaleSpinBox3->setMinimumWidth(30);

		transformLayout->addWidget(scaleLabel, 2, 0);
		transformLayout->addWidget(scaleSeparator, 2, 1);
		transformLayout->addWidget(scaleSpinBox1, 2, 2);
		transformLayout->addWidget(scaleSpinBox2, 2, 3);
		transformLayout->addWidget(scaleSpinBox3, 2, 4);

		transformLayout->setColumnStretch(1, 1);
		transformLayout->setColumnStretch(2, 1);
		transformLayout->setColumnStretch(3, 1);
		transformLayout->setColumnStretch(4, 1);

		transformLayout->setAlignment(frameCenter, Qt::AlignTop);
	}

	void TransformPanel::UpdateContent()
	{
		if (m_Transform)
		{
			if (!translationSpinBox1->hasFocus())
				translationSpinBox1->setValue(m_Transform->Translation.x);

			if (!translationSpinBox2->hasFocus())
				translationSpinBox2->setValue(m_Transform->Translation.y);

			if (!translationSpinBox3->hasFocus())
				translationSpinBox3->setValue(m_Transform->Translation.z);

			if (!rotationSpinBox1->hasFocus())
				rotationSpinBox1->setValue(glm::degrees(m_Transform->Rotation.x));

			if (!rotationSpinBox2->hasFocus())
				rotationSpinBox2->setValue(glm::degrees(m_Transform->Rotation.y));

			if (!rotationSpinBox3->hasFocus())
				rotationSpinBox3->setValue(glm::degrees(m_Transform->Rotation.z));

			if (!scaleSpinBox1->hasFocus())
				scaleSpinBox1->setValue(m_Transform->Scale.x);

			if (!scaleSpinBox2->hasFocus())
				scaleSpinBox2->setValue(m_Transform->Scale.y);

			if (!scaleSpinBox3->hasFocus())
				scaleSpinBox3->setValue(m_Transform->Scale.z);
		}
	}

	void TransformPanel::InitSettingsButton()
	{
		QMenu* SettingsMenu = new QMenu(m_SettingsButton);

		QAction* RemoveTransformComponentAction = new QAction(tr("&Remove Component"), this);
		QObject::connect(RemoveTransformComponentAction, &QAction::triggered, [this]() { emit RemoveTransformComponent(); });

		SettingsMenu->addAction(RemoveTransformComponentAction);
		m_SettingsButton->setMenu(SettingsMenu);
	}

	void TransformPanel::SetTransform(TransformComponent* transform)
	{
		m_Transform = transform;
		UpdateContent();
	}

	void TransformPanel::UpdateUI()
	{
		UpdateContent();
	}
}