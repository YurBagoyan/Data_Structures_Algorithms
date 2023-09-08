# Binary Search Implementation

This C++ program demonstrates the binary search algorithm to efficiently search for an element in a sorted vector. Binary search is a logarithmic time complexity algorithm that can quickly determine whether a given element exists in a sorted dataset or not.

Binary search is a fundamental algorithm used to efficiently locate a specific element within a sorted collection of data. It operates by repeatedly dividing the search range in half until the desired element is found or it is determined that the element does not exist in the dataset. Here are the key steps of the binary search algorithm:

Initialization: Binary search begins with two pointers, often called left and right, which represent the boundaries of the search range. Initially, left points to the first element in the collection, and right points to the last element.

Midpoint Calculation: The algorithm calculates the midpoint index mid of the current search range as (left + right) / 2.

Comparison: The element at the mid index is compared to the target element:

If they are equal, the target element has been found, and the search terminates successfully.

If the target element is less than the element at mid, it means the target must lie in the left half of the current search range. Therefore, right is updated to mid - 1.

If the target element is greater than the element at mid, it must be in the right half, so left is updated to mid + 1.

Repeat: Steps 2 and 3 are repeated until either the target element is found or left becomes greater than right, which indicates that the element is not in the dataset.


## Time Complexity
Binary search's time complexity is O(log n), where 'n' is the number of elements in the sorted collection. This means that the algorithm's running time increases very slowly as the size of the dataset grows.

The reason for this efficiency lies in the logarithmic nature of the algorithm. With each iteration, binary search reduces the size of the search range by half. Therefore, in the worst case, binary search will take approximately log₂(n) iterations to find the element or determine that it does not exist. This makes it particularly well-suited for searching in large datasets.

In comparison, linear search (where each element is checked one by one) has a time complexity of O(n), which means its running time increases linearly with the size of the dataset. Binary search, with its logarithmic time complexity, is significantly faster for large datasets, making it a preferred choice for searching in sorted collections.
