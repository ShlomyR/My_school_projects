#pragma once

#include <memory>

template<typename T>
class Stack
{
public:
    Stack(int);
    Stack(Stack const&);
    Stack<T>& operator=(Stack<T> const&);
    T& operator[](size_t);

    void push(T);
    T top();
    T size();
    T capacity();
    void pop();
    bool empty();
    
private:
    std::unique_ptr<T[]> m_arr;
    size_t m_capacity;
    size_t m_cp;
};

#include "Stack.inl"