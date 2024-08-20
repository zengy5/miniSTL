#include "RedBlackTree.h"

template<typename Key>
class myMultiSet
{
private:
    myRedBlackTree<Key, size_t> rbTree;
    size_t sz;

public:
    myMultiSet() : sz(0) {}
    ~myMultiSet() {}

    void insert(const Key &key) 
    {
        auto count = rbTree.at(key);
        if (count != nullptr) 
        {
            (*count)++;
            sz++;

            return;
        }
        rbTree.insert(key, 1);
        sz++;
    }

    void erase(const Key &key) 
    {
        auto count = rbTree.at(key);
        if (count == nullptr) 
        {
            return;
        }

        (*count)--;
        sz--;
        if (*count == 0) 
        {
            rbTree.remove(key);
        }
    }

    size_t size() const { return sz; }
    bool empty() const { return sz == 0; }

    size_t count(const Key &key) 
    {
        auto num = rbTree.at(key);
        if (num != nullptr) 
        {
            return *num;
        }

        return 0;
    }

    void clear() 
    {
        sz = 0;
        rbTree.clear();
    }    
};

int main()
{
    myMultiSet<int> testMultiSet;
    testMultiSet.insert(20);
    testMultiSet.insert(20);
    std::cout << testMultiSet.size();
    return 0;
}