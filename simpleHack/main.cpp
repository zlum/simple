#include <cstdio>
#include <type_traits>
#include <iostream>
#include <string>

template<class T> struct dependent_false : std::false_type {};
template <typename T>
void f() {
     if constexpr (std::is_arithmetic_v<T>)
     {
         std::cout << "ONE" << std::endl;
     }
     else
     {
         std::cout << "TWO" << std::endl;
         static_assert(dependent_false<T>::value, "Must be arithmetic"); // ok
     }
}

int main()
{
    f<int>();
}
