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

## How to Use

You can use the provided functions for binary exponentiation in your C++ projects as follows:

```cpp

// Example usage of bin_pow_recursive
std::cout << bin_pow_recursive(2, 10) << std::endl; // Output: 1024

// Example usage of bin_pow_iterative
std::cout << bin_pow(2, 10) << std::endl;          // Output: 1024

