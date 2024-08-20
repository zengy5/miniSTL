#include "RedBlackTree.h"
#include <chrono>  

template<typename Key, typename Value>
class myMap
{
private:
    myRedBlackTree<Key, Value> rbTree;

public:
    myMap() : rbTree() {};

    void insert(const Key &key, const Value &value) { rbTree.insert(key, value); }

    void erase(const Key &key) { rbTree.remove(key); }

    size_t size() { return rbTree.getSize(); }

    bool empty() const { return rbTree.empty(); }

    bool contains(const Key &key) { return rbTree.at(key) != nullptr; }
    
    Value &at(const Key &key) 
    {
        Value *foundVal = rbTree.at(key);
        if (foundVal) return *foundVal;
        else throw std::out_of_range("Key not found");
    }

    Value &operator[](const Key &key) 
    {
        Value *foundVal = rbTree.at(key);
        if (foundVal) return *foundVal; 
        else 
        {
            Value defaultValue;
            rbTree.insert(key, defaultValue);
            return *rbTree.at(key);
        }
    }

};

int main()
{
    myMap<int, int> testMap;
    auto start = std::chrono::high_resolution_clock::now(); 
    for(int i = 0; i < 1000000; i ++) testMap.insert(i, 0);
    auto stop = std::chrono::high_resolution_clock::now();  
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();  
    std::cout << duration << std::endl;    
}