#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <cmath>
#include <iomanip>
#include <ostream>
#include <string>

class ProgressBar
{
public:
    ProgressBar(std::ostream& os, std::size_t lineWidth,
                const std::string& message, const char& symbol);

    // Not copyable
    ProgressBar(const ProgressBar&) = delete;
    ProgressBar& operator=(const ProgressBar&) = delete;

    virtual ~ProgressBar();

    void write(double fraction);

private:
    static constexpr auto overhead = sizeof(" [100%] ");

    std::ostream& _os;
    const std::size_t _barWidth;
    std::string _message;
    const std::string _fullBar;
};

#endif // PROGRESSBAR_H
