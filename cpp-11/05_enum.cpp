#include <iostream>

// enum LED {
//     RED = 1,
//     GREEN,
//     BLUE
// };

/**
 * with C++ 11 we have scoped enum or class enum
 * which cannot be equated with integer values
 * and thus cannot be equated to enum of one type with other
 */

enum class LED {
    RED,
    GREEN,
    BLUE
};

int main()
{
    // LED led = RED;
    LED led = LED::RED;

    // if(led == 1)
    // std::cout<<"RED LED LIGHT"<<std::endl;

    // if(led == 2)
    // std::cout<<"GREEN LED LIGHT"<<std::endl;

    // if(led == 3)
    // std::cout<<"BLUE LED LIGHT"<<std::endl;

    if(led == LED::RED)
    std::cout<<"RED LED LIGHT"<<std::endl;

    if(led == LED::GREEN)
    std::cout<<"GREEN LED LIGHT"<<std::endl;

    if(led == LED::BLUE)
    std::cout<<"BLUE LED LIGHT"<<std::endl;
    // std::cout<<"RED + BLUE : "<<RED + BLUE<<std::endl;
}