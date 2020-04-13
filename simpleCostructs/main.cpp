#include <iostream>
#include <string>

using namespace std;

class Vasiliy
{
public:
    explicit Vasiliy(int a, int* p = nullptr) {cout << "A" << endl; cout.flush();}
    explicit Vasiliy(int a, bool b = false, int* p = nullptr) {cout << "B" << endl; cout.flush();}
};

class Ivanovich
{
public:
    Vasiliy a{1, this};
};

int main()
{
    Ivanovich a;

    return 0;
}
