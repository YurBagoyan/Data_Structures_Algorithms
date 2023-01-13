#include <iostream>

int input(int* arr, int* size);
void insertionSort(int* arr, int const start, int const end);
void merge(int* arr, const int start, const int middle, const int end);
void mergeSort(int* arr, const int start, const int end, int const k);
void showArr(int* arr, int const size);
void sort(int* arr, const int size, int const k);

constexpr int maxSize = 1000;

int main()
{
    int arr[maxSize] = { 6, 13, 4, 9, 11, 5, 12, 10, 2, 14, 4, 5, 20, 0, 1  };
    int const size = 15;
    //int k = input(arr, &size);
    
    int const k = 4;
    sort(arr, size, k);

    std::cout << "Sorted array:" << std::endl;
    showArr(arr, size);            
}

int input(int* arr, int* size)
{
    std::cout << "Input array size in range [1, 1000]:" << std::endl;
    do {
        std::cin >> *size;
    } while (*size < 1 || *size > maxSize);
    
    std::cout << "Input array elements of size " << *size << ':' << std::endl;
    for (int i = 0; i < *size; ++i) {
        std::cin >> arr[i];    
    }
    
    int k;
    do {
        std::cout << "Imp k = ";
        std::cin >> k;
    } while (k > *size);

    return k;    
}

void showArr(int* arr, int const size)
{
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << ' ';                
    }
    std::cout << std::endl;   
}

void sort(int* arr, const int size, int const k)
{
    if (size < 1) {
        return;             
    }
    mergeSort(arr, 0, size - 1, k);    
}

void mergeSort(int* arr, const int start, const int end, int const k)
{
    if (end - start + 1 > k) {
        //Divide
        const int middle = (start + end) / 2;
            
        // Conquer
        mergeSort(arr, start, middle, k);
        mergeSort(arr, middle + 1, end, k);
            
        // Combine
        merge(arr, start, middle, end);                                                                
    }
    else {
        insertionSort(arr, start, end);
    }
} 

/* Inputs: arr: [integer], size: integer
 * Pre: size < maxSize
 * Output: arr : [integer]
 * Post: arr[0] <= arr[1] <= ... <= arr[size - 1]
 */
void insertionSort(int* arr, int const start, int const end)
{
    int key;
    for (int j = start; j <= end; ++j) {
        key = arr[j];
        int i = j - 1;
        
        while (i >= start && arr[i] > key) {
            arr[i + 2] = arr[i--];
        }
        arr[i + 1] = key;
    }
}

/* Inputs: arr: [integer], start, middle, end: integer
 * Pre: start, middle, end < maxSize
 *      arr[start] <= arr[start + 1] <= ... <= arr[middle]
 *      arr[middle + 1] <= arr[middle + 2] <= ... <= arr[end]
 * Output: arr : [integer]
 * Post: arr[start] <= arr[start + 1] <= .... <= arr[end]
 */
void merge(int* arr, const int start, const int middle, const int end)
{
    const int lSize = middle - start + 1;
    const int rSize = end - middle;
    
    int lArr[maxSize + 1];
    int rArr[maxSize + 1];
    
    for (int i = 0; i < lSize; ++i) {
        lArr[i] = arr[start + i];
    }
    for (int i = 0; i < rSize; ++i) {
        rArr[i] = arr[middle + 1 + i];
    }
    
    /// Merging
    int li = 0, ri = 0;
    for (int k = start; k <= end; ++k) {
        if (lArr[li] < rArr[ri] && li < lSize) {
            arr[k] = lArr[li++];
        }
        else if (ri < rSize) {
            arr[k] = rArr[ri++];
        }
        else if (li < lSize) {
            arr[k] = lArr[li++];
        }
    }
}

