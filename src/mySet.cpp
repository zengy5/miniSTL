#include <iostream>
#include "RedBlackTree.h"


template <typename Key> 
class mySet
{
public:
    mySet() : rbTree() {}

    void insert(const Key &key) { rbTree.insert(key, key); }
    void erase(const Key &key) { rbTree.remove(key); }
    size_t size() { return rbTree.getSize(); }
    bool empty() { return rbTree.empty(); }
    bool contains(const Key &key) { return rbTree.at(key) != nullptr; }

private:
    myRedBlackTree<Key, Key> rbTree;
};

int main()
{
    mySet<int> set;
    set.insert(20);
    std::cout << set.size() << std::endl;
    set.insert(20);
    std::cout << set.size() << std::endl;
    set.erase(20);
    std::cout << set.size() << std::endl;
    set.insert(30);
    set.insert(50);
    set.insert(60);
    std::cout << set.size() << std::endl;
    if(set.contains(50)) std::cout << "YES" << std::endl;
    if(!set.contains(10)) std::cout << "NO" << std::endl;
    
    return 0;

}