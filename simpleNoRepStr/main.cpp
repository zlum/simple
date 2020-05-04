#include <iostream>
#include <string>
#include <cstdint>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    std::unordered_map<char, int> chars;
    int cur = 0;
    int max = 0;
    int i = 0;
    int begin = 0;

    for(const auto& next : s)
    {
        auto res = chars.find(next);

        if(res == chars.end())
        {
            ++cur;
        }
        else
        {
            if(res->second < begin)
            {
                ++cur;
            }
            else
            {
                begin = res->second;
                cur = i - begin;
            }
        }

        chars[next] = i;
        if(cur > max) max = cur;
        ++i;
    }

    return max;
}

int main()
{
    cout << lengthOfLongestSubstring("asdasdcasd") << endl;

    return 0;
}
