#include <iostream>

/**
 * we can use ' as digit separator in c++
 * to make big numbers more readable.
 */
int main()
{
    int num1 = 1'000;
    int num2 = 12'122'435;

    std::cout<<"Num : 1'000 : "<<num1<<std::endl;
    std::cout<<"Num : 12'122'435 : "<<num2<<std::endl;
}
