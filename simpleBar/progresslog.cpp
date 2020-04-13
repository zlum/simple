#include "progresslog.h"

#include "progressbar.h"

#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

ProgressLog::ProgressLog(std::ostream& os, size_t logWidth):
    _bar(new ProgressBar{os, logWidth, "Progress:", '#'}),
    _logHeigh(0),
    _logWidth(logWidth),
    _os(os)
{
}

ProgressLog::~ProgressLog()
{
    delete _bar;
}

void ProgressLog::write(const string& msg, double fraction)
{
    string line(msg + string(_logWidth - msg.size(), ' '));
    string space;

    for(size_t i = 0; i < _logHeigh; i++)
    {
        space += "\r\n";
    }

    _os << "\r" << line << "\r\n" << space;
    _bar->write(fraction);
}
