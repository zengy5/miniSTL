#include <iostream>
#include <sstream>
#include <string>

enum class Color { RED, BLACK };

template <typename Key, typename Value>
class myRedBlackTree{
public:    
    class Node
    {
    public:
        Key key;
        Value value;
        Color color;
        Node * left;
        Node * right;
        Node * parent;

        Node(const Key & k, const Value & v, Color c, Node * p = nullptr)
            : key(k), value(v), color(c), left(nullptr), right(nullptr), parent(p) {}
        
        Node()
            : color(Color::BLACK), left(nullptr), right(nullptr), parent(nullptr) {}
    };

private:
    Node * root;
    size_t size;
    Node * Nil;

    Node *lookUp(Key key) 
    {
        Node *cmpNode = root;

        while (cmpNode) 
        {
            if (key < cmpNode->key) cmpNode = cmpNode->left;
            else if (key > cmpNode->key) cmpNode = cmpNode->right;
            else return cmpNode;
        }
        return cmpNode;
    }
};