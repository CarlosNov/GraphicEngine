#include "LightPanel.h"

#include <string>
#include <sstream>

#include <QVBoxLayout>
#include <QMenu>
#include <QAction>
#include <QColorDialog>


namespace GraphicEngine
{
	LightPanel::LightPanel(QWidget* parent) : InspectorPanel(parent)
	{
		m_Light = new LightComponent();
		InitContent();
		InitSettingsButton();
		UpdatePanelName("Light Component");

		QObject::connect(m_LightTypeComboBox, qOverload<int>(&QComboBox::currentIndexChanged), [this](int index)
			{
				switch (index)
				{
				case 0:
					m_Light->Light.SetLightType(SceneLight::LightType::Point);
					break;

				case 1:
					m_Light->Light.SetLightType(SceneLight::LightType::Directional);
					break;
				}
			});

		QObject::connect(m_ColorSelectorButton, &QPushButton::clicked, [this]() { ChangeColor();  });
		QObject::connect(m_ColorSelectorButton2, &QPushButton::clicked, [this]() { ChangeColor();  });

		QObject::connect(m_LinearSpinBox, &QDoubleSpinBox::textChanged, [this]() {m_Light->Light.SetPointLinear(m_LinearSpinBox->value()); });
		QObject::connect(m_LinearSpinBox, &QDoubleSpinBox::editingFinished, m_LinearSpinBox, &QDoubleSpinBox::clearFocus);
		QObject::connect(m_QuadraticSpinBox, &QDoubleSpinBox::textChanged, [this]() {m_Light->Light.SetPointQuadratic(m_QuadraticSpinBox->value()); });
		QObject::connect(m_QuadraticSpinBox, &QDoubleSpinBox::editingFinished, m_QuadraticSpinBox, &QDoubleSpinBox::clearFocus);

		QObject::connect(m_DirectionSpinBox1, &QDoubleSpinBox::textChanged, [this]() {m_Light->Light.SetDirectionX(m_DirectionSpinBox1->value());});
		QObject::connect(m_DirectionSpinBox1, &QDoubleSpinBox::editingFinished, m_DirectionSpinBox1, &QDoubleSpinBox::clearFocus);
		QObject::connect(m_DirectionSpinBox2, &QDoubleSpinBox::textChanged, [this]() {m_Light->Light.SetDirectionY(m_DirectionSpinBox2->value()); });
		QObject::connect(m_DirectionSpinBox2, &QDoubleSpinBox::editingFinished, m_DirectionSpinBox2, &QDoubleSpinBox::clearFocus);
		QObject::connect(m_DirectionSpinBox3, &QDoubleSpinBox::textChanged, [this]() {m_Light->Light.SetDirectionZ(m_DirectionSpinBox3->value()); });
		QObject::connect(m_DirectionSpinBox3, &QDoubleSpinBox::editingFinished, m_DirectionSpinBox3, &QDoubleSpinBox::clearFocus);
	}

	void LightPanel::InitContent()
	{
		QVBoxLayout* lightLayout = new QVBoxLayout(frameCenter);
		lightLayout->setSpacing(0);
		lightLayout->setObjectName(QStringLiteral("lightLayout"));
		lightLayout->setContentsMargins(0, 0, 0, 0);
		lightLayout->setAlignment(Qt::AlignTop);

		QFrame* lightFrame = new QFrame(frameCenter);
		lightFrame->setStyleSheet("QFrame { background: transparent; }");

		QGridLayout* lightTypeLayout = new QGridLayout(lightFrame);
		lightTypeLayout->setSpacing(5);
		lightTypeLayout->setObjectName(QStringLiteral("lightTypeLayout"));
		lightTypeLayout->setContentsMargins(15, 5, 15, 15);
		lightTypeLayout->setAlignment(Qt::AlignTop);

		QLabel* lightTypeLabel = new QLabel(lightFrame);
		lightTypeLabel->setStyleSheet(QStringLiteral("color: white; font: 8pt  'Roboto';"));
		lightTypeLabel->setText(QString::fromStdString("Light Type"));

		QFrame* lightTypeSeparator = new QFrame(lightFrame);
		lightTypeSeparator->setStyleSheet("background: transparent; border-right: 1px solid #414453;");
		lightTypeSeparator->setMinimumWidth(1);
		lightTypeSeparator->setMinimumWidth(5);

		m_LightTypeComboBox = new QComboBox(lightFrame);
		m_LightTypeComboBox->setMinimumWidth(100);

		QStringList projectionList = { "Point", "Directional" };
		m_LightTypeComboBox->insertItems(0, projectionList);

		lightTypeLayout->addWidget(lightTypeLabel, 0, 0);
		lightTypeLayout->addWidget(lightTypeSeparator, 0, 1);
		lightTypeLayout->addWidget(m_LightTypeComboBox, 0, 2);

		/* POINT LIGHT */

		m_PointFrame = new QFrame(frameCenter);
		m_PointFrame->setStyleSheet("QFrame { background: transparent; }");

		QGridLayout* pointLayout = new QGridLayout(m_PointFrame);
		pointLayout->setSpacing(5);
		pointLayout->setObjectName(QStringLiteral("pointLayout"));
		pointLayout->setContentsMargins(15, 0, 15, 15);
		pointLayout->setAlignment(Qt::AlignTop);
		pointLayout->setColumnStretch(2, 1);

		QLabel* colorLabel = new QLabel(m_PointFrame);
		colorLabel->setStyleSheet(QStringLiteral("color: white; font: 8pt  'Roboto';"));
		colorLabel->setText(QString::fromStdString("Color"));

		QFrame* colorSeparator = new QFrame(m_PointFrame);
		colorSeparator->setStyleSheet("background: transparent; border-right: 1px solid #414453;");
		colorSeparator->setMinimumWidth(1);
		colorSeparator->setMinimumWidth(5);

		m_ColorFrame = new QFrame(m_PointFrame);
		m_ColorFrame->setStyleSheet("background: #414453; border: 1px solid #414453;");
		m_ColorFrame->setMinimumWidth(40);

		m_ColorSelectorButton = new QPushButton(QIcon(":/Assets/Assets/color-pickup.png"), QString(""), m_PointFrame);
		m_ColorSelectorButton->setMinimumWidth(20);
		m_ColorSelectorButton->setMaximumWidth(20);

		pointLayout->addWidget(colorLabel, 0, 0);
		pointLayout->addWidget(colorSeparator, 0, 1);
		pointLayout->addWidget(m_ColorFrame, 0, 2);
		pointLayout->addWidget(m_ColorSelectorButton, 0, 3);

		QLabel* linearLabel = new QLabel(m_PointFrame);
		linearLabel->setStyleSheet(QStringLiteral("color: white; font: 8pt  'Roboto';"));
		linearLabel->setText(QString::fromStdString("Linear"));

		QFrame* linearSeparator = new QFrame(m_PointFrame);
		linearSeparator->setStyleSheet("background: transparent; border-right: 1px solid #414453;");
		linearSeparator->setMinimumWidth(1);
		linearSeparator->setMinimumWidth(5);

		m_LinearSpinBox = new QDoubleSpinBox(m_PointFrame);
		m_LinearSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
		m_LinearSpinBox->setRange(-999999, 999999);
		m_LinearSpinBox->setSingleStep(1);
		m_LinearSpinBox->setValue(0);
		m_LinearSpinBox->setMinimumWidth(40);

		pointLayout->addWidget(linearLabel, 2, 0);
		pointLayout->addWidget(linearSeparator, 2, 1);
		pointLayout->addWidget(m_LinearSpinBox, 2, 2);

		QLabel* quadraticLabel = new QLabel(m_PointFrame);
		quadraticLabel->setStyleSheet(QStringLiteral("color: white; font: 8pt  'Roboto';"));
		quadraticLabel->setText(QString::fromStdString("Constant"));

		QFrame* quadraticSeparator = new QFrame(m_PointFrame);
		quadraticSeparator->setStyleSheet("background: transparent; border-right: 1px solid #414453;");
		quadraticSeparator->setMinimumWidth(1);
		quadraticSeparator->setMinimumWidth(5);

		m_QuadraticSpinBox = new QDoubleSpinBox(m_PointFrame);
		m_QuadraticSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
		m_QuadraticSpinBox->setRange(-999999, 999999);
		m_QuadraticSpinBox->setSingleStep(1);
		m_QuadraticSpinBox->setValue(0);
		m_QuadraticSpinBox->setMinimumWidth(40);

		pointLayout->addWidget(quadraticLabel, 3, 0);
		pointLayout->addWidget(quadraticSeparator, 3, 1);
		pointLayout->addWidget(m_QuadraticSpinBox, 3, 2);

		/* DIRECTONAL LIGHT */

		m_DirectionalFrame = new QFrame(frameCenter);
		m_DirectionalFrame->setStyleSheet("QFrame { background: transparent; }");

		QGridLayout* directionalLayout = new QGridLayout(m_DirectionalFrame);
		directionalLayout->setSpacing(5);
		directionalLayout->setObjectName(QStringLiteral("directionalLayout"));
		directionalLayout->setContentsMargins(15, 0, 15, 15);
		directionalLayout->setAlignment(Qt::AlignTop);
		directionalLayout->setColumnStretch(2, 1);

		QLabel* colorLabel2 = new QLabel(m_DirectionalFrame);
		colorLabel2->setStyleSheet(QStringLiteral("color: white; font: 8pt  'Roboto';"));
		colorLabel2->setText(QString::fromStdString("Color"));

		QFrame* colorSeparator2 = new QFrame(m_DirectionalFrame);
		colorSeparator2->setStyleSheet("background: transparent; border-right: 1px solid #414453;");
		colorSeparator2->setMinimumWidth(1);
		colorSeparator2->setMinimumWidth(5);

		m_ColorFrame2 = new QFrame(m_DirectionalFrame);
		m_ColorFrame2->setStyleSheet("background: #414453; border: 1px solid #414453;");
		m_ColorFrame2->setMinimumWidth(40);

		m_ColorSelectorButton2 = new QPushButton(QIcon(":/Assets/Assets/color-pickup.png"), QString(""), m_DirectionalFrame);
		m_ColorSelectorButton2->setMinimumWidth(20);
		m_ColorSelectorButton2->setMaximumWidth(20);

		directionalLayout->addWidget(colorLabel2, 0, 0);
		directionalLayout->addWidget(colorSeparator2, 0, 1);
		directionalLayout->addWidget(m_ColorFrame2, 0, 2, 1, 3);
		directionalLayout->addWidget(m_ColorSelectorButton2, 0, 5);

		QLabel* directionLabel = new QLabel(m_DirectionalFrame);
		directionLabel->setStyleSheet(QStringLiteral("color: white; font: 8pt  'Roboto';"));
		directionLabel->setText(QString::fromStdString("Direction"));

		QFrame* directionalSeparator = new QFrame(m_DirectionalFrame);
		directionalSeparator->setStyleSheet("background: transparent; border-right: 1px solid #414453;");
		directionalSeparator->setMinimumWidth(1);

		m_DirectionSpinBox1 = new QDoubleSpinBox(m_DirectionalFrame);
		m_DirectionSpinBox1->setButtonSymbols(QAbstractSpinBox::NoButtons);
		m_DirectionSpinBox1->setRange(-999999, 999999);
		m_DirectionSpinBox1->setSingleStep(1);
		m_DirectionSpinBox1->setValue(0);
		m_DirectionSpinBox1->setMinimumWidth(40);

		m_DirectionSpinBox2 = new QDoubleSpinBox(m_DirectionalFrame);
		m_DirectionSpinBox2->setButtonSymbols(QAbstractSpinBox::NoButtons);
		m_DirectionSpinBox2->setRange(-999999, 999999);
		m_DirectionSpinBox2->setSingleStep(1);
		m_DirectionSpinBox2->setValue(0);
		m_DirectionSpinBox2->setMinimumWidth(40);

		m_DirectionSpinBox3 = new QDoubleSpinBox(m_DirectionalFrame);
		m_DirectionSpinBox3->setButtonSymbols(QAbstractSpinBox::NoButtons);
		m_DirectionSpinBox3->setRange(-999999, 999999);
		m_DirectionSpinBox3->setSingleStep(1);
		m_DirectionSpinBox3->setValue(0);
		m_DirectionSpinBox3->setMinimumWidth(40);

		directionalLayout->addWidget(directionLabel, 1, 0);
		directionalLayout->addWidget(directionalSeparator, 1, 1);
		directionalLayout->addWidget(m_DirectionSpinBox1, 1, 2);
		directionalLayout->addWidget(m_DirectionSpinBox2, 1, 3);
		directionalLayout->addWidget(m_DirectionSpinBox3, 1, 4);

		lightLayout->addWidget(lightFrame);
		lightLayout->addWidget(m_PointFrame);
		lightLayout->addWidget(m_DirectionalFrame);
	}

	void LightPanel::UpdateContent()
	{
		if (m_Light)
		{
			std::ostringstream oss;
			glm::vec4 color = m_Light->Light.GetColor();
			oss << "background: rgba(" << color.r << "," << color.g << "," << color.b << "," << color.a  << "); border: 1px solid #414453;";
			std::string stylesheet = oss.str();
			
			switch (m_Light->Light.GetLightType())
			{
			case SceneLight::LightType::Point:
				m_PointFrame->setVisible(true);
				m_DirectionalFrame->setVisible(false);
				m_ColorFrame->setStyleSheet(QString::fromStdString(stylesheet));	

				if (!m_LightTypeComboBox->hasFocus())
					m_LightTypeComboBox->setCurrentIndex(0);

				if (!m_LinearSpinBox->hasFocus())
					m_LinearSpinBox->setValue(m_Light->Light.GetPointLinear());
				if (!m_QuadraticSpinBox->hasFocus())
					m_QuadraticSpinBox->setValue(m_Light->Light.GetPointQuadratic());
				break;
					
				break;

			case SceneLight::LightType::Directional:
				m_PointFrame->setVisible(false);
				m_DirectionalFrame->setVisible(true);
				m_ColorFrame2->setStyleSheet(QString::fromStdString(stylesheet));

				if (!m_LightTypeComboBox->hasFocus())
					m_LightTypeComboBox->setCurrentIndex(1);

				if (!m_DirectionSpinBox1->hasFocus())
					m_DirectionSpinBox1->setValue(m_Light->Light.GetDirection().x);

				if (!m_DirectionSpinBox2->hasFocus())
					m_DirectionSpinBox2->setValue(m_Light->Light.GetDirection().y);

				if (!m_DirectionSpinBox3->hasFocus())
					m_DirectionSpinBox3->setValue(m_Light->Light.GetDirection().z);

				break;

			default:
				break;
			}
		}
	}

	void LightPanel::InitSettingsButton()
	{
		QMenu* SettingsMenu = new QMenu(m_SettingsButton);

		QAction* RemoveLightComponentAction = new QAction(tr("&Remove Component"), this);
		QObject::connect(RemoveLightComponentAction, &QAction::triggered, [this]() { emit RemoveLightComponent(); });

		SettingsMenu->addAction(RemoveLightComponentAction);
		m_SettingsButton->setMenu(SettingsMenu);
	}

	void LightPanel::SetLight(LightComponent* light)
	{
		m_Light= light;
		UpdateContent();
	}

	void LightPanel::ChangeColor()
	{
		glm::vec4 colorVec4 = m_Light->Light.GetColor();
		QColor color(colorVec4.r, colorVec4.g, colorVec4.b, colorVec4.a);
		QColorDialog dialog = QColorDialog();
		QColor finalColor = dialog.getColor(color, this, tr("Select Color"));

		if (finalColor.isValid())
		{
			m_Light->Light.SetColor(glm::vec4(finalColor.red(), finalColor.green(), finalColor.blue(), finalColor.alpha()));
		}
	}

	void LightPanel::UpdateUI()
	{
		UpdateContent();
	}
}