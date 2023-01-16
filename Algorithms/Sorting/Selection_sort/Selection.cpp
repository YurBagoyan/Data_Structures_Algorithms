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

void sort(int arr[], int const size)
{
    for (int j = 0; j < size - 1; ++j) {
        int maxIdx = size - 1;
        int max = arr[maxIdx];

        for (int i = maxIdx - 1; i >= j; --i) {
            if (arr[i] > max) {
                max = arr[i];
                maxIdx = i;
            }
        }
        arr[maxIdx] = arr[j];
        arr[j] = max;
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
