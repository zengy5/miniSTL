#include "Deque.h"
#include <stdexcept>
#include <sstream>
#include <string>

template <typename T, typename Container = myDeque<T> >
class myQueue
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
        else data.pop_front();
    }

    T& front()
    {
        if(data.empty()) throw std::runtime_error("Stack is empty!");
        else return data[0];
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
    myQueue<int> st;
    st.push(1);
    std::cout << st.size() << std::endl;
    std::cout << st.front() << std::endl;
    st.push(3);
    std::cout << st.front() << std::endl;
    st.pop();
    std::cout << st.front() << std::endl;
}