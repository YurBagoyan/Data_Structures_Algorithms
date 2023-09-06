#include <iostream>
#include <vector>

using Vec = std::vector<std::string>;

void print(const Vec& vector)
{
    for(int i = 0; i < vector.size(); ++i) {
        std::cout << vector[i] << "\n";
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
        std::string input;
        std::cin >> input;
        vector.push_back(input);
    }
}

int findMaxLength(Vec& vector)
{
    int maxLength = vector[0].length();
    for(int i = 1; i < vector.size(); ++i) {
        const int currentLength = vector[i].length();
        if(currentLength > maxLength) {
            maxLength = currentLength;
        }
    }
    return maxLength;
}

void radixSort(Vec& vector)
{
    const int d = findMaxLength(vector);
    const int countOfASCII = 256;
        
    for(int pow = d - 1; pow >= 0; --pow) {
     
        std::vector<Vec> buckets(countOfASCII); // Assuming ASCII characters

        // Place elements into buckets based on the current digit (from right to left)
        for (int i = 0; i < vector.size(); ++i) {
            if (vector[i].length() <= pow) {
                // If the current string doesn't have a character at this position, put it in bucket 0
                buckets[0].push_back(vector[i]);
            } else {
                // Place the string in the bucket corresponding to its character at the current position
                buckets[static_cast<int>(vector[i][pow])].push_back(vector[i]);
            }
        }

        // Collect elements from buckets back into the original vector
        int index = 0;
        for (int i = 0; i < countOfASCII; ++i) {
            for (const std::string& str : buckets[i]) {
                vector[index++] = str;
            }
        }
    }
}


void sort(Vec& vector)
{
    radixSort(vector);
}


int main()
{
    Vec vector; //std::string vector

    input(vector);
    print(vector);
    sort(vector);
    print(vector);

}
