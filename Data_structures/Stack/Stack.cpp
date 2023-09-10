#include "Stack.hpp"
#include <stdexcept>

template <typename T>
Stack<T>::Stack()
{
    m_data = new T[m_capacity];
}

template <typename T>
Stack<T>::~Stack() 
{
    m_size = 0;
	delete[] m_data;
}

template <typename T>
Stack<T>::Stack(const Stack& obj)
	: m_data(new T[obj.m_capacity]), m_size(obj.m_size), m_capacity(obj.m_capacity)
{	
    for(size_t i = 0; i < m_size; ++i) {
        m_data[i] = obj.m_data[i];
    } 
}

template <typename T>
Stack<T>::Stack(Stack&& obj)
	: m_data(obj.m_data), m_size(obj.m_size), m_capacity(obj.m_capacity)
{
    //m_data = new T[m_capacity];
	
	obj.m_data = nullptr;
    obj.m_size = 0;
    obj.m_capacity = DEFAULT_SIZE;

}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& obj)
{
	if(this != &obj) {
		delete[] m_data;
        m_size = obj.m_size;
        m_capacity = obj.m_capacity;
		
		m_data = new T[m_capacity];
        for (size_t i = 0; i < m_size; ++i) {
            m_data[i] = obj.m_data[i];
        }
	}
	
	return *this;
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack&& obj)
{
	if (this != &obj) {
        delete[] m_data;
        m_size = obj.m_size;
        m_capacity = obj.m_capacity;
		
		m_data = obj.m_data;
		
        obj.m_data = nullptr;
        obj.m_size = 0;
        obj.m_capacity = DEFAULT_SIZE;
    }
	
    return *this;
}

template <typename T>
void Stack<T>::push(const T elm)
{
	if (m_size == m_capacity) {
        m_capacity *= 2;
        T* temp = new T[m_capacity];
        for (size_t i = 0; i < m_size; ++i) {
            temp[i] = std::move(m_data[i]);
        }
        delete[] m_data;
        m_data = temp;
    }
	
    m_data[m_size++] = elm;
}

template <typename T>
void Stack<T>::pop()
{
    if(m_size > 0)
        --m_size;
}

template <typename T>
inline T Stack<T>::top() const
{
    if(m_size > 0) 
        return m_data[m_size - 1];

    throw std::runtime_error("Stack is empty");
}

template <typename T> 
inline bool Stack<T>::empty() const
{
    return m_size == 0;
}

template <typename T>
inline size_t Stack<T>::size() const
{
    return m_size;
}

template <typename T>
inline void Stack<T>::clear()
{
    m_size = 0;
}

// Explicit instantiation
template class Stack<int>;
template class Stack<double>;
template class Stack<char>;
template class Stack<bool>;


