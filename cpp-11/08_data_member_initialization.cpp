#include<iostream>

class person {
    
    //data member initialization inside class
    //this gets initialized for all the objects that are created
    //by default
    int *age = new int(0);
    int *roll = new int(0);

    public :

    person(int ageParam ,int rollParam)
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