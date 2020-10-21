#pragma once

#include <QFrame>
#include <QLabel>
#include <QLineEdit>

#include "Scene/Components.h"


namespace GraphicEngine
{
	class TagPanel : public QFrame
	{
		Q_OBJECT

	public:
		TagPanel(QWidget* parent = 0);
		~TagPanel() {}

	public slots:
		void SetTag(TagComponent* tag);
		void SetID(uint32_t id);
		void UpdateUI();

	protected:
		void UpdateContent();

	protected:
		QLineEdit* lineEditTag;
		QLabel* labelID;

	private:
		TagComponent* m_Tag;
		uint32_t m_EntityID;
	};
}

