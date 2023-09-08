#include <iostream>
#include <vector>

using Vector = std::vector<int>;

// Binary search function to check if 'num' exists in 'vector'
bool isThere(const Vector& vector, const int num)
{
    int l = 0, r = vector.size() - 1;
    
    while(l <= r) {
        const int mid = (l + r) / 2;

        if(num == vector[mid]) {
            return true;
        }
        else if(num < vector[mid]) {
            r = mid - 1;
        } else if(num > vector[mid]) {
            l = mid + 1;
            
        
        }
    }

	// If the while loop exits without finding 'num', return false
    return false;
}

int main()
{
    Vector vector = { 1, 3, 4, 6, 7, 8, 12, 15, 20, 22, 23 };

    std::cout << isThere(vector, 4) << std::endl;
    std::cout << isThere(vector, 12) << std::endl;
    std::cout << isThere(vector, 23) << std::endl;
    std::cout << isThere(vector, 110) << std::endl;
}
