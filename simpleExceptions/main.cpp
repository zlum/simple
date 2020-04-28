#include <cstdint>
#include <exception>
#include <iostream>
#include <string>
#include <memory>

using namespace std;

class C
{
public:
    C() { throw runtime_error("C"); }
};

class B
{
public:
    B()
    {
        cout << "Hello!" << endl;
    }

    ~B()
    {
        cout << "Goodbye!" << endl;
    }
};

class A
{
public:
    A(): nested(make_shared<B>()), c{}
    {
        cout << "Object under construction" << endl;
        throw runtime_error("boom!");
    }

    ~A()
    {
        cout << "Destruction started" << endl;
//        throw runtime_error("boom!"); // leads to std terminate
    }

    shared_ptr<B> nested;
    C c;
};

int main()
{
    try
    {
        A a;
    }
    catch(...)
    {
        cout << "Catch!" << endl;
    }

    return 0;
}
