#include "simpleClass.hpp"
#include "hackerLib/hacker.h"

int main()
{
    SimpleClass simpleClass;

    simpleClass.showValue();

    Hacker::hack(&simpleClass);

    simpleClass.showValue();

    return 0;
}

