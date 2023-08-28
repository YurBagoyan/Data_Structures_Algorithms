# Counting sort
Counting Sort is a non-comparison based sorting algorithm that efficiently sorts a collection of integers within a specific range. It works by determining, for each element in the input, how many elements are less than it. Using this information, it can then place each element in its correct sorted position.

## Performance

Counting Sort is a fast sorting algorithm for small integer arrays. It has a linear time complexity of O(n + k), where n is the number of elements and k is the range of values. It's efficient when the range is small, but less practical for larger ranges due to memory usage. Counting Sort is stable, preserving the order of equal elements. While it's powerful in specific cases, other algorithms might be better for larger ranges.

## Example 

An illustration of Counting Sort: Count the frequency of each element in the input array and use that information to reconstruct a sorted array. It works well when the range of values is small. After counting, iteratively place elements in the output array according to the counts. The process creates a sorted array while maintaining the original order of equal elements.

![counting-sort](https://github.com/YurBagoyan/Data_Structures_Algorithms/assets/90376899/eda7bc9c-bace-4f56-ab1f-963bb5de04de)
