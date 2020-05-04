#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

int expandAroundCenter(const string& str, int left, int right)
{
    while(left >= 0 && right < str.size())
    {
        if(str.at(left) == str.at(right))
        {
            --left;
            ++right;
        }
        else
        {
            break;
        }
    }

    return right - left - 1;
}

string longestPalindrome(const string& str)
{
    if(str.size() < 1) return 0;

    int start = 0;
    int end = 0;

    for(int i = 0; i < str.size(); ++i)
    {
        int len1 = expandAroundCenter(str, i, i);
        int len2 = expandAroundCenter(str, i, i + 1);

        int len = max(len1, len2);

        if(len > end - start)
        {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }

    return str.substr(start, end - start + 1);
}

int main()
{
    cout << longestPalindrome("abracadabra") << endl;
//    cout << longestPalindrome("cbbd") << endl;

    return 0;
}

