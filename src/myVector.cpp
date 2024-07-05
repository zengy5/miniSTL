#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <stdexcept>

template <typename T>
class myVector
{
private:
    T * elements;           // pointer to array
    size_t capacity;        // capacity of vector
    size_t current_size;    // current count of vector elements
public:
/* Base Functions*/
    myVector() : elements(nullptr), capacity(0), current_size(0){}
    ~myVector()
    {
        delete[] elements;
    }
    
    myVector(const myVector & other) : capacity(other.capacity), current_size(other.current_size)
    {
        elements = new T[capacity];                                                 // copy arrays of the same length 
        std::copy(other.elements, other.elements + current_size, elements);         // fill the array and finish copying
    }

    myVector &operator = (const myVector & other)
    {
        if(this != other)
        {
            delete[] elements;
            capacity = other.capacity;
            current_size = other.current_size;
            elements = new T[other.capacity];
            std::copy(other.elements, other.elements + current_size, elements);
        }
        return *this;
    }

/* Core Functions*/

    void push_back(const T & input)
    {
        if(current_size == capacity)
        {
            capacity ? reserve(2 * capacity) : reserve(1);
        }
        elements[current_size++] = input;
    }

    size_t size()
    {
        return current_size;
    }

    T & operator[](size_t index)
    {
        if(index >= current_size) std::cout << "Index overstep" << std::endl;
        return elements[index];
    }
    const T & operator[](size_t index) const
    {
        if(index >= current_size) std::cout << "Index overstep" << std::endl;
        return elements[index];
    }

    void pop_back()
    {   
        if(current_size) current_size--;
    }

    void insert(const size_t index, const T & input)
    {
        if(index > current_size) throw std::out_of_range("Index overstep");
        if(current_size == capacity) reserve(capacity == 0 ? 1 : 2 * capacity);
        for(size_t i = current_size; i > index; i --)
        {
            elements[i] = elements[i - 1];
        } 
        elements[index] = input;
        current_size ++;
    }

    void clear()
    {
        current_size = 0;
    }

    T* begin()
    {
        return elements;
    }

    T* end()
    {
        return elements + current_size;
    }

    const T* begin() const
    {
        return elements;
    }

    const T* end() const
    {
        return elements + current_size;
    }

    void printElements() const
    {
        for(size_t i = 0; i < current_size; i ++)
        {
            std::cout << elements[i] << " ";
        }
        std::cout << std::endl;
    }
private:
    void reserve(size_t newCapacity)
    {
        if (newCapacity > capacity)
        {
            T *newElements = new T[newCapacity];
            std::copy(elements, elements + current_size, newElements);
            delete[] elements;
            elements = newElements;
            capacity = newCapacity;
        }
    }

};




int main(int argc, char ** argv)
{
    myVector<int> testVector;
    testVector.push_back(0);
    std::cout << testVector.size() << std::endl;
    testVector.insert(1,2);
    std::cout << testVector.size() << std::endl;
    std::cout << testVector[1] << std::endl;
    for(auto ele:testVector) std::cout << ele << std::endl;
    return 0;
}