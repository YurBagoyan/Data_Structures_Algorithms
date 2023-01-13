#include <iostream>
#include <ctime>

// Sorting
void randomized_QS(int* arr, const int start, const int end);
size_t randomized_partition(int* arr, const int start, const int end);
inline int random(const int min, const int max);
size_t partition(int* arr, const size_t start, const size_t end);

// Create array
size_t inputSize();
void randomInputArr(int* arr, const size_t size);
void showArr(int* arr, const size_t size);
void swap(int& a, int& b);

constexpr size_t MAXSIZE = 100;





//Wraper
void quickSort(int* arr, const size_t size)
{
    randomized_QS(arr, 0, size - 1);
}

int main()
{
    size_t size = 10;
    int arr[MAXSIZE] = { 6, 8, 7, 4, 5, 4, 1, 9, 9, 4 };

    //size_t size = inputSize();
    //int* arr = new int[size];
    //randomInputArr(arr, size);

    showArr(arr, size);
    quickSort(arr, size);
    showArr(arr, size);
}

/// Problem 7.4 - b
/*
 *  Although we have reduced number of recursive calls, the depth of the recurtion is still O(n) in worst case.
 *  It is possible when after each partition we will have array with n-1 elements, pivot, and array with 0 elements
 */

void randomized_QS(int* arr, int start, int end)
{
    while (start < end) {
        size_t wall = randomized_partition(arr, start, end);
        randomized_QS(arr, start, wall - 1);
        start = wall + 1;
    }
}



/// Problem 7.4 - c
/*
 * We can call the tail recurcion only for smaller array which we get after partition
 *
 */
void new_randomized_QS(int* arr, int start, int end)
{
    while (start < end) {
        size_t wall = randomized_partition(arr, start, end);

        if (wall - start < end - wall) {
            randomized_QS(arr, start, wall);
            start = wall + 1;
        }
        else
        {
            randomized_QS(arr, wall + 1, end);
            end = wall - 1;
        }
    }
}



size_t randomized_partition(int* arr, const int start, const int end)
{
    size_t i = random(start, end);
    swap(arr[i], arr[end]);
    return partition(arr, start, end);
}

inline int random(const int min, const int max)
{
    return min + rand() % (max - min);
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
        arr[i] = rand() % 10;
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

