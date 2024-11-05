#include <iostream>

class Rational
{
    int numerator;
    int denominator;

    public:

    Rational(int num, int den) : numerator(num), denominator(den) {}

    void operator()(int n)
    {
        numerator *= n;
        denominator *= n;
    }

    operator std::string()
    {
        return "R : " + std::to_string(numerator) + "/" + std::to_string(denominator);
    }
};
int main()
{
    Rational num(3,5);
    std::cout<<"Original "<<std::string(num)<<std::endl;
    std::cout<<"After Scalar multiplication by 2\n";
    num(2);
    std::cout<<std::string(num)<<std::endl;
    return 0;
}