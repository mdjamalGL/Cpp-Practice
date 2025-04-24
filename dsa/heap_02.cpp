/**
 * Min Heap
 */
#include <iostream>
#include <vector>
#include <algorithm>

void min_heapify(int i, std::vector<int> &heap)
{
    int l = 2*i + 1;
    int r = 2*i + 2;

    int smallest = i;
    if(l < heap.size() && heap[l] < heap[i])
    {
        smallest = l;
    }
    else if(r < heap.size() && heap[r] < heap [smallest])
    {
        smallest = r;
    }
    std::swap(heap[i], heap[smallest]);
    if(i != smallest)
    {
        min_heapify(smallest, heap);
    }
}
void build_heap(std::vector<int> &heap)
{
    int n = heap.size();
    for(int i = (n-1)/2 ; i >= 0 ; i--)
    {
        min_heapify(i, heap);
    }
}
int main()
{
    std::vector<int> array {12, 1, 2, 10 ,5 ,42, 22, 12};
    std::vector<int> heap = array;

    std::cout<<"Orginal Array : "<<std::endl;
    for(int &i : array)
    {
        std::cout<<i<<"  ";
    }
    std::cout<<std::endl;


    build_heap(heap);

    std::cout<<"Max Heap : ";
    for(int &i : heap)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    return 0;
}