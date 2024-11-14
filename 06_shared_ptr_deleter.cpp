#include <iostream>
#include <memory>

void deleter_function(int *arr)
{
    std::cout<<"Custom Deleter"<<std::endl;
    delete[] arr;
    arr = nullptr;
}

int main()
{
    /**
     * for custom deleter to work we can only
     * define the array via the constructor method
     * as we need to give the deleter function in the contructor argument
     * at the time of pointer object creation.
     * 
     * Custom deleter work with both lambda function and normal function.
    */

    // auto deleter_function = [](int *arr){
    //     std::cout<<"Deleter"<<std::endl;
    //     std::cout<<*arr<<" ";
    // };

    int *arr = new int[5];
    {

        std::shared_ptr<int[]> array1(arr, deleter_function);
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
    }
    std::cout<<"Array outside scope : ";
    for(int i = 0 ; i < 5 ; i++)
    {
        std::cout<<arr[i]<<" ";
    }

    std::cout<<std::endl;
    return 0;
}