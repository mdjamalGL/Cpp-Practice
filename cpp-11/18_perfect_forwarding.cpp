#include <iostream>
#include <initializer_list>

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


template <typename T>
void relay(T &&arg)
{
    /**
     * constructor called will depend on what kind of object is passed
     * to the relay function
     * 
     * first object is passed as lvalue 
     * second is passed as rvalue
     */
    std::cout<<"Starting : "<<std::endl;
    mdVector ans(std::forward<T>(arg));

    /**
     * a value is inherently gets passed as lvalue, so directly usign arg won't work
     * 
     * case 1:
     * when object passed is obj1 i.e. lvalue
     * so T is lvalue reference : T = mdVector&
     * then T && =  mdVector& && = mdVector&
     * so when we cast using forward<T> or static_cast<T &&> we call the function by lvalue reference
     * hence copy constructor is called
     * 
     * case 2:
     * when object passed is std::move(obj2) i.e. rvalue
     * so T is rvalue reference : T = mdVector&&
     * then T && = mdVector&& && = mdVector&&
     * so when we cast using forward<T> or static_cast<T &&> we call the function by rvalue reference
     * hence move constructor is called
     */
    ans.print();
}

int main()
{
    mdVector obj1 = {1.1, 1.2, 1.3, 1.4};
    mdVector obj2 = {2.1, 2.2, 2.3, 2.4};

    relay(obj1);
    relay(std::move(obj2));
    return 0;
}