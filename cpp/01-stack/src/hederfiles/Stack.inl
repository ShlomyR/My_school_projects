#pragma once

// #include "../hederfiles/Stack.hpp"
#include "Stack.hpp"

#include <iostream>


template<typename T>
Stack<T>::Stack(int size)
:   m_arr(new T[size])
,   m_capacity(size)
,   m_cp(0)
{}

template<typename T>
Stack<T>::Stack(Stack const &other)
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
Stack<T> &Stack<T>::operator=(Stack<T> const &other)
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
T &Stack<T>::operator[](size_t index)
{
    return m_arr[index];
}

template<typename T>
void Stack<T>::push(T value)
{
    m_arr[m_cp] = value;
    ++m_cp;
}

template<typename T>
T Stack<T>::top()
{
    return m_arr[m_cp - 1];
}

template<typename T>
T Stack<T>::size()
{
    return m_cp;
}

template<typename T>
T Stack<T>::capacity()
{
    return m_capacity;
}

template<typename T>
void Stack<T>::pop()
{
    m_arr[m_cp] = 0;
    m_arr[--m_cp];
}

template<typename T>
bool Stack<T>::empty()
{
    return m_cp == 0;
}