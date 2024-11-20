#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <stack>

template <typename T>
T rollNo;

template <typename T>
T object;

int main()
{
    /**
     * it works with all primitive types
     */
    rollNo<int> = 122;
    rollNo<std::string> = "122";
    object<char> = 'a';
    object<short int> = 12;
    object<double> = 21;
    object<long double> = 22;
    object<long long int> = 23;
    
    std::cout<<"<int> : "<<rollNo<int><<std::endl;
    std::cout<<"<std::string> : "<<rollNo<std::string><<std::endl;
    std::cout<<"<char> : "<<object<char><<std::endl;
    std::cout<<"<short int> : "<<object<short int><<std::endl;
    std::cout<<"<double> : "<<object<double><<std::endl;
    std::cout<<"long double> : "<<object<long double><<std::endl;
    std::cout<<"<long long double> : "<<object<long long int><<std::endl;


    /**
     * even work with container like 
     * - vector
     * - stack
     * - list
     * - map etc.
     */
    object<std::vector<int>> = {1,2,3,4,5};
    object<std::vector<int>>.push_back(6);

    std::cout<<"Vector : ";
    for(auto ele : object<std::vector<int>>)
    {
        std::cout<<ele<<" ";
    }
    std::cout<<std::endl;

    object<std::list<int>> = {8,9,10};

    std::cout<<"List : ";
    for(auto ele : object<std::list<int>>)
    {
        std::cout<<ele<<" ";
    }
    std::cout<<std::endl;

    object<std::map<int,int>>;
    object<std::map<int,int>>[1] = 2;
    object<std::map<int,int>>[2] = 3;

    std::cout<<"Map : "<<std::endl;
    for(auto ele : object<std::map<int,int>>)
    {
        std::cout<<ele.first<<" "<<ele.second<<std::endl;
    }

    object<std::stack<int>>;
    object<std::stack<int>>.push(1);
    object<std::stack<int>>.push(5);
    object<std::stack<int>>.push(10);
    object<std::stack<int>>.push(15);

    std::cout<<"Stack : ";
    while(!object<std::stack<int>>.empty())
    {
        std::cout<<object<std::stack<int>>.top()<<" ";
        object<std::stack<int>>.pop();
    }
    std::cout<<std::endl;

    return 0;
}