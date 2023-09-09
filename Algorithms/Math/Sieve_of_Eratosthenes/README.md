# Sieve of Eratosthenes

The Sieve of Eratosthenes is a classic algorithm for finding all prime numbers up to a given limit 'n'. This implementation demonstrates the Sieve of Eratosthenes algorithm to find prime numbers efficiently.

## About the Sieve of Eratosthenes

The Sieve of Eratosthenes is an ancient algorithm for finding prime numbers. It works by iteratively marking the multiples of each prime number, starting with 2, as non-prime. By doing so, it efficiently sieves out all non-prime numbers, leaving only the prime numbers behind.

### How it works:

1. Create a list of numbers from 2 to 'n'.
2. Start with the first prime number, which is 2.
3. Mark all multiples of 2 as non-prime.
4. Move to the next unmarked number (3) and mark all its multiples as non-prime.
5. Repeat the process until you reach the square root of 'n' (since any non-prime number greater than the square root of 'n' would have already been marked).
6. The remaining unmarked numbers are all prime numbers.

### Time Complexity:

The Sieve of Eratosthenes is highly efficient for finding prime numbers. Its time complexity is O(n log log n), which makes it one of the fastest algorithms for this purpose. It is particularly efficient for finding primes in a relatively large range.

## Example

Suppose you want to find all prime numbers up to 100. Running the program will output:
```
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
```

