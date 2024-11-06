#include <iostream>

int x = 20;
int main()
{
    int x = 10;
    //auto check_prime = [](int num) -> bool {} //this is also correct
    auto check_prime = [=](int num) {
        std::cout<<"x : "<<x<<std::endl; //this is captured from scope outside the lambda's.
        for(int i = 2 ; i <= num/2 ; i++)
        {
            if(num%i == 0)
            return false;
        }
        return true;
    };

    int a[] = {1,2,4,5,7,9,11,13,15,17};

    std::cout<<"Prime numbers are : ";
    for(int ele : a)
    {
        if(check_prime(ele))
        {
            std::cout<<ele<<" ";
        }
    }
    std::cout<<std::endl;
    return 0;
}