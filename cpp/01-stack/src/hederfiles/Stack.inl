#pragma once

// #include "../hederfiles/Stack.hpp"
#include "Stack.hpp"

#include <iostream>


template<typename T>
Stack_1<T>::Stack_1(int size)
:   m_arr(new T[size])
,   m_capacity(size)
,   m_cp(0)
{}

template<typename T>
Stack_1<T>::Stack_1(Stack_1 const &other)
:   m_arr(new T[other.m_capacity])
,   m_capacity(other.m_capacity)
,   m_cp(0)
{
    m_arr.reset(new T[other.m_capacity]);
    while (this->m_cp != other.m_cp) {
        this->m_arr[m_cp] = other.m_arr[m_cp];
        ++(this->m_cp);
    }
    this->m_arr[m_cp] = other.m_arr[m_cp];
}

template<typename T>
Stack_1<T> &Stack_1<T>::operator=(Stack_1<T> const &other)
{
    // copy(other.m_capacity);
    m_arr.reset(new T[other.m_capacity]);
    this->m_capacity = other.m_capacity;
    this->m_cp = 0;
    
    while (this->m_cp != other.m_cp) {
        this->m_arr[m_cp] = other.m_arr[m_cp];
        ++(this->m_cp);
    }
    this->m_arr[m_cp] = other.m_arr[m_cp];
    return *this;
}

template<typename T>
T &Stack_1<T>::operator[](size_t index)
{
    return m_arr[index];
}

template<typename T>
void Stack_1<T>::push(T value)
{
    m_arr[m_cp] = value;
    ++m_cp;
}

template<typename T>
T Stack_1<T>::top()
{
    return m_arr[m_cp - 1];
}

template<typename T>
T Stack_1<T>::size()
{
    return m_cp;
}

template<typename T>
T Stack_1<T>::capacity()
{
    return m_capacity;
}

template<typename T>
void Stack_1<T>::pop()
{
    m_arr[m_cp] = 0;
    m_arr[--m_cp];
}

template<typename T>
bool Stack_1<T>::empty()
{
    return m_cp == 0;
}