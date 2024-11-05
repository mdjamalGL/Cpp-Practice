#include <iostream>
#include <vector>
#include <array>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <list>

/**
 * Stack and queue don't have constructor implementation with initializer list as argument
 */
int main()
{
    std::vector<int> vec = {1, 2, 3, 4};
    std::array<int, 4> arr = {1,2,3,4};
    // std::stack<int> stck = {1,2,3, 4};
    // std::queue<int> que = {1,2, 3, 4};
    std::set<int> st = {1, 2, 3, 4, 4};
    std::map<int,std::string> mp = {{1, "apple"}, {2, "orange"}};
    std::unordered_map<int, std::string> mp1 = {{1, "apple"}, {2, "orange"}};
    std::list<int> lst = {1, 2, 3, 4, 5};

    std::cout<<"Vector : ";
    for(auto ele : vec)
    {
        std::cout<<ele<<" ";
    }
    std::cout<<"\n";

    std::cout<<"Array : ";
    for(auto ele : arr)
    {
        std::cout<<ele<<" ";
    }
    std::cout<<"\n";
    // std::cout<<"Stack : ";
    // for(auto ele : stck)
    // {
    //     std::cout<<ele<<" ";
    // }
    // std::cout<<"\n";
    // std::cout<<"Queue : ";
    // for(auto ele : que)
    // {
    //     std::cout<<ele<<" ";
    // }
    // std::cout<<"\n";

    std::cout<<"Set : ";
    for(auto ele : st)
    {
        std::cout<<ele<<" ";
    }
    std::cout<<"\n";

    std::cout<<"Map : ";
    for(auto ele : mp)
    {
        std::cout<<"{"<<ele.first<<", "<<ele.second<<"}"<<" ";
    }
    std::cout<<"\n";

    std::cout<<"Unordered Map : ";
    for(auto ele : mp1)
    {
        std::cout<<"{"<<ele.first<<", "<<ele.second<<"}"<<" ";
    }
    std::cout<<"\n";

    std::cout<<"List : ";
    for(auto ele : lst)
    {
        std::cout<<ele<<" ";
    }
    std::cout<<"\n";

    return 0;
}