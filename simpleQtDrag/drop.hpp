#ifndef DROP_HPP
#define DROP_HPP

#include <QtWidgets>
#include <QDebug>

class Drop: public QLabel
{
    Q_OBJECT

public:
    Drop(QWidget* pwgt = nullptr):
        QLabel("Drop area")
    {
        setAcceptDrops(true);
    }

protected:
    virtual void dragEnterEvent(QDragEnterEvent* pe)
    {
//        if(pe->mimeData()->hasFormat("text/uri-list"))
        {
            pe->acceptProposedAction();
        }
    }

    virtual void dropEvent(QDropEvent* pe)
    {
        setText("Dropped:\n" + pe->mimeData()->text());
    }
};

#endif // DROP_HPP
