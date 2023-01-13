#include <iostream>

void printArr(int* arr, const int size)
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
    for (int i = 0; i < size; ++i)
    {
        std::cout << "arr [" << i << "] = ";
        std::cin >> arr[i];
    }
}

void insertionSort(int* arr, const int size)
{
    for (int i = 1; i < size; ++i) {
        const int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j--];
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int size;
    inputSize(size);

    int* arr = new int[size];
    input(arr, size);

    printArr(arr, size);
    insertionSort(arr, size);
    printArr(arr, size);
}
