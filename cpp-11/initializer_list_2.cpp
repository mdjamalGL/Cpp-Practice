#include <iostream>

/**
 * For loop with initializer_list
 * 
 */
int main()
{
    for(auto &ele : {1, 2, 3 ,4})
    {
        std::cout << &ele << " ";
    }
    std::cout<<std::endl;
    return 0;
}