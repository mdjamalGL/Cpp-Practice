#include <iostream>

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