#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>

constexpr size_t DEFAULT_SIZE = 100;

template<typename T>
class Stack 
{
public:
    
    Stack();
    ~Stack();

    //Copy
    Stack(const Stack& obj);
    Stack& operator=(const Stack& obj);

    // Move
    Stack(Stack&& obj);
    Stack& operator=(Stack&& obj);
    

    void push(const T elm); // Adds an element to the top of the stack
    void pop();             // Removes the element from the top of the stack
    T top() const;          // Returns a reference to the top element of the stack without removing it
    bool empty() const;     // Checks if the stack is empty
    size_t size() const;    // Returns the number of elements in the stack
    void clear();
   
private:
    T* m_data;
    size_t m_size = 0;
    size_t m_capacity = DEFAULT_SIZE;
};


#endif // STACK_HPP
