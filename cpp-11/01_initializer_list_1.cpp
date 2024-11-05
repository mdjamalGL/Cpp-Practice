#include <iostream>

/**
 * doing initialization with {} braces work in the following order priority
 * 1. initializer list
 * 2. constructor with suitable number (same as the type and num of element in {}) of params
 * 3. if both are not present it presumes the class as aggreate class
 *    and aggregate initialization.
 *    This works if the data members are in public and not private, other wise its error
 */
class newArray
{
    int age;
    int roll;

    public:
    newArray(int age , int roll) : age(age), roll(roll)
    {
        std::cout<<"Constructor with params called\n";
    }
    newArray(std::initializer_list<int> list) //initializer list initialization
    {
        age = *(list.begin());
        roll = *(list.begin() + 1);
        std::cout<<"Contructor with initializer list called\n";
    }

    std::pair<int,int> getValue()
    {
        return {age, roll};
    }
};
int main()
{
    
    newArray var = {2,5};
    std::pair<int,int> data = var.getValue();
    std::cout<<"Age : "<<data.first<<" | "<<"Roll : "<<data.second<<"\n";
    return 0;
}