#include <iostream>

void input(int arr[], int const n)
{
    for (int i = 0; i < n; ++i) {
        std::cout << "arr[" << i << "] = ";
        std::cin >> arr[i];
    }
}

int MaxFinder(int* arr, int const size)
{
    // Create a max variable and initialize it with arr[0]
    int max = arr[0];

    // Iterate from the first index to the last index of the array
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    int size;
    std::cout << "Size of array = ";
    std::cin >> size;


    int* arr = new int[size];
    
    input(arr, size);
    std::cout << "Max = " << MaxFinder(arr, size) << std::endl;
}
