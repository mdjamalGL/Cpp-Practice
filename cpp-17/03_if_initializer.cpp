#include <iostream>
#include <map>

int main()
{
    std::map<int,int> coordinate;

    coordinate[2] = 3;
    coordinate[1] = 4;
    coordinate[0] = 0;

    int x = 3;
    if(auto it = coordinate.find(x); it != coordinate.end()) 
    {
        //scope of x is till this bracket so same 
        //variable name can be used more than one time
        //for the same purpose.
        
        std::cout<<x<<" as x coordinate exists"<<std::endl;
    }
    else
    {
        std::cout<<x<<" as x coordinate does not exist"<<std::endl;
    }
    return 0;
}