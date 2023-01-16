#include <iostream>

void inputSize(int& size)
{
    do {
        std::cout << "Input array size: ";
        std::cin >> size;

    } while (size < 1);
}

void input(int* arr, int const size)
{
    for (int i = 0; i < size; ++i) {
        std::cout << "arr[" << i << "] = ";
        std::cin >> arr[i];
    }
}

void printArr(int* arr, const int size) 
{
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << "  ";
    }
    std::cout << "\n";
}

void merge(int* arr, int const left, int const mid, int const right) 
{
    int const n1 = mid - left + 1;
    int const n2 = right - mid;

    int* leftArray = new int[n1 + 1];
    int* rightArray = new int[n2 + 1];

    constexpr int MAX = 1000000;

    for (int i = 0; i < n1; ++i) {
        leftArray[i] = arr[left + i];
    }
    leftArray[n1] = MAX;

    for (int i = 0; i < n2; ++i) {
        rightArray[i] = arr[mid + 1 + i];
    }
    rightArray[n2] = MAX;

    int i = 0, j = 0;
    for (int k = left; k <= right; ++k) {
        if (leftArray[i] < rightArray[j]) {
            arr[k] = leftArray[i++];
        }
        else {
            arr[k] = rightArray[j++];
        }
    }

    delete[] leftArray;
    delete[] rightArray;
}

void mergesort(int* arr, int const left, int const right) {
    if (left < right) {
        const int mid = (left + right) / 2;

        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Wraper
void mergeSort(int* arr, const int size)
{
    mergesort(arr, 0, size - 1);
}

int main() {
    int size;
    inputSize(size);

    int* arr = new int[size];
    input(arr, size);

    mergeSort(arr,size);
    printArr(arr, size);
}
