#ifndef DRAG_HPP
#define DRAG_HPP

#include <iostream>
#include <string>

#include <QDebug>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QLabel>
#include <QMimeData>
#include <QDrag>
#include <QMouseEvent>
#include <QApplication>

class Drag: public QLabel
{
    Q_OBJECT

public:
    Drag(QWidget* pwgt = nullptr): QLabel("This is а draggable text", pwgt) {}

protected:
    virtual void mousePressEvent(QMouseEvent* pe)
    {
        if(pe->button() == Qt::LeftButton)
        {
            if(pe->button())
            {
                m_ptDragPos = pe->pos();
            }

            QWidget::mousePressEvent(pe);
        }
    }

    virtual void mouseMoveEvent(QMouseEvent* pe)
    {
        if(pe->buttons() & Qt::LeftButton)
        {
            int distance = (pe->pos() - m_ptDragPos).manhattanLength();

            if(distance > QApplication::startDragDistance())
            {
                startDrag();
            }
        }

        QWidget::mouseMoveEvent(pe);
    }

private:
    QPoint m_ptDragPos;

    void startDrag()
    {
        auto pMimeData = new QMimeData{};
        pMimeData->setText(text());

        QDrag* pDrag = new QDrag(this);
        pDrag->setMimeData(pMimeData);
        pDrag->setPixmap(QPixmap(":/imgl.png"));
        pDrag->exec();
    }
};

#endif // DRAG_HPP
