#include <iostream>

template <typename T>
T rollNo;
int main()
{
    rollNo<int> = 122;
    rollNo<std::string> = "122";

    std::cout<<"Int Roll No. "<<rollNo<int><<std::endl;
    std::cout<<"String Roll No. "<<rollNo<std::string><<std::endl;
    return 0;
}