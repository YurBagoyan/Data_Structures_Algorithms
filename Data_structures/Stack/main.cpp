//#include <iostream>
#include "Stack.hpp"

int main()
{
    // Create a stack and push some elements onto it
    Stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    // Copy the stack to another stack
    Stack<int> copiedStack(myStack);

    // Move the original stack to a new stack
    Stack<int> movedStack(std::move(myStack));

    // Print the top elements of all three stacks
    std::cout << "Original Stack Top: " << (myStack.empty() ? -1 : myStack.top()) << std::endl;
    std::cout << "Copied Stack Top: " << (copiedStack.empty() ? -1 : copiedStack.top()) << std::endl;
    std::cout << "Moved Stack Top: " << (movedStack.empty() ? -1 : movedStack.top()) << std::endl;

    // Pop elements from the copied and moved stacks
    copiedStack.pop();
    movedStack.pop();

    // Print the top elements again
    std::cout << "Copied Stack Top after pop: " << (copiedStack.empty() ? -1 : copiedStack.top()) << std::endl;
    std::cout << "Moved Stack Top after pop: " << (movedStack.empty() ? -1 : movedStack.top()) << std::endl;

    // Clear the original stack
    myStack.clear();

    // Check if the stacks are empty
    std::cout << "Original Stack Empty? " << (myStack.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Copied Stack Empty? " << (copiedStack.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Moved Stack Empty? " << (movedStack.empty() ? "Yes" : "No") << std::endl; 

    return 0;
}