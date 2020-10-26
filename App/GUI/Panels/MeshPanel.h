#pragma once

#include <QPushButton>
#include <QLabel>

#include "GUI/Panels/InspectorPanel.h"
#include "Scene/Components.h"

namespace GraphicEngine
{
	class MeshPanel : public InspectorPanel
	{
		Q_OBJECT

	public:
		MeshPanel(QWidget* parent = 0);
		~MeshPanel() {}

	signals:
		void RemoveMeshComponent();

	public slots:
		void SetMesh(MeshComponent* mesh);
		void LoadFileMesh();
		void UpdateUI();
	
	protected:
		void InitContent() override;
		void UpdateContent() override;
		void InitSettingsButton() override;

	protected:
		QPushButton* meshSelectorButton;
		QLabel* meshNameLabel;

	private:
		MeshComponent* m_Mesh;		
	};
}