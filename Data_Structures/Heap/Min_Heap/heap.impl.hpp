#include <cassert>
#include "heap.hpp"

template <typename T> /// Constructor
MaxHeap<T>::MaxHeap(T* array, int arrSize)
{
    copy(array, arrSize);
    build();
}

template <typename T> /// Destructor
MaxHeap<T>::~MaxHeap()
{
    delete[] arr_;
}

template <typename T>
void MaxHeap<T>::copy(T* array, const int arrSize)
{
    capacity_ = MAXSIZE;
    size_ = arrSize;
    arr_ = new T[capacity_];

    for (int i = 0; i < size_; ++i) {
        arr_[i] = array[i];
    }
}

template <typename T>
void MaxHeap<T>::build()
{
    assert(arr_ != nullptr);

    for (int i = size_ / 2; i > 0; --i) {
        heapify(i - 1);
    }
}

template <typename T>
void MaxHeap<T>::heapify(const int i)
{
    const int l = left(i);
    const int r = right(i);
    int min = i;

    if (arr_[l] < arr_[i] && l < size_) {
        min = l;
    }

    if (arr_[r] < arr_[min] && r < size_) {
        min = r;
    }

    if (min != i) {
        swap(arr_[i], arr_[min]);
        heapify(min);
    }
}

template <typename T>
T MaxHeap<T>::extarct()
{
    swap(arr_[0], arr_[--size_]);
    heapify(0);

    return arr_[size_];
}

template <typename T>
void MaxHeap<T>::insert(T value)
{
    if (size_ + 1 > capacity_) {
        newArr();
    }

    arr_[size_++] = value;
    heapify_upwards(size_ - 1);
}

template <typename T>
void MaxHeap<T>::newArr()
{
    capacity_ += 100;
    T* newArr = new T[capacity_];

    for (int i = 0; i < size_; ++i) {
        newArr[i] = arr_[i];
    }

    delete[] arr_;
    arr_ = newArr;
}

template <typename T>
void MaxHeap<T>::heapify_upwards(const int i)
{
    const int p = parent(i);

    if (arr_[i] < arr_[p] && i > 0) {
        swap(arr_[i], arr_[p]);
        heapify_upwards(p);
    }
}

inline int parent(const int i)
{
    return (i - 1) >> 1;
}

inline int left(const int i)
{
    return (i << 1) + 1;
}

inline int right(const int i)
{
    return (i << 1) + 2;
}

template <typename T>
void swap(T& a, T& b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

template <typename T>
void MaxHeap<T>::print() const
{
    for (int i = 0; i < size_; ++i) {
        std::cout << arr_[i] << " ";
    }
    std::cout << std::endl;
}
