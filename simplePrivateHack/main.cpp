#include "simpleClass.hpp"
#include "hacker.h"

int main()
{
    SimpleClass simpleClass;

    simpleClass.showValue();

    Hacker::hack(&simpleClass);

    simpleClass.showValue();

    return 0;
}

