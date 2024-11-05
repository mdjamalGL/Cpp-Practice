#include <iostream>

constexpr float getPi()
{
    float pi = float(22)/7;
    // pi = pi*100.0;
    // pi = pi/100.0;
    return pi;
}
int main()
{
    constexpr auto pi = getPi();

    // if constexpr ()
    std::cout<<"Pi : "<<pi<<std::endl;
    return 0;
}