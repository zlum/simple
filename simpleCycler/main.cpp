#include "cyclecaller.h"

#include <cstdint>
#include <iostream>
#include <string>
#include <thread>

using namespace std;

int main()
{
    CycleCaller cyc;
    int a;
    cin >> a;
//    cyc.setFullcycleSleeptime(200.0);
    cyc.setFullcycleSleeptime(1500000.0);

    for(int i = 0; i < 500; i++)
    {
        cyc.addFunction([](){cout << "justZero!" << endl;});
        cyc.addFunction([](){cout << "funNumOne" << endl;});
        cyc.addFunction([](){cout << "fooNumTwo" << endl;});
    }

    cyc.start();
    this_thread::sleep_for(std::chrono::duration<double, std::milli>(1600));
    cyc.stop();
    this_thread::sleep_for(std::chrono::duration<double, std::milli>(1600));
    cyc.start();
    this_thread::sleep_for(std::chrono::duration<double, std::milli>(1600));

    return 0;
}
