#include <iostream>

void input(int arr[], int const n)
{
    for(int i = 0; i < n; ++i)
    {
        std::cout << "arr [" << i << "] = ";
        std::cin >> arr[i];
    }
}

void ShowArr(int arr[], int const n)
{
    for(int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void insertionSort(int* arr, int const size)
{
    for(int j = 1; j < size; ++j)
    {
        int key = arr[j];
        int i = j - 1;

        while(i >= 0 && arr[i] > key)
        {
            arr[i + 2] = arr[i--];
        }
        arr[i+1] = key;
    }
}

int main()
{
    int arr [50] = { 9, 4, 6, 3, 10, 12, 2, 0 };
    int size = 8;

    //std::cout << "Length of array = ";
    //std::cin >> size;

    //input(arr, size);
    ShowArr(arr, size);
    insertionSort(arr, size);
    ShowArr(arr, size);
}
