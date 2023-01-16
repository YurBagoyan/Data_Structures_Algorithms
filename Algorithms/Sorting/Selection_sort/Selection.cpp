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

void input(int* arr, int const size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << "arr[" << i << "] = ";
        std::cin >> arr[i];
    }
}

void sort(int* arr, int const size)
{
    for (int j = 0; j < size - 1; ++j) {
        int minIdx = j;
        int min = arr[minIdx];

        for (int i = minIdx; i < size; ++i) {
            if (arr[i] < min) {
                min = arr[i];
                minIdx = i;
            }
        }
        arr[minIdx] = arr[j];
        arr[j] = min;
    }
}

int main()
{
    int size;
    inputSize(size);

    int* arr = new int[size];
    input(arr, size);

    printArr(arr, size);
    sort(arr, size);
    printArr(arr, size);
}
