#include <iostream>
#include <string>

#include <QDebug>
#include <QFile>
#include <QString>
#include <QTextStream>

using namespace std;

int main()
{
    QFile file("test.txt");
    QTextStream stream(&file);

    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        return 1;
    }

    if (!file.isSequential())
    {
        file.seek(file.size());
    }

    stream << "check\r\n";
//    qDebug() << stream.readLine();

    while(!stream.atEnd())
    {
        qDebug() << stream.readLine();
    }

    return 0;
}
