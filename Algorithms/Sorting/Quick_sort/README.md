# Quick sort
QuickSort is a Divide and Conquer algorithm. It picks an element as a pivot and partitions the given array around the picked pivot. Then calls itself recursively twice to sort the two resulting subarrays. This algorithm is quite efficient for large-sized data sets as its average and worst-case complexity are O(n2), respectively. In this implementation as a pivot picked the last element. 

## Example

Following animated representation explains how to find the pivot value in an array.

![quick_sort_partition_animation](https://user-images.githubusercontent.com/90376899/212415246-ac8dc73f-a707-42f5-bdf7-7d248426e93d.gif)

The pivot value divides the list into two parts. And recursively, we find the pivot for each sub-lists until all lists contains only one element.
