# Bubble sort
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in the wrong order. This algorithm is not suitable for large data sets as its average and worst-case time complexity is quite high.

## Performance

Bubble sort has a worst-case and average complexity of O(n^2), where n is the number of items being sorted. Most practical sorting algorithms have substantially better worst-case or average complexity, often O(nlog(n)). Even other O(n^2) sorting algorithms, such as insertion sort, generally run faster than bubble sort, and are no more complex. For this reason, bubble sort is rarely used in practice.

## Example 

An example of bubble sort. Starting from the beginning of the list, compare every adjacent pair, swap their position if they are not in the right order (the latter one is smaller than the former one). After each iteration, one less element (the last one) is needed to be compared until there are no more elements left to be compared.

![Bubble-sort-example-300px](https://user-images.githubusercontent.com/90376899/212403468-a37cce8b-b271-480f-97f0-4d71e8ad58e5.gif)
