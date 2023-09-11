#include "Queue.hpp"

int main()
{
    // Create a queue and push some elements into it
    Queue<int> myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    // Create a copy of the queue
    Queue<int> copiedQueue(myQueue);
   
    // Create a new queue using move semantics
    Queue<int> movedQueue(std::move(myQueue));
    // Display the front and back elements of the copied queue
    std::cout << "Copied Queue Front: " << copiedQueue.front() << ", Back: " << copiedQueue.back() << std::endl;

    // Display the front and back elements of the moved queue
    std::cout << "Moved Queue Front: " << movedQueue.front() << ", Back: " << movedQueue.back() << std::endl;

    // Check if the original queue is empty
    if (myQueue.empty()) {
        std::cout << "Original Queue is empty." << std::endl;
    } else {
        std::cout << "Original Queue is not empty." << std::endl;
    }

    return 0;
}
