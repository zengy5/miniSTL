#include "RedBlackTree.h"
#include <cstddef>
#include <iostream>
#include <list>

template <typename Key, typename Value> class MultiMap
{
public:
    using ValueType = std::list<Value>; 

    MultiMap() : rbTree(), size(0) {}

    void insert(const Key &key, const Value &value) 
    {
        ValueType *existingValues = rbTree.at(key);
        if (existingValues) existingValues->push_back(value);
        else 
        {
            ValueType values;
            values.push_back(value);
            rbTree.insert(key, values);
        }
        size++;
    }

    void remove(const Key &key) 
    {
        ValueType *existingValues = rbTree.at(key);
        if (existingValues) 
        {
            size -= existingValues->size();
            rbTree.remove(key);
        }
    }

    void remove(const Key &key, const Value &value) 
    {
        ValueType *existingValues = rbTree.at(key);
        if (existingValues) 
        {
            existingValues->remove(value);
            size--;
            if (existingValues->empty()) rbTree.remove(key);
        }
    }

    ValueType *at(const Key &key) { return rbTree.at(key); }

    int getSize() { return size; }

    bool empty() { return size == 0; }

private:
    myRedBlackTree<Key, ValueType> rbTree; 
    size_t size;
};

int main() {
    MultiMap<std::string, int> myMultiMap;

    myMultiMap.insert("apple", 10);
    myMultiMap.insert("banana", 20);
    myMultiMap.insert("apple", 30); 

    auto appleValues = myMultiMap.at("apple");
    if (appleValues) 
    {
        std::cout << "Values for 'apple':";
        for (const auto &val : *appleValues) std::cout << val << ", ";
        std::cout << '\n';
    }

    myMultiMap.remove("banana");
    myMultiMap.remove("apple", 30);

    if (!myMultiMap.empty()) 
    {
        std::cout << "The MultiMap is not empty, it has " << myMultiMap.getSize()
                << " elements." << std::endl;
    }

    return 0;
}