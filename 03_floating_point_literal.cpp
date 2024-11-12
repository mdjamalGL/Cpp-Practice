#include <iostream>

int main()
{
    auto noDecimalDigit = 48.;
    auto floatNoDecimalDigit = 48.f;
    auto exponentNumber = 123.456e-67;
    auto floatExponentNumber = 123.456e-67f;
    auto capitalExponent = 0.1E4f;
    auto hexExponentDecimal = 0x10.1p0;
    auto hexExponent = 0x1p5;
    auto doubleExponent = 1.18e-4932l;

    std::cout<<"48. : \t"<<noDecimalDigit<<" "<<typeid(noDecimalDigit).name()<<std::endl;
    std::cout<<"48.f : \t"<<floatNoDecimalDigit<<" "<<typeid(floatNoDecimalDigit).name()<<std::endl;
    std::cout<<"123.456e-67 : \t"<<exponentNumber<<" "<<typeid(exponentNumber).name()<<std::endl;
    std::cout<<"123.456e-67f : \t"<<floatExponentNumber<<" "<<typeid(floatExponentNumber).name()<<std::endl;
    std::cout<<"0.1E4f : \t"<<capitalExponent<<" "<<typeid(capitalExponent).name()<<std::endl;
    std::cout<<"0x10.1p0 : \t"<<hexExponentDecimal<<" "<<typeid(hexExponentDecimal).name()<<std::endl;
    std::cout<<"0x1p5 : \t"<<hexExponent<<" "<<typeid(hexExponent).name()<<std::endl;
    std::cout<<"1.18e-4932l : \t"<<doubleExponent<<" "<<typeid(doubleExponent).name()<<std::endl;

    return 0;
}