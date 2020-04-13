#include "progressbar.h"

using namespace std;

ProgressBar::ProgressBar(ostream& os, size_t lineWidth,
                         const string& message, const char& symbol):
    _os{os},
    _barWidth{lineWidth - overhead},
    _message{message},
    _fullBar{string(_barWidth, symbol) + string(_barWidth, '.')}
{
    if(_message.size() + 1 >= _barWidth ||
       _message.find('\n') != _message.npos)
    {
        os << _message << '\n';
        _message.clear();
    }
    else
    {
        _message += ' ';
    }

    write(0.);
}

ProgressBar::~ProgressBar()
{
    write(1.);
    _os << '\n';
}

void ProgressBar::write(double fraction)
{
    // Clamp fraction to valid range [0,1]
    if(fraction < 0.)
    {
        fraction = 0.;
    }
    else if(fraction > 1.)
    {
        fraction = 1.;
    }

    auto width = _barWidth - _message.size();
    auto offset = _barWidth - static_cast<unsigned>(width * fraction);

    _os << '\r'
        << _message
        << '['
        << setw(3)
        << static_cast<int>(100. * fraction)
        << "%] "
        << '[';
    _os.write(_fullBar.data() + offset, width);
    _os << ']'
        << flush;
}
