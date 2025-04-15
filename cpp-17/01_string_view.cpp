#include <iostream>
#include <string_view>

void print(std::string_view msg, std::string_view str)
{
    std::cout<<msg<<" : "<<str<<std::endl;
}

int main()
{
    std::string hlo = "Hello World";
    print("String", hlo);

    std::string_view local_view = hlo;

    hlo[0] = 'C';

    print("Modified String", hlo);
    print("Local View", local_view);

    local_view.remove_suffix(3);
    print("After Removing 3 suffix characters", local_view);
    print("But original owner string does not get affected", hlo);

    hlo = "apple";
    print("string_view : ", local_view);
    print("original string : ", hlo);
    return 0;
}