#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> merge(const vector<int>& left, const vector<int>& right)
{
    vector<int> res;

    size_t leftIt = 0;
    size_t rightIt = 0;

    while(res.size() < left.size() + right.size())
    {
        if(left.size() == leftIt)
        {
            res.push_back(right.at(rightIt++));
            continue;
        }

        if(right.size() == rightIt)
        {
            res.push_back(left.at(leftIt++));
            continue;
        }

        if(left.at(leftIt) < right.at(rightIt))
        {
            res.push_back(left.at(leftIt++));
        }
        else
        {
            res.push_back(right.at(rightIt++));
        }
    }

    return res;
}

vector<int> mergeSort(const vector<int>& unsorted)
{
    vector<int> left;
    vector<int> right;
    vector<int> res;

    unsigned i = 0;
    unsigned pivot = unsorted.size() / 2;

    for(const auto& next : unsorted)
    {
        if(i < pivot)
        {
            left.push_back(next);
        }
        else
        {
            right.push_back(next);
        }

        ++i;
    }

    if(left.size() <= 1)
    {
        return merge(left, right);
    }

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

int main()
{
    vector<int> unsorted{1, 9, 4, 42, 1, 1, 4, 9};
//    vector<int> unsorted{1, 2, 3, 4};
//    vector<int> unsorted{4, 3, 2, 1};

    for(const auto& next : mergeSort(unsorted))
    {
        cout << next << ' ';
    }

    cout << endl;

    return 0;
}

