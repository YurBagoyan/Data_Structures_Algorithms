#include <iostream>

void show_arr(int arr[], int const n)
{
    for(int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << "  ";
    }
    std::cout << std::endl;
}

void input(int arr[], int const n)
{
   for(int i = 0; i < n; ++i)
   {
       std::cout << "arr[" << i << "] = ";
       std::cin >> arr[i];
   }
}

void sort(int arr[], int const n)
{
    for(int j = 0; j < n-1; ++j)
    {
        int max = arr[n-1], max_index = n-1;
        for(int i = n-2; i >= j; --i)
        {
            if(arr[i] > max)
            {
                max = arr[i];
                max_index = i;
            }
        }
        arr[max_index] = arr[j];
        arr[j] = max;
    }
}

int main()
{
    int arr[50], n;

    std::cout << "Size of array = ";
    std::cin >> n;

    input(arr, n);
    show_arr(arr, n);

    sort(arr, n);
    show_arr(arr, n);
}
