#include <iostream>

int main()
{
    int hexNum = 0xAE;
    int binNum = 0b101;
    int decNum = 12345;
    int octNum = 0234;

    std::cout<<"Hexadecimal : "<<hexNum<<std::endl;
    std::cout<<"Binary : "<<binNum<<std::endl;
    std::cout<<"Decimal : "<<decNum<<std::endl;
    std::cout<<"Octal : "<<octNum<<std::endl;

    auto unsignedInt = 123U;
    auto longInt = 123L;
    auto unsignedLongInt = 123UL;
    auto longLongInt = 123LL;
    auto unsignedLongLongInt = 123ULL;
    
    std::cout<<"Int : "<<decNum<<" | " <<typeid(decNum).name()<<std::endl;
    std::cout<<"Unsigned int : "<<unsignedInt<<" | "<<typeid(unsignedInt).name()<<std::endl;
    std::cout<<"Long int : "<<longInt<<" | " <<typeid(longInt).name()<<std::endl;
    std::cout<<"Unsigned long int : "<<unsignedLongInt<<" | " <<typeid(unsignedLongInt).name()<<std::endl;
    std::cout<<"Long long int : "<<longLongInt<<" | " <<typeid(longLongInt).name()<<std::endl;
    std::cout<<"unsigned long long int : "<<unsignedLongLongInt<<" | " <<typeid(unsignedLongLongInt).name()<<std::endl;

    return 0;
}