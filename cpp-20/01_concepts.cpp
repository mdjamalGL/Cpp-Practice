#include <iostream>
#include <concepts>
#include <type_traits>

template <typename T>
concept Numeric = std::is_integral<T>::value || std::is_floating_point<T>::value;

template <typename T>
requires Numeric<T>
T add(T num1, T num2)
{
    return num1 + num2;
}



int main()
{
    int a = 2;
    int b = 4;
    std::cout<<"Add integer "<<a<<" + "<<b<<" : "<<add(a, b)<<std::endl;

    // std::string as = "apple";
    // std::string bs = "jamal";

    // std::cout<<"Add String "<<as<<" + "<<bs<<" : "<<add(as, bs)<<std::endl;
    return 0;
}