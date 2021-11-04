#include <iostream>
#include <string>
#include <cstdint>
#include <map>

using namespace std;

int main()
{
    map<int, char> m{{2, 'a'}, {4, 'b'}, {6, 'c'}, {8, 'd'}, {7, 'e'}};

    cout << endl << "Given" << endl;
    for(auto it = m.begin(); it != m.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }

    for(auto it = m.begin(); it != m.end();){
        if(it->first % 2 == 0) m.erase(it++);
        else ++it;
    }

    cout << endl << "Res" << endl;
    for(auto it = m.begin(); it != m.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}
