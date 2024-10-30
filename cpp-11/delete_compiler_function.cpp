#include <iostream>

class dog
{
    int age;
    public:

    dog(int ageParam)
    {
        age = ageParam;
    }

    dog(float ageParam) = delete; //deletes this compiler generated version when obj1(3.5) is called

    void print()
    {
        std::cout<<"age : "<<age<<std::endl;
    }

};
int main()
{
    dog obj(2);
    // dog obj1(3.4);
    obj.print();
    // obj1.print();
    return 0;
}