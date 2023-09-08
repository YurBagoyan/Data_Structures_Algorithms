#include <iostream>

// Recursive binary exponentiation function
int bin_pow_recursive(const int number, const int n)
{
	// Base case: when n is 0, any number raised to the power of 0 is 1
    if(n == 0) return 1;
    
	// If n is odd, use recursion to compute (number^(n-1)) and multiply it by 'number'
    if(n % 2 != 0) {
        return bin_pow_recursive(number, n - 1) * number;
    }
    
	// If n is even, calculate (number^(n/2)) only once and square it
    const int b = bin_pow_recursive(number, n/2); 
    return b * b;
}

// iterative binary exponentiation function
int bin_pow_iterative(int number, int n)
{
    int result = 1;

    while(n != 0) {

        if(n & 1) {
            result *= number;
        }
		// Right-shift n by 1 (equivalent to dividing it by 2)
        n >>= 1;
        number *= number;
    }

    return result;
}

int main()
{
    std::cout << bin_pow_recursive(2, 10) << std::endl;
    std::cout << bin_pow_recursive(3, 5) << "\n\n";

    std::cout << bin_pow_iterative(2, 10) << std::endl;
    std::cout << bin_pow_iterative(3, 5) << std::endl;

}
