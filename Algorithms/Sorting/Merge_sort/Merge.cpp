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
    int const lSize = mid - left + 1;
    int const rSize = right - mid;

    int* leftArray = new int[lSize + 1];
    int* rightArray = new int[rSize + 1];

    for (int i = 0; i < lSize; ++i) {
        leftArray[i] = arr[left + i];
    }
   
    for (int i = 0; i < rSize; ++i) {
        rightArray[i] = arr[mid + 1 + i];
    }
    

    int l_idx = 0, r_idx = 0;
    for (int k = left; k <= right; ++k) {
        if (leftArray[l_idx] < rightArray[r_idx] && l_idx < lSize) {
            arr[k] = leftArray[l_idx++];
        }
        else if (r_idx < rSize){
            arr[k] = rightArray[r_idx++];
        }
        else if (l_idx < lSize) {
            arr[k] = leftArray[l_idx++];
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


