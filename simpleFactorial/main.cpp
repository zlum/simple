#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

int factorial(int x) { if(x == 1) return 1; return x * factorial(x - 1); }

int main()
{
    cout << factorial(4) << endl;
    return 0;
}

