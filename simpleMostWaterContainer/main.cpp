#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdint>

using namespace std;

int calcSquare(int left, int right, int height)
{
    int len = right - left;
    return len * height;
}

int maxArea(const vector<int>& height)
{
    int waterLvl = 1;
    int res = 0;
    int left = 0;
    int right = height.size() - 1;

    while(left < right)
    {
        waterLvl = min(height.at(left), height.at(right));
        res = max(res, calcSquare(left, right, waterLvl));

        if(height.at(left) < height.at(right))
        {
            ++left;
        }
        else
        {
            --right;
        }
    }

    return res;
}

int main()
{
    cout << maxArea({1, 8, 6, 2, 5, 4, 8, 3, 7}) << endl;

    return 0;
}

