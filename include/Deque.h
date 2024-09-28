#ifndef MYDEQUE_H
#define MYDEQUE_H

#include <iostream>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>

template <typename T>
class myDeque {
private:
    T* elements;  
    size_t capacity;  
    size_t frontIndex;  
    size_t backIndex;  
    size_t curr_size;  

public:
    myDeque() : elements(nullptr), capacity(0), frontIndex(0), backIndex(0), curr_size(0) {}

    myDeque(const myDeque& other) 
    {
        curr_size = other.curr_size;
        capacity = other.capacity;
        elements = new T[capacity];  
        for (size_t i = 0; i < curr_size; ++i) elements[i] = other.elements[i];  
    }
        ~myDeque() {
        clear();
        delete[] elements;
    }

    void push_back(const T& value) {
        if (curr_size == capacity) {
            resize();
        }
        elements[backIndex] = value;
        backIndex = (backIndex + 1) % capacity;
        ++curr_size;
    }

    void push_front(const T& value) {
        if (curr_size == capacity) {
            resize();
        }
        frontIndex = (frontIndex - 1 + capacity) % capacity;
        elements[frontIndex] = value;
        ++curr_size;
    }


    void pop_front() {
        if (curr_size == 0) {
            throw std::out_of_range("Deque is empty");
        }
        frontIndex = (frontIndex + 1) % capacity;
        --curr_size;
    }

    void pop_back() {
        if (curr_size == 0) {
            throw std::out_of_range("Deque is empty");
        }
        backIndex = (backIndex - 1 + capacity) % capacity;
        --curr_size;
    }

    T& operator[](int index) {
        if (index < 0 || index >= curr_size) {
            throw std::out_of_range("Index out of range");
        }
        return elements[(frontIndex + index) % capacity];
    }

    size_t size() const {
        return curr_size;
    }

    bool empty()
    {
        return curr_size == 0;
    }

    void clear() {
        while (curr_size > 0) {
            pop_front();
        }
    }

private:
    void resize() {
        size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
        T* newElements = new T[newCapacity];

        size_t index = frontIndex;
        for (size_t i = 0; i < curr_size; ++i) {
            newElements[i] = elements[index];
            index = (index + 1) % capacity;
        }
        delete[] elements;

        elements = newElements;
        capacity = newCapacity;
        frontIndex = 0;
        backIndex = curr_size;
    }
};
#endif