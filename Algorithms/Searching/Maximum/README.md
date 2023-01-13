# Find largest element in an array

Take a max variable and initialize it with the first element of the array. Now start iterating over the array and whenever a larger element encountered then update the max variable otherwise, move forward.

## Solution Steps

1. Create a max variable and initialize it with arr[0]
2. Iterate from the first index to the last index of the array:
 - If arr[i] > max then update max with arr[i]
3. Return max
