# Quick sort Hoare partition

Hoare partitioning was proposed by Tony Hoare when the Quicksort algorithm was originally published. Instead of working across the array from low to high, it iterates from both ends at once towards the center. This means that we have more iterations, and more comparisons, but fewer swaps.

## Example

An animated demonstration of Quicksort using Hoare's partition scheme. The red outlines show the positions of the left and right pointers (i and j respectively), the black outlines show the positions of the sorted elements, and the filled black square shows the value that is being compared to (pivot).

![Quicksort-example](https://user-images.githubusercontent.com/90376899/212414880-a5386e10-c914-4681-be02-386dc3e387ad.gif)
