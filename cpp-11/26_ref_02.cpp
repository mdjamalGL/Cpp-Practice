#include <iostream>
#include <vector>
#include <functional>

int main()
{
    int a = 0, b = 1, c = 2, d = 3;
    int apple=  12;
    std::vector<std::reference_wrapper<int>> ref_vec(4, a);
    ref_vec[0] = a;
    ref_vec[1] = b;
    ref_vec[2] = c;
    ref_vec[3] = d;

    printf("Before update - a : %d, b : %d, c : %d, d : %d\n",ref_vec[0].get(),ref_vec[1].get(),ref_vec[2].get(),ref_vec[3].get());
    
    a = 3; b = 2; c = 1; d = 0;
    printf("After update - a : %d, b : %d, c : %d, d : %d\n",ref_vec[0].get(),ref_vec[1].get(),ref_vec[2].get(),ref_vec[3].get());

    return 0;
}