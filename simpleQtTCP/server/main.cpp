#include "server.h"

#include <QApplication>

using namespace std;

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    Server server(6522);
    server.show();

    return QApplication::exec();
}
