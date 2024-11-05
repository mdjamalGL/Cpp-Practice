#include <iostream>

void ptrFunction(int num)
{
    std::cout<<"Num parameter function called";
}

void ptrFunction(int *ptr)
{
    std::cout<<"Pointer parameter function called";
}
int main()
{

    //ptrFunction(NULL); //compiler cannot decide since NULL is essentially an integer 0
    ptrFunction(nullptr);
    return 0;
}