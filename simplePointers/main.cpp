#include <iostream>
#include <string>
#include <cstdint>
#include <iostream>
#include <cstring>

using namespace std;

#pragma pack(push,1)
struct Bar
{
    int8_t o;
    int16_t a;
};
#pragma pack(pop)

int8_t Arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void fun(int8_t* arr)
{
    int8_t* a = &arr[0];
    Bar* bar = (Bar*)a;
    bar++;

//    cout << "Arr " << (int)(Arr) << endl;
    cout << "a   " << (int)(bar->a) << endl;
    cout.flush();
}

int main()
{
    cout << "Sizeof " << sizeof(Bar) << endl;
//    memset(Arr, 1, sizeof(Arr));
    fun(Arr);

    return 0;
}
