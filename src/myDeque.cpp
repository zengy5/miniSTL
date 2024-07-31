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
    size_t size;  

public:
    myDeque() : elements(nullptr), capacity(0), frontIndex(0), backIndex(0), size(0) {}

    ~myDeque() {
        clear();
        delete[] elements;
    }

    void push_back(const T& value) {
        if (size == capacity) {
            resize();
        }
        elements[backIndex] = value;
        backIndex = (backIndex + 1) % capacity;
        ++size;
    }

    void push_front(const T& value) {
        if (size == capacity) {
            resize();
        }
        frontIndex = (frontIndex - 1 + capacity) % capacity;
        elements[frontIndex] = value;
        ++size;
    }


    void pop_front() {
        if (size == 0) {
            throw std::out_of_range("Deque is empty");
        }
        frontIndex = (frontIndex + 1) % capacity;
        --size;
    }

    void pop_back() {
        if (size == 0) {
            throw std::out_of_range("Deque is empty");
        }
        backIndex = (backIndex - 1 + capacity) % capacity;
        --size;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return elements[(frontIndex + index) % capacity];
    }

    size_t getSize() const {
        return size;
    }

    void clear() {
        while (size > 0) {
            pop_front();
        }
    }

private:
    void resize() {
        size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
        T* newElements = new T[newCapacity];

        size_t index = frontIndex;
        for (size_t i = 0; i < size; ++i) {
            newElements[i] = elements[index];
            index = (index + 1) % capacity;
        }
        delete[] elements;

        elements = newElements;
        capacity = newCapacity;
        frontIndex = 0;
        backIndex = size;
    }
};

int main() {
    myDeque<int> deque;
    deque.push_back(1);
    deque.push_front(0);
    std::cout << deque[0] << " " << deque[1] << std::endl;
    deque.pop_back();
    deque.pop_front();
    deque.clear();
    for(int i = 0; i < 20; i ++)
    {
        deque.push_back(i * i);
    }
    std::cout << deque.getSize() << std::endl;
}