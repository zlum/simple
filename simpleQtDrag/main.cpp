#include "drag.hpp"
#include "drop.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    // Read arguments
    QStringList args = app.arguments();
    foreach(QString arg, args)
    {
    }

    Drag drag{};
    Drop drop{};
    drop.show();
    drag.show();

    return app.exec();
}
