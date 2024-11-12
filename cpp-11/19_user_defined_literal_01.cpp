#include <iostream>

typedef char Distance;

Distance operator"" _km(Distance x) { return x+1; }
Distance operator"" _m(Distance x) { return x; }
Distance operator"" _cm(Distance x) { return x-1; }

// also use constexpr

/**
 * Works with : 
 * unsigned long long
 * long double
 * char * works with const type;
 *      1. (const char *num, size_t size) //size will automatically deduced form passed c-string
 *      2. (const wchar_t *num, size_t size)
 *      3. (const char16_t *num, size_t size)
 *      4. (const char32_t *num, size_t size)
 * 
 * return type can be of different types.
 */

int main()
{
    Distance ruler = '1'_km;
    Distance ruler2 = '2'_m;
    Distance ruler3 = '3'_cm;

    std::cout<<ruler<<" "<<ruler2<<" "<<ruler3<<std::endl;
    return 0;
}