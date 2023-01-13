#include <iostream>

void input(int arr[], int const n)
{
    for(int i = 0; i < n; ++i)
    {
        std::cout << "arr[" << i << "] = ";
        std::cin >> arr[i];
    }
}

int MaxFinder(int arr[], int const n)
{
    int max = arr[0];
    for(int i = 1; i < n; ++i)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    int arr[50];
    int n;

    std::cout << "Size of array = ";
    std::cin >> n;
    
    input(arr, n);
    std::cout << "Max = " << MaxFinder(arr, n) << std::endl;
}
