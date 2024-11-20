#include <iostream>

int main()
{
    int num1 = 10;
    int &num1Ref = num1;
    
    /**
     * auto work as expected and deduces type "int"
     * rhs = int
     */
    auto autonum1 = num1;
    std::cout<<"using auto [ with variable on rhs ] : "<<std::endl;
    std::cout<<"autonum1 : "<<&autonum1<<std::endl;
    std::cout<<"num1: "<<&num1<<std::endl;
    std::cout<<std::endl;

    /**
     * auto works not as expected and again deduces type "int"
     * rhs = int &
     * this happens because not matter what the rhs is only using 
     * auto deduces to "int" or the primitive counterpart always
     */
    auto num1auto = num1Ref;
    std::cout<<"using auto [ with reference variable on rhs ] : "<<std::endl;
    std::cout<<"num1auto : "<<&num1auto<<std::endl;
    std::cout<<"num1Ref : "<<&num1Ref<<std::endl;
    std::cout<<std::endl;

    /**
     * we can however use qualifier like & with auto to make it deduces as ref
     * auto deduces as int&
     * rhs = int &
     */
    auto &num1autoRef = num1Ref;
    std::cout<<"using auto & [ with reference variable on rhs] : "<<std::endl;
    std::cout<<"num1autoRef : "<<&num1autoRef<<std::endl;
    std::cout<<"num1Ref : "<<&num1Ref<<std::endl;
    std::cout<<std::endl;

    /**
     * we can use decltype(auto) which deduces to int or int& depending 
     * upon what is on the rhs
     * so,
     * decltype(auto) deduces to int
     * rhs = int
     */
    decltype(auto) declautonum1 = num1;
    std::cout<<"using decltype(auto) [ with variable on rhs] : "<<std::endl;
    std::cout<<"decltype(auto): "<<&declautonum1<<std::endl;
    std::cout<<"num1 : "<<&num1<<std::endl;
    std::cout<<std::endl;

    /**
     * decltype(auto) deduces to int&
     * rhs = int&
     */
    decltype(auto) declautonum1Ref = num1Ref;
    std::cout<<"using decltype(auto) [ with reference variable on rhs] : "<<std::endl;
    std::cout<<"decltype(auto): "<<&declautonum1Ref<<std::endl;
    std::cout<<"num1Ref : "<<&num1Ref<<std::endl;
    std::cout<<std::endl;
    
    return 0;
}