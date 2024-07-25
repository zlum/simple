#include "hacker.h"

#include "hackerClass.hpp"

void Hacker::hack(SimpleClass* obj)
{
    obj->_value = 15;
}
