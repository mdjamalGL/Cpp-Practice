#include <iostream>
#include <functional>
#include <thread>

void make_change(int &num)
{
    num = num - 2;
}

int main()
{
    int num = 12;
    std::cout<<"Before Change  : "<<num<<std::endl;

    // std::thread t0(make_change, num);
    // t0.join();
    /**
     * This Call does not passes the argument by ref, even though the argument 
     * for the make_change function is by reference.
     *  
     * We make the function to by reference with std::ref.
     */
    std::cout<<"After Change t0 : "<<num<<std::endl;

    std::thread t1(make_change, std::ref(num));
    t1.join();

    std::cout<<"After Change t1 : "<<num<<std::endl;
    return 0;
}