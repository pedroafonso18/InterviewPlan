#pragma once

template<typename T>
class DynamicArray {
    public:
        DynamicArray() = default;
        ~DynamicArray();

        void push_back(const T& value);
        void pop_back();

        std::size_t size() const;
        std::size_t capacity() const;
        bool is_empty() const;
    private:
        T* data = nullptr;
        std::size_t current_size = 0;
        std::size_t current_capacity = 0;
        void grow();
};