#include <iostream>

void printArr(int* arr, int const size)
{
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void inputSize(int& size)
{
    do {
        std::cout << "Input array size: ";
        std::cin >> size;

    } while (size < 1);
}

void input(int* arr, const int size)
{
    std::cout << "Input array elements of size " << size << ':' << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }
}

void bubbleSort(int* arr, int const size)
{
    for (int i = size - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{    
    int size;
    inputSize(size);
        
    int* arr = new int[size];
    input(arr, size);

    bubbleSort(arr, size);
    printArr(arr, size);
}
