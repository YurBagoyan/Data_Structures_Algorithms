#include <iostream>

void input(int arr[], int const size)
{
    for(int i = 0; i < size; ++i)
    {
        std::cout << "arr[" << i << "] = ";
        std::cin >> arr[i];
    }
}

void show(int arr[], int start, int finish) {
    for(int i = start; i < finish; ++i){
        std::cout << arr[i] << "  ";
    }
    std::cout << "\n";
}

void merge(int arr[], int const p, int const q, int const n) {
    int const n1 = q - p + 1;
    int const n2 = n - q;
    int L[n1 + 1], R[n2 + 1];
    int const  MAX = 1000000;

    for(int i = 0; i < n1; ++i) {
        L[i] = arr[p + i];
    }
    L[n1] = MAX;

    for(int i = 0; i < n2; ++i) {
        R[i] = arr[q + 1 + i];
    }
    R[n2] = MAX;

    int i = 0, j = 0;
    for(int k = p; k <= n; ++k) {
        if (L[i] < R[j]) {
           arr[k] = L[i++];
        } else{
            arr[k] = R[j++];
        }
    }
}

void mergeSort(int arr[], int const p, int const n) {
    if (p < n) {
        const int q = (p + n) / 2;

        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, n);

        merge(arr, p, q, n);
    }
}

int main(){
    int const MaxSize = 1000;
    int arr[MaxSize];

    int size;
    std::cout << "Size = ";
    std::cin >> size;
    
    input(arr, size);

    mergeSort(arr, 0, size - 1);
    show(arr, 0, size);
}
