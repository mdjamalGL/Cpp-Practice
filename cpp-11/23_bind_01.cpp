#include <iostream>
#include <functional>

int gcd_helper(int a, int b)
{
    if(a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    if(a == 0 )
    {
        return b;
    }
    if(b == 0)
    {
        return a;
    }

    return gcd_helper(b, a-b);
}
int main()
{
    int(*gcd_14)(int,int) = gcd_helper; 
    auto gcd_15 = std::bind(gcd_helper, 15, std::placeholders::_1);
    auto gcd = std::bind(gcd_helper, std::placeholders::_1, std::placeholders::_2);

    int num1 = 0, num2 = 0;
    std::cout<<"Enter num1, num2 : ";
    std::cin>>num1>>num2;
    std::cout<<"gcd of "<<num1<<" : "<<"14"<<" - "<<gcd_14(num1, 14)<<std::endl;
    std::cout<<"gcd of "<<num1<<" : "<<"15"<<" - "<<gcd_15(num1)<<std::endl;
    std::cout<<"gcd of "<<num1<<" : "<<num2<<" - "<<gcd(num1, num2)<<std::endl;
    return 0;
}