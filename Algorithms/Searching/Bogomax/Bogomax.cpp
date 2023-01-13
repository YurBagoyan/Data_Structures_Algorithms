#include <iostream>
#include <ctime>

void input(int& size)
{
    do {
        std::cout << "size = ";
        std::cin >> size;
                            
    } while (size <= 0);

    std::cout << std:: endl;  
}

void randomFillArr(int* arr, const int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 10;
    }        
}

void printArr(int* arr, const int size)
{
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;        
}

bool firstIsMax(int* arr, const int size)
{
    for(int i = 1; i < size; ++i) {
        if(arr[i] > arr[0]) {
            return false;                            
        }       
    } 
        
    return true;        
}
    
int randIdx(const int size)
{
    srand(time(NULL));
    return 1 + rand() % (size - 1);           
}

void swapFirst(int* arr, const int size)
{
    std::swap(arr[0], arr[randIdx(size)]);
}

int bogoMax(int* arr, const int size)
{
    while(!firstIsMax(arr, size)) {
        swapFirst(arr, size);              
    }       
    return arr[0];        
}

int main()
{
    int size;
    input(size);
    int* arr = new int[size];
    randomFillArr(arr, size);
    printArr(arr, size);
    std::cout << "Max = " << bogoMax(arr, size) << std::endl;
}
