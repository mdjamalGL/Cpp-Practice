#include <any>
#include <iostream>

int main()
{
    int IntVar = 2;
    float FloatVar = 2.23;
    std::string StringVar = "jamal";

    std::any var1 {IntVar};

    std::cout<<"Value : "<<std::any_cast<int>(var1)<< "| Has Value : " <<var1.has_value()<<" | type : "<<var1.type().name()<<std::endl;

    var1 = FloatVar;
    std::cout<<"Value : "<<std::any_cast<float>(var1)<< "| Has Value : " <<var1.has_value()<<" | type : "<<var1.type().name()<<std::endl;


    var1 = StringVar;
    std::cout<<"Value : "<<std::any_cast<std::string>(var1)<< "| Has Value : " <<var1.has_value()<<" | type : "<<var1.type().name()<<std::endl;

    return 0;
}