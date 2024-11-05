#include <iostream>
#include <cassert>

int main()
{
    /**
     * asset is done at runtime : uses cases like validating user input
     * static_assert is done at compile time: uses cases like checking type compatibility
     */
    std::cout<<"This statement was printed before assert\n";
    int var = 4;

    // static_assert(var > 4, "var is less than or equal to 4");


    assert(var > 4);
    std::cout<<"This statement was printed after assert\n";
    return 0;
}