#include <iostream>
#include <ctime>

/// Problem 7.1 - a
/*  

    Iteration #1
    pivot = 13
    wall = 0
    j = 10
    arr: 6 19 9 5 12 8 7 4 11 2 13 21


    Iteration #2
    pivot = 13
    wall = 1
    j = 9
    arr: 6 2 9 5 12 8 7 4 11 19 13 21


    Iteration #3
    pivot = 6
    wall = 0
    j = 7
    arr: 4 2 9 5 12 8 7 6 11 19 13 21


    Iteration #4
    pivot = 6
    wall = 2
    j = 3
    arr: 4 2 5 9 12 8 7 6 11 19 13 21


    Iteration #5
    pivot = 4
    wall = 0
    j = 1
    arr: 2 4 5 9 12 8 7 6 11 19 13 21
    

    Iteration #6
    pivot = 9
    wall = 3
    j = 7
    arr: 2 4 5 6 12 8 7 9 11 19 13 21
    
    
    Iteration #7
    pivot = 9
    wall = 4
    j = 6
    arr: 2 4 5 6 7 8 12 9 11 19 13 21
    
    
    Iteration #8
    pivot = 12
    wall = 6
    j = 8
    arr: 2 4 5 6 7 8 11 9 12 19 13 21
    
    
    Iteration #9
    pivot = 11
    wall = 6
    j = 7
    arr: 2 4 5 6 7 8 9 11 12 19 13 21
    
    
    Iteration #10
    pivot = 19
    wall = 9
    j = 10
    arr: 2 4 5 6 7 8 9 11 12 13 19 21

    Answer: 2 4 5 6 7 8 9 11 12 13 19 21
*/


/// Problem 7.1 - e
size_t partition(int* arr, const size_t start, const size_t end);
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
    const size_t size = 12;
    int arr[MAXSIZE] = { 13, 19, 9, 5, 12, 8, 7, 4, 11, 2, 6, 21 };

    //size_t size = inputSize();
    //int* arr = new int[size];
    //randomInputArr(arr, size);

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
