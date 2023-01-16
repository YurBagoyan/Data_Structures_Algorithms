# Hybrid of merge and insertion sort

When the subarray size reaches below a threshold K, it should switch to insertion sort. So, start out performing merge-sort, but switch to insertion sort when the problem size goes below K. 
The advantages of both the sorting algorithms can be combined, and the resulting algorithm will have time complexity O(N [K+log( N/K )] ).
