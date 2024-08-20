#include "HashTable.h"
#include <chrono>  


template <typename Key> class myUnSet 
{
public:
    myUnSet() : hashtable(){};

    ~myUnSet(){}

    bool empty() const noexcept { return hashtable.size() == 0; }

    size_t size() const noexcept { return hashtable.size(); }

    void clear() noexcept { hashtable.clear(); }

    void insert(Key key) { hashtable.insertKey(key); }

    void erase(Key key) { hashtable.erase(key); }

    bool find(const Key &key) { return hashtable.find(key) != nullptr; }

    private:
    myHashTable<Key, Key> hashtable;
};

int main()
{
    myUnSet<int> testUnSet;
    auto start = std::chrono::high_resolution_clock::now(); 
    for(int i = 0; i < 1000000; i ++) testUnSet.insert(i);
    auto stop = std::chrono::high_resolution_clock::now();  
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();  
    std::cout << duration << std::endl;
    return 0;
}