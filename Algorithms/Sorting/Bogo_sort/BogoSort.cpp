#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <random>
#include <chrono>

bool isSorted(const std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

void shuffle(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = n - 1; i > 0; --i) {
        int j = std::rand() % (i + 1);
        std::swap(arr[i], arr[j]);
    }
}

void bogoSort(std::vector<int>& arr) {

    auto start = std::chrono::high_resolution_clock::now();

    while (!isSorted(arr)) {
        shuffle(arr);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "\nSorting took " << duration.count() << " seconds." << std::endl;
}

int main() {
    std::vector<int> arr = {5, 2, 9, 1, 5, 6};
    
    // Seed the random number generator for shuffling
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    
    bogoSort(arr);
    
    std::cout << "\nSorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    
    std::cout << std::endl;
    
    return 0;
}

