#include <iostream>
#include <string>

using namespace std;

void bruteHelper(int len, const string& alp, int pos, string str, int ignore)
{
    if(pos >= len) return;

    for(size_t i = 0; i < alp.size(); ++i)
    {
        str[pos] = alp[i];
        bruteHelper(len, alp, pos + 1, str, ignore);

        if(i > size_t(ignore))
        {
            cout << str << endl;
        }
    }
}

void brute(int len, const string& alp)
{
    if(len <= 0) return;

    string str(len, alp[0]);

    cout << str << endl;

    bruteHelper(len, alp, 0, str, 0);
}

int main()
{
    brute(3, "ABCD");

    return 0;
}
