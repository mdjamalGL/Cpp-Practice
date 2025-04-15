#include <iostream>

template <typename T, typename ... Args>
T adder(T _first_arg, Args... _args)
{
    return _first_arg + (_args + ...);
    //fold expression was introdcued after cpp-17
}
int main()
{
    std::cout<<"1 + 2 + 3 + 4 : "<<adder(1,2,3,4)<<std::endl;
    std::cout<<"Hello +  World + 01 : "<<adder(std::string("Hello "), std::string("World ") , std::string("01"))<<std::endl;
    return 0;
}