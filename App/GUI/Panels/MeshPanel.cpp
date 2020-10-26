#include "MeshPanel.h"

#include <QGridLayout>
#include <QLabel>
#include <QFrame>
#include <QMenu>
#include <QAction>
#include <QFileDialog>

namespace GraphicEngine
{
	MeshPanel::MeshPanel(QWidget* parent) : InspectorPanel(parent)
	{
		m_Mesh = new MeshComponent();
		InitContent();
		InitSettingsButton();
		UpdatePanelName("Mesh Component");

		QObject::connect(meshSelectorButton, &QPushButton::clicked, [this]() { LoadFileMesh();  });
	}

	void MeshPanel::InitContent()
	{
		QGridLayout* meshLayout = new QGridLayout(frameCenter);
		meshLayout->setSpacing(5);
		meshLayout->setObjectName(QStringLiteral("meshLayout"));
		meshLayout->setContentsMargins(15, 5, 15, 15);
		meshLayout->setAlignment(Qt::AlignTop);

		QLabel* projectionLabel = new QLabel(frameCenter);
		projectionLabel->setStyleSheet(QStringLiteral("color: white; font: 8pt  'Roboto';"));
		projectionLabel->setText(QString::fromStdString("Mesh Object"));

		QFrame* projectionSeparator = new QFrame(frameCenter);
		projectionSeparator->setStyleSheet("background: transparent; border-right: 1px solid #414453;");
		projectionSeparator->setMinimumWidth(1);
		projectionSeparator->setMinimumWidth(5);

		meshNameLabel = new QLabel(frameCenter);
		meshNameLabel->setStyleSheet(QStringLiteral("background: #414453; color: white; font: 8pt  'Roboto'; padding-left: 5px;"));
		meshNameLabel->setText(QString::fromStdString(m_Mesh->FileName));

		meshSelectorButton = new QPushButton(QIcon(":/Assets/Assets/link.png"), QString(""), frameCenter);
		meshSelectorButton->setMinimumWidth(20);
		meshSelectorButton->setMaximumWidth(20);

		meshLayout->addWidget(projectionLabel, 0, 0);
		meshLayout->addWidget(projectionSeparator, 0, 1);
		meshLayout->addWidget(meshNameLabel, 0, 2);
		meshLayout->addWidget(meshSelectorButton, 0, 3);

		meshLayout->setColumnStretch(2, 1);
	}

	void MeshPanel::UpdateContent()
	{
		if (m_Mesh)
		{
			meshNameLabel->setText(QString::fromStdString(m_Mesh->FileName));
		}
	}

	void MeshPanel::InitSettingsButton()
	{
		QMenu* SettingsMenu = new QMenu(m_SettingsButton);

		QAction* RemoveMeshComponentAction = new QAction(tr("&Remove Component"), this);
		QObject::connect(RemoveMeshComponentAction, &QAction::triggered, [this]() { emit RemoveMeshComponent(); });

		SettingsMenu->addAction(RemoveMeshComponentAction);
		m_SettingsButton->setMenu(SettingsMenu);
	}

	/* SLOTS */

	void MeshPanel::SetMesh(MeshComponent* mesh)
	{
		m_Mesh = mesh;
		UpdateContent();
	}

	void MeshPanel::LoadFileMesh()
	{
		QString fileName = QFileDialog::getOpenFileName(this, tr("Open Mesh File"), "", tr("Object File (*.obj);;"));

		if (fileName.isEmpty())
			return;
		else 
		{
			m_Mesh->Mesh.Destroy();
			m_Mesh->Mesh =  Mesh(fileName.toStdString());
		}

		m_Mesh->FileName = fileName.toStdString();
	}

	void MeshPanel::UpdateUI()
	{
		UpdateContent();
	}
}