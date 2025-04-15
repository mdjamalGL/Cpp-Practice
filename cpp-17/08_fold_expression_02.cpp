#include <iostream>
#include <vector>
#include <initializer_list>

template <typename... Args>
int enter(std::vector<int> &vec, int num)
{
    vec.push_back(num);
    return num;
}

template <typename... Args>
std::vector<int> make_vector(Args... arg)
{
    std::vector<int> ans;

    //(enter(ans,arg),...);
    (ans.push_back(arg), ...);

    return ans;
}

int main()
{
    std::vector<int> ret = make_vector(1,2,3,4);
    for(auto ele : ret)
    {
        std::cout<<ele<<" ";
        std::cout<<std::endl;
    }
    return 0;
}