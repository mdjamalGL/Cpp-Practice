#include <iostream>

class person{
    int age = 0;
    std::string name = "md shabbir jamal";

    public:

    virtual void act()
    {
        std::cout<<"Person is acting"<<std::endl;
    }
};

class employee : public person{
    public:
    void act() override
    {
        std::cout<<"employee is acting"<<std::endl;
    }
};
int main()
{
    employee obj;
    obj.act();
    return 0;
}