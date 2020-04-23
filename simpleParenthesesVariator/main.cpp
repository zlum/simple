#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

void generate(const string& str, int open, int close, const int pairs)
{
    if(open > pairs)
    {
        return;
    }

    if(close == pairs)
    {
        cout << str << endl;
    }

    if(close < open)
    {
        generate(str + ')', open, close + 1, pairs);
    }

    generate(str + '(', open + 1, close, pairs);
}

int main()
{
    const int pairs = 3;
    string str;

    generate(str, 0, 0, pairs);

    return 0;
}
