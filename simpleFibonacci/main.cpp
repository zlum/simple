#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

int fibonacci(int a, int b, int limit) { if(b >= limit) return b; int c = a + b; cout << c << endl; fibonacci(b, c, limit); }

int main()
{
    cout << fibonacci(0, 1, 22) << endl;
    ;
    return 0;
}

