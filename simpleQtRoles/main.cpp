#include <iostream>
#include <string>
#include <cstdint>

#include <QApplication>
#include <QStandardItem>
#include <QtWidgets>

using namespace std;

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QStringList lst;
    lst << "Linux" << "Windows" << "MacOS" << "OS2";

    QStandardItemModel model(lst.size(), 1);

    for(int i = 0; i < model.rowCount(); ++i)
    {
        QModelIndex index = model.index(i, 0);
        QString str = lst.at(i);
        model.setData(index, str, Qt::DisplayRole);
        model.setData(index, "ToolTip for " + str, Qt::ToolTipRole);
        model.setData(index, QIcon(str + ".png"), Qt::DecorationRole);
    }

    QListView view;
    view.setViewMode(QListView::IconMode);
    view.setModel(&model);
    view.show();

    return QApplication::exec();
}
