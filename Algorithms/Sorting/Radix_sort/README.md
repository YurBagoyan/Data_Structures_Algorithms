# Radix Sort

This is a C++ implementation of the Radix Sort algorithm for sorting a vector of strings lexicographically.

## Overview

Radix Sort is a non-comparative sorting algorithm that works on strings by processing individual characters from the least significant digit (rightmost character) to the most significant digit (leftmost character). It is often used to sort strings of varying lengths, such as words, names, or alphanumeric codes.
Radix Sort is an efficient and stable sorting algorithm with a time complexity of O(n*k), where n is the number of elements in the array, and k is the average length of the strings being sorted. It has advantages over comparison-based sorting algorithms like Quick Sort and Merge Sort when dealing with large datasets of strings.

The algorithm works by iteratively distributing the strings into buckets based on the value of a specific character position, starting from the least significant digit (rightmost character) and moving towards the most significant digit (leftmost character). After each iteration, the strings are collected from the buckets and placed back into the original array. This process is repeated for each character position, resulting in a sorted array.

This implementation takes an unsorted vector of strings as input and sorts it in lexicographic order using the Radix Sort algorithm.

## Implementation Details

- The program takes an unsorted vector of strings as input and sorts it using Radix Sort.
- It first finds the maximum length of a string in the vector to determine the number of iterations needed for sorting.
- The sorting process occurs by iterating through each character position (from right to left) in the strings.
- Strings are placed into buckets based on the character at the current position.
- The buckets are then collected back into the original vector.
- This process is repeated for each character position, resulting in a sorted vector.

## Example
![radix-sort-animation-o](https://github.com/YurBagoyan/Data_Structures_Algorithms/assets/90376899/bf1c4690-b800-475b-be01-d79ef9baf978)
