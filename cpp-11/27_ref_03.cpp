#include <iostream>
#include <functional>
#include <math.h>

float ret_pi_power(float power)
{
    return std::pow(3.141592f, power);
}
int main()
{
    std::function<float(float)> pi_func = (ret_pi_power);
    std::reference_wrapper<std::function<float(float)>> ref_func = std::ref(pi_func);
    std::reference_wrapper<std::function<float(float)>> ref_func_2 = std::ref(pi_func);

    std::cout<<"Ref Function Call : "<<ref_func(2.0)<<std::endl;
    std::cout<<"Ref Function Call 2 : "<<ref_func_2(3.0)<<std::endl;
    return 0;
}