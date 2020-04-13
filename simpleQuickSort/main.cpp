#include <iostream>
#include <string>
#include <cstdint>
#include <array>
#include <vector>

using namespace std;

vector<int> quickSort(vector<int> vec)
{
    if(vec.size() < 2) return vec;

    vector<int> less;
    vector<int> greater;
    const auto& pivot = vec.front();

    for(auto i = vec.begin() + 1; i != vec.end(); i++)
    {
        const auto& next = *i;

        if(next >= pivot)
        {
            greater.push_back(next);
        }
        else
        {
            less.push_back(next);
        }
    }

    greater = quickSort(greater);
    less = quickSort(less);

    less.push_back(pivot);
    less.insert(less.end(), greater.begin(), greater.end());

    return less;
}

int main()
{
    vector<int> vec{41, 6, 2, 3, 88, 11};
//    vector<int> vec{10, 2, 11};

    for(const auto& next : quickSort(vec))
    {
        cout << next << ' ';
    }

    cout << endl;

    return 0;
}

