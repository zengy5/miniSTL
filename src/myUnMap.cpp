#include "HashTable.h"

template<typename Key, typename Value>
class myUnMap
{
private:
    myHashTable<Key, Value> hashtable;

public:
    myUnMap() : hashtable() {}
    ~myUnMap() {}

    bool empty() const noexcept { return hashtable.size() == 0; }
    size_t size() const noexcept { return hashtable.size(); }
    void clear() noexcept { hashtable.clear(); }

    void insert(const Key &key, const Value &value) 
    {
        hashtable.insert(key, value);
    }

    void erase(const Key &key) { hashtable.erase(key); }
    bool find(const Key &key) { return hashtable.find(key) != nullptr; }

    Value &operator[](const Key &key) 
    {
        Value *ans = hashtable.find(key);
        if (ans != nullptr) return *ans;
        
        hashtable.insertKey(key);
        ans = hashtable.find(key);
        return *ans;
    }
};