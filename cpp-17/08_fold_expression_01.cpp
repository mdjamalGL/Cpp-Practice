#include <iostream>

template <typename... nums>
int add(nums... num)
{
    (std::cout<<...<<num);
    return (num + ...);
}

int main()
{
    std::cout<<add(1,2,3,4)<<std::endl;
    return 0;
}