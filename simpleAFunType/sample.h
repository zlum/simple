#pragma once

class A
{
    //using asd = int (A::*)(int);
    typedef int (A::* asd)(int);
    asd fn;
    int fun(int);
    void other();

    using qwe = int (A::*)(int);
    qwe second;
//    int fun(int a);
};
