#include <iostream>
#include <memory>

int main()
{
    /**
     * we can make array using constructor, we pass the parameter
     * "new int[size], this only works after cpp 20"
     */
    std::shared_ptr<int[]> array(new int[5]);

    for(int i = 0; i < 5; i++)
    {
        array[i] = i;
    }
    std::cout<<"Array using contructor : ";
    for(int i = 0 ; i < 5 ; i++)
    {
        std::cout<<array[i]<<" ";
    }
    std::cout<<std::endl;

    /**
     * we can also make array usign make shared, where we only have
     * to pass the "size" argument.
     * 
     * note the type for shared_ptr is  "int[]"
     */
    std::shared_ptr<int[]> array1 = std::make_shared<int[]>(5);
    for(int i = 0; i < 5; i++)
    {
        array1[i] = i;
    }
    std::cout<<"Array using make_shared : ";
    for(int i = 0 ; i < 5 ; i++)
    {
        std::cout<<array1[i]<<" ";
    }
    std::cout<<std::endl;

    /**
     * When we create an array of size N, the shared pointer only points
     * to the first element, when the pointer goes out of scope, only the
     * first element is relesed, this may lead to memory leak
     * 
     * * shared_pointer<int[]> arr(new int[5] ) ---> memory leak
     * 
     * We need to define custom deleter, to handle the memory leak
     * 
     * * shared_pointer<int[]> arr(new int[5], [](int *arr){delete[] arr})
     * 
     * the above definition, cleans the whole array and not the first element
     * only
     */
    return 0;
}