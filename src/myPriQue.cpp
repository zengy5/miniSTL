#include "Deque.h"
#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <sstream>
#include <string>

template <typename T, typename Container = myDeque<T> >
class myPriQue
{
private:
    Container data;

    void heapUp()
    {
        int index = data.size() - 1;
        while (index)
        {
            int parentIndex = (index - 1) / 2;
            if(data[index] > data[parentIndex])
            {
                std::swap(data[index], data[parentIndex]);
                index = parentIndex;
            }
            else break;
        }
    }

    void heapDown() {
        int index = 0;
        int size = data.size();
        while (true) 
        {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int largest = index;

            if (leftChild < size && data[leftChild] > data[largest]) largest = leftChild;
            if (rightChild < size && data[rightChild] > data[largest]) largest = rightChild;
            
            if (largest != index) 
            {
                std::swap(data[index], data[largest]);
                index = largest;
            } 
            else break;
        }
    }  

public:
    myPriQue() {};
    myPriQue(const Container & c) : data(c) 
    {
        int size = data.size();
        for(int i = (size / 2) - 1; i >= 0; i --) heapDown();
    }

    void push(const T & value)
    {
        data.push_back(value);
        heapUp();
    }

    void pop()
    {
        if (!data.empty())
        {
            std::swap(data[0], data[data.size() - 1]);
            data.pop_back();
            heapDown();
        }
        else throw std::runtime_error("Stack is empty!");
        
    }

    T& top() 
    {
        if (!data.empty()) return data[0];
        else throw std::runtime_error("Priority queue is empty.");
        
    }

    bool empty()  
    {
        return data.empty();
    }

    size_t size() const 
    {
        return data.size();
    }
};

int main()
{
    // myPriQue<int> que;
    // que.push(10);
    // std::cout << que.size() << std::endl;
    // std::cout << que.top() << std::endl;
    // que.pop();
    // std::cout << que.empty() << std::endl;
    // que.push(10);
    // que.push(15);
    // que.push(13);
    // while (!que.empty())
    // {
    //     std::cout << que.top() << std::endl; que.pop();
    // }
    
    myDeque<int> origin_que;
    int n = 8;
    while(n --) origin_que.push_back(100 - n);
    for(int i = 0; i < origin_que.size(); i++)
    std::cout << origin_que[i] << " ";
    std::cout << std::endl;

    myPriQue<int> que(origin_que);
    while (!que.empty())
    {
        std::cout << que.top() << " "; que.pop();
    }
    
}