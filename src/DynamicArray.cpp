#include "DynamicArray.h"

#include <cstddef>

constexpr std::size_t default_size = 4;

template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] data;
}

template <typename T>
void DynamicArray<T>::grow() {
    const std::size_t new_capacity =
        current_capacity == 0 ? default_size : current_capacity * 2;

    T* new_data = new T[new_capacity];

    for (std::size_t i = 0; i < current_size; ++i) {
        new_data[i] = data[i];
    }

    delete[] data;
    data = new_data;
    current_capacity = new_capacity;
}

template <typename T>
void DynamicArray<T>::push_back(const T& value)
{
    if (current_size == current_capacity) {
        T copy = value;
        grow();
        data[current_size] = copy;
    } else {
        data[current_size] = value;
    }

    ++current_size;
}

template <typename T>
void DynamicArray<T>::pop_back()
{
    if (current_size == 0) {
        return;
    }

    --current_size;
}

template <typename T>
std::size_t DynamicArray<T>::size() const
{
    return current_size;
}

template <typename T>
std::size_t DynamicArray<T>::capacity() const
{
    return current_capacity;
}

template <typename T>
bool DynamicArray<T>::is_empty() const
{
    return current_size == 0;
}
