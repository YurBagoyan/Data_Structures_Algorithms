#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <deque>

template <typename T>
class Queue 
{
public:
    Queue();
    ~Queue();

    // Copy
    Queue(const Queue& obj);
    Queue& operator=(const Queue& obj);

    // Move
    Queue(Queue&& obj);
    Queue& operator=(Queue&& obj);

    void push(const T& elm);// Adds an element to the back of the queue
    void pop();             // Removes the front element from the queue
    T front() const;        // Returns a reference to the front element in the queue
    T back() const;         // Returns a reference to the back element in the queue
    bool empty() const;     // Checks if the queue is empty
    size_t size() const;    // Returns the number of elements in the queue
    void clear();

private:
    std::deque<T> m_data;
};

#endif // QUEUE_HPP
