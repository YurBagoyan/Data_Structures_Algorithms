#include <iostream>
#include <vector>

using Vec = std::vector<int>;

void print(const Vec& vector)
{
    for(int i = 0; i < vector.size(); ++i) {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}

void input(Vec& vector)
{
    int size;
    std::cout << "Input vector size: ";
    std::cin >> size;

    std::cout << "Input vector: ";
    for(int i = 0; i < size; ++i) {
        int input;
        std::cin >> input;
        vector.push_back(input);
    }
}

void findMaxAndMin(const Vec& vector, int& min, int& max) 
{
    for(int i = 0; i < vector.size(); ++i) {
        if(vector[i] > max) 
            max = vector[i];
        else if(vector[i] < min)
            min = vector[i];
    }
}

void countingSort(Vec& vector)
{
    int max = vector[0], min = vector[0];
    findMaxAndMin(vector, min, max);

    const int size = max - min + 1;
    Vec bucket(size);

    for(int i = 0; i < vector.size(); ++i) {
        ++bucket[vector[i] - min];
    }

    int index = 0;
    for(int i = 0; i < size; ++i) {
        int count = bucket[i];
        for(int j = 0; j < count; ++j) {
            vector[index++] = i + min;
        }
    }
}

void sort(Vec& vector)
{
    countingSort(vector);
}


int main()
{
    Vec vector;

    input(vector);
    print(vector);
    sort(vector);
    print(vector);

}
