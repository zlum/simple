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

    QWidget wgt;
    QStringListModel model;
    model.setStringList(QStringList()
                        << "Nightwish"
                        << "Evanescence"
                        << "Therion"
                        << "Epica"
                        << "Xandria");

    QSortFilterProxyModel proxyModel;
    proxyModel.setSourceModel(&model);
    proxyModel.setFilterWildcard("E*");

    QListView* pListViewl = new QListView;
    pListViewl->setModel(&model);
    QListView* pListView2 = new QListView;
    pListView2->setModel(&proxyModel);

    //Layout setup
    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(pListViewl);
    layout->addWidget(pListView2);
    wgt.setLayout(layout);
    wgt.show();

    return QApplication::exec();
}
