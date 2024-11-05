#include<iostream>

class person {
    
    int *age;
    int *roll;

    public :

    person()
    {
        age = new int(0);
        roll = new int(0);
    }

    person(int ageParam ,int rollParam) : person() //delegating constructor
    {
        *age = ageParam;
        *roll = rollParam;
    }

    void print()
    {
        std::cout<<"Roll : "<<*roll<<" | Age : "<<*age<<std::endl;
    } 
};
int main()
{
    person obj(22, 101);
    obj.print();
    return 0;
}