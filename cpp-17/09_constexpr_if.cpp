#include <iostream>

template <typename T>
void print(T _param)
{
    if constexpr (std::is_integral_v<T>)
    {
        std::cout<<"Num : "<<_param<<std::endl;
    }
    else
    {
        std::cout<<"Not Integer : "<<_param<<std::endl;
    }
}

int main()
{
    print(12);
    std::string apple = "Apple";
    print("Apple");
    return 0;
}