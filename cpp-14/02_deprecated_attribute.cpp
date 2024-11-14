#include <iostream>

[[deprecated("This implementation is not efficient. Try function : \"Prime()\"")]]
bool isPrime(int num)
{
    for(int i = 2; i <= num/2 ; i++)
    {
        if(num%i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int num = 10;

    if(isPrime(num))
    {
        std::cout<<num<<" : Prime"<<std::endl;
    }
    else
    {
        std::cout<<num<<" : Not A Prime"<<std::endl;
    }
    return 0;
}