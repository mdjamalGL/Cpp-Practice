#include <iostream>
#include <optional>
#include <vector>

std::optional<std::vector<int>> get_primes(std::vector<int> vec)
{
    std::vector<int> ans;
    for(auto ele : vec)
    {
        bool divFlag = false;
        for(int i {2} ; i <= ele/2 ; i++)
        {
            if(ele%i == 0)
            {
                divFlag = true;
                break;
            }
        }
        if(!divFlag)
        {
            ans.push_back(ele);
        }
    }

    if(ans.size() == 0)
    {
        return {};
    }
    return ans;
}
int main()
{
    std::vector<int> vec {4,6,8,12};
    if(auto primes = get_primes(vec))
    {
        std::cout<<"Primes : ";
        for(auto ele : *primes)
        {
            std::cout<<ele<< " ";
        }
        std::cout<<std::endl;
    }
    else
    {
        std::cout<<"No prime among the vector"<<std::endl;
    }

    return 0;
}