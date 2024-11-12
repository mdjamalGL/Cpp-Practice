#include <iostream>

int operator"" _b(const char *num, size_t size) {
    int number = 0;
    int mult = 1;
    for(int i = size-1; i >=0 ;i--)
    {
        number = number + (num[i] == '1' ? mult : 0);
        mult *= 2;
    }
    return number;
}

/**
 * this is example for char *, will work only if its const
 * operator overloading parameter : (const char * num, size_t size)
 * second parameter stores the size of num c - string, its automatically
 * deduced from the passed string by the compiler, we don't have to call it
 */

int main()
{
    int bin1 = "101101"_b;
    int bin2 = "0110"_b;
    int bin3 = "01110"_b;

    std::cout<<bin1<<std::endl;
    std::cout<<bin2<<std::endl;
    std::cout<<bin3<<std::endl;

    return 0;
}