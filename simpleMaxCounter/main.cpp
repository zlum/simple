#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

struct Res
{
    explicit Res(int size): arr(new int[size]), n(size) {}
    ~Res() { delete[] arr; }

    int* arr = nullptr;
    int n = 0;
};

Res* findMax(int a[], int n)
{
    if(n == 0) return nullptr;

    int max = a[0];
    int count = 1;

    for(int i = 1; i < n - 1; ++i)
    {
        if(a[i] > max)
        {
            max = a[i];
            count = 1;
        }
        else
        if(a[i] == max)
        {
            ++count;
        }
    }

    Res* res = new Res(count);

    for(int i = 0; i < count; ++i)
    {
        res->arr[i] = max;
    }

    return res;
}

int main()
{
    int arr[] = {1,10,12,22,34,7,3,34,2};

    Res* res = findMax(arr, sizeof(arr) / sizeof(int));

    if(res != nullptr)
    {
        for(int i = 0; i < res->n; ++i)
        {
            cout << res->arr[i];
            if(i < res->n - 1) cout << ", ";
        }

        cout << endl;

        delete res;
    }

    return 0;
}
