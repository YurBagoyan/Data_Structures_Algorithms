#include <iostream>
#include "heap.hpp"

int main()
{
    /// Create and input array
    int arrSize = inputSize();
    int* arr = new int[MAXSIZE];
    randInput(arr, arrSize);
    print(arr, arrSize);


    /// Create class and build heap
	using Heap = MaxHeap<int>;
    Heap heap(arr, arrSize);
    heap.print(); 


    /// Instert
    heap.insert(10);
    heap.print();
    

    /// Extarct
    std::cout << "Extracted element: " << heap.extarct() << std::endl;
    heap.print();

    delete[] arr;
}

void randInput(int* arr, const int size)
{
    //srand(time(NULL));

    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 10;
    }
}

int inputSize()
{
    int size;
    std::cout << "Size = ";
    std::cin >> size;

    return size;
}

void print(int* arr, const int size)
{
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}