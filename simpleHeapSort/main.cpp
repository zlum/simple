#include <iostream>
#include <string>
#include <cstdint>
#include <vector>

using namespace std;

void heapify(vector<int>& vec, int n, int i)
{
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    int largest = i; // Root element

    if((left < n) && (vec[left] > vec[largest]))
    {
        largest = left;
    }

    if((right < n) && (vec[right] > vec[largest]))
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(vec[largest], vec[i]);
        heapify(vec, n, largest);
    }
}

vector<int> heapSort(vector<int> unsorted)
{
    // Make heap
    for(int i = (unsorted.size() / 2) - 1; i >= 0; i--)
    {
        heapify(unsorted, unsorted.size(), i);
    }

    // Move greatest to the end position and continue with smaller heap
    for(int i = unsorted.size() - 1; i >= 0; i--)
    {
        swap(unsorted[0], unsorted[i]);
        heapify(unsorted, i, 0);
    }

    return unsorted;
}

int main()
{
    vector<int> unsorted{1, 0, 3, 42, 7, 9, 9, 9, 7, 11, 0, 2};

    for(const auto& next : heapSort(unsorted))
    {
        cout << next << ' ';
    }

    cout << endl;

    return 0;
}
