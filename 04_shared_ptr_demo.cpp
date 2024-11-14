#include <iostream>
#include <memory>

int main()
{
    /**
     * we can either make new pointer objects by calling constructor
     * and pass the memory address as below
     */
    std::shared_ptr<int> arr(new int(5));
    std::shared_ptr<int> arr1 = arr;
    std::cout<<"Arr 0 : "<<*arr<<std::endl;
    std::cout<<"Arr 1 : "<<*arr1<<std::endl;
    std::cout<<"Count : "<<arr.use_count()<<" "<<arr1.use_count()<<std::endl;

    /**
     * we can also use the "make_shared" that internally calls
     * "new" to allocate memory, as parameter we pass the value
     * for the location
     */
    std::shared_ptr<char> carr = std::make_shared<char>('a');
    std::shared_ptr<char> carr1 = carr;
    std::cout<<"Char 0 : "<<*carr<<std::endl;
    std::cout<<"Char 1 : "<<*carr1<<std::endl;
    std::cout<<"Count : "<<carr.use_count()<<" "<<carr1.use_count()<<std::endl;

    /**
     * we can also use assignment operator to make a shared pointer point to already
     * defined shared memory location (note this cannot be raw pointer)
     */
    std::shared_ptr<float> farr = std::make_shared<float>(2.1);
    std::shared_ptr<float> farr1 = std::make_shared<float>(2.3);
    float *farr2 = new float(2.2);
    std::cout<<"Count FLoat : "<<farr.use_count()<<" "<<farr1.use_count()<<std::endl;
    std::cout<<"Resetting farr and setting it to farr2"<<std::endl;

    /**
     * we can however use ".reset()"
     * with no paramter : it frees the memory location only
     * with a raw pointer('r') : the current location is freed if the current count is 1
     *                           and the pointer shall now point to 'r' memory location
     * 
     * the same thing is possible with shared_pointer, but we only need to use "=".
     * like farr = farr1;
     */
    farr.reset(farr2);
    std::cout<<"Count FLoat : "<<farr.use_count()<<" "<<farr1.use_count()<<std::endl;
    return 0;
}
