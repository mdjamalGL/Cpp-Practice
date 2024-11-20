#include <iostream>

template <typename T>
auto sum(T a, T b)
{
    return a + b;
}
int main()
{
    int numSum = sum(12,22);
    std::string stringSum = sum(std::string("apple"), std::string("orange"));

    std::cout<<"Int sum : "<<numSum<<std::endl;
    std::cout<<"String Sum : "<<stringSum<<std::endl;

    /**
     * we can use qualifier like const, *, & with the auto
     * for the returning with reference (&) and so on
     */
    return 0;
}