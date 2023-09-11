# Queue Data Structure

A queue is a fundamental data structure in computer science and programming. It follows the FIFO (First-In-First-Out) principle, meaning that the first element added to the queue is the first one to be removed. It can be visualized as a line of people waiting for a service, where the person at the front of the line is served first.

## Implementation

This is a simple C++ implementation of a queue data structure using the standard library's `std::deque` as the underlying data structure. It provides basic queue operations such as `push`, `pop`, `front`, `back`, `empty`, `size`, and `clear`. Additionally, it includes copy and move constructors and assignment operators.

## Complexity

Push (Enqueue): O(1) - Adding an element to the rear of the queue is typically a constant-time operation.

Pop (Dequeue): O(1) - Removing an element from the front of the queue is also typically a constant-time operation.

Front: O(1) - Retrieving the front element is a constant-time operation.

Rear: O(1) - Retrieving the rear element is a constant-time operation.

Empty: O(1) - Checking if the queue is empty is a constant-time operation.

Size: O(1) - Getting the size of the queue is a constant-time operation.

## Getting Started

To use this `Queue` implementation in your C++ project, follow these steps:

1. Clone or download this repository to your local machine.

2. Include the `Queue.hpp` header file in your project:
