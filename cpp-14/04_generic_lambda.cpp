#include <iostream>

int main()
{
    auto isPrime = [](auto num) {
        for(int i = 2; i <= num/2; i++)
        {
            if(num%i == 0)
            return false;
        }
        return true;
    };

    int num;
    std::cout<<"Enter Num : ";
    std::cin>>num;

    if(isPrime(num))
    {
        std::cout<<num<<" : Prime"<<std::endl;
    }
    else
    {
        std::cout<<num<<" : Not a Prime"<<std::endl;
    }
    return 0;

}