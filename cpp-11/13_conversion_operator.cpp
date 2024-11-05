#include <iostream>

/**
 * When the function accepts two strings as parameters
 * 
 * when explicit is not used, the compiler automatically
 * casts the number object to string.
 * 
 * when explicit is defined, the funciton requires the
 * std::string casting in the call.
 */
class Rational
{
    int numerator;
    int denominator;

    public:

    Rational(int num, int den) : numerator(num), denominator(den) {}
    std::string str()
    {
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }

    operator std::string()
    {
        return this->str();
    }
};

std::string addString(std::string str1, std::string str2)
{
    return str1 + str2;
}

int main()
{
    Rational number(3,4);
    std::string ans = addString("Rational Number is : ", number);
    std::cout<<ans<<std::endl;
    return 0;
}