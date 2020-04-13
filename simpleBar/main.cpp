// Test program

#include "progresslog.h"

#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

int main()
{
    ProgressLog progress{clog, 80u};

    for(auto i = 0.0; i <= 100.0; i += 3.666)
    {
        progress.write("Processing triggers for"
                       " man-db (2.8.5-2) ...",
                       i / 100.0);

        // simulate some work
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}
