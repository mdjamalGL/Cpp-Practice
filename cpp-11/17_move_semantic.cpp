#include <iostream>
#include <initializer_list>
#include <chrono>

class mdVector
{
    int size;
    double *arr;

    public:

    mdVector(std::initializer_list<double> list)
    {
        arr = new double[list.size()];
        int i = 0;
        for(auto ele : list)
        {
            arr[i] = ele;
            i++;
        }
        size = i;
    }

    mdVector(mdVector &vec)
    {
        std::cout<<"Copy constructor called "<<std::endl;
        size = vec.getSize();
        arr = new double[size];

        for(int i = 0 ; i < size ; i++)
        {
            arr[i] = vec[i];
        }
    }

    mdVector(mdVector &&vec)
    {
        std::cout<<"Move constructor called "<<std::endl;
        size = vec.getSize();
        arr = vec.getArr();
        vec.arr = nullptr;
    }

    ~mdVector()
    {
        delete[] arr;
        size = 0;
    }

    int getSize(){ return size ; }
    double *getArr() { return arr;}

    double operator[](int index)
    {
        return arr[index];
    }

    void print()
    {
        std::cout<<"Array : "; 
        for(int i = 0 ; i < size ; i++)
        {
            std::cout<<arr[i]<<" ";
        }
        std::cout<<std::endl;
    }
};

mdVector demoFunc(mdVector vec)
{
    vec.print();
    return vec;
}

int main()
{
    mdVector vec = {1.1, 2.2, 3.4, 5.5, 6.0};

    /**
     * First call to demoFunc passes the object's lvalue this leads
     * to calling copy constructor.
     * 
     * This is expensive deep copy.
     * while returning the local variable is destroyed and the rvalue is passed to the main function
     * this means the move constructor is called
     * 
     * Runtime is more compared to passing by move constructor
     */
    auto st = std::chrono::steady_clock::now();
    mdVector res1 = demoFunc(vec);
    auto et = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(et - st);
    std::cout << "Function runtime: " << duration.count() << " microseconds" << std::endl;

    /**
     * This call to demoFunc uses the std::move to make the rvalueRef
     * This calls the move constructor for the parameter
     * 
     * This is inexpensive shallow copy
     * while returning the local parameter that has the object
     * is destroyed so the return object is prvalue [pure r value]
     * thus move constructor is called at the main function when the
     * value is assigned to res2;
     * 
     * Runtime is lesses than the previous example.
     */
    st = std::chrono::steady_clock::now();
    mdVector res2 = demoFunc(std::move(vec));
    et = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(et - st);
    std::cout << "Function runtime: " << duration.count() << " microseconds" << std::endl;
    return 0;
}