#include <iostream>
#include <variant>

/**
 * This is type safe version of union
 * 
 * functions - 
 * 1. obj.index()       : gives index of the current type according
 *                        to the declared order
 * 2. get<type>(obj)    : gives the value of the current member,
 *                        with the known data type 'type'.
 * 3. get_if<type>(obj) : give a pointer to the member if the type given
 *                        is correct, else NULL is returned.
 */
int main()
{
    std::variant<int, float, std::string> uniVar;

    uniVar = 12;
    uniVar = 24.4f;

    std::cout<<"Is it integer : "<< (std::get_if<int>(&uniVar) == 0 ? "NO" : "YES" )<<std::endl;
    std::cout<<"Current Value : "<<std::get<float>(uniVar)<<std::endl;

    uniVar = "apple";

    std::cout<<"Current Value changed to : "<<std::get<std::string>(uniVar)<<std::endl;
    std::cout<<"Index : "<<uniVar.index()<<std::endl;

}