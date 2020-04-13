#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;

int fun()
{
    cout << "fun" << endl;
    return 1;
}

int main()
{
//    auto a = new int(1);
    int a = 1;

    switch (a) {
    case 1 ... 2:
        cout << "LOLKEK" << endl;
    break;
    default:
        cout << "uuuuuuuu" << endl;
    break;
    }


    int res = fun() ?: 0;

    cout << res << endl;

    int i[2] = {2};
    cout << i[1] << endl;

    return 0;
}
