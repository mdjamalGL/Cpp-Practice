#include <iostream>
#include <algorithm>

int main()
{
    int min = -10;
    int max = 10;

    int a = std::clamp(-20, min, max);
    int b = std::clamp(0, min, max);
    int c = std::clamp(30, min, max);

    std::cout<<"A : "<<a<<std::endl;
    std::cout<<"B : "<<b<<std::endl;
    std::cout<<"C : "<<c<<std::endl;
    return 0;
}