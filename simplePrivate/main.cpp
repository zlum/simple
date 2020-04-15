#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

class Stealth
{
    Stealth() = default;

public:
    int a = 0;
};

int main()
{

    auto s = new Stealth{1};
    Stealth a{2};

    *s = a;

    cout << (*s).a << endl;

    delete s;

    return 0;
}

