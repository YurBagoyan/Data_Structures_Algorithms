#include <iostream>
#include <ctime>

size_t partition(int* arr, const size_t start, const size_t end);
void hybridQuickSort(int* arr, const int start, const int end, const int k);
void insertionSort(int* arr, const size_t start, const size_t end);

size_t inputSize();
void randomInputArr(int* arr, const size_t size);
void showArr(int* arr, const size_t size);
void swap(int& a, int& b);


//Wraper
void quickSort(int* arr, const size_t size)
{
    const int k = 5;
    hybridQuickSort(arr, 0, size - 1, k);
}

int main()
{
    size_t size = inputSize();
    int* arr = new int[size];
    randomInputArr(arr, size);

    showArr(arr, size);
    quickSort(arr, size);
    showArr(arr, size);
}

size_t partition(int* arr, const size_t start, const size_t end)
{
    size_t wall = start - 1;
    size_t pivot = end;

    for (size_t j = start; j < end; ++j) {
        if (arr[j] <= arr[pivot]) {
            swap(arr[j], arr[++wall]);
        }
    }

    ++wall;
    swap(arr[wall], arr[end]);
    return wall;
}

void hybridQuickSort(int* arr, int start, const int end, const int k)
{
    if (end - start + 1 < k) {
        // Tail recurtion
        int wall = partition(arr, start, end);
        hybridQuickSort(arr, start, wall - 1, k);
        start = wall - 1;
    }
    else {
        insertionSort(arr, start, end);
    }
}

void insertionSort(int* arr, const size_t start, const size_t end)
{
    for (int i = start; i <= end; ++i) {
        const int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j--];
        }
        arr[j + 1] = key;
    }
}

size_t inputSize()
{
    size_t size;
    do {
        std::cout << "Input array size: ";
        std::cin >> size;
    } while (size <= 0);

    return size;
}

void randomInputArr(int* arr, const size_t size)
{
    srand(time(NULL));

    for (size_t i = 0; i < size; ++i) {
        arr[i] = rand() % 20;
    }
}

void showArr(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
