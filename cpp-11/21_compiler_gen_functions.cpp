#include <iostream>
#include <initializer_list>

class mdVector
{
    int size;
    int *arr;

    public :
    mdVector(std::initializer_list<int> list)
    {
        size = list.size();
        arr = new int[size];
        int i = 0;
        for(auto ele : list)
        {
            arr[i++] = ele;
        }
    }

    /**
     * defining the move constructor make the compiler
     * not generate the copy constructor and thus the
     * line mdVector vec = vec1 will give error
     * 
    */
    // mdVector(mdVector &&vec)
    // {
    //     size = vec.size;
    //     arr = vec.arr;
    //     vec.arr = nullptr;
    //     std::cout<<"Move Constructor called : "<<std::endl;
    // }
    
    ~mdVector()
    {
        size = 0;
        delete[] arr;
    }

    int &operator[](int i)
    {
        return arr[i];
    }
    void print()
    {
        std::cout<<"Array : ";
        for(int i = 0 ; i < size; i++ )
        {
            std::cout<<arr[i]<<" ";
        }
        std::cout<<std::endl;
    }
};

int main()
{
    mdVector vec {1,2,3,4,5};
    vec.print();
    mdVector vec1 = vec;
    vec1.print();
    vec[1] = 42;
    std::cout<<"After Change"<<std::endl;
    vec.print();
    vec1.print();
    return 0;
}