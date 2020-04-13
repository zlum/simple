#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;

class A
{
public:
    explicit A(): var(new int(2)) {}
    A(const A& other) noexcept
    {
        var = new int(*other.var);
        cout << "Copied" << endl;
    }

    A(A&& other) noexcept
    {
        var = exchange(other.var, nullptr);
        cout << "Moved" << endl;
    }

    virtual ~A() { delete var;}

    A& operator =(A other)
    {
        other.swap(*this);
        return *this;
    }

    void swap(A& other)
    {
        using std::swap;
        swap(var, other.var);
    }

    int* var;

    friend void swap(A& a, A& b)
    {
        a.swap(b);
    }
};

int main()
{
    A a;
    A b{};

    a = b;

//    cout << *a.var << endl;

    return 0;
}
