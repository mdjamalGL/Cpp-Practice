#include <iostream>
#include <functional>

std::pair<int,int> return2Max(int num1, int num2, int num3)
{
    if( num1 > num2)
    {
        if(num2 > num3)
        {
            return {num1, num2};
        }
        else
        {
            return {num1, num3};
        }
    }
    else
    {
        if(num3 < num2)
        {
            if(num1 > num3)
            {
                return {num1, num2};
            }
            else
            {
                return {num3, num2};
            }
        }
        else{
            return {num2, num3};
        }
    }
}
int main()
{
    int num1, num2, num3;
    std::pair<int,int> ans;
    std::function<std::pair<int,int>(int,int,int)> max_cb = return2Max;
    std::cout<<"Enter Three Numbers : ";
    std::cin>>num1>>num2>>num3;
    ans = max_cb(num1, num2, num3);
    std::cout<<"Ans : "<<ans.first<<" "<<ans.second<<std::endl;
    ans = max_cb(num2, num3, num1);
    std::cout<<"Ans : "<<ans.first<<" "<<ans.second<<std::endl;

    return 0;
}