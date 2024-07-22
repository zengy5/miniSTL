#include <iostream>


template<typename T>
class myList
{
private:
    struct Node
    {
        T data;
        Node * next;
        Node * prev;

        Node(const T & data_, Node * next_ = nullptr, Node * prev_ = nullptr)
            : data(data_), next(next_), prev(prev_) {} 
    };
    
    Node * head;
    Node * tail;
    size_t current_size;
public:
    myList() : head(nullptr), tail(nullptr), current_size(0) {}
    ~myList() {clear(); }

    void push_back(const T & value)
    {
        Node * temp = new Node(value, nullptr, tail);
        if(tail) tail->next = temp;
        else head = temp;

        tail = temp;
        current_size ++;
    }

    void push_front(const T & value)
    {
        Node * temp = new Node(value, head, nullptr);
        if(head) head->prev = temp;
        else tail = temp;
        head = temp;
        current_size ++;
    }

    void pop_back()
    {
        if(current_size > 0)
        {
            Node * temp = tail->prev;
            delete tail;
            tail = temp;

            if(tail) tail->next = nullptr;
            else head = nullptr;
            current_size --;
        }
    }

    void pop_front()
    {
        if(current_size > 0)
        {
            Node * temp = head->next;
            delete head;
            head = temp;

            if(head) head->prev = nullptr;
            else tail = nullptr;
            current_size --;
        }
    }

    int size()
    {
        return current_size;
    }

    void clear()
    {
        while (head)
        {
            Node * temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        current_size = 0;
        
    }

    T &operator[](size_t index)
    {
        Node * curr = head;
        for(size_t i = 0; i < index; i ++)
        {
            if(!curr) throw std::out_of_range("Index out of range!");
            curr = curr->next;
        }
        return curr->data;
    }

    const T & operator[](size_t index) const
    {
        Node * curr = head;
        for(size_t i = 0; i < index; i ++)
        {
            if(!curr) throw std::out_of_range("Index out of range!");
            curr = curr->next;
        }
        return curr->data;
    }

    void remove(const T & val)
    {
        Node * temp = head;
        while (temp && temp->data != val)
        {
            temp = temp->next;
        }
        if(!temp) return;
        if(temp != head && temp != tail)
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        else if(temp == head && temp == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else if(temp == head)
        {
            head = temp->next;
            head->prev = nullptr;
        }
        else
        {
            tail = temp->prev;
            tail->next = nullptr;
        }

        current_size --;
        delete temp;
        temp = nullptr;
    }

    Node * getNode(const T & val)
    {
        Node * node = head;
        while (node && node->data != val)
        {
            node = node->next;
        }
        return node;
        
    }

    T *find(const T &val)
    {
        Node * node = getNode(val);
        if(!node) return nullptr;
        return & node->data;
    }

    bool empty()
    {
        return current_size == 0;
    }

    Node * begin() { return head; }
    Node * end() { return nullptr; }
    const Node * begin() const { return head; }
    const Node * end() const { return nullptr; }
};

template <typename T>
std::ostream &operator<<(std::ostream &os, myList<T> &pt)
{
    for (auto current = pt.begin(); current;
         current = current->next)
    {
        os << " " << current->data;
    }
    os << std::endl;
    return os;
}

int main()
{
    myList<int> testList;
    testList.push_back(1);
    testList.push_back(2);
    std::cout << testList;
}