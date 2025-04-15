#include <iostream>

template <typename ... Args>
void print(Args ... arg)
{
    std::string format = "Numbers : ";
    int sizeArgs = sizeof...(arg);
    printf("size : %d\n", sizeArgs);
    while(sizeArgs--)
    {
        format = format + "%d, ";
    }

    printf(format.c_str(), (... , arg));
}
int main()
{
    print(1,2,3,4,5);
    return 0;
}