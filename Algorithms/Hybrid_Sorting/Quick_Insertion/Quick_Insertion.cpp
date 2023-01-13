#include <iostream>
#include <ctime>

void hybrid_QS(int* arr, int start, int end);
size_t partition(int* arr, const size_t start, const size_t end);
void insertionSort(int* arr, const size_t start, const size_t end);

size_t inputSize();
void randomInputArr(int* arr, const size_t size);
void showArr(int* arr, const size_t size);
void swap(int& a, int& b);

constexpr size_t MAXSIZE = 100;

//Wraper
void quickSort(int* arr, const size_t size)
{
    hybrid_QS(arr, 0, size - 1);
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

void hybrid_QS(int* arr, int start, int end)
{
    const int k = 5;
    while (start < end) {

        if (end - start + 1 < k) {
            insertionSort(arr, start, end);
            break;
        }
        else {
            // Tail recurtion 
            size_t wall = partition(arr, start, end);
            hybrid_QS(arr, start, wall - 1);
            start = wall - 1;

            /*if (wall - start < end - wall) {
                hybrid_QS(arr, start, wall - 1);
                end = wall + 1;
            }
            else {
                hybrid_QS(arr, wall + 1, end);
                start = wall - 1;
            }*/
        }   
    }
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

    swap(arr[++wall], arr[end]);
    return wall;
}

void insertionSort(int* arr, const size_t start, const size_t end)
{
    for (size_t i = start + 1; i < end + 1; ++i) {
        
        int val = arr[i];
        size_t j = i;

        while (j > start && arr[j - 1] > val) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = val;
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

