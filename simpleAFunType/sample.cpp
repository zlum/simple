#include "sample.h"

void A::other()
{
    this->fn = &A::fun;
    (this->*fn)(5);
}

int A::fun(int a)
{
    return a;
}
