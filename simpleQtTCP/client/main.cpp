#include "client.h"

#include <QApplication>

using namespace std;

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    Client client("localhost", 6522);
    client.show();

    return QApplication::exec();
}
