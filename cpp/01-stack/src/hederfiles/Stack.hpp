#pragma once

#include <memory>

template<typename T>
class Stack_1
{
public:
    Stack_1(int);
    Stack_1(Stack_1 const&);
    Stack_1<T>& operator=(Stack_1<T> const&);
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