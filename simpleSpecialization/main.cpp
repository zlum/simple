#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

class A
{
public:
    template<typename T>
    static auto fun(T a) -> decltype(a)
    {
        return a;
    }

    int _b = 2;
};

template<>
auto A::fun<int>(int a) -> decltype(a)
{
    return 2;
}

int main()
{
    cout << A::fun(1.) << endl;
    cout << A::fun(1) << endl;

    return 0;
}
