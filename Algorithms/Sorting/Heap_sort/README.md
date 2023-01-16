# Heap sort

Heap sort is a comparison-based sorting technique based on Binary Heap data structure. Heapsort can be thought of as an improved selection sort: like selection sort, heapsort divides its input into a sorted and an unsorted region, and it iteratively shrinks the unsorted region by extracting the largest element from it and inserting it into the sorted region. 

## Example
Let { 6, 5, 3, 1, 8, 7, 2, 4 } be the list that we want to sort from the smallest to the largest. (NOTE, for 'Building the Heap' step: Larger nodes don't stay below smaller node parents. They are swapped with parents, and then recursively checked if another swap is needed, to keep larger numbers above smaller numbers on the heap binary tree.)

![Heapsort-example](https://user-images.githubusercontent.com/90376899/212743032-50255a83-3318-4a18-a16d-7a72776b443a.gif)
