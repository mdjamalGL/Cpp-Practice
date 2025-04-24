/**
 * Heap Sort
 */
#include <iostream>
#include <vector>
#include <algorithm>

void max_heapify(int i, std::vector<int> &heap, int heap_size)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    int largest = i;
    if (l < heap_size && heap[l] > heap[i])
    {
        largest = l;
    }
    if (r < heap_size && heap[r] > heap[largest])
    {
        largest = r;
    }

    std::swap(heap[i], heap[largest]);
    if (i != largest)
    {
        max_heapify(largest, heap, heap_size);
    }
}
void build_heap(std::vector<int> &heap)
{
    int n = heap.size();
    for (int i = (n - 1) / 2; i >= 0; i--)
    {
        max_heapify(i, heap, n);
    }
}

void heap_sort(std::vector<int> &heap)
{
    int heap_size = heap.size();
    for (int i = heap_size - 1; i >= 1; i--)
    {
        std::swap(heap[0], heap[i]);
        heap_size--;
        max_heapify(0, heap, heap_size);
    }
}
int main()
{
    std::vector<int> array{12, 1, 2, 10, 5, 42, 22, 12};
    std::vector<int> heap = array;

    std::cout << "Original Array : " << std::endl;
    for (int &i : array)
    {
        std::cout << i << "  ";
    }
    std::cout << std::endl;

    build_heap(heap);

    std::cout << "Max Heap : ";
    for (int &i : heap)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    heap_sort(heap);
    std::cout << "Sorted Heap : ";
    for (int &i : heap)
    {
        std::cout << i << " ";
    }
    std::cout<<std::endl;
    return 0;
}