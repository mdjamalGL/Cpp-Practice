#include <iostream>

/**
 * Compiler generates defualt constructor for a class, if it is not
 * provided by the programmer.
 * 
 * This behaviour does not occur, when we have user defined constructors
 * in the class. We can observe this if we comment the line "dog() = default;"
 * This shall give error, as no default constructor is there.abs
 * 
 * We can force the compiler to generate the default contructor, using the format
 * 
 * dog() = default;
 * 
 * This instructs to generate a default constructor.
 */
class dog
{
    int age;
    public:

    dog(int age)
    {
        age = age;
    }

    dog() = default;
    void print()
    {
        std::cout<<"age : "<<age<<std::endl;
    }

};
int main()
{
    dog obj;
    obj.print();
    return 0;
}