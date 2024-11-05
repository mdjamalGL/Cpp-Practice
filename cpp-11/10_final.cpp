#include <iostream>

class person{

    public :

    int age = 0;
    std::string name = "md shabbir jamal";

    virtual void act() final
    {
        std::cout<<"Person is acting"<<std::endl;
    }

    void print()
    {
        std::cout<<"Person : age : "<<age<<" name : "<<name<<std::endl;
    }
};

class employee final : public person {
    public:
    
    /**
     * this if uncommented will give error because
     * final keywords stop the act function from being overridden.
     */
    // void act() override
    // {
    //     std::cout<<"employee is acting"<<std::endl;
    // }
    void print()
    {
        std::cout<<"Employee : age : "<<age<<" name : "<<name<<std::endl;
    }
};

/**
 * this also gives error in compilation because we cannot 
 * inherit from a class already declared as final
*/
// class engineer : public employee {

// }
int main()
{
    employee obj;
    obj.act();
    obj.print();
    return 0;
}