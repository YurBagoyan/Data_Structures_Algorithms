#include <iostream>
#include <vector>

// Function to find all prime numbers up to 'n' using Sieve of Eratosthenes algorithm
std::vector<int> getPrimes(const int n)
{
	// Boolean vector 'flag' to mark numbers as prime or non-prime
    std::vector<bool> flag(n, true);
	
    std::vector<int> primes;
    primes.push_back(2);

	// Loop through odd numbers starting from 3 up to the square root of 'n'
    for(int i = 3; i * i <= n; i += 2) {
        if(flag[i]) {
			// If 'i' is marked as prime, mark its multiples as non-prime
            for(int j = i * i; j < n; j += i) {
                flag[j] = false;            
            }
        }
    }

    for(int i = 3; i < n; i += 2) {
        if(flag[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

int main()
{
	// Call the getPrimes function to find prime numbers up to 100
    std::vector<int> primes = getPrimes(100);

    for(int prime : primes) {
        std::cout << prime << " ";
    }
}
