#include <iostream>
#include <ctime>

void qSort(int* arr, const int start, const int end);
size_t inputSize();
void randomInputArr(int* arr, const size_t size);
void showArr(int* arr, const size_t size);
void swap(int& a, int& b);

constexpr size_t MAXSIZE = 100;

//Wraper
void quickSort(int* arr, const size_t size)
{
    qSort(arr, 0, size - 1);
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

size_t hoare_partition(int* arr, const size_t start, const size_t end)
{
    int pivot = arr[start];
    int wall = start - 1;
    int j = end + 1;

    while (true) {

        do {
            --j;
        } while (arr[j] > pivot);

        do {
            ++wall;
        } while (arr[wall] < pivot);

        if (wall < j) {
            swap(arr[wall], arr[j]);
        }
        else {
            return j;
        }
    }
}

void qSort(int* arr, const int start, const int end)
{
    if (start < end) {
        size_t wall = hoare_partition(arr, start, end);
        qSort(arr, start, wall);
        qSort(arr, wall + 1, end);
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
