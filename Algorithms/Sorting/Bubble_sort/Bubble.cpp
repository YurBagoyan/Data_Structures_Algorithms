#include <iostream>

void showArr(int* arr, int const size)
{
    for(int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int input(int* arr, int const MAXSIZE, int size)
{
    std::cout << "Input array size in range [1, 1000]:" << std::endl;
    do {
        std::cin >> size;
                    
    } while (size < 1 || size > MAXSIZE);

        std::cout << "Input array elements of size " << size << ':' << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    return size;
}

/* Inputs: arr : [integer], size: integer
 * Pre: size < MAXSIZE, size > 1
 * Outputs: arr : [integer]
 * Post: arr[0] <= arr[1] <= ... <= arr[size - 1];
 */
void bubbleSort(int* arr, int const size)
{
    for(int i = size - 1; i > 0; --i) {
        for(int j = 0; j < i; ++j) {
            if(arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() 
{
    int MAXSIZE = 1000;
    int arr[MAXSIZE];
    int size = input(arr, MAXSIZE, size);

    bubbleSort(arr, size);
    showArr(arr, size);
}


//Invariant -> At the end of the iteration of the inner loop, the last element of the array is the largest
