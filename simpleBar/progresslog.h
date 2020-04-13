#ifndef PROGRESSLOG_H
#define PROGRESSLOG_H

#include <string>

class ProgressBar;

class ProgressLog
{
public:
    explicit ProgressLog(std::ostream& os, std::size_t logWidth);
    virtual ~ProgressLog();

    void write(const std::string& msg, double fraction);

private:
    ProgressBar* _bar;
    std::size_t _logHeigh;
    std::size_t _logWidth;
    std::ostream& _os;
};

#endif // PROGRESSLOG_H
