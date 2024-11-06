#include <iostream>

typedef long double Distance;

Distance operator"" _km(Distance x) { return x/1000 ;}
Distance operator"" _m(Distance x) {return x;}
Distance operator"" _cm(Distance x) {return x*10;}

//also use constexpr

int main()
{
    Distance ruler = 1.0_km;
    Distance ruler2 = 2.0_m;
    Distance ruler3 = 3.0_cm;

    std::cout<<ruler<<" "<<ruler2<<" "<<ruler3<<std::endl;
    return 0;
}