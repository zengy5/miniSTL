#include "Deque.h"
#include <stdexcept>
#include <sstream>
#include <string>

template <typename T, typename Container = myDeque<T> >
class myStack
{
private:
    Container data;

public:
    void push(const T & value)
    {
        data.push_back(value);
    }

    void pop()
    {
        if(data.empty()) throw std::runtime_error("Stack is empty!");
        else data.pop_back();
    }

    T& top()
    {
        if(data.empty()) throw std::runtime_error("Stack is empty!");
        else return data[data.size()-1];
    }

    size_t size()
    {
        return data.size();
    }

    bool empty()
    {
        return data.empty();
    }
};

int main()
{
    myStack<int> st;
    st.push(1);
    std::cout << st.size() << std::endl;
    std::cout << st.top() << std::endl;
    st.push(3);
    std::cout << st.top() << std::endl;
    
}