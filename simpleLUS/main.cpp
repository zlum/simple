#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int findLongestSimpleUniqueSubstr(const string& input)
{
    unordered_set<char> presented;

    int curLen = 0;
    int maxLen = 0;

    for(const auto& next : input)
    {
        if(presented.emplace(next).second)
        {
            // It is a new character

            if(++curLen > maxLen) maxLen = curLen;
        }
        else
        {
            // Repeating character has been found
            // Update presented character set and curLen to use with next substr
            presented.clear();
            presented.emplace(next);
            curLen = 1;
        }
    }

    return maxLen;
}

int main()
{
    cout << findLongestSimpleUniqueSubstr("QweasdQweasdzxcQweasd") << endl;

    return 0;
}

