#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

int** findSubstringLen(const string& strA, const string& strB)
{
    int** arr = new int*[strA.size()];

    for(unsigned i = 0; i < strA.size(); i++)
    {
        arr[i] = new int[strB.size()];

        for(unsigned j = 0; j < strB.size(); j++)
        {
            if(strA.at(i) == strB.at(j))
            {
                int ii = i - 1;
                int jj = j - 1;

                if(ii < 0) ii = 0;
                if(jj < 0) jj = 0;

                arr[i][j] = arr[ii][jj] + 1;
            }
            else
            {
                int a, b;
                int ii = i - 1;
                int jj = j - 1;

                if((ii >= 0) && (jj >= 0))
                {
                    arr[i][j] = max(arr[ii][j], arr[i][jj]);
                }
                else if(jj >= 0)
                {
                    arr[i][j] = arr[i][jj];
                }
                else if(ii >= 0)
                {
                    arr[i][j] = arr[ii][j];
                }
                else
                {
                    arr[i][j] = 0;
                }
            }
        }
    }

    return arr;
}

int main()
{
    string strA = "queue";
    string strB = "eueue";

    int** arr = findSubstringLen(strA, strB);

    for(unsigned i = 0; i < strA.size(); i++)
    {
        for(unsigned j = 0; j < strB.size(); j++)
        {
            cout << int(arr[i][j]) << ' ';
        }

        cout << endl;
    }

    for(unsigned i = 0; i < strA.size(); i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}
