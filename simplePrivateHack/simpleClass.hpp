#ifndef SIMPLE_CLASS_H
#define SIMPLE_CLASS_H

#include <iostream>

class SimpleClass
{
public:
    explicit SimpleClass() = default;
    ~SimpleClass() = default;

    void showValue() { std::cout << _value << std::endl; }

private:
    int _value = 2;
};

#endif // SIMPLE_CLASS_H
