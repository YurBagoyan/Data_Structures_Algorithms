# Binary Exponentiation

This repository contains two implementations of binary exponentiation in C++. Binary exponentiation is a fast algorithm for computing the power of a number raised to an integer exponent.

## About Binary Exponentiation

Binary exponentiation, also known as exponentiation by squaring, is an efficient algorithm for calculating the result of raising a number to a power. It takes advantage of the binary representation of the exponent to reduce the number of multiplications needed, resulting in faster computation, especially for large exponent values.

This repository provides both recursive and iterative implementations of binary exponentiation to demonstrate the algorithm's versatility.

## Implementation

The C++ code in this repository includes two functions for binary exponentiation:

1. `bin_pow_recursive`: This function implements binary exponentiation using a recursive approach.

2. `bin_pow_iterative`: This function implements binary exponentiation using an iterative approach.

Both functions take two arguments: `number` (the base) and `n` (the exponent), and return the result of `number` raised to the power of `n`.

## Time Complexity 

Binary exponentiation, also known as exponentiation by squaring, is an efficient algorithm for calculating the result of raising a number to a power. The primary advantage of this algorithm is that it significantly reduces the number of multiplications required to compute the result, especially for large exponent values.

The time complexity of binary exponentiation depends on whether you are using the recursive or iterative version of the algorithm:

Recursive Binary Exponentiation:

In the recursive version of binary exponentiation, the algorithm divides the exponent n by 2 in each recursive call. Therefore, the number of recursive calls is proportional to the number of bits in the binary representation of n. Let's denote the number of bits in n as b.

The time complexity of the recursive binary exponentiation algorithm is O(log₂(n)) or O(b).
This means that the algorithm's running time grows logarithmically with the value of the exponent n. It is highly efficient and performs a minimal number of multiplications compared to the straightforward method, which has a time complexity of O(n).

Iterative Binary Exponentiation:

In the iterative version of binary exponentiation, the algorithm uses bit manipulation to traverse the bits of the exponent n. It performs one multiplication in each iteration and right-shifts n by one bit.

The time complexity of the iterative binary exponentiation algorithm is also O(log₂(n)) or O(b).
Like the recursive version, the iterative version has the same logarithmic time complexity. It accomplishes this with a loop instead of recursion, making it a suitable choice for situations where you want to avoid the function call overhead associated with recursion.

In summary, binary exponentiation is an algorithm with a time complexity of O(log₂(n)) or O(b), making it highly efficient for computing exponentiation, especially for large exponent values. This efficiency is achieved by exploiting the binary representation of the exponent to minimize the number of multiplications required to calculate the result.

## How to Use

You can use the provided functions for binary exponentiation in your C++ projects as follows:

```cpp

// Example usage of bin_pow_recursive
std::cout << bin_pow_recursive(2, 10) << std::endl; // Output: 1024

// Example usage of bin_pow_iterative
std::cout << bin_pow(2, 10) << std::endl;          // Output: 1024

