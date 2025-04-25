/**
 * Max Heap
 * Inserting elements after building the heap
 */
#include <iostream>
#include <vector>
#include <algorithm>

void max_heapify(int i, std::vector<int> &heap)
{
    int l = 2*i + 1;
    int r = 2*i + 2;

    int largest = i;
    if(l < heap.size() && heap[l] > heap[i])
    {
        largest = l;
    }
    else if(r < heap.size() && heap[r] > heap [largest])
    {
        largest = r;
    }
    std::swap(heap[i], heap[largest]);
    if(i != largest)
    {
        max_heapify(largest, heap);
    }
}
void build_heap(std::vector<int> &heap)
{
    int n = heap.size();
    for(int i = (n-1)/2 ; i >= 0 ; i--)
    {
        max_heapify(i, heap);
    }
}

void insert_heap(std::vector<int> &heap, int val)
{
    heap.push_back(val);

    auto get_parent = [](int index){ 
        return index/2;
    };
    int index = heap.size()-1;

    while(get_parent(index) >= 0)
    {
        if(heap[get_parent(index)] < heap[index])
        {
            std::swap(heap[index], heap[get_parent(index)]);
            index = get_parent(index);
        }
        else
        {
            break;
        }
        if(index == 0)
        break;
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

    std::cout<<"Inserting 6"<<std::endl;
    insert_heap(heap, 6);

    std::cout<<"Heap after Insertion : ";
    for(int &i : heap)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;


    return 0;
}