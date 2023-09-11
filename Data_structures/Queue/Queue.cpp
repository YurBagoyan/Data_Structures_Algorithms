#include "Queue.hpp"

template<typename T>
Queue<T>::Queue()
{
   
}

template<typename T>
Queue<T>::~Queue()
{
    clear();
}

template<typename T>
Queue<T>::Queue(const Queue& obj)
{
    for(const auto& elm : obj.m_data) {
        m_data.push_back(elm); // Push each element into the new queue
    }
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue& obj)
{
    if(this != &obj) {
        for(const auto& elm : obj.m_data) {
            m_data.push_back(obj.m_data[elm]);
        }
    }

    return *this;
}

template<typename T>
Queue<T>::Queue(Queue&& obj)
{
    m_data = std::move(obj.m_data);
}

template<typename T>
Queue<T>& Queue<T>::operator=(Queue&& obj)
{
    if(this != &obj) {
       m_data = std::move(obj.m_data);
    }

    return *this;
}

template<typename T>
inline void Queue<T>::push(const T& elm)
{
    m_data.push_back(elm);
}

template<typename T>
inline void Queue<T>::pop()
{
    if(!empty()) {
        m_data.pop_front();
    }
}

template<typename T>
inline T Queue<T>::front() const
{
    return m_data.front();
}

template<typename T>
inline T Queue<T>::back() const
{
    return m_data.back();
}

template<typename T>
inline bool Queue<T>::empty() const
{
    return m_data.empty();
}

template<typename T>
inline size_t Queue<T>::size() const
{
    return m_data.size();
}

template<typename T>
inline void Queue<T>::clear()
{
    m_data.clear();
}


// Explicit instantiation
template class Queue<int>;
template class Queue<double>;
template class Queue<char>;
template class Queue<bool>;

