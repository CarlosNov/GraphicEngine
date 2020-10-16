#ifndef SECTION_HPP
#define SECTION_HPP

#include <QPushButton> //for the expand/collapse button
#include <QtDesigner/QDesignerExportWidget>
#include <QLayout>
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>
#include <QSize>

namespace GraphicEngine
{

    class Section : public QWidget
    {
        Q_OBJECT

            Q_PROPERTY(bool is_expanded MEMBER isExpanded)

    public:

        explicit Section(QWidget* parent = 0) : QWidget(parent), expandButton(this)
        {
            expandButton.resize(20, 20);
            expandButton.move(0, 0);
            expandButton.connect(&expandButton, &QPushButton::clicked,
                this, &Section::expandCollapseEvent);

            QMargins m = contentsMargins();
            m.setTop(m.top() + 25);
            setContentsMargins(m);
            //setSizePolicy(sizePolicy().horizontalPolicy(), QSizePolicy::Minimum);

        }

        virtual void expand(bool expanding) noexcept
        {
            /*
            resize(sizeHint());
            isExpanded = expanding;
            updateGeometry();

            qDebug() << (isExpanded ? "expanded" : "collapsed") << sizeHint() << QWidget::size() <<
                parentWidget()->layout()->closestAcceptableSize(this, size());
                */
        }

        virtual QSize sizeHint() const noexcept override
        {
            QSize* qsize = new QSize(200, 200);
            /*
            if (isExpanded) 
                return QSize(layout()->contentsRect().width(), layout()->contentsRect().height());
            else return QSize(layout()->contentsRect().width(), 20);
            */
            return *qsize;
        }

        // Implement custom appearance
        virtual void paintEvent(QPaintEvent* e) noexcept override
        {
            /*
            (void)e; //TODO: remove
            QPainter p(this);
            p.setClipRect(e->rect());
            p.setRenderHint(QPainter::Antialiasing);
            p.fillRect(e->rect(), QColor(0, 0, 255, 128));
            */
        }

    protected:

        virtual void expandCollapseEvent() noexcept
        {
            /*
            expand(!isExpanded);
            */
        }


        bool isExpanded = true; //whenever the section is collapsed(false) or expanded(true)
        QPushButton expandButton; //the expanding/collapsing button
    };

}
#endif // SECTION_HPP